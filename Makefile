LIB = crc
STATICLIB = $(BUILDDIR)/lib$(LIB).a
SHAREDLIB = $(BUILDDIR)/lib$(LIB).dll
IMPLIB = $(BUILDDIR)/lib$(LIB).dll.a

TOOLCHAIN_PREFIX =
CC = $(TOOLCHAIN_PREFIX)gcc
CFLAGS =
LD = $(CC)
LDFLAGS =
AR = $(TOOLCHAIN_PREFIX)ar
ARFLAGS = rcs
STRIP = $(TOOLCHAIN_PREFIX)strip

BUILDDIR = build/$(TOOLCHAIN_PREFIX)
SRCDIRS = src
INCDIRS = include src

DEFINES =
OPTFLAGS =
# OPTFLAGS += -ffunction-sections
# OPTFLAGS += -fdata-sections
WARNFLAGS = -Wall -Wextra -pedantic
DEPENDFLAGS = -MMD -MP

ifeq ($(DEBUG),1)
OPTFLAGS += -Og -g
else
OPTFLAGS += -O2
DEFINES += NDEBUG
endif

CFLAGS += $(addprefix -D,$(DEFINES)) -std=c90
CFLAGS += $(addprefix -I,$(INCDIRS))
CFLAGS += $(WARNFLAGS)
CFLAGS += $(OPTFLAGS)
CFLAGS += $(DEPENDFLAGS)
CFLAGS += $(EXTRAFLAGS)

VPATH = $(BUILDDIR):$(subst $() $(),:,$(SRCDIRS)):$(subst $() $(),:,$(INCDIRS))
SOURCES = $(wildcard $(SRCDIRS)/*.c)
OBJECTS = $(addprefix $(BUILDDIR)/,$(notdir $(patsubst %.c,%.o,$(SOURCES))))
DEPENDS = $(patsubst %.o,%.d,$(OBJECTS))
-include $(DEPENDS)

include test/test.mk

.DEFAULT_GOAL = all

all: static shared

static: $(BUILDDIR) $(STATICLIB)

shared: $(BUILDDIR) $(SHAREDLIB)

$(STATICLIB): $(OBJECTS)
	@$(AR) $(ARFLAGS) $@ $^
	@echo '  AR      ' $@

$(SHAREDLIB): $(OBJECTS)
	@$(CC) -shared -Wl,--out-implib,$(IMPLIB) $(LDFLAGS) -o $@ $^
	@echo '  CC      ' $@
	@$(STRIP) $@
	@echo '  STRIP   ' $@

$(IMPLIB): $(SHAREDLIB)

$(BUILDDIR)/%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo '  CC      ' $@

$(BUILDDIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILDDIR)

dox:
	@mkdir -p doc
	@doxygen doxyfile

format:
	@clang-format \
		-style=file:.clang-format \
		-i $(wildcard src/*.c) $(wildcard src/*.h) \
		$(wildcard test/*.c) $(wildcard test/*.h) \
		$(wildcard include/crc/*.h) \
		$(wildcard include/crcxx/*.hxx) \
		$(wildcard include/crcxx/detail/*.hxx) \
		$(wildcard test/*.hxx) $(wildcard test/*.cxx)

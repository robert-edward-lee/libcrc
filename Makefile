LIB = crc
CC = gcc
AR = ar rcs
CFLAGS =
LFLAGS =

BUILDDIR = build
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

CFLAGS += $(addprefix -D,$(DEFINES))
CFLAGS += $(addprefix -I,$(INCDIRS))
CFLAGS += $(WARNFLAGS)
CFLAGS += $(OPTFLAGS)
CFLAGS += $(DEPENDFLAGS)

VPATH = $(BUILDDIR):$(subst $() $(),:,$(SRCDIRS)):$(subst $() $(),:,$(INCDIRS))
SOURCES = $(wildcard $(SRCDIRS)/*.c)
OBJECTS = $(addprefix $(BUILDDIR)/,$(notdir $(patsubst %.c,%.o,$(SOURCES))))
DEPENDS = $(patsubst %.o,%.d,$(OBJECTS))
-include $(DEPENDS)

include test/test.mk

.DEFAULT_GOAL = static_lib

static_lib: $(BUILDDIR) lib$(LIB).a

lib$(LIB).a: $(OBJECTS)
	@$(AR) $(LFLAGS) $(BUILDDIR)/$@ $^
	@echo '  AR      ' $(BUILDDIR)/$@

$(BUILDDIR)/%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo '  CC      ' $@

$(BUILDDIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILDDIR)

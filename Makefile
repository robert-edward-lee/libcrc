################################################################################
#                              НАСТРОЙКА ПРОЕКТА                               #
################################################################################
PROJECT_NAME = crc
PROJECT_VERSION_MAJOR = 2
PROJECT_VERSION_MINOR = 1
PROJECT_VERSION_PATCH = 1
PROJECT_VERSION = $(PROJECT_VERSION_MAJOR).$(PROJECT_VERSION_MINOR).$(PROJECT_VERSION_PATCH)

################################################################################
#                              ОПРЕДЕЛЕНИЯ ПАПОК                               #
################################################################################
BUILD_DIR = build/$(TOOLCHAIN_PREFIX)$(CC)
SOURCE_DIRS = src
INCLUDE_DIRS = include src

TEST_DIR = tests
TEST_DIRS = $(sort $(TEST_DIR)/ $(dir $(wildcard $(TEST_DIR)/*/)))
TEST_SRCS = $(foreach dir,$(TEST_DIRS),$(wildcard $(dir)*.cpp))
TEST_BINS = $(patsubst %.cpp,%,$(TEST_SRCS))

WORK_DIRS = $(sort . $(TEST_DIRS) \
			$(dir $(wildcard include/sb/*/)) \
			$(dir $(wildcard include/sb/*/*/)))

VPATH = $(TEST_DIR):$(BUILD_DIR):$(subst $() $(),:,$(SOURCE_DIRS)):$(subst $() $(),:,$(INCLUDE_DIRS))
SOURCES = $(wildcard $(SOURCE_DIRS)/*.c)
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(patsubst %.c,%.o,$(SOURCES))))
DEPENDS = $(patsubst %.o,%.d,$(OBJECTS))
-include $(DEPENDS)

################################################################################
#                              НАСТРОЙКА ТУЛЧЕЙНА                              #
################################################################################
TOOLCHAIN_PREFIX =
CC = gcc
CFLAGS = \
	$(INC_FLAGS) \
	$(DEF_FLAGS) \
	$(OPT_FLAGS) \
	$(WARN_FLAGS) \
	$(STDC_FLAGS) \
	$(EXTRA_FLAGS) \
	$(DEPEND_FLAGS)

DEFINES = CRC_USE_HEAP=
OPT_LEVEL = 2

ifeq ($(CC),gcc)
include platforms/gcc.mk
else ifeq ($(CC),clang)
include platforms/clang.mk
else ifeq ($(CC),cl)
include platforms/msvc.mk
else ifeq ($(CC),armcc)
include platforms/armcc.mk
else ifeq ($(CC),armclang)
include platforms/armclang.mk
else ifeq ($(CC),iccarm)
include platforms/iccarm.mk
else
$(error Unknown compiler!)
endif

################################################################################
#                                  ОБЩИЕ ЦЕЛИ                                  #
################################################################################
.DEFAULT_GOAL = all

all: version static shared

static: $(BUILD_DIR) $(STATIC_LIB)

shared: $(BUILD_DIR) $(SHARED_LIB)

$(BUILD_DIR):
	@mkdir -p $@

dox:
	@mkdir -p doc
	@doxygen doxyfile

clean:
	@$(RM) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.a,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.d,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.dll,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.exe,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.o,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.obj,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.tds,$(dir))) \
		$(BUILD_DIR)/*

format:
	@clang-format -style=file:./.clang-format -i \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.c,$(dir))) \
		$(foreach dir,$(WORK_DIRS),$(addsuffix /*.h,$(dir))) \
		2> /dev/null ||:

.PHONY: test version

version:
	@echo "#ifndef H_CRC_VERSION"								 > include/crc/version.h
	@echo "#define H_CRC_VERSION"								>> include/crc/version.h
	@echo ""													>> include/crc/version.h
	@echo "#define CRC_VERSION_MAJOR $(PROJECT_VERSION_MAJOR)"	>> include/crc/version.h
	@echo "#define CRC_VERSION_MINOR $(PROJECT_VERSION_MINOR)"	>> include/crc/version.h
	@echo "#define CRC_VERSION_PATCH $(PROJECT_VERSION_PATCH)"	>> include/crc/version.h
	@echo "#define CRC_VERSION_STRING \"$(PROJECT_VERSION)\""	>> include/crc/version.h
	@echo ""													>> include/crc/version.h
	@echo "#endif /* H_CRC_VERSION */"							>> include/crc/version.h

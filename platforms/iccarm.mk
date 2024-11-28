STATIC_LIB = $(BUILD_DIR)/lib$(PROJECT_NAME).a
SHARED_LIB = $(STATIC_LIB)

AR = iarchive
ARFLAGS = --create

INC_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))
DEF_FLAGS = $(addprefix -D,$(DEFINES))

ifeq ($(OPT_FLAGS),0)
OPT_FLAGS = -On
else ifeq ($(OPT_FLAGS),1)
OPT_FLAGS = -Ol
else ifeq ($(OPT_FLAGS),2)
OPT_FLAGS = -Om
else ifeq ($(OPT_FLAGS),3)
OPT_FLAGS = -Oh
else
OPT_FLAGS =
endif

STDC_FLAGS = --c89
WARN_FLAGS =
DEPEND_FLAGS =

$(STATIC_LIB): $(OBJECTS)
	@echo '  AR      ' $@
	@$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/%.o: %.c
	@echo '  CC      ' $@
	@$(CC) -c $(CFLAGS) -o $@ $<

test: version $(BUILD_DIR) $(STATIC_LIB)
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) test/crc_test.c $(STATIC_LIB) -o $(BUILD_DIR)/$@
	@$(BUILD_DIR)/$@

print: $(BUILD_DIR) $(STATIC_LIB)
	@$(CC) $(CFLAGS) -DCRC_NAME=$(CRC_NAME) -DCRC_WIDTH=$(CRC_WIDTH) test/crc_print.c $(STATIC_LIB) -o $(BUILD_DIR)/$@
	@$(BUILD_DIR)/$@

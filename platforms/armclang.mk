STATIC_LIB = $(BUILD_DIR)/lib$(PROJECT_NAME).a
SHARED_LIB = $(STATIC_LIB)

AR = armar
ARFLAGS = -rcs

INC_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))
DEF_FLAGS = $(addprefix -D,$(DEFINES))
OPT_FLAGS = $(addprefix -O,$(OPT_LEVEL))
STDC_FLAGS = -ansi
WARN_FLAGS =
DEPEND_FLAGS =

ifeq ($(EXTRA_FLAGS),)
EXTRA_FLAGS = --target=arm-arm-none-eabi
endif

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

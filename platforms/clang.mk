STATIC_LIB = $(BUILD_DIR)/lib$(PROJECT_NAME).a
SHARED_LIB = $(BUILD_DIR)/lib$(PROJECT_NAME).dll
IMP_LIB = $(BUILD_DIR)/lib$(PROJECT_NAME).dll.a

AR = llvm-ar
ARFLAGS = rcs
LD = $(CC) -fuse-ld=lld
LDFLAGS = -shared -Wl,--out-implib,$(IMP_LIB)
STRIP = llvm-strip

INC_FLAGS = $(addprefix -I,$(INCLUDE_DIRS))
DEF_FLAGS = $(addprefix -D,$(DEFINES))
OPT_FLAGS = $(addprefix -O,$(OPT_LEVEL))
STDC_FLAGS = -ansi
WARN_FLAGS = -Wall -Wextra -pedantic
DEPEND_FLAGS = -MMD -MP

$(STATIC_LIB): $(OBJECTS)
	@echo '  AR      ' $@
	@$(AR) $(ARFLAGS) $@ $^

$(SHARED_LIB): $(OBJECTS)
	@echo '  LD      ' $@
	@$(LD) $(LDFLAGS) -o $@ $^
	@echo '  STRIP   ' $@
	@$(STRIP) $@

$(IMP_LIB): $(SHARED_LIB)

$(BUILD_DIR)/%.o: %.c
	@echo '  CC      ' $@
	@$(CC) -c $(CFLAGS) -o $@ $<

test: version $(BUILD_DIR) $(STATIC_LIB)
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) test/crc_test.c $(STATIC_LIB) -o $(BUILD_DIR)/$@
	@$(BUILD_DIR)/$@

print: $(BUILD_DIR) $(STATIC_LIB)
	@$(CC) $(CFLAGS) -DCRC_NAME=$(CRC_NAME) -DCRC_WIDTH=$(CRC_WIDTH) test/crc_print.c $(STATIC_LIB) -o $(BUILD_DIR)/$@
	@$(BUILD_DIR)/$@

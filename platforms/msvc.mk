STATIC_LIB = $(BUILD_DIR)/$(PROJECT_NAME).lib
SHARED_LIB = $(BUILD_DIR)/lib$(PROJECT_NAME).dll

AR = lib
ARFLAGS = /nologo
LD = link
LDFLAGS = /DLL /nologo

INC_FLAGS = $(addprefix /I,$(INCLUDE_DIRS))
DEF_FLAGS = $(addprefix /D,$(DEFINES))
OPT_FLAGS = $(addprefix /O,$(OPT_LEVEL))
STDC_FLAGS =
WARN_FLAGS = /W4
DEPEND_FLAGS =

EXTRA_FLAGS += /nologo #/Zc:preprocessor

$(STATIC_LIB): $(OBJECTS)
	@echo '  AR      ' $@
	@$(AR) $(ARFLAGS) /out:$@ $^

$(SHARED_LIB): $(OBJECTS)
	@echo '  LD      ' $@
	@$(LD) $(LDFLAGS) /out:$@ $^

$(BUILD_DIR)/%.o: %.c
	@echo '  CC      ' $@
	@$(CC) /c $(CFLAGS) /Fo:$@ $<

test: version $(BUILD_DIR) $(STATIC_LIB)
	@$(CC) $(CFLAGS) test/crc_test.c $(STATIC_LIB) /Fe:$(BUILD_DIR)/$@
	@$(BUILD_DIR)/$@

print: $(BUILD_DIR) $(STATIC_LIB)
	@$(CC) $(CFLAGS) /DCRC_NAME=$(CRC_NAME) test/crc_print.c $(STATIC_LIB) /Fe:$(BUILD_DIR)/$@
	@$(BUILD_DIR)/$@

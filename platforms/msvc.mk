STATIC_LIB = $(BUILD_DIR)/$(PROJECT_NAME).lib
SHARED_LIB = $(BUILD_DIR)/lib$(PROJECT_NAME).dll

AR = lib
ARFLAGS = /nologo
LD = link
LDFLAGS = /DLL /nologo

INC_FLAGS = $(addprefix /I,$(INCLUDE_DIRS))
DEF_FLAGS = $(addprefix /D,$(DEFINES))
ifeq ($(OPT_LEVEL),0)
OPT_FLAGS = /Od
else ifeq ($(OPT_LEVEL),1)
OPT_FLAGS = /O1
else ifeq ($(OPT_LEVEL),2)
OPT_FLAGS = /O2
else ifeq ($(OPT_LEVEL),3)
OPT_FLAGS = /Ox
else
OPT_FLAGS =
endif
STDC_FLAGS =
WARN_FLAGS = /W4
DEPEND_FLAGS =

EXTRA_FLAGS += /nologo

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
	@$(CC) $(CFLAGS) /DCRC_NAME=$(CRC_NAME) /DCRC_WIDTH=$(CRC_WIDTH) test/crc_print.c $(STATIC_LIB) /Fe:$(BUILD_DIR)/$@
	@$(BUILD_DIR)/$@

CXX = cl
STDCXX_FLAGS = /EHsc

bench: version $(BUILD_DIR) $(STATIC_LIB)
	@$(CXX) /Ipicobench/include $(CXXFLAGS) $(TEST_CFLAGS) bench/crc_bench.cpp $(STATIC_LIB) /Fe:$(BUILD_DIR)/$@
	@$(BUILD_DIR)/$@

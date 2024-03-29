TEST_CFLAGS = -ansi

test: $(BUILDDIR) $(STATICLIB)
	@$(CC) $(CFLAGS) $(TEST_CFLAGS) $(CURDIR)/test/crc_test.c $(STATICLIB) -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

print: $(BUILDDIR) $(STATICLIB)
	@$(CC) $(CFLAGS) -DCRC_NAME=$(CRC_NAME) -DCRC_WIDTH=$(CRC_WIDTH) $(CURDIR)/test/crc_print.c $(STATICLIB) -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

TEST_CXX = g++
TEST_CXXFLAGS = -Wall -pedantic -Iinclude -ansi

testxx: $(BUILDDIR)
	@$(TEST_CXX) $(CXXFLAGS) $(TEST_CXXFLAGS) $(CURDIR)/test/crcxx_test.cxx -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

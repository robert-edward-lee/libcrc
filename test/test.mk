test: $(BUILDDIR) $(STATICLIB)
	@$(CC) $(CFLAGS) -ansi $(CURDIR)/test/crc_test.c $(STATICLIB) -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

print: $(BUILDDIR) $(STATICLIB)
	@$(CC) $(CFLAGS) -DCRC_NAME=$(CRC_NAME) -DCRC_WIDTH=$(CRC_WIDTH) $(CURDIR)/test/crc_print.c $(STATICLIB) -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -Iinclude -ansi -U__STRICT_ANSI__

testxx: $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) $(CURDIR)/test/crcxx_test.cxx -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

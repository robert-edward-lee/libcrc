test: static_lib
	@$(CC) $(CFLAGS) $(CURDIR)/test/crc_test.c $(BUILDDIR)/lib$(LIB).a -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

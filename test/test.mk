test: static_lib
	@gcc $(CFLAGS) $(CURDIR)/test/crc_test.c $(BUILDDIR)/lib$(LIB).a -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

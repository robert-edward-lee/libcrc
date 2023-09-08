test: $(BUILDDIR) $(STATICLIB)
	@$(CC) $(CFLAGS) $(CURDIR)/test/crc_test.c $(STATICLIB) -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

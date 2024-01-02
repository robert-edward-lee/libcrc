test: $(BUILDDIR) $(STATICLIB)
	@$(CC) $(CFLAGS) $(CURDIR)/test/crc_test.c $(STATICLIB) -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

print: $(BUILDDIR) $(STATICLIB)
	@$(CC) $(CFLAGS) -DCRC_NAME=$(CRC_NAME) -DCRC_WIDTH=$(CRC_WIDTH) $(CURDIR)/test/crc_print.c $(STATICLIB) -o $(CURDIR)/$(BUILDDIR)/$@
	@$(CURDIR)/$(BUILDDIR)/$@

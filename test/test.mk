crc_test:
	@gcc -Wall -Wextra -pedantic -I$(CURDIR)/include -I$(CURDIR)/src $(CURDIR)/test/crc_test.c $(CURDIR)/src/crc.c -o $(CURDIR)/test/test
	@$(CURDIR)/test/test

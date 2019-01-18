
SOURCE = example.c
OUT = example-test

LIB_SOURCE = lib/arglib.c
HEADER_SOURCE = lib/arglib.h

LIB_INSTALL = /usr/lib
HEADER_INSTALL = /usr/include

CFLAG = -static

default: all

install-arglib: $(LIB_SOURCE)
	@echo "Installing: arglib.h"
	@echo " INSTALL: $(LIB_SOURCE) $(LIB_INSTALL)"
	@cp -f $(LIB_SOURCE) $(LIB_INSTALL)
	@echo " INSTALL: $(HEADER_SOURCE) $(HEADER_INSTALL)"
	@cp -f $(HEADER_SOURCE) $(HEADER_INSTALL)
	@echo "DONE"

compile-example: $(SOURCE)
	@echo "Compiling..."
	gcc $(CFLAG) -o $(OUT) $(SOURCE)
	@echo "DONE."

.PHONY: all
all:
	@echo "To install the library, do:"
	@echo "  $$ sudo make install-arglib"
	@echo

clean:
	rm -f $(OUT)

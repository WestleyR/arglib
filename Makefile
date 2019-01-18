# Created by: WestleyR
# email: westleyr@nym.hush.com
# Date: Jan 17, 2018
# https://github.com/WestleyR/arglib
# Version-1.0.1
#
# The Clear BSD License
#
# Copyright (c) 2019 WestleyR
# All rights reserved.
#
# This software is licensed under a Clear BSD License.
#

SOURCE = example.c
OUT = example-test

LIB_SOURCE = lib/arglib.c
HEADER_SOURCE = lib/arglib.h

LIB_INSTALL = /usr/lib/
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

#
# End Makefile
#
# Created by: WestleyR
# email: westleyr@nym.hush.com
# Date: Sep 26, 2019
# https://github.com/WestleyR/arglib
# Version-1.0.2
#
# The Clear BSD License
#
# Copyright (c) 2019 WestleyR
# All rights reserved.
#
# This software is licensed under a Clear BSD License.
#

CC = gcc

LIB_PREFIX = $(HOME)/.lib
INCLUDE_PREFIX = $(HOME)/.lib/include

LIB = libarglib.so

CFLAGS = -Wall

TARGET = test-example
SOURCE = example.c

all: $(LIB)
	$(CC) -L${HOME}/.lib -I${HOME}/.lib/include -Wall -o $(TARGET) example.c -larglib

	@#$(CC) -L${HOME}/.lib/x86_64-linux-gnu -I${HOME}/.lib/include -Wall -o example example.c -larglib
	@#$(CC) -L${HOME}/.lib/x86_64-linux-gnu/libarglib.so -Wall -o example example.c
	@#$(CC) -L$(shell pwd) -Wall -o example example.c -larglib

$(LIB):
	@#$(CC) -c -fpic src/arglib.c
	$(CC) -c src/arglib.c
	$(CC) -shared -o $(LIB) arglib.o

install-lib: $(LIB)
	mkdir -p $(LIB_PREFIX)
	mkdir -p $(INCLUDE_PREFIX)
	cp -f $(LIB) $(LIB_PREFIX)
	cp -f src/arglib.h $(INCLUDE_PREFIX)
	@echo
	@echo "Please add this to your .bashrc:"
	@echo
	@echo "  export LD_LIBRARY_PATH=\$${HOME}/.lib/:\$${LD_LIBRARY_PATH}"
	@echo

clean:
	rm $(LIB) $(TARGET) arglib.o


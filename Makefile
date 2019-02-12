# Created by: WestleyR
# email: westleyr@nym.hush.com
# Date: Feb 11, 2019
# https://github.com/WestleyR/arglib
# Version-1.0.0
#
# The Clear BSD License
#
# Copyright (c) 2019 WestleyR
# All rights reserved.
#
# This software is licensed under a Clear BSD License.
#

CC = gcc
TARGET = test
SOURCE = example.c

FUNC =
FUNC += deps/arglib/arglib.c
#FUNC += deps/other/deps.c

DEP_URL =
DEP_URL += WestleyR/arglib
#DEP_URL += other-user/library

CLIB = clib install

.PHONY:
all: $(TARGET)

.PHONY:
$(TARGET): $(FUNC) $(SOURCE)
	$(CC) -o $(TARGET) $(SOURCE) $(FUNC)

.PHONY:
$(FUNC):
	$(CLIB) $(DEP_URL)

.PHONY:
clean:
	rm -f $(TARGET)
	rm -rf deps

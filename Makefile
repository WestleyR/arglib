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

CFLAGS =

TARGET = test
SOURCE = example.c

SRC = $(wildcard *.c src/*.c)

ALLFILE = $(notdir $(SRC))

OBJS = $(ALLFILE:.c=.o)

.PHONY:
all: $(TARGET)

.PHONY:
$(TARGET): $(OBJS) $(SOURCE)
#	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

.PHONY:
$(OBJS): $(SRC) $(DEPS)
	$(foreach srcfile, $(SRC), $(CC) $(CFLAGS) -c $(srcfile);)
	$(foreach depfile, $(DEPS), $(CC) $(CFLAGS) -c $(depfile);)

.PHONY:
clean:
	rm -f arglib.o example.o
#	rm -f $(TARGET)

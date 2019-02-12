

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

$(TARGET): $(FUNC) $(SOURCE)
	$(CC) -o $(TARGET) $(SOURCE) $(FUNC)


$(FUNC):
	$(CLIB) $(DEP_URL)



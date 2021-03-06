# Simple, Library for Argument Processing

<br>

## Install:

Install via [clib](https://github.com/clibs/clib):

```
$ clib install WestleyR/arglib
```

<br>

## Usage:

Add this to your main code:

```c
#include "arglib/arglib.h"
```

Then add this to your `CFLAGS`:

```makefile
CFLAGS = -I deps
```

<br>

Then, here is a basic Makefile, combine this to your main project Makefile:

```makefile
CC = gcc
DEPDIR = deps
SRCDIR = src
CFLAGS = -I $(DEPDIR) -std=c99 -Wall 
LDFLAGS =

TARGET = test

SRC = $(wildcard $(SRCDIR)/*.c)
DEPS = $(wildcard $(DEPDIR)/*/*.c)

ALLFILE = $(notdir $(SRC) $(DEPS))
OBJS = $(ALLFILE:.c=.o)

.PHONY:
all: $(TARGET)

.PHONY:
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

.PHONY:
$(OBJS): $(DEPDIR)
	$(foreach srcfile, $(SRC), $(CC) $(CFLAGS) $(LDFLAGS) -c $(srcfile);)
	$(foreach depfile, $(DEPS), $(CC) $(CFLAGS) $(LDFLAGS) -c $(depfile);)

```

<br>

### Example C file:

```c
// for printf
#include <stdio.h>

#include "arglib/arglib.h"

int main(int argc, char** argv) {

    // if no args, print help menu.
    if (argc <= 1 ) {
        printf("Help Menu.\n");
        return(0);
    }

    // loop throught all the arguments
    for (int i=1; i < argc; i++) {
    
        // get the output of `--out=`
        char* var;
        var = get_val(argv[i], "--out=");
        if (var != NULL) {
            printf("OUTPUT:  %s\n", get_val(argv[i], "--out="));
        }

        // check if arguments are: sort, or long args
        if (check_flag(argv[i], "-s", "--long") == 0) {
            printf("Help Menu.\n");
        } else if (check_flag(argv[i], "-x", "--xxx") == 0) {
            printf("Script Version.\n");
        }

        // all the possible short args, will automatically print error
        // for example, $ ./your-code -lds --out=file
        if (check_small_args(argv[i], "lvdf") != 0) {
            return(1);
        }

        // if `l` is in the sort argument group
        if (find_args(argv[i], "l") == 0) {
            printf("l = true\n");
        }
        
        // if `v` is in the sort argument group
        if (find_args(argv[i], "v") == 0) {
            printf("v = true\n");
        }
        
        // if `d` is in the sort argument group
        if (find_args(argv[i], "d") == 0) {
            printf("d = true\n");
        }
        
        // if `f` is in the sort argument group
        if (find_args(argv[i], "f") == 0) {
            printf("f = true\n");
        }
    }
    return(0);
}
```

<br>

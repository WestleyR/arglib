// created by: WestleyR
// email: westleyr@nym.hush.com
// https://github.com/WestleyR/arglib
// date: Jan 17, 2018
// version-1.0.0
//
// The Clear BSD License
//
// Copyright (c) 2019 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include <arglib.h>

#define SCRIPT_VERSION "version-1.0.0, Jan 17, 2018"

#define OUT "--out="

int help_menu() {
    printf("USAGE:\n");
    printf("    ./somthing [--option]...\n");
    printf("\n");
    printf("OPTIONS:\n");
    printf("    -h, --help     : print help menu & exit.\n");
    printf("    -v, --version  : print script version & exit.\n");
    printf("\n");

    return(0);
}

int script_version() {
    printf("%s\n", SCRIPT_VERSION);
    return(0);
}

int main(int argc, char** argv) {

    if (argc <= 1 ) {
        help_menu();
    }

    for (int i=1; i < argc; i++) {
        char* var;
        var = get_val(argv[i], OUT);
        if (var != NULL) {
            printf("OUTPUT:  %s\n", get_val(argv[i], OUT));
        }

        if (check_flag(argv[i], "", "--help") == 0) {
            printf("help option set!\n");
//            help_menu();
        } else if (check_flag(argv[i], "", "--version") == 0) {
            script_version();
        }

        if (check_small_args(argv[i], "lvdf") != 0) {
            return(1);
        }

        if (find_args(argv[i], "l") == 0) {
            printf("l = true\n");
        }
        if (find_args(argv[i], "v") == 0) {
            printf("v = true\n");
        }
        if (find_args(argv[i], "d") == 0) {
            printf("d = true\n");
        }
        if (find_args(argv[i], "f") == 0) {
            printf("f = true\n");
        }

    }


    return(0);
}



//
// End example.c
//

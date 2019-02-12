// created by: WestleyR
// email: westleyr@nym.hush.com
// https://github.com/WestleyR/arglib
// date: Feb 11, 2019
// version-1.0.1
//
// The Clear BSD License
//
// Copyright (c) 2019 WestleyR
// All rights reserved.
//
// This software is licensed under a Clear BSD License.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> 

#include "deps/arglib/arglib.h"

#define SCRIPT_VERSION "version-1.0.0, Jan 17, 2018"
#define TypeFile "--type="

char *SCRIPT_NAME;
char *Path;
char *type;

void helpMenu() {
    printf("DESCRIPTION:\n");
    printf("  this is a test example for arglib.\n");
    printf("\n");
    printf("USAGE:\n");
    printf("  %s [--option]... <path>\n", SCRIPT_NAME);
    printf("\n");
    printf("OPTIONS:\n");
    printf("  --type=string  : set type for something.\n");
    printf("  -l, --list     : list.\n");
    printf("  -f, --force    : force.\n");
    printf("  -h, --help     : print help menu & exit.\n");
    printf("  -v, --version  : print script version & exit.\n");
    printf("\n");

    exit(0);
}

void scriptVersion() {
    printf("%s\n", SCRIPT_VERSION);
    exit(0);
}

int main(int argc, char** argv) {
    SCRIPT_NAME = argv[0];

    int list;
    int force;

    if (argc <= 1 ) {
        helpMenu();
    }

    for (int i=1; i < argc; i++) {
        char* var = get_val(argv[i], TypeFile);

        if (check_flag(argv[i], "", "--help") == 0) {
            helpMenu();
            return(0);
        } else if (check_flag(argv[i], "", "--version") == 0) {
            scriptVersion();
            return(0);
        } else if (var != NULL) {
            type = var;
        } else if ((strstr(argv[i], "--") == argv[i]) && (strstr(argv[i], TypeFile) != argv[i])) {
            printf("%s: Option not found: %s\n", SCRIPT_NAME, argv[i]);
            return(2);
        } else if (strstr(argv[i], "-") != argv[i]) {
            Path = argv[i];
        }

        // all the avalibal sort options:
        if (check_small_args(argv[i], "lfhv") != 0) {
            return(1);
        }

        if (find_args(argv[i], "v") == 0) {
            scriptVersion();
            return(0);
        }
        if (find_args(argv[i], "h") == 0) {
            helpMenu();
            return(0);
        }
        if (find_args(argv[i], "l") == 0) {
            list = 1;
        }
        if (find_args(argv[i], "f") == 0) {
            force = 1;
        }
    }

    if (type != NULL) {
        printf("Type: %s\n", type);
    }
    if (list == 1) {
        printf("List: true\n");
    }
    if (force == 1) {
        printf("Force: true\n");
    }
    if (Path != NULL) {
        printf("Path: %s\n", Path);
    }


    return(0);
}



//
// End example.c
//

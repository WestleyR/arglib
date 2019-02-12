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
#include <stdlib.h>
#include <string.h>
#include <dirent.h> 

#include "deps/arglib.h"

#define SCRIPT_VERSION "version-1.0.0, Jan 17, 2018"
#define TypeFile "--type="

char *SCRIPT_NAME;
char *Path;

void helpMenu() {
    printf("DESCRIPTION:\n");
    printf("  list file with relvent path, used for definging varibals, eg.\n");
    printf("  FOO = $(shell lcf --type=.c libs/)  # 'FOO' will be a string if all .c files.\n");
    printf("\n");
    printf("USAGE:\n");
    printf("  %s [--option]... <path>\n", SCRIPT_NAME);
    printf("\n");
    printf("OPTIONS:\n");
    printf("  --type=string  : list files only of type string.\n");
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

    char *var;
    char *fileType;

    if (argc <= 1 ) {
        helpMenu();
    }

    for (int i=1; i < argc; i++) {
        var = get_val(argv[i], TypeFile);

        if (check_flag(argv[i], "", "--help") == 0) {
            helpMenu();
            return(0);
        } else if (check_flag(argv[i], "", "--version") == 0) {
            scriptVersion();
        } else if (var != NULL) {
            fileType = var;
        } else if ((strstr(argv[i], "--") == argv[i]) && (strstr(argv[i], TypeFile) != argv[i])) {
            printf("%s: Option not found: %s\n", SCRIPT_NAME, argv[i]);
            return(2);
        } else {
            Path = argv[i];
        }

        // all the avalibal sort options:
        if (check_small_args(argv[i], "hv") != 0) {
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
    }


    if (Path == NULL) {
        printf("Need a Path.\n");
        return(1);
    }
//    printf("Path: %s\n", Path);

    listFiles(Path, fileType);

    printf("\n");


    return(0);
}



//
// End example.c
//

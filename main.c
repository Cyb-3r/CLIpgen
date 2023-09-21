/*
 *  Made by Isaac Ghr
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/generator.h"

int main(int argc, char* argv[]) {
    // initialize things
    const char* pgname   = argv[0];
    const char version[] =   "1.0";
    
    // si aucun paramètre n'est donné
    if (argc <= 1) {
        printf("error : no instruction given\nenter \"-h\" to get help");
        return 0;
    }

    // looks for -h arg first
    for (int h = 1; h < argc; h++) {
        if (strcmp(argv[h],"-h") == 0) {
            // just pretend it prints help infos
            printf("need help?\n");
            return 0;
        }
    }

    if (strcmp(argv[1], "create") == 0) {
        Settings settings = {14, 1, 1, 1}; // default config
        int i = 0, c = 0;
        // custom config
        for (i = 0; i < argc; i++) {
            if      (!strcmp(argv[i], "-l") || !strcmp(argv[i], "--length"))  { settings.length = atoi(argv[i+1]); }
            else if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "--amount"))  { settings.amount = atoi(argv[i+1]); }
            else if (!strcmp(argv[i], "-n") || !strcmp(argv[i], "--number"))  { settings.number = 1; }
            else if (!strcmp(argv[i], "-s") || !strcmp(argv[i], "--special")) { settings.special = 1; }
        }
        const int pwdsize = settings.length+1;
        // password tab
        char** pwd = newstrmt(pwdsize, settings.amount);
        int score; char* comment = NULL;
        for (i = 0; i < settings.amount; i++) {
            score = 0; comment = NULL;
            genpwd(pwd[i], settings.length, settings.number, settings.special);
            score = calcustrength(pwd[i]);
            switch(score) {
                case 1 : comment = "\e[0;31m[Very Weak]\e[0m";      break;
                case 2 : comment = "\e[0;31m[Weak]\e[0m";           break;
                case 3 : comment = "\e[0;33m[Weak]\e[0m";           break;
                case 4 : comment = "\e[0;33m[Good]\e[0m";           break;
                case 5 : comment = "\e[0;36m[Strong]\e[0m";         break;
                case 6 : comment = "\e[0;32m[Very Strong]\e[0m";    break;
                default: comment = "\e[1;31m[Not Valid]\e[0m";      break;
            }
            if (settings.amount == 1) { printf("%s %s\n", pwd[i], comment); }
            else { printf("Password no.%d : %s %s\n", i+1, pwd[i], comment); }
        }
        printf("\e[0;32mPasswords generated successfully\e[0m");
        deststrmat(pwd, settings.amount);
    }
    return 0;
}
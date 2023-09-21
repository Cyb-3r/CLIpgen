#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "generator.h"


// creates an array of strings
char** newstrmt(int matlength, int strlength) {
    char** strings = (char **)malloc(matlength * sizeof(char *));
    // NULL safe check
    if (strings == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    // actual init
    for (int i = 0; i < matlength; i++) {
        strings[i] = (char*)malloc(strlength * sizeof(char));
        // another NULL safe check
        if (strings[i] == NULL) {
            perror("Memory allocation failed");
            exit(1);
        }
    }
    
    // string array creation successful
    return strings;
}

// free a string array
int deststrmat(char** input, int matlength) {
    if (input == NULL) { perror("There is no memory to free"); return 1;}
    for (int i = 0; i < matlength; i++) {
        free(input[i]);
    }
    free(input);
    return 0;
}

char randc( int n, int s ) {
    // very basic randomizer setup [WIP]
    time_t timer = time(NULL);
    unsigned int seconds = difftime(timer, 0);

    int const strength = s*2 + n;
    int limit = 3;
    static const char* charset[] = {
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "0123456789",
        "!\"#$%&\'()*+,-./:;<=>?@[]^_`{|}~"
    };

    switch (strength) {
        default: limit = 3; break;
        case 0 : limit = 1; break;
        case 1 : limit = 2; break;
        case 2 : limit = 3; break;
        case 3 : limit = 3; break;
    }

    int setindex  = (rand() * seconds) % limit;
    static int max; max = strlen(charset[setindex]);
    int charindex = (rand() * seconds) % max;

    return charset[setindex][charindex];
}

void genpwd(char* buffer, int l, int n, int s) {
    for (int k = 0; k < l+1; k++) {
        buffer[k] = randc(n, s);
        if (k == l) { buffer[k] = *"\0"; }
    }
}

int calcustrength(char* input) {
    // safe check
    if (input == NULL) { perror("There is no string to read"); return -1; }

    static const char* charset = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&\'()*+,-./:;<=>?@[]^_`{|}~"};
    int cl = strlen(charset);
    int il = strlen(input);
    int c = 0, n = 0, s = 0; // char counters
    // reads the password and counts each types of characters
    for (int i = 0; i < il; i++) {
        for (int j = 0; j < cl; j++) {
            c += (input[i] == charset[j] && (j >= 0  && j < 52)) ? 1 : 0;
            n += (input[i] == charset[j] && (j >= 52 && j < 62)) ? 1 : 0;
            s += (input[i] == charset[j] && (j >= 62 && j < cl)) ? 1 : 0;
        }
    }
    int totalchars = c + n + s;
    if (totalchars != il) { perror("Invalid string error"); return -1; }

    // calculate score
    int score = 0;
    /*
     * Here are the factors that determines the password's strength :
     * - the length
     * - having numbers and / or special characters
     */
    if          (totalchars < 10)   { score += 1; }
    else if     (totalchars < 16)   { score += 2; }
    else                            { score += 3; }
    score += (c > 0) ? 1 : 0;
    score += (n > 0) ? 1 : 0;
    score += (s > 0) ? 1 : 0;

    return score;
}
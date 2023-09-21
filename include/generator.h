#ifndef GENERATOR_H
#define GENERATOR_H

// this struct carries the generation settings
typedef struct {
    // int values
    int length; // password char length
    int amount; // number of pwd generated
    // boolean values
    int number; // add numbers to pwd
    int special; // add special chars to pwd
} Settings;

// creates string array
char** newstrmt(int matlength, int strlength);
// destroy string array
int deststrmat(char** input, int matlength);
// gets a random character from charset
char randc(int n, int s);
// generates the password
void genpwd(char* buffer, int l, int n, int s);
// calculates password strength
int calcustrength(char* input);

#endif
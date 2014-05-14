//
//  depends.h
//  simpleShellEmu
//
//  Created by tihm on 07.05.14.
//  Copyright (c) 2014 org.tihmstar. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cleanInput(char **input);
int countOccurencesOfCharInString(const char *in, char mychar);
int isFile(const char*path);
int isDir(const char*path);
void appendString(char **myString, const char *toAppend);
void appendChar(char **myString, const char toAppend);
char *getCopyOfString(const char *orig);


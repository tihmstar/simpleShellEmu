//
//  depends.c
//  simpleShellEmu
//
//  Created by tihm on 07.05.14.
//  Copyright (c) 2014 org.tihmstar. All rights reserved.
//

#include "depends.h"
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int countOccurencesOfCharInString(const char *in, char mychar){
    
    char *copy = malloc(strlen(in)+1);
    int i;
    strncat(copy, in, strlen(in));
    for (i=0; in[i]; in[i]==mychar ? i++ : (int)in++);
    
    free(copy);
    return i;
}

char *getCopyOfString(const char *orig){
    
    char *ret = (char *)malloc(strlen(orig)+1);
    strncat(ret, orig, strlen(orig));
    ret[strlen(orig)] = 0;
    
    return ret;
}

void cleanInput(char **input){
    char *lCopy = getCopyOfString(*input);
    char *ret = malloc(1);
    
    //remove pre " "
    while (lCopy[0] == ' ') {
        lCopy++;
    }
    
    while (*lCopy) {
        if (*lCopy == ' ' && *(lCopy+1) == ' ') {
            lCopy++;
        }
        appendChar(&ret, *lCopy);
        lCopy++;
    }
    
    char *rett;
    if (ret[strlen(ret)] == ' ') {
        rett = malloc(strlen(ret));
        strncat(rett, ret, strlen(ret)-1);
    }else{
        rett = getCopyOfString(ret);
    }
    
    free(ret);
    free(lCopy- (strlen(*input)-strlen(lCopy)));
    
    *input = rett;
}

int isFile(const char*path){
    return ( access( path, F_OK ) != -1 );
}

int isDir(const char*path){
    DIR *dir;
    dir = opendir(path);
    
    int ret = (dir > 0);
    free(dir);
    return ret;
}

void appendString(char **myString, const char *toAppend){
    
    char* retString =malloc(strlen(*myString)+strlen(toAppend)+1);
    retString[0] = 0;
    strncat(retString, *myString, strlen(*myString));
    strncat(retString, toAppend, strlen(toAppend));
    retString[strlen(retString)+1] = 0;
    free(*myString);
    *myString = retString;
}

void appendChar(char **myString, const char toAppend){
    
    long int sLen = strlen(*myString);
    
    char* retString =malloc(sLen+2);
    retString[0] = 0;
    strncat(retString, *myString, strlen(*myString));
    retString[sLen] = toAppend;
    retString[sLen+1] = 0;
    free(*myString);
    *myString = retString;
}





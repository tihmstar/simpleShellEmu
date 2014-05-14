//
//  ls_module.c
//  simpleShellEmu
//
//  Created by tihm on 07.05.14.
//  Copyright (c) 2014 org.tihmstar. All rights reserved.
//

#include "depends.h"
#include "ls_module.h"

#include <dirent.h>

char *ls_module(const char *dirname){ //takes 1 parameter
    
    char *retString = NULL;
    char *buf = NULL ;
    
    //alloc once
    buf = (char *)malloc(1);
    retString = (char *)malloc(1);
    buf[0] = retString[0] = '\0';
    //
    
    DIR *dir;
    struct dirent *dirStruct;
    dir = opendir(dirname);
    if (dir)
    {
        while ((dirStruct = readdir(dir)) != NULL)
        {
            long retStringSize = strlen(buf)+dirStruct->d_namlen+2; // doing +2 for '\n' and '\0'
            
            if (dirStruct->d_name[0] == '.') { //hideing all files starting with "." by UNIX standards
                continue;
            }
            appendString(&retString, dirStruct->d_name);
            appendString(&retString, "\n");
        }
        closedir(dir);
        free(dirStruct);
    }else{
        printf("ERROR no such directory \"%s\"\n",dirname);
        retString = (char *)malloc(1);
        retString[0] = '\0';
    }
    
    free(buf);
    
    
    return retString;
}
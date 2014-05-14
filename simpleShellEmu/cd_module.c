//
//  cd_module.c
//  simpleShellEmu
//
//  Created by tihm on 12.05.14.
//  Copyright (c) 2014 org.tihmstar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "depends.h"





int cd_module(char **currentPath, const char *newPath){
    
    if (!isDir(newPath)) {
        printf("ERROR no such directory \"%s\"\n",newPath);
        return -1;
    }
    realpath(newPath, *currentPath);
    return 1;
}











//
//  main.c
//  simpleShellEmu
//
//  Created by tihm on 07.05.14.
//  Copyright (c) 2014 org.tihmstar. All rights reserved.
//

//default headers
#include <stdio.h>
#include <unistd.h>


//modules
#include "depends.h"
#include "ls_module.h"
#include "grep_module.h"
#include "echo_module.h"
#include "cd_module.h"

void pwd(char *currentDir){
    printf("%s $ ",currentDir);
}

char *doCommand(const char *input, const char *parameter, int prePipe){
    
    int startParam =0;
    
   // if (prePipe) {
    //}
    
    return 0;
}

int shellLoop(char **currentDir, const char *uInput){
    
    int pipeParts = countOccurencesOfCharInString(uInput, '|')+1;
    char *lInput = getCopyOfString(uInput);
    char **partsList = malloc(pipeParts);
    char *cmdRet =malloc(1);
    cmdRet[0] =0;
    
    int pipeNr = 0;
    for (; pipeNr<pipeParts; pipeNr++) {
        partsList[pipeNr] = strsep(&lInput, "|");
    }
    
    for (int i=0; i<=pipeNr; i++) {
        cmdRet = doCommand(partsList[pipeNr],cmdRet,i);
    }
    
    printf("pipes=%d\n",pipeParts);
    
    free(lInput);
    free(partsList);
    return 1;
}

int main(int argc, const char * argv[])
{
    char input[256];
    char *currentDir = (char *)malloc(2048);
    char *nInput = (char *)malloc(1);
    getcwd(currentDir, 2048);

    if (!strlen(currentDir)) {
        printf("ERROR getting current directory\n");
        exit(-1);
    }
    //dbg
    cd_module(&currentDir, "/Users/tihm");
    char *test = getCopyOfString("   asd  sras hi ");
    cleanInput(&test);
    printf("oo=1%s1\n",test);
    return 0;
    
    //shell loop
    pwd(currentDir);
    while (fgets(input, sizeof(input), stdin)){
        nInput = getCopyOfString(input);
        cleanInput(&nInput);
        if (!shellLoop(&currentDir,nInput)) break;
        pwd(currentDir);
        free(nInput);
    }
    
    return 0;
}


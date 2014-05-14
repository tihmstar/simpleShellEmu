//
//  grep_module.c
//  simpleShellEmu
//
//  Created by tihm on 11.05.14.
//  Copyright (c) 2014 org.tihmstar. All rights reserved.
//

#include <stdio.h>
#include "depends.h"
#include "grep_module.h"



char *grep_module_text(const char *input, const char * searchfor){
    
    //count lines
    int linesCount = countOccurencesOfCharInString(input, '\n');
        
    char *ret,*line;
#warning check next line
    line = (char*)malloc((strchr(input, '\n')-input+1)+1);
    
    //init empty string
    ret = malloc(1);
    ret[0] = 0;
    
    char *lCopy = getCopyOfString(input);
    
    
    for (; linesCount >0; linesCount--) {
        line = strsep(&lCopy, "\n");
        if (strstr(line, searchfor)) {
            appendString(&ret, line);
            appendString(&ret, "\n");
        }
    }
    free(lCopy);
    free(line);
    return ret;
}


char *grep_module_file(const char *file, const char * searchfor){
    
    if (!isFile(file)) {
        printf("ERROR: No such File %s",file);
        return NULL;
    }
    
    FILE *myFile = fopen(file, "r");
    char *filecontent, *line;
    filecontent = line = NULL;
    size_t linelenght = 0;
    
    // init empty string
    filecontent = malloc(1);
    filecontent[0] = 0;
    
    //read file to string
    while ((linelenght = getline(&line, &linelenght, myFile)) && (int)linelenght > 0 ) {
        appendString(&filecontent, line);
    }

    char *ret = grep_module_text(filecontent, searchfor);
    free(filecontent);
    free(line);
    return ret;
}


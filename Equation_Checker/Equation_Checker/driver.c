//
//  driver.c
//  Stack_Fun
//
//  Created by Barrett Stricklin on 2/23/19.
//  Copyright © 2019 Barrett Stricklin. All rights reserved.
//

#include <stdio.h>
#include "stack_arr.h"
#include <string.h>
#include <stdlib.h>

bool valid(char exp[80], Stack312 s, int len);
void newEq(char expression[80],int len, Stack312 s);
char missing=' ';

int main(int argc, char *argv[]){
    Stack312 s;
    char *fname = argv[1];//"/Users/barrett/Xcode Projects/Equation_Checker/Equation_Checker/exp.dat";//////argv[1];
    char expression[80];
    int len=0;
    
    
    makeStack(&s);
    
    FILE *fptr;
    fptr = fopen(fname, "r");
    
    if (fptr == NULL) {
        printf ("file error\n");
        exit(-1);
    }
    while(fgets(expression, 80, fptr) != NULL){
        newEq(expression, len, s); //for every line/equation, call equation checking function
    }
}

void newEq(char expression[80],int len, Stack312 s){
        bool isValid=valid(expression, s, len); //calls valid checker and prints result
        if(isValid)
            printf("%s === valid\n", expression);
        else
            printf("%s === missing %c \n",expression, missing);
    
}
bool valid(char exp[80], Stack312 s, int len){
    
    while(exp[len]){
        if(exp[len]=='\n') //finds the length of the eq
            exp[len]='\0';
        else
            len++;
    }
    
    
    for(int i=0;i<len;i++){
        if(exp[i]=='['||exp[i]=='<'||exp[i]=='(')
            push(exp[i],&s); //if the char is a left bracket, put it on the stack
            
        if(exp[i]==']'||exp[i]=='>'||exp[i]==')'){ //if closing/right bracket
            if(isEmpty(s))
                return false;
            switch(exp[i])                      //check for matching starting/left bracket
            {                                   //if no match, equation is not valid and missing var is
                case ']':                       //stored in global var
                    if(pop(&s)!='['){
                        missing='[';
                        return false;
                    }
                    break;
                case '>':
                    if(pop(&s)!='<'){
                        missing='<';
                        return false;
                    }
                    break;
                case ')':
                    if(pop(&s)!='('){
                        missing='(';
                        return false;
                    }
                    break;
                default:
                    return false;
                    
            }
        }}
        if(!isEmpty(s)){
            char leftover=pop(&s);  //if extra starting bracket, set missing var to matching closing char
            switch (leftover){
                case '(':
                    missing=')';
                    break;
                case '<':
                    missing='>';
                    break;
                case '[':
                    missing='>';
                    break;
                default:
                    break;
            }
            return false;
        }
            
    
    return true;
}

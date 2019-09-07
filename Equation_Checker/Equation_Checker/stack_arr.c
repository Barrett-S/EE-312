//
//  stack_arr.c
//  Equation_Checker
//
//  Created by Barrett Stricklin on 2/24/19.
//  Copyright © 2019 Barrett Stricklin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_arr.h"

#define MAX_ELEMENTS 100

//typedef char StackEntry;

void makeStack(Stack312 *s){
    s->top=-1;
}

bool isFull(Stack312 s){
    return s.top==MAX_ELEMENTS-1;
}

bool isEmpty(Stack312 s){
    return s.top==-1; //checks for last (-1) node
}

void push(StackEntry e,Stack312 *s){
    if(isFull(*s))
        return;
    s->top++;   //increment head of LL
    s->elements[s->top]=e; //adds e as head of linked list
}

StackEntry pop(Stack312 *s){
    if(isEmpty(*s))
        return false;
    return s->elements[s->top--]; //returns top and decrements it
}

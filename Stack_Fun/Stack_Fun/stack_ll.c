//
//  stack_ll.c
//  Stack_Fun
//
//  Created by Barrett Stricklin on 2/23/19.
//  Copyright © 2019 Barrett Stricklin. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Pixel {
    int row;
    int col;
    char color;
} Pixel;

typedef Pixel StackEntry;

typedef struct StackNode {
    StackEntry pixel;
    struct StackNode *next;
} StackNode;

typedef struct Stack312 {
    struct StackNode *top;
} Stack312;

void makeStack(Stack312 *s){
    s->top = NULL;
}

bool isFull(Stack312 s){
    return false;
}

bool isEmpty(Stack312 s){
    return(s.top == NULL);
}

void push(StackEntry e,Stack312 *s){
    struct StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
    temp->pixel.col=e.col;  //transfer attributes of e to temp
    temp->pixel.row=e.row;
    temp->pixel.color=e.color;
    
    temp->next=s->top; //insert temp node as new head of linked list
    s->top=temp;
}

StackEntry pop(Stack312 *s){
    StackEntry popped=s->top->pixel; //removed head of LL and return it
    StackNode *temp=s->top;
    s->top=s->top->next; //making node that is after head the new head
    free (temp);
    return popped;
    
    
}

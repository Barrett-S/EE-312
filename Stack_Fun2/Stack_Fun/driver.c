//
//  driver.c/
//  Stack_Fun
//
//  Created by Barrett Stricklin on 2/23/19.
//  Copyright © 2019 Barrett Stricklin. All rights reserved.
//

#include <stdio.h>
#include "stack_ll.h"
#include <string.h>
#include <stdlib.h>

void checkNeighbors(StackEntry e, char picture[25][25], Stack312 *s, int numRows, int numCols, char newColor, char oldColor);
void prompt(char picture[25][25], int numRows, int numCols);
//loads in file and prompts until exit
int main(int argc, char *argv[]){
    char *fname =argv[1];//"/Users/barrett/Xcode Projects/Stack_Fun/Stack_Fun/fake_picture.txt"
    char picture[25][25];
    int numCols=0;
    int numRows=0;
    FILE *fptr;
    fptr = fopen(fname, "r");
    
    if (fptr == NULL) {
        printf ("file error\n");
        exit(-1);
    }
    while(fgets(picture[numRows], 25, fptr) != NULL){
        numRows++; //counts number of rows
    }
    numCols = (int)strlen(picture[0])-1; //counts columns
    while(true){
    prompt(picture, numRows, numCols);
        printf("\n");
    }
    
}
//prompts for user input and calls modifying function for grid
void prompt(char picture[25][25], int numRows, int numCols){
    
    Stack312 s;
    makeStack(&s);
    
    StackEntry curr;
    int r=0;
    printf("\nEnter a row: ");
    scanf("%d", &r);
    if(r==-1)               //captures input and checks for exit condition
        exit(0);
    curr.row=r;
    printf("\nEnter a column: ");
    scanf("%d", &r);
    if(r==-1)
        exit(0);
    curr.col=r;
    getchar();
    printf("\nEnter a color: ");
    curr.color=getchar();
    
    char oldColor=picture[curr.row][curr.col];
    
    checkNeighbors(curr, picture, &s, numRows, numCols, curr.color,oldColor); //find first set of neighbors
    
    while(!isEmpty(s)){
        StackEntry lastPop=pop(&s); //for every cell that is changed, recheck the neighbors of those cells
        curr.row=lastPop.row;
        curr.col=lastPop.col;
        picture[lastPop.row][lastPop.col]=curr.color;
        checkNeighbors(curr, picture, &s, numRows, numCols,curr.color, oldColor);
    }
    for(int i = 0; i < numRows; i++)
        printf("%s", picture[i]);
}//checks neighboring cells of selected cell
    void checkNeighbors(StackEntry e, char picture[25][25], Stack312 *s, int numRows, int numCols, char newColor, char oldColor){
        int row=e.row;
        int col=e.col;
        bool noLeft = false;
        bool noRight=false;
        bool noUp=false;
        bool noDown=false;
        StackEntry neighbor;
        
        if(col==0)
            noLeft=true;    //checking for out of bounds conditions on every edge side
        if(col==numCols-1)
            noRight=true;
        if(row==0)
            noUp=true;
        if(row==numRows-1)
            noDown=true; 
        
        picture[row][col]=newColor;
        
        if(!noLeft&&picture[row][col-1]==oldColor){ //for all 8 neighbors, check to see if it can be filled with new color
            neighbor.row=row;
            neighbor.col=col-1;
            neighbor.color=picture[row][col-1];
            push(neighbor,s);
        }
        if(!noRight&&picture[row][col+1]==oldColor){
            neighbor.row=row;
            neighbor.col=col+1;
            neighbor.color=picture[row][col+1];
            push(neighbor,s);
        }
        if(!noUp&&picture[row-1][col]==oldColor){
            neighbor.row=row-1;
            neighbor.col=col;
            neighbor.color=picture[row-1][col];
            push(neighbor,s);
        }
        if(!noDown&&picture[row+1][col]==oldColor){
            neighbor.row=row+1;
            neighbor.col=col;
            neighbor.color=picture[row+1][col];
            push(neighbor,s);
        }
        if(!noUp&&!noLeft&&picture[row-1][col-1]==oldColor){
            neighbor.row=row-1;
            neighbor.col=col-1;
            neighbor.color=picture[row-1][col-1];
            push(neighbor,s);
        }
        if(!noUp&&!noRight&&picture[row-1][col+1]==oldColor){
            neighbor.row=row-1;
            neighbor.col=col+1;
            neighbor.color=picture[row-1][col+1];
            push(neighbor,s);
        }
        if(!noDown&&!noLeft&&picture[row+1][col-1]==oldColor){
            neighbor.row=row+1;
            neighbor.col=col-1;
            neighbor.color=picture[row+1][col-1];
            push(neighbor,s);
        }
        if(!noDown&&!noRight&&picture[row+1][col+1]==oldColor){
            neighbor.row=row+1;
            neighbor.col=col+1;
            neighbor.color=picture[row+1][col+1];
            push(neighbor,s);
        }
    }


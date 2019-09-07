//
//  driver.c
//  Stack_Fun/
//
//  Created by Barrett Stricklin on 2/23/19.
//  Copyright © 2019 Barrett Stricklin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void checkNeighbors(char picture[25][25], int numRows, int numCols, int row, int col, char newColor, char oldColor);
void prompt(char picture[25][25], int numRows, int numCols);
//repeats the prompting until exit condition is reached later in the prog
int main(int argc, char *argv[]){
    char *fname =argv[1];//"/Users/barrett/Xcode Projects/Recursion Flood Fill/Stack_Fun/fake_picture.txt";//
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
//prompts for user input and calls modifying function for grid (which contains recursive calls)
void prompt(char picture[25][25], int numRows, int numCols){
    int row=0;
    int col=0;
    char color;
    
    
    int r=0;
    printf("\nEnter a row: ");
    scanf("%d", &r);
    if(r==-1)               //captures input and checks for exit condition
        exit(0);
    if(r>=numRows) {         //reprompts if bad index
        printf("Bad index, try again");
        return;
    }
    row=r;
    
    printf("\nEnter a column: ");
    scanf("%d", &r);
    if(r==-1)
        exit(0);
    if(r>=numCols){
        printf("Bad index, try again");
        return;
    }
    col=r;
    
    getchar();
    printf("\nEnter a color: ");
    color=getchar();
    
    char oldColor=picture[row][col];
    
    checkNeighbors(picture, numRows, numCols, row, col,  color,oldColor); //find sets of neighbors
    
    for(int i = 0; i < numRows; i++)
        printf("%s", picture[i]);
}
//checks neighboring cells of selected cell
void checkNeighbors(char picture[25][25], int numRows, int numCols, int row, int col, char newColor, char oldColor){

    bool noLeft = false;
    bool noRight=false;
    bool noUp=false;
    bool noDown=false;
    
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
        picture[row][col-1]=newColor;
        checkNeighbors(picture, numRows, numCols, row, col-1, newColor,oldColor);
    }
    if(!noRight&&picture[row][col+1]==oldColor){
        picture[row][col+1]=newColor;
        checkNeighbors(picture, numRows, numCols, row, col+1, newColor,oldColor);
    }
    if(!noUp&&picture[row-1][col]==oldColor){
        picture[row-1][col]=newColor;
        checkNeighbors(picture, numRows, numCols, row-1, col, newColor,oldColor);
    }
    if(!noDown&&picture[row+1][col]==oldColor){
        picture[row+1][col]=newColor;
        checkNeighbors(picture, numRows, numCols, row+1, col, newColor,oldColor);
    }
    if(!noUp&&!noLeft&&picture[row-1][col-1]==oldColor){
        picture[row-1][col-1]=newColor;
        checkNeighbors(picture, numRows, numCols, row-1, col-1, newColor,oldColor);
    }
    if(!noUp&&!noRight&&picture[row-1][col+1]==oldColor){
        picture[row-1][col+1]=newColor;
        checkNeighbors(picture, numRows, numCols, row-1, col+1, newColor,oldColor);
    }
    if(!noDown&&!noLeft&&picture[row+1][col-1]==oldColor){
        picture[row+1][col-1]=newColor;
        checkNeighbors(picture, numRows, numCols, row+1, col-1, newColor,oldColor);
    }
    if(!noDown&&!noRight&&picture[row+1][col+1]==oldColor){
       picture[row+1][col+1]=newColor;
        checkNeighbors(picture, numRows, numCols, row+1, col+1, newColor,oldColor);
    }
}



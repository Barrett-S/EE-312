//
//  life.c
//  GameOfLife
//
//  Created by Barrett Stricklin on 2/6/19.
//  Copyright © 2019 Barrett Stricklin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "life.h"
#include <string.h>

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols){
    
    FILE *fptr;
    fptr = fopen(fname, "r");
    char tGrid[80][80];
    
    if (fptr == NULL) {
        printf ("file error\n");
        exit(-1);
    }
    else {
        char buf[BUFSIZ];
        while (fgets(tGrid[*numRows],sizeof(buf),fptr)) {   //fgets reads line of file into tGrid
            *numCols=(int)strlen(tGrid[*numRows]);   //find how many columns exist in world.txt
            grid[*numRows] = (char*)malloc(sizeof(char) * (*numCols));  //free up space for columns
            grid[*numRows] = tGrid[*numRows];   //move temporary grid to grid that is passed in
            (*numRows)++;               //increment
        }
        printf("\n");
    
    }}

void showWorld(char *grid[], int numRows, int numCols){
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols;j++) {
            
            if (grid[i][j] == '1') {
                printf("*");
            }                               //nested for loop examines every char in 2d array and prints the map
            else if (grid[i][j] == '0') {
                printf(".");
            }
        }
        
        printf("\n");
    }
    printf("\n");
}
int countNeighbors(char *grid[], int cRow, int cCol, int numRows, int numCols){
    bool noLeft = false,noRight=false,noUp=false, noDown=false; //set flags to check for out of bounds
    int count=0;    //counting alive cells
    noLeft = false;
    noRight=false;
    noUp=false;
    noDown=false;
    
    if(cCol==0)
        noLeft=true;    //checking for out of bounds conditions on every edge side
    if(cCol==numCols-1)
        noRight=true;
    if(cRow==0)
        noUp=true;
    if(cRow==numRows-1)
        noDown=true;
    
    
    if(!noLeft&&grid[cRow][cCol-1]=='1')    //counting alive cells surrounding current cell, check flags
        count++;
    if(!noRight&&grid[cRow][cCol+1]=='1')
        count++;
    if(!noUp&&grid[cRow-1][cCol]=='1')
        count++;
    if(!noDown&&grid[cRow+1][cCol]=='1')
        count++;
    if(!noUp&&!noLeft&&grid[cRow-1][cCol-1]=='1')  //checking diagonal cells now
        count++;
    if(!noUp&&!noRight&&grid[cRow-1][cCol+1]=='1')
        count++;
    if(!noDown&&!noLeft&&grid[cRow+1][cCol-1]=='1')
        count++;
    if(!noDown&&!noRight&&grid[cRow+1][cCol+1]=='1')
        count++;
    return count;
}
void iterateGeneration(char *grid[], int numRows, int numCols){
    bool alive=false;
    int count=0;
    char tGrid[numRows][numCols];
    for(int i=0;i<numRows;i++){
        for(int j = 0; j < numCols; j++) { //copy grid into temp grid
            tGrid[i][j]=grid[i][j];
        }}
    for(int i=0; i<numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            alive=false;
            count=countNeighbors(grid, i, j, numRows, numCols); //return number of neighbors into count
            if (tGrid[i][j] == '1')
                alive=true;     //store value of cell to be possibly transformed
            
            if(!alive&&count==3)
                tGrid[i][j]='1';   //A new cell is born on an empty square if is surrounded by exactly three neighboring cells
            
            if(alive&&count>3)  //A cell dies of overcrowding if it has four or more neighbors
                tGrid[i][j]='0';
            
            if(alive&&count<2)  //A cell dies of loneliness if it has zero or one neighbor
                tGrid[i][j]='0';
            
        }
        
        
        //printf("\n");
    }
    for(int i=0;i<numRows;i++){
        for(int j = 0; j < numCols; j++) { //put temp grid back into real grid space
            grid[i][j]=tGrid[i][j];
        }}
    
}



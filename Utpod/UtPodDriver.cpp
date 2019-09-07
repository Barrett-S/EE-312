//
// Created by tburf on 10/30/2018.
//
#include <algorithm>
#include <vector>
#include "UtPod.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

UtPod::UtPod(){ //default constructor
    songs = nullptr;
    memSize = MAX_MEMORY;
}
//overloaded constructor with passed in size, if wrong size, sets to max
UtPod::UtPod(int size){
    songs = nullptr;
    if((size <= 0) || (size > MAX_MEMORY))
        memSize = MAX_MEMORY;
    else
        memSize = size;
}
//add song to linked list
int UtPod::addSong(Song const &s){
    if(s.getTitle() == ""){
        cout << "Error, attempted to add a song with no title." << endl;
        return -1;
    }
    if(s.getArtist() == ""){
        cout << "Error, attempted to add a song with no artist." << endl;
        return -1;
    }
    if(s.getSize() < 1){
        cout << "Error, attempted to add a song with a size less than 1" << endl;
        return -1;
    }

    int memRemain = UtPod::getRemainingMemory();
    if((memRemain-s.getSize()) >= 0) { //check that there is enough memory for the song
        SongNode *song = new SongNode;  //allocate memory for a SongNode
        song->s = s;               //copy data
        song->next = songs;        //The new struct song's "next" points to what head pointer was pointing to
        songs = song;              //head now points to new song;
        return 0;
    }
    else
        cout << "Error, not enough memory." << endl;
        return -1;              //not enough memory
}
//removes song from linked list
int UtPod::removeSong(Song const &s) {
    SongNode *songPtr = songs;
    SongNode *prevPtr = NULL;
    if (songs->s == s) {
        songs = songs->next;
        return 0;
    }
    prevPtr = songPtr;
    songPtr = songPtr->next;
    while (songPtr != NULL) {
    if (songPtr->s.getTitle() == s.getTitle()) {
        prevPtr->next = songPtr->next;//removes element from linked list by routing around it
        delete songPtr;
        return 0;
    }
    prevPtr = songPtr;
    songPtr = songPtr->next;
}
return -1;
}


//shuffle in a vector by using time as a seed
void UtPod::shuffle(){
    srand(unsigned(time(0)));
    if(getNumberOfSongs() < 2) //do nothing if less than 2 songs
        return;
    int i;
    SongNode *newPtr = songs;    //copy head pointer
    vector<Song> songsVec; //create a vector of songs to shuffle
    for(i=0; i<getNumberOfSongs(); i++){    //fill vector
        songsVec.push_back(newPtr->s);
        newPtr = newPtr->next;
    }
    random_shuffle(songsVec.begin(), songsVec.end()); //shuffle the vector
    newPtr = songs;              //reset head ptr
    for(i=0; i<getNumberOfSongs(); i++){
        newPtr->s = songsVec.at(i);
        newPtr = newPtr->next;
    }
}
//prints all songs in list
void UtPod::showSongList(){
    SongNode *newPtr = songs; //create copy of head pointer
    while(newPtr != nullptr) {
        cout << newPtr->s.getTitle() << ", by " << newPtr->s.getArtist() << " - " << newPtr->s.getSize() << " MBs" << endl;
        newPtr = newPtr->next;
    }
}
//sorts songs using overloaded operators
//sorts by artist, then title, then size
//bubble sort algo
void UtPod::sortSongList(){
    SongNode *newPtr = songs;
    int listSize=getNumberOfSongs();
    Song *arr=new Song[listSize];
    for(int i=0; i<listSize;i++){
        arr[i]=newPtr->s;
        newPtr=newPtr->next;
    }
    for(int i=0;i<listSize-1;i++){
        for(int j=0;j<listSize-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
    newPtr = songs;              //reset head ptr
    for(int i=0; i<listSize;i++){
        newPtr->s = arr[i];
        newPtr = newPtr->next;
    }
    delete [] arr;
}
//helper function for bubble sort
void UtPod::swap(Song *song1, Song *song2)
{
    Song temp = *song1;
    *song1 = *song2;
    *song2= temp;
}
//clears all songs
void UtPod::clearMemory(){
    SongNode *songClear = songs;
    int listSize=getNumberOfSongs();
    for(int i=0; i<listSize; i++){
        removeSong(songClear->s);
        songClear = songClear->next;
    }
}
//checks total memory left
int UtPod::getRemainingMemory(){
    int remMemory = memSize;
    SongNode *newPtr = songs;
    while(newPtr != nullptr) {
        remMemory -= newPtr->s.getSize();
        newPtr = newPtr->next;
    }
    return remMemory;
}

//finds number of songs
int UtPod::getNumberOfSongs(){   //helper function
    SongNode *tempPtr = songs;
    int numSongs = 1; //needs to start at one
    while(tempPtr->next != nullptr){
        numSongs++;
        tempPtr = tempPtr->next;
    }
    return numSongs;
}
//destructor
UtPod::~UtPod(){
    clearMemory();
}
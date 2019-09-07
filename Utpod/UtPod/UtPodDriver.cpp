//
// Created by tburf on 10/30/2018.
//
#include "Song.h"
#include "UtPod.h"
using namespace std;

UtPod::UtPod(){ //default constructor
    new struct SongNode *songs;
    UtPod.songs->next = NULL;
    UtPod.memSize = MAX_MEMORY;
}
UtPod::UtPod(int size){
    new struct SongNode *songs;
    songs = nullptr;
    if((size <= 0) || (size > MAX_MEMORY))
        UtPod.memSize = MAX_MEMORY;
    else
        UtPod.memSize = size;
}
UtPod::int addSong(Song const &s){
    int memRemain = UtPod::getRemainingMemory();
    if(memRemain - s.size >= 0) { //check that there is enough memory for the song
        UtPod.SongNode;     //need to create a struct
        SongNode.s = *s;
        SongNode.next = UtPod.songs; //The new struct song's "next" points to what head pointer was pointing to
        UtPod.songs = s; //head now points to new song;
        return 0;
    }
    else
        return -1;
}
int UtPod::removeSong(Song const &s){
    SongNode *newPtr = UtPod.songs; //create copy of head pointer
    while(newPtr->s != s) { //iterate through songs until newPtr points to the song to remove
        if(newPtr->next = NULL) //return -2 if newPtr reached the end of the list aka song not found;
            return -2;
        newPtr = newPtr->next;
        if(newPtr->next->s = s) //if the next song is the one we want
            newPtr->next = newPtr->next->next; //make the song before the song we remove point to the song after the song we remove
    }
    delete (*newPtr); //delete the song
    return 0;
}
void UtPod::shuffle();{

}
void UtPod::showSongList(){
    SongNode *newPtr = UtPod.songs; //create copy of head pointer
    while(newPtr != NULL) { //if i use newPtr->next, it won't show the last song
        cout << newPtr->s.getTitle() << end1;
        cout << newPtr->s.getArtist() << end1;
        cout << newPtr->s.getSize() << end1;
    }
}
void UtPod::sortSongList(){

}
void UtPod::clearMemory(){

}
int UtPod::getRemainingMemory(){
    int remMemory = UtPod.memSize;
    SongNode *newPtr = UtPod.songs;
    while(newPtr != NULL)
        newPtr

}
UtPod::~UtPod(){

}

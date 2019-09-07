
#include "Song.h"
using namespace std;
Song::Song(){
    title = "";
    artist = "";
    size = 0;
}
Song::Song(string artist2, string title2, int size2){
    title = title2;
    artist = artist2;
    size = size2;
}
void Song::setTitle(string t){
    title = t;
}
void Song::setArtist(string a){
    artist = a;
}
void Song::setSize(int s){
    size = s;
}
//compares songs, first by artist, then title, then size
bool operator>(Song &s1, Song &s2){
    string st1=s1.getArtist();
    string st2=s2.getArtist();
    string t1=s1.getTitle();
    string t2=s2.getTitle();
    int si1=s1.getSize();
    int si2=s2.getSize();
    if(st1.compare(st2)==0){
        if(t1.compare(t2)==0)
            if(si1>si2)
                return true;
            else
                return false;
        if(t1.compare(t2)>0)
            return true;
            return false;
    }
    if(st1.compare(st2)>0)
        return true;
    return false;
}
//compares songs, first by artist, then title, then size
bool operator<(Song &s1, Song &s2){
    string st1=s1.getArtist();
    string st2=s2.getArtist();
    string t1=s1.getTitle();
    string t2=s2.getTitle();
    int si1=s1.getSize();
    int si2=s2.getSize();
    if(st1.compare(st2)==0){
        if(t1.compare(t2)==0)
            if(si1<si2)
                return true;
            else
                return false;
        if(t1.compare(t2)<0)
            return true;
        return false;
    }
    if(st1.compare(st2)<0)
        return true;
    return false;
}
//compares songs, first by artist, then title, then size
bool operator==(Song &s1, Song const &s2){
    string st1=s1.getArtist();
    string st2=s2.getArtist();
    string t1=s1.getTitle();
    string t2=s2.getTitle();
    int si1=s1.getSize();
    int si2=s2.getSize();
    if(st1.compare(st2)==0&&t1.compare(t2)==0&&si1==si2)
        return true;
    return false;
}


Song::~Song(){
    //todo
}

#include "Song.h"
using namespace std;
Song::Song(){
    title = "";
    artist = "";
    size = 0;
}
Song::Song(string *title2, string *artist2, int size2){
    title = *title2;
    artist = *artist2;
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

#include <string>
#include <iostream>
using namespace std;

class Song{
private:
    string title;
    string artist;
    int size;

public:
    Song(); //default constructor
    Song(string title2, string artist2, int size2); //overloaded constructor

    string getTitle() const
        {return title;}
    string getArtist() const
        {return artist;}
    int getSize() const
        {return size;}

    void setTitle(string t);
    void setArtist(string a);
    void setSize(int s);

    friend bool operator>(Song &s1, Song &s2);
    friend bool operator<(Song &s1, Song &s2);
    friend bool operator==(Song &s1, Song const &s2);

    ~Song(); //destructor
};
#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#endif //UTPOD_SONG_H

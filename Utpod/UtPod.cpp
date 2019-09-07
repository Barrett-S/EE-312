/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Beatles", "Hey Jude", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;

    t.showSongList();

    Song s2("Michael Jackson", "Thriller", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;

    t.showSongList();

    Song s3("Queen", "Bohemian Rhapsody", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    Song s4("Drake", "Yolo", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Santa Clause", "Jingle Bells", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("Michael Jackson", "Beat It(Remastered)", 5);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("Michael Jackson", "This Is It", 343);  //too big
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    Song s8("Michael Jackson", "", 12);         //missing title
    result = t.addSong(s8);
    cout << "add result = " << result << endl;

    Song s9("", "Baby Got Back", 12);         //missing artist
    result = t.addSong(s9);
    cout << "add result = " << result << endl;

    Song s10("Michael Jackson", "Smooth Criminal", 0);  //missing size
    result = t.addSong(s10);
    cout << "add result = " << result << endl;

    Song s11("Michael Jackson", "Beat It", 5);      //duplicate
    result = t.addSong(s11);
    cout << "add result = " << result << endl;


//t.showSongList();
    t.shuffle();
    t.shuffle();
    t.showSongList();
    cout<<"sorting now"<<endl;
    t.sortSongList();
    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.clearMemory();
    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;


}
//
//  main.cpp
//  FactoryMethodPattern
//
//  Created by bsarvan on 20/04/19.
//  Copyright © 2019 bsarvan. All rights reserved.
//

#include <iostream>
using namespace std;

enum genre_e{ROCK,POP, REGGAE, INVALID};

/*Base Class*/
class Music {
public:
    virtual void song() = 0;
    static Music* create(genre_e genre);
};

/*Derived class Rock from Music*/
class Rock: public Music
{
public:
    void song()
    {
        cout<<"Nirvana: Smells like a teen spirit\n";
    }
};

/*Derived class Pop from Music*/
class Pop: public Music
{
public:
    void song()
    {
        cout<<"Michael Jackson: Billie Jean\n";
    }
};

/*Derived class Reggae from Music*/
class Reggae: public Music
{
public:
    void song()
    {
        cout<<"Bob Marley: No woman, No cry\n";
    }
};

Music* Music::create(genre_e genre) {
    Music *music = NULL;
    
    /*Logic based on Genre*/
    switch(genre)
    {
        case ROCK:
            music = new Rock();
            break;
        case POP:
            music = new Pop();
            break;
        case REGGAE:
            music = new Reggae();
            break;
        default:
            music = NULL;
            break;
    }
    return music;
}

/*Factory Class*/
class MusicFactory
{
    Music* music;
public:
    MusicFactory() {
        genre_e genre = REGGAE;
        music = Music::create(genre);
    }
    Music* getMusic() {
        return music;
    }
  
};

int main()
{
    /*Create factory*/
    MusicFactory *musicFactory = new MusicFactory();
    
    /*Factory instantiating an object of type ROCK*/
    Music *music = musicFactory->getMusic();
    
    cout<<"Song: ";
    if(music)
        music->song();
    else
        cout<<"Wrong selection dude/dudette !!";
}

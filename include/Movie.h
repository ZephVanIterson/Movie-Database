//Zeph Van Iterson March-2020
//IMDB Movies Asignment
//This program reads in a text file of movies into a vector, then outputs the movies onto the screen
//It allows the user to add new movies, remove existing movies, or sort the movies
//When the user is finished they can type "stop" to end the program

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include<apmatrix.h>
#include <windows.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include<stdlib.h>
#include<math.h>
#include <bits/stdc++.h>

const int width = 1500;
const int height = 480;
#define white al_map_rgb(0xff, 0xff, 0xff)
#define black al_map_rgb(0x3C, 0x64, 0x78)

using namespace std;

//Create movie class
class Movie
{
    public:
        //Constructors and destructors
        Movie();
        ~Movie();

        //Getters and setters
        string Gettitle() { return title; }
        void Settitle(string val) { title = val; }

        string GetdirectorLastName() { return directorLastName; }
        void SetdirectorLastName(string val) { directorLastName = val; }

        string GetdirectorFirstName() { return directorFirstName; }
        void SetdirectorFirstName(string val) { directorFirstName = val; }

        string GetstarLastName() { return starLastName; }
        void SetstarLastName(string val) { starLastName = val; }

        string GetstarFirstName() { return starFirstName; }
        void SetstarFirstName(string val) { starFirstName = val; }

        string Getstudio() { return studio; }
        void Setstudio(string val) { studio = val; }

        int GetreleaseYear() { return releaseYear; }
        void SetreleaseYear(int val) { releaseYear = val; }

        string Getlanguage() { return language; }
        void Setlanguage(string val) { language = val; }

        float Getrating() { return rating; }
        void Setrating(float val) { rating = val; }

    protected:

    private:
        //Variables
        string title;
        string directorLastName;
        string directorFirstName;
        string starLastName;
        string starFirstName;
        string studio;
        int releaseYear;
        string language;
        float rating;
};

//Create database class
class Database
{
    public:
        //Constructors and destructors
        Database();
        Database(int num);
        ~Database();

        //Variables
        vector<Movie> database;
        int numMovies;

        //functions
        void addMovie();
        void removeMovie();
        int titleToIndex(string title);
        void sortByYear();
        void sortByRating();
        void sortByStudio();
        void printMovies(ALLEGRO_FONT *font);

    protected:

    private:
};

//Prototype functions
int initializeAllegro();
int checkAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);
int getNumLines(ifstream &file);
void readFile(Database &database, ifstream &file);


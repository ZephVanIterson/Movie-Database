#include "Movie.h"

//Movie constructor
Movie::Movie()
{
    //ctor
}

//Movie destructor
Movie::~Movie()
{
    //dtor
}

//Database constructor
Database::Database()
{

}

//Database constructor
Database::Database(int num)
{
    numMovies = num;
}

//Database destructor
Database::~Database()
{
    //dtor
}

//Allows the user to enter information for a new movie, and thenadds it to the database
void Database::addMovie()
{
    //Declare and initialize variables
    Movie temp;
    string tempTitle;
    string tempDirectorLastName;
    string tempDirectorFirstName;
    string tempStarLastName;
    string tempStarFirstName;
    string tempStudio;
    int tempReleaseYear = 0;
    string tempLanguage;
    float tempRating = 0;

    //Get input from user
    cout<<"What is the title?";
    cin>>tempTitle;
    cout<<"What is the director's last name?";
    cin>>tempDirectorLastName;
    cout<<"What is the director's first name?";
    cin>>tempDirectorFirstName;
    cout<<"What is the star's last name?";
    cin>>tempStarLastName;
    cout<<"What is the star's first name?";
    cin>>tempStarFirstName;
    cout<<"What is the studio?";
    cin>>tempStudio;
    cout<<"What is the release year?";
    cin>>tempReleaseYear;
    cout<<"What is the language?";
    cin>>tempLanguage;
    cout<<"What is the rating?";
    cin>>tempRating;

    //Fill temporary movie with information from user
    temp.Settitle(tempTitle);
    temp.SetdirectorLastName(tempDirectorLastName);
    temp.SetdirectorFirstName(tempDirectorFirstName);
    temp.SetstarLastName(tempStarLastName);
    temp.SetstarFirstName(tempStarFirstName);
    temp.Setstudio(tempStudio);
    temp.SetreleaseYear(tempReleaseYear);
    temp.Setlanguage(tempLanguage);
    temp.Setrating(tempRating);

    //put the temporary movie into the database and increase the number of movies
    database.push_back(temp);
    numMovies++;
}

//Allows the user to enter the name of a movie which is deleted
void Database::removeMovie()
{
    //initaliaze and declare variable
    string title = " ";

    //Get input from user
    cout<<"What is the title of the movie you want to delete?";
    getline(cin, title);

    //Erases the movie with the title that the user entered and reduces the number of movies
    database.erase(database.begin() + titleToIndex(title));
    numMovies--;

}

//converts a given movie title to its position in the database
int Database::titleToIndex(string title)
{
    for(int i =0; i<numMovies; i++)
    {
        if(title == database[i].Gettitle())
            return i;
    }

    return 404;
}

//Sorts the movies by release year
void Database::sortByYear()
{

    vector<int> releaseYear;
    vector<Movie> temp;

    for(int i =0; i<numMovies; i++)
    {
        releaseYear.push_back(database[i].GetreleaseYear());
    }

    sort(releaseYear.begin(),releaseYear.end());

    for(int k = 0; k<numMovies; k++)
    {
        for(int i = 0; i<numMovies; i++)
        {
            if(releaseYear[k]==database[i].GetreleaseYear())
            {
                temp.push_back(database[i]);
                database.erase(database.begin()+i);
                i = numMovies;
            }
        }
    }
    database = temp;
}

//Sorts the movies by rating
void Database::sortByRating()
{

    vector<float> rating;
    vector<Movie> temp;

    for(int i =0; i<numMovies; i++)
    {
        rating.push_back(database[i].Getrating());
    }

    sort(rating.begin(),rating.end());

    for(int k = 0; k<numMovies; k++)
    {
        for(int i = 0; i<numMovies; i++)
        {
            if(rating[k]==database[i].Getrating())
            {
                temp.push_back(database[i]);
                database.erase(database.begin()+i);
                i = numMovies;
            }
        }
    }
    database = temp;
}

//Sorts the movies alphabetically by studio name
void Database::sortByStudio()
{
    vector<string> studio;
    vector<Movie> temp;

    for(int i =0; i<numMovies; i++)
    {
        studio.push_back(database[i].Getstudio());
    }

    sort(studio.begin(),studio.end());

    for(int k = 0; k<numMovies; k++)
    {
        for(int i = 0; i<numMovies; i++)
        {
            if(studio[k]==database[i].Getstudio())
            {
                temp.push_back(database[i]);
                database.erase(database.begin()+i);
                i = numMovies;
            }
        }
    }
    database = temp;
}

//Outputs all movies in the database to the screen
void Database::printMovies(ALLEGRO_FONT *font) {

    for(int i =0;i<numMovies;i++) {

        al_draw_text(font, black, 60+150*i, 0, ALLEGRO_ALIGN_CENTER, database[i].Gettitle().c_str());
        al_draw_text(font, black, 60+150*i, 50, ALLEGRO_ALIGN_CENTER, database[i].GetdirectorLastName().c_str());
        al_draw_text(font, black, 60+150*i, 100, ALLEGRO_ALIGN_CENTER, database[i].GetdirectorFirstName().c_str());
        al_draw_text(font, black, 60+150*i, 150, ALLEGRO_ALIGN_CENTER, database[i].GetstarLastName().c_str());
        al_draw_text(font, black, 60+150*i, 200, ALLEGRO_ALIGN_CENTER, database[i].GetstarFirstName().c_str());
        al_draw_text(font, black, 60+150*i, 250, ALLEGRO_ALIGN_CENTER, database[i].Getstudio().c_str());
        al_draw_text(font, black, 60+150*i, 300, ALLEGRO_ALIGN_CENTER, to_string(database[i].GetreleaseYear()).c_str());
        al_draw_text(font, black, 60+150*i, 350, ALLEGRO_ALIGN_CENTER, database[i].Getlanguage().c_str());
        al_draw_text(font, black, 60+150*i, 400, ALLEGRO_ALIGN_CENTER, to_string(database[i].Getrating()).c_str());

        al_draw_text(font, black, 470, 460, ALLEGRO_ALIGN_CENTER, "Use the console to sort, add, and remove movies");
    }
}






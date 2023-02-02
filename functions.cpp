#include"Movie.h"

//Reads in information from a file to a movie vector within a database object
void readFile(Database &database, ifstream &file)
{
   //Declare and initialize variables
    string dump;
    Movie temp;
    string tempTitle;
    string tempDirectorLastName;
    string tempDirectorFirstName;
    string tempStarLastName;
    string tempStarFirstName;
    string tempStudio;
    int tempReleaseYear;
    string tempLanguage;
    float tempRating;

    for(int i = 0; i<database.numMovies; i++)
    {
        //Readin the file
        getline(file, tempTitle);
        getline(file, tempDirectorLastName);
        getline(file, tempDirectorFirstName);
        getline(file, tempStarLastName);
        getline(file, tempStarFirstName);
        getline(file, tempStudio);
        file>>tempReleaseYear;
        getline(file, dump);
        getline(file, tempLanguage);
        file>>tempRating;
        getline(file, dump);

        //Put information from file into a temporary movie object
        temp.Settitle(tempTitle);
        temp.SetdirectorLastName(tempDirectorLastName);
        temp.SetdirectorFirstName(tempDirectorFirstName);
        temp.SetstarLastName(tempStarLastName);
        temp.SetstarFirstName(tempStarFirstName);
        temp.Setstudio(tempStudio);
        temp.SetreleaseYear(tempReleaseYear);
        temp.Setlanguage(tempLanguage);
        temp.Setrating(tempRating);

        //puts the temporary movie object into the database
        database.database.push_back(temp);
    }

}

//initalizes allegrp
int initializeAllegro()
{

    // Initialize Allegro
    al_init();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    return 0;
}

//Checks that allegro, display, and font are working
int checkAllegro(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font)
{

    //check integrity
    if (!display)
    {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // Initialize primitive add on
    //check integrity
    if (!al_init_primitives_addon())
    {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if (!font){
        al_show_native_message_box(display, "Error", "Error", "Could not load comic.ttf",
                                    nullptr, ALLEGRO_MESSAGEBOX_ERROR);
      return -1;
   }

    al_set_window_title(display, "IMDB Movies");

    return 0;
}

//Gets the number of lines in a file
int getNumLines(ifstream &file)
{

    int lines = 0;
    string dump1 = "test1";
    string dump2 = "test2";

    while(dump1!=dump2)
    {
        dump1 = dump2;
        getline(file, dump2);
        lines++;
    }
    return lines-1;
}


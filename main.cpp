#include "Movie.h"

int main()
{
    //Declare and initialize variables
    string command = " ";
    bool play = true;

    //Get the number of lines in the file
    ifstream file("database.txt");
    int numLines = getNumLines(file);
    file.close();

    //Create movie database and give it the number of movies
    Database database(numLines/9);

    //read in the file to the database
    file.open("database.txt");
    readFile(database, file);
    file.close();

    //Initialize and check allegro
    initializeAllegro();
    ALLEGRO_DISPLAY *display = al_create_display(width, height);
    ALLEGRO_FONT *font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 18, 0);
    checkAllegro(display, font);

    //Print the movies
    al_clear_to_color(white);
    database.printMovies(font);
    al_flip_display();


    //Allow the user to edit the database or end the program
            cout<<"Type..."<<endl;
        cout<< "    'add' to add a movie"<<endl;
        cout<< "    'remove' to remove a movie"<<endl;
        cout<< "    'stop' to end the program"<<endl;
        cout<< "    'sortByYear' to sort the movies by release year"<<endl;
        cout<< "    'sortByRating' to sort the movies by  rating"<<endl;
        cout<< "    'sortByStudio' to sort the movies alphabetically by studio"<<endl<<endl;

    while(play ==true)
    {
        cout<<"Enter your command: ";
        getline(cin, command);

        if(command == "add")
        {
            database.addMovie();
        }
        else if(command == "remove")
        {
            database.removeMovie();
        }
        else if(command == "stop")
        {
            play = false;
        }
        else if(command == "sortByYear")
        {
            database.sortByYear();
        }
        else if(command == "sortByRating")
        {
            database.sortByRating();
        }
        else if(command == "sortByStudio")
        {
            database.sortByStudio();
        }
        else
            cout<<"invalid command"<<endl;

        al_clear_to_color(white);
        database.printMovies(font);
        al_flip_display();
    }

    //destroy display
    al_destroy_display(display);

    return 0;
}

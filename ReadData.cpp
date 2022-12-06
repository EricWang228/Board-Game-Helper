#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "BoardGameOBJ/BoardGame.h"
#include "SCHash.cpp"
using namespace std;

void printall(vector<BoardGame> new_test);

int main()
{
    // open file
    fstream file;
    file.open("bgg_dataset.csv");

    // line of data
    string line = "";

    // read in one line of input
    getline(file, line);

    // variables to store data
    string name;

    string yearPublished;

    string minPlayers;

    string maxPlayers;

    string minAge;

    string avgRating;
    // data order from csv file
    // ID;Name;Year Published;Min Players;Max Players;Play Time;Min Age;

    // while loop until there's no more lines
    while(getline(file, line))
    {
        stringstream input(line);

        // name, skip id
        getline(input, name, ';');
        getline(input, name, ';');

        // year published
        getline(input, yearPublished, ';');

        // min players
        getline(input, minPlayers, ';');

        // max players
        getline(input, maxPlayers, ';');

        // min age, skip play time
        getline(input, minAge, ';');
        getline(input, minAge, ';');
        
        // avg rating, and changes ',' to '.'
        getline(input, avgRating, ';');
        getline(input, avgRating, ';');
        if(avgRating.find(',') != string::npos){
            avgRating.replace(avgRating.find(','), 1, ".");
        }
 
        BoardGame test = BoardGame(name, yearPublished, minPlayers, maxPlayers, minAge, avgRating);
    } 

}

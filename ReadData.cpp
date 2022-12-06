#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "BoardGameOBJ/BoardGame.h"
using namespace std;

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

    string yearPublished_;
    int yearPublished;

    string minPlayers_;
    int minPlayers;

    string maxPlayers_;
    int maxPlayers;

    string minAge_;
    int minAge;

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
        getline(input, yearPublished_, ';');

        // min players
        getline(input, minPlayers_, ';');

        // max players
        getline(input, maxPlayers_, ';');

        // min age, skip play time
        getline(input, minAge_, ';');
        getline(input, minAge_, ';');

        // convert to integers to fit object parameters
        yearPublished = stoi(yearPublished_);
        minPlayers = stoi(minPlayers_);
        maxPlayers = stoi(maxPlayers_);
        minAge = stoi(minAge_);

        BoardGame test = BoardGame(name, yearPublished, minPlayers, maxPlayers, minAge);
        test.print_details();
    } 
}

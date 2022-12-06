#pragma once
#include <string>
#include <iostream>
using namespace std;
class BoardGame
{
    private:
    // variables
    string name;
    unsigned int year;
    unsigned int min_player;
    unsigned int max_players;
    unsigned int age;
    public:
    // Constructors
    BoardGame();
    BoardGame(string name, unsigned int year, unsigned int min_players, unsigned int max_players, unsigned int age);
    // Operator Overload
    BoardGame& operator=(const BoardGame& other);
    
    // Get methods
    string get_name();
    unsigned int get_year();
    unsigned int get_min_players();
    unsigned int get_max_players();
    unsigned int get_age();
    // print object
    void print_details();
};

BoardGame::BoardGame()
{
    name = "";
    year = 0;
    min_player = 0;
    max_players = 0;
    age = 0;
}

BoardGame::BoardGame(string name, unsigned int year, unsigned int min_player, unsigned int max_players, unsigned int age)
{
    this->name = name;
    this->year = year;
    this->min_player = min_player;
    this->max_players = max_players;
    this->age = age;
}

BoardGame& BoardGame::operator=(const BoardGame& other){
    this->name = other.name;
    this->year = other.year;
    this->min_player = other.min_player;
    this->max_players = other.max_players;
    this->age = other.age;
    return *this;
}

std::string BoardGame::get_name()
{
    return name;
}

unsigned int BoardGame::get_year()
{
    return year;
}

unsigned int BoardGame::get_min_players()
{
    return min_player;
}

unsigned int BoardGame::get_max_players()
{
    return max_players;
}

unsigned int BoardGame::get_age()
{
    return age;
}

void BoardGame::print_details()
{
    cout << "Board Game Name: " << name << endl;
    cout << "Year Published: " << year << endl;
    cout << "Min Players: " << min_player << endl;
    cout << "Max Players: " << max_players << endl;
    cout << "Min Age: " << age << endl;
}

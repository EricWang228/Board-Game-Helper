#pragma once
#include <string>
#include <iostream>

class BoardGame
{
    private:
    // variables
    std::string name;
    unsigned int year;
    unsigned int min_player;
    unsigned int max_players;
    unsigned int age;
    public:
    // Constructors
    BoardGame();
    BoardGame(std::string name, unsigned int year, unsigned int min_players, unsigned int max_players, unsigned int age);
    // Get methods
    std::string get_name();
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

BoardGame::BoardGame(std::string name, unsigned int year, unsigned int min_players, unsigned int max_players, unsigned int age)
{
    this->name = name;
    this->year = year;
    this->min_player = min_player;
    this->max_players = max_players;
    this->age = age;
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
    std::cout << "Board Game Name: " << name << std::endl;
    std::cout << "Year Published: " << year << std::endl;
    std::cout << "Min Players: " << min_player << std::endl;
    std::cout << "Max Players: " << max_players << std::endl;
    std::cout << "Min Age: " << age << std::endl;
}

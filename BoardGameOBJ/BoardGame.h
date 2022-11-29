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
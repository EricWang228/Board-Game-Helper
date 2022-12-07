#include<iostream>
#include<chrono>
#include<fstream>
#include<string>
#include<sstream>
#include "OAHash.cpp"
#include "SCHash.cpp"
#include "BoardGameOBJ/BoardGame.h"
using namespace std;
using namespace std::chrono;

void readData(SCHash& SC, OAHash& OA);

int main() {

	int option, filter, contOpt, hashType, year, minPlay, maxPlay, minAge;
	string name;
	SCHash SC;
	OAHash OA;
	readData(SC, OA);

	auto start = system_clock::now(), stop = system_clock::now();

	cout << "Welcome To Board Bot!" << endl;

	
	while (true) {
		cout << "\nSelect An Option:" << endl;
		cout << "1. Print All Board Games" << endl;
		cout << "2. Search By Filter" << endl;
		cout << "3. Exit" << endl;

		cin >> option;

		if (option == 1) { // Print All Board Games
			// takes input directly and outputs it
		}

		else if (option == 2) { // Search by Filter
	
			while (true) {
				cout << "\nSelect A Filter:" << endl;
				cout << "1. Name" << endl;
				cout << "2. Year Published" << endl;
				cout << "3. Min Players" << endl;
				cout << "4. Max Players" << endl;
				cout << "5. Min Age" << endl;
				cout << "6. Back To Options" << endl;

				cin >> filter;

				if (filter > 0 && filter < 7) {
					break;
				}
				
				cout << "\nInvalid Filter\nPlease Select: 1, 2, 3, 4, 5 or 6" << endl;
			}

			if (filter == 1) { // Name filter
				cout << "\nEnter Board Game Name: " << endl;
				cin >> name;

				while (true) {
					cout << "\nSelect A Collision Resolution Strategy: " << endl;
					cout << "1. Open Addressing" << endl;
					cout << "2. Separate Chaining" << endl;

					cin >> hashType;

					if (hashType > 0 && hashType < 3) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1 or 2" << endl;;
				}

				if (hashType == 1) {
					start = system_clock::now();
					// call function for instance of name Open Addressing
					OA.find_all(name);
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					// call function for instance of name Separate Chaining
					SC.find_all(name);
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Separate Chaining: " << duration.count() << " microseconds" << endl;
				}
			}

			else if (filter == 2) { // Year filter
				cout << "\nEnter Year Board Game was Published: " << endl;
				cin >> year;

				while (true) {
					cout << "\nSelect A Collision Resolution Strategy: " << endl;
					cout << "1. Open Addressing" << endl;
					cout << "2. Separate Chaining" << endl;

					cin >> hashType;

					if (hashType > 0 && hashType < 3) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1 or 2" << endl;;
				}

				if (hashType == 1) {
					start = system_clock::now();
					// call function to find year Open Addressing
					OA.find_all_year(to_string(year));
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					// call function to find year Separate Chaining
					SC.find_all_year(to_string(year));
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Separate Chaining: " << duration.count() << " microseconds" << endl;
				}
			}

			else if (filter == 3) { // Min Player filter
				while (true) {
					cout << "\nInput Minimum Players (1 - 10, 10+ Represented by 10): " << endl;

					cin >> minPlay;

					if (minPlay > 0 && minPlay < 11) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select An Integer 1 - 10" << endl;
				}

				while (true) {
					cout << "\nSelect A Collision Resolution Strategy: " << endl;
					cout << "1. Open Addressing" << endl;
					cout << "2. Separate Chaining" << endl;

					cin >> hashType;

					if (hashType > 0 && hashType < 3) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1 or 2" << endl;;
				}

				if (hashType == 1) {
					start = system_clock::now();
					// call function to find minPlayers Open Addressing
					OA.find_all_minPlayers(to_string(minPlay));
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					SC.find_all_minPlayers(to_string(minPlay));
					// call function to find minPlayers Separate Chaining
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Separate Chaining: " << duration.count() << " microseconds" << endl;
				}
			}

			else if (filter == 4) { // Max Player filter
				while (true) {
					cout << "\nInput Maximum Players (1 - 10, 10+ Represented by 10): " << endl;

					cin >> maxPlay;

					if (maxPlay > 0 && maxPlay < 11) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select An Integer 1 - 10" << endl;
				}

				while (true) {
					cout << "\nSelect A Collision Resolution Strategy: " << endl;
					cout << "1. Open Addressing" << endl;
					cout << "2. Separate Chaining" << endl;

					cin >> hashType;

					if (hashType > 0 && hashType < 3) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1 or 2" << endl;;
				}

				if (hashType == 1) {
					start = system_clock::now();
					// call function to find maxPlayer Open Addressing
					OA.find_all_maxPlayers(to_string(maxPlay));
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					// call function to find maxPlayer Separate Chaining
					SC.find_all_maxPlayers(to_string(maxPlay));
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Separate Chaining: " << duration.count() << " microseconds" << endl;
				}
			}

			else if (filter == 5) { // Max Age Filter
				while (true) {
					cout << "\nInput Minimum Age (1 - 18, 18+ Represented by 18): " << endl;

					cin >> minAge;

					if (minAge > 0 && minAge < 19) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1, 2, 3, 4, or 5" << endl;
				}

				while (true) {
					cout << "\nSelect A Collision Resolution Strategy: " << endl;
					cout << "1. Open Addressing" << endl;
					cout << "2. Separate Chaining" << endl;

					cin >> hashType;

					if (hashType > 0 && hashType < 3) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1 or 2" << endl;;
				}

				if (hashType == 1) {
					start = system_clock::now();
					// call function to find minAge Open Addressing
					OA.find_all_age(to_string(minAge));
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					// call function to find minAge Separate Chaining
					SC.find_all_age(to_string(minAge));
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Separate Chaining: " << duration.count() << " microseconds" << endl;
				}
			}
			else if (filter == 6) { // Back to Options
				continue;
			}
		}

		else if (option == 3) { // Exit
			cout << "\nThanks for Using Board Bot!" << endl;
			break;
		}

		else {
			cout << "\nInvalid Option\nPlease Select: 1, 2, or 3" << endl;
			continue;
		}

		while (true) { // Continue Option
			cout << "\nDo you want to continue?" << endl;
			cout << "1. Yes, bring me to the options menu" << endl;
			cout << "2. No, let me exit" << endl;

			cin >> contOpt;

			if (contOpt > 0 && contOpt < 3) {
				break;
			}

			cout << "\nInvalid Option\nPlease Select: 1 or 2" << endl;
		}

		if (contOpt == 2) { // Exit
			cout << "\nThanks for Using Board Bot!" << endl;
			break;
		}
	}
}

void readData(SCHash& SC, OAHash& OA){
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
		SC.insert(name, test);
		OA.insert(name, test);
    } 
}
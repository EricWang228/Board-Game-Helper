#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

int main() {

	int option, filter, contOpt, hashType, year, minPlay, maxPlay, minAge;
	string name;
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
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					// call function for instance of name Separate Chaining
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
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					// call function to find year Separate Chaining
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
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
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
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					// call function to find maxPlayer Separate Chaining
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
					auto duration = duration_cast<microseconds>(system_clock::now() - start);
					cout << "\nExecution Time with Open Addressing: " << duration.count() << " microseconds" << endl;
				}

				if (hashType == 2) {
					start = system_clock::now();
					// call function to find minAge Separate Chaining
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
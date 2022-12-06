#include<iostream>

using namespace std;
#include<iostream>
#include "BoardGameOBJ/BoardGame.h"

using namespace std;

int main() {

	int option, filter, contOpt, year, minPlay, maxPlay, minAge;
	string name;

	cout << "Welcome To Board Bot!" << endl;

	while (true) {
		cout << "\nSelect An Option:" << endl;
		cout << "1. Print All Board Games" << endl;
		cout << "2. Search By Filter" << endl;
		cout << "3. Exit" << endl;

		cin >> option;

		if (option == 1) {
			// iterate through and call print function
		}
		else if (option == 2) { // SUBJECT TO CHANGE
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


				// call function
				// output time for both hash functions
				//cout << "Time: " << something << endl;
			}
			else if (filter == 2) { // Year filter
				cout << "\nEnter Year Board Game was Published: " << endl;
				cin >> year;
				// call function
				// output time for both hash functions
			}
			else if (filter == 3) { // Min Player filter
				while (true) {
					cout << "\nMinimum Players: " << endl;
					cout << "1. 1 - 2" << endl;
					cout << "2. 3 - 4" << endl;
					cout << "3. 5 - 6" << endl;
					cout << "4. 7 - 8" << endl;
					cout << "5. 9 - 10" << endl;
					cout << "6. 10+" << endl;

					cin >> minPlay;

					if (minPlay > 0 && minPlay < 7) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1, 2, 3, 4, 5 or 6" << endl;
				}
				// call function
				// output time for both hash functions
			}
			else if (filter == 4) { // Max Player filter
				while (true) {
					cout << "\nMaximum Players: " << endl;
					cout << "1. 1 - 2" << endl;
					cout << "2. 3 - 4" << endl;
					cout << "3. 5 - 6" << endl;
					cout << "4. 7 - 8" << endl;
					cout << "5. 9 - 10" << endl;
					cout << "6. 10+" << endl;

					cin >> maxPlay;

					if (maxPlay > 0 && maxPlay < 7) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1, 2, 3, 4, 5 or 6" << endl;
				}
				// call function
				// output time for both hash functions
			}
			else if (filter == 5) { // Max Age Filter
				while (true) {
					cout << "\nMinimum Age: " << endl;
					cout << "1. 1 - 5" << endl;
					cout << "2. 6 - 11" << endl;
					cout << "3. 12 - 15" << endl;
					cout << "4. 16 - 17" << endl;
					cout << "5. 18+" << endl;

					cin >> minAge;

					if (minAge > 0 && minAge < 6) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1, 2, 3, 4, or 5" << endl;
				}
				// call function
				// output time for both hash functions
			}
			else if (filter == 6) { // Back to Options
				continue;
			}
		}

		else if (option == 3) {
			cout << "\nThanks for Using Board Bot!" << endl;
			break;
		}
		else {
			cout << "\nInvalid Option\nPlease Select: 1, 2, or 3" << endl;
			continue;
		}

		while (true) {
			cout << "\nDo you want to continue?" << endl;
			cout << "1. Yes, bring me to the options menu" << endl;
			cout << "2. No, let me exit" << endl;

			cin >> contOpt;

			if (contOpt > 0 && contOpt < 3) {
				break;
			}

			cout << "\nInvalid Option\nPlease Select: 1 or 2" << endl;
		}

		if (contOpt == 2) {
			cout << "\nThanks for Using Board Bot!" << endl;
			break;
		}
		
	}
}
int main() {

	int option, filter, contOpt, year, minPlay, maxPlay, minAge;
	string name;

	cout << "Welcome To Board Bot!" << endl;

	while (true) {
		cout << "\nSelect An Option:" << endl;
		cout << "1. Print All Board Games" << endl;
		cout << "2. Search By Filter" << endl;
		cout << "3. Exit" << endl;

		cin >> option;

		if (option == 1) {
			// iterate through and call print function
		}
		else if (option == 2) { // SUBJECT TO CHANGE
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


				// call function
				// output time for both hash functions
				//cout << "Time: " << something << endl;
			}
			else if (filter == 2) { // Year filter
				cout << "\nEnter Year Board Game was Published: " << endl;
				cin >> year;
				// call function
				// output time for both hash functions
			}
			else if (filter == 3) { // Min Player filter
				while (true) {
					cout << "\nMinimum Players: " << endl;
					cout << "1. 1 - 2" << endl;
					cout << "2. 3 - 4" << endl;
					cout << "3. 5 - 6" << endl;
					cout << "4. 7 - 8" << endl;
					cout << "5. 9 - 10" << endl;
					cout << "6. 10+" << endl;

					cin >> minPlay;

					if (minPlay > 0 && minPlay < 7) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1, 2, 3, 4, 5 or 6" << endl;
				}
				// call function
				// output time for both hash functions
			}
			else if (filter == 4) { // Max Player filter
				while (true) {
					cout << "\nMaximum Players: " << endl;
					cout << "1. 1 - 2" << endl;
					cout << "2. 3 - 4" << endl;
					cout << "3. 5 - 6" << endl;
					cout << "4. 7 - 8" << endl;
					cout << "5. 9 - 10" << endl;
					cout << "6. 10+" << endl;

					cin >> maxPlay;

					if (maxPlay > 0 && maxPlay < 7) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1, 2, 3, 4, 5 or 6" << endl;
				}
				// call function
				// output time for both hash functions
			}
			else if (filter == 5) { // Max Age Filter
				while (true) {
					cout << "\nMinimum Age: " << endl;
					cout << "1. 1 - 5" << endl;
					cout << "2. 6 - 11" << endl;
					cout << "3. 12 - 15" << endl;
					cout << "4. 16 - 17" << endl;
					cout << "5. 18+" << endl;

					cin >> minAge;

					if (minAge > 0 && minAge < 6) {
						break;
					}

					cout << "\nInvalid Selection\nPlease Select: 1, 2, 3, 4, or 5" << endl;
				}
				// call function
				// output time for both hash functions
			}
			else if (filter == 6) { // Back to Options
				continue;
			}
		}

		else if (option == 3) {
			cout << "\nThanks for Using Board Bot!" << endl;
			break;
		}
		else {
			cout << "\nInvalid Option\nPlease Select: 1, 2, or 3" << endl;
			continue;
		}

		while (true) {
			cout << "\nDo you want to continue?" << endl;
			cout << "1. Yes, bring me to the options menu" << endl;
			cout << "2. No, let me exit" << endl;

			cin >> contOpt;

			if (contOpt > 0 && contOpt < 3) {
				break;
			}

			cout << "\nInvalid Option\nPlease Select: 1 or 2" << endl;
		}

		if (contOpt == 2) {
			cout << "\nThanks for Using Board Bot!" << endl;
			break;
		}
		
	}
}

#include<iostream>

using namespace std;

int main() {

	int option, filter, contOpt;

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
				// call function
				// output time for both hash functions
				//cout << "Time: " << something << endl;
			}
			else if (filter == 2) { // Year filter
				// call function
				// output time for both hash functions
			}
			else if (filter == 3) { // Min Player filter
				// call function
				// output time for both hash functions
			}
			else if (filter == 4) { // Max Player filter
				// call function
				// output time for both hash functions
			}
			else if (filter == 5) { // Max Age Filter
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
			break;
		}
		
	}
}
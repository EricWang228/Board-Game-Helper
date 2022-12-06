#include<iostream>
#include<chrono>

using namespace std;
using namespace std::chrono;

int main() {

	int option, filter, contOpt, year, minPlay, maxPlay, minAge;
	string name;
	auto start = system_clock::now(), stop = system_clock::now();

	cout << "Welcome To Board Bot!" << endl;

	while (true) {
		cout << "\nSelect An Option:" << endl;
		cout << "1. Print Top 10 Rated Board Games" << endl;
		cout << "2. Search By Filter" << endl;
		cout << "3. Exit" << endl;

		cin >> option;

		if (option == 1) {
			start = system_clock::now();
			// call function to find top 10 Open Addressing
			auto duration1 = duration_cast<microseconds>(system_clock::now() - start);

			start = system_clock::now();
			// call function to find top 10 Separate Chaining
			auto duration2 = duration_cast<microseconds>(system_clock::now() - start);

			// OUTPUT OF EITHER FUNCTION

			cout << "\nExecution Time with Open Addressing: " << duration1.count() << " microseconds" << endl;
			cout << "Execution Time with Separate Chaining: " << duration2.count() << " microseconds" << endl;
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

				start = system_clock::now();
				// call function for instance of name Open Addressing
				auto duration1 = duration_cast<microseconds>(system_clock::now() - start);

				start = system_clock::now();
				// call function for instance of name Separate Chaining
				auto duration2 = duration_cast<microseconds>(system_clock::now() - start);

				// OUTPUT OF EITHER FUNCTION

				cout << "\nExecution Time with Open Addressing: " << duration1.count() << " microseconds" << endl;
				cout << "Execution Time with Separate Chaining: " << duration2.count() << " microseconds" << endl;
			}
			else if (filter == 2) { // Year filter
				cout << "\nEnter Year Board Game was Published: " << endl;
				cin >> year;

				start = system_clock::now();
				// call function to find year Open Addressing
				auto duration1 = duration_cast<microseconds>(system_clock::now() - start);

				start = system_clock::now();
				// call function to find year Separate Chaining
				auto duration2 = duration_cast<microseconds>(system_clock::now() - start);

				// OUTPUT OF EITHER FUNCTION

				cout << "\nExecution Time with Open Addressing: " << duration1.count() << " microseconds" << endl;
				cout << "Execution Time with Separate Chaining: " << duration2.count() << " microseconds" << endl;
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

				start = system_clock::now();
				// call function to find minPlayers Open Addressing
				auto duration1 = duration_cast<microseconds>(system_clock::now() - start);

				start = system_clock::now();
				// call function to find minPlayers Separate Chaining
				auto duration2 = duration_cast<microseconds>(system_clock::now() - start);

				// OUTPUT OF EITHER FUNCTION

				cout << "\nExecution Time with Open Addressing: " << duration1.count() << " microseconds" << endl;
				cout << "Execution Time with Separate Chaining: " << duration2.count() << " microseconds" << endl;
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

				start = system_clock::now();
				// call function to find maxPlayer Open Addressing
				auto duration1 = duration_cast<microseconds>(system_clock::now() - start);

				start = system_clock::now();
				// call function to find maxPlayer Separate Chaining
				auto duration2 = duration_cast<microseconds>(system_clock::now() - start);

				// OUTPUT EITHER FUNCTION

				cout << "\nExecution Time with Open Addressing: " << duration1.count() << " microseconds" << endl;
				cout << "Execution Time with Separate Chaining: " << duration2.count() << " microseconds" << endl;
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

				start = system_clock::now();
				// call function to find minAge Open Addressing
				auto duration1 = duration_cast<microseconds>(system_clock::now() - start);

				start = system_clock::now();
				// call function to find minAge Separate Chaining
				auto duration2 = duration_cast<microseconds>(system_clock::now() - start);

				// OUTPUT EITHER FUNCTION

				cout << "\nExecution Time with Open Addressing: " << duration1.count() << " microseconds" << endl;
				cout << "Execution Time with Separate Chaining: " << duration2.count() << " microseconds" << endl;
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
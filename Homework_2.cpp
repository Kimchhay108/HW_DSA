#include <iostream>
using namespace std;

int myArray[10] = {23, 65, 678, 35, 12, 65};
int currentSize = 6;

void showelement() 
	{
	    cout << "The current array values are: ";
	    for (int i = 0; i < currentSize; i++) 
		{
	        cout << myArray[i] << " ";
	    }
	    cout << endl;
	}
void searchValue() {
    int valueToSearch;
    cout << "Enter the value you want to search for: ";
    cin >> valueToSearch;

    bool found = false;
    int element; ;
    for (int i = 0; i < currentSize; i++) {
        if (myArray[i] == valueToSearch) {
            found = true;
            element = i+1;  
            break;
        }
    }

    if (found) {
        cout << "Value " << valueToSearch << " found at the " << element << " value of the array." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the array." << endl;
    }
}

void searchDuplicateValue() {
    int valueToSearch, count = 0;
    cout << "Enter the value you want to search for: ";
    cin >> valueToSearch;

    for (int i = 0; i < currentSize; i++) {
        if (myArray[i] == valueToSearch) {
            count++;
        }
    }

    if (count > 0) {
        cout << "Value " << valueToSearch << " found " << count << " time(s) in the array." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the array." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n1.Show Values" << endl;
        cout << "2. Search for a value" << endl;
        cout << "3. Search for duplicate values" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                showelement();
            case 2:
                searchValue();
                break;
            case 3:
                searchDuplicateValue();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

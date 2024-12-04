#include <iostream>
using namespace std;

int myArray[10] = {23, 65, 678, 35, 12,65}; 
int currentSize = 6;
int index, newValue;



void insertvalue() 
		{
		    if (currentSize >= 10) 
			{ // Check if the array is full
		        cout << "The array is full. Cannot insert more values." << endl;
		        return;
		    }
			
		    cout << "Enter the index where you want to insert (1-" << currentSize + 1 << "): ";
		    cin >> index;
		    index--; // Adjust for 1-based index by subtracting 1
	
		    if (index < 0 || index > currentSize) 
			{ // check to see if the the index matched the one the has in the array
		        cout << "Invalid index! Please enter a valid number between 1 and " << currentSize + 1 << "." << endl;
		        return;
		    }
	
		    cout << "Enter the new value: ";
		    cin >> newValue;
		    
	
		    // move the elements to the right
		    for (int i = currentSize; i > index; i--) 
			{
		        myArray[i] = myArray[i - 1];
		    }
	
		    // Insert the new value
		    myArray[index] = newValue;
		    currentSize++; // Increase the size of the array
	
		    cout << "The updated array values are: ";
		    for (int i = 0; i < currentSize; i++) 
			{
		        cout << myArray[i] << " ";
		    }
	    	cout << endl;
		}

void showelement() 
	{
	    cout << "The current array values are: ";
	    for (int i = 0; i < currentSize; i++) 
		{
	        cout << myArray[i] << " ";
	    }
	    cout << endl;
	}

void deletevalue() 
	{
	    int index;
	
	    cout << "Enter the index (1-" << currentSize << ") of the value you want to delete: ";
	    cin >> index;
	
	    // Adjust for 1-based index by subtracting 1
	    index--; 
	
	    if (index < 0 || index >= currentSize) 
		{ // check to see if the index has it 
	        cout << "Invalid index! Please enter a valid number between 1 and " << currentSize << "." << endl;
	        return;
	    }
	
	    // move element  to the left to fill the gap
	    for (int i = index; i < currentSize - 1; i++) 
		{
	        myArray[i] = myArray[i + 1];
	    }
	    currentSize--; // Decrease the size of the array
	
	    cout << "The updated array values are: ";
	    for (int i = 0; i < currentSize; i++) 
		{
	        cout << myArray[i] << " ";
	    }
	    cout << endl;
	}
	
	void deleteByValue() 
{
    int valueToDelete;
    cout << "Enter the value you want to delete: ";
    cin >> valueToDelete;
	// Tracks the size of the new array after deletion
    int newSize = 0; 

    // Create a new array with elements that do not match valueToDelete
    for (int i = 0; i < currentSize; i++) 
    {
        if (myArray[i] != valueToDelete) 
        {
            myArray[newSize++] = myArray[i];
        }
    }

    // Update the current size
    if (newSize == currentSize) 
    {
        cout << "Value " << valueToDelete << " not found in the array." << endl;
    } 
    else 
    {
        currentSize = newSize;
        cout << "The updated array values after deleting " << valueToDelete << " are: ";
        for (int i = 0; i < currentSize; i++) 
        {
            cout << myArray[i] << " ";
        }
        cout << endl;
    }
}

void searchvalue()
	{
		int valueToSearch,i;
        cout << "Enter the value you want to search for: ";
        cin >> valueToSearch;
        
        bool found = false;
        for (int i = 0; i < currentSize; i++) {
            if (myArray[i] == valueToSearch) {
                found = true;
                break;
            }
        }
        
        if (found) {
            cout << "Value " << valueToSearch << " found at index " << i + 1 << "." << endl;
        } else {
            cout << "Value " << valueToSearch << " not found in the array." << endl;
        }
	}

	void searchDuplicateValue()
		{
			int valueToSearch, i, count = 0;
        cout << "Enter the value you want to search for: ";
        cin >> valueToSearch;
        
        for (int i = 0; i < currentSize; i++) {
            if (myArray[i] == valueToSearch) {
                count++;
            }
        }
        
        if (count > 1) {
            cout << "Value " << valueToSearch << " found " << count << " times in the array." << endl;
        } else {
            cout << "Value " << valueToSearch << " not found in the array." << endl;
        }
		}


	
	

int main() {
    int choice;
    do {
       
        cout << "Please Choose the following option:" << endl;
        cout << "1. Insert a new value" << endl;
        cout << "2. Show current array values" << endl;
        cout << "3. Delete Value" << endl;
        cout << "4. Delete by Value" << endl;
		cout << "5. Search for a value" << endl;
		cout<<	"6. Search for Duplicate Value" << endl;  
		cout << "7. Exit" << endl;
		cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertvalue(); 
                break;
            case 2:
                showelement(); 
                break;
            case 3:
                deletevalue();
                break;
            case 4:
                deleteByValue();
                break; 
			case 5:
                searchvalue();
            break;    
			case 6:
            	searchDuplicateValue();
            break;   
			case 7:
            	cout << "Exiting program..." << endl;
            break;  
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 8); 

    return 0;
}

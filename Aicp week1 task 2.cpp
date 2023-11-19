#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

using namespace std;

// Function to display the menu and get user choice
int displayMenu(const string categories[], const string items[][3], const double prices[]) {
    int choice;
    cout << "Categories:\n";
    for (int i = 0; i < 7; ++i) {
        cout << i + 1 << ". " << categories[i] << endl;
    }
    cout << "Enter the category number: ";
    cin >> choice;

    // Validate user input
    while (choice < 1 || choice > 7) {
        cout << "Invalid choice. Please enter a number between 1 and 7: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }

    // Display items in the chosen category
    cout << "Items in " << categories[choice - 1] << " category:\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ". " << items[choice - 1][i] << " - $" << prices[(choice - 1) * 3 + i] << endl;
    }

    return choice;
}

// Function to get user's choice for a specific category
int getItemChoice(const string items[][3], int category) {
    int choice;
    cout << "Enter the item number for your choice: ";
    cin >> choice;

    // Validate user input
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter a number between 1 and 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }

    return choice;
}

int main() {
    const string categories[] = {"Case", "RAM", "Main Hard Disk Drive", "Solid State Drive", "Second Hard Disk Drive", "Optical Drive", "Operating System"};
    const string items[][3] = {{"A1", "Compact", "75.00"}, {"A2", "Tower", "150.00"}, {"B1", "8 GB", "79.99"}, {"B2", "16 GB", "149.99"}, {"B3", "32 GB", "299.99"},
                              {"C1", "1 TB HDD", "49.99"}, {"C2", "2 TB HDD", "89.99"}, {"C3", "4 TB HDD", "129.99"}, {"D1", "240 GB SSD", "59.99"}, {"D2", "480 GB SSD", "119.99"},
                              {"E1", "1 TB HDD", "49.99"}, {"E2", "2 TB HDD", "89.99"}, {"E3", "4 TB HDD", "129.99"}, {"F1", "DVD/Blu-Ray Player", "50.00"}, {"F2", "DVD/Blu-Ray Re-writer", "100.00"},
                              {"G1", "Standard Version", "100.00"}, {"G2", "Professional Version", "175.00"}};
    const double prices[] = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00};

    string chosenItems[3];
    double totalPrice = 200.00; // Initial cost for basic set of components

    // Get user choices for case, RAM, and Main Hard Disk Drive
    for (int i = 0; i < 3; ++i) {
        int categoryChoice = displayMenu(categories, items, prices);
        int itemChoice = getItemChoice(items, categoryChoice);

        // Store chosen item details
        chosenItems[i] = categories[categoryChoice - 1] + ": " + items[categoryChoice - 1][itemChoice - 1];

        // Add item price to total cost
        totalPrice += prices[(categoryChoice - 1) * 3 + itemChoice - 1];
    }

    // Ask the user if they want to purchase additional items
    char additionalChoice;
    cout << "Do you want to purchase additional items? (y/n): ";
    cin >> additionalChoice;

    // Validate user input
    while (additionalChoice != 'y' && additionalChoice != 'n') {
        cout << "Invalid choice. Please enter 'y' or 'n': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> additionalChoice;
    }

    // Process additional items if the user chooses to purchase
    if (additionalChoice == 'y') {
        vector<string> additionalItems;
        int additionalCategory;
        do {
            additionalCategory = displayMenu(categories, items, prices);
            int additionalItemChoice = getItemChoice(items, additionalCategory);
            additionalItems.push_back(categories[additionalCategory - 1] + ": " + items[additionalCategory - 1][additionalItemChoice - 1]);
            totalPrice += prices[(additionalCategory - 1) * 3 + additionalItemChoice - 1];

            cout << "Do you want to add more items? (y/n): ";
            cin >> additionalChoice;

            // Validate user input
            while (additionalChoice != 'y' && additionalChoice != 'n') {
                cout << "Invalid choice. Please enter 'y' or 'n': ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> additionalChoice;
            }
        } while (additionalChoice == 'y');
        
        // Display additional items
        cout << "\nAdditional Items:\n";
        for (const string& item : additionalItems) {
            cout << item << endl;
        }
    }

    // Display chosen items and total price
    cout << "\nChosen Items:\n";
    for (const string& item : chosenItems) {
        cout << item << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Total Price: $" << totalPrice << endl;

    return 0;
}


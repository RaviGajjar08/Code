#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const int PRICE_PER_TICKET = 10;

vector<vector<bool>> seatAvailability(NUM_ROWS, vector<bool>(NUM_COLS, true));

void displaySeats() {
    cout << "  ";
    for (int i = 1; i <= NUM_COLS; ++i)
        cout << i << " ";
    cout << "\n";
    
    for (int i = 0; i < NUM_ROWS; ++i) {
        char rowLabel = 'A' + i;
        cout << rowLabel << " ";
        
        for (int j = 0; j < NUM_COLS; ++j) {
            if (seatAvailability[i][j])
                cout << "O ";
            else
                cout << "X ";
        }
        cout << "\n";
    }
}

bool isSeatValid(int row, int col) {
    return (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && seatAvailability[row][col]);
}

void bookSeats() {
    int numSeats;
    cout << "Enter the number of seats to book: ";
    cin >> numSeats;

    int totalCost = 0;

    for (int i = 0; i < numSeats; ++i) {
        char row;
        int col;
        cout << "Enter the seat (row, col) for seat " << i + 1 << " (e.g., A 3): ";
        cin >> row >> col;
        col--;  // Decrement by 1 to match array indexing

        int rowIdx = row - 'A';

        if (isSeatValid(rowIdx, col)) {
            seatAvailability[rowIdx][col] = false;
            totalCost += PRICE_PER_TICKET;
        } else {
            cout << "Invalid seat. Please choose again.\n";
            i--;  // Decrement to allow the user to choose a valid seat again
        }
    }

    cout << "Booking successful! Total cost: $" << totalCost << "\n";
}

int main() {
    cout << "Welcome to the Movie Ticket Booking System!\n\n";

    while (true) {
        cout << "1. View available seats\n";
        cout << "2. Book seats\n";
        cout << "3. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeats();
                break;
            case 3:
                cout << "Thank you for using the Movie Ticket Booking System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

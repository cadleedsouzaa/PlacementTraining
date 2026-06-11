#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

// Passenger Class holding passenger details
class Passenger {
public:
    int id;
    string name;
    Passenger(int ticketId, string pName) : id(ticketId), name(pName) {}
};

// Booking System managing passengers and registration/login
class TrainBookingSystem {
private:
    vector<Passenger> confirmed;  // Confirmed passenger vector (Max size: 2)
    queue<Passenger> waitingList; // Waiting list queue (Max size: 2)
    queue<Passenger> overflow;    // Secondary overflow queue
    map<string, string> users;    // Database of registered users (username -> password)
    string loggedInUser = "";
    int ticketCounter = 101;      // Generates unique Ticket IDs

public:
    void registerUser() {
        string username, password;
        cout << "Enter Username: "; cin >> username;
        cout << "Enter Password: "; cin >> password;
        users[username] = password;
        cout << "Registration successful!\n";
    }

    bool loginUser() {
        string username, password;
        cout << "Enter Username: "; cin >> username;
        cout << "Enter Password: "; cin >> password;
        if (users.count(username) && users[username] == password) {
            loggedInUser = username;
            cout << "Login successful! Welcome, " << username << ".\n";
            return true;
        }
        cout << "Invalid username or password.\n";
        return false;
    }

    void logout() {
        loggedInUser = "";
        cout << "Logged out.\n";
    }

    bool isLoggedIn() {
        return !loggedInUser.empty();
    }

    void bookTicket() {
        if (!isLoggedIn()) {
            cout << "Please login first to book a ticket.\n";
            return;
        }
        string name;
        cout << "Enter passenger name: ";
        cin.ignore();
        getline(cin, name);
        
        Passenger p(ticketCounter++, name);

        // Core Queuing Logic:
        // Confirmed vector holds up to 2.
        // Waiting List holds up to 2.
        // The rest are pushed to the overflow queue.
        if (confirmed.size() < 2) {
            confirmed.push_back(p);
            cout << "Ticket booked! Status: CONFIRMED (Ticket ID: " << p.id << ")\n";
        } else if (waitingList.size() < 2) {
            waitingList.push(p);
            cout << "Ticket booked! Status: WAITING LIST (Ticket ID: " << p.id << ")\n";
        } else {
            overflow.push(p);
            cout << "Ticket booked! Status: OVERFLOW QUEUE (Ticket ID: " << p.id << ")\n";
        }
    }

    void cancelTicket() {
        if (!isLoggedIn()) {
            cout << "Please login first to cancel a ticket.\n";
            return;
        }
        int ticketId;
        cout << "Enter Ticket ID to cancel: ";
        cin >> ticketId;

        // Find and cancel from confirmed vector
        for (auto it = confirmed.begin(); it != confirmed.end(); ++it) {
            if (it->id == ticketId) {
                cout << "Cancelled ticket ID: " << ticketId << " for " << it->name << "\n";
                confirmed.erase(it);

                // Promote first waiting list passenger to confirmed
                if (!waitingList.empty()) {
                    confirmed.push_back(waitingList.front());
                    cout << "Promoted " << waitingList.front().name << " to CONFIRMED.\n";
                    waitingList.pop();

                    // Promote first overflow passenger to waiting list
                    if (!overflow.empty()) {
                        waitingList.push(overflow.front());
                        cout << "Promoted " << overflow.front().name << " to WAITING LIST.\n";
                        overflow.pop();
                    }
                }
                return;
            }
        }
        cout << "Ticket ID not found in confirmed list.\n";
    }

    void display() {
        cout << "\n-------------------------------\n";
        cout << "   TRAIN BOOKING SYSTEM STATUS\n";
        cout << "-------------------------------\n";
        
        cout << "Confirmed Vector (Max 2):\n";
        for (const auto& p : confirmed) {
            cout << "  [ID: " << p.id << "] " << p.name << "\n";
        }
        if (confirmed.empty()) cout << "  (Empty)\n";

        cout << "\nWaiting List Queue (Max 2):\n";
        queue<Passenger> tempWL = waitingList;
        while (!tempWL.empty()) {
            cout << "  [ID: " << tempWL.front().id << "] " << tempWL.front().name << "\n";
            tempWL.pop();
        }
        if (waitingList.empty()) cout << "  (Empty)\n"; 

        cout << "\nOverflow Queue:\n";
        queue<Passenger> tempOF = overflow;
        while (!tempOF.empty()) {
            cout << "  [ID: " << tempOF.front().id << "] " << tempOF.front().name << "\n";
            tempOF.pop();
        }
        if (overflow.empty()) cout << "  (Empty)\n";
        cout << "-------------------------------\n";
    }
};

int main() {
    TrainBookingSystem system;
    int choice;

    while (true) {
        if (!system.isLoggedIn()) {
            cout << "\n--- MAIN MENU ---\n";
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Display Status\n";
            cout << "4. Exit\n";
            cout << "Enter Choice: ";
            if (!(cin >> choice)) break;

            if (choice == 1) system.registerUser();
            else if (choice == 2) system.loginUser();
            else if (choice == 3) system.display();
            else break;
        } else {
            cout << "\n--- USER DASHBOARD ---\n";
            cout << "1. Book Ticket\n";
            cout << "2. Cancel Ticket\n";
            cout << "3. Display Status\n";
            cout << "4. Logout\n";
            cout << "Enter Choice: ";
            if (!(cin >> choice)) break;

            if (choice == 1) system.bookTicket();
            else if (choice == 2) system.cancelTicket();
            else if (choice == 3) system.display();
            else system.logout();
        }
    }
    cout << "Exiting system.\n";
    return 0;
}

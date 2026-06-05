#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iomanip>
#include <algorithm>

// Passenger Class
class Passenger {
private:
    int ticketId;
    std::string name;
    int age;
    std::string gender;
    std::string status; // "CONFIRMED", "WAITING_LIST", "OVERFLOW"
    std::string bookedBy; // User who booked this passenger

public:
    Passenger(int id, const std::string& pName, int pAge, const std::string& pGender, const std::string& pStatus, const std::string& pUser)
        : ticketId(id), name(pName), age(pAge), gender(pGender), status(pStatus), bookedBy(pUser) {}

    // Getters and Setters
    int getTicketId() const { return ticketId; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getGender() const { return gender; }
    std::string getStatus() const { return status; }
    std::string getBookedBy() const { return bookedBy; }

    void setStatus(const std::string& newStatus) {
        status = newStatus;
    }
};

// User Class
class User {
private:
    std::string username;
    std::string password;

public:
    User(const std::string& uname, const std::string& pwd)
        : username(uname), password(pwd) {}

    std::string getUsername() const { return username; }
    bool verifyPassword(const std::string& pwd) const { return password == pwd; }
};

// BookingSystem Class
class BookingSystem {
private:
    std::vector<Passenger> confirmedList; // Confirmed Passengers (Max 2)
    std::list<Passenger> waitingList;     // Waiting List Queue (Max 2)
    std::list<Passenger> overflowList;    // Overflow Queue

    std::vector<User> registeredUsers;
    std::string loggedInUser;
    int ticketCounter;

public:
    BookingSystem() : loggedInUser(""), ticketCounter(101) {}

    // Authentication Functions
    bool registerUser(const std::string& username, const std::string& password) {
        if (username.empty() || password.empty()) {
            std::cout << "\nError: Username and Password cannot be empty.\n";
            return false;
        }

        for (const auto& u : registeredUsers) {
            if (u.getUsername() == username) {
                std::cout << "\nError: Username already exists! Please choose another one.\n";
                return false;
            }
        }

        registeredUsers.push_back(User(username, password));
        std::cout << "\nRegistration successful! You can now log in.\n";
        return true;
    }

    bool loginUser(const std::string& username, const std::string& password) {
        for (const auto& u : registeredUsers) {
            if (u.getUsername() == username && u.verifyPassword(password)) {
                loggedInUser = username;
                std::cout << "\nWelcome, " << username << "! Login successful.\n";
                return true;
            }
        }
        std::cout << "\nError: Invalid Username or Password.\n";
        return false;
    }

    void logoutUser() {
        if (!loggedInUser.empty()) {
            std::cout << "\nUser " << loggedInUser << " logged out successfully.\n";
            loggedInUser = "";
        }
    }

    bool isLoggedIn() const {
        return !loggedInUser.empty();
    }

    std::string getLoggedInUser() const {
        return loggedInUser;
    }

    // Booking Function
    void bookTicket(const std::string& name, int age, const std::string& gender) {
        if (!isLoggedIn()) {
            std::cout << "\nError: You must be logged in to book a ticket.\n";
            return;
        }

        int id = ticketCounter++;
        
        // Rules:
        // 1. If confirmedList size is less than 2, then confirmed.
        // 2. If confirmedList is full (size >= 2) and waitingList size is less than 2, push to waitingList.
        // 3. Otherwise, push to overflowList.
        if (confirmedList.size() < 2) {
            Passenger p(id, name, age, gender, "CONFIRMED", loggedInUser);
            confirmedList.push_back(p);
            std::cout << "\nTicket Booked Successfully!\n";
            std::cout << "Passenger: " << name << " | Ticket ID: " << id << " | Status: CONFIRMED\n";
        }
        else if (waitingList.size() < 2) {
            Passenger p(id, name, age, gender, "WAITING_LIST", loggedInUser);
            waitingList.push_back(p);
            std::cout << "\nTicket Booked on Waiting List!\n";
            std::cout << "Passenger: " << name << " | Ticket ID: " << id << " | Status: WAITING_LIST\n";
        }
        else {
            Passenger p(id, name, age, gender, "OVERFLOW", loggedInUser);
            overflowList.push_back(p);
            std::cout << "\nTicket Booked on Overflow Queue (RAC/WL-2)!\n";
            std::cout << "Passenger: " << name << " | Ticket ID: " << id << " | Status: OVERFLOW\n";
        }
    }

    // Cancellation Function
    void cancelTicket(int id) {
        if (!isLoggedIn()) {
            std::cout << "\nError: You must be logged in to cancel a ticket.\n";
            return;
        }

        // Try to find the ticket in confirmedList
        auto confirmedIt = std::find_if(confirmedList.begin(), confirmedList.end(),
            [id](const Passenger& p) { return p.getTicketId() == id; });

        if (confirmedIt != confirmedList.end()) {
            // Verify ownership: User can cancel their own bookings
            if (confirmedIt->getBookedBy() != loggedInUser) {
                std::cout << "\nError: You can only cancel tickets booked by yourself (" << confirmedIt->getBookedBy() << ").\n";
                return;
            }

            std::cout << "\nCancelling Confirmed Ticket for: " << confirmedIt->getName() << " (ID: " << id << ")\n";
            confirmedList.erase(confirmedIt);

            // Promote first passenger from waitingList to confirmedList
            if (!waitingList.empty()) {
                Passenger promoted = waitingList.front();
                waitingList.pop_front();
                promoted.setStatus("CONFIRMED");
                confirmedList.push_back(promoted);
                std::cout << "Promotion: " << promoted.getName() << " (ID: " << promoted.getTicketId() 
                          << ") promoted from WAITING_LIST to CONFIRMED.\n";

                // Promote first passenger from overflowList to waitingList
                if (!overflowList.empty()) {
                    Passenger waitingPromoted = overflowList.front();
                    overflowList.pop_front();
                    waitingPromoted.setStatus("WAITING_LIST");
                    waitingList.push_back(waitingPromoted);
                    std::cout << "Promotion: " << waitingPromoted.getName() << " (ID: " << waitingPromoted.getTicketId() 
                              << ") promoted from OVERFLOW to WAITING_LIST.\n";
                }
            }
            std::cout << "Cancellation processed successfully!\n";
            return;
        }

        // Try to find in waitingList
        auto waitingIt = std::find_if(waitingList.begin(), waitingList.end(),
            [id](const Passenger& p) { return p.getTicketId() == id; });

        if (waitingIt != waitingList.end()) {
            if (waitingIt->getBookedBy() != loggedInUser) {
                std::cout << "\nError: You can only cancel tickets booked by yourself (" << waitingIt->getBookedBy() << ").\n";
                return;
            }

            std::cout << "\nCancelling Waiting List Ticket for: " << waitingIt->getName() << " (ID: " << id << ")\n";
            waitingList.erase(waitingIt);

            // Promote first passenger from overflowList to waitingList
            if (!overflowList.empty()) {
                Passenger waitingPromoted = overflowList.front();
                overflowList.pop_front();
                waitingPromoted.setStatus("WAITING_LIST");
                waitingList.push_back(waitingPromoted);
                std::cout << "Promotion: " << waitingPromoted.getName() << " (ID: " << waitingPromoted.getTicketId() 
                          << ") promoted from OVERFLOW to WAITING_LIST.\n";
            }
            std::cout << "Cancellation processed successfully!\n";
            return;
        }

        // Try to find in overflowList
        auto overflowIt = std::find_if(overflowList.begin(), overflowList.end(),
            [id](const Passenger& p) { return p.getTicketId() == id; });

        if (overflowIt != overflowList.end()) {
            if (overflowIt->getBookedBy() != loggedInUser) {
                std::cout << "\nError: You can only cancel tickets booked by yourself (" << overflowIt->getBookedBy() << ").\n";
                return;
            }

            std::cout << "\nCancelling Overflow Ticket for: " << overflowIt->getName() << " (ID: " << id << ")\n";
            overflowList.erase(overflowIt);
            std::cout << "Cancellation processed successfully!\n";
            return;
        }

        std::cout << "\nError: Ticket ID " << id << " not found, or it is not under your bookings.\n";
    }

    // Display Status Function
    void displayStatus() const {
        std::cout << "\n" << std::string(60, '=') << "\n";
        std::cout << "                 TRAIN BOOKING SYSTEM STATUS\n";
        std::cout << std::string(60, '=') << "\n";

        // Confirmed List
        std::cout << "1. CONFIRMED SEATS (Max 2) [Size: " << confirmedList.size() << "/2]\n";
        if (confirmedList.empty()) {
            std::cout << "   (No passengers booked)\n";
        } else {
            std::cout << "   " << std::left << std::setw(10) << "Ticket ID" 
                      << std::setw(20) << "Passenger Name" 
                      << std::setw(6) << "Age" 
                      << std::setw(10) << "Gender" 
                      << "Booked By\n";
            std::cout << "   " << std::string(55, '-') << "\n";
            for (const auto& p : confirmedList) {
                std::cout << "   " << std::left << std::setw(10) << p.getTicketId()
                          << std::setw(20) << p.getName()
                          << std::setw(6) << p.getAge()
                          << std::setw(10) << p.getGender()
                          << p.getBookedBy() << "\n";
            }
        }
        std::cout << "\n";

        // Waiting List
        std::cout << "2. WAITING LIST QUEUE (Max 2) [Size: " << waitingList.size() << "/2]\n";
        if (waitingList.empty()) {
            std::cout << "   (No passengers on waiting list)\n";
        } else {
            std::cout << "   " << std::left << std::setw(10) << "Ticket ID" 
                      << std::setw(20) << "Passenger Name" 
                      << std::setw(6) << "Age" 
                      << std::setw(10) << "Gender" 
                      << "Booked By\n";
            std::cout << "   " << std::string(55, '-') << "\n";
            for (const auto& p : waitingList) {
                std::cout << "   " << std::left << std::setw(10) << p.getTicketId()
                          << std::setw(20) << p.getName()
                          << std::setw(6) << p.getAge()
                          << std::setw(10) << p.getGender()
                          << p.getBookedBy() << "\n";
            }
        }
        std::cout << "\n";

        // Overflow Queue
        std::cout << "3. OVERFLOW QUEUE [Size: " << overflowList.size() << "]\n";
        if (overflowList.empty()) {
            std::cout << "   (No passengers on overflow list)\n";
        } else {
            std::cout << "   " << std::left << std::setw(10) << "Ticket ID" 
                      << std::setw(20) << "Passenger Name" 
                      << std::setw(6) << "Age" 
                      << std::setw(10) << "Gender" 
                      << "Booked By\n";
            std::cout << "   " << std::string(55, '-') << "\n";
            for (const auto& p : overflowList) {
                std::cout << "   " << std::left << std::setw(10) << p.getTicketId()
                          << std::setw(20) << p.getName()
                          << std::setw(6) << p.getAge()
                          << std::setw(10) << p.getGender()
                          << p.getBookedBy() << "\n";
            }
        }
        std::cout << std::string(60, '=') << "\n";
    }

    // Helper to generate seed data for testing
    void setupTestData() {
        registerUser("admin", "admin123");
        registerUser("user1", "user123");
        
        // Log in as user1 to book some initial test data
        loginUser("user1", "user123");
        bookTicket("Alice", 25, "Female");
        bookTicket("Bob", 30, "Male");
        bookTicket("Charlie", 22, "Male");
        bookTicket("Diana", 29, "Female");
        bookTicket("Ethan", 35, "Male");
        bookTicket("Fiona", 27, "Female");
        logoutUser();
    }
};

// Main function / Menu execution
int main() {
    BookingSystem system;
    
    // Seed with initial testing users and bookings
    system.setupTestData();

    int choice = 0;
    while (true) {
        if (!system.isLoggedIn()) {
            std::cout << "\n=== MAIN MENU ===\n";
            std::cout << "1. Register User\n";
            std::cout << "2. Login\n";
            std::cout << "3. View System Status (Public View)\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (choice == 1) {
                std::string username, password;
                std::cout << "Enter Username: ";
                std::cin >> username;
                std::cout << "Enter Password: ";
                std::cin >> password;
                system.registerUser(username, password);
            }
            else if (choice == 2) {
                std::string username, password;
                std::cout << "Enter Username: ";
                std::cin >> username;
                std::cout << "Enter Password: ";
                std::cin >> password;
                system.loginUser(username, password);
            }
            else if (choice == 3) {
                system.displayStatus();
            }
            else if (choice == 4) {
                std::cout << "\nThank you for using the Train Booking System. Goodbye!\n";
                break;
            }
            else {
                std::cout << "\nInvalid choice. Please select from options 1-4.\n";
            }
        }
        else {
            std::cout << "\n=== USER DASHBOARD (Logged in as: " << system.getLoggedInUser() << ") ===\n";
            std::cout << "1. Book Ticket\n";
            std::cout << "2. Cancel Ticket\n";
            std::cout << "3. View Passenger Status & Queues\n";
            std::cout << "4. Logout\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";

            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (choice == 1) {
                std::string name, gender;
                int age;
                std::cout << "Enter Passenger Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter Age: ";
                while (!(std::cin >> age) || age <= 0) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid age. Please enter a positive number: ";
                }
                std::cout << "Enter Gender (Male/Female/Other): ";
                std::cin >> gender;
                system.bookTicket(name, age, gender);
            }
            else if (choice == 2) {
                int ticketId;
                std::cout << "Enter Ticket ID to cancel: ";
                while (!(std::cin >> ticketId)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Invalid Ticket ID. Please enter a number: ";
                }
                system.cancelTicket(ticketId);
            }
            else if (choice == 3) {
                system.displayStatus();
            }
            else if (choice == 4) {
                system.logoutUser();
            }
            else if (choice == 5) {
                std::cout << "\nThank you for using the Train Booking System. Goodbye!\n";
                break;
            }
            else {
                std::cout << "\nInvalid choice. Please select from options 1-5.\n";
            }
        }
    }
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// User struct to store user information
struct User {
    string username;
    string password;
    string email;
};

// Function to register a new user
void registerUser() {
    User newUser;
    cout << "Enter username: ";
    cin >> newUser.username;
    cout << "Enter password: ";
    cin >> newUser.password;
    cout << "Enter email address: ";
    cin >> newUser.email;

    // Open file to store user information
    ofstream userFile("users.txt", ios::app);
    if (userFile.is_open()) {
        // Write user information to file
        userFile << newUser.username << "," << newUser.password << "," << newUser.email << endl;
        cout << "Registration successful!" << endl;
    } else {
        cout << "Error: could not open file." << endl;
    }
    userFile.close();
}

// Function to log in an existing user
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open file to read user information
    ifstream userFile("users.txt");
    if (userFile.is_open()) {
        string line;
        bool found = false;
        while (getline(userFile, line)) {
            // Split line into username, password, and email
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1+1);
            string storedUsername = line.substr(0, pos1);
            string storedPassword = line.substr(pos1+1, pos2-pos1-1);
            string storedEmail = line.substr(pos2+1);

            // Check if entered username and password match stored information
            if (username == storedUsername && password == storedPassword) {
                found = true;
                cout << "Login successful!" << endl;
                // Allow user to access their account
                // ...
                break;
            }
        }
        if (!found) {
            cout << "Invalid username or password." << endl;
        }
    } else {
        cout << "Error: could not open file." << endl;
    }
    userFile.close();
}

int main() {
    int choice;
    do {
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}

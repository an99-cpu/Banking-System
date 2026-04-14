#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    int password;   // simple PIN
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNo, int pass, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        password = pass;
        balance = initialBalance;
    }

    // Login function
    bool login(int pass) {
        return pass == password;
    }

    // Deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful!\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    // Withdraw
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
        } else if (amount > balance) {
            cout << "Insufficient funds!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
    }

    // Display
    void display() const {
        cout << "\n--- Account Details ---\n";
        cout << "Name: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Save to file
    void saveToFile() {
        ofstream file("account.txt");
        if (file.is_open()) {
            file << accountHolder << endl;
            file << accountNumber << endl;
            file << password << endl;
            file << balance << endl;
            file.close();
        }
    }
};

int main() {
    string name;
    int accNo, pass, loginPass;
    double initialBalance;

    cout << "Create Account\n";
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Account Number: ";
    cin >> accNo;

    cout << "Set Password (PIN): ";
    cin >> pass;

    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    BankAccount account(name, accNo, pass, initialBalance);

    // Login system
    cout << "\n--- Login ---\n";
    cout << "Enter Password: ";
    cin >> loginPass;

    if (!account.login(loginPass)) {
        cout << "Incorrect password! Access denied.\n";
        return 0;
    }

    cout << "Login successful!\n";

    int choice;
    double amount;

    do {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Save & Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 3:
                account.display();
                break;

            case 4:
                account.saveToFile();
                cout << "Data saved. Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
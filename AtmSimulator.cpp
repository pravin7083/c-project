#include <iostream>

using namespace std;

class ATM {
private:
    int pin;
    double balance;

public:
    ATM(int userPin, double initialBalance) : pin(userPin), balance(initialBalance) {}

    bool verifyPIN(int enteredPin) {
        return enteredPin == pin;
    }

    void showBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful! New Balance: $" << balance << endl;
        } else {
            cout << "Invalid amount. Please enter a positive value.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful! Remaining Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }
};

int main() {
    int userPin, enteredPin;
    double initialBalance = 1000.0;  // Default balance

    cout << "Set your ATM PIN (4 digits): ";
    cin >> userPin;

    ATM atm(userPin, initialBalance);

    cout << "\nEnter your PIN: ";
    cin >> enteredPin;

    if (!atm.verifyPIN(enteredPin)) {
        cout << "Incorrect PIN! Access Denied.\n";
        return 1;
    }

    int choice;
    double amount;

    while (true) {
        cout << "\n=== ATM MENU ===\n";
        cout << "1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                atm.showBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                atm.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                atm.withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
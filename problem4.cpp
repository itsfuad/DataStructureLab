#include <iostream>

using namespace std;

struct BankAccount
{
    int accountNumber;
    string accountHolderName;
    double accountBalance;
};

void createAccount(BankAccount &account)
{
    cout << "Enter account number: ";
    cin >> account.accountNumber;
    cout << "Enter account holder name: ";
    cin >> account.accountHolderName;
    cout << "Enter account balance: ";
    cin >> account.accountBalance;
}

void depositMoney(BankAccount &account)
{
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    account.accountBalance += amount;
}

void withdrawMoney(BankAccount &account)
{
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > account.accountBalance)
    {
        cout << "Insufficient balance!" << endl;
    }
    else
    {
        account.accountBalance -= amount;
    }
}

void displayAccount(BankAccount &account)
{
    cout << "Account number: " << account.accountNumber << endl;
    cout << "Account holder name: " << account.accountHolderName << endl;
    cout << "Account balance: " << account.accountBalance << endl;
}

int main(){

    BankAccount account;
    int choice;

    do
    {
        cout << "1. Create account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Display account" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount(account);
            break;
        case 2:
            depositMoney(account);
            break;
        case 3:
            withdrawMoney(account);
            break;
        case 4:
            displayAccount(account);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}

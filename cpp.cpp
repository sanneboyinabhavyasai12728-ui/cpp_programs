#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Base Class
class BankAccount
{
protected:
    int accountNumber;
    string customerName;
    double balance;

public:

    // Constructor
    BankAccount(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        customerName = name;
        balance = bal;
    }

    // Virtual function
    virtual void displayAccount()
    {
        cout << "\n----------------------------------" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : Rs. "
             << fixed << setprecision(2) << balance << endl;
        cout << "----------------------------------" << endl;
    }

    // Get account number
    int getAccountNumber()
    {
        return accountNumber;
    }

    // Get balance
    double getBalance()
    {
        return balance;
    }

    // Deposit
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;

            cout << "\nAmount deposited successfully!" << endl;
            cout << "New Balance: Rs. "
                 << fixed << setprecision(2) << balance << endl;
        }
        else
        {
            cout << "\nInvalid deposit amount!" << endl;
        }
    }

    // Withdraw
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "\nInvalid withdrawal amount!" << endl;
        }
        else if (amount > balance)
        {
            cout << "\nInsufficient balance!" << endl;
        }
        else
        {
            balance = balance - amount;

            cout << "\nAmount withdrawn successfully!" << endl;
            cout << "Remaining Balance: Rs. "
                 << fixed << setprecision(2) << balance << endl;
        }
    }
};


// Derived Class
class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:

    SavingsAccount(int accNo, string name, double bal)
        : BankAccount(accNo, name, bal)
    {
        interestRate = 4.0;
    }

    // Function overriding
    void displayAccount()
    {
        cout << "\n==================================" << endl;
        cout << "         SAVINGS ACCOUNT" << endl;
        cout << "==================================" << endl;

        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : Rs. "
             << fixed << setprecision(2) << balance << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;

        cout << "==================================" << endl;
    }
};


// Function to find account
BankAccount* findAccount(vector<BankAccount*> &accounts, int accountNumber)
{
    int i;

    for (i = 0; i < (int)accounts.size(); i++)
    {
        if (accounts[i]->getAccountNumber() == accountNumber)
        {
            return accounts[i];
        }
    }

    return NULL;
}


// Main Function
int main()
{
    vector<BankAccount*> accounts;

    int choice;

    do
    {
        cout << "\n\n============================================" << endl;
        cout << "       BANK ACCOUNT MANAGEMENT SYSTEM" << endl;
        cout << "============================================" << endl;

        cout << "1. Create Account" << endl;
        cout << "2. Display Account" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Withdraw Money" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Display All Accounts" << endl;
        cout << "7. Close Account" << endl;
        cout << "8. Exit" << endl;

        cout << "============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        // CREATE ACCOUNT
        if (choice == 1)
        {
            int accNo;
            string name;
            double initialBalance;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            // Check duplicate account
            if (findAccount(accounts, accNo) != NULL)
            {
                cout << "\nAccount number already exists!" << endl;
            }
            else
            {
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Initial Balance: ";
                cin >> initialBalance;

                if (initialBalance < 0)
                {
                    cout << "\nInvalid balance!" << endl;
                }
                else
                {
                    BankAccount* newAccount =
                        new SavingsAccount(accNo, name, initialBalance);

                    accounts.push_back(newAccount);

                    cout << "\nAccount created successfully!" << endl;
                }
            }
        }


        // DISPLAY ACCOUNT
        else if (choice == 2)
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            BankAccount* account =
                findAccount(accounts, accNo);

            if (account != NULL)
            {
                account->displayAccount();
            }
            else
            {
                cout << "\nAccount not found!" << endl;
            }
        }


        // DEPOSIT
        else if (choice == 3)
        {
            int accNo;
            double amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            BankAccount* account =
                findAccount(accounts, accNo);

            if (account != NULL)
            {
                cout << "Enter Deposit Amount: Rs. ";
                cin >> amount;

                account->deposit(amount);
            }
            else
            {
                cout << "\nAccount not found!" << endl;
            }
        }


        // WITHDRAW
        else if (choice == 4)
        {
            int accNo;
            double amount;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            BankAccount* account =
                findAccount(accounts, accNo);

            if (account != NULL)
            {
                cout << "Enter Withdrawal Amount: Rs. ";
                cin >> amount;

                account->withdraw(amount);
            }
            else
            {
                cout << "\nAccount not found!" << endl;
            }
        }


        // CHECK BALANCE
        else if (choice == 5)
        {
            int accNo;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            BankAccount* account =
                findAccount(accounts, accNo);

            if (account != NULL)
            {
                cout << "\nAccount Number : "
                     << account->getAccountNumber() << endl;

                cout << "Current Balance: Rs. "
                     << fixed << setprecision(2)
                     << account->getBalance() << endl;
            }
            else
            {
                cout << "\nAccount not found!" << endl;
            }
        }


        // DISPLAY ALL ACCOUNTS
        else if (choice == 6)
        {
            int i;

            if (accounts.size() == 0)
            {
                cout << "\nNo accounts available!" << endl;
            }
            else
            {
                cout << "\n========== ALL ACCOUNTS ==========" << endl;

                for (i = 0; i < (int)accounts.size(); i++)
                {
                    accounts[i]->displayAccount();
                }
            }
        }


        // CLOSE ACCOUNT
        else if (choice == 7)
        {
            int accNo;
            int i;
            bool found = false;

            cout << "\nEnter Account Number to close: ";
            cin >> accNo;

            for (i = 0; i < (int)accounts.size(); i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    delete accounts[i];

                    accounts.erase(accounts.begin() + i);

                    cout << "\nAccount closed successfully!" << endl;

                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "\nAccount not found!" << endl;
            }
        }


        // EXIT
        else if (choice == 8)
        {
            cout << "\nThank you for using" << endl;
            cout << "Bank Account Management System!" << endl;
        }


        // INVALID CHOICE
        else
        {
            cout << "\nInvalid choice!" << endl;
            cout << "Please enter a number between 1 and 8." << endl;
        }

    } while (choice != 8);


    // Free memory
    int i;

    for (i = 0; i < (int)accounts.size(); i++)
    {
        delete accounts[i];
    }

    accounts.clear();

    return 0;
}

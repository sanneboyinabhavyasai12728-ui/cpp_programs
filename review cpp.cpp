#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================
// BASE CLASS: BankAccount
// ==========================================
class BankAccount
{
protected:
    string accountNumber;
    string customerName;
    double balance;

public:

    // Constructor
    BankAccount(string accNo, string name, double bal)
    {
        accountNumber = accNo;
        customerName = name;
        balance = bal;
    }

    // Display account details
    virtual void displayAccount()
    {
        cout << "\n----------------------------------------" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : Rs. "
             << fixed << setprecision(2) << balance << endl;
        cout << "----------------------------------------" << endl;
    }

    // Get account number
    string getAccountNumber()
    {
        return accountNumber;
    }

    // Get balance
    double getBalance()
    {
        return balance;
    }

    // Deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;

            cout << "\nAmount deposited successfully!" << endl;
            cout << "Deposited Amount : Rs. "
                 << fixed << setprecision(2) << amount << endl;
            cout << "New Balance      : Rs. "
                 << fixed << setprecision(2) << balance << endl;
        }
        else
        {
            cout << "\nInvalid deposit amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "\nInvalid withdrawal amount!" << endl;
        }
        else if (amount > balance)
        {
            cout << "\nInsufficient balance!" << endl;
            cout << "Available Balance: Rs. "
                 << fixed << setprecision(2) << balance << endl;
        }
        else
        {
            balance = balance - amount;

            cout << "\nAmount withdrawn successfully!" << endl;
            cout << "Withdrawn Amount : Rs. "
                 << fixed << setprecision(2) << amount << endl;
            cout << "Remaining Balance: Rs. "
                 << fixed << setprecision(2) << balance << endl;
        }
    }
};


// ==========================================
// DERIVED CLASS: SavingsAccount
// ==========================================
class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:

    // Constructor
    SavingsAccount(string accNo, string name, double bal)
        : BankAccount(accNo, name, bal)
    {
        interestRate = 4.0;
    }

    // Function overriding
    void displayAccount()
    {
        cout << "\n========================================" << endl;
        cout << "          SAVINGS ACCOUNT" << endl;
        cout << "========================================" << endl;

        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Balance        : Rs. "
             << fixed << setprecision(2) << balance << endl;
        cout << "Interest Rate  : " << interestRate << "%" << endl;

        cout << "========================================" << endl;
    }
};


// ==========================================
// FIND ACCOUNT FUNCTION
// ==========================================
BankAccount* findAccount(
    vector<BankAccount*>& accounts,
    string accountNumber)
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


// ==========================================
// VALIDATE 11-DIGIT ACCOUNT NUMBER
// ==========================================
bool isValidAccountNumber(string accountNumber)
{
    // Check exactly 11 digits
    if (accountNumber.length() != 11)
    {
        return false;
    }

    // Check whether all characters are digits
    for (int i = 0; i < 11; i++)
    {
        if (accountNumber[i] < '0' ||
            accountNumber[i] > '9')
        {
            return false;
        }
    }

    return true;
}


// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    vector<BankAccount*> accounts;

    int choice;

    do
    {
        cout << "\n\n";
        cout << "============================================" << endl;
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


        // ====================================
        // 1. CREATE ACCOUNT
        // ====================================
        if (choice == 1)
        {
            string accNo;
            string name;
            double initialBalance;

            cout << "\n========== CREATE ACCOUNT ==========" << endl;

            cout << "Enter 11-digit Account Number: ";
            cin >> accNo;

            // Validate account number
            if (!isValidAccountNumber(accNo))
            {
                cout << "\nError: Account number must contain"
                     << " exactly 11 digits!" << endl;
            }
            else if (findAccount(accounts, accNo) != NULL)
            {
                cout << "\nError: Account number already exists!"
                     << endl;
            }
            else
            {
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Initial Balance: Rs. ";
                cin >> initialBalance;

                if (initialBalance < 0)
                {
                    cout << "\nError: Balance cannot be negative!"
                         << endl;
                }
                else
                {
                    BankAccount* newAccount =
                        new SavingsAccount(
                            accNo,
                            name,
                            initialBalance
                        );

                    accounts.push_back(newAccount);

                    cout << "\n====================================" << endl;
                    cout << "     ACCOUNT CREATED SUCCESSFULLY" << endl;
                    cout << "====================================" << endl;

                    cout << "Account Number : "
                         << accNo << endl;

                    cout << "Customer Name  : "
                         << name << endl;

                    cout << "Initial Balance: Rs. "
                         << fixed << setprecision(2)
                         << initialBalance << endl;
                }
            }
        }


        // ====================================
        // 2. DISPLAY ACCOUNT
        // ====================================
        else if (choice == 2)
        {
            string accNo;

            cout << "\n========== DISPLAY ACCOUNT ==========" << endl;

            cout << "Enter 11-digit Account Number: ";
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


        // ====================================
        // 3. DEPOSIT MONEY
        // ====================================
        else if (choice == 3)
        {
            string accNo;
            double amount;

            cout << "\n========== DEPOSIT MONEY ==========" << endl;

            cout << "Enter 11-digit Account Number: ";
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


        // ====================================
        // 4. WITHDRAW MONEY
        // ====================================
        else if (choice == 4)
        {
            string accNo;
            double amount;

            cout << "\n========== WITHDRAW MONEY ==========" << endl;

            cout << "Enter 11-digit Account Number: ";
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


        // ====================================
        // 5. CHECK BALANCE
        // ====================================
        else if (choice == 5)
        {
            string accNo;

            cout << "\n========== BALANCE ENQUIRY ==========" << endl;

            cout << "Enter 11-digit Account Number: ";
            cin >> accNo;

            BankAccount* account =
                findAccount(accounts, accNo);

            if (account != NULL)
            {
                cout << "\nAccount Number : "
                     << account->getAccountNumber()
                     << endl;

                cout << "Current Balance: Rs. "
                     << fixed << setprecision(2)
                     << account->getBalance()
                     << endl;
            }
            else
            {
                cout << "\nAccount not found!" << endl;
            }
        }


        // ====================================
        // 6. DISPLAY ALL ACCOUNTS
        // ====================================
        else if (choice == 6)
        {
            int i;

            cout << "\n========== ALL ACCOUNTS ==========" << endl;

            if (accounts.size() == 0)
            {
                cout << "\nNo accounts available!" << endl;
            }
            else
            {
                for (i = 0; i < (int)accounts.size(); i++)
                {
                    accounts[i]->displayAccount();
                }
            }
        }


        // ====================================
        // 7. CLOSE ACCOUNT
        // ====================================
        else if (choice == 7)
        {
            string accNo;
            int i;
            bool found = false;

            cout << "\n========== CLOSE ACCOUNT ==========" << endl;

            cout << "Enter 11-digit Account Number: ";
            cin >> accNo;

            for (i = 0; i < (int)accounts.size(); i++)
            {
                if (accounts[i]->getAccountNumber() == accNo)
                {
                    delete accounts[i];

                    accounts.erase(
                        accounts.begin() + i
                    );

                    cout << "\nAccount closed successfully!"
                         << endl;

                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "\nAccount not found!" << endl;
            }
        }


        // ====================================
        // 8. EXIT
        // ====================================
        else if (choice == 8)
        {
            cout << "\n====================================" << endl;
            cout << "Thank you for using the" << endl;
            cout << "Bank Account Management System!" << endl;
            cout << "====================================" << endl;
        }


        // ====================================
        // INVALID CHOICE
        // ====================================
        else
        {
            cout << "\nInvalid choice!" << endl;
            cout << "Please enter a number between 1 and 8."
                 << endl;
        }

    } while (choice != 8);


    // ==========================================
    // FREE MEMORY
    // ==========================================
    int i;

    for (i = 0; i < (int)accounts.size(); i++)
    {
        delete accounts[i];
    }

    accounts.clear();

    return 0;
}

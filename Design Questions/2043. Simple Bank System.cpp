
class Bank {
public:
    // Vector to store balance for each account (1-based indexing)
    vector<long long> balance;
    
    // Total number of accounts
    int n;

    // Constructor to initialize the bank with initial balances
    Bank(vector<long long>& balance) // TC--->O(N)          SC--->O(N)
    {
        this->balance = balance;   // Copy input balances to class member
        n = balance.size();        // Store total number of accounts
    }
    
    // Function to transfer money from one account to another
    bool transfer(int account1, int account2, long long money) {// TC--->O(1)                    SC--->O(1)
        // Check: both accounts must exist and account1 must have enough money
        if (account1 > n || account2 > n || balance[account1 - 1] < money) 
        {
            return false;  // Invalid accounts or insufficient funds
        }

        // Perform the transfer
        balance[account1 - 1] -= money;  // Deduct from sender
        balance[account2 - 1] += money;  // Add to receiver
        return true;                     // Successful transfer
    }
    
    // Function to deposit money into an account
    bool deposit(int account, long long money) {// TC--->O(1)                        SC--->O(1)
        // Check if account exists
        if (account > n) 
        {
            return false;  // Invalid account number
        }

        // Add money to the specified account
        balance[account - 1] += money;
        return true;  // Successful deposit
    }
    
    // Function to withdraw money from an account
    bool withdraw(int account, long long money) {// TC--->O(1)                                SC--->O(1)
        // Check if account exists and has enough money
        if (account > n || balance[account - 1] < money) 
        {
            return false;  // Invalid account or insufficient balance
        }

        // Subtract money from account balance
        balance[account - 1] -= money;
        return true;  // Successful withdrawal
    }
};

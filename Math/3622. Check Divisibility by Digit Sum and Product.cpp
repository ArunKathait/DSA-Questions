
class Solution {// Time  → O(log n)                                          Space → O(1)
public:

    // This function calculates:
    // digit sum + digit product
    int solve(int n)
    {
        int sum = 0;       // Stores the sum of all digits
        int prod = 1;      // Stores the product of all digits

        // Run until all digits of n are processed
        while(n)
        {
            // Extract the last digit of n
            // Example: n = 123
            // 123 % 10 = 3
            int digit = n % 10;

            // Add the digit to sum
            // Example: 1 + 2 + 3 = 6
            sum += digit;

            // Multiply the digit with the product
            // Example: 1 * 2 * 3 = 6
            prod *= digit;

            // Remove the last digit from n
            // Example:
            // 123 / 10 = 12
            // 12 / 10 = 1
            // 1 / 10 = 0
            n /= 10;
        }

        // Return:
        // digit sum + digit product
        return sum + prod;
    }

    bool checkDivisibility(int n)
    {
        // solve(n) gives:
        // digit sum + digit product
        //
        // Check whether n is completely divisible
        // by (digit sum + digit product).
        //
        // If remainder is 0 → divisible → true
        // Otherwise → false
        return n % solve(n) == 0;
    }
};

/*
NOTE : 

n % 10  → get last digit
n /= 10 → remove last digit

sum     → add all digits
prod    → multiply all digits

solve(n)
    ↓
digit sum + digit product
    ↓
n % solve(n) == 0
    ↓
true / false

*/

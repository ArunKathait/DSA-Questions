*************************************************************APPROACH 1st(RECURSION)*******************************************************************

class Solution {// TC--->O(3^n)           SC--->O(N)
public:
    // Define a function named tribonacci that takes an integer n as input and returns an integer.
    int tribonacci(int n) {
        
       if(n == 0)
       {
           // If n is equal to 0,return 0.
           return 0;
       }
        
        if(n == 1 || n == 2)
        {
            // If n is equal to 1 or n is equal to 2,return 1.
            return 1;
        }
        
        // If n is not equal to 0, 1, or 2,
        // Return the sum of tribonacci(n - 1), tribonacci(n - 2), and tribonacci(n - 3).
        // This is the recursive step where the tribonacci sequence is calculated using recursion.
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        
    }
};

********************************************************APPROACH 2nd(USING MEMOIZATION)*****************************************************************************

class Solution {// TC--->O(N)             SC--->O(N)
public:
    int memorization(int n,vector<int>&dp)
    {
        // If n is equal to 0,return 0.
        if( n == 0)
        {
            return 0;
        }
        
        // If n is equal to 1 or n is equal to 2,return 1.
        if(n == 1 || n == 2)
        {
            return 1;
        }
        
        // If the value of dp[n] is not equal to -1, which means it has been previously computed,
        // Return the precomputed value of dp[n].
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        // Compute the Tribonacci number for n recursively by calling memorization for n-1, n-2, and n-3,
        // and store the result in dp[n].
        dp[n] = memorization(n - 1,dp) + memorization(n - 2,dp) + memorization(n - 3,dp);
        
        // Return the computed Tribonacci number for n.
        return dp[n];
    }
    
    int tribonacci(int n) {
        
        // Declare a vector named dp of size n+1 and initialize all elements to -1.
        // This vector will be used for memoization to store computed Tribonacci numbers.
        vector<int>dp(n  + 1,-1);
        
         // Call the memorization function with n and the dp vector as arguments and return the result.
        return memorization(n,dp);
    }
};

*************************************************APPROACH 3rd(USING TABULATION)*******************************************************************

class Solution {// TC--->O(N)              SC--->O(N)
public:
    int tribonacci(int n) {
        
        // If n is equal to 0,return 0.
        if(n == 0)
        {
            return 0;
        }
        
        // If n is equal to 1 or n is equal to 2,return 1.
        if(n == 1 || n == 2)
        {
            return 1;
        }
        
        // Declare a vector named dp of size n+1 to store the Tribonacci numbers.
        // The vector will be initialized with default values (0 for integers).
        vector<int>dp(n + 1);
        
        // Initialize dp[0] to 0.
        dp[0] = 0;
        
        // Initialize dp[1] to 1.
        dp[1] = 1;
        
        // Initialize dp[2] to 1.
        dp[2] = 1;
        
        // Iterate from i=3 to i=n to calculate Tribonacci numbers starting from the 4th term.
        for(int i=3;i<=n;i++)
        {
        // Compute the Tribonacci number for index i by summing the previous three Tribonacci numbers.
        // Store the result in dp[i].
            dp[i] = dp[i-1] + dp[i - 2] + dp[i - 3];
        }
        
        // Return the Tribonacci number for index n.
        return dp[n];
    }
};

**************************************************APPROACH 4th(USING SPACE OPTIMIZATION)********************************************************

class Solution {// TC--->O(N)        SC--->O(1)
public:
    int tribonacci(int n) {
        
        // If n is equal to 0,return 0.
        if(n == 0)
        {
            return 0;
        }
        
        // If n is equal to 1 or n is equal to 2,return 1.
        if(n == 1 || n == 2)
        {
            return 1;
        }
        
        // Initialize three variables a, b, and c to store the first three terms of the Tribonacci sequence.
        int a = 0;
        int b = 1;
        int c = 1;
        
        // Iterate from i=3 to i=n to calculate Tribonacci numbers starting from the 4th term.
        for(int i=3;i<=n;i++)
        {
            // Calculate the next Tribonacci number by summing the previous three terms.
            // Store the result in a temporary variable d.
            int d = a + b + c;
            
            // Update the value of a to be the value of the previous b.
            a = b;
            
            // Update the value of b to be the value of the previous c.
            b = c;
            
            // Update the value of c to be the calculated Tribonacci number for the current iteration.
            c = d;
        }
        
        // Return the Tribonacci number for index n, which is stored in variable c.
        return c;
    }
};

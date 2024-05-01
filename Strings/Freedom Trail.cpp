**************************************APPROACH 1st(USING RECURSION)*******************************

class Solution {
public:
    // Function to calculate the minimum steps needed to move from one index to another on the ring.
    int countSteps(int ringIndex, int i, int n)
    {
        // Calculate the distance between the two indices.
        int distance = abs(i - ringIndex);
        
        // Calculate the wrap-around distance (when moving from one end of the ring to the other).
        int wrapAround = n - distance;
        
        // Return the minimum of the direct distance and the wrap-around distance.
        return min(distance, wrapAround);
    }
    
    // Recursive function to find the minimum steps needed to spell out the key from the ring.
    int solve(int ringIndex, int keyIndex, string &ring, string &key)
    {
        // Base case: If all characters in the key have been matched.
        if(keyIndex == key.length()) 
        {
            return 0;
        }
        
        // Initialize answer to maximum integer value.
        int ans = INT_MAX;
        
        // Iterate through each character position in the ring.
        for(int i = 0; i < ring.length(); i++) 
        {
            // If the character at the current position in the ring matches the character in the key.
            if(ring[i] == key[keyIndex])
            {
                
                // Calculate the total steps needed to move from current ringIndex to 'i',
                // then add 1 (for pressing the button), and the steps needed for the remaining key characters.
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 + solve(i, keyIndex + 1, ring, key);
    
                // Update the minimum steps needed so far.
                ans = min(ans, totalSteps);
            }
        }
        
        // Return the minimum steps needed.
        return ans;
    }
    
    // Main function to find the minimum steps needed to spell out the key from the ring.
    int findRotateSteps(string ring, string key) {
        
        // Start the recursive function with initial ringIndex = 0, keyIndex = 0.
        return solve(0, 0, ring, key);
    }
};

//NOTE: This will give time limit exceed.

**************************************APPROACH 2nd(USING MEMOIZATION)**********************************

class Solution {
public:
// Define a 2D array 'dp' with dimensions 101x101 to store intermediate results for dynamic programming.
    int dp[101][101];
    
    // Function to calculate the minimum steps needed to move from one index to another on the ring.
    int countSteps(int ringIndex, int i, int n)
    {
        // Calculate the distance between the two indices.
        int distance = abs(i - ringIndex);
        
        // Calculate the wrap-around distance (when moving from one end of the ring to the other).
        int wrapAround = n - distance;
        
        // Return the minimum of the direct distance and the wrap-around distance.
        return min(distance, wrapAround);
    }
    
    // Recursive function to find the minimum steps needed to spell out the key from the ring.
    int solve(int ringIndex, int keyIndex, string &ring, string &key)
    {
        // Base case: If all characters in the key have been matched.
        if(keyIndex == key.length()) 
        {
            return 0;
        }
        
        // If the value for the current state (keyIndex, ringIndex) has been previously calculated and stored in the 'dp' array:
        if(dp[ringIndex][keyIndex] != -1)
        {
           // Return the precalculated value stored in 'dp' for the current state (ringIndex, keyIndex).
            return dp[ringIndex][keyIndex];
        }
        
        // Initialize answer to maximum integer value.
        int ans = INT_MAX;
        
        // Iterate through each character position in the ring.
        for(int i = 0; i < ring.length(); i++) 
        {
            // If the character at the current position in the ring matches the character in the key.
            if(ring[i] == key[keyIndex])
            {
                
                // Calculate the total steps needed to move from current ringIndex to 'i',
                // then add 1 (for pressing the button), and the steps needed for the remaining key characters.
                int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 + solve(i, keyIndex + 1, ring, key);
    
                // Update the minimum steps needed so far.
                ans = min(ans, totalSteps);
            }
        }
        
        // Return the minimum steps needed.
        return dp[ringIndex][keyIndex] =  ans;
    }
    
    // Main function to find the minimum steps needed to spell out the key from the ring.
    int findRotateSteps(string ring, string key) {
        
        // Initializes the array 'dp' with -1, indicating that no valid result has been calculated yet for the corresponding states.
        memset(dp,-1,sizeof(dp));
        
        // Start the recursive function with initial ringIndex = 0, keyIndex = 0.
        return solve(0, 0, ring, key);
    }
};

***********************************APPROACH 3rd(WITHOUT USING DP GLOBALLY)*******************************************

class Solution {// Here we do not assign dp globally
public:
    
    // Function to calculate the minimum steps needed to move from one index to another on the ring.
    int countSteps(int ringIndex, int i, int n) 
    {
        int distance = abs(i - ringIndex);
        int wrapAround = n - distance;
        
        return min(distance, wrapAround);
    }
    
    // Recursive function to find the minimum steps needed to spell out the key from the ring.
    int solve(int ringIndex, int keyIndex, string &ring, string &key, vector<vector<int>>& dp) 
    {
        // Base case: If all characters in the key have been matched.
        if(keyIndex == key.length()) {
            return 0;
        }
        
        // If the value for the current state (keyIndex, ringIndex) has been previously calculated and stored in the 'dp' array:
        if(dp[ringIndex][keyIndex] != -1) 
        {
            
        // Return the precalculated value stored in 'dp' for the current state (ringIndex, keyIndex).
            return dp[ringIndex][keyIndex];
        }
        
        // Initialize answer to maximum integer value.
        int ans = INT_MAX;
        
        // Iterate through each character position in the ring.
        for(int i = 0; i < ring.length(); i++)
        {
            // If the character at the current position in the ring matches the character in the key.
            if(ring[i] == key[keyIndex])
            {
                
                   // Calculate the total steps needed to move from current ringIndex to 'i',
                   // then add 1 (for pressing the button), and the steps needed for the remaining key characters.
                   int totalSteps = countSteps(ringIndex, i, ring.length()) + 1 + solve(i, keyIndex + 1, ring, key, dp);
                
                // Update the minimum steps needed so far.
                ans = min(ans, totalSteps);
            }
        }
        
        // Return the minimum steps needed.
        return dp[ringIndex][keyIndex] = ans;
    }
    
    // Main function to find the minimum steps needed to spell out the key from the ring.
    int findRotateSteps(string ring, string key) 
    {
        // Initialize the dp array locally within the function
        vector<vector<int>> dp(101, vector<int>(101, -1));
        
        // Start the recursive function with initial ringIndex = 0, keyIndex = 0.
        return solve(0, 0, ring, key, dp);
    }
};


***********************************APPROACH 4th(TABULATION)********************************************

class Solution {// TC--->O(n^2 * m)          SC--->O(n*m)
public:
    // Function to calculate the minimum steps needed to move from one index to another on the ring.
    int countSteps(int ringIndex,int i,int n)
    {
        int distance = abs(i - ringIndex);
        int wrapAround = n - distance;
        
        return min(distance,wrapAround);
    }
    
    // Main function to find the minimum steps needed to spell out the key from the ring.
    int findRotateSteps(string ring, string key) {
        // Length of the ring and key
        int n = ring.length();// Length of ring
        int m = key.length();// Length of key
        
        // 2D DP array to store intermediate results.
        // dp[i][j] represents the minimum steps needed to spell out the suffix of the key starting at index 'j'
        // using the ring starting at index 'i'.
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));// Initialized with INT_MAX
        
        // Base case: when key is empty, no steps needed, so initialize dp[i][m] to 0 for all 'i'.
        for(int ringIndex = 0;ringIndex < n ;ringIndex++)
        {
            dp[ringIndex][m] = 0;
        }
        
        // Loop through the characters of the key in reverse order.
        // This loop represents the dynamic programming bottom-up approach.
        for(int keyIndex = m-1;keyIndex >= 0;keyIndex--)
        {
            // Loop through each position on the ring.
            for(int ringIndex = 0;ringIndex<n;ringIndex++)
            {
                
                // Initialize ans to maximum integer value.
                int ans = INT_MAX;
                
                // Loop through each position on the ring to find the character matching the current character in the key.
                for(int i=0;i<ring.length();i++)
                {
                    if(ring[i] == key[keyIndex])
                    {
                        // Calculate the total steps needed to move from current ringIndex to 'i',
                        // then add 1 (for pressing the button), and the steps needed for the remaining key characters.
                        int totalSteps = countSteps(ringIndex,i,ring.length()) + 1 + dp[i][keyIndex + 1];

                        // Update the minimum steps needed so far.
                        ans = min(ans,totalSteps);
                    }
                }
                
                // Store the minimum steps needed for the current state (ringIndex, keyIndex) in dp array.
                dp[ringIndex][keyIndex] = ans;
            }
        }
        
        // Return the minimum steps needed to spell out the key starting from index 0 in the ring.
        return dp[0][0];
    }
};

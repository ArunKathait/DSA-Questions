class Solution       // TC--->O(N)         SC--->O(N)
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){      
        
        // Define the modulo value M
        int M = 1e9 + 7;
        
        // Get the length of the input string
        int n = s.length();
        
        // Create an array to store the intermediate results
        long long dp[n];
        
        // Initialize the first element of the array with the first digit of the string
        dp[0] = s[0] - '0';
        
        // Initialize the total sum with the value of the first digit
        long long ans = dp[0];
        
        // Loop through the string starting from the second character
        for(int i=1;i<n;i++)
        {
            // Get the integer value of the current character
            int val = s[i] - '0';
            
            // Calculate the contribution of the current digit to all substrings
            // by multiplying the previous sum by 10 (to shift digits left)
            // and adding the value of the current digit multiplied by its position (i+1)
            dp[i] = ((dp[i-1] * 10) % M + (val * (i+1)) % M) % M;
            
            // Update the total sum by adding the contribution of the current digit
            ans = (ans + dp[i])%M;
        }
        
        // Return the final sum of all substrings modulo M
        return ans;
    }
};

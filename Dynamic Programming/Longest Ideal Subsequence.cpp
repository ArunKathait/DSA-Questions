****************************************APPROACH 1st********************************************************

class Solution {// TC--->O(n^2)            SC--->O(N)
public:
    int longestIdealString(string s, int k) {
        // Get the length of the input string
        int n = s.length();
        
        // Initialize a dynamic programming array dp of size n+1, where dp[i] represents the length of the longest ideal string ending at index i
        vector<int>dp(n+1,1);
        
        // Initialize a variable to store the length of the longest ideal string
        int longest = 1;
        
        // Iterate through each character of the input string
        for(int i=0;i<n;i++)
        {
            // Iterate backwards through the characters before the current index
            for(int j=i-1;j>=0;j--)
            {
                // Check if the absolute difference between the ASCII values of characters at indices i and j is less than or equal to k
                if(abs(s[j] - s[i]) <= k)
                {
                    // If the condition is satisfied, update dp[i] to the maximum of its current value and dp[j] + 1
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
            
            // Update the length of the longest ideal string seen so far
            longest = max(longest,dp[i]);
        }

        // Return the length of the longest ideal string
        return longest;
    }
};

// NOTE: This will give time limit exceed.


******************************************APPROACH 2nd**************************************************

class Solution {// TC--->O(N)        SC--->O(1)
public:
    int longestIdealString(string s, int k) {
        // Get the length of the input string
        int n = s.length();
        
        // Initialize the variable to store the length of the longest ideal string
        int ans = 0;
        
        // Initialize a vector 'count' of size 26 (representing the 26 lowercase letters), all initialized to 0
        vector<int>count(26,0);
        
        // Iterate through each character of the input string
        for(int i=0;i<n;i++)
        {
            // Calculate the index of the current character in the range [0, 25] (corresponding to 'a' to 'z')
            int index = s[i] - 'a';
            
            // Calculate the left and right bounds of the ideal string considering the allowed difference k
            int left = max(0,index - k);
            int right = min(25,index + k);
            
             // Initialize the variable to store the length of the longest ideal string
            int longest = 0;
            
            // Iterate through the range of letters from 'a' to 'z' within the left and right bounds
            for(int j=left;j<=right;j++)
            {
                // Update the 'longest' variable with the maximum count of occurrences among the letters within the bounds
                longest = max(longest,count[j]);
            }
            
            // Update the count of occurrences of the current character by taking the maximum of its current count
            // and the length of the longest ideal string among the adjacent letters within the allowed difference k, plus 1
            count[index] = max(count[index],longest + 1);
            
            // Update the overall length of the longest ideal string seen so far
            ans = max(ans,count[index]);
        }
        
        // Return the length of the longest ideal string
        return ans;
    }
};

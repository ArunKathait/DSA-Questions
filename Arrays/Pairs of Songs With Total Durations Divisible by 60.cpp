***************************************************APPROACH 1st(BRUTE FORCE)**********************************************

class Solution {// TC--->O(N^2)                           SC--->O(1)
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // Get the size of the input vector 'time'
        int n = time.size();
        
        // Initialize the result variable 'ans' to store the count of valid pairs
        int ans = 0;
        
        // Use a nested loop to check every unique pair in the array
        for(int i=0;i<n;i++)
        {
            // j starts from i + 1 to avoid duplicate pairs
            for(int j=i+1;j<n;j++)
            {
                // Calculate the sum of time[i] and time[j]
                int sum = time[i] + time[j];
                // Check if the sum of the two elements is divisible by 60
                if(sum%60 == 0)
                {
                    // If true, increment the result counter
                    ans++;
                }
            }
        }
        // Return the total count of pairs whose sum is divisible by 60
        return ans;
    }
};

*************************************************APPROACH 2nd(OPTIMAL APPROACH)****************************************

class Solution {// TC--->O(N)                          SC--->O(1)
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        // Get the size of the input vector 'time'
        int n = time.size();
        
        // Create a frequency array to keep track of how many times each remainder (0-59) occurs
        // Initially, all frequencies are 0
        vector<int>freq(60,0);
        
        // Initialize the result variable 'ans' to store the count of valid pairs
        int ans = 0;
        
        // Iterate through each song duration in the 'time' array
        for(int i=0;i<n;i++)
        {
            // Calculate the remainder when the current song's duration is divided by 60
            int remainder = time[i]%60;
            
            // If the remainder is 0, we're looking for pairs where the other song's remainder is also 0
            if(remainder == 0)
            {
                // Add the count of songs with remainder 0
                ans += freq[0];
            }
            else
            {
                // Otherwise, find the complement remainder (60 - remainder) to make the sum divisible by 60
                // Add the count of songs with remainder (60 - remainder)
                ans += freq[60 - remainder];
            }
            
            // Update the frequency array for the current remainder
            freq[remainder]++;
        }
        
        // Return the total number of valid pairs
        return ans;
    }
};

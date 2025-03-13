
class Solution {// TC--->O(N)              SC--->O(1)
public:
    int numberOfSubstrings(string s) {
        // Get the length of the string
        int n = s.length();

        // Variable to store the count of valid substrings
        int ans = 0;

        // Frequency array to track occurrences of 'a', 'b', and 'c'
        vector<int>mp(3,0);
        
        // Left pointer of the sliding window
        int i = 0;

         // Right pointer of the sliding window
        int j = 0;

        // Traverse the string with the right pointer (j)
        while(j < n)
        {
            // Increment the count of the current character ('a', 'b', or 'c')
            mp[s[j] - 'a']++;

            // When all three characters ('a', 'b', and 'c') are present in the window
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0)
            {
                // Add all substrings starting from index i to the end of the string
                ans += n - j;

                // Shrink the window from the left
                // Decrease the count of the character at index 'i'
                mp[s[i] - 'a']--;

                // Move the left pointer ahead
                i++;
            }

            // Expand the right pointer
            j++;
        }

        // Return the total count of valid substrings
        return ans;
        
    }
};

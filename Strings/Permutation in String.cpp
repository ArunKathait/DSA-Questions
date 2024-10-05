************************************************APPROACH 1st***************************************************************

class Solution {// TC--->O(NlogN) * O(m-n)                        SC--->O(N)
public:
    bool checkInclusion(string s1, string s2) {
        // Get the length of s1 and s2
        int n = s1.length();
        int m = s2.length();
        
        // If s1 is longer than s2, it's impossible for s1 to be a permutation of any substring of s2
        if(n > m)
        {
            // Return false immediately
            return false;
        }
        
        // Sort the characters of s1 to prepare for comparison with substrings of s2
        sort(s1.begin(),s1.end());
        
        // Loop through s2 to check all possible substrings of length n
        // Changed from `i < m` to `i <= m - n` to avoid out-of-bounds errors
        for(int i=0;i<=m-n;i++)
        {
            // Extract a substring of length n from s2 starting at index i
            string substring = s2.substr(i,n);
            
            // Sort the substring to check if it's a permutation of s1
            sort(substring.begin(),substring.end());
            
            // If the sorted substring matches the sorted s1, we have found a valid permutation
            if(s1 == substring)
            {
                // Return true as soon as we find a match
                return true;
            }
        }
        // If no permutation is found after checking all substrings, return false
        return false;
    }
};

************************************************APPROACH 2nd(OPTIMAL APPROACH)****************************************

class Solution {// TC--->O(N + M)                           SC--->O(26)
public:
    bool checkInclusion(string s1, string s2) {
        // Get the length of s1 and s2
        int n = s1.length(); // n is the length of s1
        int m = s2.length();// m is the length of s2
        
        // If the length of s1 is greater than s2, it's impossible for s1 to be a permutation of any substring in s2
        if(n > m)
        {
            // Return false since no permutation is possible
            return false;
        }
        
        // Create a frequency array for characters in s1 (since we are dealing with only lowercase letters, we use size 26)
        vector<int>s1Freq(26,0);// Initialized to 0
        
        
        // Fill the frequency array for s1
        for(auto &ch : s1)
        {
            // Increment the frequency of each character in s1
            s1Freq[ch - 'a']++;
        }
        
         // Create another frequency array for the current window in s2
        vector<int>currentWindowFreq(26,0);// Also initialized to 0
        
        // Two pointers for the sliding window approach
        int i = 0;// Left pointer (start of the window)
        int j = 0;// Right pointer (end of the window)
        
        // Start iterating over s2 with the right pointer
        while(j < m)
        {
            // Add the current character s2[j] to the window's frequency array
            currentWindowFreq[s2[j] - 'a']++;
            
            // If the size of the window (j - i + 1) exceeds the length of s1, slide the window by removing the character at the left end (i)
            if(j - i + 1 > n)
            {
                // Remove the character s2[i] from the current window frequency
                currentWindowFreq[s2[i] - 'a']--;
                
                // Move the left pointer forward to shrink the window
                i++;
            }
            
            // If the frequency array of the current window matches the frequency array of s1, we have found a valid permutation
            if(s1Freq == currentWindowFreq)
            {
                // Return true if the window is a permutation of s1
                return true;
            }
            
            // Expand the window by moving the right pointer forward
            j++;
        }
        
        // If we finish checking all windows without finding any valid permutation, return false
        return false;
    }
};

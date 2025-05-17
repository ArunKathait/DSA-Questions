
class Solution {// TC--->O(S + T)                          SC--->O(T)
public:
    string minWindow(string s, string t) {
        int n = t.length();
        
        // If t is longer than s, it's impossible to find a valid window
        if(t.length() > s.length())
        {
            return "";
        }

        // Total characters we need to find from t in s
        int requiredCount = n;

        // Frequency map for characters in t
        unordered_map<char,int> ump;
        for(auto &ch : t)
        {
            ump[ch]++;
        }

        // Two pointers for sliding window
        int i = 0; // start of window
        int j = 0; // end of window

        // Variables to track the smallest valid window
        int startingIndex = -1;
        int minWindowLength = INT_MAX;

        // Iterate through string s with right pointer j
        while(j < s.length())
        {
            char ch = s[j];

            // If the character is needed (its count in ump is > 0), we decrement requiredCount
            if(ump[ch] > 0)
            {
                requiredCount--;
            }

            // We always decrement the count in ump whether it’s in t or not
            ump[ch]--;

            // When all required characters are in the current window
            while(requiredCount == 0)
            {
                // Update the minimum window size and starting index
                int currentWindowSize = j - i + 1;
                if(minWindowLength > currentWindowSize)
                {
                    minWindowLength = currentWindowSize;
                    startingIndex = i;
                }

                // Try to reduce the window size from the left (move i forward)
                ump[s[i]]++;

                // If character at i is now again required (count > 0), increase requiredCount
                if(ump[s[i]] > 0)
                {
                    requiredCount++;
                }
                // shrink the window from the left
                i++; 
            }
            // expand the window from the right
            j++; 
        }

        // Return the smallest window substring if found, otherwise return empty string
        return (minWindowLength == INT_MAX) ? "" : s.substr(startingIndex, minWindowLength);
    }
};

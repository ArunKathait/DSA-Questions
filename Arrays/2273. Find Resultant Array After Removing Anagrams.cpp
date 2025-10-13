************************************************APPROACH 1st************************************************************

class Solution {// TC--->O(N*M)                        SC--->O(N*M)
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        // To store the final words list after removing anagrams
        vector<string> result;              

        // Step 1: Push the first word into the result
        result.push_back(words[0]);

        // Step 2: Create frequency vector for the first word
        vector<int> prevFreq(26, 0);        // To store frequency of characters (for 'a' to 'z')
        for (char ch : words[0]) 
        {
            prevFreq[ch - 'a']++;
        }

        // Step 3: Iterate over remaining words
        for (int i = 1; i < n; i++) 
        {
            // Frequency of the current word
            vector<int> currFreq(26, 0);    

            // Count frequency of each character in the current word
            for (char ch : words[i]) 
            {
                currFreq[ch - 'a']++;
            }

            // Step 4: Compare with previous frequency
            if (currFreq != prevFreq) 
            {
                // If not an anagram, keep this word
                result.push_back(words[i]);

                // Update previous frequency for next comparison
                prevFreq = currFreq;
            }
            // Else, it's an anagram → skip it
        }

        // Step 5: Return the final list
        return result;
    }
};

************************************************APPROACH 2nd**********************************************************

class Solution {// TC--->O(N*M)                                     SC--->O(N*M)
public: 
    // Function to check if two words are anagrams of each other
    bool areAnagrams(string word1, string word2)
    {
        // Step 1: If lengths differ, they can't be anagrams
        if(word1.length() != word2.length())
        {
            return false;
        }

        // Step 2: Count character frequencies for word1 and subtract frequencies for word2
        vector<int> charCount(26, 0);  // For 'a' to 'z'
        for(char ch : word1)
        {
            charCount[ch - 'a']++;     // Increment count for word1
        }

        for(char ch : word2)
        {
            charCount[ch - 'a']--;     // Decrement count for word2
        }

        // Step 3: If any count is not zero, the words are not anagrams
        for(int count : charCount)
        {
            if(count != 0)
            {
                return false;
            }
        }

        // Step 4: All counts zero → words are anagrams
        return true;
    }

    // Main function to remove consecutive anagrams from the list
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> result;             // To store final list of words
        result.push_back(words[0]);        // Always keep the first word

        // Iterate over the rest of the words
        for(int i = 1; i < n; i++)
        {
            // Compare current word with the previous word in the original list
            if(!areAnagrams(words[i], words[i-1]))
            {
                // If not an anagram, add to result
                result.push_back(words[i]);
            }
            // Else: skip the word as it's an anagram of the previous one
        }

        return result;  // Return final list
    }
};

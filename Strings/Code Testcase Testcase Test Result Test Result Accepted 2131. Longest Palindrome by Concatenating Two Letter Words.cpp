class Solution {// TC--->O(N)                             SC--->O(N)
public:
    int longestPalindrome(vector<string>& words) {
        // Create a hashmap to store the frequency of each 2-letter word
        unordered_map<string, int> ump;

        int ans = 0;

        // Iterate through each word in the input list
        for(auto &word : words)
        {
            // Create the reverse of the current word
            string reverseWord = word;

            // reverse the two characters
            swap(reverseWord[0], reverseWord[1]); 

            // If the reverse of the current word exists in the map (can form a palindrome pair)
            if(ump[reverseWord] > 0)
            {
                // Add 4 to the answer since "word + reverseWord" contributes 4 characters to the palindrome
                ans += 4;

                // Decrease the count of reverseWord as it's now used
                ump[reverseWord]--;
            }
            else
            {
                // Otherwise, add the current word to the map for future matching
                ump[word]++;
            }
        }

        // After pairing, check if there’s any word with same characters (like "aa", "bb") left unused
        // Such a word can be placed in the center of the palindrome (contributes 2 characters)
        for(auto &it : ump)
        {
            string word = it.first;
            int count = it.second;

            // Check if the word has identical characters and has at least one occurrence
            if(word[0] == word[1] && count > 0)
            {
                // Only one such word can be used in the middle of the palindrome
                ans += 2;
                break; // break after using one such middle word
            }
        }

        // Return the total length of the longest possible palindrome
        return ans;
    }
};

***********************************************APPROACH 1st(USING SET)**************************************************

class Solution {// TC--->O(N * M)                     SC--->O(N)
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create an unordered set 'set' to store all unique characters from the 'allowed' string.
        // This set will allow us to check whether a character is allowed in constant time O(1). 
        unordered_set<char>set(allowed.begin(),allowed.end());
        
        // Variable to store the count of consistent strings.
        int ans = 0;
        
        // Iterate through each word in the 'words' vector.
        for(auto word:words)
        {
            // A flag to determine if the current word is consistent (contains only allowed characters).
            bool flag = true;
            
            // Iterate through each character in the current word.
            for(auto ch:word)
            {
                // If the character 'ch' is not found in the 'set' of allowed characters,
                // mark the word as inconsistent and break out of the loop.
                if(!set.count(ch))
                {
                    flag = false;
                    break;
                }
            }
            
            // If the word is consistent (i.e., all characters are allowed), increment the answer.
            if(flag)
            {
                // Increment 'ans' if all characters of the word are allowed.
                ans++;
            }
        }
        
        // Return the total number of consistent strings.
        return ans;
    }
};

***********************************************APPROACH 2nd(USING FREQUENCY ARRAY)**************************************
class Solution {// TC--->O(N * M)                      SC--->O(1)
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a vector of size 26 initialized to 0. This will be used to track which characters are 'allowed'.
        // Each index represents a letter ('a' corresponds to index 0, 'b' to 1, ..., 'z' to 25).
        vector<int>count(26,0);
        
        // Mark the characters present in the 'allowed' string by incrementing their respective positions in the 'count' vector.
        for(auto x:allowed)
        {
            // Increment the count for the current character in 'allowed'.
            count[x - 'a']++;
        }
        
        // Initialize the result variable to store the count of consistent strings.
        int ans = 0;
        
        // Loop through each word in the 'words' vector.
        for(int i=0;i<words.size();i++)
        {
            // Flag to check if the current word is consistent with 'allowed'.
            bool flag = true;
            
            // Get the current word from the 'words' vector.
            string str = words[i];
            
            // Check each character in the current word.
            for(auto ch:str)
            {
                // If the current character is not in 'allowed' (i.e., its count is 0 in the 'count' array), set flag to false.
                if(count[ch - 'a'] == 0)
                {
                    flag = false;
                    break;// No need to check further, the word is not consistent.
                }
                
            }
            
            // If the flag remains true, all characters in the word are allowed, so we increment the count of consistent strings.
            if(flag)
            {
                // Increment the result since the current word is consistent.
                ans++;
            }
        }
        
        // Return the total number of consistent strings.
        return ans;
    }
};

********************************************APPROACH 3rd(USING BIT MANIPULATION)*****************************************

  class Solution {// TC--->O(N * M)                   SC--->O(1)
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Initialize a bitmask (integer) to 0. This will be used to store the allowed characters.
        int mask = 0;
        
        // Create a bitmask for the 'allowed' characters.
        // Each bit in 'mask' will represent a character from 'a' to 'z'.
        for(auto &ch:allowed)
        {
            // Shift 1 left by (ch - 'a') positions to create a bitmask for the current character.
            // Use bitwise OR (|=) to set the corresponding bit for the character in 'mask'.
            mask |= (1 << (ch - 'a'));// This sets the bit corresponding to 'ch' in the mask.
        }
        
        // Initialize the counter for consistent strings.
        int ans = 0;
        
        // Iterate through each word in the 'words' vector.
        for(auto &word:words)
        {
            // Flag to check if all characters in the word are allowed.
            bool allCharPresent = true;
            
            // Check each character in the current word.
            for(auto &ch:word)
            {
                // Check if the bit corresponding to the character 'ch' is set in 'mask'.
                // (mask >> (ch - 'a')) shifts the mask right by (ch - 'a') positions.
                // & 1 checks if the least significant bit is 1 (indicating that the character is allowed).
                if(((mask >> (ch - 'a')) & 1) == 0)
                {
                    // If the bit is not set, the character is not allowed.
                    allCharPresent = false;
                    
                    // Break the loop as the word is inconsistent.
                    break;
                }
            }
            
            // If all characters in the word are allowed, increment the count.
            if(allCharPresent)
            {
                // Increment 'ans' if the word is consistent.
                ans++;
            }
        }
        
        // Return the total number of consistent strings.
        return ans;
    }
};

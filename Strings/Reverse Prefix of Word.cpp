******************************************APPROACH 1st*******************************************************

class Solution {// TC--->O(N)         SC--->O(1)
public:
    // Function to reverse the prefix of a string up to the first occurrence of a given character.
    string reversePrefix(string word, char ch) {
        
        // Initialize index to -1, indicating the character hasn't been found yet.
        int index = -1;
        
        // Loop through the characters of the word.
        for(int i=0;i<word.size();i++)
        {
            // If the current character matches the target character 'ch'.
            if(word[i] == ch)
            {
                // Store the index of the first occurrence of 'ch'.
                index = i;
                
                // Reverse the prefix of the word up to the character 'ch'.
                reverse(word.begin(),word.begin() + index + 1);
                
                // Break out of the loop since we've found the target character.
                break;
            }
        }
        
        // If the target character was not found in the word, return the original word.
        if(index == -1)
        {
            // Return the modified word with the reversed prefix.
            return word;
        }
        
        
        return word;
    }
};

*********************************************APPROACH 2nd***************************************************

class Solution {// TC--->O(N)        SC--->O(1)
public:
    // Function to reverse the prefix of a string up to the first occurrence of a given character.
    string reversePrefix(string word, char ch) {
        
        // Initialize index to -1, indicating the character hasn't been found yet.
        int index = -1;
        
        // Loop through the characters of the word to find the target character 'ch'.
        for(int i=0;i<word.size();i++)
        {
            // If the current character matches the target character 'ch'.
            if(word[i] == ch)
            {
                // Store the index of the first occurrence of 'ch'.
                index = i;
                
                // Break out of the loop since we've found the target character.
                break;
            }
        }
        
        // If the target character was not found in the word, return the original word.
        if(index == -1)
        {
            return word;
        }
        
        // Initialize variable 'j' to 0, which will traverse from the beginning of the word.
        int j = 0;
        
        // Reverse the characters from the beginning of the word up to the index where 'ch' was found.
        // Traverse until 'j' is less than 'index'.
        while(j < index)
        {
            // Swap characters at positions 'j' and 'index'.
            swap(word[j],word[index]);
            
            // Move 'j' towards the end of the prefix.
            j++;
            
            // Move 'index' towards the beginning of the prefix.
            index--;
        }
        
        // Return the modified word with the reversed prefix.
        return word;
    }
};


class Solution {// TC--->O(N)                     SC--->O(1)
public:
    bool isValid(string word) {
        int n = word.size();

        // A valid word must have at least 3 characters
        if(n < 3)
        {
            return false;
        }

        // Flags to check presence of at least one vowel and one consonant
        bool hasVowel = false;
        bool hasConsonant = false;

        // Loop through each character in the word
        for(char ch : word)
        {
            // Check if the character is an alphabet letter
            if(isalpha(ch))
            {
                // Convert to lowercase to make comparison case-insensitive
                ch = tolower(ch);

                // Check if it's a vowel
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                {
                    // At least one vowel found
                    hasVowel = true; 
                }
                else
                {
                    // Any other letter is a consonant
                    hasConsonant = true; 
                }
            }
            // If it's not an alphabet and also not a digit, it's invalid
            else if(!isdigit(ch))
            {
                // Invalid character found
                return false; 
            }
        }

        // The word is valid only if it has at least one vowel AND one consonant
        return hasVowel && hasConsonant;
    }
};

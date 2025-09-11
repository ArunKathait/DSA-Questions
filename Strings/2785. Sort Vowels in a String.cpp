*****************************************************APPROACH 1st********************************************************

class Solution {// Time Complexity → O(N log N)                       Space Complexity → O(N)
public:
    string sortVowels(string s) {
        // Store ASCII values of vowels found in the string
        vector<int> vowelAsciiValues;
        
        for (int i = 0; i < s.length(); i++) {
            // Check if the current character is a vowel (both lowercase and uppercase)
            if (s[i] == 'a' || s[i] == 'A' || 
                s[i] == 'e' || s[i] == 'E' || 
                s[i] == 'i' || s[i] == 'I' || 
                s[i] == 'o' || s[i] == 'O' || 
                s[i] == 'u' || s[i] == 'U') 
            {
                // Convert character to its ASCII value and store in the vector
                int asciiValue = int(s[i]);
                vowelAsciiValues.push_back(asciiValue);
            }
        }

        // Sort collected vowels based on their ASCII values
        sort(vowelAsciiValues.begin(), vowelAsciiValues.end());

        // Replace vowels in the original string with sorted vowels
        int vowelIndex = 0; // To track position in sorted vowel list
        
        for (int i = 0; i < s.length(); i++) 
        {
            // Again check if current character is a vowel
            if (s[i] == 'a' || s[i] == 'A' || 
                s[i] == 'e' || s[i] == 'E' || 
                s[i] == 'i' || s[i] == 'I' || 
                s[i] == 'o' || s[i] == 'O' || 
                s[i] == 'u' || s[i] == 'U') 
            {
                // Take the next sorted vowel ASCII value
                int sortedAscii = vowelAsciiValues[vowelIndex++];
                
                // Convert ASCII value back to char
                char sortedChar = char(sortedAscii);
                
                // Replace original vowel with sorted vowel
                s[i] = sortedChar;
            }
        }

        // Return the modified string
        return s;
    }
};


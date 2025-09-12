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

************************************************APPROACH 2nd(BETTER)***********************************************

class Solution {// Time Complexity: O(n)                          Space Complexity: O(1)
public:
    // Helper function: check if a character is a vowel
    bool isVowel(char ch) 
    {
        ch = tolower(ch);  
        // return true if ch is one of the vowels
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        int n = s.length();

        // Frequency map: counts how many times each vowel occurs in the string
        unordered_map<char, int> ump;

        // First pass: count the frequency of all vowels in the string
        for (int i = 0; i < n; i++) 
        {
            if (isVowel(s[i])) 
            {
                ump[s[i]]++;
            }
        }
        
        // String with vowels in ASCII-sorted order
        // (uppercase vowels come first in ASCII, then lowercase)
        string Vowel = "AEIOUaeiou";

        // Pointer to track which vowel to use next
        int k = 0;

        // Second pass: replace vowels in s with sorted vowels
        for (int i = 0; i < n; i++) 
        {
            if (isVowel(s[i])) 
            {
                // Find the next vowel in sorted order that still has remaining frequency
                while (ump[Vowel[k]] == 0) 
                {
                    k++;
                }

                // Place the sorted vowel into the string
                s[i] = Vowel[k];

                // Decrease its frequency since one instance is used
                ump[Vowel[k]]--;
            }
        }

        // Return the modified string with vowels sorted
        return s;
    }
};

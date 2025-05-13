
*******************************************APPROACH 1st***********************************************************

class Solution {// TC--->O(N+t)                          SC--->O(1)
public:
    // Define a large constant for modulo operations to avoid integer overflow
    int M = 1e9 + 7;

    // Function to calculate the length of the string after t transformations
    int lengthAfterTransformations(string s, int t) 
    {
        // Create an unordered_map to store the frequency of each character in the string
        unordered_map<char, int> ump;

        // Count the initial frequency of each character in the string 's'
        for (auto &ch : s) 
        {
            ump[ch]++;
        }

        // Perform the transformation 't' times
        for (int i = 1; i <= t; i++) 
        {
            // Temporary map to store the updated character frequencies after transformation
            unordered_map<char, int> temp;

            // Iterate through the current frequency map
            for (auto &it : ump) 
            {
                // Current character
                int character = it.first;   

                // Frequency of that character  
                int frequency = it.second;    

                if (character != 'z') 
                {
                    // If the character is not 'z', it gets transformed to next character
                    // Add its frequency to the next character in the alphabet
                    temp[character + 1] = (temp[character + 1] + frequency) % M;
                } 
                else 
                {
                    // If character is 'z', it transforms into two characters: 'a' and 'b'
                    // Add frequency to both 'a' and 'b'
                    temp['a'] = (temp['a'] + frequency) % M;
                    temp['b'] = (temp['b'] + frequency) % M;
                }
            }

            // Update the main map with the newly calculated frequencies
            ump = move(temp);
        }

        // Calculate the total number of characters after all transformations
        int ans = 0;
        for (auto &it : ump) 
        {
            ans = (ans + it.second) % M;
        }

        // Return the final answer
        return ans;
    }
};

*********************************************APPROACH 2nd(BETTER APPROACH)*************************************

class Solution {// TC--->O(N + t)                        SC--->O(26) ~ O(1)
public:
    // Modulo constant to prevent integer overflow
    int M = 1e9 + 7;

    // Function to calculate the length of the string after 't' transformations
    int lengthAfterTransformations(string s, int t) {
        // Frequency vector for characters 'a' to 'z' (26 letters), initialized to 0
        vector<int> mp(26, 0);

        // Count initial frequency of each character in the input string 's'
        for (auto &ch : s) 
        {
            // 'a' maps to index 0, 'b' to 1, ..., 'z' to 25
            mp[ch - 'a']++; 
        }

        // Perform the transformation 't' times
        for (int i = 1; i <= t; i++) 
        {
            // Temporary frequency vector for this transformation step
            vector<int> temp(26, 0);

            // Iterate over all 26 characters
            for (int i = 0; i < 26; i++) 
            {
                // Convert index back to character
                char character = i + 'a'; 

                // Get current frequency of the character     
                int frequency = mp[i];         

                if (character != 'z') 
                {
                    // Normal case: shift to next character (e.g., 'a' → 'b')
                    temp[(character + 1) - 'a'] = (temp[(character + 1) - 'a'] + frequency) % M;
                }
                 else 
                 {
                    // Special case: if character is 'z', it becomes both 'a' and 'b'
                    temp['a' - 'a'] = (temp['a' - 'a'] + frequency) % M;
                    temp['b' - 'a'] = (temp['b' - 'a'] + frequency) % M;
                }
            }

            // Update the main frequency vector with the transformed frequencies
            mp = move(temp);
        }

        // Sum up all the frequencies to get the total length after all transformations
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            ans = (ans + mp[i]) % M;
        }

        // Return the total length of the string after transformations
        return ans;
    }
};

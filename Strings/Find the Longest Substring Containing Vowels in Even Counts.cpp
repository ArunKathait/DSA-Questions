************************************************APPROACH 1st**************************************************************

class Solution {// TC--->O(N)                       SC--->O(N)
public:
    int findTheLongestSubstring(string s) {
        // Unordered map to store the first occurrence of each state
        unordered_map<string,int>ump;
        
        // Vector to keep track of the parity (even/odd) of each vowel count
        // Index 0 for 'a', 1 for 'e', 2 for 'i', 3 for 'o', 4 for 'u'
        vector<int>vowelCount(5,0);
        
        // Initial state with all vowel counts being even (represented as "00000")
        string currentState = "00000";
        
        // Record the initial state with index -1 to handle substrings starting from index 0
        ump[currentState] = -1;
        
        // Variable to store the maximum length of the substring found
        int ans = 0;
        
        // Traverse through each character in the input string
        for(int i=0;i<s.length();i++)
        {
            // Update the vowelCount array based on the current character
            if(s[i] == 'a')
            {
                // Toggle between 0 and 1
                vowelCount[0] = (vowelCount[0] + 1)%2;
            }
            else if(s[i] == 'e')
            {
                // Toggle between 0 and 1
                vowelCount[1] = (vowelCount[1] + 1)%2;
            }
            else if(s[i] == 'i')
            {
                // Toggle between 0 and 1
                vowelCount[2] = (vowelCount[2] + 1)%2;
            }
            else if(s[i] == 'o')
            {
                // Toggle between 0 and 1
                vowelCount[3] = (vowelCount[3] + 1)%2;
            }
            else if(s[i] == 'u')
            {
                // Toggle between 0 and 1
                vowelCount[4] = (vowelCount[4] + 1)%2;
            }
            
            // Build the currentState string from the vowelCount vector
            currentState = "";
            for(int j=0;j<5;j++)
            {
                // Convert each count to a string and append
                currentState += to_string(vowelCount[j]);
            }
            
            // Check if the currentState has been seen before
            if(ump.find(currentState) != ump.end())
            {
                // Calculate the length of the substring from the first occurrence to the current index
                ans = max(ans,i - ump[currentState]);
            }
            else 
            {
                // Record the first occurrence of the currentState with the current index
                ump[currentState] = i;
            }
        }
        
        // Return the length of the longest substring found
        return ans;
    }
};

************************************************APPROACH 2nd***********************************************************

class Solution {// TC--->O(N)                       SC--->O(N)
public:
    int findTheLongestSubstring(string s) {
        // Unordered map to store the first occurrence of each state
        unordered_map<string,int>ump;
        
        // Vector to keep track of the parity (even/odd) of each vowel count
        // Index 0 for 'a', 1 for 'e', 2 for 'i', 3 for 'o', 4 for 'u'
        vector<int>vowelCount(5,0);
        
        // Initial state with all vowel counts being even (represented as "00000")
        string currentState = "00000";
        
        // Record the initial state with index -1 to handle substrings starting from index 0
        ump[currentState] = -1;
        
        // Variable to store the maximum length of the substring found
        int ans = 0;
        
        // Traverse through each character in the input string
        for(int i=0;i<s.length();i++)
        {
            // Update the vowelCount array based on the current character
            if(s[i] == 'a')
            {
                // Toggle between 0 and 1
                vowelCount[0] = (vowelCount[0] ^ 1);
            }
            else if(s[i] == 'e')
            {
                // Toggle between 0 and 1
                vowelCount[1] = (vowelCount[1] ^ 1);
            }
            else if(s[i] == 'i')
            {
                // Toggle between 0 and 1
                vowelCount[2] = (vowelCount[2] ^ 1);
            }
            else if(s[i] == 'o')
            {
                // Toggle between 0 and 1
                vowelCount[3] = (vowelCount[3] ^ 1);
            }
            else if(s[i] == 'u')
            {
                // Toggle between 0 and 1
                vowelCount[4] = (vowelCount[4] ^ 1);
            }
            
            // Build the currentState string from the vowelCount vector
            currentState = "";
            for(int j=0;j<5;j++)
            {
                // Convert each count to a string and append
                currentState += to_string(vowelCount[j]);
            }
            
            // Check if the currentState has been seen before
            if(ump.find(currentState) != ump.end())
            {
                // Calculate the length of the substring from the first occurrence to the current index
                ans = max(ans,i - ump[currentState]);
            }
            else 
            {
                // Record the first occurrence of the currentState with the current index
                ump[currentState] = i;
            }
        }
        
        // Return the length of the longest substring found
        return ans;
    }
};

***********************************************APPROACH 3rd(BEST APPROACH)*********************************************

class Solution {// TC--->O(N)                            SC--->O(1)
public:
    int findTheLongestSubstring(string s) {
        // Unordered map to store the first occurrence of each 'mask' value.
        // The mask represents the state of the vowels (even/odd count for each).
        unordered_map<int,int>ump;
        
        // Initial state with all vowels having an even count (mask = 0).
        // Set the starting index for this state to -1 to handle substrings starting from index 0.
        ump[0] = -1;
        
        // Mask to track the even/odd status of the vowels.
        int mask = 0;
        
        // Variable to store the maximum length of the substring found.
        int ans = 0;
        
        // Traverse each character in the input string.
        for(int i=0;i<s.length();i++)
        {
            // If the current character is a vowel, we toggle its corresponding bit in the mask.
            if(s[i] == 'a')
            {
                // Toggle the bit for 'a' (bit 0).
                mask = mask ^ (1 << 0);
            }
            else if(s[i] == 'e')
            {
                // Toggle the bit for 'e' (bit 1).
                mask = mask ^ (1 << 1);
            }
            else if(s[i] == 'i')
            {
                // Toggle the bit for 'i' (bit 2).
                mask = mask ^ (1 << 2);
            }
            else if(s[i] == 'o')
            {
                // Toggle the bit for 'o' (bit 3).
                mask = mask ^ (1 << 3);
            }
            else if(s[i] == 'u')
            {
                // Toggle the bit for 'u' (bit 4).
                mask = mask ^ (1 << 4);
            }
            
            // Check if the current mask has been seen before.
            if(ump.find(mask) != ump.end())
            {
                // If it has been seen, calculate the length of the substring
                // from the first occurrence of this mask to the current index.
                ans = max(ans,i - ump[mask]);
            }
            else
            {
                // If the mask hasn't been seen, record the current index as its first occurrence.
                ump[mask] = i;
            }
        }
        
        // Return the length of the longest substring found.
        return ans;
    }
};

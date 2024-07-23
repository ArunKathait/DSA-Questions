*****************************************APPROACH 1st(USING STACK)**********************************************************

class Solution {// TC--->O(N + N) ~ O(N)          SC--->O(N)
public:
    string removeSubstr(string &s,string &matchStr)
    {
        // Create a stack to help with removing substrings
        stack<char>st;
        
        // Iterate through each character in the input string
        for(auto x:s)
        {
            // Check if the current character and the top of the stack form the "matchStr" substring
            if(x == matchStr[1] && !st.empty() && st.top() == matchStr[0])
            {
                // Remove the top character from the stack if "matchStr" is found
                st.pop();
            }
            else
            {
                // Otherwise, push the current character onto the stack
                st.push(x);
            }
        }
        
        string temp;
        
        // Transfer the characters from the stack to the temporary string in reverse order
        while(!st.empty())
        {
            temp += st.top();
            st.pop();
        }
        
        // Reverse the temporary string to get the correct order
        reverse(temp.begin(),temp.end());
        
        // Return the string with "matchStr" removed
        return temp;
    }
    
    // Function to calculate the maximum score by removing "ab" and "ba" substrings
    int maximumGain(string s, int x, int y) {
        // Get the length of the input string
        int n = s.length();
        
        // Initialize the score to 0
        int score = 0;
        
        // Determine the order of substring removal based on the given scores x and y
        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";
        
        // Remove the substrings that give the higher score first
        string temp_first = removeSubstr(s,maxStr);
        
        // Get the length of the resulting string
        int L = temp_first.length();
        
        // Calculate the number of characters removed and update the score
        int charRemoved = (n - L);
        score += (charRemoved/2) * max(x,y);
        
        // Remove the substrings that give the lower score
        string temp_second = removeSubstr(temp_first,minStr);
        
        // Calculate the number of characters removed
        charRemoved = L - temp_second.length();
        
        // Update the score
        score += (charRemoved/2) * min(x,y);
        
        // Return the maximum score
        return score;
     }
};


**************************************APPROACH 2nd(WITHOUT STACK)**************************************************

class Solution {// TC--->O(N + N) ~ O(N)             SC--->O(1)
public:
    // Function to remove specific substrings ("ab" or "ba") from the string
    string removeSubstr(string &s,string &matchStr)
    {
        // Index to keep track of the position in the modified string
        int i = 0;
        
        // Iterate through the string with a second index j
        for(int j=0;j<s.length();j++)
        {
            // Copy current character to position i
            s[i] = s[j];
            
            // Move to the next position
            i++;
            
            
            // Check if the last two characters form the "matchStr" substring
            if(i >= 2 && s[i-2] == matchStr[0] && s[i-1] == matchStr[1])
            {
                // Remove the last two characters by moving back the index
                i -= 2;
            }
        }
        
        // Erase the remaining part of the string after the index i
        s.erase(s.begin() + i,s.end());
        
        // Return the modified string
        return s;
    }
    
    // Function to calculate the maximum score by removing "ab" and "ba" substrings
    int maximumGain(string s, int x, int y) {
        // Get the length of the input string
        int n = s.length();
        
        // Initialize the score to 0
        int score = 0;
        
        // Determine the order of substring removal based on the given scores x and y
        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (x < y) ? "ab" : "ba";
        
        // Remove the substrings that give the higher score first
        string temp_first = removeSubstr(s,maxStr);
        
        // Get the length of the resulting string
        int L = temp_first.length();
        
        // Calculate the number of characters removed and update the score
        int charRemoved = (n - L);
        
        score += (charRemoved/2) * max(x,y);
        
        // Remove the substrings that give the lower score
        string temp_second = removeSubstr(temp_first,minStr);
        
        // Calculate the number of characters removed
        charRemoved = L - temp_second.length();
        
        // Update the score
        score += (charRemoved/2) * min(x,y);
        
        // Return the maximum score
        return score;
        
    }
};

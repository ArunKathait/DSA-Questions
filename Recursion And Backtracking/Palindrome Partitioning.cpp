
class Solution {// TC--->O(N * 2^N)             SC--->O(N * 2^N)
public:
    // Function to check if a substring is a palindrome
    bool isPalindrome(string s,int start,int end)
    {
        // Loop to compare characters from start to end
        while(start <= end)
        {
            // If characters at start and end are not equal, it's not a palindrome
            if(s[start] != s[end])
            {
               return false;
            }
            // Move towards the center
            start++;
            end--;
        }
        
        // If all characters match, it's a palindrome
        return true;
    }
    
    // Helper function to recursively find all palindromic partitions
    void solve(int index,string s,vector<string>&path,vector<vector<string>>&ans,int n)
    {
        // Base case: if we've reached the end of the string
        if(index == n)
        {
            // Add the current path (a valid partition) to the answer
            ans.push_back(path);
            return ;
        }
        
        // Loop to explore all possible substrings starting from 'index'
        for(int i=index;i<n;i++)
        {
            // Check if the substring from 'index' to 'i' is a palindrome
            if(isPalindrome(s,index,i))
            {
                // If it is, add this substring to the current path
                path.push_back(s.substr(index,i-index+1));
                
                // Recursively solve for the remaining substring
                solve(i+1,s,path,ans,n);
                
                // Backtrack: remove the last added substring to explore new partitions
                path.pop_back();
            }
        }
    }
    
    // Main function to return all possible palindromic partitions of a string
    vector<vector<string>> partition(string s) {
        
        // Get the length of the input string
        int n = s.length();
        
         // This will store all the palindromic partitions
        vector<vector<string>>ans;
        
        // Temporary path to store current partition
        vector<string>path;
        
        // Start the recursive process from index 0
        solve(0,s,path,ans,n);
        
        // Return the list of all palindromic partitions
        return ans;
    }
};

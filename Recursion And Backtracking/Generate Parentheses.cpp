**************************************************APPROACH 1st************************************************************

class Solution {// TC--->O(2n* (2^(2N))                       SC--->O(2*N)
public:
    // Function to check if a string of parentheses is valid
    bool isValid(string current)
    {
        // Variable to track the balance between '(' and ')'
        int count = 0;
        
        // Iterate through each character in the string
        for(auto x:current)
        {
            if(x == '(')
            {
                // Increment count for an opening bracket
                count++;
            }
            else if(x == ')')
            {
                // Decrement count for a closing bracket
                count--;
            }
            
            // If at any point, count becomes negative, it means there are more closing brackets than opening ones, so it's invalid
            if(count < 0)
            {
                return false;
            }
        }
        
        // At the end, the count should be zero for the string to be valid (equal number of opening and closing brackets)
        return count == 0;
    }
    
    // Recursive function to generate all possible combinations of parentheses
    void solve(string current,vector<string>&ans,int n)
    {
        // Base case: If the current string has 2*n characters, check if it's valid
        if(current.size() == 2*n)
        {
            // If valid, add it to the result list
            if(isValid(current))
            {
                ans.push_back(current);
            }
            return ;
        }
        
        // Recursively add '(' to the current string and explore further
        current.push_back('(');
        solve(current,ans,n);
        
        // Backtrack by removing the last added '('
        current.pop_back();
        
        // Recursively add ')' to the current string and explore further
        current.push_back(')');
        solve(current,ans,n);
        
        // Backtrack by removing the last added ')'
        current.pop_back();
        
    }
    
    // Main function to generate all valid combinations of n pairs of parentheses
    vector<string> generateParenthesis(int n) {
        // To store all valid combinations of parentheses
        vector<string>ans;
        
        // Start the recursive process with an empty string
        solve("",ans,n);
        
        // Return the list of valid combinations
        return ans;
    }
};

************************************************APPROACH 2nd(BETTER APPROACH)***************************************

class Solution {// TC--->O(2^N)                       SC--->O(2*N)
public:
    // Recursive function to generate valid combinations of parentheses
    void solve(string current,vector<string>&ans,int n,int open,int close)
    {
        // Base case: If the current string has n open and n close parentheses, it's a valid combination
        if(open == n && close == n)
        {
            // Add the valid combination to the result vector
            ans.push_back(current);
            return ;
        }
        
        // If the number of open parentheses used is less than n, we can add an opening parenthesis
        if(open < n)
        {
            // Add an opening parenthesis to the current string
            current.push_back('(');
            
            // Recurse with one more open parenthesis
            solve(current,ans,n,open+1,close);
            
            // Backtrack by removing the last added '(' to explore other possibilities
            current.pop_back();
        }
        
        // If the number of closing parentheses used is less than the number of open parentheses,
        // we can add a closing parenthesis (only add ')' if there are open parentheses to match)
        if(open > close)
        {
            // Add a closing parenthesis to the current string
            current.push_back(')');
            
            // Recurse with one more close parenthesis
            solve(current,ans,n,open,close+1);
            
            // Backtrack by removing the last added ')' to explore other possibilities
            current.pop_back();
        }
        
    }
    
    // Main function to generate all valid combinations of n pairs of parentheses
    vector<string> generateParenthesis(int n) {
        
        // To store all valid combinations of parentheses
        vector<string>ans;
        
        // Counter for the number of open parentheses '(' used
        int open = 0;
        
         // Counter for the number of close parentheses ')' used
        int close = 0;
        
        // Start the recursive process with an empty string and 0 open/close parentheses
        solve("",ans,n,open,close);
        
        // Return the list of valid combinations
        return ans;
    }
};

**********************************************APPROACH 3rd(MINOR CHANGES IN ABOVE)**************************************

class Solution {// TC--->O(2^N)                     SC--->O(2*N)
public:
    
    void solve(string current,vector<string>&ans,int n,int open,int close)
    {
        // Base case: when both 'open' and 'close' reach 'n', a valid combination is formed
        if(open == n && close == n)
        {
            // Add the valid combination to the result vector

            ans.push_back(current);
            
            // End the current recursion branch
            return ;
        }
        
        // If the number of open parentheses used is less than 'n', add an open parenthesis '('
        if(open < n)
        {
            // Recurse with one more '('
            solve(current + '(',ans,n,open + 1,close);
        }
        
        // If the number of close parentheses used is less than the number of open ones, add a close parenthesis ')'
        if(open > close)
        {
            // Recurse with one more ')'
            solve(current + ')',ans,n,open,close + 1);
        }
    }
    
    // Main function to generate all valid parentheses combinations for 'n' pairs
    vector<string> generateParenthesis(int n) {
        // Vector to store all valid combinations
        vector<string>ans;
        
        // Counter for open parentheses '('
        int open = 0;
        
        // Counter for close parentheses ')'
        int close = 0;
        
        // Start the recursive process with an empty string
        solve("",ans,n,open,close);
        
        // Return the vector containing all valid combinations
        return ans;
    }
};

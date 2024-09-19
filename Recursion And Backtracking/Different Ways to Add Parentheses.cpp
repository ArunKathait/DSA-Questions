
class Solution {// TC--->O(N * 2^N)                     SC--->O(2^N)
public:
    // A helper function to recursively compute all possible results from the expression
    vector<int>solve(string s)
    {
        // This will store the possible results for the current sub-expression.
        vector<int>ans;
        
        // Loop through each character of the string 's'
        for(int i=0;i<s.length();i++)
        {
            // Check if the current character is an operator (+, -, or *)
            if(s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                // Recursively solve the left part of the expression (before the operator)
                vector<int>leftAns = solve(s.substr(0,i));
                
                // Recursively solve the right part of the expression (after the operator)
                vector<int>rightAns = solve(s.substr(i+1));
                
                // Combine the results of the left and right parts based on the operator
                for(auto &x:leftAns)
                {
                    for(auto &y:rightAns)
                    {
                        if(s[i] == '+')
                        {
                            // If operator is '+', add results
                            ans.push_back(x + y);
                        }
                        else if(s[i] == '-')
                        {
                            // If operator is '-', subtract results
                            ans.push_back(x - y);
                        }
                        else if(s[i] == '*')
                        {
                            // If operator is '*', multiply results
                            ans.push_back(x * y);
                        }
                    }
                }
            }
        }
        
        // Base case: if no operator is found, this means 's' is a number
        if(ans.empty())
        {
            // Convert the string to an integer and add it to the result
            ans.push_back(stoi(s));
        }
        
        // Return the vector of possible results for this sub-expression
        return ans;
    }
    
    // The main function to solve the problem, which calls the helper function
    vector<int> diffWaysToCompute(string expression) {
        // Call 'solve' on the input expression and return the result
        return solve(expression);
    }
};

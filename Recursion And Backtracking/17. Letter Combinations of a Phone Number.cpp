
class Solution {// TC--->O(4^N)                                 SC--->O(4^N * N)
public:
    // Recursive function to build letter combinations
    void solve(int index,int n,string &digits,string &temp,vector<string>&ans,unordered_map<char,string>&ump)
    {
        // Base case: if we've formed a string of length n, add it to result
        if(index >= n)
        {
            // A complete combination is formed
            ans.push_back(temp);
            return ;
        }
        
        // Get the current digit
        char ch = digits[index];

        // Get the corresponding letters (e.g., '2' → "abc")
        string str = ump[ch];

        // Loop through each letter corresponding to the current digit
        for(int i=0;i<str.length();i++)
        {
            // Add current letter to the temporary string
            temp.push_back(str[i]);

            // Recurse for next digit
            solve(index + 1,n,digits,temp,ans,ump);

            // Backtrack to try the next letter
            temp.pop_back();
        }
    }

    // Main function to return all possible letter combinations
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0)
        {
            // If input is empty, return an empty list
            return {};
        }

        // Mapping of digits to corresponding letters on a phone keypad
        unordered_map<char,string>ump;
        ump['2'] = "abc";
        ump['3'] = "def";
        ump['4'] = "ghi";
        ump['5'] = "jkl";
        ump['6'] = "mno";
        ump['7'] = "pqrs";
        ump['8'] = "tuv";
        ump['9'] = "wxyz";

        // To store the final combinations
        vector<string>ans;

        // Temporary string to build each combination
        string temp = "";

        // Start recursive combination generation from index 0
        solve(0,n,digits,temp,ans,ump);

        // Return the final list of combinations
        return ans;
        
    }
};

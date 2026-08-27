*************************************************APPROACH 1st(BRUTE FORCE)******************************************

class Solution {// Time  : O(n² × n!)                                           Space : O(n × n!)
public:

    // This function generates all possible permutations of string s
    void solve(int index, int n, string &s, vector<string>& ans)
    {
        // If index reaches the end of the string,
        // we have formed one complete permutation.
        if(index >= n)
        {
            ans.push_back(s);  // Store the permutation
            return;
        }

        // Try every character from index to n-1
        // at the current position.
        for(int i = index; i < n; i++)
        {
            // Put s[i] at the current index.
            // This gives us one possible choice
            // for the current position.
            swap(s[index], s[i]);

            // Recursively generate permutations
            // for the remaining positions.
            solve(index + 1, n, s, ans);

            // Backtrack:
            // Restore the original string so that
            // we can try the next character.
            swap(s[index], s[i]);
        }
    }

    string lexGreaterPermutation(string s, string target)
    {
        int n = s.length();

        // This vector will contain all permutations of s.
        vector<string> ans;

        // Generate all permutations of s.
        solve(0, n, s, ans);

        // Sort permutations lexicographically.
        // After sorting, the smallest permutation
        // will come first.
        sort(ans.begin(), ans.end());

        // Traverse permutations in lexicographical order.
        for(auto &str : ans)
        {
            // Find the first permutation that is
            // lexicographically greater than target.
            if(str > target)
            {
                return str;
            }
        }

        // If no permutation is greater than target,
        // return an empty string.
        return "";
    }
};

**********************************************APPROACH 2nd(OPTIMAL)*************************************************
  

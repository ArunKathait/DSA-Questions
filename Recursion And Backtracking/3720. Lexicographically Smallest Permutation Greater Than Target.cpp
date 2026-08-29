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
  

class Solution { // TC ---> O(26^n) worst case                               SC ---> O(n)
public: 
    // Stores the final lexicographically smallest permutation
    // that is strictly greater than target.
    string ans; 

    // Recursive function to build the permutation character by character.
    //
    // index   -> current position we are filling
    // n       -> length of target/string
    // current -> permutation built so far
    // target  -> string that our answer must be greater than
    // freq     -> frequency of each character available from s
    // greater  -> tells whether current is already greater than target
    bool solve(int index, int n, string &current, string &target,
               vector<int>&freq, bool greater) 
    { 
        // We have constructed all n characters.
        if(index >= n) 
        { 
            // If the constructed string is already greater than target,
            // we found a valid answer.
            if(greater) 
            { 
                ans = current; 
                return true; 
            } 

            // current == target, so it is not strictly greater.
            return false; 
        } 

        // Try every possible character from 'a' to 'z'.
        //
        // We try in increasing order because we want the
        // lexicographically smallest valid permutation.
        for(char ch = 'a'; ch <= 'z'; ch++) 
        { 
            // If this character is not available in s,
            // we cannot use it.
            if(freq[ch - 'a'] == 0) 
            { 
                continue; 
            } 

            // If we are still equal to target so far,
            // choosing a character smaller than target[index]
            // would make the entire string smaller than target.
            //
            // Therefore, skip it.
            if(greater == false && ch < target[index]) 
            { 
                continue; 
            } 

            // Choose this character.
            current.push_back(ch); 

            // Use one occurrence of this character.
            freq[ch - 'a']--; 

            // Check whether the string is now greater than target.
            //
            // Once we become greater, we will remain greater
            // regardless of what characters we choose later.
            bool isGreater = greater || ch > target[index]; 

            // Recursively fill the next position.
            if(solve(index + 1, n, current, target, freq, isGreater)) 
            { 
                // A valid answer has been found.
                // Since we tried characters from 'a' to 'z',
                // this is the smallest possible answer.
                return true; 
            } 

            // Backtracking:
            //
            // The choice of 'ch' did not lead to a valid answer,
            // so remove it and try another character.
            current.pop_back(); 

            // Restore the frequency because we are undoing
            // our previous choice.
            freq[ch - 'a']++; 
        } 

        // No character choice from this position
        // could produce a valid answer.
        return false; 
    } 

    string lexGreaterPermutation(string s, string target) { 
        int n = s.length(); 

        // freq[i] stores how many times character
        // ('a' + i) occurs in s.
        vector<int> freq(26, 0); 

        // Count frequency of every character in s.
        for(auto &ch : s) 
        { 
            freq[ch - 'a']++; 
        } 

        // Initially, no characters have been selected.
        string current; 

        // Start building the answer from index 0.
        //
        // greater = false because initially
        // current is equal to the empty prefix of target.
        solve(0, n, current, target, freq, false); 

        // Return the smallest valid permutation found.
        // If no valid permutation exists, ans remains "".
        return ans; 
    } 
};

/*

┌──────────────────────────────────────┐
│   LEXICOGRAPHICALLY GREATER PERM.    │ 
├──────────────────────────────────────┤
│                                      │
│ 1. Count frequency of characters     │
│    using freq[26]                    │
│                                      │
│ 2. State: solve(index)               │
│    = build permutation from index    │
│                                      │
│ 3. Try characters from 'a' to 'z'    │
│    → ensures smallest answer         │
│                                      │
│ 4. If current == target so far:      │
│    choose ch >= target[index]        │
│                                      │
│    ch < target[index] → skip         │
│                                      │
│ 5. Once ch > target[index]:          │
│    greater = true                    │
│    → remaining chars can be anything │
│                                      │
│ 6. If complete string is greater:    │
│    store in ans and return true      │
│                                      │
│ 7. If choice doesn't work:           │
│    backtrack                         │
│    → remove character                │
│    → restore frequency               │
│                                      │
│ Pattern:                             │
│ Backtracking + Frequency + Greedy    │
│                                      │
│ Time  : O(26^n) worst case           │
│ Space : O(n)                         │
└──────────────────────────────────────┘

*/

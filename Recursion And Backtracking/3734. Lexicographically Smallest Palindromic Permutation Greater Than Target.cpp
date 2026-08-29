
class Solution { // Time: O((n/2)! × n) worst case                                         Space: O(n)
public: 
    // Stores the middle character of the palindrome.
    // '$' means there is no middle character, i.e. n is even.
    char midChar = '$'; 

    // Length of the left half of the palindrome.
    int half; 

    // Stores the final answer.
    string ans; 
 
    // Backtracking function to construct the left half.
    //
    // index    -> current position we are filling
    // n        -> length of the original string
    // current  -> left half constructed so far
    // target   -> given target string
    // halfFreq -> frequency of characters available for left half
    // greater   -> whether current left half is already greater
    //              than the corresponding target prefix
    bool solve(int index, int n, string &current, string &target,
               vector<int>& halfFreq, bool greater) 
    { 
        // We have completely constructed the left half.
        if(index == half) 
        { 
            // Start constructing the complete palindrome.
            string candidate = current; 

            // The right half is the reverse of the left half.
            string rightHalf = candidate; 
            reverse(rightHalf.begin(), rightHalf.end()); 
 
            // If n is odd, add the middle character.
            if(midChar != '$') 
            { 
                candidate += midChar; 
            } 

            // Add the reversed left half.
            candidate += rightHalf; 
             
            // Check whether the complete palindrome is
            // strictly greater than target.
            if(candidate > target) 
            { 
                ans = candidate; 
                return true; 
            } 

            // Candidate is either equal to or smaller than target.
            return false; 
        } 
 
        // Try every possible character from 'a' to 'z'.
        //
        // We try in increasing order so that the first valid
        // palindrome we find is lexicographically smallest.
        for(char ch = 'a'; ch <= 'z'; ch++) 
        { 
            // If this character is not available in the left half,
            // we cannot choose it.
            if(halfFreq[ch - 'a'] == 0) 
            { 
                continue; 
            } 
 
            // If we are still equal to target so far,
            // choosing a smaller character would make our
            // palindrome smaller than target.
            //
            // Therefore, skip this character.
            if(greater == false && ch < target[index]) 
            { 
                continue; 
            } 
 
            // Choose the character.
            current.push_back(ch); 

            // Use one occurrence of this character.
            halfFreq[ch - 'a']--; 
 
            // Check whether we are now greater than target.
            //
            // Once greater becomes true, it stays true.
            //
            // Example:
            // target = "abc..."
            // current = "abd..."
            // Since 'd' > 'c', the entire string is already greater.
            bool isGreater = greater || ch > target[index]; 
             
            // Recursively construct the next position.
            if(solve(index + 1, n, current, target, halfFreq, isGreater)) 
            { 
                // A valid answer has been found.
                return true; 
            } 
 
            // Backtracking:
            // Remove the character because this choice
            // did not lead to a valid answer.
            current.pop_back(); 

            // Restore its frequency so that it can be
            // used in another possible arrangement.
            halfFreq[ch - 'a']++; 
        } 
 
        // No valid choice was found from this state.
        return false; 
    } 
 
    string lexPalindromicPermutation(string s, string target) { 
        int n = s.length(); 
 
        // Frequency of every character in s.
        vector<int> freq(26, 0); 
 
        // Count how many times each character occurs.
        for(auto &ch : s) 
        { 
            freq[ch - 'a']++; 
        } 
         
        // A palindrome can have at most one character
        // with an odd frequency.
        int oddCount = 0; 

        for(int c = 0; c < 26; c++) 
        { 
            if(freq[c] % 2 == 1) 
            { 
                oddCount++; 

                // The odd-frequency character becomes
                // the middle character of the palindrome.
                midChar = c + 'a'; 
            } 
        } 
 
        // If more than one character has odd frequency,
        // a palindrome cannot be formed.
        if(oddCount > 1) 
        { 
            return ""; 
        } 
         
        // Only half of each character's frequency
        // goes into the left half.
        //
        // Example:
        // a: 4 -> 2 in left half
        // b: 2 -> 1 in left half
        // c: 1 -> 0 in left half
        vector<int> halfFreq(26, 0); 

        for(int c = 0; c < 26; c++) 
        { 
            halfFreq[c] = freq[c] / 2; 
        } 
 
        // For a palindrome, we only need to construct
        // the first half.
        half = n / 2; 
 
        string current; 

        // Start backtracking from index 0.
        //
        // Initially, current is not greater than target,
        // so greater = false.
        solve(0, n, current, target, halfFreq, false); 

        // Return the smallest valid palindrome.
        // If no valid palindrome exists, ans remains "".
        return ans; 
    } 
};

/* 

┌──────────────────────────────────────┐
│  PALINDROMIC PERMUTATION > TARGET    │
├──────────────────────────────────────┤
│                                      │
│ 1. Count frequency of every char     │
│                                      │
│ 2. Palindrome condition:             │
│    At most ONE odd frequency         │
│                                      │
│ 3. Split characters:                 │
│    halfFreq[c] = freq[c] / 2         │
│                                      │
│ 4. Build only LEFT HALF              │
│                                      │
│ 5. Try 'a' → 'z'                     │
│    → smallest character first        │
│                                      │
│ 6. If still equal to target:         │
│    ch < target[index] → skip         │
│                                      │
│ 7. If ch > target[index]:            │
│    greater = true                    │
│    → entire palindrome is greater    │
│                                      │
│ 8. Build complete palindrome:        │
│                                      │
│    LEFT + MIDDLE + reverse(LEFT)     │
│                                      │
│ 9. Check candidate > target          │
│                                      │
│ 10. If choice fails: BACKTRACK       │
│     → remove character               │
│     → restore frequency              │
│                                      │
│ Pattern:                             │
│ Frequency + Backtracking + Palindrome│
└──────────────────────────────────────┘

  */


class Solution { // Time  : O(n²)                                          Space : O(n)
public: 
    string shortestBeautifulSubstring(string s, int k) { 
        int n = s.length(); 
 
        // i = left pointer of the sliding window
        // j = right pointer of the sliding window
        int i = 0; 
        int j = 0; 
 
        // Number of '1's present in the current window [i...j]
        int ones = 0; 
 
        // Stores the best answer found so far
        string ans; 
 
        // Expand the window using j
        while(j < n) 
        { 
            // If current character is '1',
            // increase the count of ones.
            if(s[j] == '1') 
            { 
                ones++; 
            } 
 
            // Shrink the window from the left when:
            // 1. We have more than k ones
            // OR
            // 2. The leftmost character is '0'
            // Removing leading zeros makes the substring shorter
            // without changing the number of ones.
            while(ones > k || s[i] == '0') 
            { 
                // If we are removing a '1',
                // decrease the count of ones.
                if(s[i] == '1') 
                { 
                    ones--; 
                } 
 
                // Move the left pointer forward.
                i++; 
            } 
 
            // If the current window contains exactly k ones,
            // then it is a valid beautiful substring.
            if(ones == k) 
            { 
                // Extract the current substring [i...j].
                //
                // Length = j - i + 1
                string temp = s.substr(i, j - i + 1); 
 
                // Update answer if:
                // 1. We don't have an answer yet
                // OR
                // 2. Current substring is shorter
                // OR
                // 3. Both have the same length but current
                //    substring is lexicographically smaller.
                if(ans.empty() || 
                   ans.length() > temp.length() || 
                   (ans.length() == temp.length() && ans > temp)) 
                { 
                    ans = temp; 
                } 
            } 
 
            // Expand the window to the right.
            j++; 
        } 
 
        return ans; 
    } 
};

/* 

┌──────────────────────────────────────────┐
│   SHORTEST BEAUTIFUL SUBSTRING - SW      │
├──────────────────────────────────────────┤
│                                          │
│ 1. Expand window using j                 │
│    → count number of '1's                │
│                                          │
│ 2. If ones > k                           │
│    → move i forward                      │
│    → remove extra '1's                   │
│                                          │
│ 3. If s[i] == '0'                        │
│    → remove leading zeros                │
│    → substring becomes shorter           │
│                                          │
│ 4. If ones == k                          │
│    → current window is BEAUTIFUL         │
│                                          │
│ 5. Compare with ans:                     │
│    → shorter substring wins              │
│    → same length → lexicographically     │
│      smaller substring wins              │
│                                          │
│ Pattern:                                 │
│ Sliding Window + Greedy Shrinking        │
│                                          │
│ Time  : O(n²)                            │
│ Space : O(n)                             │
└──────────────────────────────────────────┘

*/

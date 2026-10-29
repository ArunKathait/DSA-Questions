
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakePalindrome(string s) {
        // Each bit represents one character from 'a' to 'z'.
        // A set bit means that character appears an odd number of times.
        int mask = 0;

        // Process every character in the string.
        for (char c : s) {
            // Toggle the bit corresponding to the current character.
            // If the character appears twice, its bit becomes 0 again.
            mask ^= (1 << (c - 'a'));
        }

        // A palindrome is possible if at most one bit is set.
        // This expression checks whether mask has at most one set bit.
        return (mask & (mask - 1)) == 0;
    }
};

int main() {
    Solution sol;

    string s = "aabbc";

    // Check whether the string can be rearranged into a palindrome.
    if (sol.canMakePalindrome(s)) {
        cout << "Palindrome is possible" << endl;
    } else {
        cout << "Palindrome is not possible" << endl;
    }

    return 0;
}

/*

┌──────────────────────────────────────┐
│ Palindrome Check (Bitmask)           │
├──────────────────────────────────────┤
│ Steps                                │
│ ☐ Initialize mask = 0                │
│ ☐ Toggle: mask ^= (1 << (c - 'a'))   │
│ ☐ Duplicate bits cancel using XOR    │
│ ☐ Check: (mask & (mask - 1)) == 0    │
├──────────────────────────────────────┤
│ Key Trick                            │
│ ☐ 0 set bits  → Palindrome possible  │
│ ☐ 1 set bit   → Palindrome possible  │
│ ☐ 2+ set bits → Not possible         │
├──────────────────────────────────────┤
│ Time Complexity      → O(n)          │
│ Auxiliary Space      → O(1)          │
└──────────────────────────────────────┘

*/

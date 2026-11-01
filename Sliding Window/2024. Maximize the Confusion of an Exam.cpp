*************************************************APPROACH 1st(BRUTE FORCE)**********************************************

class Solution {// Time  : O(n * 2^n)                 Space : O(n)
public:

    // Finds the longest consecutive sequence of same characters (T or F)
    // in the current modified string.
    void findMax(string &answerKey, int &ans) {

        int n = answerKey.length();
        int i = 0;

        // Traverse the entire string
        while (i < n) 
        {
            // Start counting a new consecutive group
            int length = 0;

            // Store the character of the current group (T or F)
            char ch = answerKey[i];

            // Count consecutive occurrences of the same character
            while (i < n && answerKey[i] == ch) 
            {
                length++;
                i++;
            }

            // Update the maximum consecutive length
            ans = max(ans, length);
        }
    }

    // Recursively explores the choices of flipping or not flipping
    // characters, while allowing at most k flips.
    void solve(int index, int n, string &answerKey, int k, int &ans) {

        // Check the maximum consecutive sequence in the current string
        findMax(answerKey, ans);

        // Base case:
        // 1. All characters have been processed.
        // 2. No more flips are allowed.
        if (index >= n || k == 0) 
        {
            return;
        }

        // CHOICE 1: Flip the current character
        // T becomes F and F becomes T.
        answerKey[index] = (answerKey[index] == 'T') ? 'F' : 'T';

        // Move to the next index and use one flip
        solve(index + 1, n, answerKey, k - 1, ans);

        // BACKTRACKING:
        // Restore the original character after exploring the flip choice.
        answerKey[index] = (answerKey[index] == 'T') ? 'F' : 'T';

        // CHOICE 2: Do not flip the current character.
        // Move to the next index without decreasing k.
        solve(index + 1, n, answerKey, k, ans);
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        int n = answerKey.size();
        int ans = 0;

        // Start recursion from index 0 with k available flips
        solve(0, n, answerKey, k, ans);

        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│       LEETCODE 2024 - MAXIMUM CONSECUTIVE    │
├──────────────────────────────────────────────┤
│ Approach: Recursion + Backtracking           │
├──────────────────────────────────────────────┤
│ 1. Check longest consecutive T/F using       │
│    findMax().                                │
│ 2. Choice 1: Flip current character (k - 1). │
│ 3. Backtrack: Restore original character.    │
│ 4. Choice 2: Do not flip (k unchanged).      │
│ 5. Update global maximum answer.             │
├──────────────────────────────────────────────┤
│ Base Case: index == n OR k == 0              │
│ Choices:    Flip / Do not flip               │
├──────────────────────────────────────────────┤
│ Time Complexity:  O(n * 2^n)                 │
│ Space Complexity: O(n)                       │
│ Extra Space:      O(n) recursion stack       │
└──────────────────────────────────────────────┘

*/

**********************************************APPROACH 2nd(BETTER)***************************************************

class Solution {// Time Complexity : O(2 * n)            Space Complexity : O(1)
public:

    // Finds the longest substring that can be converted
    // entirely into targetChar using at most k flips.
    int findMax(string answerKey, int n, int k, char targetChar) {

        int ans = 0;

        // i = left pointer, j = right pointer
        int i = 0;
        int j = 0;

        // Counts characters that are different from targetChar.
        // These are the characters we need to flip.
        int count = 0;

        // Expand the window by moving the right pointer.
        while (j < n) 
        {
            // If the current character is not our target,
            // we need one flip to convert it.
            if (answerKey[j] != targetChar) 
            {
                count++;
            }

            // If required flips exceed k, shrink the window
            // from the left until the window becomes valid.
            while (count > k) 
            {
                // If the leftmost character was different
                // from targetChar, remove its flip requirement.
                if (answerKey[i] != targetChar) 
                {
                    count--;
                }

                // Move the left pointer forward.
                i++;
            }

            // Current window is valid because count <= k.
            // Update the maximum window length.
            ans = max(ans, j - i + 1);

            // Expand the window.
            j++;
        }

        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        int n = answerKey.length();

        // Case 1: Find the longest window that can become all T.
        int makeAllT = findMax(answerKey, n, k, 'T');

        // Case 2: Find the longest window that can become all F.
        int makeAllF = findMax(answerKey, n, k, 'F');

        // Return the maximum of both possibilities.
        return max(makeAllT, makeAllF);
    }
};

/*

┌────────────────────────────────────────────────────┐
│       LEETCODE 2024 - MAXIMIZE THE CONFUSION       │
├────────────────────────────────────────────────────┤
│ Approach: Variable Size Sliding Window             │
├────────────────────────────────────────────────────┤
│ KEY IDEA:                                          │
│ Find the longest window that can be converted      │
│ entirely into T or F using at most k flips.        │
├────────────────────────────────────────────────────┤
│ ALGORITHM:                                         │
│ 1. Take targetChar = 'T' and find the longest      │
│    valid window.                                   │
│ 2. Count characters != targetChar (flips needed).  │
│ 3. If count > k, shrink window from the left.      │
│ 4. Update ans = max(ans, j - i + 1).               │
│ 5. Repeat the same process for targetChar = 'F'.   │
│ 6. Return max(makeAllT, makeAllF).                 │
├────────────────────────────────────────────────────┤
│ POINTERS & CONDITIONS:                             │
│ i     -> Left boundary of the window               │
│ j     -> Right boundary of the window              │
│ count -> Number of flips required                  │
│ Valid -> count <= k                                │
│ Length -> j - i + 1                                │
├────────────────────────────────────────────────────┤
│ COMPLEXITY:                                        │
│ Time  : O(2n) = O(n)                               │
│ Space : O(1)                                       │
│ Extra : O(1)                                       │
└────────────────────────────────────────────────────┘

*/

***************************************************APPROACH 3rd(OPTIMAL)**********************************************

class Solution {// Time Complexity : O(n)                      Space Complexity : O(1) 
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        int n = answerKey.size();

        // Count the frequency of T and F in the current window.
        int countF = 0;
        int countT = 0;

        // Stores the maximum valid window length.
        int ans = 0;

        // i = left pointer, j = right pointer.
        int i = 0;
        int j = 0;

        // Expand the window by moving the right pointer.
        while (j < n) 
        {
            // Include the current character in the window.
            if (answerKey[j] == 'T') 
            {
                countT++;
            }
            else 
            {
                countF++;
            }

            // To make all characters identical, we flip
            // the character that occurs less frequently.
            // Therefore, minimum flips = min(countT, countF).

            // If required flips exceed k, shrink the window.
            while (min(countT, countF) > k) 
            {
                // Remove the leftmost character from the window.
                if (answerKey[i] == 'T') 
                {
                    countT--;
                }
                else 
                {
                    countF--;
                }

                // Move the left pointer forward.
                i++;
            }

            // Current window is valid because required flips <= k.
            // Update the maximum consecutive answer length.
            ans = max(ans, j - i + 1);

            // Expand the window.
            j++;
        }

        return ans;
    }
};

/*

┌────────────────────────────────────────────────────┐
│ LEETCODE 2024 - MAXIMIZE THE CONFUSION             │
├────────────────────────────────────────────────────┤
│ Approach: Single-Pass Variable Size Sliding Window │
├────────────────────────────────────────────────────┤
│ KEY IDEA:                                          │
│ Minimum flips required = min(countT, countF)       │
│                                                    │
│ ALGORITHM:                                         │
│ 1. Expand window using right pointer (j).          │
│ 2. Update countT or countF based on current char.  │
│ 3. Calculate minimum flips using min().            │
│ 4. If flips > k, shrink window from left (i).      │
│ 5. Continue until the window becomes valid.        │
│ 6. Update ans = max(ans, j - i + 1).               │
├────────────────────────────────────────────────────┤
│ VALID CONDITION:                                   │
│ min(countT, countF) <= k                           │
│                                                    │
│ WINDOW LENGTH:                                     │
│ j - i + 1                                          │
├────────────────────────────────────────────────────┤
│ Time Complexity  : O(n)                            │
│ Space Complexity : O(1)                            │
│ Extra Space      : O(1)                            │
└────────────────────────────────────────────────────┘

*/

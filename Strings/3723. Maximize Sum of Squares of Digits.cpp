

class Solution {//  Time  : O(num)                      Space : O(num)
public:
    string maxSumOfSquares(int num, int sum) {

        // If the required digit sum exceeds the maximum possible sum,
        // no valid num-digit number can be formed.
        // Each digit can be at most 9, so maximum sum = 9 * num.
        if (sum > 9 * num) 
        {
            return "";
        }

        // Calculate how many complete 9s can fit into sum.
        int nines = sum / 9;

        // Calculate the remaining sum after using all those 9s.
        int remainder = sum % 9;

        // Create a string containing 'nines' copies of character '9'.
        // Example: nines = 2 -> ans = "99".
        string ans(nines, '9');

        // If a remainder exists, append it as a digit.
        // Example: remainder = 4 -> append '4'.
        if (remainder > 0) 
        {
            ans.push_back(remainder + '0');
        }

        // Fill the remaining positions with zeros so that
        // the final string contains exactly num digits.
        // Example: num = 5, ans = "994" -> append two zeros.
        ans.append(num - ans.length(), '0');

        // Return the constructed number as a string.
        return ans;
    }
};

/*

┌─────────────────────────────────────┐
│         MAX SUM OF SQUARES          │
├─────────────────────────────────────┤
│ nines     = sum / 9                 │
│ remainder = sum % 9                 │
│                                     │
│ 1. If sum > 9 * num → return ""     │
│ 2. Append nines copies of '9'       │
│ 3. Append remainder if > 0          │
│ 4. Fill remaining positions with '0'│
│                                     │
│ KEY IDEA:                           │
│ Use the largest digits first        │
│ to maximize the sum of squares.     │
│                                     │
│ Time  : O(num)                      │
│ Space : O(num) including output     │
│ Extra : O(1) auxiliary*             │
└─────────────────────────────────────┘

*/

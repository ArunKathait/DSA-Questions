
class Solution {// TC ---> O(N)                                  SC ---> O(1)
public:
    int minOperations(string s) {
        int n = s.length();

        // If the string is already sorted in non-decreasing order,
        // no operation is required.
        if (is_sorted(s.begin(), s.end())) 
        {
            return 0;
        }

        // If the string has length 2 and is not sorted,
        // it cannot be sorted using the allowed operations.
        if (n == 2) 
        {
            return -1;
        }

        // Find the minimum and maximum characters in the entire string.
        char min_Char = *min_element(s.begin(), s.end());
        char max_Char = *max_element(s.begin(), s.end());

        // If the first character is the minimum character,
        // or the last character is the maximum character,
        // the string can be sorted in one operation.
        if (s[0] == min_Char || s[n - 1] == max_Char) 
        {
            return 1;
        }

        // Find the minimum and maximum characters in the middle portion
        // of the string, excluding the first and last characters.
        char min_Mid = *min_element(s.begin() + 1, s.end() - 1);
        char max_Mid = *max_element(s.begin() + 1, s.end() - 1);

        // If the first character is greater than every middle character
        // and the last character is smaller than every middle character,
        // both ends are misplaced in opposite directions.
        // In this case, three operations are required.
        if (s[0] > max_Mid && s[n - 1] < min_Mid) 
        {
            return 3;
        }

        // For all other unsorted cases, two operations are sufficient.
        return 2;
    }
};

/*

┌──────────────────────────────────────┐
│ Minimum Operations                   │
├──────────────────────────────────────┤
│ Already sorted         → 0           │
│ n == 2 (unsorted)      → -1          │
│ First == min OR                      │
│ Last == max           → 1            │
│ First > maxMid AND                   │
│ Last < minMid         → 3            │
│ Otherwise             → 2            │
├──────────────────────────────────────┤
│ Time Complexity:       O(n)          │
│ Auxiliary Space:       O(1)          │
└──────────────────────────────────────┘

*/

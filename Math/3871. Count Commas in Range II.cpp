*************************************************APPROACH 1st********************************************************

class Solution {// Time  → O(log n)                             Space → O(1)
public:
    long long countCommas(long long n) {

        // Stores the total number of commas
        // required for all numbers from 1 to n.
        long long ans = 0;


        // The first number that needs a comma is 1000.
        //
        // 1 to 999     -> 0 commas
        // 1000 onward  -> at least 1 comma
        long long lower = 1000;


        // Numbers starting from 1000 initially
        // have 1 comma.
        //
        // 1000     -> "1,000"    -> 1 comma
        // 999999   -> "999,999"  -> 1 comma
        long long commas = 1;


        // Continue while the current range
        // starts within [1, n].
        while(lower <= n)
        {

            // Find the last number in the current range.
            //
            // lower = 1000
            //
            // upper = 1000 * 1000 - 1
            //       = 999999
            //
            // Therefore:
            //
            // 1000 → 999999
            // All these numbers have exactly 1 comma.
            long long upper = (lower * 1000) - 1;


            // If the calculated upper value goes beyond n,
            // we only need to count up to n.
            //
            // Example:
            //
            // n = 1005
            // calculated upper = 999999
            //
            // We don't need 1006 → 999999.
            // So:
            //
            // upper = 1005
            if(upper > n)
            {
                upper = n;
            }


            // Find how many numbers are present
            // between lower and upper.
            //
            // Formula:
            //
            // Number of elements from L to R
            // = R - L + 1
            //
            // Example:
            //
            // 1000, 1001, 1002, 1003, 1004, 1005
            //
            // count = 1005 - 1000 + 1
            //       = 6
            long long countNumbers = upper - lower + 1;


            // Every number in this range contains
            // the same number of commas.
            //
            // Therefore:
            //
            // total commas in this range
            // = number of numbers × commas per number
            //
            // Example:
            //
            // 6 numbers × 1 comma
            // = 6 commas
            ans += countNumbers * commas;


            // Move to the next comma range.
            //
            // 1000 → 1,000
            //
            // Next:
            // 1,000,000 → 1,000,000
            //
            // So multiply lower by 1000.
            lower = lower * 1000;


            // The next range has one additional comma.
            //
            // Current:
            // 1000 → 999999
            //       1 comma
            //
            // Next:
            // 1000000 → 999999999
            //           2 commas
            //
            // Therefore increase commas.
            commas++;
        }


        // Return the total number of commas
        // required for all numbers from 1 to n.
        return ans;
    }
};

************************************************APPROACH 2nd(CLEAN & BETTER)*******************************************

class Solution {//  Time Complexity: O(log n)                    Space Complexity: O(1)
public: 
    long long countCommas(long long n) { 
        
        // Stores total number of commas
        long long ans = 0; 

        // First number that contains at least one comma
        long long start = 1000; 

        while(start <= n) 
        {
            // Count all numbers from 'start' to 'n'
            //
            // Number of elements in [start, n]
            // = n - start + 1
            //
            // Each of these numbers contributes
            // one comma at the current comma position.
            ans += (n - start) + 1; 

            // Move to the next comma position
            //
            // 1000       -> counts the first comma
            // 1000000    -> counts the second comma
            // 1000000000 -> counts the third comma
            start = start * 1000; 
        } 

        return ans; 
    } 
};

/*

╔══════════════════════════════════════════════════╗
║                  COUNT COMMAS                    ║
╠══════════════════════════════════════════════════╣
║ Problem: Count total commas when writing         ║
║ all numbers from 1 → n.                          ║
╠══════════════════════════════════════════════════╣
║ KEY OBSERVATION                                  ║
║                                                  ║
║ Numbers >= 1,000                                 ║
║ → contribute at least 1 comma                    ║
║                                                  ║
║ Numbers >= 1,000,000                             ║
║ → contribute an additional comma                 ║
║                                                  ║
║ Numbers >= 1,000,000,000                         ║
║ → contribute another comma                       ║
╠══════════════════════════════════════════════════╣
║ FORMULA                                          ║
║                                                  ║
║ ans += (n - start + 1)                           ║
║                                                  ║
║ start *= 1000                                    ║
╠══════════════════════════════════════════════════╣
║ EXAMPLE: n = 1,000,005                           ║
║                                                  ║
║ start = 1,000                                    ║
║ count = 1,000,005 - 1,000 + 1                    ║
║       = 999,006                                  ║
║                                                  ║
║ start = 1,000,000                                ║
║ count = 1,000,005 - 1,000,000 + 1                ║
║       = 6                                        ║
║                                                  ║
║ Answer = 999,006 + 6 = 999,012                   ║
╠══════════════════════════════════════════════════╣
║ CODE PATTERN                                     ║
║                                                  ║
║ long long ans = 0;                               ║
║ long long start = 1000;                          ║
║                                                  ║
║ while(start <= n) {                              ║
║     ans += n - start + 1;                        ║
║     start *= 1000;                               ║
║ }                                                ║
╠══════════════════════════════════════════════════╣
║ COMPLEXITY                                       ║
║                                                  ║
║ Time  → O(log n)                                 ║
║ Space → O(1)                                     ║
╚══════════════════════════════════════════════════╝

🧠 One-line intuition

n
↓
≥ 1000       → +1 comma
≥ 1000000    → +1 more comma
≥ 1000000000 → +1 more comma

*/

**************************************************APPROACH 3rd(OPTIMAL AND EASY)**************************************

#define ll long long

class Solution {// Time  → O(log n)                                Space → O(1)
public:

    long long countCommas(long long n) {

        // 'll' is just a shortcut for 'long long'
        //
        // So:
        // ll ans = 0;
        //
        // is the same as:
        // long long ans = 0;
        //
        // 'ans' stores the total number of commas.
        ll ans = 0;


        // We start from 1000 because:
        //
        // 1 to 999
        //     -> no commas
        //
        // 1000 to ...
        //     -> at least one comma
        //
        // We multiply i by 1000 after every iteration
        // to move to the next comma position.
        //
        // i values:
        //
        // 1000
        // 1000000
        // 1000000000
        // 1000000000000
        // ...
        //
        for(ll i = 1000; i <= n; i *= 1000)
        {

            // Count how many numbers are from 'i' to 'n'.
            //
            // Number of integers in the range [i, n]:
            //
            // n - i + 1
            //
            // Example:
            //
            // n = 1005
            // i = 1000
            //
            // Numbers are:
            //
            // 1000, 1001, 1002, 1003, 1004, 1005
            //
            // Count:
            //
            // 1005 - 1000 + 1 = 6
            //
            // Every one of these numbers has at least
            // one comma.
            //
            // Therefore, add 6 to the answer.
            ans += (n - i + 1);
        }


        // Return the total number of commas.
        return ans;
    }
};

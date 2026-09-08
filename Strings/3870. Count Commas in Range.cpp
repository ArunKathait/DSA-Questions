
class Solution {
public:

    // This function calculates the number of commas
    // present in a number represented as a string.
    //
    // Example:
    // "1000"      -> 1 comma
    // "10000"     -> 1 comma
    // "1000000"   -> 2 commas
    // "1000000000"-> 3 commas
    int count(string str)
    {
        int n = str.length();

        // Every group of 3 digits (from right to left)
        // creates a comma.
        //
        // Number of commas = (number of digits - 1) / 3
        //
        // Examples:
        // n = 4  -> (4 - 1) / 3 = 1
        // n = 5  -> (5 - 1) / 3 = 1
        // n = 6  -> (6 - 1) / 3 = 1
        // n = 7  -> (7 - 1) / 3 = 2
        //
        // Integer division automatically removes the decimal part.
        int count = (n - 1) / 3;

        return count;
    }


    int countCommas(int n)
    {
        // Stores the total number of commas
        // found in all numbers from 1000 to n.
        int ans = 0;

        // Start from 1000 because 1000 is the
        // smallest number that contains a comma.
        //
        // 999 -> no comma
        // 1000 -> 1 comma
        for(int i = 1000; i <= n; i++)
        {
            // Convert the current number into a string.
            //
            // Example:
            // i = 1000 -> "1000"
            // i = 10000 -> "10000"
            string str = to_string(i);

            // Count the number of commas in the current number
            // and add it to the total.
            ans += count(str);
        }

        // Return the total number of commas
        // in all numbers from 1000 to n.
        return ans;
    }
};

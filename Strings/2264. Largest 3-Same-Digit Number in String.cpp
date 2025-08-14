
class Solution {// TC--->O(N)                         SC--->O(1)
public:
    string largestGoodInteger(string num) {

        // Get the length of the given string
        int n = num.size();

        // If the string length is less than or equal to 2,
        // it can't have a substring of length 3, so return empty string
        if(n <= 2)
        {
            return "";
        }

        // This will store the largest digit that forms a triple (e.g., "777")
        // Initialize with -1 to indicate no triple found yet
        int maxDigit = -1;

        // Start checking from index 2 (because we check current and previous two chars)
        for(int i = 2; i < n; i++)
        {
            // Check if three consecutive characters are the same
            if(num[i] == num[i-1] && num[i] == num[i-2])
            {
                // Convert the char digit to int (subtract '0')
                // and update maxDigit if this digit is larger
                maxDigit = max(maxDigit, num[i] - '0');
            }
        }

        // If maxDigit is still -1, it means no triple found → return empty string
        if(maxDigit == -1)
        {
            return "";
        }

        // Create a string of length 3, all characters being the found maxDigit
        // Example: if maxDigit = 7 → string(3, '7') → "777"
        string ans = string(3, maxDigit + '0');

        // Return the result
        return ans;
    }
};

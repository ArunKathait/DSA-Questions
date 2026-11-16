
class Solution {
public:
    // Function to calculate the sum of digits in a substring.
    int getSum(string &current)
    {
        int sum = 0;

        // Traverse each character of the current substring.
        for(auto &num : current)
        {
            // Convert character digit into integer and add it to sum.
            sum += (num - '0');
        }

        return sum;
    }

    string digitSum(string s, int k) {
        int n = s.length();

        // Repeat the process until the string length becomes <= k.
        while(s.length() > k)
        {
            string str = "";  // Stores the transformed string.

            // Divide the string into groups of k characters.
            for(int i = 0; i < s.length(); i += k)
            {
                // Extract k characters starting from index i.
                // If fewer than k characters remain, substr() returns
                // all the remaining characters.
                string current = s.substr(i, k);

                // Calculate the sum of digits in the current group
                // and convert the integer result back into a string.
                str += to_string(getSum(current));
            }

            // Update the original string with the transformed string.
            // The next iteration operates on this new string.
            s = str;
        }

        // Return the final string when its length is <= k.
        return s;
    }
};

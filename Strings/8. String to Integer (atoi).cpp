
class Solution {// TC ---> O(N)                                SC ---> O(1)
public:
    int myAtoi(string s) {

        // Get the length of the input string
        int n = s.length();

        // Pointer to traverse the string
        int i = 0;

        // Step 1: Ignore all leading white spaces
        // Example: "    -42" -> i will stop at '-'
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // Step 2: Assume the number is positive by default
        int sign = +1;

        // Step 3: Check if the current character is '+' or '-'
        // A valid integer can have at most one optional sign.
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            // If the sign is '-', make the number negative
            if (s[i] == '-')
            {
                sign = -1;
            }

            // Move to the first digit
            i++;
        }

        // Step 4: Variable to store the number being formed.
        // Using long helps detect overflow before converting to int.
        long ans = 0;

        // Step 5: Read characters until a non-digit is found
        while (i < n && isdigit(s[i]))
        {
            // Convert the current character into a digit
            // Example:
            // '5' - '0' = 5
            ans = ans * 10 + (s[i] - '0');

            // Step 6: Check for positive overflow
            if (sign == 1 && ans > INT_MAX)
            {
                return INT_MAX;
            }

            // Step 7: Check for negative overflow
            // Example:
            // ans = 2147483649
            // -ans = -2147483649 < INT_MIN
            if (sign == -1 && -ans < INT_MIN)
            {
                return INT_MIN;
            }

            // Move to the next character
            i++;
        }

        // Step 8: Return the number with its sign
        return sign * ans;
    }
};

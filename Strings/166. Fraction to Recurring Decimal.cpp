
class Solution {// TC: O(n) average*                                SC: O(n) 
public:
    string fractionToDecimal(int numerator, int denominator) {

        // Special case:
        // If numerator is 0, the answer is simply "0"
        if(numerator == 0)
        {
            return "0";
        }

        // This string will store the final decimal answer
        string ans;

        // Check whether the result should be negative.
        // If numerator and denominator have opposite signs,
        // their product will be negative.
        //
        // Cast to long long first to avoid integer overflow.
        if((long long)numerator * (long long)denominator < 0)
        {
            ans += "-";
        }

        // Convert numerator and denominator to positive values.
        //
        // labs() returns the absolute value of a long long.
        long long absNumerator = labs(numerator);
        long long absDenominator = labs(denominator);

        // Calculate the integer part.
        //
        // Example:
        // 7 / 2 = 3
        //
        // quotient = 3
        long long quotient = absNumerator / absDenominator;

        // Add the integer part to the answer
        ans += to_string(quotient);

        // Calculate the remaining part.
        //
        // Example:
        // 7 / 2
        // quotient = 3
        // remainder = 1
        long long remainder = absNumerator % absDenominator;

        // If remainder is 0, the division is completely finished.
        //
        // Example:
        // 6 / 2 = 3
        //
        // So return "3"
        if(remainder == 0)
        {
            return ans;
        }

        // Since there is a fractional part,
        // add the decimal point.
        ans += ".";

        // Store:
        // remainder -> position in the answer
        //
        // This helps us detect a repeating decimal.
        unordered_map<int, int> ump;

        // Continue until there is no remainder.
        while(remainder != 0)
        {
            // If this remainder has already appeared,
            // the same sequence of decimal digits will repeat.
            if(ump.find(remainder) != ump.end())
            {
                // Insert '(' at the position where
                // this remainder was first seen.
                ans.insert(ump[remainder], "(");

                // The repeating part ends at the current position.
                ans += ")";

                break;
            }

            // Store the current remainder and the current
            // position in the answer.
            //
            // Example:
            // remainder = 1
            // ans = "3."
            //
            // Store:
            // ump[1] = 2
            ump[remainder] = ans.length();

            // Multiply remainder by 10 to generate
            // the next decimal digit.
            //
            // Example:
            // 1 * 10 = 10
            remainder *= 10;

            // The integer part of remainder / denominator
            // gives the next decimal digit.
            //
            // Example:
            // 10 / 2 = 5
            // digit = 5
            int digit = remainder / absDenominator;

            // Add this digit to the answer
            ans += to_string(digit);

            // Keep the remaining part for the next iteration.
            //
            // Example:
            // 10 % 2 = 0
            // Division is finished.
            remainder = remainder % absDenominator;
        }

        // Return the final decimal representation
        return ans;
    }
};

/*

┌─────────────────────────────────────┐
│        FRACTION TO DECIMAL          │
├─────────────────────────────────────┤
│ 1. Handle numerator = 0             │
│ 2. Check negative sign              │
│ 3. quotient = num / den             │
│ 4. remainder = num % den            │
│                                     │
│ If remainder != 0:                  │
│ → add "."                           │
│ → store remainder → position        │
│ → remainder *= 10                   │
│ → digit = remainder / denominator   │
│ → remainder %= denominator          │
│                                     │
│ Same remainder again?               │
│ → digits will repeat                │
│ → insert "(" at first position      │
│ → add ")" at the end                │
│                                     │
│ KEY:                                │
│ Same remainder = same future digits │
│                                     │
│ TC: O(n) average                    │
│ SC: O(n)                            │
└─────────────────────────────────────┘

*/

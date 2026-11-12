
class Solution {// TIME COMPLEXITY:  O(n)                             SPACE COMPLEXITY: O(n)
public:
    int calculate(string s) {
        int n = s.length();

        // Stack stores the previous result and sign
        // whenever we encounter an opening bracket '{'.
        stack<int> st;

        // number: Builds the current number (handles multiple digits).
        // sign: Stores the sign (+1 or -1) of the current number.
        // result: Stores the calculated result of the current expression.
        long long number = 0;
        long long sign = 1;
        long long result = 0;

        for(auto &ch : s)
        {
            // CASE 1: If the character is a digit,
            // construct the complete number.
            // Example: '1', '2', '3' -> 123.
            if(isdigit(ch))
            {
                number = number * 10 + (ch - '0');
            }

            // CASE 2: If '+' is encountered,
            // add the previously constructed number with its sign.
            else if(ch == '+')
            {
                result += (sign * number);

                // Reset number for the next operand.
                number = 0;

                // Next number will have a positive sign.
                sign = 1;
            }

            // CASE 3: If '-' is encountered,
            // add the previous number with its current sign.
            else if(ch == '-')
            {
                result += (sign * number);

                // Reset number for the next operand.
                number = 0;

                // Next number will have a negative sign.
                sign = -1;
            }

            // CASE 4: Opening bracket '{'.
            // Save the current expression's result and sign
            // because we need to evaluate the inner expression separately.
            else if(ch == '(')
            {
                // Save the result calculated before the bracket.
                st.push(result);

                // Save the sign associated with the bracket.
                st.push(sign);

                // Start evaluating the inner expression from scratch.
                number = 0;
                result = 0;
                sign = 1;
            }

            // CASE 5: Closing bracket '}'.
            // First calculate the remaining number inside the bracket.
            else if(ch == ')')
            {
                result += (sign * number);

                // Retrieve the sign saved before the opening bracket.
                int stackSign = st.top();
                st.pop();

                // Retrieve the previous expression's result.
                int lastResult = st.top();
                st.pop();

                // Apply the saved sign to the inner expression.
                result *= stackSign;

                // Add the result calculated before the opening bracket.
                result += lastResult;

                // Reset variables for further calculations.
                number = 0;
            }
        }

        // Add the last number because the expression
        // might end without encountering an operator or closing bracket.
        result += (sign * number);

        // Return the final evaluated expression.
        return result;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│             BASIC CALCULATOR (LC 224)                │
├──────────────────────────────────────────────────────┤
│ APPROACH: Stack + Expression Evaluation              │
│                                                      │
│ KEY IDEA:                                            │
│ • Use number to construct multi-digit numbers.       │
│ • Use sign (+1 / -1) to track the current sign.      │
│ • On '+' or '-', add the previous signed number.     │
│ • On '(', push the previous result and sign.         │
│ • Evaluate the inner expression independently.       │
│ • On ')', multiply the inner result by the saved     │
│   sign and add the previous result.                  │
│ • Use long long to avoid intermediate overflow.      │
│                                                      │
│ TIME COMPLEXITY:  O(n)                               │
│ SPACE COMPLEXITY: O(n)                               │
│ TOTAL SPACE:      O(n) (Stack)                       │
└──────────────────────────────────────────────────────┘

*/

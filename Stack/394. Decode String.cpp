
class Solution {// TC ---> O(N)                               SC ---> O(N)
public:
    string decodeString(string s) {

        // Stack to store strings formed before encountering '['
        stack<string> stringStack;

        // Stack to store numbers (k values) before '['
        stack<int> numStack;

        // This will store the currently forming decoded string
        string currentString = "";

        // This will store the number (k) before '['
        int currentNum = 0;

        // Traverse each character in the string
        for (char x : s) 
        {
            // Case 1: Opening bracket '['
            if (x == '[') 
            {
                // Save the string formed so far
                stringStack.push(currentString);

                // Save the number formed so far
                numStack.push(currentNum);

                // Reset for decoding the substring inside brackets
                currentString = "";
                currentNum = 0;
            }
            // Case 2: Closing bracket ']'
            else if (x == ']') 
            {
                // Get how many times the substring should repeat
                int times = numStack.top();
                numStack.pop();

                // Get the string that was before this bracket
                string prevString = stringStack.top();
                stringStack.pop();

                // Append currentString 'times' times to prevString
                while (times--) 
                {
                    prevString += currentString;
                }

                // Update currentString with the expanded result
                currentString = prevString;
            }

            // Case 3: Digit (build the repeat number)
            else if (isdigit(x)) 
            {
                // Handle multi-digit numbers (e.g., 12[a])
                currentNum = currentNum * 10 + (x - '0');
            }

            // Case 4: Normal alphabet character
            else 
            {
                // Add character to the current string
                currentString += x;
            }
        }

        // Final decoded string
        return currentString;
    }
};

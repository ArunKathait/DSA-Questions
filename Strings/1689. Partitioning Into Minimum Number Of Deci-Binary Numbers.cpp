******************************************************************APPROACH 1st**********************************************************************

class Solution {// TC ---> O(n * D) ≈ O(n)                                 SC ---> O(1)
public:
    int minPartitions(string n) {

        // This will count how many deci-binary numbers are needed
        int count = 0;

        // Infinite loop (we will manually break it)
        while(true)
        {
            // This flag checks whether we reduced any digit in this iteration
            bool changed = false;

            // Traverse each digit of the string
            for(auto &ch : n)
            {
                // If digit is not zero
                if(ch != '0')
                {
                    // Reduce digit by 1
                    // Example: '5' becomes '4'
                    ch--;

                    // Mark that we changed something
                    changed = true;
                }
            }

            // If no digit was reduced,
            // that means all digits are '0'
            // So stop the loop
            if(!changed)
            {
                break;
            }

            // One full subtraction round completed
            // That represents one deci-binary number used
            count++;
        }

        // Return minimum number of deci-binary numbers required
        return count;
    }
};

/*   

🧠 What Is This Code Actually Doing?

It repeatedly:

👉 Subtracts 1 from every non-zero digit
👉 Counts how many times this happens
👉 Stops when number becomes "000...0"

*/

***************************************************************APPROACH 2nd************************************************************************

class Solution {
public:
    int minPartitions(string n) {
        
        // max_element finds the largest character in the string.
        // Since digits are stored as characters ('0' to '9'),
        // it returns the character with highest ASCII value.
        
        // Example:
        // n = "273462"
        // max_element returns '7'
        
        // We subtract '0' to convert the character digit to integer.
        // '7' - '0' = 7
        
        // The maximum digit is the answer because:
        // Each deci-binary number can contribute at most 1
        // to each digit position.
        // So the largest digit determines how many layers are needed.
        
        return *max_element(n.begin(), n.end()) - '0';
    }
};

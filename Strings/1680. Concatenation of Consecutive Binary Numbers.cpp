*****************************************************APPROACH 1st*****************************************************

class Solution {// TC ---> O(N)                                    SC ---> O(1)
public:
    // Mod value to prevent overflow
    int M = 1e9 + 7;

    int concatenatedBinary(int n) {

        // We use long because value grows very large
        long ans = 0;

        // Loop from 1 to n
        for(int num = 1; num <= n; num++)
        {
            /*
             digits = number of bits required to represent num in binary

             Example:
             num = 1  -> binary = 1      -> digits = 1
             num = 2  -> binary = 10     -> digits = 2
             num = 3  -> binary = 11     -> digits = 2
             num = 4  -> binary = 100    -> digits = 3

             log2(num) gives highest power of 2
             So digits = floor(log2(num)) + 1
            */
            int digits = log2(num) + 1;

            /*
             Left shift ans by 'digits' places.

             Why?
             Because we want to append current number
             to the right side of previous binary result.

             Example:
             ans = 110  (6 in decimal)
             num = 5 (binary = 101, digits = 3)

             ans << 3
             110 becomes 110000

             Then we add num:
             110000 + 101 = 110101
            */
            ans = ( (ans << digits) % M + num ) % M;
        }

        return ans;
    }
};

**************************************************APPROACH 2nd*********************************************************

class Solution {// TC ---> O(N)                                  SC ---> O(1)
public:
    // Mod value to prevent overflow
    int M = 1e9 + 7;

    int concatenatedBinary(int n) {

        // Stores final concatenated result
        long ans = 0;

        // This will store how many binary digits current number has
        int digits = 0;

        // Loop from 1 to n
        for(int num = 1; num <= n; num++)
        {
            /*
            Check if current number is a power of 2

            Condition:
            (num & (num - 1)) == 0

            Why?
            Power of 2 numbers in binary:
            1  -> 1
            2  -> 10
            4  -> 100
            8  -> 1000

            These numbers have exactly ONE set bit.

            Example:
            8      = 1000
            8 - 1  = 0111
            AND -> 0000

            So whenever num becomes power of 2,
            number of binary digits increases by 1.
            */
            if((num & (num - 1)) == 0)
            {
                digits++;
            }

            /*
            Shift ans left by 'digits' bits
            to make space for current number.

            Example:
            Suppose ans = 110 (6)
            num = 5 (101)

            digits = 3
            ans << 3 = 110000

            Then add num:
            110000 + 101 = 110101
            */

            ans = ((ans << digits) % M + num) % M;
        }

        return ans;
    }
};

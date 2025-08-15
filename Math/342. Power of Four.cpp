******************************************APPROACH 1st(USING RECURSION)*********************************************

class Solution {// TC--->O(log₄(n))                     SC--->O(log₄(n))
public:
    bool isPowerOfFour(int n) {
        
        // Step 1: Handle negative numbers and zero
        // A power of four must be positive, so if n <= 0, return false immediately
        if(n <= 0)
        {
            return false;
        }
        
        // Step 2: Base case
        // If n is 1, return true because 4^0 = 1, which is a valid power of four
        if(n == 1)
        {
            return true;
        }

        // Step 3: Check divisibility by 4
        // If remainder is 1, 2, or 3, that means n is not perfectly divisible by 4
        // and thus it can't be a power of four.
        if(n % 4 == 1)
        {
            return false;
        }

        if(n % 4 == 2)
        {
            return false;
        }

        if(n % 4 == 3)
        {
            return false;
        }

        // Step 4: Recursive step
        // If divisible by 4, divide n by 4 and check again
        // This keeps reducing the number until it becomes 1 (true) or fails divisibility (false)
        return isPowerOfFour(n / 4);
    }
};

*******************************************APPROACH 2nd(USING ITERATIVE)***********************************************

class Solution {// TC--->O(log₄(n))                 SC--->O(1)
public:
    bool isPowerOfFour(int n) {
        // Negative numbers and zero are not powers of four
        if (n <= 0) return false;

        // Keep dividing n by 4 while it is divisible by 4
        while (n % 4 == 0) 
        {
            n /= 4;
        }

        // If we end up at 1, it means it was a power of four
        return n == 1;
    }
};

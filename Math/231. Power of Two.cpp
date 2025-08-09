
class Solution {// TC--->O(logN)                              SC--->O(logN)
public:
    bool isPowerOfTwo(int n) {
        // Powers of two are always positive integers (1, 2, 4, 8, ...)
        // If n is less than 1 (0 or negative), it cannot be a power of two
        if (n < 1)
        {
            return false;
        }

        // Base case: 1 is 2^0, so it's a valid power of two
        if (n == 1)
        {
            return true;
        }

        // If n is odd (n % 2 == 1), it cannot be a power of two
        // because all powers of two > 1 are even
        if (n % 2 == 1)
        {
            return false;
        }

        // Recursive step: divide n by 2 and check again
        // If n is a power of two, this process will eventually reach 1
        return isPowerOfTwo(n / 2);
    }
};


class Solution {// TC--->O(log₃(n))                 SC--->O(log₃(n))
public:
    bool isPowerOfThree(int n) {
        // If n is less than or equal to 0, it cannot be a power of 3
        if(n <= 0)
        {
            return false;
        }
        
        // Base case: 3^0 = 1
        // If n becomes 1, it means we kept dividing by 3 successfully until we reached 1
        if(n == 1)
        {
            return true;
        }

        // If remainder is 1 when divided by 3, it means n is not perfectly divisible by 3
        // Example: n = 10 → 10 % 3 = 1 → Not a power of 3
        if(n % 3 == 1)
        {
            return false;
        }

        // If remainder is 2 when divided by 3, also means it's not a perfect multiple of 3
        // Example: n = 8 → 8 % 3 = 2 → Not a power of 3
        if(n % 3 == 2)
        {
            return false;
        }

        // Recursive call: divide n by 3 and check again
        // This keeps breaking n down until it becomes 1 (power of 3) or fails divisibility
        return isPowerOfThree(n / 3);
    }
};

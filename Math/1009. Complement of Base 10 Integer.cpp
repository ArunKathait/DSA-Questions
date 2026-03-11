
class Solution {
public:
    int bitwiseComplement(int n) {

        // Edge case:
        // If n = 0, its binary is "0"
        // Complement becomes "1"
        if(n == 0) return 1;

        int ans = 0;      // This will store the final complement number
        int power = 1;    // Represents 2^position (1,2,4,8,...)

        // Process each bit of n
        while(n)
        {
            // Step 1: Extract the last bit of n
            // Example: n = 5 (101)
            // First iteration → bit = 1
            int bit = n & 1;

            // Step 2: Flip the bit
            // 1 -> 0
            // 0 -> 1
            int flip = bit ^ 1;

            // Step 3: Add flipped bit to the answer
            // Multiply by power to place it at correct binary position
            ans += flip * power;

            // Step 4: Move power to next binary position
            // (1 -> 2 -> 4 -> 8 ...)
            power <<= 1;

            // Step 5: Shift n to process the next bit
            // Removes the last bit
            n >>= 1;
        }

        // Return the final complement number
        return ans;
    }
};

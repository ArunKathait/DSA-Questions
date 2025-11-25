
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        // If k is 1, the smallest repunit ("1") is already divisible by 1.
        if(k == 1)
        {
            return 1;
        }

        // 'num' will store the remainder of the repunit number when divided by k.
        // We never build the full number because it can be extremely large.
        int num = 0;

        // A repunit divisible by k will have at most 'k' digits.
        // If no such repunit exists within k iterations, answer is -1.
        for(int length = 1; length <= k; length++)
        {
            // Update the remainder:
            // Example: If current remainder is R,
            // new number is (R * 10 + 1), so update remainder using mod k.
            num = (num * 10 + 1) % k;

            // If remainder becomes 0, then the repunit of length 'length'
            // is divisible by k.
            if(num == 0)
            {
                return length;
            }
        }

        // If loop ends, no repunit number divisible by k exists.
        return -1;
    }
};

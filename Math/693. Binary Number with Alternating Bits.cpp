
class Solution {// TC ---> O(number of bits) → O(log n)                   SC ---> O(1)
public:
    bool hasAlternatingBits(int n) {
        // Get the last (rightmost) bit of n
        // Example: n = 101 (5), n & 1 = 1
        int previous = n & 1;

        // Right shift n to move to the next bit
        n = n >> 1;

        // Loop until all bits are checked
        while(n)
        {
            // Get the current last bit
            int current = n & 1;

            // If two adjacent bits are the same,
            // then bits are NOT alternating
            // Example: ...11 or ...00
            if(current == previous)
            {
                return false;
            }

            // Update previous bit for next comparison
            previous = current;

            // Move to the next bit
            n = n >> 1;
        }

        // If all adjacent bits were different,
        // then the number has alternating bits
        return true;
    }
};

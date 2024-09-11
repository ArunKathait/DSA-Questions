************************************************APPROACH 1st*************************************************************

class Solution {// TC--->O(1)                        SC--->O(1)
public:
    int minBitFlips(int start, int goal) {
        // XOR operation will give a number where the bits are set (1)
        // only where 'start' and 'goal' have different bits.
        // For example: 
        // start = 5 (in binary: 101)
        // goal  = 7 (in binary: 111)
        // XOR   = 2 (in binary: 010)
        int XOR = start^goal;
        
        // __builtin_popcount(XOR) is a GCC built-in function that counts the number
        // of 1's (set bits) in the binary representation of XOR.
        // This will give the number of differing bits between 'start' and 'goal',
        // which is the number of bit flips required to convert 'start' to 'goal'.
        return __builtin_popcount(XOR);
        
    }
};

*************************************************APPROACH 2nd************************************************************

class Solution {// TC--->O(N)                  SC--->O(1)
public:
    int minBitFlips(int start, int goal) {
        // XOR operation will give a number where the bits are set (1)
        // only where 'start' and 'goal' have different bits.
        // Example: 
        // start = 5 (in binary: 101)
        // goal  = 7 (in binary: 111)
        // XOR   = 2 (in binary: 010)
        int XOR = start^goal;
        
        // Initialize a counter to keep track of the number of set bits (1's)
        // in the XOR result.
        int count = 0;
        
        // Loop until all bits in XOR are processed (when XOR becomes 0)
        while(XOR)
        {
            // Check if the least significant bit (rightmost bit) is 1
            // If it is, it means 'start' and 'goal' had different bits in this position,
            // so we need to flip it, and thus we increase the count.
            count += (XOR & 1);// This checks if the last bit of XOR is 1.
            
            // Right shift XOR by 1 bit to process the next bit in the next iteration.
            // This essentially moves the next bit to the rightmost position for evaluation.
            XOR = (XOR >> 1);
        }
        
         // Return the total number of differing bits, which equals the number of flips required.
        return count;
    }
};

*****************************************************APPROACh 3rd*******************************************************

class Solution {// TC--->O(N)                           SC--->O(1)
public:
    int minBitFlips(int start, int goal) {
        // XOR operation will give a number where the bits are set (1)
        // only where 'start' and 'goal' have different bits.
        // Example: 
        // start = 5 (in binary: 101)
        // goal  = 7 (in binary: 111)
        // XOR   = 2 (in binary: 010)
        int XOR = start^goal;
        
        // Initialize a counter to keep track of the number of set bits (1's)
        // in the XOR result.
        int count = 0;
        
        // Loop until XOR becomes 0 (i.e., all bits have been processed)
        while(XOR)
        {
            // XOR & (XOR - 1) is a trick to remove the rightmost set bit (1) from XOR.
            // Example: 
            // If XOR = 6 (binary: 110), XOR - 1 = 5 (binary: 101).
            // XOR & (XOR - 1) = 110 & 101 = 100, effectively removing the rightmost 1.
            XOR = XOR & (XOR-1);
            
            // Increment the count to reflect the removal of one set bit (1).
            count++;
        }
        
        // Return the total number of set bits, which is the number of bit flips needed.
        return count;
    }
};

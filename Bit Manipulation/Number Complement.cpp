**************************************************APPROACH 1st*********************************************************

class Solution {// TC--->O(log2(num))                   SC--->O(1)
public:
    int findComplement(int num) {
        // Calculate the number of bits in the binary representation of 'num'
        // log2(num) gives the position of the highest set bit (0-indexed),
        // so add 1 to get the total number of bits.
        int numberOfBits = (int)(log2(num)) + 1;
        
        // Loop over each bit position from 0 to (numberOfBits - 1)
        for(int i=0;i<numberOfBits;i++)
        {
            // XOR 'num' with a number that has only the ith bit set to 1.
            // This operation flips the ith bit of 'num'.
            num = num^(1<<i);
        }
        
        // Return the modified number which is the complement of the original 'num'
        return num;
    }
};


****************************************************APPROACH 2nd*****************************************************

class Solution {// TC--->O(log2(num))                  SC--->O(1)
public:
    int findComplement(int num) {
        
        // Special case: if the number is 0, return 1 as its complement (since 0 in binary is all 0s).
        if(num == 0)
        {
            return 1;
        }
        
        // Calculate the number of bits in the binary representation of 'num'
        // log2(num) gives the position of the highest set bit (0-indexed),
        // so add 1 to get the total number of bits.
        int numberOfBits = (int)(log2(num)) + 1;
        
        // Create a mask with all bits set to 1, which is the same length as the binary representation of 'num'
        // (1U << numberOfBits) shifts 1 left by 'numberOfBits' places, resulting in a number with a single 1
        // followed by 'numberOfBits' 0s. Subtracting 1 from this value gives a mask with all bits set to 1.
        unsigned int mask = (1U << numberOfBits) - 1;
        
        // XOR 'num' with the mask to flip all bits in the binary representation of 'num'
        // and return the result.
        return num ^ mask;
    }
};


************************************************APPROACH 3rd********************************************************

class Solution {// TC--->O(log2(num))               SC--->O(1)
public:
    int findComplement(int num) {
         // Initialize 'i' for bit position and 'ans' to store the complement result
        int i = 0,ans = 0;
        
        // Continue the loop until 'num' becomes 0
        while(num)
        {
            // Check if the current bit of 'num' is 0
            if(!(num & 1))
            {
                // If the current bit is 0, set the corresponding bit in 'ans' to 1
                ans |= (1 << i);
            }
            
            // Right shift 'num' by 1 to process the next bit in the next iteration
            num >>= 1;
            
            // Move to the next bit position
            i++;
        }
        
        // Return the computed complement
        return ans;
    }
};

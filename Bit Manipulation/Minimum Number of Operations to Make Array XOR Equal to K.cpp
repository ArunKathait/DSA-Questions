********************************************************APPROACH 1st****************************************************************

class Solution {// TC--->O(N + log(diff))           SC--->O(1)
public:
    int minOperations(vector<int>& nums, int k) {
        
        // Initializing a variable to store the XOR of all elements in the nums array.
        int totalXor = 0;
        
        // Calculating the XOR of all elements in nums.
        for(auto x:nums)
        {
            totalXor = totalXor^x;
        }
        
        // Calculating the XOR of totalXor and k to find the difference.
        int diff = totalXor^k;
        
        // Initializing a variable to count the number of set bits in the difference.
        int countSetBit = 0;
        
        // Loop to count the number of set bits in the difference.
        while(diff)
        {
            // Incrementing the count of set bits.
            countSetBit++;
            
            // Clearing the least significant set bit.
            diff = diff & (diff - 1);
        }
        
        // Returning the count of set bits, which represents the minimum number of operations required.
        return countSetBit;
    }
};


******************************************************APPROACH 2nd****************************************************************************

class Solution {// TC--->O(N + log(diff))         SC--->O(1)
public:
    int minOperations(vector<int>& nums, int k) {
        
        // Initializing a variable to store the XOR of all elements in the nums array.
        int totalXor = 0;
        
        // Calculating the XOR of all elements in nums.
        for(auto x:nums)
        {
            totalXor = totalXor^x;
        }
        
        // Calculating the XOR of totalXor and k to find the difference.
        int diff = totalXor^k;
        
        // Using the built-in function __builtin_popcount() to count the number of set bits in diff.
        return __builtin_popcount(diff);
    }
};

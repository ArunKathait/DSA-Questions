
class Solution { // TC ---> O(N)                           SC ---> O(1)
public: 
    int longestSubsequence(vector<int>& nums) { 
        int n = nums.size(); 

        // Assume initially that every element is 0.
        // We will change this to false if we find any non-zero element.
        bool allZeros = true; 

        // XOR of all elements in the array.
        int totalXor = 0; 

        for(int num : nums) 
        { 
            // Calculate XOR of the entire array.
            totalXor ^= num; 

            // If we find even one non-zero element,
            // then the array is NOT made entirely of zeros.
            if(num != 0) 
            { 
                allZeros = false; 
            } 
        } 

        // If every element is 0, then XOR of any subsequence
        // will always be 0.
        //
        // Example:
        // [0, 0, 0]
        // 0 ^ 0 ^ 0 = 0
        //
        // Therefore, no valid subsequence exists.
        if(allZeros) 
        { 
            return 0; 
        } 

        // If totalXor is 0:
        //
        // The entire array is NOT valid because its XOR is 0.
        //
        // But because we know there is at least one non-zero
        // element, we can remove one non-zero element.
        //
        // Suppose:
        // nums = [1, 2, 3]
        //
        // Total XOR:
        // 1 ^ 2 ^ 3 = 0
        //
        // Remove 1:
        // 2 ^ 3 = 1
        //
        // So we get a valid subsequence of length n - 1.
        //
        // If totalXor is already non-zero:
        // The entire array is itself a valid subsequence,
        // so the maximum length is n.
        return totalXor == 0 ? n - 1 : n; 
    } 
};

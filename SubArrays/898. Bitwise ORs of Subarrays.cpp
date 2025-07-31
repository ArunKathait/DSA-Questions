*********************************************APPROACH 1st(BRUTE FORCE)********************************************

class Solution {// TC--->O(N^2)                              SC--->O(K)
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        // Get the size of the input array
        int n = arr.size();  
        
        // This set will store all unique OR results
        unordered_set<int> set;  
        
        // Loop through all possible starting indices of subarrays
        for (int i = 0; i < n; i++) 
        {
            // Initialize OR value for the current subarray
            int Or = 0;  
            
            // Loop through all possible ending indices starting from i
            for (int j = i; j < n; j++) 
            {
                // Perform OR operation with the current element
                // Insert the OR result into the set
                // Set ensures only unique values are stored
                Or |= arr[j];        
                set.insert(Or);      
                                     
            }
        }
        
        // Return the total number of unique bitwise OR results
        return set.size();
    }
};

*********************************************APPROACH 2nd(BETTER APPROACH)*************************************

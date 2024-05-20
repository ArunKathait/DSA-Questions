*******************************************APPROACH 1st************************************************************

class Solution {// TC--->O(N*2^N)             SC--->O(N*2^N)
public:
    // Recursive function to generate all subsets
    void solve(int index,vector<int>&nums,vector<int>&currentSubset,vector<vector<int>>&subsets)
    {
        // Base case: if we've considered all elements
        if(index == nums.size())
        {
            // Add the current subset to the list of subsets
            subsets.push_back(currentSubset);
            return ;
        }
        
        // Include the current element in the subset
        currentSubset.push_back(nums[index]);
        
        // Recur for the next element
        solve(index+1,nums,currentSubset,subsets);
        
        // Backtrack by removing the current element
        currentSubset.pop_back();
        
        // Exclude the current element from the subset
        // Recur for the next element
        solve(index+1,nums,currentSubset,subsets);
    }
    
    // Function to calculate the sum of XOR of all subsets
    int subsetXORSum(vector<int>& nums) {
        
        // To store all subsets
        vector<vector<int>>subsets;
        
        // To store the current subset
        vector<int>currentSubset;
        
        // Generate all subsets
        solve(0,nums,currentSubset,subsets);
        
        // To store the final XOR sum of all subsets
        int xorAll = 0;
        
        // Iterate over all subsets
        for(auto subset:subsets)
        {
            // To store the XOR of the current subset
            int Xor = 0;
            
            // Compute XOR for the current subset
            for(auto num:subset)
            {
                // XOR all elements in the subset
                Xor ^= num;
            }
            
            // Add the current subset's XOR to the total XOR sum
            xorAll += Xor;
        }
        
        // Return the final XOR sum of all subsets
        return xorAll;
    }
};


**********************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(2^N)             SC--->O(N)
public:
    // Recursive function to calculate the sum of XORs of all subsets
    int solve(int index,int Xor,vector<int>&nums)
    {
        // Base case: if we've considered all elements
        if(index == nums.size())
        {
            // Return the XOR value for the current subset
            return Xor;
        }
        
        // Include the current element in the XOR
        int include = solve(index+1,Xor^nums[index],nums);
        
        // Exclude the current element from the XOR
        int exclude = solve(index+1,Xor,nums);
        
        
        // Return the sum of XOR values from both inclusion and exclusion
        return include + exclude;
    }
    
    // Function to initiate the recursive calculation
    int subsetXORSum(vector<int>& nums) {
        
        // Initial XOR value is 0
        int Xor = 0;
        
        // Start the recursive process from index 0
        return solve(0,Xor,nums);
    }
};


*************************************************APPROACH 3rd(BETTTER APPROACH)*****************************************

class Solution {// TC--->O(N)               SC--->O(1)
public:
    // Function to calculate the sum of XORs of all subsets
    int subsetXORSum(vector<int>& nums) {
        
        // Get the size of the nums array
        int n = nums.size();
        
        // Initialize Xor to 0
        int Xor = 0;
        
        // Calculate the bitwise OR of all elements in nums
        for(auto x:nums)
        {
            // Bitwise OR accumulates all bits that are set in any element of nums
            Xor |= x;
        }
    
        // Each subset is formed by selecting or not selecting each element
        // There are 2^(n-1) subsets for each possible combination of XORed elements
        // Multiply Xor by 2^(n-1) using a left shift
        return Xor << (n-1);
    }
};

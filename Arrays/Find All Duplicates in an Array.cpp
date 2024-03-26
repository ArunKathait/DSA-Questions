class Solution {// TC--->O(N)        SC--->O(1)
public:
    vector<int> findDuplicates(vector<int>& nums) {
       // Vector to store duplicate elements
        vector<int>ans;
        
        // Size of the input array
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            // Take the absolute value of the current element
            int num = abs(nums[i]);
            
            // Calculate the index (0-based) corresponding to the value of the current element
            int index = num - 1;
            
            // If the element at the calculated index is negative
            if(nums[index] < 0)
            {
                // This means we have encountered this value before, so add it to the result vector
                ans.push_back(num);
            }
            // If the element at the calculated index is positive
            else
            {
                // Mark it as visited by negating it
                nums[index] = nums[index]*-1;
            }
        }
        
        // Return the vector containing duplicate elements
        return ans;
    }
};

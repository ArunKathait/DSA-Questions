*********************************APPROACH 2nd(USING SORTING + 2 POINTERS)***********************************

class Solution {// TC--->O(NlogN)             SC--->O(1)
public:
    int findMaxK(vector<int>& nums) {
        
        // Sort the input vector in non-decreasing order
        sort(nums.begin(),nums.end());
        
        // Initialize the answer variable to -1
        int ans = -1;
        
        // Initialize two pointers, i and j, pointing to the start and end of the sorted vector respectively
        int i = 0;
        int j = nums.size() - 1;
        
         // Iterate until the pointers meet or cross each other
        while(i < j)
        {
            // Check if the negative counterpart of nums[i] is equal to nums[j]
            if(-(nums[i]) == nums[j])
            {
                // If equal, return nums[j] as it's the maximum number satisfying the condition
                return nums[j];
            }
            // If the negative counterpart of nums[i] is less than nums[j], move j pointer to the left
            else if(-(nums[i]) < nums[j])
            {
                j--;
            }
            // If the negative counterpart of nums[i] is greater than nums[j], move i pointer to the right
            else
            {
                i++;
            }
        }
        // If no such pair exists, return -1
        return ans;
    }
};

*********************************APPROACH 1st(USING UNORDERED SET)******************************************

class Solution {// TC--->O(N)              SC--->O(N)
public:
    int findMaxK(vector<int>& nums) {
        // Create an unordered_set to store unique elements of the input vector nums
        unordered_set<int>set(nums.begin(),nums.end());
        
        // Initialize maxi to -1, which will store the maximum number satisfying the condition
        int maxi = -1;
        
        // Iterate through each element x in the vector nums
        for(auto x:nums)
        {
            // Calculate the negative counterpart of x
            int negative = -1*x;
            
            // Check if the negative counterpart exists in the set
            if(set.find(negative) != set.end())
            {
                // If it exists, update maxi to the maximum of current x and maxi
                maxi = max(x,maxi);
            }
        }
        // Return the maximum number satisfying the condition
        return maxi;
        
    }
};


**************************************APPROACH 3rd(OPTIMISED SOLUTION)******************************************

class Solution {// TC--->O(N)                SC--->O(1)
public:
    int findMaxK(vector<int>& nums) {
        // Initialize the answer variable to -1
        int ans = -1;
        
        // Create a vector 'arr' of size 2001 and initialize all elements to 0
        // The size 2001 is chosen to accommodate both positive and negative indices
        vector<int>arr(2001,0);
        
        // Iterate through each element 'num' in the input vector 'nums'
        for(auto num:nums)
        {
            
            // If the element at the position corresponding to the negative counterpart of 'num' in 'arr' is 1
            if(arr[-num + 1000] == 1)
            {
                // Update 'ans' to the maximum of its current value and the absolute value of 'num'
                ans = max(ans,abs(num));
            }
            else
            {
                // If the element at the position corresponding to 'num' in 'arr' is not 1, set it to 1
                arr[num + 1000] = 1;
            }
        }
        
        // Return the final value of 'ans', which represents the maximum number satisfying the condition
        return ans;
    }
};

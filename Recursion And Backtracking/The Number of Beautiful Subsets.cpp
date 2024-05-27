
class Solution {// TC--->O(2^N)               SC--->O(N)
public:
    // Recursive function to explore subsets
    void solve(int index,vector<int>&nums,unordered_map<int,int>&ump,int &ans,int k)
    {
        // Base case: if we've processed all elements, increment the answer
        if(index == nums.size())
        {
            ans++;
            return ;
        }
        
        // Skip the current element and proceed to the next
        solve(index+1,nums,ump,ans,k);
        
        // Check if we can include the current element in the subset
        if(!ump[nums[index] - k] && !ump[nums[index] + k])
        {
            // Include the current element and mark it as used
            ump[nums[index]]++;
            
            // Continue to the next element
            solve(index+1,nums,ump,ans,k);
            
            // Backtrack: unmark the current element
            ump[nums[index]]--;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        // Initialize the count of beautiful subsets to 0
        int ans = 0;
        
        // Hash map to keep track of elements in the current subset
        unordered_map<int,int>ump;
        
        // Start the recursive process
        solve(0,nums,ump,ans,k);
        
        // Subtract 1 to exclude the empty subset
        return ans - 1;
    }
};

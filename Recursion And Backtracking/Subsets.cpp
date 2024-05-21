
class Solution {// TC--->O(2^N * N)           SC--->O(N + 2^N)
public:
    
    // Recursive function to generate all subsets
    void solve(int index,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans)
    {
        // Base case: if the current index is out of bounds, add the current subset to the answer
        if(index >= nums.size())
        {
            // Add the current subset to the answer
            ans.push_back(temp);
            
            // Return to stop further recursion
            return ;
        }
        
        // Include the current element in the subset and move to the next element
        // Add current element to the temporary subset
        temp.push_back(nums[index]);
        
        // Recursive call to include the next element
        solve(index+1,nums,temp,ans);
        
        // Exclude the current element from the subset and move to the next element
        // Remove the last element to backtrack
        temp.pop_back();
        
        // Recursive call to exclude the next element
        solve(index+1,nums,temp,ans);
        
    }
    
    // Function to generate all subsets of a given vector nums
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // This will store all subsets
        vector<vector<int>>ans;
        
        // Temporary vector to store the current subset
        vector<int>temp;
        
        // Call the recursive function starting from the first index
        solve(0,nums,temp,ans);
        
        // Return the list of all subsets
        return ans;
    }
};

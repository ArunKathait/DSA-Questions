class Solution {// TC--->O(NlogN + MlogM)              SC--->O(N+M)
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // Using a map to store key-value pairs where:
        // - Key (int) represents the ID from the input arrays
        // - Value (int) stores the sum of corresponding values
        map<int,int>mp;
        
        // Iterate through the first array (nums1)
        for(auto &x:nums1)
        {
            // x[0] is the key (ID), x[1] is the value to add
            // If the key already exists, add to the existing value
            mp[x[0]] += x[1];
        }

        // Iterate through the second array (nums2)
        for(auto &x:nums2)
        {
            // Merge values into the map in the same way
            mp[x[0]] += x[1];
        }

        // Declare a vector to store the final merged result
        vector<vector<int>>ans;

        // Iterate through the map to convert it into a 2D vector
        for(auto &pair:mp)
        {
            // pair.first -> key (ID), pair.second -> summed value
            ans.push_back({pair.first,pair.second});
        }
        
        // Return the merged 2D vector
        return ans;

    }
};

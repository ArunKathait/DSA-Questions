
class Solution {// TC--->O(n + m)        SC--->O(n + m)
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Initialize a vector to store the intersection results
        vector<int>ans;
        
        // Create an unordered_map to count occurrences of each element in nums1
        unordered_map<int,int>ump;
        
        // Iterate over each element in nums1
        for(auto x:nums1)
        {
            // Increment the count of the element in the map
            ump[x]++;
        }
        
        // Iterate over each element in nums2
        for(auto x:nums2)
        {
            // Check if the element exists in the map
            if(ump.find(x) != ump.end())
            {
                // Add the element to the result vector
                ans.push_back(x);
                
                // Decrement the count of the element in the map
                ump[x]--;
            
                // If the count of the element becomes less than 1, remove it from the map
                if(ump[x] < 1)
                {
                    ump.erase(x);
                }
            }
        }
        // Return the result vector containing the intersection of nums1 and nums2
        return ans;
    }
};


class Solution {// TC--->O(NlogN)                SC--->O(N)
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Create an unordered map to store the frequency of each element in the input vector
        unordered_map<int,int>ump;
        
        // Iterate through the input vector and count the frequency of each element
        for(auto x:nums)
        {
            ump[x]++;
        }
        
        // Create a vector of pairs to store frequency and corresponding elements
        vector<pair<int,int>>vec;
        
        // Transfer the elements and their frequencies from the map to the vector of pairs
        for(auto it:ump)
        {
            // Each pair is {frequency, element}
            vec.push_back({it.second,it.first});
        }
        
        // Define a lambda function for custom comparison
        auto myComp = [](pair<int,int>p1,pair<int,int>p2)
        {
            // If frequencies are the same
            if(p1.first == p2.first)
            {
                // Sort by element in descending order
                return p1.second > p2.second;
            }
            
            // Otherwise, sort by frequency in ascending order
            return p1.first < p2.first;
        };
        
        // Sort the vector of pairs using the custom comparator
        sort(vec.begin(),vec.end(),myComp);
        
        // Create a vector to store the result
        vector<int>ans;
        
        // Iterate through the sorted vector of pairs
        for(auto x:vec)
        {
            // Get the frequency of the current element
            int freq = x.first;
            // Add the element to the result vector 'freq' times
            while(freq--)
            {
                ans.push_back(x.second);
            }
        }
        
        // Return the result vector
        return ans;
    }
};

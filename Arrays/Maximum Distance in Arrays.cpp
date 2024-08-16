
class Solution {// TC--->O(N)                         SC--->O(1)
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        // Initialize globalMin to the first element of the first array
        // This will keep track of the smallest value encountered across all arrays so far
        int globalMin = arrays[0].front();
        
         // Initialize globalMax to the last element of the first array
        // This will keep track of the largest value encountered across all arrays so far
        int globalMax = arrays[0].back();
        
        // Initialize maxDistance to 0
        // This will store the maximum distance between elements from different arrays
        int maxDistance = 0;
        
        // Iterate through the arrays starting from the second one (index 1)
        for(int i=1;i<arrays.size();i++)
        {
            // Get the smallest value from the current array (first element)
            int currentArrayMin = arrays[i].front();
            
            // Get the largest value from the current array (last element)
            int currentArrayMax = arrays[i].back();
            
            // Calculate the distance between the largest value in the current array
            // and the smallest value encountered so far (from a previous array)
            // Update maxDistance if this distance is larger than the current maxDistance
            maxDistance = max(maxDistance,currentArrayMax - globalMin);
            
            // Calculate the distance between the smallest value in the current array
            // and the largest value encountered so far (from a previous array)
            // Update maxDistance if this distance is larger than the current maxDistance
            maxDistance = max(maxDistance,globalMax - currentArrayMin);
            
            // Update globalMin with the minimum value encountered so far
            // This ensures globalMin always holds the smallest value across all arrays seen so far
            globalMin = min(globalMin,currentArrayMin);
            
            // Update globalMax with the maximum value encountered so far
            // This ensures globalMax always holds the largest value across all arrays seen so far
            globalMax = max(globalMax,currentArrayMax);
        }
        
        // Return the maximum distance found
        return maxDistance;
    }
};

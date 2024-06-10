
class Solution {// TC--->O(NlogN)                   SC--->O(N)
public:
    int heightChecker(vector<int>& heights) {
        // Initialize the counter for the number of students not in the correct position
        int ans = 0;
       
        // Create a copy of the original heights vector and store it in 'sorted'
        vector<int>sorted(heights.begin(),heights.end());
        
        // Sort the copied vector 'sorted' to get the expected order of heights
        sort(sorted.begin(),sorted.end());
        
        // Iterate through each element in the original heights vector
        for(int i=0;i<heights.size();i++)
        {
            // Compare the original heights with the sorted heights
            if(heights[i] != sorted[i])
            {
                // If the height in the original vector is different from the sorted vector at the same index
                // Increment the counter 'ans'
                ans++;
            }
        }
        
        // Return the total count of mismatches
        return ans;
    }
};




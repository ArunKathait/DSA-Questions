class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        
        // Get the size of the 'nums' vector
        int n = nums.size();
        
        // This will store the result for each query
        vector<int>ans;
        
        // This keeps track of the occurrence number of 'x'
        int count = 1;
        
        // This map will store the 'count' as the key and the index of 'x' as the value
        unordered_map<int,int>ump;
        
        // Iterate through each element in 'nums'
        for(int i=0;i<n;i++)
        {
            // If the current element is equal to 'x'
            if(nums[i] == x)
            {
                // Map the current occurrence number 'count' to the index 'i'
                ump[count] = i;
                
                // Increment the occurrence count(i.e for next occurence of x)
                count++;
            }
        }
        
        // Iterate through each query in 'queries'
        for(int i=0;i<queries.size();i++)
        {
            // Get the 'x-th' occurrence number from the query
            int index = queries[i];
            
            // If the occurrence number is not found in the map
            if(ump.find(index) == ump.end())
            {
                // Push -1 to the result as the 'x-th' occurrence does not exist
                ans.push_back(-1);
            }
            // If the occurrence number is found in the map
            else
            {
                // Push the index of the 'x-th' occurrence of 'x' to the result
                ans.push_back(ump[index]);
            }
        }
        
        // Return the result vector
        return ans;
    }
};

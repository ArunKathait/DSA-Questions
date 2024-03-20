****************************************APPROACH 1st*********************************************************

class Solution {//TC--->O(NLOGN)         SC--->O(N)
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // Insert the new interval into the intervals vector
    intervals.push_back(newInterval);
    
    // Sort the intervals based on the start values of each interval
    sort(intervals.begin(), intervals.end());
    
    // Create a vector to store the merged intervals
    vector<vector<int>> ans;
    
    // Initialize a variable 'current' to store the current interval
    vector<int> current = intervals[0];
    
    // Iterate through the sorted intervals
    for (int i = 1; i < intervals.size(); i++) 
    {
        
// If the end of the current interval is less than the start of the next interval,
// it means there is no overlap, so push the current interval into the result vector and update'current'
        if (current[1] < intervals[i][0])
        {
            ans.push_back(current);
            current = intervals[i];
        } 
        else
        {
        // If there is an overlap, update the end of the current interval to the maximum of the two ends
            current[1] = max(current[1], intervals[i][1]);
        }
    }
    
    // Push the last merged interval into the result vector
    ans.push_back(current);
    
    // Return the merged intervals
    return ans;
}
};

***********************************************APPROACH 2nd*************************************************

class Solution {// TC--->O(N)         SC--->O(N)
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Initialize a vector to store the resulting merged intervals
        vector<vector<int>>ans;
        
        // Initialize a variable for iterating through the given intervals
        int i=0;
        
        // Iterate through the intervals
        while(i<intervals.size())
        {
            // If the end of the current interval is less then start of the new interval,
            // add the current interval to the result without merging
            if(intervals[i][1] < newInterval[0])
            {
                ans.push_back(intervals[i]);
            }
            // If the start of the current interval is large then end of the new interval,
            // break the loop because there's no need to check further intervals
            else if(intervals[i][0] > newInterval[1])
            {
                break;
            }
            // If there is an overlap between the current interval and the new interval,
            // merge them by updating the start and end of the new interval
            else
            { 
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
            }
            
            // Move to the next interval
            i++;
        }
        
        // Add the merged interval to the result
        ans.push_back(newInterval);
        
        
        // Add the remaining intervals to the result
        while(i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }
        
        // Return the resulting merged intervals
        return ans;
    }
};

*********************************************APPROACH 3rd***************************************************

class Solution {// TC--->O(N)               SC--->O(N)
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Vector to store the merged intervals
        vector<vector<int>>ans;
        
        // Traverse through each interval in the input intervals vector
        for(auto x:intervals)
        {
            // If the end of the current interval is less than the start of the new interval,
            // it means there is no overlap, so we push the current interval to the result.
            if(x[1] < newInterval[0])
            {
                ans.push_back(x);
            }
            // If the start of the current interval is greater than the end of the new interval,
            // it means we have passed the new interval, so we push the new interval to the result
            // and update the new interval to the current interval for further comparisons.
            else if(x[0] > newInterval[1])
            {
                ans.push_back(newInterval);
                newInterval = x;
            }
            // If there is an overlap between the current interval and the new interval,
            // we update the start and end of the new interval to cover both intervals.
            else
            {
                newInterval[0] = min(newInterval[0],x[0]);
                newInterval[1] = max(newInterval[1],x[1]);
            }
        }
        // Push the remaining new interval to the result vector
        ans.push_back(newInterval);
        
        // Return the merged intervals
        return ans;
    }
};

*************************************************APPROACH 1st(BRUTE FORCE)************************************************

class Solution {// TC--->O(N^2)                             SC--->O(N)
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort intervals by their starting times (first element of each interval)
        // This helps to process the intervals in a logical sequence from left to right.
        sort(intervals.begin(),intervals.end());
        
        // Vector `last` will store the end times of the different groups.
        // Initially, we add the end time of the first interval as the first group.
        vector<int>last;
        
        // Adding the end time of the first interval to the `last` vector
        last.push_back(intervals[0][1]);
        
        // Iterate through the remaining intervals starting from the second one
        for(int i=1;i<intervals.size();i++)
        {
            // The start time of the current interval
            int first = intervals[i][0];
            
            // The end time of the current interval
            int second = intervals[i][1];
            
            // Flag to check if the interval has been placed in any group
            bool placed = false;
            
            // Try to place the current interval in an existing group
            for(int j=0;j<last.size();j++)
            {
                // If the start time of the current interval is after the end time of group `j`
                if(first > last[j])
                {
                    // Update the end time of this group with the current interval's end time
                    last[j] = second;
                    
                    // Mark the interval as placed
                    placed = true;
                    
                    // Exit the loop since we placed the interval in this group
                    break;
                }
            }
            
            // If the interval couldn't fit into any existing group
            if(!placed)
            {
                // Create a new group by adding the end time of the current interval to `last`
                last.push_back(second);
            }
        }
        
        // The number of groups needed is the size of the `last` vector,
        // which contains the end times of each group.
        return last.size();
    }
};

***************************************************APPROACH 2nd(BETTER APPROACH)**************************************

class Solution {// TC--->O(NlogN)                         SC--->O(N)
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort the intervals based on their start times (first element of each interval).
        // Sorting helps in processing the intervals in a logical sequence from left to right.
        sort(intervals.begin(),intervals.end());
        
        // We use a priority queue (min-heap) to track the end times of the intervals.
        // The min-heap (priority_queue with greater<int>) ensures the smallest end time is at the top.
        priority_queue<int,vector<int>,greater<int>>pq;
        
        // Iterate through each interval
        for(int i=0;i<intervals.size();i++)
        {
            // The start time of the current interval
            int start = intervals[i][0];
            
            // The end time of the current interval
            int end = intervals[i][1];
            
            // If the priority queue is not empty and the top element (earliest end time)
            // is less than the current start time, we pop it because we can reuse this group.
            if(!pq.empty() && pq.top() < start)
            {
                // Remove the group whose end time is smaller than the current interval's start time
                pq.pop();
            }
            
            // Push the end time of the current interval into the priority queue.
            // This means we are assigning the current interval to a group that ends at 'end'.
            pq.push(end);
        }
        
        // The size of the priority queue represents the number of active groups needed.
        // Each group corresponds to an end time stored in the queue, so the size of the queue
        // gives the minimum number of groups required to accommodate all intervals.
        return pq.size();
    }
};

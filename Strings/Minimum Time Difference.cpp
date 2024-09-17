************************************************APPROACH 1st************************************************************

class Solution {// TC--->O(NlogN)                       SC--->O(N)
public:
    int findMinDifference(vector<string>& timePoints) {
        // Get the number of time points
        int n = timePoints.size();
        
        // A vector to store the time points in minutes
        vector<int>minutes;
        
        // Convert each time point into minutes
        for(int i=0;i<n;i++)
        {
            // Get the current time as a string
            string time = timePoints[i];
            
            // Extract the hour and minute parts from the time string
            string hour = time.substr(0,2);         // First two characters for the hour
            string min = time.substr(3,2);          // Characters at index 3 and 4 for the minute
            
            // Convert the extracted hour and minute to integers and calculate the total minutes
            int total = stoi(hour) * 60 + stoi(min);
            
            // Add the total minutes to the vector
            minutes.push_back(total);
        }
        
        // Sort the minutes vector to arrange time points in increasing order
        sort(minutes.begin(),minutes.end());
        
        // Initialize `ans` to the maximum possible integer value (used to find the minimum)
        int ans = INT_MAX;
        
        // Find the minimum difference between consecutive time points
        for(int i=1;i<n;i++)
        {
            // Calculate the difference between consecutive time points and update the minimum difference
            ans = min(ans,minutes[i] - minutes[i-1]);
        }
        
        
        // Handle the circular difference between the first and last time point
        // The difference is between the last time point of the day and the first one (crossing midnight)
        // 24 * 60 is the total number of minutes in a day
        return min(ans,(24 * 60 - minutes[n-1]) + minutes[0]);
    }
};

************************************************APPROACH 2nd**********************************************************

class Solution {// TC--->O(NlogN)                       SC--->O(N)
public:
    int findMinDifference(vector<string>& timePoints) {
        // Get the number of time points
        int n = timePoints.size();
        
        // Vector to store the time points in terms of total minutes
        vector<int>minutes;
        
        // Loop through each time point and convert it to total minutes
        for(int i=0;i<n;i++)
        {
            // Get the current time point as a string
            string time = timePoints[i];
            
            // Extract hours and minutes as integers from the string `time`
            int hour = (time[0] - '0') * 10 + (time[1] - '0');       // First two characters represent the hour
            int min = (time[3] - '0') * 10 + (time[4] - '0');        // Characters at index 3 and 4 represent the minutes
            
            
            // Convert the time into total minutes since midnight
            int totalMinutes = (hour * 60) + min;
            
            // Add the calculated total minutes to the `minutes` vector
            minutes.push_back(totalMinutes);
        }
        
        // Sort the `minutes` vector to arrange the time points in ascending order of total minutes
        sort(minutes.begin(),minutes.end());
        
        // Initialize `ans` with a large value to track the minimum time difference
        int ans = INT_MAX;
        
        // Loop through the sorted `minutes` vector to calculate the difference between consecutive time points
        for(int i=1;i<n;i++)
        {
            // Compute the difference between consecutive time points and update `ans` if a smaller difference is found
            ans = min(ans,minutes[i] - minutes[i-1]);
        }
        
        // Handle the circular nature of the clock: the time difference between the last and first time points (across midnight)
        // The total number of minutes in a day is 24 * 60, and the circular difference is (1440 - last time + first time)
        return min(ans,(24 * 60 - minutes[n-1]) + minutes[0]);
    }
};

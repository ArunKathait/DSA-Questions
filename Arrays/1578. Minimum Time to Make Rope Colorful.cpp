***************************************************APPROACH 1st(BETTER)*********************************************

class Solution {// TC ---> O(N) + O(N) ~ O(N)                            SC ---> O(K)
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        
        // Vector to store pairs of indices (start, end)
        // representing groups of consecutive balloons
        // having the same color.
        vector<pair<int, int>> groups;
        
        // 'start' marks the beginning of the current group.
        int start = 0;
        
        // Traverse the string to find all consecutive color groups.
        for (int i = 1; i < n; i++) 
        {
            // If the current color is different from the previous one,
            // it means the current group has ended.
            if (colors[i] != colors[i - 1]) 
            {
                // If the group has more than one element (i.e., a duplicate color sequence),
                // store its start and end index in the 'groups' vector.
                if (i - 1 > start) 
                {
                    groups.push_back({start, i - 1});
                }

                // Start a new group from the current index.
                start = i;
            }
        }

        // Handle the last group if the string ends with repeated colors.
        if (n - 1 > start) 
        {
            groups.push_back({start, n - 1});
        }

        // Variable to store the total minimum time required to remove balloons.
        int time = 0;

        // Process each group of consecutive same-colored balloons.
        for (auto [l, r] : groups) 
        {
            int maxi = 0; // Track the maximum time in this group (balloon to keep)
            int sum = 0;  // Sum of all removal times in this group

            // Calculate the total time and the maximum needed time in this group
            for (int i = l; i <= r; i++) 
            {
                sum += neededTime[i];
                maxi = max(maxi, neededTime[i]);
            }

            // We remove all balloons except the one with the maximum needed time.
            // Hence, add (sum - maxi) to total.
            time += (sum - maxi);
        }

        // Return the total minimum time required.
        return time;
    }
};

*****************************************************APPROACH 2nd(OPTIMAL)********************************************

class Solution {// TC ---> O(N)                          SC ---> O(1)
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        
        // Variable to store the total minimum time required
        int ans = 0; 

        // Traverse the string from the 2nd character
        for(int i = 1; i < n; i++)
        {
            // If two consecutive balloons have the same color
            if(colors[i] == colors[i - 1])
            {
                // Add the smaller removal time to the answer,
                // because we need to remove one of them to make colors[i-1] and colors[i] different.
                ans += min(neededTime[i], neededTime[i - 1]);

                // Keep the larger removal time for the remaining balloon.
                // This ensures that if there are multiple same-colored balloons in a row (like "aaa"),
                // we always keep the one with the maximum neededTime so far.
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }

        // Return the total minimum time required to make all adjacent colors different
        return ans;
    }
};

********************************************APPROACH 3rd********************************************************

class Solution {// TC ---> O(N)                             SC ---> O(1)
public:
    int minCost(string colors, vector<int>& neededTime) {
        // Get the total number of balloons
        int n = colors.size();  
        
        // This will store the total minimum time required
        int time = 0;  

        // Keeps track of the maximum time in the current group of same-colored balloons         
        int prevMax = 0;        
        
        // Loop through each balloon
        for (int i = 0; i < n; i++) 
        {    
            // If the current balloon color is different from the previous one,
            // it means we are starting a new group of colors.
            // So, reset prevMax to 0.
            if (i > 0 && colors[i] != colors[i - 1]) 
            {
                prevMax = 0;
            }
            
            // Time needed to remove the current balloon
            int current = neededTime[i];  
            
            // If two consecutive balloons have the same color,
            // we must remove one of them. We always keep the one with higher removal time.
            // So we add the smaller one (min(prevMax, current)) to total time.
            time += min(prevMax, current);
            
            // Update prevMax to the larger of the two times (current or previous max),
            // because we will keep the balloon that takes the longest to remove.
            prevMax = max(prevMax, current);
        }
        // Return the total minimum time to make all colors non-consecutive
        return time;  
    }
};

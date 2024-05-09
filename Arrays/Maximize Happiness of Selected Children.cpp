************************************************APPROACH 1st******************************************************

class Solution {// TC--->O(NlogN)               SC--->O(1)
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        // Sorting the happiness vector in non-increasing order 
        sort(happiness.begin(),happiness.end(),greater<int>());
        
        // Variable to keep track of how much happiness should decrease
        int decrease = 0;
        
        // Variable to store the final maximum happiness sum
        long long ans = 0;
        
        // Iterate through the first 'k' elements of the sorted happiness vector
        for(int i=0;i<k;i++)
        {
            // Calculate the modified happiness by subtracting the decrease
            int val = happiness[i] - decrease;
            
            // Add the maximum of the modified happiness and 0 to the final sum
            // (if the modified happiness is negative, it contributes 0 to the sum)
            ans += max(val,0);
            
            // Increment the decrease value to reflect decreasing happiness
            decrease++;
        }
        
        // Return the final maximum happiness sum
        return ans;
    }
};


******************************************APPROACH 2nd(PRIORITY QUEUE)*********************************************

class Solution {// TC--->O(NlogN)            SC--->O(N)
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       
        // Creating a max heap (priority queue) using the elements of the happiness vector
        priority_queue<int>pq(happiness.begin(),happiness.end());
        
        // Variable to store the final maximum happiness sum
        long long ans = 0;
        
        // Variable to keep track of how much happiness should decrease
        int decrease = 0;
        
        // Iterate through the first 'k' elements of the priority queue
        for(int i=0;i<k;i++)
        {
            // Get the maximum happiness level from the top of the priority queue
            int val = pq.top();
            
            // Remove the top element from the priority queue
            pq.pop();
            
            // Calculate the modified happiness by subtracting the decrease
            // If the modified happiness is negative, contribute 0 to the sum
            ans += max(val - decrease,0);
            
            // Increment the decrease value to reflect decreasing happiness
            decrease++;
        }
        
        // Return the final maximum happiness sum
        return ans;
    }
};

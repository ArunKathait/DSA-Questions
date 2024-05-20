***********************************************APPROACH 1st****************************************************************

class Solution {// TC--->O(N)                 SC--->O(1)
public:
    
    // Define a type alias for long long
    typedef long long ll;
    
    // Function to calculate the maximum value sum
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // Initialize minLoss to the maximum integer value
        int minLoss = INT_MAX;
        
        // Initialize sum to 0
        ll sum = 0;
        
        // Initialize count to 0
        int count = 0;
        
        // Iterate over each number in the nums vector
        for(auto num:nums)
        {
            // Check if the XOR operation increases the value of num
            if(num < (num^k))
            {
                // Increment count if XOR increases the value
                count++;
                
                // Add the XORed value to the sum
                sum += (num^k);
            }
            else
            {
                // Add the original value to the sum if XOR does not increase the value
                sum += num;
            }
            
            // Calculate the minimum loss
            // Update minLoss with the smallest difference
            minLoss = min(minLoss,abs(num - (num^k)));
        }
        
        // Check if count is even
        if(count%2 == 0)
        {
            // If even, return the sum directly
            return sum;
        }
        
        // If count is odd, subtract the minimum loss from the sum
        return sum - minLoss;
    }
};


************************************************APPROACH 2nd************************************************************

class Solution {// TC--->O(NlogN)             SC--->O(N)
public:
    // Define a type alias for long long
    typedef long long ll;
    
    // Function to calculate the maximum value sum
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // Vector to store the profit of using XOR operation
        vector<int>profit;
        
        // Initialize the normal sum to 0
        ll normalSum = 0;
        
        // Iterate over each number in the nums vector
        for(auto num:nums)
        {
            // Add the original value to normalSum
            normalSum += num;
            
            // Calculate the profit of using XOR operation and store it in profit vector
            profit.push_back((num^k) - num);
        }
        
        // Sort the profit vector in descending order
        // We can also do like this below---->sort(profit.begin(),profit.end(,greater<int>()))
        sort(profit.rbegin(),profit.rend());
        
        // Get the size of the profit vector
        int n = profit.size();
        
        // Iterate through the profit vector in pairs
        for(int i=0;i<n-1;i+=2)
        {
            // Sum the pair of profits
            ll pairSum = profit[i] + profit[i+1];
            
            // If the sum of the pair is positive, add it to normalSum
            if(pairSum > 0)
            {
                normalSum += pairSum;
            }
        }
        
        // Return the calculated normalSum
        return normalSum;
    }
};

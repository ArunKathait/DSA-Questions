*********************************************APPROACH 1st(BRUT FORCE)*******************************************
// NOTE:This will give time limit exceed.

class Solution {// TC--->O(N^3)         SC--->O(1)
public:
    int findMaxLength(vector<int>& nums) {
        // Initialize a variable to store the maximum length
        int maxi =INT_MIN;
        
        // Get the size of the input vector
        int n = nums.size();
        
        // Iterate over all possible starting indices
        for(int i=0;i<n;i++)
        {
            // Iterate over all possible ending indices starting from the current starting index
            for(int j=i;j<n;j++)
            {
                // Initialize counters for zeros and ones
                int zeros = 0,ones = 0;
                
                // Iterate over the subarray defined by the current starting and ending indices
                for(int k=i;k<=j;k++)
                {
                    // Count the number of zeros and ones in the subarray
                    if(nums[k] == 0)
                    {
                        zeros++;
                    }
                    else
                    {
                        ones++;
                    }
                }
                
                // If the count of zeros is equal to the count of ones,
                // update the maximum length if the length of the current subarray is greater
                if(zeros == ones)
                {
                    maxi = max(maxi,j-i+1);
                }
            }
        }
        
        // Return the maximum length found. If maxi is still INT_MIN, 
        // it means no subarray with equal counts of zeros and ones was found,
        // so return 0. Otherwise, return the maximum length found.
        return maxi == INT_MIN ? 0 : maxi;
    }
};

********************************************APPROACH 2nd******************************************************
// NOTE:This will give time limit exceed.
  
class Solution {// TC--->O(N^2)         SC--->O(1)
public:
    int findMaxLength(vector<int>& nums) {
        // Initialize a variable to store the maximum length
        int maxi =INT_MIN;
        
        // Get the size of the input vector
        int n = nums.size();
        
        // Iterate over all possible starting indices
        for(int i=0;i<n;i++)
        {
                // Initialize counters for zeros and ones.   
                int zeros = 0,ones = 0;
            
            // Iterate over all possible ending indices starting from the current starting index
            for(int j=i;j<n;j++)
            {
                // Check the value of the current element in the input array 'nums' at index 'j'.
                if(nums[j] == 0)
                {
                    // If the current element is 0, increment the count of zeros.
                    zeros++;
                }
                else
                {
                    // If the current element is not 0 (i.e., it's 1 in this case), increment the count of ones.
                    ones++;
                }
                
                // If the count of zeros is equal to the count of ones,
                // update the maximum length if the length of the current subarray is greater
                if(zeros == ones)
                {
                    maxi = max(maxi,j-i+1);
                }
            }
        }
        
        // Return the maximum length found. If maxi is still INT_MIN, 
        // it means no subarray with equal counts of zeros and ones was found,
        // so return 0. Otherwise, return the maximum length found.
        return maxi == INT_MIN ? 0 : maxi;
    }
};

*****************************************APPROACH 3rd******************************************************
class Solution {// TC--->O(N)         SC--->O(N)
public:
    int findMaxLength(vector<int>& nums) {
        // Initialize the maximum length of contiguous subarray with equal number of 0s and 1s.
        int ans = 0;
        
        // Initialize an unordered map to store prefix sums and their corresponding indices.
        unordered_map<int,int>ump;
        
        // Initialize the prefix sum.
        int prefixSum = 0;
        
        // The initial prefix sum of 0 (no elements before).
        ump[0] = -1;
        
        // Iterate through the elements of the input array 'nums'.
        for(int i=0;i<nums.size();i++)
        {
            // Update the prefix sum based on the value of the current element.
            // Increment for 1, decrement for 0.
            prefixSum += (nums[i] == 1) ? 1:-1;
            
            // Check if the current prefix sum has been encountered before.
            if(ump.find(prefixSum)!=ump.end())
            {
                // If yes, update the maximum length using the current index and the index stored in the map.
                ans = max(ans,i - ump[prefixSum]);
            }
            else
            {
                // If not, store the current prefix sum along with its index in the map.
                ump[prefixSum] = i;
            }
        }
        
        // Return the maximum length of contiguous subarray with equal number of 0s and 1s.
        return ans;
    }
};

********************************************************************APPROACH 1st*************************************************************************************

class Solution {//TC--->O(N)          SC--->O(N)
public:
    
    // Function to find the pivot integer
    int pivotInteger(int n) {
        
        // Initializing a vector to store prefix sums
        vector<int>prefix(n+1,0);
        
        // Initializing prefix[1] as 1
        prefix[1] = 1;
        
        // Calculating prefix sums for numbers from 2 to n
        for(int i=2;i<=n;i++)
        {
            prefix[i] = prefix[i-1] + i;
        }
        
        // Initializing a vector to store suffix sums
        vector<int>suffix(n+1,0);
        
        // Initializing suffix[n] as n
        suffix[n] = n;
        
        // Calculating suffix sums for numbers from n-1 to 1
        for(int j=n-1;j>=1;j--)
        {
            suffix[j] = j + suffix[j+1];
        }
        
        // Finding the pivot integer by checking where prefix sum equals suffix sum
        for(int i=1;i<=n;i++)
        {
            if(prefix[i] == suffix[i])
            {
                return i;
            }
        }
        
        // If no pivot integer is found, return -1
        return -1;
    }
};

******************************************************************APPROACH 2nd*************************************************************************************
class Solution { // TC--->O(N)         SC--->O(1)
public:
    int pivotInteger(int n) {
        
        // Calculating the sum of integers from 1 to n
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            sum += i;
        }
        
        // Iterating through the numbers from 1 to n
        // and checking if the sum of integers to the left of the current number
        // is equal to the sum of integers to the right
        int leftSum = 0;
        for(int i=1;i<=n;i++)
        {
            // Incrementally adding the current number to the left sum
            leftSum += i;
            
            // If left sum equals total sum
            if(leftSum == sum)
            {
                // Return the current number as the pivot integer
                return i;
            }
            
            // Subtract the current number from the total sum for the next iteration
            sum -= i;
        }
        
        // If no pivot integer is found, return -1
        return -1;
    }
};

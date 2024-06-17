****************************************************************APPROACH 1st(USING BRUTE FORCE)*************************************************************

// NOTE: This will give Time Limit Exceeded.

class Solution {// TC--->O(N^2)                 SC--->O(1)
public:
    bool judgeSquareSum(int c) {
        // Iterate over all integers from 0 to c for variable i
        for(long i=0;i<=c;i++)
        {
            // Iterate over all integers from 0 to c for variable j
            for(long j=0;j<=c;j++)
            {
                // Calculate the sum of the squares of i and j
                long sum = (i*i + j*j);
                
                // If the sum equals c, then there exist two integers i and j
                // such that i^2 + j^2 = c, so return true
                if(sum == c)
                {
                    return true;
                }
            }
        }
        
        // If no such pair (i, j) is found, return false
        return false;
    }
};


*****************************************************************APPROACH 2nd(USING 2 POINTERS)*************************************************************

class Solution {// TC--->O(sqrt(C))                SC--->O(1)
public:
    bool judgeSquareSum(int c) {
        // Initialize two pointers: low starting from 0, high starting from the square root of c
        long long low = 0;
        long long high = sqrt(c);
        
        // Use a two-pointer approach to find if there exist two numbers such that their squares sum up to c
        while(low <= high)
        {
            // Calculate the sum of squares of the current low and high pointers
            long long currentSum = (low*low) + (high*high);
            
            // If the sum of squares equals c, return true
            if(currentSum == c)
            {
                return true;
            }
            // If the sum of squares is less than c, increment the low pointer to increase the sum
            else if(currentSum < c)
            {
                low++;
            }
            // If the sum of squares is greater than c, decrement the high pointer to decrease the sum
            else
            {
                high--;
            }
        }
        // If no such pair (low, high) is found, return false
        return false;
    }
};

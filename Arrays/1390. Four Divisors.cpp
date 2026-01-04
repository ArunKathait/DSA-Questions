*************************************************APPROACH 1st(USING BRUTE FORCE)********************************************

class Solution {// TC ---> O(N*M)                                  SC ---> O(1)
public:

    // This function calculates the sum of divisors of 'num'
    // ONLY if the number has exactly 4 divisors
    int calculateDivisors(int num)
    {
        int sum = 0;     // To store sum of divisors
        int count = 0;   // To count number of divisors

        // Loop from 1 to num to check all possible divisors
        for(int i = 1; i <= num; i++)
        {
            // If i divides num completely, it is a divisor
            if(num % i == 0)
            {
                sum += i;   // Add divisor to sum
                count++;    // Increase divisor count
            }
        }

        // If number has exactly 4 divisors
        if(count == 4)
        {
            return sum;     // Return sum of those 4 divisors
        }
        else
        {
            return 0;       // Otherwise return 0
        }
    }

    // Main function to calculate total sum for all numbers in array
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();   // Size of input array
        
        int totalSum = 0;      // Stores final answer

        // Loop through each number in the array
        for(int i = 0; i < n; i++)
        {
            // Get sum of divisors if number has exactly 4 divisors
            int sum = calculateDivisors(nums[i]);

            // Add it to total sum
            totalSum += sum;
        }

        // Return final sum
        return totalSum;
    }
};

***********************************************APPROACH 2nd(OPTIMAL APPROACH)******************************************


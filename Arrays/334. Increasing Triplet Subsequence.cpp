**************************************************APPROACH 1st(BRUTE FORCE)******************************************

class Solution {// TC--->O(N^3)                         SC--->O(1)
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();  
        // 'n' stores the total number of elements in the input array 'nums'

        // The goal: Check if there exists any triplet (i, j, k)
        // such that i < j < k and nums[i] < nums[j] < nums[k]

        // Outer loop: Choose the first element of the triplet
        for (int i = 0; i < n; i++) 
        {
            // Middle loop: Choose the second element
            // It must come after the first element
            for (int j = i + 1; j < n; j++) 
            {
                // Inner loop: Choose the third element
                // It must come after the second element
                for (int k = j + 1; k < n; k++) 
                {
                    // Check if the selected three numbers are in strictly increasing order
                    if (nums[i] < nums[j] && nums[j] < nums[k]) 
                    {
                        // As soon as one valid triplet is found,
                        // return true immediately — no need to check further
                        return true;
                    }
                }
            }
        }

        // If no triplet (i, j, k) satisfies the condition after all loops,
        // it means the array does NOT contain any increasing triplet
        return false;
    }
};

**********************************************APPROACH 2nd(BETTER APPROACH)**************************************

class Solution {// TC--->O(N)                                         SC--->O(1)
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        // 'firstNumber' will store the smallest number seen so far.
        // 'secondNumber' will store the second smallest number (greater than firstNumber).
        // Initialize both to INT_MAX so that any number in the array will be smaller initially.
        int firstNumber = INT_MAX;
        int secondNumber = INT_MAX;

        // Traverse through each number in the array
        for (int i = 0; i < n; i++) 
        {
            // Current element being processed
            int thirdNumber = nums[i]; 

            // Case 1: If current number is smaller than or equal to firstNumber,
            // update firstNumber (potentially new smallest number).
            if (thirdNumber <= firstNumber) 
            {
                firstNumber = thirdNumber;
            }
            // Case 2: Else if the current number is greater than firstNumber
            // but smaller than or equal to secondNumber,
            // update secondNumber (potentially new second smallest).
            else if (thirdNumber <= secondNumber) 
            {
                secondNumber = thirdNumber;
            }
            // Case 3: If current number is greater than both firstNumber and secondNumber,
            // it means we have found an increasing triplet:
            // firstNumber < secondNumber < thirdNumber
            else 
            {
                return true; // Triplet found
            }
        }

        // If loop finishes without finding such a triplet, return false.
        return false;
    }
};

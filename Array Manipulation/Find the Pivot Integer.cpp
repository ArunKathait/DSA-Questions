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

*******************************************APPROACH 3rd(2 POINTERS)**********************************************************
class Solution {//TC--->O(N)       SC--->O(1)
public:
    int pivotInteger(int n) {
        // Initialize two pointers: one at the beginning (i) and one at the end (j) of the range
        int i = 1;  // Start from 1
        int j = n;  // End at n
        
        // Initialize left sum and right sum to keep track of the sums of elements on both sides
        int leftSum = 1;  // Initially, left sum contains only the first element
        int rightSum = n; // Initially, right sum contains only the last element
        
        // Loop until the pointers meet or cross each other
        while(i < j) 
        {
            // If left sum is smaller than right sum, move the left pointer to the right
            if(leftSum < rightSum) 
            {
                i++;            // Move the left pointer to the right
                leftSum += i;   // Update left sum by adding the new element
            } else
            {
                j--;            // If left sum is not smaller, move the right pointer to the left
                rightSum += j;  // Update right sum by adding the new element
            }
        }
        
        // At this point, if both left sum and right sum are equal, we found the pivot integer
        // Return the index if pivot integer is found, otherwise return -1
        return leftSum == rightSum ? i : -1;
    }
};

*****************************************************4th APPROACH(BINARY SEARCH)*****************************************

 class Solution { // TC--->LOGN           SC--->O(1)
public:
    int pivotInteger(int n) {
// Calculate the total sum of integers from 1 to n using the formula for the sum of an arithmetic series
        int totalSum = n * (n + 1) / 2;
        
        // Initialize variables for binary search
        int low = 1;  // Lowest possible pivot integer
        int high = n; // Highest possible pivot integer
        
        // Perform binary search to find the pivot integer
        while (low <= high) 
        {
            // Calculate the mid pivot
            int midPivot = low + (high - low) / 2;
            
            // Check if mid pivot squared equals the total sum
            if (midPivot * midPivot == totalSum)
            {
                return midPivot; // If so, mid pivot is the pivot integer
            }
            // If mid pivot squared is less than total sum, search the right half
            else if (midPivot * midPivot < totalSum) 
            {
                low = midPivot + 1; // Move the low pointer to the right
            }
            // If mid pivot squared is greater than total sum, search the left half
            else 
            {
                high = midPivot - 1; // Move the high pointer to the left
            }
        }
        
        // If the loop exits, it means no pivot integer was found
        return -1; // Return -1 to indicate that there is no valid pivot integer
    }
};


*******************************************************5th APPROACH(SQUARE ROOT METHOD)*********************************************
class Solution { // TC--->O(1)        SC--->O(1)
public:
    int pivotInteger(int n) {
    // Calculate the total sum of integers from 1 to n using the formula for sum of arithmetic series
        int totalSum = n * (n + 1) / 2;
        
        // Calculate the integer square root of the total sum
        int pivot = sqrt(totalSum);
        
        // If the square of pivot is equal to the total sum, then pivot is a valid integer
        if (pivot * pivot == totalSum) 
        {
            return pivot; // Return the pivot as the result
        }
        
        // If the square of pivot is not equal to the total sum, then pivot is not a valid integer
        return -1; // Return -1 indicating that there is no valid pivot integer
    }
};


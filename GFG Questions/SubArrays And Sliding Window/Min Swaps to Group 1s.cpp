**********************************************APPROACH 1st(USING BRUTE FORCE)*************************************

class Solution {// TC ---> O(N^2)                                         SC ---> O(1)
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();  // Size of array

        // Step 1: Count total number of 1's in the array
        int totalOnes = 0;
        for(int num : arr) 
        {
            if(num == 1) 
                totalOnes++;  // Increment when we find a 1
        }

        // Edge case: If there are no 1's, grouping is not possible
        if(totalOnes == 0) 
            return -1;

        int minSwaps = INT_MAX;  // To store minimum swaps required

        // Step 2: Check all possible subarrays (windows) of size = totalOnes
        for(int i = 0; i <= n - totalOnes; i++) 
        {

            int countOnes = 0;  // Count number of 1's in current window

            // Step 3: Traverse current window from i to i + totalOnes - 1
            for(int j = i; j < i + totalOnes; j++) 
            {
                if(arr[j] == 1) 
                    countOnes++;  // Count how many 1's are already present
            }

            // Step 4: Calculate swaps needed for this window
            // total positions - already correct 1's
            int swaps = totalOnes - countOnes;

            // Step 5: Update minimum swaps among all windows
            minSwaps = min(minSwaps, swaps);
        }

        // Step 6: Return minimum swaps required
        return minSwaps;
    }
};
**************************************APPROACH 2nd(USING SLIDING WINDOW)****************************************
  
class Solution {// TC ---> O(n) + O(n) = O(n)                        SC ---> O(1)
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();  // Size of the array
        
        int totalOnes = 0;   // Step 1: Count total number of 1's in array
        
        for(auto &num : arr) 
        {
            if(num == 1) 
            {
                totalOnes++;  // Increment count if element is 1
            }
        }
        
        // Edge case: if no 1's exist, grouping is not possible
        if(totalOnes == 0) 
        {
            return -1;
        }
        
        // Two pointers for sliding window
        int i = 0;  // Left pointer (start of window)
        int j = 0;  // Right pointer (end of window)
        
        int currentOnes = 0; // Number of 1's inside current window
        int maxOnes = 0;     // Maximum number of 1's found in any window
        
        // Step 2: Traverse the array using sliding window
        while(j < n) 
        {
            
            // Include current element (arr[j]) into window
            if(arr[j] == 1) 
            {
                currentOnes++;  // Increase count if it's 1
            }
            
            // Step 3: If window size exceeds required size (totalOnes)
            if(j - i + 1 > totalOnes) 
            {
                
                // Remove element going out of window (arr[i])
                if(arr[i] == 1) 
                {
                    currentOnes--;  // Decrease count if removed element was 1
                }
                i++;  // Move left pointer forward
            }
            
            // Step 4: When window size is exactly equal to totalOnes
            if(j - i + 1 == totalOnes) 
            {
                
                // Update maximum number of 1's found in any valid window
                maxOnes = max(maxOnes, currentOnes);
            }
            
            // Move right pointer forward
            j++;
        }
        
        // Step 5: Calculate minimum swaps required
        // = total positions - already correct 1's in best window
        return totalOnes - maxOnes;
    }
};

/*   NOTE :

Approach

First, I count total number of 1’s in the array.
This becomes my window size.

Then I use a sliding window of that size and find the maximum number of 1’s present in any window.

The idea is:

-> "That window already has maximum correct positions"
-> "Remaining positions must be swapped"

  */

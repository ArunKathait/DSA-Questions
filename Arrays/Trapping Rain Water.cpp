***********************************APPROACH 1st(USING PREFIX AND SUFFIX SUM)***************************************
class Solution {// TC--->O(N) + O(n) ~= O(N)         SC--->O(N) + O(N) ~= O(N)
public:
    int trap(vector<int>& height) {
        // Getting the size of the input vector
        int n = height.size();
        
        // Initializing two vectors to store prefix and suffix maximum heights
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        // Storing the first element of height in prefix[0]
        prefix[0] = height[0];
        
        // Storing the last element of height in suffix[n-1]
        suffix[n-1] = height[n-1];
        
        // Loop to calculate prefix maximum heights
        for(int i = 1; i < n; i++)
        {
            // Calculating the prefix maximum heights using max function
            prefix[i] = max(prefix[i-1], height[i]);
            
            // Calculating the suffix maximum heights using max function
            suffix[n-i-1] = max(suffix[n-i], height[n-i-1]);
        }
        
        // Initializing variable to store the total trapped water
        int ans = 0;
        
        // Loop to calculate trapped water at each position
        for(int i = 0; i < n; i++)
        {
            // Adding the minimum of prefix and suffix maximum heights at each position 
            // to the total trapped water and subtracting the height of the current position
            ans += min(prefix[i], suffix[i]) - height[i]; 
        }

        // Returning the total trapped water
        return ans;
    }
};


***********************************APPROACH 2nd(USING 2 POINTERS)****************************************************
class Solution {// TC--->O(N)         SC--->O(1)
public:
    int trap(vector<int>& height) {
        
        // Getting the size of the input vector
        int n = height.size();
        
        // Initializing variables for left and right pointers, left and right maximum heights, and the answer
        int left = 0;
        int right = n-1;
        int left_max = 0;
        int right_max = 0;
        int ans = 0;
        
        // Loop until left pointer is less than or equal to right pointer
        while(left <= right)
        {
            //If the height at the left pointer is less than or equal to the height at the right pointer
            if(height[left] <= height[right])
            {
                // Update left_max to be the maximum of itself and the current height at left pointer
                left_max = max(left_max,height[left]);
                
                // Add to the answer the difference between left_max and the current height at left pointer
                ans += left_max - height[left];
                
                // Move the left pointer to the right
                left++;
            }
            else
            {
                // If height at right pointer is less than height at left pointer
                // Update right_max to be the maximum of itself and the current height at right pointer
                right_max = max(right_max,height[right]);
                
                // Add to the answer the difference between right_max and the current height at right pointer
                ans += right_max - height[right];
                
                // Move the right pointer to the left
                right--;
            }
        }
        
        // Return the total trapped water
        return ans;
    }
};

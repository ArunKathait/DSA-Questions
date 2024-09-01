*************************************************APPROACH 1st*********************************************************

class Solution {// TC--->O(N) + O(N) +O(N) ~ O(N)                                SC--->O(N) + O(N) ~ O(N)
public:
    
    // Function to find Previous Smaller Left (PSL) for each element in the array
    vector<int>psl(vector<int>&heights,int n)
    {
        // Stack to store indices of elements
        stack<int>st;
        
        // Result vector to store PSL indices for each element
        vector<int>ans(n);
        
        // Traverse the array from left to right
        for(int i=0;i<n;i++)
        {
            // Pop elements from the stack until the top element is smaller than the current element
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            
            // If the stack is empty, no smaller element to the left, use -1
            ans[i] = st.empty() ? -1 : st.top();
            
            // Push the current index onto the stack
            st.push(i);
        }
        
        // Return the vector containing PSL indices
        return ans;
    }
    
    // Function to find Next Smaller Right (NSR) for each element in the array
    vector<int>nsr(vector<int>&heights,int n)
    {
        // Stack to store indices of elements
        stack<int>st;
        
         // Result vector to store NSR indices for each element
        vector<int>ans(n);
        
        // Traverse the array from right to left
        for(int i=n-1;i>=0;i--)
        {
            // Pop elements from the stack until the top element is smaller than the current element
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                st.pop();
            }
            
            // If the stack is empty, no smaller element to the right, use 'n' (which is the length of the array)
            ans[i] = st.empty() ? n : st.top();
            
            // Push the current index onto the stack
            st.push(i);
        }
        
        // Return the vector containing NSR indices
        return ans;
    }
    
    // Function to compute the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        
        // Size of the histogram
        int n = heights.size();
        
        // Find the Previous Smaller Left (PSL) for each bar
        vector<int>left = psl(heights,n);
        
        // Find the Next Smaller Right (NSR) for each bar
        vector<int>right = nsr(heights,n);
        
        // Initialize maximum area as 0
        int maxArea = 0;
        
        // Calculate the area for each bar as the smallest height multiplied by the width between NSR and PSL
        for(int i=0;i<n;i++)
        {
            // Current bar height
            int height = heights[i];
            
            // Width between the Next Smaller Right and Previous Smaller Left
            int width = right[i] - left[i] - 1;
            
            // Calculate the area for the current bar
            maxArea = max(maxArea,height * width);
        }
        
        // Return the maximum area found
        return maxArea;
    }
};


**************************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(N)                                       SC--->O(N)
public:
    int largestRectangleArea(vector<int>& heights) {
        // Stack to store indices of histogram bars
        stack<int>st;
        
        // Get the number of bars in the histogram
        int n = heights.size();
        
        // Variable to store the maximum area found
        int maxArea = 0;

        // Traverse through each bar of the histogram
        for(int i = 0; i < n; i++) 
        {
            // While the stack is not empty and the current bar height is less than the bar height at the top index of the stack
            // (this means we've found a right boundary for the bar at the top of the stack)
            while (!st.empty() && heights[st.top()] > heights[i]) 
            {
                // Height of the bar at the top index of the stack
                int height = heights[st.top()];
                
                // Remove the index from the stack as this bar will now be processed
                st.pop();
                
                // Find the index of the Previous Smaller Element (PSE)
                // If the stack is empty after popping, the PSE index is -1
                // Otherwise, it's the current top of the stack
                int pse = st.empty() ? -1 : st.top();
                
                // Calculate the width of the rectangle using the PSE index and the current index `i`
                // Width is determined by the distance between the current bar and the bar represented
                // by the top of the stack after popping
                int width = i - pse - 1;
                
                // Update the maximum area if the area with the current height and width is larger
                maxArea = max(maxArea, height * width);
            }
            
            // Push the current index `i` onto the stack
            st.push(i);
        }

        // Process the remaining elements in the stack after the loop completes
        while (!st.empty()) 
        {
            // Height of the bar at the top index of the stack
            int height = heights[st.top()];
            
            // Remove the index from the stack as this bar will now be processed
            st.pop();
            
            // Find the index of the Previous Smaller Element (PSE)
            // If the stack is empty after popping, the PSE index is -1
            // Otherwise, it's the current top of the stack
            int pse = st.empty() ? -1 : st.top();
            
            // Calculate the width of the rectangle using the PSE index and the end of the array `n`
            // Width is determined by the distance from the PSE index to the end of the histogram
            int width = n - pse - 1;
            
            // Update the maximum area if the area with the current height and width is larger
            maxArea = max(maxArea, height * width);
        }

        // Return the maximum rectangular area found in the histogram
        return maxArea;
    }
};

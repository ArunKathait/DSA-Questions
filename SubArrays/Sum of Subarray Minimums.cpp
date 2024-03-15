**************************************************APPROACH 1st(BRUTE FORCE)*********************************
// NOTE: This will give time limit exceed.

class Solution {// TC--->O(N^3)           SC--->O(1)
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        // Initialize a variable to store the minimum value found in the subarray
        int mini = INT_MAX;
        
        // Initialize a variable to store the sum of minimums of all subarrays
        int sum = 0;
        
        // Initialize a variable to temporarily store the minimum value
        int val =0;
        
        // Iterate through each element of the array
        for(int i=0;i<arr.size();i++)
        {
            // For each element, consider all possible subarrays starting from this element
            for(int j=i;j<arr.size();j++)
            {
                // Create a temporary vector to store the elements of the current subarray
                vector<int>ans;
                
                // Iterate through the subarray from index i to j
                for(int k=i;k<=j;k++)
                {
                    // Add the element to the temporary vector
                    ans.push_back(arr[k]);
                    
                    // Find the minimum element in the temporary vector
                    val = *min_element(ans.begin(),ans.end());
                    
                }
                
                // Add the minimum value found in the subarray to the sum
                sum += val;
            }
        }
        
        // Return the sum of minimums of all subarrays
        return sum;
    }
};

********************************************2nd APPROACH(USING STACK)*********************************************

class Solution {// TC--->O(N)           SC--->O(N)
public:
    
    // Function to get the index of the next smaller element to the right (LSR)
    vector<int>getNSL(int n,vector<int>&arr)
    {
        // Initialize a vector to store the LSR indices
        vector<int>ans(n);
        
        // Create a stack to store indices
        stack<int>st;
        
        // Iterate through the array
        for(int i=0;i<n;i++)
        {
            // If the stack is empty, there's no smaller element to the right
            if(st.empty())
            {
                // Mark it as -1
                ans[i] = -1;
            }
            else
            {
            // Otherwise,keep popping elements from the stack until we find an element smaller than the   
            // current element
                 while(!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                
        // If the stack is empty now, there's no smaller element to the right
        // Otherwise, the top of the stack contains the index of the next smaller element to the right
                ans[i] = st.empty() ? -1 : st.top();
            }
            
            // Push the current index to the stack
            st.push(i);
        }
        
        // Return the vector containing LSR indices
        return ans;
    }
    
    // Function to get the index of the next smaller element to the left (RSR)
    vector<int>getNSR(int n,vector<int>&arr)
    {
        // Initialize a vector to store the RSR indices
        vector<int>ans(n);
        
        // Create a stack to store indices
        stack<int>st;
        
        // Iterate through the array in reverse order
        for(int i=n-1;i>=0;i--)
        {
            // If the stack is empty, there's no smaller element to the left
            if(st.empty())
            {
                // Mark it as n (out of bounds)
                ans[i] = n;
            }
            else
            {
                // Otherwise, keep popping elements from the stack until we find an element smaller than   
                // the current element
                while(!st.empty() && arr[st.top()] > arr[i])
                {
                    st.pop();
                }
                
        // If the stack is empty now, there's no smaller element to the left
        // Otherwise, the top of the stack contains the index of the next smaller element to the left
                ans[i] = st.empty() ? n:st.top();
            }
            
            // Push the current index to the stack
            st.push(i);
        }
        
         // Return the vector containing RSR indices
        return ans;
    }
    
    
    // Function to calculate the sum of the minimums of all subarrays
    int sumSubarrayMins(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();
        
        // Get LSR and RSR vectors for the array
        vector<int>NSL = getNSL(n,arr);
        vector<int>NSR = getNSR(n,arr);
        
        // Initialize sum as a long long to avoid overflow
        long long sum = 0;
        
        // Define modulo constant
        int M = 1e9 + 7;
        
        // Iterate through the array
        for(int i=0;i<n;i++)
        {
            // Length of the left segment
            long long ls = i - NSL[i];
            
            // Length of the right segment
            long long rs = NSR[i] - i;
            
            // Total number of subarrays with the minimum at index i
            long long totalWays = ls * rs;
            
            // Sum of minimums for all subarrays with the minimum at index i
            long long totalSum = arr[i] * totalWays;
            
             // Add the sum to the total sum
            sum = (sum + totalSum)%M;// Apply modulo operation to avoid overflow
        }
        
        // Return the sum modulo M
        return sum%M;
    }
};

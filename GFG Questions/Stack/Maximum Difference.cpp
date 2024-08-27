

class Solution {// TC--->O(N)                            SC--->O(N)
  public:
  // Function to find the nearest smaller element to the left of each element in the array
   vector<int>leftSmaller(vector<int> &arr)
   {
       // Stack to store indices of elements
       stack<int>st;
       
       // Vector to store results
       vector<int>ans(arr.size());
       
       // Iterate over the array from left to right
       for(int i=0;i<arr.size();i++)
       {
           // Pop elements from the stack until we find a smaller element
           while(!st.empty() && arr[st.top()] >= arr[i])
           {
               st.pop();
           }
           
           // If the stack is empty, there is no smaller element on the left; otherwise, get the value of the smaller element
           ans[i] = st.empty() ? 0 : arr[st.top()];
           
           // Push the current element index onto the stack
           st.push(i);
       }
       
       // Return the vector of nearest smaller elements to the left
       return ans;
   }
   
   // Function to find the nearest smaller element to the right of each element in the array
   vector<int>rightSmaller(vector<int> &arr)
   {
       // Stack to store indices of elements
       stack<int>st;
       
       // Vector to store results
       vector<int>ans(arr.size());
       
       // Iterate over the array from right to left
       for(int i=arr.size()-1;i>=0;i--)
       {
           // Pop elements from the stack until we find a smaller element
           while(!st.empty() && arr[st.top()] >= arr[i])
           {
               st.pop();
           }
           
           // If the stack is empty, there is no smaller element on the right; otherwise, get the value of the smaller element
           ans[i] = st.empty() ? 0:arr[st.top()];
           
           // Push the current element index onto the stack
           st.push(i);
       }
       
       // Return the vector of nearest smaller elements to the right
       return ans;
   }
  
    // Function to find the maximum absolute difference between nearest smaller elements on left and right
    int findMaxDiff(vector<int> &arr) {
       // Get the size of the array
       int n = arr.size();
        
       // Get the vectors of nearest smaller elements on the left and right
       vector<int>left = leftSmaller(arr);
       vector<int>right = rightSmaller(arr);
       
       // Variable to store the maximum difference
       int ans = 0;
       
       // Iterate through the array to calculate the maximum difference
       for(int i=0;i<n;i++)
       {
           // Calculate the absolute difference between left and right smaller elements
           ans = max(ans,abs(left[i] - right[i]));
       }
       
       // Return the maximum difference
       return ans;
    }
};

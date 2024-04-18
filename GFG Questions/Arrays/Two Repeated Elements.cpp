***********************************************APPROACH 1st****************************************************

class Solution {// TC--->O(N)       SC--->O(N)
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        
        // Vector to store the result
        vector<int> ans;
        
        // Unordered map to count occurrences of elements
        unordered_map<int,int> ump;
        
        // Count occurrences of elements in the array
        for(int i = 0; i < n + 2; i++) 
        {
            ump[arr[i]]++;
        }
        
        // Iterate through the unordered map
        for(auto it : ump)
            {
            // If an element occurs twice, add it to the result vector
            if(it.second == 2) 
            {
                ans.push_back(it.first);
            }
        }
        
        // Iterate through the array from the end
        for(int i = n + 2; i >= 0; i--) 
        {
            // If the current element matches the first element in the result vector, reverse the vector and return
            if(arr[i] == ans[0]) 
            {
                reverse(ans.begin(), ans.end());
                return ans;
            }
            // If the current element matches the second element in the result vector, return
            if(arr[i] == ans[1])
            {
                return ans;
            }
        }
    }
};

*********************************************APPROACH 2nd******************************************************

  class Solution {// TC--->O(N)        SC--->O(N)
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        
        // Create an unordered map to store the frequency of each element
        unordered_map<int,int> ump;
        
        // Create a vector to store the result
        vector<int> ans;
        
        // Iterate through the array
        for(int i = 0; i < n + 2; i++)
            {
            // Increment the count of the current element in the unordered map
            ump[arr[i]]++;
                
            // If the count of the current element reaches 2, add it to the result vector
            if(ump[arr[i]] == 2) 
            {
                ans.push_back(arr[i]);
            }
        }
        
        // Return the vector containing the two repeated elements
        return ans;
    }
};

  ********************************************APPROACH 3rd*****************************************************

  class Solution {// TC--->O(N)         SC--->O(1)
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        
         // Vector to store the two repeated elements
        vector<int>ans;
        
        // Iterate through the array (n+2 is used to handle the range of indices)
        for(int i=0;i<n+2;i++)
        {
            // Calculate the index by taking the absolute value of the element
            int index = abs(arr[i]);
            
            // Check if the element at the calculated index is negative
            if(arr[index] < 0)
            {
                // If it is negative, it means this element has been encountered before, so it's a duplicate
                // Add the index to the result vector
                ans.push_back(index);
            }
            else
            {
                // If it's positive, mark it as visited by negating its value
                arr[index] *= -1;
            }
        }
        
        // Return the vector containing the two repeated elements
        return ans;
    }
};

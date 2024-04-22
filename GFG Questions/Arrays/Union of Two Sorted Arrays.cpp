***********************************APPROACH 1st(USING UNORDERED SET)***************************************

class Solution {
public:
    // Function to find the union of two arrays
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        
        // Initialize a vector to store the union elements
        vector<int> ans;
        
        // Create an unordered_set using the elements of arr2 to store unique elements
        unordered_set<int> set(arr2, arr2 + m);
        
        // Iterate through each element of arr1
        for(int i = 0; i < n; i++)
        {
            // If the current element of arr1 is not found in the set
            if(set.find(arr1[i]) == set.end())
            {
                // Insert the element into the set
                set.insert(arr1[i]);
            }
        }
        
        // Iterate through each element in the set
        for(auto x : set) 
        {
            // Add the element to the answer vector
            ans.push_back(x);
        }
        
        // Sort the answer vector in ascending order
        sort(ans.begin(), ans.end());
        
        // Return the vector containing the union of arr1 and arr2
        return ans;
    }
};


***************************************APPROACH 2nd(USING MAP)*************************************************

class Solution {// TC--->O(n+m)        SC--->O(n+m)
public:
    // Function to find the union of two arrays
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        
       // Create a map to store the frequency of elements from both arrays
        map<int,int> mp;
        
        // Count the frequency of elements from arr1 and store them in the map
        for(int i = 0; i < n; i++) 
        {
            mp[arr1[i]]++;
        }
        
        // Count the frequency of elements from arr2 and update the map
        for(int i = 0; i < m; i++)
        {
            mp[arr2[i]]++;
        }
        
        // Create a vector to store the union elements
        vector<int> ans;
        
        // Iterate through the map and add keys (elements) to the answer vector
        for(auto x : mp) 
        {
            ans.push_back(x.first);
        }
        
        // Return the vector containing the union of elements from arr1 and arr2
        return ans;
    }
};

**************************************APPROACH 3rd(USING 2 POINTERS)********************************************
class Solution {// TC--->O(n+m)        SC--->O(n+m)
public:
    // Function to find the union of two arrays
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        
      // Define a set to store unique elements
      set<int>set;
      
      // Initialize two pointers i and j to traverse arr1 and arr2 respectively
      int i=0,j=0;
      
      // Iterate until both pointers are within the bounds of their respective arrays
      while(i<n && j<m)
      {
          // If the current element of arr1 is less than or equal to the current element of arr2
          if(arr1[i] <= arr2[j])
          {
              // Insert the current element of arr1 into the set
              set.insert(arr1[i]);
              
              // Move to the next element in arr1
              i++;
          }
          else
          {
              // If the current element of arr2 is less than the current element of arr1
              // Insert the current element of arr2 into the set
              set.insert(arr2[j]);
              
              // Move to the next element in arr2
              j++;
          }
           
      }
       
      // If there are remaining elements in arr1, insert them into the set
      while(i<n)
      {
          set.insert(arr1[i]);
          i++;
      }
       
      // If there are remaining elements in arr2, insert them into the set
      while(j<m)
      {
          set.insert(arr2[j]);
          j++;
      }
       
      // Convert the set to a vector to return the result
      vector<int>ans(set.begin(),set.end());
      return ans;
       
    }
};

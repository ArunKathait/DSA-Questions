******************************************APPROACH 1st**************************************************************
class Solution {// TC--->O(NlogN + M)           SC--->O(N) 
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create an unordered_map to count occurrences of each element in arr1
        unordered_map<int, int> ump;
        for (auto x : arr1)
        {
            ump[x]++;
        }

        // This will store the final sorted result
        vector<int> ans;
        
        // Process elements according to the order specified in arr2
        for (auto it : arr2) 
        {
            // While there are occurrences of the current element in arr1
            while (ump[it] > 0) 
            {
                // Add the element to the result
                ans.push_back(it);
                
                // Decrease the count in the map
                ump[it]--;
            }
            
            // Remove the element from the map once all its occurrences are added
            ump.erase(it);
        }

        // This will store the remaining elements not in arr2
        vector<int> remaining;
        
        // Iterate through the map to get the remaining elements
        for (auto it : ump) 
        {
            // Add each element to the remaining vector according to its count
            while(it.second > 0) 
            {
                remaining.push_back(it.first);
                
                // Decrease the count for each added element
                it.second--;
            }
        }
        
        // Sort the remaining elements in ascending order
        sort(remaining.begin(),remaining.end());
        
       // Append the sorted remaining elements to the result 
        ans.insert(ans.end(),remaining.begin(),remaining.end());

        // Return the final sorted array
        return ans;
    }
};


*********************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(NlogN + M)            SC--->O(N)
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create a map to count occurrences of each element in arr1
        map<int,int>mp;
        for(auto x:arr1)
        {
            mp[x]++;
        }
        
        // Initialize index to keep track of the position in arr1
        int i=0;
        
        // Place elements from arr2 into arr1 in the order they appear in arr2
        for(auto x:arr2)
        {
            // While there are occurrences of the current element in arr1
            while(mp[x] > 0)
            {
                // Place the element in arr1 at index i and increment i
                arr1[i++] = x;
                
                 // Decrease the count in the map
                mp[x]--;
            }
        }
        
        // Place remaining elements that are not in arr2
        for(auto it:mp)
        {
            // Get the count of the current element
            int freq = it.second;
            
            // While there are occurrences of the current element
            while(freq > 0)
            {
                // Place the element in arr1 at index i and increment i
                arr1[i++] = it.first;
                
                // Decrease the count
                freq--;
            }
        }
        
        // Return the sorted arr1
        return arr1;
    }
};

**************************************APPROACH 3rd(LAMBDA)*************************************************

class Solution {// TC--->O(NlogN)                          SC--->O(N)
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create a map to store the order of elements as specified in arr2
        map<int,int>mp;
        
        // Populate the map with elements from arr2, where the value is the index of the element in arr2
        for(int i=0;i<arr2.size();i++)
        {
            mp[arr2[i]] = i;

        }
        
        // For elements in arr1 that are not in arr2, set their value in the map to INT_MAX
        for(auto x:arr1)
        {
            if(!mp.count(x))
            {
                mp[x] = INT_MAX;
            }
        }
        
        // Define a lambda function for custom sorting
        auto lambda = [&](int &num1,int &num2)
        {
            // If both elements have the same value in the map, sort by their value (ascending order)
            if(mp[num1] == mp[num2])
            {
                return num1 < num2;
            }
             
            // Otherwise, sort by their value in the map
            return mp[num1] < mp[num2];
        };
        
        // Sort arr1 using the custom sorting lambda function
        sort(arr1.begin(),arr1.end(),lambda);
            
        // Return the sorted array
        return arr1;
            
    }
};

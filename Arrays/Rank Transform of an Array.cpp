***************************************************APPROACH 1st**********************************************************

class Solution {// TC--->O(NlogN)                     SC--->O(N)
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a set to store unique elements from the array. 
        // This automatically sorts the elements in ascending order.
        set<int>set(arr.begin(),arr.end());
        
        // Create an unordered_map to store the rank for each unique number in the array.
        unordered_map<int,int>numToRank;
        
        // Initialize rank to 1. We will assign ranks starting from 1.
        int rank = 1;
        
        // Iterate through the sorted set. Since sets store elements in sorted order,
        // the smallest number will get rank 1, the next smallest rank 2, and so on.
        for(auto &num:set)
        {
            // Assign the current rank to the number.
            numToRank[num] = rank;
            
            // Increment the rank for the next number.
            rank++;
        }
        
        // Iterate through the original array.
        // Replace each element in the array with its corresponding rank from the map.
        for(int i=0;i<arr.size();i++)
        {
            // Replace the number with its rank.
            arr[i] = numToRank[arr[i]];
        }
        
        // Return the transformed array with ranks instead of original values.
        return arr;
    }
};


***************************************************APPROACH 2nd******************************************************

class Solution {// TC--->O(NLogN)                      SC--->O(N)
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a map to store each unique number in the array as a key
        // and a vector of indices where the number appears as the value.
        map<int,vector<int>>mp;
        
        // Iterate over the array and populate the map.
        // For each element arr[i], store the index 'i' in the vector corresponding to arr[i].
        for(int i=0;i<arr.size();i++)
        {
            // Append index i to the vector associated with arr[i].
            mp[arr[i]].push_back(i);
        }
        
        // Initialize rank to 1. This will be the rank assigned to the smallest unique number.
        int rank = 1;
        
        // Iterate over the map, which is automatically sorted by keys (the array values).
        // 'it' refers to each (key, value) pair, where 'key' is the number in the array,
        // and 'value' is a vector of indices where the number appears in the original array.
        for(auto &it:mp)
        {
            // For each index where the current number appears, assign the rank.
            for(auto &index:it.second)
            {
                // Replace the original number at index with its rank.
                arr[index] = rank;
            }
            
            // Increment rank for the next smallest number.
            rank++;
        }
        
        // Return the transformed array with ranks instead of original values.
        return arr;
    }
};

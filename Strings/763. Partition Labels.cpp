
class Solution {// TC--->O(N)                              SC--->O(N)
public:
    vector<int> partitionLabels(string s) {
        // Length of the string
        int n = s.length();  
        
        // mp will store the last index (position) of each character 'a' to 'z'
        // Since there are 26 lowercase letters, we use a size 26 vector
        vector<int> mp(26, 0);  

        for (int i = 0; i < n; i++) 
        {
            // Store the last occurrence index of each character
            // Example: if s = "abca", then for 'a' -> last index will be 3
            mp[s[i] - 'a'] = i;  
        }

        // This will store the sizes of partitions
        vector<int> ans;  

        // Start index of current partition
        int start = 0;  

        // End index of current partition
        int end = 0;    

        for (int i = 0; i < n; i++) 
        {
            // Expand the current partition's end to cover 
            // the farthest last occurrence of the current character
            end = max(end, mp[s[i] - 'a']);  
    
            if (i == end) 
            {  
                // When current index reaches the partition end
                // It means all characters from 'start' to 'end' 
                // only occur inside this segment
                // Push partition length into result
                ans.push_back(end - start + 1);  
                
                // Move start to next index for new partition
                start = i + 1;  
            }
        }

        return ans;  
        // Return all partition sizes
    }
};

**************************************************APPROACH 1st*******************************************************
class Solution { // TC--->O(M + N)      SC--->O(26) ~ O(1)
public:
    string customSortString(string order, string s) {
        // Initialize a vector to store the count of each character
        // Assuming lowercase English letters, hence size 26
        vector<int>count(26,0);
    
        // Count occurrences of each character in s
        for(auto x:s)
        {
            // Increment count for the character at x
            count[x - 'a']++;
        }
        
        // Initialize an empty string to store the sorted result
        string ans;
        
        // Iterate through each character in the specified order
        for(auto ch:order)
        {
            // Append characters from s according to the specified order
            while(count[ch - 'a']--)
            {
                // Append the character ch to the result string
                ans += ch;
            }
        }
        
        // Append characters from s that were not present in the order string
        for(auto it:s)
        {
            if(count[it - 'a'] > 0)
            {
                // Append the character it to the result string
                ans += it;
            }
        }
        
        // Return the final sorted string
        return ans;
    }
};

****************************************************APPROACH 2nd********************************************************
  class Solution {// TC--->O(N*LOGN)          SC--->O(26) ~ O(1)
public:
    string customSortString(string order, string s) {
        
        // Initialize a vector to store the index of each character in the order string
        // Initialize all indices to -1
        vector<int>count(26,-1);
        
        // Assign indices of characters based on their positions in the order string
        for(int i=0;i<order.size();i++)
        {
            char ch = order[i];
            
            // Map character to its position in order string
            count[ch - 'a'] = i;
        }
        
         // Define a custom comparison function using lambda expression
        auto myComp = [&count](char &ch1,char &ch2)
        {
            // Compare characters based on their indices in the order string
            return count[ch1 - 'a'] < count[ch2 - 'a'];
        };
        
        // Sort string s based on the custom comparison function
        sort(s.begin(),s.end(),myComp);
        
        // Return the sorted string
        return s;
    }
};

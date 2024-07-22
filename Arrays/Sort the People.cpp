****************************************APPROACH 1st*********************************************************

class Solution {// TC--->O(NlogN)                   SC--->O(N)
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of pairs to store heights and corresponding names
        vector<pair<int,string>>vec;
        
        for(int i=0;i<heights.size();i++)
        {
            // Push each height and name pair into the vector
            vec.push_back({heights[i],names[i]});
        }
        
        // Sort the vector of pairs in descending order based on heights
        sort(vec.begin(),vec.end(),greater<>());
        
        // Create a vector to store the sorted names
        vector<string>ans;
        
        // Extract the names from the sorted vector of pairs
        for(auto x:vec)
        {
            ans.push_back(x.second);
        }
        
        // Return the sorted names
        return ans;
    }
};

/*
NOTE:  If we have pair then we have to sort on both basis int or string then we write
       greater<>() like this.We do not pass int inside it because we have to sort on both basis 
       i.e(string,int).
           
*/

*****************************************APPROACH 2nd**********************************************************


class Solution {// TC--->O(NlogN)                   SC--->O(N)
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of pairs to store heights and corresponding names
        vector<pair<int,string>>vec;
        
        for(int i=0;i<heights.size();i++)
        {
            // Push each height and name pair into the vector
            vec.push_back({heights[i],names[i]});
        }
        
        // Sort the vector of pairs in descending order based on heights
        sort(vec.rbegin(),vec.rend());
        
        // Create a vector to store the sorted names
        vector<string>ans;
        
        // Extract the names from the sorted vector of pairs
        for(auto x:vec)
        {
            ans.push_back(x.second);
        }
        
        // Return the sorted names
        return ans;
    }
};


class Solution {// TC ---> O(n * m * L)                               SC ---> O(1)
public:

    // Function to check if two strings differ by at most 2 positions
    bool isValid(string &str1, string &str2)
    {
        int diff = 0; // counts number of different positions

        // Traverse both strings character by character
        for(int i = 0; i < str1.size(); i++)
        {
            // If characters at same index are different
            if(str1[i] != str2[i])
            {
                diff++; // increase difference count

                // If more than 2 differences → not valid
                if(diff > 2)
                {
                    return false; // early exit (optimization)
                }
            }
        }

        // If differences are ≤ 2 → valid pair
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector<string> ans; // to store final valid queries

        // Loop through each query word
        for(auto &q : queries)
        {
            // Compare with every word in dictionary
            for(auto &d : dictionary)
            {
                // Check if q and d differ by at most 2 characters
                if(isValid(q, d))
                {
                    ans.push_back(q); // add query to answer
                    
                    break; 
                    // IMPORTANT: stop checking further dictionary words
                    // because we only need ONE valid match
                }
            }
        }

        // Return all valid queries
        return ans;
    }
};

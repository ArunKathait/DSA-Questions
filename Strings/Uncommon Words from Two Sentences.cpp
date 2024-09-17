
class Solution {// TC--->O(N + M)                      SC--->O(N + M)
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // A map to store the frequency of each word.
        unordered_map<string,int>ump;
        
        // A vector to store the final result of uncommon words.
        vector<string>ans;
        
        // A string to build each word from the sentences.
        string str = "";
        
        // Process the first sentence (s1) to extract words and count their occurrences.
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i] != ' ')
            {
                // If the current character is not a space, add it to the current word (str).
                str += s1[i];
            }
            else 
            {
                 // If a space is encountered, the current word (str) is completed.
                // Increment the count of the word in the map.
                ump[str]++;
                
                // Reset the word string (str) for the next word.
                str = "";
            }     
        }
        
        // After the loop ends, add the last word in s1 to the map (since it doesn't end with a space).
        ump[str]++;
        
        // Reset the string `str` to process the second sentence (s2).
        str = "";
        for(int i=0;i<s2.length();i++)
        {
            if(s2[i] != ' ')
            {
                // If the current character is not a space, add it to the current word (str).
                str += s2[i];
            }
            else
            {
                // If a space is encountered, the current word (str) is completed.
                // Increment the count of the word in the map.
                ump[str]++;
                
                // Reset the word string (str) for the next word.
                str = "";
            }
        }
        
        // After the loop ends, add the last word in s2 to the map (since it doesn't end with a space).
        ump[str]++;
        
        
        // Iterate over the map to find words that appear exactly once.
        for(auto &it:ump)
        {
            if(it.second == 1)
            {
                // If a word's count is 1, it's uncommon, so add it to the result vector `ans`.
                ans.push_back(it.first);
            }
        }
        
        // Return the final list of uncommon words.
        return ans;
    }
};

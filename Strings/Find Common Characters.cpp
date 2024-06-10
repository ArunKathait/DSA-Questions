
class Solution {// TC--->O(N)                      SC--->O(N)
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize a frequency vector to store the minimum frequency of each character across all words.
        vector<int>freq(26,0);
        
        // Fill the frequency vector with the character counts from the first word.
        for(auto x:words[0])
        {
            // Increment the count of the character in the frequency vector.
            freq[x - 'a']++;
        }
        
        // Loop through the rest of the words to adjust the frequency vector.
        for(int i=1;i<words.size();i++)
        {
            // Create a temporary frequency vector for the current word.
            vector<int>temp(26,0);
            
            // Fill the temporary vector with the character counts from the current word.
            for(auto x:words[i])
            {
                // Increment the count of the character in the temporary vector.
                temp[x - 'a']++;
            }
            
            // Update the main frequency vector to keep the minimum frequency of each character.
            for(int j=0;j<26;j++)
            {
                // Keep the minimum frequency between the current and temporary vectors.
                freq[j] = min(freq[j],temp[j]);
            }
        }
        
        // Prepare the result vector to store common characters.
        vector<string>ans;
        for(int i=0;i<26;i++)
        {
            // Add the character to the result vector based on its minimum frequency across all words.
            while(freq[i]--)
            {
                // Convert the character index back to a character and add to the result.
                ans.push_back(string(1,i + 'a'));
            }
        }
        
        // Return the result vector containing common characters.
        return ans;
    }
};

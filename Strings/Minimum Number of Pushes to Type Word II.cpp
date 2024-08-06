
class Solution {// TC--->O(N)                   SC--->O(26)
public:
    int minimumPushes(string word) {
        
        // Create a vector to store the frequency of each letter (26 letters in the alphabet)
        vector<int>mp(26);
        
        // Iterate over each character in the word
        for(auto x:word)
        {
            // Increment the count for the corresponding letter
            mp[x - 'a']++;
        }
        
        // Sort the frequencies in descending order
        sort(mp.begin(),mp.end(),greater<int>());
        
        // Initialize the answer (total pushes) to 0
        int ans = 0;
        
        // Iterate over the sorted frequencies
        for(int i=0;i<26;i++)
        {
            // Get the frequency of the current letter
            int freq = mp[i];
            
            // Determine the number of key presses required for the letter
            int press = i/8 + 1;
            
            // Multiply the frequency by the number of presses and add to the total
            ans += freq * press;
        }
        
        // Return the total number of pushes required
        return ans;
        
    }
};

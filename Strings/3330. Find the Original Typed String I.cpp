
class Solution {// TC--->O(N)                                SC--->O(1)
public:
    int possibleStringCount(string word) {
        // Get the length of the input string
        int n = word.size();

        // Initialize the answer to 1 (minimum one group or count)
        int ans = 1;

        // Iterate through the string starting from the second character
        for(int i = 1; i < n; i++)
        {
            // If the current character is the same as the previous one,
            // it means there is a repetition and a new possible string
            if(word[i] == word[i - 1])
            {
                // Increment the count
                ans++; 
            }
        }

        // Return the total count of possible strings (based on adjacent repetitions)
        return ans;
    }
};

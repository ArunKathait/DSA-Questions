
class Solution {// TC ---> O(N)                                   SC ---> O(1)
public:
    int characterReplacement(string s, int k) {

        // Length of the string
        int n = s.length();

        // Frequency array for storing count of A-Z characters
        vector<int> freq(26, 0);

        // Left and right pointers of the sliding window
        int left = 0;
        int right = 0;

        // Stores the maximum frequency of any character
        // inside the current window
        int maxFreq = 0;

        // Stores the maximum valid window size
        int ans = 0;

        // Expand the window by moving the right pointer
        while (right < n) {

            // Include the current character in the window
            freq[s[right] - 'A']++;

            // Update the highest occurring character count
            // Example:
            // Window = "AAB"
            // A = 2, B = 1
            // maxFreq = 2
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Current window size
            // = right - left + 1

            // Characters that need to be replaced
            // = window size - frequency of most common character
            //
            // Example:
            // Window = "AABAB"
            // A = 3, B = 2
            //
            // Window size = 5
            // maxFreq = 3
            //
            // Replacements needed = 5 - 3 = 2
            //
            // If replacements exceed k,
            // shrink the window from the left.
            while ((right - left + 1) - maxFreq > k) {

                // Remove the left character from the window
                freq[s[left] - 'A']--;

                // Move left pointer
                left++;
            }

            // Current window is valid,
            // so update the maximum answer
            ans = max(ans, right - left + 1);

            // Expand the window
            right++;
        }

        return ans;
    }
};


class Solution {// TC ---> O(log n)                                   SC ---> O(1)
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        // Total number of characters in the array
        int n = letters.size();

        // Binary search boundaries
        int low = 0;
        int high = n - 1;

        // Default answer:
        // If no character is greater than target,
        // we return the first character (circular condition)
        char ans = letters[0];

        // Standard binary search loop
        while (low <= high) 
        {
            // Find middle index safely
            int mid = low + (high - low) / 2;

            // If current character is strictly greater than target
            if (letters[mid] > target) 
            {
                // This is a potential answer
                ans = letters[mid];

                // Try to find a smaller valid character on the left
                high = mid - 1;
            }
            else 
            {
                // Current character is <= target,
                // so the answer must be on the right side
                low = mid + 1;
            }
        }

        // Return the smallest character greater than target
        // If none exists, returns letters[0] (wrap-around)
        return ans;
    }
};

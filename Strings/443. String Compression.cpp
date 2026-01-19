
class Solution {// TC ---> O(N)                         SC ---> O(1)
public:
    int compress(vector<char>& chars) {

        // Total number of characters in the array
        int n = chars.size();

        // i → pointer to read characters
        int i = 0;

        // index → pointer to write compressed result
        int index = 0;

        // Traverse the entire array
        while (i < n) 
        {
            // Store the current character
            char currentChar = chars[i];

            // Count how many times currentChar repeats
            int count = 0;

            // Count consecutive occurrences of currentChar
            while (i < n && chars[i] == currentChar) 
            {
                count++;   // increase count
                i++;       // move read pointer forward
            }

            // Write the character to the compressed position
            chars[index] = currentChar;
            index++;

            // If character appears more than once
            if (count > 1) 
            {

                // Convert count to string (e.g., 12 → "12")
                string CountString = to_string(count);

                // Write each digit of count separately
                for (auto &ch : CountString) 
                {
                    chars[index] = ch;
                    index++;   // move write pointer
                }
            }
        }

        // index represents the new length of compressed array
        return index;
    }
};

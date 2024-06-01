
class Solution {//TC--->O(N)                   SC--->O(1)
  public:
    string oddEven(string s) {
        // Create an unordered map to count the frequency of each character in the string
        unordered_map<int,int>ump;
        
        // Loop through each character in the string
        for(int i=0;i<s.length();i++)
        {
            // Convert the character to an integer representing its position in the alphabet (1 for 'a', 2 for 'b', etc.)
            // and increment the corresponding count in the unordered map
            ump[s[i] - 'a' + 1]++;
        }
        
        // Initialize counters for even-positioned characters with even frequency and odd-positioned characters with odd frequency
        int x = 0,y = 0;
        
        // Iterate through the unordered map
        for(auto it:ump)
        {
            // Check if the character's position is even and its frequency is even
            if(it.first%2 == 0 && it.second%2 == 0)
            {
                // Increment the counter for even-positioned characters with even frequency
                x++;
            }
            // Check if the character's position is odd and its frequency is odd
            else if(it.first%2 != 0 && it.second%2 != 0)
            {
                // Increment the counter for odd-positioned characters with odd frequency
                y++;
            }
        }
        // Return "EVEN" if the sum of x and y is even, otherwise return "ODD"
        return (x+y)%2 == 0 ?"EVEN" : "ODD";
    }
};

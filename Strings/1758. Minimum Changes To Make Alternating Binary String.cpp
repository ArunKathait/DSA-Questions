
class Solution {// TC ---> O(N)                            SC ---> O(1)
public:
    int minOperations(string s) {

        // Length of the string
        int n = s.length();

        // Count operations if we want pattern starting with '0'
        // Example expected pattern: 010101...
        int start_with_0 = 0;

        // Count operations if we want pattern starting with '1'
        // Example expected pattern: 101010...
        int start_with_1 = 0;

        // Traverse the entire string
        for(int i = 0; i < n; i++)
        {
            // If index is even
            if(i % 2 == 0)
            {
                // For pattern starting with '0'
                // Even index should contain '0'
                if(s[i] != '0')
                {
                    // If not '0', we need one operation to change it
                    start_with_0++;   
                }
                else
                {
                    // If it is already '0', then for pattern starting with '1'
                    // it should be '1', so we count operation for that case
                    start_with_1++;
                }
            }

            // If index is odd
            else
            {
                // For pattern starting with '0'
                // Odd index should contain '1'
                if(s[i] != '1')
                {
                    // If not '1', we need an operation
                    start_with_0++;
                }
                else
                {
                    // If it is already '1', then for pattern starting with '1'
                    // it should be '0', so count operation for that case
                    start_with_1++;
                }

            }
        }

        // Return minimum operations between both possible patterns
        return min(start_with_0, start_with_1);
    }
};

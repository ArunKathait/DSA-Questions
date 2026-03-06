****************************************************************APPROACH 1st*************************************************************************

class Solution {// TC ---> O(N)                               SC ---> O(1)
public:
    bool checkOnesSegment(string s) {

        int n = s.length();   // length of the binary string

        int count = 0;        // this will count how many segments of '1' exist
        
        int i = 0;            // pointer to traverse the string

        while(i < n)          // traverse the entire string
        {
            // If we encounter '1', it means a new segment of 1's starts
            if(s[i] == '1')
            {
                count++;      // increase segment count

                // move forward until the entire continuous segment of '1's ends
                while(i < n && s[i] == '1')
                {
                    i++;      // skip all consecutive '1's
                }
            }
            else
            {
                // if current character is '0', just move to next index
                i++;
            }
        }

        // if more than one segment of '1' exists → return false
        // otherwise return true
        return count > 1 ? false : true;
    }
};

*****************************************************************APPROACH 2nd************************************************************************

class Solution {// TC ---> O(N)                                  SC ---> O(1)
public:
    bool checkOnesSegment(string s) {

        // Find the length of the string (not really needed here,
        // but often used in string traversal problems)
        int n = s.length();

        // We check if the substring "01" exists in the string.
        // s.find("01") returns:
        // - the index where "01" first appears
        // - string::npos if "01" is not present

        // If "01" is present, it means:
        // there is a transition from 0 → 1 later in the string,
        // which indicates the start of another segment of '1's.
        // Example: "11011"
        //            ↑
        //           "01" → new segment of '1'

        if(s.find("01") != string::npos)
        {
            // If "01" exists, there are multiple segments of '1'
            return false;
        }

        // If "01" does not exist, all '1's are in one continuous segment
        // Example: "111000" or "000111" or "111"
        return true;
    }
};

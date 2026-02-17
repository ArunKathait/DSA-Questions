
class Solution {// TC ---> O(1) ~ fixed 12×60 iterations                  SC ---> O(1)
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
        // This vector will store all valid time strings (e.g., "3:25")
        vector<string> ans;

        // Loop through all possible hours (0 to 11 for a binary watch)
        for(int HH = 0; HH <= 11; HH++)
        {
            // Loop through all possible minutes (0 to 59)
            for(int MM = 0; MM <= 59; MM++)
            {
                /*
                    __builtin_popcount(x) returns the number of set bits (1s)
                    in the binary representation of x.

                    Example:
                    HH = 3  -> binary 0011 -> popcount = 2
                    MM = 5  -> binary 0101 -> popcount = 2
                    Total LEDs ON = 2 + 2 = 4
                */

                // Check if total ON LEDs equals the given 'turnedOn'
                if(__builtin_popcount(HH) + __builtin_popcount(MM) == turnedOn)
                {
                    // Convert hour to string (no leading zero needed)
                    string hour = to_string(HH);

                    /*
                        Convert minute to string.
                        If minute < 10, add a leading '0'
                        Example:
                        MM = 5  -> "05"
                        MM = 15 -> "15"
                    */
                    string minute = (MM < 10 ? "0" : "") + to_string(MM);

                    // Combine hour and minute in "HH:MM" format
                    ans.push_back(hour + ":" + minute);
                }
            }
        }

        // Return all valid time combinations
        return ans;
    }
};

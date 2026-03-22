
class Solution {// TC ---> O(1)                                    SC ---> O(1)
public:

    // Function to check if a substring is a valid IP segment
    bool isValid(string str)
    {
        // If the segment starts with '0', reject it
        // (NOTE: this also rejects "0", which is actually valid in IP)
        if(str[0] == '0')
        {
            return false;
        }

        // Convert string to integer
        int num = stoi(str);

        // Check if value is within valid IP range (0–255)
        if(num >= 0 && num <= 255)
        {
            return true;
        }
        return false;
    }

    // Recursive function to build IP addresses
    void solve(int index, int n, int parts, string current,vector<string>& ans, string &s)
    {
        // ✅ Base Case:
        // If we used all characters and formed exactly 4 parts
        if(index == n && parts == 4)
        {
            current.pop_back();      // remove last '.'
            ans.push_back(current);  // store valid IP
            return;
        }
        
        // 🔹 Try taking 1 digit
        if(index + 1 <= n)
        {
            string part = s.substr(index, 1); // take 1 character

            // Single digit (0–9) is always valid
            solve(index + 1, n, parts + 1,current + part + ".", ans, s);
        }

        // 🔹 Try taking 2 digits
        if(index + 2 <= n)
        {
            string part = s.substr(index, 2); // take 2 characters

            // Check if valid (no leading zero, <=255)
            if(isValid(part))
            {
                solve(index + 2, n, parts + 1,current + part + ".", ans, s);
            }
        }

        // 🔹 Try taking 3 digits
        if(index + 3 <= n)
        {
            string part = s.substr(index, 3); // take 3 characters

            // Validate the segment
            if(isValid(part))
            {
                solve(index + 3, n, parts + 1,current + part + ".", ans, s);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();

        // If string length > 12, cannot form valid IP
        // (since max 4 parts × 3 digits = 12)
        if(n > 12)
        {
            return {};
        }

        vector<string> ans;   // stores final IP addresses
        string current;       // current IP being formed
        int parts = 0;        // number of parts used so far

        // Start recursion from index 0
        solve(0, n, parts, current, ans, s);

        return ans;
    }
};

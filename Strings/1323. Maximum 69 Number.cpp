
class Solution {// TC--->O(d)                          SC--->O(d)--->where d = number of digits in num
public:
    int maximum69Number (int num) {
        // Convert the integer 'num' into a string 
        // so that we can manipulate its digits individually.
        string str = to_string(num);

        // Get the length of the string representation of the number.
        int n = str.length();

        // Traverse through each digit of the number (from left to right).
        for(int i = 0; i < n; i++)
        {
            // If we find the first digit that is '6',
            // change it to '9' (because that maximizes the number).
            if(str[i] == '6')
            {
                str[i] = '9';
                
                // After changing the first '6' to '9',
                // break out of the loop because only one change is allowed.
                break;
            }
        }

        // Convert the modified string back into an integer and return it.
        return stoi(str);
    }
};

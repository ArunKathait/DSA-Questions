***********************************************APPROACH 1st(USING STRING)**********************************************
class Solution {// TC--->O(N)        SC--->O(N)
public:
    string removeKdigits(string num, int k) {
        
        // Initialize an empty string to store the resulting number
        string ans;
        
        // Iterate through each digit in the input string 'num'
        for(auto x:num)
        {
            // While the ans string is not empty, the last digit in the ans is greater than the current digit 'x', 
            // and we still have remaining removals 'k'
            while(ans.length() > 0 && ans.back() > x && k > 0)
            {
                // Remove the last digit from the ans string
                ans.pop_back();
                
                // Decrement 'k' to track the number of removals
                k--;
            }
            
            // If the ans string is not empty or the current digit is not '0', add the current digit to the ans
            if(ans.length() > 0 || x != '0')
            {
                ans.push_back(x);
            }
        }
        
        // After processing all digits, if there are still removals remaining, remove digits from the end of the ans string
        // Ex--->"12345" and k = 5 
        while(ans.length() > 0 && k > 0)
        {
            ans.pop_back();
            k--;
        }
        
        // If the ans string is empty, return "0"
        // Ex--->"10"  k = 2 we return "0"
        if(ans == "")
        {
            return "0";
        }
        
        // Otherwise, return the ans string
        return ans;
    }
};

***********************************************APPROACH 2nd(USING STACK)***********************************************
class Solution {// TC--->O(N)           SC--->O(N)
public:
    string removeKdigits(string num, int k) {
        
        // Create a stack to store the digits
        stack<char>st;
        
        // Iterate through each digit in the input string 'num'
        for(auto x:num)
        {
            // While the stack is not empty, the top element is greater than the current digit,
            // and we still have remaining removals 'k'
            while(!st.empty()  && st.top() > x && k > 0)
            {
                // Pop the top element of the stack
                st.pop();
                
                // Decrement 'k' to track the number of removals
                k--;
            }
            
            // If the stack is not empty or the current digit is not '0', push the current digit onto the stack
            if(!st.empty() || x != '0')
            {
                st.push(x);
            }
        }
        
       // After processing all digits, if there are still removals remaining, pop elements from the stack
       // Ex--->"12345" and k = 5  
        while(!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }
        
        // If the stack is empty, return "0" (indicating that no digits are left)
        // Ex--->"10"  k = 2 we return "0"
        if(st.empty())
        {
            return "0";
        }
        
        // Otherwise,construct the resulting string by popping digits from the stack and appending them to 'ans'
        string ans;
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        // Reverse 'ans' to obtain the correct order of digits
        reverse(ans.begin(),ans.end());
        
        // Return the resulting string
        return ans;
    }
};

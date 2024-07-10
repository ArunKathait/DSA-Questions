*************************************************APPROACH 1st*********************************************************

class Solution {// TC--->O(N)                    SC--->O(1)
public:
    int minOperations(vector<string>& logs) {
        // Initialize the current depth to 0
        int depth = 0;
        
        // Iterate through each log entry in the logs vector
        for(auto x:logs)
        {
            // If the log entry is "../", move one level up in the directory
            if(x == "../")
            {
                // Decrease depth by 1 but ensure it doesn't go below 0
                depth = max(0,depth - 1);
            }
            // If the log entry is "./", it means stay in the current directory, so do nothing
            else if(x == "./")
            {
                // Skip to the next log entry
                continue;
            }
            // For any other log entry, it means moving into a subdirectory
            else
            {
                // Increase the depth by 1
                depth++;
            }
        }
        
        // Return the final depth, which represents the minimum operations needed to reach the main folder
        return depth;
    }
};

************************************************APPROACH 2nd(USING STACK)********************************************

class Solution {// TC--->O(N)                    SC--->O(N)
public:
    int minOperations(vector<string>& logs) {
        // Create a stack to keep track of the current directory depth
        stack<string>st;
        
        // Iterate through each log entry in the logs vector
        for(auto x:logs)
        {
            // If the log entry is "../", it means moving up one directory
            if(x == "../")
            {
                // Only pop from the stack if it is not empty (i.e., we're not at the main folder)
                if(!st.empty())
                {
                    st.pop();
                }
            }
            // If the log entry is not "./" (stay in the current directory), it means moving into a subdirectory
            else if(x != "./")
            {
                // Push the current directory into the stack
                st.push(x);
            }
        }
        // The size of the stack represents the current depth
        return st.size();
    }
};

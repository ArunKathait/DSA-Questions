**********************************************APPROACH 1st(USING STACK)**********************************************

class Solution {// Time: O(n)                                        Space: O(n)
public:
    string simplifyPath(string path) {

        // 'token' will store each directory name
        // obtained after splitting the path using '/'
        string token;

        // stringstream helps us split the path
        // Example: "/a/b/c" -> "a", "b", "c"
        stringstream ss(path);

        // Stack is used to maintain the valid directory path
        stack<string> st;

        // Read the path one token at a time, separated by '/'
        while (getline(ss, token, '/'))
        {
            // If token is empty:
            //   Example: "//" creates an empty token
            //
            // If token is ".":
            //   It means current directory, so we don't need
            //   to make any change.
            if (token == "." || token == "")
            {
                continue;
            }

            // ".." means go to the parent directory.
            // Therefore, remove the most recently added directory.
            else if (token == "..")
            {
                // We can only go back if there is a directory
                // currently present in the stack.
                if (!st.empty())
                {
                    st.pop();
                }
            }

            // This is a normal directory name.
            // Store it in the stack.
            else
            {
                st.push(token);
            }
        }

        // If the stack is empty, it means we are at the root "/".
        if (st.empty())
        {
            return "/";
        }

        // Build the final simplified path.
        string ans;

        // Stack gives elements from the last directory to the first,
        // so we add each directory at the FRONT of the answer.
        while (!st.empty())
        {
            ans = '/' + st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

/* 

┌──────────────────────────────────────────┐
│          SIMPLIFY PATH - STACK           │
├──────────────────────────────────────────┤
│                                          │
│ Split path using '/'                     │
│                                          │
│ ""       → IGNORE                        │
│ "."      → IGNORE                        │
│ ".."     → POP                           │
│ directory → PUSH                         │
│                                          │
│ Finally:                                 │
│ Build answer from stack                  │
│                                          │
│ Example:                                 │
│ /a/b/../c                                │
│                                          │
│ a → PUSH                                 │
│ b → PUSH                                 │
│ .. → POP b                               │
│ c → PUSH                                 │
│                                          │
│ Answer = /a/c                            │
│                                          │
│ Time  : O(n)                             │
│ Space : O(n)                             │
└──────────────────────────────────────────┘

*/

*************************************************APPROACH 2nd(VECTOR AS STACK)****************************************

class Solution {// Time: O(n)                                        Space: O(n)
public:
    string simplifyPath(string path) {

        // 'token' will store each part/directory of the path
        string token;

        // stringstream is used to split the path using '/'
        // Example: "/home/user" -> "home", "user"
        stringstream ss(path);

        // Vector is used as a stack to store valid directory names
        vector<string> vec;

        // Read the path one token at a time, using '/' as delimiter
        while (getline(ss, token, '/'))
        {
            // Empty token can occur because of:
            //   "/" or "//"
            //
            // "." means current directory, so it has no effect.
            if (token == "." || token == "")
            {
                continue;
            }

            // ".." means go to the parent directory.
            // So we remove the most recently added directory.
            else if (token == "..")
            {
                // Only pop if there is a directory to go back from.
                if (!vec.empty())
                {
                    vec.pop_back();
                }
            }

            // This is a normal directory name.
            // Add it to the vector.
            else
            {
                vec.push_back(token);
            }
        }

        // If there are no directories left,
        // the simplified path is the root directory "/".
        if (vec.empty())
        {
            return "/";
        }

        // Build the final simplified path.
        string ans;

        // Traverse all valid directories in their original order.
        for (auto &token : vec)
        {
            // Add '/' before every directory.
            //
            // Example:
            // vec = {"home", "user", "docs"}
            //
            // ans becomes:
            // "/home"
            // "/home/user"
            // "/home/user/docs"
            ans += "/" + token;
        }

        return ans;
    }
};

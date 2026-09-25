***********************************************APPROACH 1st(DFS)*********************************************************

class Solution {// Time Complexity  = O(n log n)                Space Complexity = O(n)
public:

    // DFS function
    //
    // row = current level/depth of the node
    // col = horizontal distance from the root
    //
    // We store:
    // {column, row, value}
    //
    // Example:
    // root at (row = 0, col = 0), value = 5
    // stored as {0, 0, 5}
    void dfs(TreeNode *root, int row, int col, vector<tuple<int, int, int>>& nodes)
    {
        // Base case:
        // If there is no node, stop the recursion.
        if(root == NULL)
        {
            return;
        }

        // Store the current node.
        //
        // We intentionally store column first because
        // we want sorting to happen primarily by column.
        //
        // {column, row, value}
        nodes.push_back({col, row, root->val});

        // Move to the left child.
        //
        // Going left:
        // row increases by 1
        // column decreases by 1
        dfs(root->left, row + 1, col - 1, nodes);

        // Move to the right child.
        //
        // Going right:
        // row increases by 1
        // column increases by 1
        dfs(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        // This vector will contain information about
        // every node in the tree.
        //
        // Each tuple contains:
        // {column, row, value}
        vector<tuple<int, int, int>> nodes;

        // Start DFS from the root.
        //
        // Root is at:
        // row = 0
        // column = 0
        dfs(root, 0, 0, nodes);

        // Sort tuples automatically in this order:
        //
        // 1. column
        // 2. row
        // 3. value
        //
        // This is because C++ tuple comparison
        // is lexicographical.
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        // Keep track of the previous column.
        //
        // INT_MIN is used initially because it cannot
        // normally be a column value of the tree.
        int previousColumn = INT_MIN;

        // Process every sorted tuple.
        //
        // col   = horizontal distance
        // row   = level
        // value = node value
        for(auto &[col, row, value] : nodes)
        {
            // If this is a new column,
            // create a new vector for that column.
            if(previousColumn != col)
            {
                ans.push_back({});

                // Update the current column.
                previousColumn = col;
            }

            // Add the node value to the current column.
            ans.back().push_back(value);
        }

        return ans;
    }
};

***************************************************APPROACH 2nd(USING VECTOR)******************************************

class Solution {// Time  → O(n log n)                           Space → O(n)
public:

    // DFS function
    //
    // row = current level/depth of the node
    // col = horizontal distance from the root
    //
    // nodes stores information about every node as:
    // {column, row, value}
    void dfs(TreeNode* root, int row, int col, vector<vector<int>>& nodes)
    {
        // Base case:
        // If there is no node, stop the recursion.
        if(root == NULL)
        {
            return;
        }

        // Store the current node's information.
        //
        // We store column first because the final answer
        // needs columns from left to right.
        //
        // Example:
        // {0, 2, 5}
        //  ↓  ↓  ↓
        // col row value
        nodes.push_back({col, row, root->val});

        // Move to the left child.
        //
        // Going one level down:
        // row + 1
        //
        // Going left:
        // col - 1
        dfs(root->left, row + 1, col - 1, nodes);

        // Move to the right child.
        //
        // Going one level down:
        // row + 1
        //
        // Going right:
        // col + 1
        dfs(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        // Store information about every node.
        //
        // Each element contains:
        // {column, row, value}
        vector<vector<int>> nodes;

        // Root starts at:
        // row = 0
        // col = 0
        dfs(root, 0, 0, nodes);

        // Sort the nodes.
        //
        // vector<int> is sorted lexicographically.
        //
        // Therefore sorting happens in this order:
        //
        // 1. column
        // 2. row
        // 3. value
        //
        // Example:
        //
        // {0, 2, 4}
        // {0, 2, 1}
        //
        // becomes:
        //
        // {0, 2, 1}
        // {0, 2, 4}
        //
        // because column and row are same,
        // so value is used as the tie-breaker.
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        // Store the previous column.
        //
        // INT_MIN is used initially because
        // no column has been processed yet.
        int previousColumn = INT_MIN;

        // Traverse all nodes after sorting.
        for(auto& node : nodes)
        {
            // node[0] = column
            // node[1] = row
            // node[2] = value
            int col = node[0];
            int row = node[1];
            int value = node[2];

            // If the column is different from the previous
            // column, we have found a new vertical column.
            if(col != previousColumn)
            {
                // Create a new vector for this column.
                ans.push_back({});

                // Update previous column.
                previousColumn = col;
            }

            // Add the node's value to the current column.
            //
            // ans.back() refers to the most recently
            // created column.
            ans.back().push_back(value);
        }

        return ans;
    }
};

/*

┌────────────────────────────────────────┐
│       LC 987 — DFS + Vector            │
├────────────────────────────────────────┤
│ Store each node as:                    │
│ {column, row, value}                   │
│                                        │
│ vector<vector<int>> nodes;             │
│                                        │
│ DFS:                                   │
│ Left  → row+1, col-1                   │
│ Right → row+1, col+1                   │
│                                        │
│ Store:                                 │
│ nodes.push_back({col,row,root->val});  │
│                                        │
│ Sort:                                  │
│ column → row → value                   │
│                                        │
│ Iterate vector:                        │
│ for(auto& node : nodes)                │
│ {                                      │
│     int col   = node[0];               │
│     int row   = node[1];               │
│     int value = node[2];               │
│ }                                      │
│                                        │
│ TC → O(n log n)                        │
│ SC → O(n)                              │
└────────────────────────────────────────┘

*/

*********************************************APPROACH 3rd(BFS)********************************************************

class Solution {// TC = O(n log n)                      SC = O(n)
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        // If tree is empty, there is nothing to traverse
        if(root == nullptr)
        {
            return {};
        }

        // We store every node as:
        // {column, row, value}
        //
        // Example:
        // {0, 0, 1} -> root node with value 1
        // {-1, 1, 2} -> left child
        // {1, 1, 3} -> right child
        vector<vector<int>> nodes;

        // Queue stores:
        // {TreeNode*, {row, column}}
        //
        // We need row and column along with the node
        // because vertical traversal depends on their positions.
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Root starts at:
        // row = 0
        // column = 0
        q.push({root, {0, 0}});

        // Perform BFS
        while(!q.empty())
        {
            // Get the front element from the queue
            auto front = q.front();
            q.pop();

            // Extract the current node
            TreeNode* node = front.first;

            // Extract its row and column
            int row = front.second.first;
            int col = front.second.second;

            // Store the node as:
            // {column, row, value}
            //
            // We intentionally store column first
            // because our final sorting should be:
            // column -> row -> value
            nodes.push_back({col, row, node->val});

            // ---------------- LEFT CHILD ----------------

            if(node->left)
            {
                // Moving to the left child:
                //
                // Row increases by 1
                // Column decreases by 1
                //
                // Example:
                // Current = (row=0, col=0)
                // Left    = (row=1, col=-1)

                q.push({node->left, {row + 1, col - 1}});
            }

            // ---------------- RIGHT CHILD ----------------

            if(node->right)
            {
                // Moving to the right child:
                //
                // Row increases by 1
                // Column increases by 1
                //
                // Example:
                // Current = (row=0, col=0)
                // Right   = (row=1, col=1)

                q.push({node->right, {row + 1, col + 1}});
            }
        }

        // Sort every node using vector's lexicographical ordering.
        //
        // Since each element is:
        // {column, row, value}
        //
        // sort() automatically sorts by:
        //
        // 1. column
        // 2. row
        // 3. value
        //
        // This exactly matches the requirement of LC 987.
        sort(nodes.begin(), nodes.end());

        // Final answer
        //
        // Each inner vector represents one vertical column.
        vector<vector<int>> ans;

        // Keep track of the previous column
        //
        // INT_MIN is used initially because no column
        // has been processed yet.
        int prevCol = INT_MIN;

        // Traverse all sorted nodes
        for(auto& node : nodes)
        {
            // Extract:
            // node[0] = column
            // node[1] = row
            // node[2] = value
            int col = node[0];
            int row = node[1];
            int val = node[2];

            // If this is a new column,
            // create a new vector in the answer.
            if(prevCol != col)
            {
                ans.push_back({});

                // Update previous column
                prevCol = col;
            }

            // Add the current node's value
            // to the current vertical column.
            ans.back().push_back(val);
        }

        // Return the final vertical traversal
        return ans;
    }
};

/*

┌─────────────────────────────────────────┐
│       VERTICAL TRAVERSAL — LC 987       │
├─────────────────────────────────────────┤
│ IDEA                                    │
│ BFS + store coordinates + sort          │
│                                         │
│ Store: {column, row, value}             │
│ Queue: {node, {row, column}}            │
│                                         │
│ POSITION                                │
│ Root  → (0, 0)                          │
│ Left  → (row+1, col-1)                  │
│ Right → (row+1, col+1)                  │
│                                         │
│ SORT                                    │
│ column → row → value                    │
│                                         │
│ GROUP                                   │
│ Same column → same answer vector        │
│                                         │
│ TC → O(n log n)                         │
│ SC → O(n)                               │
└─────────────────────────────────────────┘

*/

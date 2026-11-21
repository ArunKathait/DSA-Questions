
class Solution {// Time Complexity:  O(n)                                      Space Complexity: O(n)
public:
    void dfs(int currentNode, vector<int>& parent, string &s,
             unordered_map<int, vector<int>>& adj,
             vector<int>& ansSize, vector<int>& last)
    {
        // Get the character of the current node.
        // Convert character into an index from 0 to 25.
        int c = s[currentNode] - 'a';

        // Store the nearest ancestor of the current node
        // having the same character.
        // -1 means no such ancestor exists.
        int nearestAncestor = last[c];

        // Update the last occurrence of this character
        // to the current node.
        // This helps its descendants find the nearest matching ancestor.
        last[c] = currentNode;

        // Traverse all children of the current node.
        for(int child : adj[currentNode])
        {
            dfs(child, parent, s, adj, ansSize, last);
        }

        // Backtrack:
        // Restore the previous occurrence of this character.
        // This ensures that other branches do not use the
        // current node as an ancestor.
        last[c] = nearestAncestor;

        // The root node has no parent, so skip parent updating for it.
        if(currentNode != 0)
        {
            // Initially, the node's parent remains its original parent.
            int newParent = parent[currentNode];

            // If an ancestor with the same character exists,
            // make that nearest matching ancestor the new parent.
            if(nearestAncestor != -1)
            {
                newParent = nearestAncestor;
            }

            // Update the parent of the current node.
            parent[currentNode] = newParent;

            // Add the current node's subtree size to its new parent.
            // This accumulates subtree sizes while DFS processes
            // nodes from children to parents.
            ansSize[newParent] += ansSize[currentNode];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        // Adjacency list to represent the original tree.
        // adj[u] contains all children of node u.
        unordered_map<int, vector<int>> adj;

        // Initially, every node contributes 1 to its own subtree.
        vector<int> ansSize(n, 1);

        // last[c] stores the nearest ancestor encountered
        // with character c during the current DFS path.
        // Initially, no character has been encountered.
        vector<int> last(26, -1);

        // Build the adjacency list using the parent array.
        for(int i = 0; i < n; i++)
        {
            int u = parent[i]; // Parent of current node.
            int v = i;         // Current node.

            // Add an edge from parent to child.
            // For root node, parent[0] = -1.
            adj[u].push_back(v);
        }

        // Start DFS from the root node (0).
        dfs(0, parent, s, adj, ansSize, last);

        // Return the subtree size of every node
        // after updating the parent relationships.
        return ansSize;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Find Subtree Sizes After Reparenting         │
├──────────────────────────────────────────────┤
│ Approach: DFS + Tree + Backtracking          │
│                                              │
│ Key Idea:                                    │
│ Track the nearest ancestor having the same   │
│ character using the last[26] array.          │
│                                              │
│ 1. Store the previous matching ancestor.     │
│ 2. Update last[c] with the current node.     │
│ 3. Traverse all children using DFS.          │
│ 4. Restore last[c] using backtracking.       │
│ 5. Update the node's parent if a matching    │
│    ancestor exists.                          │
│ 6. Add its subtree size to the new parent.   │
│                                              │
│ Initial Subtree Size: 1 for every node       │
│                                              │
│ Time Complexity:  O(n) Average               │
│ Space Complexity: O(n)                       │
│ Extra Space:      O(n)                       │
└──────────────────────────────────────────────┘

*/

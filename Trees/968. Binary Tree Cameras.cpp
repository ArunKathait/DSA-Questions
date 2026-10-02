
class Solution {// Time Complexity: O(n)           Space Complexity: O(h), worst case O(n)
public:
    int solve(TreeNode* root, int& cameras) {
        // State 1: A NULL node is considered monitored.
        // This prevents unnecessary cameras from being placed
        // below leaf nodes.
        if (root == NULL) 
        {
            return 1;
        }

        // Postorder traversal: first process both children,
        // then decide the state of the current node.
        int leftSide = solve(root->left, cameras);
        int rightSide = solve(root->right, cameras);

        // State 0: Not monitored.
        // If either child is not monitored, place a camera
        // at the current node to cover that child.
        if (leftSide == 0 || rightSide == 0) 
        {
            cameras++;
            return 2;  // State 2: Current node has a camera.
        }

        // If either child has a camera, the current node
        // is monitored by that child's camera.
        if (leftSide == 2 || rightSide == 2) 
        {
            return 1;  // State 1: Monitored, no camera here.
        }

        // Both children are monitored, but neither has a camera.
        // The current node is not monitored by its children,
        // so its parent may need to place a camera.
        return 0;  // State 0: Not monitored.
    }

    int minCameraCover(TreeNode* root) {
        int cameras = 0;

        // Start DFS and process the entire tree.
        int rootState = solve(root, cameras);

        // The root has no parent to cover it.
        // If it is not monitored, place one final camera.
        if (rootState == 0) 
        {
            cameras++;
        }

        return cameras;
    }
};

/*

+---------------+-------------------------+-------------------------------+
| Return value  | Meaning                 | Action                        |
+---------------+-------------------------+-------------------------------+
| 0             | Not monitored           | Parent must handle it         |
+---------------+-------------------------+-------------------------------+
| 1             | Monitored, no camera    | No immediate action           |
+---------------+-------------------------+-------------------------------+
| 2             | Camera installed        | Covers parent and children    |
+---------------+-------------------------+-------------------------------+

┌──────────────────────────────────────┐
│       BINARY TREE CAMERAS            │
│       GREEDY + POSTORDER DFS         │
├──────────────────────────────────────┤
│ STATES:                              │
│ 0 = Not monitored                    │
│ 1 = Monitored, no camera             │
│ 2 = Camera installed                 │
│                                      │
│ BASE CASE:                           │
│ NULL node → return 1                 │
│                                      │
│ TRANSITIONS:                         │
│ Either child = 0 → cameras++         │
│                    return 2          │
│ Either child = 2 → return 1          │
│ Both children = 1 → return 0         │
│                                      │
│ ROOT CHECK:                          │
│ Root returns 0 → cameras++           │
│                                      │
│ TRAVERSAL:                           │
│ Left → Right → Root                  │
│                                      │
│ TC: O(n)                             │
│ SC: O(h) recursion stack             │
│ Worst-case SC: O(n)                  │
└──────────────────────────────────────┘

*/

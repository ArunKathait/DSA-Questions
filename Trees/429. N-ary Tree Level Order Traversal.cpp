
class Solution {// TC → O(N)                                 SC → O(N)
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> ans;

        // If the tree is empty, return empty answer.
        if (root == NULL) 
        {
            return {};
        }

        // N-ary tree uses Node*
        queue<Node*> q;

        // Start BFS from the root.
        q.push(root);

        // Process the tree level by level.
        while (!q.empty()) 
        {
            // Number of nodes present in the current level.
            int size = q.size();

            // Store values of the current level.
            vector<int> level;

            // Process exactly all nodes of this level.
            while (size--) 
            {
                // Get the front node.
                Node* node = q.front();
                q.pop();

                // Store its value.
                level.push_back(node->val);

                // N-ary tree can have multiple children.
                // Add every child to the queue.
                //
                // These children will be processed
                // in the next level.
                for(Node* child : node->children) 
                {
                    q.push(child);
                }
            }

            // Store the completed level.
            ans.push_back(level);
        }

        return ans;
    }
};

/*

╔══════════════════════════════════════╗
║      N-ARY LEVEL ORDER — CHEAT       ║
╠══════════════════════════════════════╣
║ Pattern: BFS + Queue                 ║
║                                      ║
║ Queue: queue<Node*>                  ║
║                                      ║
║ 1. Push root                         ║
║ 2. size = q.size()                   ║
║ 3. Process exactly `size` nodes      ║
║ 4. Add node->val to level            ║
║ 5. Push ALL children                 ║
║ 6. ans.push_back(level)              ║
║                                      ║
║ Binary → left + right                ║
║ N-ary  → children vector             ║
║                                      ║
║ TC: O(N)                             ║
║ SC: O(N)                             ║
╚══════════════════════════════════════╝


Key pattern:

queue + q.size() + for(child : node->children) → level-by-level BFS.

*/

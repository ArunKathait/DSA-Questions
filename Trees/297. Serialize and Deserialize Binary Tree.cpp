
class Codec {
public:
    // serialize()        TC ---> O(N)              SC ---> O(N)
    // deserialize()      TC ---> O(N)              SC ---> O(N)
    // Overall            TC ---> O(N)              SC ---> O(N)
    // ------------------ SERIALIZE ------------------
    // Converts a binary tree into a comma-separated string
    string serialize(TreeNode* root) {
        if (root == NULL) 
        {
            return ""; // If tree is empty, return empty string
        }

        string str; // This will store the serialized tree
        queue<TreeNode*> q; // Queue for level-order (BFS) traversal
        q.push(root);

        // Traverse the tree in level order
        while (!q.empty()) 
        {
            int size = q.size();

            // Process all nodes of the current level
            while (size--) 
            {
                TreeNode* currentNode = q.front(); // Get front node
                q.pop();

                if (currentNode == NULL) 
                {
                    // If current node is NULL, store "#" to represent null
                    str += "#,";
                } 
                else 
                {
                    // Otherwise, store its value
                    str += to_string(currentNode->val) + ",";
                }

                // Even if node is NULL, we don't push its children
                // Push left and right children for non-null nodes
                if (currentNode != NULL) 
                {
                    q.push(currentNode->left);
                    q.push(currentNode->right);
                }
            }
        }

        // Return the final serialized string representation
        return str;
    }

    // ------------------ DESERIALIZE ------------------
    // Converts the serialized string back into the binary tree
    TreeNode* deserialize(string data) {
        if (data.empty()) 
        {
            return NULL; // If input string is empty, return null tree
        }

        stringstream ss(data); // To split string by commas
        string str;

        // First token is the root value
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str)); // Create root node

        queue<TreeNode*> q; // Queue to rebuild tree level by level
        q.push(root);

        // BFS reconstruction of tree
        while (!q.empty()) 
        {
            int size = q.size();

            while (size--) 
            {
                TreeNode* node = q.front(); // Get current node
                q.pop();

                // Get next token for left child
                getline(ss, str, ',');
                if (str == "#") 
                {
                    // "#" means NULL → no left child
                    node->left = NULL;
                } 
                else 
                {
                    // Otherwise, create left child node
                    TreeNode* leftNode = new TreeNode(stoi(str));
                    node->left = leftNode;
                    q.push(leftNode);
                }

                // Get next token for right child
                getline(ss, str, ',');
                if (str == "#") 
                {
                    // "#" means NULL → no right child
                    node->right = NULL;
                } 
                else 
                {
                    // Otherwise, create right child node
                    TreeNode* rightNode = new TreeNode(stoi(str));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        // Return the reconstructed root node
        return root;
    }
};

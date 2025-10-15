*********************************************APPROACH 1st********************************************************

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

************************************************APPROACH 2nd*******************************************************

class Codec {
public:
    // serialize()        TC ---> O(N)              SC ---> O(N)
    // deserialize()      TC ---> O(N)              SC ---> O(N)
    // Overall            TC ---> O(N)              SC ---> O(N)
    // Function to convert a binary tree into a string representation
    string serialize(TreeNode* root) {
        // If the tree is empty, return an empty string
        if (!root) 
        {
            return "";
        }

        string str; // This string will store the serialized output
        queue<TreeNode*> q; // Queue for level-order traversal (BFS)
        q.push(root); // Start with the root node

        // Perform level-order traversal
        while (!q.empty()) 
        {
            TreeNode* node = q.front(); // Get the current node
            q.pop();

            if (node == NULL) 
            {
                // If the node is NULL, represent it with '#'
                str += "#,";
            } 
            else 
            {
                // Otherwise, add its value followed by a comma
                str += to_string(node->val) + ",";
                // Push its left and right children to the queue
                // (They might be NULL, which will be handled later)
                q.push(node->left);
                q.push(node->right);
            }
        }
        // Return the final serialized string
        return str;
    }

    // Function to rebuild a binary tree from its string representation
    TreeNode* deserialize(string data) {
        // If the input string is empty, return NULL (empty tree)
        if (data.empty())
        {
            return NULL;
        } 

        // Step 1: Split the input string by commas into tokens
        vector<string> nodes; // This will store node values (and '#')
        string token = "";
        for (char c : data) 
        {
            if (c == ',') 
            {
                // When comma found, push current token to vector
                nodes.push_back(token);
                token = ""; // Reset token for next value
            } 
            else 
            {
                token += c; // Build up the current token
            }
        }

        // Step 2: Create the root node from the first element
        int index = 0; // Index to track current position in 'nodes' vector
        TreeNode* root = new TreeNode(stoi(nodes[index++])); // Create root
        queue<TreeNode*> q; // Queue for BFS reconstruction
        q.push(root);

        // Step 3: Build the tree using level-order logic
        while (!q.empty()) 
        {
            TreeNode* node = q.front(); // Get current node from queue
            q.pop();

            // Process left child
            if (index < nodes.size()) {
                if (nodes[index] != "#") 
                {
                    // If not '#', create left child node
                    node->left = new TreeNode(stoi(nodes[index]));
                    q.push(node->left); // Add to queue for further processing
                }
                index++; // Move to next token
            }

            // Process right child
            if (index < nodes.size()) {
                if (nodes[index] != "#") 
                {
                    // If not '#', create right child node
                    node->right = new TreeNode(stoi(nodes[index]));
                    q.push(node->right); // Add to queue for further processing
                }
                index++; // Move to next token
            }
        }

        // Step 4: Return the rebuilt root node
        return root;
    }
};

*************************************************APPROACH 1st(BETTER)************************************************

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {// TC ---> O(N)                            SC ---> O(N)
public:
    Node* connect(Node* root) {
        // Base case: If the tree is empty, return NULL
        if(root == NULL)
        {
            return NULL;
        }
        
        // Create a queue for level order traversal (BFS)
        queue<Node*> q;
        q.push(root);  // Start with the root node

        // Process the tree level by level
        while(!q.empty())
        {
            int size = q.size();   // Number of nodes in the current level
            Node *prev = NULL;     // Keeps track of the previous node in this level

            // Traverse all nodes of the current level
            while(size--)
            {
                // Get the front node from the queue
                auto currentNode = q.front();
                q.pop();

                // Push left child into the queue (for next level)
                if(currentNode->left != NULL)
                {
                    q.push(currentNode->left);
                }

                // Push right child into the queue (for next level)
                if(currentNode->right != NULL)
                {
                    q.push(currentNode->right);
                }

                // If there is a previous node in the same level,
                // connect its 'next' pointer to the current node
                if(prev != NULL)
                {
                    prev->next = currentNode;
                }

                // Update 'prev' to the current node
                prev = currentNode;
            }

            // After processing the level, the last node's 'next' should be NULL
            prev->next = NULL;
        }

        // Return the modified tree (root remains the same)
        return root;
    }
};

*************************************************APPROACH 2nd(OPTIMAL)**********************************************


class Solution {// TC ---> O(N)                                           SC ---> O(1)
public:
    Node* connect(Node* root) {
        // If the tree is empty, return NULL
        if (root == NULL) 
        {
            return NULL;
        }

        // 'current' pointer starts from the root node
        Node* current = root;

        // Loop until we reach the last level (which has no children)
        // Because we connect children at each level
        while (current->left != NULL) 
        {
            // 'temp' stores the leftmost node of the current level
            // We'll move down to it after processing the entire current level
            Node* temp = current;

            // Traverse the current level using the already established 'next' pointers
            while (current != NULL) 
            {
                // Connect left child -> right child (within the same parent)
                current->left->next = current->right;

                // Connect right child -> next parent's left child
                // Only if the next parent exists (current->next != NULL)
                current->right->next = (current->next == NULL) ? NULL : current->next->left;

                // Move to the next node at the same level
                current = current->next;
            }

            // Move down to the leftmost node of the next level
            current = temp->left;
        }

        // Return the root after setting up all 'next' pointers
        return root;
    }
};

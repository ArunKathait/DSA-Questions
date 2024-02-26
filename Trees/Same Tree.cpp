//  Using DFS
//T.C : O(n)
//S.C : O(1) Auxiliary space, O(depth of tree) Recursion stack space

class Solution {
public:
    // Function to check if two binary trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Check if both nodes are NULL (base case for recursion)
        if(p == NULL && q == NULL)
        {
            return true; // Both trees are empty, they are identical
        }
        
        // Check if only one node is NULL (trees are not identical)
        if(p == NULL || q == NULL)
        {
            return false; // One tree is empty while the other is not, they are not identical
        }
        
        // Check if the values of the current nodes are equal
        if(p->val == q->val)
        {
            // Recursively check left and right subtrees
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            // If both recursive calls return true, the subtrees are identical,
            // otherwise, false will propagate upwards.
        }
        
        // If the values of the current nodes are not equal, trees are not identical
        return false;
    }
};




//Approach-2 (Using BFS)
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    // Function to check if two binary trees are identical using iterative BFS
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Check if both trees are empty
        if(p == NULL && q == NULL)
        {
            return true; // Both trees are identical
        }
        
        // Check if one tree is empty while the other is not
        if(p == NULL || q == NULL)
        {
            return false; // Trees are not identical
        }
        
        // Create two queues for iterative BFS traversal of the trees
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        
        // Enqueue the roots of both trees
        q1.push(p);
        q2.push(q);
        
        // Perform BFS traversal
        while(!q1.empty() && !q2.empty())
        {
            // Dequeue nodes from both queues
            TreeNode* first = q1.front();
            q1.pop();
            
            TreeNode* second = q2.front();
            q2.pop();
            
            // Check if values of dequeued nodes are equal
            if(first->val != second->val)
            {
                return false; // Trees are not identical
            }
            
            // Check left subtrees of both nodes
            if(first->left && second->left)
            {
                q1.push(first->left);
                q2.push(second->left);
            }
            // If only one of the nodes has a left child, trees are not identical
            else if(first->left || second->left)
            {
                return false; // Trees are not identical
            }
            
            // Check right subtrees of both nodes
            if(first->right && second->right)
            {
                q1.push(first->right);
                q2.push(second->right);
            }
            // If only one of the nodes has a right child, trees are not identical
            else if(first->right || second->right)
            {
                return false; // Trees are not identical
            }
        }
        // If traversal completes without returning false, trees are identical
        return true;
    }
};


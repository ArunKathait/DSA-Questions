*************************************************APPROACH 1st(USING DFS)***********************************************

class Solution {// TC--->O(N)       SC--->O(h) i.e->Height of tree 
public:
    
    // Depth-first search function to traverse the binary tree and compute the sum of root-to-leaf paths
    int dfs(TreeNode* root,int currentSum)
    {
        // If the current node is null, return 0
        if(root == NULL)
        {
            return 0;
        }
        
        // Update the current sum by multiplying it by 10 and adding the value of the current node
        currentSum = currentSum*10 + root->val;
        
        //If the current node is a leaf node (both left and right children are null),return the current sum
        if(root->left == NULL && root->right == NULL)
        {
            return currentSum;
        }
        
        // Recursively compute the sum of root-to-leaf paths for the left and right subtrees
        int leftSum = dfs(root->left,currentSum);
        int rightSum = dfs(root->right,currentSum);
        
         // Return the sum of root-to-leaf paths from the left and right subtrees
        return leftSum + rightSum;
    }
    
    // Function to compute the sum of all root-to-leaf paths in the binary tree
    int sumNumbers(TreeNode* root) {
        
        // Initialize the answer variable to store the final result
        int ans = 0;
        
        // Call the dfs function to compute the sum of root-to-leaf paths, starting from the root
        return dfs(root,ans);
        
    }
};

************************************************APPROACH 2nd(USING BFS)******************************************************

class Solution {// TC--->O(N)         SC--->O(N)
public:
    
    // Function to compute the sum of all root-to-leaf paths in a binary tree
    int sumNumbers(TreeNode* root) {
        
        // Initialize the total sum to store the sum of all root-to-leaf paths
        int totalSum = 0;
        
        // Create a queue to perform BFS traversal, storing pairs of TreeNode* and int (currentSum)
        queue<pair<TreeNode*,int>>q;
        
        // Push the pair of the root node and initial sum (0) into the queue to start traversal
        q.push({root,0});
        
        // Perform BFS traversal until the queue is empty
        while(!q.empty())
        {
            // Dequeue the front element containing the current node and its associated sum
            auto [root,currentSum] = q.front();
            q.pop();
            
            // Update the current sum by multiplying it by 10 and adding the value of the current node
            currentSum = currentSum * 10 + root->val;
            
            //If the current node is a leaf node (both left and right children are null),add the current sum to the total sum
            if(root->left == NULL && root->right == NULL)
            {
                totalSum += currentSum;
            }
            
            // If the current node has a left child, enqueue it along with the updated current sum
            if(root->left != NULL)
            {
                q.push({root->left,currentSum});
            }
            
            // If the current node has a right child, enqueue it along with the updated current sum
            if(root->right != NULL)
            {
                q.push({root->right,currentSum});
            }
        }
        
        // Return the total sum of all root-to-leaf paths
        return totalSum;
    }
};

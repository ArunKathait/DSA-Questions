*********************************************APPROACH 1st(USING DFS)*************************************************

class Solution // TC--->O(N)             SC--->O(N)
{
    public:
    
    // Recursive function to traverse the tree in preorder and find nodes at distance k from root
    vector<int>preorder(Node *root,vector<int>&ans,int current,int k)
    {
        // Base case: If the current node is NULL, return an empty vector
        if(root == NULL)
        {
            return {0};
        }
        
    
        // If the current distance from the root is equal to k, add the data of the current node to the answer vector
        if(current == k)
        {
            ans.push_back(root->data);
            return ans;
        }
        
        // Recursively traverse the left and right subtrees with increased distance from the root
        preorder(root->left,ans,current + 1,k);
        preorder(root->right,ans,current + 1,k);
        
        // Return the answer vector after traversal
        return ans;
    }
    
    // Function to find nodes at distance k from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Initialize an empty vector to store the nodes at distance k from root
      vector<int>ans;
      
      // Initialize the current distance from root to 0
      int current = 0;
      
      // Call the preorder function to traverse the tree and find nodes at distance k from root
      preorder(root,ans,current,k);
      
      // Return the vector containing nodes at distance k from root
      return ans;
    }
};

*****************************************************APPROACH 2nd(USING BFS)****************************************

class Solution // TC--->O(N)            SC--->O(N)
{
    public:
    // Function to find all nodes at distance 'k' from the given root node
    vector<int> Kdistance(struct Node *root, int k)
    {
        // Vector to store nodes at distance 'k' from the root
        vector<int>ans;
        
        // Queue to perform level order traversal
        queue<Node*>q;
        
        // Initialize the level to 0
        int level = 0;
        
        // Push the root node into the queue
        q.push(root);
        
        // Continue the traversal until the queue is not empty
        while(!q.empty())
        {
            // Get the current size of the queue (number of nodes at this level)
            int size = q.size();
            
            // Traverse all nodes at the current level
            while(size--)
            {
                // Get the front node of the queue
                auto node = q.front();
                q.pop();
            
               // If the current level matches the target distance 'k',
               // add the data of the current node to the result vector
               if(level == k)
               {
                  ans.push_back(node->data);
               }
            
               // Enqueue the left child if it exists
               if(node->left != NULL)
               {
                   q.push(node->left);
               }
            
               // Enqueue the right child if it exists
               if(node->right != NULL)
               {
                   q.push(node->right);
               }
            }
            // Move to the next level
            level++;
        }
        
        // Return the vector containing nodes at distance 'k' from the root
        return ans;
    }
}; 

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

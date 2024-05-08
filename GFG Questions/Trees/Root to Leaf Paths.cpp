class Solution {// TC--->O(N)            SC--->O(N)
  public:
  
  // Depth First Search (DFS) function to traverse the binary tree and find all paths
  void dfs(Node *root,vector<vector<int>>&ans,vector<int>&path)
  {
      // If the current node is NULL, return
      if(root == NULL)
      {
          return;
      }
      
      // Add the current node's value to the current path
      path.push_back(root->data);
      
      
      // If the current node is a leaf node (i.e., it has no children),
      // add the current path to the answer
      if(root->left == NULL && root->right == NULL)
      {
          ans.push_back(path);
          
          // Remove the last added node from the path as we backtrack
          path.pop_back();
          return ;
      }
      
      // Recursively traverse the left subtree
      dfs(root->left,ans,path);
      
      // Recursively traverse the right subtree
      dfs(root->right,ans,path);
      
      // Remove the current node from the path as we backtrack
      path.pop_back();
  }
  
    // Function to find all root-to-leaf paths in a binary tree
    vector<vector<int>> Paths(Node* root) {
        
        // Vector to store all the paths
        vector<vector<int>>ans;
        
        // Vector to store the current path
        vector<int>path;
         
         // Call the DFS function to find all paths
        dfs(root,ans,path);
        
        // Return the vector containing all the paths
        return ans;
    }
};

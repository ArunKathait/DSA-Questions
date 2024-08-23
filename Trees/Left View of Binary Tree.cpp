**************************************************APPROACH 1st(USING UNORDERED MAP)**************************************

// TC--->O(NlogN)                         SC--->O(N)
 
 // Helper function to traverse the binary tree and store nodes' data in the unordered_map at each level.
 void solve(Node *root,int level,unordered_map<int,vector<int>>&ump)
 {
     // Base case: If the current node is NULL, return.
     if(root == NULL)
     {
         return ;
     }
     
     // Add the current node's data to the vector corresponding to the current level in the unordered_map.
     ump[level].push_back(root->data);
     
     // Recursively call the function for the left child of the current node, increasing the level by 1.
     solve(root->left,level+1,ump);
     
     // Recursively call the function for the right child of the current node, increasing the level by 1.
     solve(root->right,level+1,ump);
 }

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Declare an unordered_map to store node values at each level. 
    // The key is the level number, and the value is a vector of node data at that level.
   unordered_map<int,vector<int>>ump;
   
   // Initialize the level to 0 (root level) and call the helper function.
   int level = 0;
   solve(root,level,ump);
   
   // Vector to store the result, which will be the left view of the binary tree.
   vector<int>ans;
   
   // Vector to store the levels (keys) from the unordered_map.
   vector<int>levels;
   
   // Iterate through the unordered_map to extract the keys (levels).
   for(auto it:ump)
   {
       levels.push_back(it.first);
   }
   
   // Sort the levels vector to ensure nodes are processed in increasing level order.
   sort(levels.begin(),levels.end());
   
   // Iterate through the sorted levels.
   for(auto it:levels)
   {
       // Add the first node's data (leftmost node at each level) to the result vector.
       ans.push_back(ump[it][0]);
   }
   
   // Return the vector containing the left view of the binary tree.
   return ans;
}

*************************************************APPROACH 2nd(USING MAP)*********************************************

// TC--->O(NlogN)                         SC--->O(N)
 
 // Helper function to traverse the binary tree and store nodes' data in the map at each level.
 void solve(Node *root,int level,map<int,vector<int>>&mp)
 {
     // Base case: If the current node is NULL, return.
     if(root == NULL)
     {
         return ;
     }
     
     // Add the current node's data to the vector corresponding to the current level in the map.
     mp[level].push_back(root->data);
     
     // Recursively call the function for the left child of the current node, increasing the level by 1.
     solve(root->left,level+1,mp);
     
     // Recursively call the function for the right child of the current node, increasing the level by 1.
     solve(root->right,level+1,mp);
 }

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Declare an map to store node values at each level. 
    // The key is the level number, and the value is a vector of node data at that level.
    map<int,vector<int>>mp;
   
   // Initialize the level to 0 (root level) and call the helper function.
   int level = 0;
   solve(root,level,mp);
   
   // Vector to store the result, which will be the left view of the binary tree.
   vector<int>ans;

   // Iterate through the map, which is sorted by levels in ascending order.
   for(auto it:mp)
   {
       // Add the first node's data (leftmost node at each level) to the result vector.
       // Access the first element of the vector for the current level.
       ans.push_back(it.second[0]);
   }
   
   // Return the vector containing the left view of the binary tree.
   return ans;
}


*************************************************APPROACH 3rd(BETTER APPROACH)***********************************

//TC--->O(N)                            SC--->O(N)
// Helper function to traverse the binary tree and build the left view.
// The function uses depth-first traversal (preorder: root, left, right).
void solve(Node *root,int level,vector<int>&ans)
{
    // Base case: If the current node is NULL, return.
    if(root == NULL)
    {
        return ;
    }
    
    // If this is the first node being visited at the current level,
    // add the node's data to the answer vector.
    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
    
    // Recursively call the function for the left child of the current node,
    // increasing the level by 1.
    solve(root->left,level+1,ans);
    
    // Recursively call the function for the right child of the current node,
    // increasing the level by 1.
    solve(root->right,level+1,ans);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Vector to store the result, which will be the left view of the binary tree.
   vector<int>ans;
   
   // Initialize the level to 0 (root level) and call the helper function.
   int level = 0;
   solve(root,level,ans);
   
   // Return the vector containing the left view of the binary tree.
   return ans;
}

/* 
NOTE: If we have to find the right view of binary tree then we do below steps --------->

   solve(root->right,level+1,ans);

   solve(root->left,level+1,ans);

*/

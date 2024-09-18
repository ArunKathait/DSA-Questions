************************************************APPROACH 1st***********************************************************

class Solution {// TC--->O(N^2)                                          SC--->O(N)
public:
    // Function to search for the index of the root value (rootVal) in the inorder vector
    int searchIndex(vector<int>&inorder,int rootVal)
    {
        // Variable to store the index of the root value in the inorder traversal
        int index;
        
        // Loop through the inorder vector to find the rootVal
        for(int i=0;i<inorder.size();i++)
        {
            // If the root value is found
            if(inorder[i] == rootVal)
            {
                // Store the index of rootVal in the variable index
                index = i;
                
                // Break the loop once the index is found
                break;
            }
        }
        
        // Return the index of rootVal in inorder array
        return index;
    }
    
    // Recursive function to construct the binary tree from preorder and inorder traversals
    TreeNode *solve(vector<int>&preorder,vector<int>&inorder,int start,int end,int &idx)
    {
        // Base case: If start exceeds end, it means there are no elements to process, return NULL
        if(start > end)
        {
            return NULL;
        }
        
        // Get the root value from the current index of the preorder array
        int rootVal = preorder[idx];
        // Increment the index to process the next element in preorder
        idx++;
        
        // Find the index of the root value in the inorder traversal (helps in splitting the tree)
        int InorderIdx = searchIndex(inorder,rootVal);
        
        // Create a new node with the root value
        TreeNode *root = new TreeNode(rootVal);
        
        // Recursively build the left subtree. The left subtree elements lie in the range [start, InorderIdx-1] in the inorder traversal.
        root->left = solve(preorder,inorder,start,InorderIdx-1,idx);
        
        // Recursively build the right subtree. The right subtree elements lie in the range [InorderIdx+1, end] in the inorder traversal.
        root->right = solve(preorder,inorder,InorderIdx+1,end,idx);
        
        // Return the constructed tree rooted at 'root'
        return root;
    }
    
    // Main function to build a binary tree from the preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Initialize index to process the preorder array
        int idx = 0;
        
        // Size of the inorder array
        int n = inorder.size();
        
        // Call the recursive function solve to construct the binary tree and return the root of the tree
        return solve(preorder,inorder,0,n-1,idx);  
    }
};

********************************************APPROACH 2nd(OPTIMAL APPROACH)**********************************************


class Solution {// TC--->O(N)                         SC--->O(N)
public:
    // Function to recursively build the binary tree from preorder and inorder traversals.
    // 'preorder' - vector representing the preorder traversal of the tree.
    // 'inorder' - vector representing the inorder traversal of the tree.
    // 'start' and 'end' define the current range in the inorder array we are working on.
    // 'idx' is a reference variable that keeps track of the current index in the preorder vector.
    // 'ump' is an unordered_map storing the index of each value in the inorder vector.
    TreeNode *solve(vector<int>&preorder,vector<int>&inorder,int start,int end,int &idx,unordered_map<int,int>&ump)
    {
        // Base case: If the range is invalid, return NULL, as no node exists here.
        if(start > end)
        {
            return NULL;
        }
        
         // Get the current root value from the preorder array (preorder traversal always starts with the root).
        int rootVal = preorder[idx];
        
        // Move to the next index in preorder.
        idx++;
        
        // Find the index of this root value in the inorder array using the map 'ump'.
        int InorderIdx = ump[rootVal];
        
        // Create a new TreeNode with the root value.
        TreeNode *root = new TreeNode(rootVal);
        
        // Recursively build the left and right subtrees.
        // The left subtree is in the range [start, InorderIdx-1] in the inorder array.
        root->left = solve(preorder,inorder,start,InorderIdx-1,idx,ump);
        
        // The right subtree is in the range [InorderIdx+1, end] in the inorder array.
        root->right = solve(preorder,inorder,InorderIdx+1,end,idx,ump);
        
        // Return the constructed root node.
        return root;
    }
    
    // Function to initiate building the binary tree.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a map to store the index of each element in the inorder array.
        unordered_map<int,int>ump;
        
        // Get the size of the inorder array.
        int n = inorder.size();
        
        // Populate the unordered_map 'ump' with the element value as the key and its index as the value.
        for(int i=0;i<n;i++)
        {
            ump[inorder[i]] = i;
        }
        
        // Initialize 'idx' to track the current index in the preorder array.
        int idx = 0;
        
        // Call the 'solve' function to recursively build the tree.
        return solve(preorder,inorder,0,n-1,idx,ump);
    }
};

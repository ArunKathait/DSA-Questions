
class Solution {// TC--->O(N)                        SC--->O(N)
public:
    // Helper function to perform postorder traversal
    void solve(Node *root,vector<int>&ans)
    {
        // If the current node is null, return (base case)
        if(root == NULL)
        {
            return ;
        }
        
        // Traverse each child of the current node
        for(auto child:root->children)
        {
            // Recursively perform postorder traversal on each child
            solve(child,ans);
        }
        
        // After all children have been visited, add the current node's value to the answer vector
        ans.push_back(root->val);
    }
    
    // Function to initiate the postorder traversal and return the result
    vector<int> postorder(Node* root) {
        // Vector to store the result of the traversal
        vector<int>ans;
        
        // Call the helper function with the root node
        solve(root,ans);
        
        // Return the result vector
        return ans;
    }
};

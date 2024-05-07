// TC--->O(N)         SC--->O(N)

vector<int> reverseLevelOrder(Node *root)  
{
    // Create a queue to perform level order traversal
    queue<Node*>q;
    
    // Push the root node into the queue
    q.push(root);
    
    // Vector to store the reverse level order elements
    vector<int>ans;
    
    // Continue until the queue is empty
    while(!q.empty())
    {
        // Get the current size of the queue (number of nodes at current level)
        int size = q.size();
        
        // Process all nodes at the current level
        while(size--)
        {
            // Get the front node of the queue
            auto front = q.front();
            
            // Remove the front node from the queue
            q.pop();
            
            // Push the right child into the queue if it exists
            if(front->right != NULL)
            {
                q.push(front->right);
            }
            
            // Push the left child into the queue if it exists
            if(front->left != NULL)
            {
                q.push(front->left);
            }
            
            // Store the data of the current node in the answer vector
            ans.push_back(front->data);
        }
        
    }
    
        // Reverse the order of elements in the answer vector
        // This is done after processing each level, so that the elements in the answer vector are in reverse level order
        reverse(ans.begin(),ans.end());
    
        // Return the vector containing the reverse level order elements
        return ans;
}

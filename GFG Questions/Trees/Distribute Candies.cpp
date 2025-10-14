
class Solution {
  public:
    // Recursive helper function that returns the "balance" of candies for each subtree
    int solve(Node *root, int &moves)
    {
        // Base case: if the node is NULL, it contributes 0 balance
        if (root == NULL)
        {
            return 0;
        }
        
        // Recursively calculate the candy balance from the left and right subtrees
        int leftBalance = solve(root->left, moves);
        int rightBalance = solve(root->right, moves);
        
        /*
          The "balance" of a node = number of candies it can give to (or needs from) its parent.
          Example:
          - If leftBalance = +2 → left subtree has 2 extra candies to pass up.
          - If leftBalance = -1 → left subtree needs 1 candy from the parent.
          
          Every transfer (abs of balance) counts as one move per candy.
        */
        moves += abs(leftBalance) + abs(rightBalance);
        
        /*
          Return the current node's balance to its parent.

          Formula: 
              (candies in this node)
            + (balance from left child)
            + (balance from right child)
            - 1  (because the node itself needs exactly 1 candy)

          → Positive value means extra candies to give to parent.
          → Negative value means candies needed from parent.
        */
        return (root->data + leftBalance + rightBalance) - 1;
    }
    
    // Main function to find minimum number of moves
    int distCandy(Node* root) {
        int moves = 0;          // total moves counter
        solve(root, moves);     // start DFS traversal from root
        return moves;           // return total moves needed
    }
};

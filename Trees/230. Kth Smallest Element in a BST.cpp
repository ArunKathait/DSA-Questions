************************************************APPROACH 1st*****************************************************

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {// TC ---> O(n log k)                           SC ---> O(k + h)
public:

    // Recursive function to traverse the entire tree
    void solve(TreeNode *root, int k, priority_queue<int> &pq)
    {
        // Base case: if current node is NULL, return
        if(root == NULL)
        {
            return;
        }

        // Insert current node value into the max heap
        pq.push(root->val);

        // If heap size becomes greater than k,
        // remove the largest element.
        //
        // This ensures that the heap always contains
        // only the k smallest elements seen so far.
        if(pq.size() > k)
        {
            pq.pop();
        }

        // Traverse the left subtree
        solve(root->left, k, pq);

        // Traverse the right subtree
        solve(root->right, k, pq);
    }

    int kthSmallest(TreeNode* root, int k) {

        // Max Heap
        //
        // It stores at most k smallest elements.
        // The top of the heap is the largest among them.
        priority_queue<int> pq;

        // Traverse the complete tree
        solve(root, k, pq);

        // After traversal,
        // the heap contains exactly k smallest elements.
        //
        // The largest among these k elements
        // is the kth smallest element.
        return pq.top();
    }
};

************************************************APPROACH 2nd(OPTIMAL)*************************************************

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {// TC ---> O(n)                              SC ---> O(h)
public:

    // Performs inorder traversal of the BST.
    // 'count' keeps track of how many nodes have been visited.
    // 'ans' stores the kth smallest element once found.
    // Both are passed by reference so that updates are reflected
    // across all recursive calls.
    void inorder(TreeNode *root, int k, int &count, int &ans)
    {
        // Base case: if the current node is NULL,
        // there is nothing to traverse.
        if(root == NULL)
        {
            return;
        }

        // Step 1: Traverse the left subtree.
        // In a BST, the left subtree contains smaller values.
        inorder(root->left, k, count, ans);

        // Step 2: Visit the current node.
        count++;

        // If this is the kth node visited during inorder traversal,
        // then it is the kth smallest element.
        if(count == k)
        {
            ans = root->val;
            return;
        }

        // Step 3: Traverse the right subtree.
        // The right subtree contains larger values.
        inorder(root->right, k, count, ans);
    }

    int kthSmallest(TreeNode* root, int k) {

        // Keeps track of how many nodes have been visited.
        int count = 0;

        // Stores the answer.
        int ans = 0;

        // Perform inorder traversal.
        inorder(root, k, count, ans);

        // Return the kth smallest element.
        return ans;
    }
};

***************************************************KTH LARGEST(IN BST)*******************************************

Key Observation

For a BST:

Left < Root < Right
Inorder (Left → Root → Right) → Ascending order → kth Smallest
Reverse Inorder (Right → Root → Left) → Descending order → kth Largest ✅

class Solution {
public:

    void reverseInorder(TreeNode *root, int k, int &count, int &ans)
    {
        if(root == NULL)
        {
            return;
        }

        // Visit right subtree first (larger values)
        reverseInorder(root->right, k, count, ans);

        // Visit current node
        count++;

        if(count == k)
        {
            ans = root->val;
            return;
        }

        // Visit left subtree
        reverseInorder(root->left, k, count, ans);
    }

    int kthLargest(TreeNode *root, int k)
    {
        int count = 0;
        int ans = 0;

        reverseInorder(root, k, count, ans);

        return ans;
    }
};

Remember this simple pattern:

Problem	Traversal
kth Smallest	Left → Root → Right (Inorder)
kth Largest	Right → Root → Left (Reverse Inorder)

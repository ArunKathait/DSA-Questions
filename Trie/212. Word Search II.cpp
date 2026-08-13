
#include <bits/stdc++.h>
using namespace std;


// Directions:
//        (-1,0)
//           ↑
// (0,-1) ← cell → (0,1)
//           ↓
//         (1,0)
vector<int> delRow = {-1, 0, 1, 0};
vector<int> delCol = {0, 1, 0, -1};


// Trie Node
struct TrieNode
{
    // true when a complete word ends at this node
    bool isEnd;

    // Store the complete word at the ending node
    string word;

    // 26 children for a-z
    TrieNode *child[26];


    TrieNode()
    {
        isEnd = false;
        word = "";

        // Initially, no children
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};


// Insert a word into Trie
void insert(TrieNode *root, string word)
{
    TrieNode *current = root;

    // Process every character
    for(char ch : word)
    {
        // Convert character to index
        // 'a' -> 0
        // 'b' -> 1
        // ...
        // 'z' -> 25
        int index = ch - 'a';

        // If this path doesn't exist,
        // create a new Trie node
        if(current->child[index] == NULL)
        {
            current->child[index] = new TrieNode();
        }

        // Move to next Trie node
        current = current->child[index];
    }

    // We reached the end of the word
    current->isEnd = true;

    // Store the complete word
    current->word = word;
}


// DFS + Backtracking
void dfs(int row, int col, int n, int m, vector<vector<char>>& board, TrieNode *root, vector<string>& ans)
{
    // --------------------------------
    // 1. Check boundary
    // --------------------------------
    if(row < 0 || col < 0 || row >= n || col >= m)
    {
        return;
    }


    // --------------------------------
    // 2. Check whether cell is visited
    // --------------------------------
    //
    // '#' means this cell is already used
    // in the current path.
    //
    if(board[row][col] == '#')
    {
        return;
    }


    // Current character
    char ch = board[row][col];

    // Convert character to Trie index
    int index = ch - 'a';


    // --------------------------------
    // 3. Check Trie
    // --------------------------------
    //
    // If current character doesn't exist
    // in the Trie path, stop DFS.
    //
    if(root->child[index] == NULL)
    {
        return;
    }


    // Move to the Trie node
    root = root->child[index];


    // --------------------------------
    // 4. Check if complete word found
    // --------------------------------
    if(root->isEnd)
    {
        // Add word to answer
        ans.push_back(root->word);

        // Prevent duplicate result
        root->isEnd = false;
    }


    // --------------------------------
    // 5. Mark current cell as visited
    // --------------------------------
    board[row][col] = '#';


    // --------------------------------
    // 6. Explore 4 directions
    // --------------------------------
    for(int k = 0; k < 4; k++)
    {
        int newRow = row + delRow[k];
        int newCol = col + delCol[k];

        dfs(newRow, newCol, n, m, board, root, ans);
    }


    // --------------------------------
    // 7. Backtracking
    // --------------------------------
    //
    // Restore original character
    // so that this cell can be used
    // in another DFS path.
    //
    board[row][col] = ch;
}


class Solution {
public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int n = board.size();
        int m = board[0].size();


        // --------------------------------
        // 1. Create Trie
        // --------------------------------
        TrieNode *root = new TrieNode();


        // --------------------------------
        // 2. Insert all words into Trie
        // --------------------------------
        for(string &word : words)
        {
            insert(root, word);
        }


        vector<string> ans;


        // --------------------------------
        // 3. Start DFS from every cell
        // --------------------------------
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                char ch = board[i][j];


                // Optimization:
                //
                // Only start DFS if the starting
                // character exists in the Trie.
                //
                if(root->child[ch - 'a'] != NULL)
                {
                    dfs(i, j, n, m, board, root, ans);
                }
            }
        }


        return ans;
    }
};

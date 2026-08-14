
// TC ---> O(N × L)                        SC ---> O(N × L)
struct TrieNode
{
    // true means a complete word ends at this Trie node
    bool isEnd;

    // Each node can have 26 children for 'a' to 'z'
    TrieNode *child[26];

    TrieNode()
    {
        // Initially, no word ends at this node
        isEnd = false;

        // Initially, all child pointers are NULL
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};


class Solution
{
public:

    // Insert a word into the Trie
    void insert(TrieNode *root, string word)
    {
        // Start from the root
        TrieNode *current = root;

        // Process every character of the word
        for(char ch : word)
        {
            // Convert character to index
            // 'a' -> 0
            // 'b' -> 1
            // ...
            // 'z' -> 25
            int index = ch - 'a';

            // If this character node doesn't exist,
            // create a new TrieNode
            if(current->child[index] == NULL)
            {
                current->child[index] = new TrieNode();
            }

            // Move to the next node
            current = current->child[index];
        }

        // We have reached the end of the word
        // Mark this node as the end of a complete word
        current->isEnd = true;
    }


    // Check whether every prefix of the given word
    // exists as a complete word in the Trie
    bool allPrefixesExist(TrieNode *root, string word)
    {
        // Start from the root
        TrieNode *current = root;

        // Check every character one by one
        for(char ch : word)
        {
            // Convert character to index
            int index = ch - 'a';

            // Move to the node corresponding to this character
            current = current->child[index];

            // If node doesn't exist,
            // this prefix does not exist
            if(current == NULL)
            {
                return false;
            }

            // Node exists, but if it is not the end of
            // a complete word, then this prefix is invalid
            if(current->isEnd == false)
            {
                return false;
            }
        }

        // Every prefix exists as a complete word
        return true;
    }


    string longestWord(vector<string>& words)
    {
        // Create the root node of the Trie
        TrieNode *root = new TrieNode();


        // ------------------------------------------------
        // STEP 1: Insert all words into the Trie
        // ------------------------------------------------

        for(string word : words)
        {
            insert(root, word);
        }


        // This will store our final answer
        string ans = "";


        // ------------------------------------------------
        // STEP 2: Check every word
        // ------------------------------------------------

        for(string &word : words)
        {
            // Check whether every prefix of this word
            // is also a complete word
            if(allPrefixesExist(root, word))
            {
                // Case 1:
                // Current word is longer than our answer
                if(word.length() > ans.length())
                {
                    ans = word;
                }

                // Case 2:
                // Both words have the same length
                // Choose lexicographically smaller word
                else if(word.length() == ans.length() && word < ans)
                {
                    ans = word;
                }
            }
        }


        // Return the longest valid word
        return ans;
    }
};

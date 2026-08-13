
// Time Complexity  : O(C)
// Space Complexity : O(C)

// Trie Node
struct TrieNode
{
    // true means a complete word ends at this node.
    //
    // Example:
    // If we inserted "cat":
    //
    // root -> c -> a -> t
    //                  ↑
    //              isEnd = true
    bool isEnd;


    // Each node can have 26 possible children:
    //
    // child[0]  -> 'a'
    // child[1]  -> 'b'
    // child[2]  -> 'c'
    // ...
    // child[25] -> 'z'
    TrieNode* child[26];


    // Constructor
    TrieNode()
    {
        // Initially, this node is NOT the end
        // of any complete word.
        isEnd = false;


        // Initially, this node has no children.
        // Therefore, set all pointers to NULL.
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};


class Solution {
public:

    // Create the root of the Trie.
    //
    // Root doesn't represent any character.
    // It is simply the starting point of the Trie.
    TrieNode* root = new TrieNode();


    // Function to insert one word into the Trie.
    void insert(string word)
    {
        // Start from the root.
        TrieNode* current = root;


        // Process every character of the word.
        //
        // Example:
        // word = "cat"
        //
        // First ch = 'c'
        // Second ch = 'a'
        // Third ch = 't'
        for(char ch : word)
        {
            // Convert character into an array index.
            //
            // 'a' - 'a' = 0
            // 'b' - 'a' = 1
            // 'c' - 'a' = 2
            // ...
            int index = ch - 'a';


            // Check whether this character path
            // already exists.
            if(current->child[index] == NULL)
            {
                // If it doesn't exist,
                // create a new Trie node.
                current->child[index] = new TrieNode();
            }


            // Move to the next Trie node.
            //
            // Example:
            //
            // root
            //   |
            //   c
            //
            // current moves from root to 'c'.
            current = current->child[index];
        }


        // We have reached the end of the word.
        //
        // Mark this node as the end of a complete word.
        current->isEnd = true;
    }


    // Checks whether ALL prefixes of 'word'
    // are present as complete words in the Trie.
    //
    // Example:
    //
    // word = "world"
    //
    // We need:
    //
    // "w"     -> exists as a word
    // "wo"    -> exists as a word
    // "wor"   -> exists as a word
    // "worl"  -> exists as a word
    // "world" -> exists as a word
    bool allPrefixesExist(TrieNode* root, string word)
    {
        // Start from the root.
        TrieNode* current = root;


        // Process every character of the word.
        for(char ch : word)
        {
            // Convert character to index.
            int index = ch - 'a';


            // Move to the Trie node corresponding
            // to this character.
            current = current->child[index];


            // Two things can make the answer false:
            //
            // 1. current == NULL
            //    -> this prefix does not exist in Trie.
            //
            // 2. current->isEnd == false
            //    -> the prefix exists in Trie,
            //       BUT it is not a complete word.
            //
            // Example:
            //
            // words = ["w", "world"]
            //
            // "wo" exists as a path,
            // but "wo" is NOT a complete word.
            //
            // Therefore "world" is invalid.
            if(current == NULL || current->isEnd == false)
            {
                return false;
            }
        }


        // Every prefix was found and every prefix
        // was a complete word.
        return true;
    }


    // Main function
    string longestString(vector<string>& words)
    {

        // ----------------------------------------
        // STEP 1: Build the Trie
        // ----------------------------------------
        //
        // Insert every word into the Trie.
        for(string word : words)
        {
            insert(word);
        }


        // This will store our final answer.
        string ans = "";


        // ----------------------------------------
        // STEP 2: Check every word
        // ----------------------------------------
        //
        // We check whether all prefixes of each
        // word exist as complete words.
        for(auto word : words)
        {
            // Example:
            //
            // word = "world"
            //
            // Check:
            // "w"
            // "wo"
            // "wor"
            // "worl"
            // "world"
            if(allPrefixesExist(root, word))
            {

                // If this word is longer than
                // our current answer, choose it.
                if(word.length() > ans.length() ||

                   // If both words have the same length,
                   // choose the lexicographically smaller word.
                   //
                   // Example:
                   //
                   // "apple" < "apply"
                   //
                   // So "apple" will be chosen.
                   (word.length() == ans.length() && word < ans))
                {
                    ans = word;
                }
            }
        }


        // Return the longest valid word.
        return ans;
    }
};

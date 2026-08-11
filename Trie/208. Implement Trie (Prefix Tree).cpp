
struct TrieNode
{
    // isEnd tells us whether a complete word
    // ends at this particular node.
    //
    // Example:
    // If we insert "app",
    // the node representing the last 'p'
    // will have isEnd = true.
    bool isEnd;

    // Each node can have up to 26 children,
    // one for each lowercase English character.
    //
    // child[0]  -> 'a'
    // child[1]  -> 'b'
    // ...
    // child[25] -> 'z'
    TrieNode* child[26];

    // Constructor for every TrieNode
    TrieNode()
    {
        // Initially, this node does not represent
        // the end of any word.
        isEnd = false;

        // Initially, this node has no children.
        // So all child pointers are NULL.
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};


class Trie {// SC ---> O(N)
public:

    // Root is the starting point of the Trie.
    //
    // Root does not represent any character.
    // It is just the starting node.
    TrieNode* root;


    // Constructor of Trie
    Trie()
    {
        // Create the root node.
        // The Trie initially contains no words.
        root = new TrieNode();
    }


    // Insert a word into the Trie
    void insert(string word) //  TC ---> O(L) ~ Length of word
    {
        // Start from the root.
        TrieNode* current = root;

        // Process every character of the word.
        for(char ch : word)
        {
            // Convert character into an array index.
            //
            // 'a' - 'a' = 0
            // 'b' - 'a' = 1
            // 'c' - 'a' = 2
            // ...
            // 'z' - 'a' = 25
            int index = ch - 'a';


            // Check whether a node for this character
            // already exists.
            if(current->child[index] == nullptr)
            {
                // If it doesn't exist,
                // create a new TrieNode.
                current->child[index] = new TrieNode();
            }


            // Move current to the child node.
            //
            // Example:
            // If ch = 'a', move to child[0].
            // If ch = 'p', move to child[15].
            current = current->child[index];
        }


        // We have reached the last character of the word.
        //
        // Mark this node as the end of a complete word.
        current->isEnd = true;
    }


    // Search for a complete word
    bool search(string word) //  TC ---> O(L) ~ Length of word
    {
        // Start from the root.
        TrieNode* current = root;

        // Traverse through every character.
        for(char ch : word)
        {
            // Convert character to index.
            int index = ch - 'a';


            // If the required child doesn't exist,
            // the word definitely doesn't exist.
            if(current->child[index] == nullptr)
            {
                return false;
            }


            // Move to the next node.
            current = current->child[index];
        }


        // We successfully found the complete path.
        //
        // But that doesn't necessarily mean the word
        // was inserted.
        //
        // Example:
        // Inserted: "apple"
        //
        // search("app")
        //
        // The path 'a' -> 'p' -> 'p' exists,
        // but "app" wasn't inserted as a complete word.
        //
        // Therefore, we check isEnd.
        return current->isEnd;
    }


    // Check whether any inserted word starts
    // with the given prefix.
    bool startsWith(string prefix) //  TC ---> O(L) ~ Length of word prefix
    {
        // Start from the root.
        TrieNode* current = root;

        // Traverse through every character
        // of the prefix.
        for(char ch : prefix)
        {
            // Convert character to index.
            int index = ch - 'a';


            // If any character is missing,
            // then no word starts with this prefix.
            if(current->child[index] == nullptr)
            {
                return false;
            }


            // Move to the next node.
            current = current->child[index];
        }


        // We successfully traversed the entire prefix.
        //
        // We DON'T check isEnd here because the prefix
        // doesn't have to be a complete word.
        return true;
    }
};

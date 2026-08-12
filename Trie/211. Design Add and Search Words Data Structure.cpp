
struct TrieNode
{
    // isEnd = true means:
    // a complete word ends at this node.
    //
    // Example:
    // If we inserted "bad",
    // then the node representing 'd'
    // will have isEnd = true.
    bool isEnd;


    // There can be 26 children:
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
        // Initially, no complete word ends here.
        isEnd = false;


        // Initially, this node has no children.
        // So all child pointers are NULL.
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};


class WordDictionary {
public:

    // root is the starting point of our Trie.
    TrieNode* root;


    WordDictionary()
    {
        // Create the root node.
        //
        // Root does not represent any character.
        root = new TrieNode();
    }


    // Adds a word into the Trie.
    void addWord(string word)// TC ---> O(L)
    {
        // Start from the root.
        TrieNode* current = root;


        // Process every character of the word.
        //
        // Example:
        // word = "bad"
        //
        // ch = 'b'
        // ch = 'a'
        // ch = 'd'
        for(char ch : word)
        {
            // Convert character into an array index.
            //
            // 'a' - 'a' = 0
            // 'b' - 'a' = 1
            // 'c' - 'a' = 2
            // ...
            int index = ch - 'a';


            // If the required child doesn't exist,
            // create a new TrieNode.
            if(current->child[index] == NULL)
            {
                current->child[index] = new TrieNode();
            }


            // Move current to that child.
            //
            // Example:
            //
            // root
            //   |
            //   b
            //
            // current moves from root to 'b'.
            current = current->child[index];
        }


        // We have processed the complete word.
        //
        // Mark this node as the end of a complete word.
        //
        // Example:
        // For "bad":
        //
        // root -> b -> a -> d
        //                  ↑
        //                isEnd=true
        current->isEnd = true;
    }


    // This function searches for a word.
    //
    // 'root' here means:
    // the Trie node from which we should start searching.
    //
    // IMPORTANT:
    // This is NOT necessarily the original root.
    // When '.' is encountered, we recursively call this
    // function starting from one of the child nodes.
    bool searchUtil(TrieNode* root, string word)
    {
        // Start searching from the given Trie node.
        TrieNode* current = root;


        // Go through every character of the search word.
        for(int i = 0; i < word.length(); i++)
        {
            // Convert current character into an index.
            //
            // NOTE:
            // This is only useful for normal characters.
            // If ch == '.', we don't use this index.
            int index = word[i] - 'a';

            char ch = word[i];


            // --------------------------------
            // CASE 1: Current character is '.'
            // --------------------------------
            //
            // '.' means:
            //
            // "I don't care which character is here."
            //
            // It can represent:
            //
            // a, b, c, d, ... z
            if(ch == '.')
            {

                // Since '.' can represent ANY character,
                // we have to try all 26 possible children.
                for(int j = 0; j < 26; j++)
                {
                    // Check whether this character actually
                    // exists in the Trie.
                    //
                    // If child[j] == NULL,
                    // there is no word continuing with
                    // that character.
                    if(current->child[j] != NULL)
                    {

                        // Suppose child[j] exists.
                        //
                        // We choose this character as the
                        // character represented by '.'.
                        //
                        // We have already processed:
                        // word[i] = '.'
                        //
                        // Therefore, we need to search
                        // the remaining part:
                        //
                        // word.substr(i + 1)
                        //
                        // Example:
                        //
                        // word = ".ad"
                        //
                        // i = 0
                        //
                        // word.substr(1) = "ad"
                        //
                        // So we try:
                        //
                        // current child + "ad"
                        if(searchUtil(current->child[j],word.substr(i + 1)))
                        {
                            // If ANY one of the 26 possibilities
                            // successfully finds the word,
                            // the complete search is successful.
                            return true;
                        }
                    }
                }


                // We tried every possible character:
                //
                // a, b, c, ... z
                //
                // But none of them worked.
                return false;
            }


            // --------------------------------
            // CASE 2: Normal character
            // --------------------------------
            //
            // Example:
            // ch = 'a'
            //
            // We know exactly which child we need.
            else if(current->child[index] == NULL)
            {
                // Required character doesn't exist.
                //
                // Therefore, this word cannot exist.
                return false;
            }


            // Move to the child corresponding
            // to the current character.
            //
            // Example:
            //
            // current
            //    |
            //    b
            //
            // current moves to 'b'.
            current = current->child[index];
        }


        // We have processed every character of the search word.
        //
        // But reaching a Trie node isn't enough.
        //
        // We need to check whether a COMPLETE word
        // actually ends here.
        //
        // Example:
        //
        // Inserted:
        // "bad"
        //
        // Search:
        // "ba"
        //
        // 'b' -> 'a' exists,
        // but "ba" was never inserted.
        //
        // Therefore isEnd will be false.
        return current->isEnd;
    }


    // Public search function.
    bool search(string word)// TC ---> O(26^D × L) worst case
    {
        // Start searching from the root.
        return searchUtil(root, word);
    }
};

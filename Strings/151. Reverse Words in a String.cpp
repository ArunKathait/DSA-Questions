***********************************************APPROACH 1st***********************************************************

class Solution {
public:
    string reverseWords(string s) {
        
        // Create a stringstream from the input string.
        // It allows us to read the string word by word.
        stringstream ss(s);

        // This will store one word at a time.
        string token;

        // Store all the words in a vector.
        vector<string> words;

        // Read the string using space ' ' as delimiter.
        // getline() reads characters until it finds a space.
        while(getline(ss, token, ' '))
        {
            // Multiple spaces can produce an empty string.
            // We don't want to store empty words.
            if(!token.empty())
                words.push_back(token);
        }

        // This will store the final reversed sentence.
        string ans;

        // Start from the last word and move towards the first word.
        // Example:
        // words = ["the", "sky", "is", "blue"]
        // i = 3 → "blue"
        // i = 2 → "is"
        // i = 1 → "sky"
        // i = 0 → "the"
        for(int i = words.size() - 1; i >= 0; i--)
        {
            // Add the current word to the answer.
            ans += words[i];

            // Add a space between words.
            // Don't add a space after the last word.
            if(i != 0)
                ans += ' ';
        }

        // Return the sentence with words in reverse order.
        return ans;
    }
};

************************************************APPROACH 2nd********************************************************

class Solution {
public:
    string reverseWords(string s) {

        // Create a stringstream using the input string.
        // stringstream allows us to extract words one by one.
        stringstream ss(s);

        // This variable will store one word at a time.
        string token;

        // Store all extracted words in a vector.
        vector<string> words;

        // Extract words using the >> operator.
        //
        // >> automatically:
        // 1. Separates words using whitespace.
        // 2. Skips leading spaces.
        // 3. Ignores multiple spaces between words.
        // 4. Ignores trailing spaces.
        //
        // Example:
        // "  hello    world  "
        //
        // token = "hello"
        // token = "world"
        while(ss >> token)
        {
            // Store each word in the vector.
            words.push_back(token);
        }

        // This string will store our final answer.
        string ans;

        // Start from the last word and move towards the first word.
        //
        // Example:
        // words = ["the", "sky", "is", "blue"]
        //
        // i = 3 → "blue"
        // i = 2 → "is"
        // i = 1 → "sky"
        // i = 0 → "the"
        //
        // This reverses the ORDER of the words.
        for(int i = words.size() - 1; i >= 0; i--)
        {
            // Add the current word to the answer.
            ans += words[i];

            // Add a space between words.
            //
            // When i becomes 0, we are adding the first word.
            // We don't want an extra space after it.
            if(i != 0)
                ans += ' ';
        }

        // Return the reversed word order.
        return ans;
    }
};

/*

┌──────────────────────────────────────┐
│   WITHOUT DELIMITER                  │
├──────────────────────────────────────┤
│                                      │
│ stringstream ss(s);                  │
│                                      │
│ while(ss >> token)                   │
│                                      │
│     ↓                                │
│ Automatically extracts words         │
│ and ignores extra spaces             │
│                                      │
│ "  hello    world  "                 │
│          ↓                           │
│ ["hello", "world"]                   │
│                                      │
│ Traverse RIGHT → LEFT                │
│          ↓                           │
│ "world hello"                        │
└──────────────────────────────────────┘

🧠 Example:
Input:
"  the   sky is   blue  "

        ↓

stringstream

        ↓

words = ["the", "sky", "is", "blue"]

        ↓

Traverse from right → left

        ↓

blue → is → sky → the

        ↓

Output:
"blue is sky the"

*/

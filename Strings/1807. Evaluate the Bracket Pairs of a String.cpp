************************************************APPROACH 1st*********************************************************

class Solution {// Time  = O(N + K) average                      Space = O(N + K)
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // Create a map to store each key with its corresponding value.
        // Example: ["name", "bob"] → "name" : "bob"
        unordered_map<string, string> ump;

        // Store all key-value pairs from knowledge into the map.
        for (auto x : knowledge) 
        {
            // x[0] is the key and x[1] is the value.
            string key = x[0];
            string value = x[1];

            // Store key → value in the map.
            ump[key] = value;
        }

        // Store the index of '('.
        // -1 means we are currently outside brackets.
        int first = -1;

        // Stores the final evaluated string.
        string ans;

        // Traverse the input string character by character.
        for (int i = 0; i < s.length(); i++) 
        {
            // If '(' is found, store its index.
            if (s[i] == '(') 
            {
                first = i;
            }

            // If ')' is found, we have reached the end of a key.
            else if (s[i] == ')') 
            {
                // Extract the key between '(' and ')'.
                // Example: "(name)" → "name"
                string key = s.substr(first + 1, i - first - 1);

                // Check whether the key exists in the map.
                if (ump.find(key) != ump.end()) {

                    // If key exists, add its corresponding value.
                    ans += ump[key];
                }
                else 
                {

                    // If key does not exist, add '?'.
                    ans += "?";
                }

                // Bracket pair has been processed.
                // Reset first to -1 because we are outside brackets.
                first = -1;
            }

            // If it is a normal character and we are outside brackets,
            // add it directly to the answer.
            else if (first == -1) 
            {
                ans += s[i];
            }
        }

        // Return the final evaluated string.
        return ans;
    }
};

***********************************************APPROACH 2nd**********************************************************

class Solution {// Time  → O(N + K) average                        Space → O(N + K)
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // Store key-value pairs in an unordered_map.
        // Example: ["name", "bob"] → "name" : "bob"
        unordered_map<string, string> ump;

        // Traverse all key-value pairs in knowledge.
        for (auto &vec : knowledge) 
        {
            // vec[0] = key
            // vec[1] = value
            // Store key -> value in the map.
            ump[vec[0]] = vec[1];
        }

        // Store the final answer.
        string ans;

        // Traverse the input string.
        for (int i = 0; i < s.length(); i++) 
        {
            // If we find an opening bracket '(',
            // we need to extract the key inside the brackets.
            if (s[i] == '(') 
            {
                // Move i to the first character after '('.
                i++;

                // Store the key present inside the brackets.
                string key;

                // Keep reading characters until we find ')'.
                while (s[i] != ')') 
                {
                    // Add each character to the key.
                    key += s[i];

                    // Move to the next character.
                    i++;
                }

                // Check whether the extracted key exists in the map.
                if (ump.find(key) != ump.end()) 
                {
                    // Key exists, so add its corresponding value.
                    ans += ump[key];
                }
                else 
                {
                    // Key does not exist, so add '?'.
                    ans += "?";
                }
            }
            else 
            {
                // If it is a normal character,
                // directly add it to the answer.
                ans += s[i];
            }
        }

        // Return the final evaluated string.
        return ans;
    }
};

/*

┌──────────────────────────────────────┐
│       Evaluate Bracket Pairs         │
├──────────────────────────────────────┤
│ Pattern: String + HashMap            │
│                                      │
│ ump[key] = value                     │
│                                      │
│ Traverse string:                     │
│                                      │
│ '(' → extract key until ')'          │
│                                      │
│ Key exists → append value            │
│ Key missing → append '?'             │
│                                      │
│ Normal character → append directly   │
│                                      │
│ Key FIRST → identify bracket key     │
│ HashMap → O(1) average lookup        │
│                                      │
│ TC: O(N + K) average                 │
│ SC: O(N + K)                         │
└──────────────────────────────────────┘

*/

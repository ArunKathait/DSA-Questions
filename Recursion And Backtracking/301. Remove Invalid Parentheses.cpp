
class Solution {// Time  → O(2ⁿ × n)                              Space → O(2ⁿ × n)
public:

    // Stores all valid answers having the maximum possible length.
    // unordered_set is used to automatically remove duplicates.
    unordered_set<string> st;


    // index     -> current position in the string
    // n         -> length of the string
    // temp      -> string we are currently building
    // s         -> original string
    // count     -> balance of parentheses
    // maxLength -> maximum length of a valid string found so far
    //
    // maxLength is passed by reference because we want every
    // recursive call to update the SAME maxLength.
    void solve(int index, int n, string &temp, string &s,int count, int &maxLength)
    {

        // If count becomes negative, we have more ')' than '('.
        //
        // Example:
        // temp = ")"
        // count = -1
        //
        // This can never become a valid parentheses string,
        // so we can stop this branch immediately.
        if(count < 0)
        {
            return;
        }


        // We have processed the entire string.
        if(index == n)
        {
            // count == 0 means every '(' has a matching ')'.
            // Therefore, temp is a valid parentheses string.
            if(count == 0)
            {
                // If this valid string is LONGER than the
                // maximum length found so far...
                if(temp.length() > maxLength)
                {
                    // Update maximum length.
                    maxLength = temp.length();

                    // Previous answers were shorter,
                    // so remove them.
                    st.clear();
                }

                // If temp has the maximum length,
                // store it as one of our answers.
                //
                // unordered_set avoids duplicate strings.
                if(temp.length() == maxLength)
                {
                    st.insert(temp);
                }
            }

            // IMPORTANT:
            // We reached the end, so do not access s[index].
            return;
        }


        // If current character is NOT a parenthesis,
        // such as 'a', 'b', 'c', etc.,
        // we cannot remove it.
        //
        // Therefore, we MUST keep it.
        if(s[index] != '(' && s[index] != ')')
        {
            // Add the normal character to our answer.
            temp.push_back(s[index]);

            // Move to the next character.
            // count does not change because this is
            // not a parenthesis.
            solve(index + 1, n, temp, s, count, maxLength);

            // Backtracking:
            // Remove the character before returning to
            // the previous recursive state.
            temp.pop_back();

            return;
        }


        // ------------------------------------------------
        // OPTION 1: KEEP the current parenthesis
        // ------------------------------------------------

        // Add current '(' or ')' to temp.
        temp.push_back(s[index]);

        // Update the parenthesis balance:
        //
        // '(' → count + 1
        // ')' → count - 1
        //
        // Then move to the next character.
        solve(index + 1,n,temp,s,count + (s[index] == '(' ? 1 : -1),maxLength);

        // Backtracking:
        // Remove the parenthesis that we just added.
        temp.pop_back();


        // ------------------------------------------------
        // OPTION 2: REMOVE the current parenthesis
        // ------------------------------------------------

        // We don't add s[index] to temp.
        // Therefore, the count also remains unchanged.
        //
        // Move directly to the next character.
        solve(index + 1,n,temp,s,count,maxLength);
    }


    vector<string> removeInvalidParentheses(string s)
    {
        // Length of the input string.
        int n = s.length();

        // Temporary string used to build possible answers.
        string temp;

        // Initially, we haven't found any valid string.
        int maxLength = 0;

        // Start recursion from index 0.
        //
        // count = 0 because initially there are
        // no open parentheses.
        solve(0, n, temp, s, 0, maxLength);

        // Convert unordered_set into vector and return.
        vector<string> ans(st.begin(), st.end());

        return ans;
    }
};

/*

┌─────────────────────────────────────┐
│    REMOVE INVALID PARENTHESES       │
├─────────────────────────────────────┤
│                                     │
│ For each '(' or ')':                │
│        KEEP  OR  REMOVE             │
│             ↓                       │
│       Backtracking                  │
│                                     │
│ count = balance                     │
│ '(' → count++                       │
│ ')' → count--                       │
│                                     │
│ count < 0 → STOP branch             │
│                                     │
│ index == n:                         │
│   count == 0 → valid                │
│                                     │
│ Keep ONLY maximum-length strings    │
│ → minimum removals                  │
│                                     │
│ maxLength → pass by reference       │
│ unordered_set → remove duplicates   │
│                                     │
│ Time  : O(2ⁿ × n)                   │
│ Space : O(2ⁿ × n)                   │
└─────────────────────────────────────┘

Memory Trick:
KEEP / REMOVE → BALANCE → VALIDATE
→ MAX LENGTH → STORE

*/

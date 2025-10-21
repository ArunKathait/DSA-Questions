
class Solution {// TC--->O(N * L * 4) ~ O(N * L)                      SC--->O(N)
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Convert the list of valid genes (bank) into an unordered_set for O(1) lookup.
        unordered_set<string> set(bank.begin(), bank.end());

        // Queue for BFS traversal; stores a pair of (gene string, number of mutations so far)
        queue<pair<string,int>> q;

        // Start BFS from the startGene with 0 mutations
        q.push({startGene, 0});  

        // Perform Breadth-First Search (BFS)
        while(!q.empty())
        {
            string gene = q.front().first;  // Current gene sequence
            int steps = q.front().second;   // Number of mutations (steps) taken so far
            q.pop();

            // If the current gene matches the target gene, return the number of steps
            if(gene == endGene)
            {
                return steps;
            }

            // Possible gene characters (only these four are allowed)
            string choices = "ACGT";

            // Try mutating each character of the current gene
            for(int i = 0; i < gene.length(); i++)
            {
                string temp = gene;  // Copy current gene to modify

                // Try replacing the i-th character with each possible base (A, C, G, T)
                for(char ch : choices)
                {
                    temp[i] = ch;  // Change one character

                    // If the new gene exists in the bank (is valid and unvisited)
                    if(set.find(temp) != set.end())
                    {
                        set.erase(temp);  // Mark as visited (avoid revisiting)
                        q.push({temp, steps + 1});  // Add to BFS queue with incremented step count
                    }
                }
            } 
        }

        // If we finish BFS without finding endGene, mutation path doesn't exist
        return -1;
    }
};

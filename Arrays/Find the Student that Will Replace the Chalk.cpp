
class Solution {// TC--->O(N)                          SC--->O(1)
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Get the number of elements in the chalk vector.
        int n = chalk.size();
        
        // Calculate the total sum of all elements in the chalk vector.
        long long sum = 0;
        for(auto &x:chalk)
        {
            sum += x;
        }
        
        // Calculate the remainder of k after dividing by the total sum of chalk.
        // This is because if k is larger than the total sum, we can ignore full rounds
        // and just focus on the remainder to find the starting point.
        int remainder = k%sum;
        
        // Initialize the index to 0. This will be used to find the student 
        // who will use up the remaining chalk.
        int index = 0;
        
        // Iterate through the chalk vector until we find the student who will
        // run out of chalk.
        while(chalk[index] <= remainder)
        {
            // Subtract the amount of chalk the current student will use from the remainder.
            remainder -= chalk[index];
            
            // Move to the next student.
            index++;
        }
        
        // Return the index of the student who will run out of chalk.
        return index;
        
    }
};

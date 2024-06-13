***********************************************APPROACH 1st(USING SORTING)*****************************************

class Solution {// TC--->O(NlogN)            SC--->O(1)
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        // Sort both seats and students arrays to align the lowest seats with the lowest students
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        
        // Variable to store the total number of moves needed
        int moves = 0;
        
        // Iterate through the sorted lists of seats and students
        for(int i=0;i<seats.size();i++)
        {
            // Calculate the absolute difference between the seat position and student position
            // Add this difference to the total moves
            moves += abs(seats[i] - students[i]);
        }
        
        // Return the total number of moves needed to seat all students
        return moves;
    }
};


********************************************APPROACH 2nd**********************************************************

class Solution {// TC--->O(N)                    SC--->O(1)
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        // Frequency arrays to count the occurrences of seat and student positions
        vector<int>seatsFreq(101,0);
        vector<int>studentsFreq(101,0);
        
        // Populate the frequency array for seats
        for(int i=0;i<seats.size();i++)
        {
            seatsFreq[seats[i]]++;
        }
        
        // Populate the frequency array for students
        for(int j=0;j<students.size();j++)
        {
            studentsFreq[students[j]]++;
        }
        
        // Initialize pointers for seats and students frequency arrays
        int i=0,j=0;
        
        // Variable to store the total number of moves needed
        int moves = 0;
        
        // Loop through the frequency arrays to match seats and students
        while(i <= 100 && j <= 100)
        {
            // If no seats at position i, move to the next position
            if(seatsFreq[i] == 0)
            {
                i++;
            }
            // If no students at position j, move to the next position
            if(studentsFreq[j] == 0)
            {
                j++;
            }
            
            // If there are seats and students at positions i and j
            if(i <= 100 && j <= 100 && seatsFreq[i] != 0 && studentsFreq[j] != 0)
            {
                // Calculate the moves needed for this seat-student pair
                moves += abs(j-i);
                
                // Decrease the frequency count for the matched seat and student
                seatsFreq[i]--;
                studentsFreq[j]--;
            }
        }
        
         // Return the total number of moves needed to seat all students
        return moves;
    }
};

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Initialize counters for students preferring sandwiches of type 1 and type 0
        int student_1 = 0;
        int student_0 = 0;
        
        // Count the number of students preferring each type of sandwich
        for(auto x:students)
        {
            if(x == 1)
            {
                // Increment counter for students preferring sandwich type 1
                student_1++;
            }
            else
            {
                // Increment counter for students preferring sandwich type 0
                student_0++;
            }
        }
        
        // Iterate through each sandwich preference
        for(auto it:sandwiches)
        {
            // If the current sandwich preference is type 1
            if(it == 1)
            {   
                // If there are no students left who prefer type 1 sandwiches
                if(student_1 == 0)
                {
                    // Return the count of students preferring type 0 sandwiches who couldn't get their sandwiches
                    return student_0; 
                }
                else
                {
                    // Serve a type 1 sandwich to a student by decrementing the count of students preferring type 1 sandwiches
                    student_1--; 
                }
            }
            else// If the current sandwich preference is type 0
            {        
                // If there are no students left who prefer type 0 sandwiches
                if(student_0 == 0)
                {
                    // Return the count of students preferring type 1 sandwiches who couldn't get their sandwiches
                    return student_1;
                }
                else
                {
                    // Serve a type 0 sandwich to a student by decrementing the count of students preferring type 0 sandwiches
                    student_0--;
                }
            }
        }
        
        // If all students get their sandwiches, return 0
        return 0;
    }
};

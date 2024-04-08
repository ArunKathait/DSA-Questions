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
            // If the sandwich preference is 1
            if(it == 1)
            {   
                // If no students prefer sandwich type 1
                if(student_1 == 0)
                {
                    // Return the remaining count of students preferring sandwich type 0
                    return student_0; 
                }
                else
                {
                    // Decrease the count of students preferring sandwich type 1
                    student_1--; 
                }
            }
            else// If the sandwich preference is 0
            {        
                // If no students prefer sandwich type 0
                if(student_0 == 0)
                {
                    // Return the remaining count of students preferring sandwich type 1
                    return student_1;
                }
                else
                {
                    // Decrease the count of students preferring sandwich type 0
                    student_0--;
                }
            }
        }
        
        // Return 0 if all students have been accounted for
        return 0;
    }
};


class Solution {// TC ---> O(n × m)                            SC ---> O(1)
public:
    int numberOfBeams(vector<string>& bank) {
        // Total number of rows in the security bank matrix
        int totalRows = bank.size();

        // To store the final count of laser beams  
        int totalBeams = 0; 

        // Number of devices ('1's) in the previous non-empty row          
        int prevRowDevices = 0;       

        // Traverse each row of the bank
        for (int row = 0; row < totalRows; row++) 
        {
            // Current row string (e.g., "011001")
            string currentRow = bank[row]; 

            // Count of devices ('1's) in the current row 
            int currentRowDevices = 0;      

            // Count devices ('1's) in the current row
            for (char cell : currentRow) 
            {
                if (cell == '1') 
                {
                    currentRowDevices++;
                }
            }

            // Laser beams between two rows = devices_in_previous_row * devices_in_current_row
            totalBeams += (prevRowDevices * currentRowDevices);

            // Update previous row count only if current row has at least one device
            if (currentRowDevices != 0) 
            {
                prevRowDevices = currentRowDevices;
            }
        }
        
        // Return total number of laser beams
        return totalBeams;  
    }
};

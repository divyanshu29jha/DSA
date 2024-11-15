//Simple Simulation
//T.C : O(max(rows,cols)^2)
//S.C : O(1) (I am not considering the result matrix we have to return as result)
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart){
        // {0, 1}:EAST, {1, 0}:SOUTH, {0, -1}:WEST, {-1, 0}:NORTH
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<vector<int>> result;  
        int step = 0;  // how much steps to move
        int dir  = 0;  // which direction

        result.push_back({rStart, cStart});

        while(result.size() < rows * cols){
            if (dir == 0 || dir == 2) step++;  // When we move EAST or WEST, we need to increase our steps by 1
 
            for(int i = 0; i < step; i++){
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)   // check valid (cell inside grid or not)
                    result.push_back({rStart, cStart});
            }

            dir = (dir + 1) % 4;   // turn to next direction
        }

        return result;
    }
};

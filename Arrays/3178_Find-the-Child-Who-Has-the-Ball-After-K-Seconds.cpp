// Time complexity: O(1) using Math
// After (n-1) passes, ball reaches right end. 
// After (n-1) more passes i.e total (2n-2) passes, the ball reaches the start position again.
class Solution {
public:
    int numberOfChild(int n, int k) {
        k = k % (2*n - 2);  // for cases when k>(2n - 2)
        
        int pass;
        if(k <= n-1){
            pass = k;
        }
        else{
            pass = (2*n - 2) - k;    // dry run with an example to find this logic
        }

        return pass; 
    }
};


// Time complexity: O(k) - Depends on the number of seconds.
// If direction is 1, move right. If -1, move left.
// If position is n-1 (last child), set direction = -1 (start moving left).
// If position is 0 (first child), set direction = 1 (start moving right).
/*
class Solution {
public:
    int numberOfChild(int n, int k) {
        int position = 0;   // first child
        int direction = 1;  // moving right
    
        for (int i = 0; i < k; i++) {
            position += direction;

            if (position == n - 1) {   // Reverse direction if the ball reaches either end
                direction = -1;
            } 
            else if (position == 0) {
                direction = 1;
            }
        }
    
        return position;
    }
};
*/
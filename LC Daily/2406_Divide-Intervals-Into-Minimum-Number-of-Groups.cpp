// M-1) Brute force --> Gives TLE
// T.C: O(n^2), S.C: O(n)
// The minimum number of groups we need is equivalent to the maximum number of intervals that overlap at some point. 
/*
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<int> endPoints;   // stores end point of each group    
        for(auto interval : intervals){
            int start = interval[0];
            int end = interval[1];
            if(endPoints.size() == 0){
                endPoints.push_back(end);
                continue;
            }

            bool found = false;
            for(int i=0; i<endPoints.size(); i++){
                if(start > endPoints[i]){   // this interval lies can lie in same group
                    endPoints[i] = end;    
                    found = true;
                    break;
                }
            }
            if(found == false) 
                endPoints.push_back(end);            
        }

        return endPoints.size();    // no. of groups will be equal to no. of end points
    }
};
*/


// M-2) (sorting and using heap)
//T.C : O(nlogn), S.C : O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));  // O(n*logn)

        priority_queue<int, vector<int>, greater<int>> pq;   //stores end point of each group

        for(auto& interval : intervals){  // O(n)
            int start = interval[0];
            int end   = interval[1];

            if(!pq.empty() && pq.top() < start){
                pq.pop();  // O(logn)
            }

            pq.push(end);  // O(logn)
        }

        return pq.size();
    }
};



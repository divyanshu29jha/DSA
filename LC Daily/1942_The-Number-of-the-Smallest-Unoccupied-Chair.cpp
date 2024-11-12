// Approach-1 (Naive O(n^2) approach that comes to mind first)
// T.C : O(n^2)
// S.C : O(n)
// We need to sort the times based on arrival time but we don't want to loose the targetFriend number after sorting. So, store the arrival time
// of targetFriend because it's given in the question that each arrival time is distinct.
/*
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> endTimes(n, -1);   // at max we will have 0 to n-1 chairs
        
        int targetArrivalTime = times[targetFriend][0];
        sort(times.begin(), times.end());   // Sort based on arrival time
        
        for(vector<int> time : times){
            int arrival = time[0];
            int depart  = time[1];

            for(int i=0; i<n; i++){   // find the first unoccupied chair (traverse through endTimes vector)
                if(endTimes[i] <= arrival){
                    endTimes[i] = depart;   // update with current friend depart time
                    if(arrival == targetArrivalTime)
                        return i;
                    break;
                }
            }
        }

        return -1;
    }
};
*/


// https://www.youtube.com/watch?v=NePJRPCuOwg
// For dry run: [[1,10], [2,6], [5,7], [8,9]], targetFriend = 3
// Approach-2 (Using min-heaps)
// T.C : O(nlogn)
// S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;

    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        priority_queue<P, vector<P>, greater<P>> occupied;      // {departTime, chairNo}
        priority_queue<int, vector<int>, greater<int>> free;     // min heap of unoccupied chairs
        
        int targetFriendArrival = times[targetFriend][0];
        sort(times.begin(),times.end());  // Sort based on arrival time
        
		int chairNo = 0;

        for(int i = 0; i < n; i++){
            int arrival  = times[i][0];
            int depart   = times[i][1];
            
            while(!occupied.empty() && occupied.top().first <= arrival){
                free.push(occupied.top().second);   //this chair is now free
                occupied.pop();
            }

            if(free.empty()){
                occupied.push({depart, chairNo});
                if(arrival == targetFriendArrival)
                    return chairNo;
                chairNo++;
            } 
            else{
                int leastChairAvailable = free.top();
                free.pop();
                if(arrival == targetFriendArrival) 
                    return leastChairAvailable;
                occupied.push({depart, leastChairAvailable});
            }
        }

        return -1;
    }
};


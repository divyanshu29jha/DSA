// M-1) Priority Queue
// T.C : O(n + klogn), S.C: O(n)
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        // for(int i=0; i<nums.size(); i++){
        //     pq.push(nums[i]);   // O(logn)
        // }

        priority_queue<int> pq(nums.begin(), nums.end());   // First time creation of heap "heapify" is O(n). But in Java, it is O(nlogn)
        long long ans = 0;
        for(int i=0; i<k; i++){
            int num = pq.top();  // O(1)
            pq.pop();  // O(1)
            ans += num;
            pq.push(ceil(double(num)/3));   // O(logn)
        }

        return ans;
    }
};


// M-2) Multiset
/*
class Solution {
public:
    long long maxKelements(vector<int>& a, int k) {
        long long ans=0;
        multiset<int>s;
        for(auto i:a){
            s.insert(i);
        }
        while(k-- && !s.empty()){
            auto it=prev(s.end());
            int cur=*it;
            s.erase(it);
            ans+=cur;
            s.insert((cur+2)/3);
        }
        return ans;
    }
};
*/
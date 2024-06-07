// WARNING: Wrong Approach 
// Time complexity of O(n*m), where n is the number of children and m is the number of cookies (can give TLE).
// Your approach attempts to assign each cookie to the first unsatisfied child whose greed factor is less than or equal to the size of the cookie. But, it fails to distribute the cookies in an optimal way. To maximize the number of content children, you should assign the smallest possible cookie that satisfies each child's greed factor.
/*
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        vector<int> satisfy(n);   // initialize with all 0's

        int cnt = 0;  
        for(int j=0; j<s.size(); j++){    // 'j' iterates through s
            for(int i=0; i<g.size(); i++){   // 'i' keeps track of g and satify vectors
                if(s[j] >= g[i] && satisfy[i] == 0){
                    cnt++;
                    satisfy[i] = 1;
                    break;   // Important to add break : g = [1,2,3] and s[3]. If we don't add break, then cnt = 3.
                }
            }
        }

        return cnt;       
    }
};
*/

// Sorting: Sorting both arrays helps in efficiently matching the smallest available cookie to the smallest need.
// Two Pointers: Pointer i tracks the current child (from the g array). Pointer j tracks the current cookie (from the s array).
// Logic: If the current cookie (s[j]) can satisfy the current child (g[i]), increment i to move to the next child.
// Always increment j to move to the next cookie, regardless of whether the current child was satisfied or not.
// Time Complexity: O(n.log⁡n+m.log⁡m + m + n) =  O(n.log⁡n+m.log⁡m), where n is the size of the array g and m is the size of the array s.
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {    
            if (s[j] >= g[i]) {
                i++;
            }
            j++;
        }

        return i; 
    }
};
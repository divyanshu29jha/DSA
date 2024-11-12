class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> ans;
        long long a=A, b=B;
        
        // long long gcd;
        // for(int i=1; i<=min(A,B); i++){      // O(min(A,B))
        //     if(A%i==0 && B%i==0)
        //         gcd = i;
        // }
        
        
        long long gcd;     // Euclidean Algorithm
        while(A>0 && B>0){   
            if(A>B) A=A%B;
            else B=B%A;
        }
        if(A==0)  gcd=B;
        else gcd= A;
        
        long long lcm=(a*b)/gcd;
        
        ans.push_back(lcm);
        ans.push_back(gcd);
        
        return ans;
    }
};
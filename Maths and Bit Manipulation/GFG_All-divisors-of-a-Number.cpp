class Solution {
  public:
    // T.C: O(n)  --> TLE
    /*
    void print_divisors(int n) {
       for(int i=1 ; i <= n; i++){
           if(n % i == 0)
            cout<< i <<" ";
       }
    }
    */
    
    
    // Factors/Divisors of a number n exist till n/2
    // T.C: O(n/2)  --> TLE
    /*
    void print_divisors(int n) {
       for(int i=1 ; i <= n/2; i++){
           if(n % i == 0)
            cout<< i << " ";
       }
       cout<< n;
    }
    */
    
    
    // T.C: O(sqrt(n))
    void print_divisors(int n) {
       vector<int> divisors;

        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                divisors.push_back(i);  // i is a divisor
                if (i != n / i) 
                    divisors.push_back(n / i);  // n/i is also a divisor, if distinct
            }
        }
        
        sort(divisors.begin(), divisors.end());

        for (int divisor : divisors) {
            cout << divisor << " ";
        }
    }
};
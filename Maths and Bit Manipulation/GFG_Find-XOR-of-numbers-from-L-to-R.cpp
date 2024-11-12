// T.C: O(1), S.C: O(1)
class Solution {
  public:
    int getXOR(int n){
        if(n%4 == 1) return 1;
        else if(n%4 == 2) return n+1;
        else if(n%4 == 3) return 0;
        else return n;
    }
    
    int findXOR(int l, int r) {
        if(l == 0){
            return getXOR(r);
        }
        else{
            return getXOR(r) ^ getXOR(l-1);
        }
    }
};
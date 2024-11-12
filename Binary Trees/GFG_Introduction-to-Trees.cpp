// n-th level consists of 2^(n-1) nodes.
class Solution {
  public:
    int countNodes(int i) {
        return pow(2, i-1);
    }
};

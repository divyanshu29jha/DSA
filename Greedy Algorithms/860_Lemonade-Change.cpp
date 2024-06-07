// WARNING: Wrong Approach 
// find() and erase() method  has a time complexity of O(n)
// Your code tries to find and remove a $5 and a $10 bill (but not three $5 bills), using find and erase, which is inefficient and can lead to errors if the bills are not found as expected.
/*
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change;
        
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                change.push_back(5);
            }
            
            if(bills[i] == 10){
                auto it = find(change.begin(), change.end(), 5);
                if(it != change.end()){
                    change.push_back(10);
                    change.erase(it);
                }
                else{
                    return false;
                }
            }

            if(bills[i] == 20){
                auto it1 = find(change.begin(), change.end(), 5);
                auto it2 = find(change.begin(), change.end(), 10);
                if(it1 != change.end() && it2 != change.end()){
                    change.push_back(20);
                    change.erase(it1);
                    change.erase(it2);
                }
                else{
                    return false;
                }
            }            
        }

        return true;
    }
};
*/


// Initialization: Two counters, five and ten, to keep track of $5 and $10 bills.
// Iterate through bills:
// $5 bill: Increment the five counter.
// $10 bill: Check if a $5 bill is available. If yes, decrement the five counter and increment the ten counter. If not, return false.
// $20 bill: Prefer giving one $10 bill and one $5 bill as change. If not possible, give three $5 bills. If neither is possible, return false.
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;   // counters to keep track of change (no need for $20 as it will not be returned in change)
        
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five > 0){
                    ten++;
                    five--;
                }
                else{
                    return false;
                }
                
            }
            else{   // bill == 20
                if(ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                else if(five >= 3) {
                    five -= 3;
                } 
                else{
                    return false;
                }
            }
        }

        return true;
    }
};
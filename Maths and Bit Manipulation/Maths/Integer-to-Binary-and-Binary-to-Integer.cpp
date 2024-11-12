#include <bits/stdc++.h>
using namespace std;

string intToBinary(int num){
    if(num == 0) return "0";
    
    string ans = "";
    while(num > 0){
        ans = (num % 2 == 0 ? "0" : "1") + ans;
        num /= 2;
    }
    
    return ans;
}

int binaryToInt(string &binary){
    int len = binary.length();
    int ans = 0;
    
    for(int i = 0; i < len; i++){
        if (binary[len-1-i] == '1')
            ans += pow(2, i);
    }
    
    return ans;
}

int main(){
    int num = 10;
    string binary = intToBinary(num);
    cout << "Integer: " << num << " -> Binary: " << binary << endl;

    string binaryInput = "1010";
    int integer = binaryToInt(binaryInput);
    cout << "Binary: " << binaryInput << " -> Integer: " << integer << endl;

    return 0;
}

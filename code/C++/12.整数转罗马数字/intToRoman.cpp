#include <iostream>
#include <vector>

using namespace std;

string intToRoman(int num) {
    vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string res = "";
    int index = 0;
    while(index < 13){
        while(num >= nums[index]){
            res += romans[index];
            num -= nums[index];
        }
        index++;
    }
    return res;
}

int main(){
    cout<<intToRoman(345);
    return 0;
}

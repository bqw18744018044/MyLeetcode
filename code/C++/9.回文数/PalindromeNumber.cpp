#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if(x<0)return false;
    long long rev = 0;
    int tmp = x;
    while(tmp!=0){
        rev = rev*10+tmp%10;
        if(rev>INT_MAX)return false;
        tmp/=10;
    }
    return rev==x;
}

int main(){
    cout<<isPalindrome(1234321);
    return 0;
}

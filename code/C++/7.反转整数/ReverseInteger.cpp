#include <iostream>

using namespace std;

int reverse(int x) {
    int rev = 0;
    while(x!=0){
        int pop = x % 10;
        x /= 10;
        // �ж�������
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int main(){
    cout<<reverse(-123456);
    return 0;
}

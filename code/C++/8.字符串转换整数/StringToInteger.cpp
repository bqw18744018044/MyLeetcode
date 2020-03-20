#include <iostream>

using namespace std;

int myAtoi(string str) {
    if(str.size()==0)return 0;
    int start = 0, end = 0;//用于记录数字在字符串str中的起始位置
    int sign = 1; //记录数字的正负号
    while(str[start]==' ')start++; //去除开头的空白符
    // 处理正负号
    if(str[start]=='-')sign = -1, start++;
    else if(str[start]=='+')start++;
    end = start;
    while(str[end]<='9'&&str[end]>='0')end++; //确定数字的结尾位置
    end--;
    string substr = str.substr(start,end-start+1); //将数字取出
    // 将字符串的数字转换为int
    long long res = 0;
    for(auto s:substr){
        res = res*10+(s-'0');
        // 溢出判断
        if(sign*res>=INT_MAX)return INT_MAX;
        if(sign*res<=INT_MIN)return INT_MIN;
    }
    return sign*res;
}

int main(){
    string str="2147483649";
    cout<<myAtoi(str);
    return 0;
}

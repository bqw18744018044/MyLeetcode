#include <iostream>

using namespace std;

int myAtoi(string str) {
    if(str.size()==0)return 0;
    int start = 0, end = 0;//���ڼ�¼�������ַ���str�е���ʼλ��
    int sign = 1; //��¼���ֵ�������
    while(str[start]==' ')start++; //ȥ����ͷ�Ŀհ׷�
    // ����������
    if(str[start]=='-')sign = -1, start++;
    else if(str[start]=='+')start++;
    end = start;
    while(str[end]<='9'&&str[end]>='0')end++; //ȷ�����ֵĽ�βλ��
    end--;
    string substr = str.substr(start,end-start+1); //������ȡ��
    // ���ַ���������ת��Ϊint
    long long res = 0;
    for(auto s:substr){
        res = res*10+(s-'0');
        // ����ж�
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

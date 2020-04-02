 #include <iostream>
 #include <vector>

 using namespace std;

 // 判断单个字符是否能够解码
bool canDecode_one(char ch){
    return (ch-'0'>0)&&(ch-'0')<=9;
}
// 判断两个字符是否能够解码
bool canDecode_two(char ch1, char ch2){
    return ch1=='1'||(ch1=='2'&&ch2-'0'>=0&&ch2-'0'<=6);
}

int numDecodings(string s) {
    int size = s.size();
    if(size==0)return 1;
    if(size==1){
        if(canDecode_one(s[0]))return 1;
        else return 0;
    }
    vector<int> dp(size);
    if(canDecode_one(s[0]))dp[0]=1;
    dp[1] = (canDecode_one(s[1])?dp[0]:0)+(canDecode_two(s[0],s[1])?1:0);
    for(int i=2;i<size;++i){
        dp[i] = (canDecode_one(s[i])?dp[i-1]:0)+(canDecode_two(s[i-1],s[i])?dp[i-2]:0);
    }
    return dp[size-1];
}

int main(){
    string s="226";
    cout<<numDecodings(s);
    return 0;
}

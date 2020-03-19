#include <iostream>
#include <vector>

using namespace std;

int expandAroundCenter(string s,int left,int right){
    /*返回以(left,right)为中的最长回文子串的长度*/
    int l=left, r=right;
    if(s[l]!=s[r])return 0;
    while(l>=0&&r<s.size()&&s[l]==s[r])l--,r++;
    return r-l-1; // 因为l和r均会多扩展1位，因此长度应该为r-l+1-2=r-l-1
}

string longestPalindrome_expand(string s){
    int size = s.size();
    if(size<=1)return s;
    int start = 0, end = 0; // 记录最长子串的起始和终止位置
    for(int i=0;i<size;i++){
        int l1 = expandAroundCenter(s,i,i);
        int l2 = expandAroundCenter(s,i,i+1);
        int l = max(l1,l2);
        if(l>end-start+1){
            // 分情况整理后的计算位置公式
            start = i - (l-1)/2;
            end = i + l/2;
        }
    }
    return s.substr(start,end-start+1);
}

string longestPalindrome_dp(string s){
    int size = s.size();
    if(size<=1)return s;
    int start = 0, maxLen = 1; // 用于记录当前最长回文子串的起始位置和长度
    vector<vector<bool>> dp(size, vector<bool>(size)); //dp[i][j]表示子串i-j是否是回文
    // 对长度为1和2的子串进行初始化
    for(int i=0;i<size;i++){
        dp[i][i] = true;
        if(i<size-1&&s[i]==s[i+1]){
            dp[i][i+1] = true;
            start = i;
            maxLen = 2;
        }
    }
    // 开始逐长度判断
    for(int l=3;l<=size;l++){
        for(int i=0;i<size-l+1;i++){
            int j=i+l-1;
            if(s[i]==s[j]&&dp[i+1][j-1]==true){
                dp[i][j]=true;
                start = i;
                maxLen = l;
            }
        }
    }
    return s.substr(start, maxLen);
}

int main(){
    string s = "babad";
    cout<<longestPalindrome_dp(s)<<endl;
    cout<<longestPalindrome_expand(s);
    return 0;
}

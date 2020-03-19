#include <iostream>
#include <vector>

using namespace std;

int expandAroundCenter(string s,int left,int right){
    /*������(left,right)Ϊ�е�������Ӵ��ĳ���*/
    int l=left, r=right;
    if(s[l]!=s[r])return 0;
    while(l>=0&&r<s.size()&&s[l]==s[r])l--,r++;
    return r-l-1; // ��Ϊl��r�������չ1λ����˳���Ӧ��Ϊr-l+1-2=r-l-1
}

string longestPalindrome_expand(string s){
    int size = s.size();
    if(size<=1)return s;
    int start = 0, end = 0; // ��¼��Ӵ�����ʼ����ֹλ��
    for(int i=0;i<size;i++){
        int l1 = expandAroundCenter(s,i,i);
        int l2 = expandAroundCenter(s,i,i+1);
        int l = max(l1,l2);
        if(l>end-start+1){
            // ����������ļ���λ�ù�ʽ
            start = i - (l-1)/2;
            end = i + l/2;
        }
    }
    return s.substr(start,end-start+1);
}

string longestPalindrome_dp(string s){
    int size = s.size();
    if(size<=1)return s;
    int start = 0, maxLen = 1; // ���ڼ�¼��ǰ������Ӵ�����ʼλ�úͳ���
    vector<vector<bool>> dp(size, vector<bool>(size)); //dp[i][j]��ʾ�Ӵ�i-j�Ƿ��ǻ���
    // �Գ���Ϊ1��2���Ӵ����г�ʼ��
    for(int i=0;i<size;i++){
        dp[i][i] = true;
        if(i<size-1&&s[i]==s[i+1]){
            dp[i][i+1] = true;
            start = i;
            maxLen = 2;
        }
    }
    // ��ʼ�𳤶��ж�
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

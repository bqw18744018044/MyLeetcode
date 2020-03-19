#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int size = s.size();
    if(size<=1)return size;
    unordered_map<char,int> hmap; // 用于记录字符上一次出现的位置
    int curMaxLength = 0; // 存储上一个位置的最长子串的长度
    int MaxLength = 0; // 存在全局的最长子串长度
    for(int i=0;i<size;i++){
        // 之前未出现过该字符
        if(hmap.find(s[i])==hmap.end())curMaxLength++;
        else{
            int start = i - curMaxLength;
            if(hmap[s[i]]<start)curMaxLength++; // 之前出现过该字符，但是不影响当前的最长子串长度
            else curMaxLength = i-hmap[s[i]]; // 之前出现过该字符，并且影响当前的最长子串长度
        }
        hmap[s[i]] = i; //更少字符s[i]的出现位置
        if(curMaxLength>MaxLength)MaxLength=curMaxLength;
    }
    return MaxLength;
}

int main(){
    string s = "abba";
    cout<<lengthOfLongestSubstring(s);
}

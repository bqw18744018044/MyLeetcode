#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int size = s.size();
    if(size<=1)return size;
    unordered_map<char,int> hmap; // ���ڼ�¼�ַ���һ�γ��ֵ�λ��
    int curMaxLength = 0; // �洢��һ��λ�õ���Ӵ��ĳ���
    int MaxLength = 0; // ����ȫ�ֵ���Ӵ�����
    for(int i=0;i<size;i++){
        // ֮ǰδ���ֹ����ַ�
        if(hmap.find(s[i])==hmap.end())curMaxLength++;
        else{
            int start = i - curMaxLength;
            if(hmap[s[i]]<start)curMaxLength++; // ֮ǰ���ֹ����ַ������ǲ�Ӱ�쵱ǰ����Ӵ�����
            else curMaxLength = i-hmap[s[i]]; // ֮ǰ���ֹ����ַ�������Ӱ�쵱ǰ����Ӵ�����
        }
        hmap[s[i]] = i; //�����ַ�s[i]�ĳ���λ��
        if(curMaxLength>MaxLength)MaxLength=curMaxLength;
    }
    return MaxLength;
}

int main(){
    string s = "abba";
    cout<<lengthOfLongestSubstring(s);
}

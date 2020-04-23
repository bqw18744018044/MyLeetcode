#include <iostream>
#include <vector>

using namespace std;

void restoreIpAddressesCore(int start, int depth, string path, string s, vector<string>& res){
    if(depth==4){// ����Ѿ������4�����ֵ�ȷ������ôIP��ַҲ��ȷ����
        path.pop_back();//ɾ�����ڵ�'.'
        res.push_back(path);
        return;
    }
    int n = s.size();
    // ��ǰ����λ������СֵΪmax(1, �������־�Ϊ��λ����ʣ���µ�����)
    int endMin = max(start + 1, n - (3 - depth) * 3);
    int endMax = min(start + 3, n - (3 - depth));
    for(int end = endMin; end <= endMax; end++) {
        string split = s.substr(start, end - start); // end - start ��ʾ��ȡ����
        int splitLen = split.size();
        if(splitLen > 1 && split[0] == '0') { //������>1ʱ, ��һλ����Ϊ0
            break;
        }
        if(stoi(split) <= 255) {
            restoreIpAddressesCore(end, depth + 1, path + (split + '.'), s, res);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    int size = s.size();
    restoreIpAddressesCore(0,0,"",s, res);
    return res;
}

int main(){
    vector<string> res = restoreIpAddresses("25525511135");
    for(auto r:res)cout<<r<<endl;
    return 0;
}

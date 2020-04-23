#include <iostream>
#include <vector>

using namespace std;

void restoreIpAddressesCore(int start, int depth, string path, string s, vector<string>& res){
    if(depth==4){// 如果已经完成了4个数字的确定，那么IP地址也就确定了
        path.pop_back();//删除多于的'.'
        res.push_back(path);
        return;
    }
    int n = s.size();
    // 当前数字位数的最小值为max(1, 后续数字均为三位数所剩余下的数字)
    int endMin = max(start + 1, n - (3 - depth) * 3);
    int endMax = min(start + 3, n - (3 - depth));
    for(int end = endMin; end <= endMax; end++) {
        string split = s.substr(start, end - start); // end - start 表示截取长度
        int splitLen = split.size();
        if(splitLen > 1 && split[0] == '0') { //当长度>1时, 第一位不能为0
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

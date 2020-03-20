#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    /*模仿整个排列的过程*/
    if(numRows==1)return s;
    vector<string> rows(min(numRows,int(s.size())));
    int curRow = 0;
    bool goingDown = false;
    for(auto c:s){
        rows[curRow] += c;
        if(curRow==0||curRow==numRows-1)goingDown = !goingDown;
        curRow += goingDown?1:-1;
    }
    string res;
    for(string row:rows)res += row;
    return res;
}

int main(){
    string s = "LEETCODEISHIRING";
    int numRows = 4;
    cout<<convert(s, numRows);
    return 0;
}

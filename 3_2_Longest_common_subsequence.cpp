#include <iostream>
#include <vector>
using namespace std;
int LCS(string s1, string s2) {
        vector<vector<int>> M(2, vector<int>(s1.length() + 1, 0));

        for (int i = 1; i <= s2.length(); i++) {
            M[i % 2][0] = 0;
            for (int j = 1; j <= s1.length(); j++) {
                if (s1[j - 1] == s2[i - 1]) {
                    M[i % 2][j] = M[(i - 1) % 2][j - 1] + 1;
                } else {
                    M[i % 2][j] = max(M[(i - 1) % 2][j - 1],
                                max(M[(i - 1) % 2][j], M[i % 2][j - 1]));
                }
            }
        }
        return M[s2.length() % 2][s1.length()];
}


int main(){
    string x ,y;
    cin >> x >> y;
    //vector<vector<int>> dp(x.size()+1,vector<int>(y.size()+1,-1));
    if(x.size() > y.size()){
        cout <<LCS(x,y) << endl;
    }else{
        cout <<LCS(y,x) << endl;
    }
}
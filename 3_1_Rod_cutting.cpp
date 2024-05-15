#include <iostream>
#include <vector>
using namespace std;

int main(){
    int length, price, rodLength;
    vector<int> p;
    vector<int> r;
    cin >> rodLength;
    p.push_back(0);
    while(cin >> length >> price){
        if(length == 0 && price == 0)break;
        p.push_back(price);
    }
    r.resize(rodLength + 1, 0);
    for(int i= 1 ; i<=rodLength;i++){
        int q = -2;
        for(int j = 1;j<= i;j++){
            q = max(q,p[j] + r[i - j]);
        }
        r[i] = q;
    }
    cout << r[rodLength] << endl;
}
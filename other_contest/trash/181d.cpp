#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
int func(){
    string s;
    cin >> s;
    vector<int> have(10);
    rep(i,s.size()){
        have[s[i] - '0']++;
    }
    if(s.size() == 2){
        int s1 = s[0] - '0';
        int s2 = s[1] - '0';
        int a = s1 + s2 * 10;
        int b = s2 + s1 * 10;
        if(a % 8 == 0|| b % 8 == 0)return 1;
        return 0;
    }
    if(s.size() == 1){
        int a = s[0] - '0';
        if(a % 8 == 0)return 1;
        return 0;
    }
    vector<vector<int>> hachi;
    for(int i=992;i>100;i-=8){
        vector<int> h(10);
        int ti = i;
        rep(j,3){
            h[ti % 10]++;
            ti /= 10;
        }
        if(h[0])continue;
        hachi.push_back(h);
    }
    int hn = hachi.size();
    rep(i,hn){
        for(int j=1;j<10;j++){
            if(hachi[i][j] > have[j])break;
            if(j==9)return 1;
        }
    }
    return 0;
}
int main(){
    cout << (func() ? "Yes" : "No") << endl;
}
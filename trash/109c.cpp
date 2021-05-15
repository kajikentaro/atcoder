#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
int main(){
    int n,k;
    char win[200][200];
        win['R']['P'] = 'P';
        win['S']['R'] = 'R';
        win['S']['P'] = 'S';
        win['P']['R'] = 'P';
        win['R']['S'] = 'R';
        win['P']['S'] = 'S';
        win['P']['P'] = 'P';
        win['R']['R'] = 'R';
        win['S']['S'] = 'S';
    string s_tmp;
    cin >> n >> k >> s_tmp;
    vector<char> s(s_tmp.size());
    rep(i,s_tmp.size()){
        s[i] = s_tmp[i];
    }
    rep(j,k){
        n = s.size();
        vector<char> s2;
        int loop_n = ((n%2)==1 ? n*2 : n);
        rep(i,loop_n){
            s2.push_back(s[i%n]);
        }
        vector<char> s3;
        for(int i=0;i<s2.size();i+=2){
            s3.push_back(win[s2[i]][s2[i+1]]);
        }
        swap(s3,s);
    }
    cout << s[0] << endl;
}
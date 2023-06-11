#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
int main(){
    string s;
    cin >> s;
    int m = 0;
    int t = 0;
    rep(i,s.size()){
        if(s[i] == 'R')t++;
        else{
            m = max(m,t);
            t = 0;
        }
    }
    m = max(m,t);
    t = 0;
    cout << m << endl;
}
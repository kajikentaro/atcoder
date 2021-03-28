#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define P pair<int,int>
int func(){
    int h,w,m;
    cin >> h >> w >> m;
    vector<int> H(h);
    vector<int> W(w);
    map<P,int> bomb;
    rep(i,m){
        int hh,ww;
        cin >> hh >> ww;
        hh--;ww--;
        bomb[P(hh,ww)] = 777;
        H[hh]++;
        W[ww]++;
    }
    int h_max = *max_element(H.begin(),H.end());
    int w_max = *max_element(W.begin(),W.end());
    vector<int> listH,listW;
    rep(i,h)if(H[i] == h_max)listH.push_back(i);
    rep(i,w)if(W[i] == w_max)listW.push_back(i);
    for(auto i : listH){
        for(auto j : listW){
            if(bomb[P(i,j)] == 777)continue;
            return h_max + w_max;
        }
    }
    return h_max + w_max - 1;
}
int main(){
    cout << func() << endl;
}
#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
using namespace std;
using namespace atcoder;
int main(){
    double sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    double katamuki = (sy+gy)/(sx-gx);
    double answer = (-sy /katamuki) + sx;
    printf("%.10lf",answer);
    return 0;
}
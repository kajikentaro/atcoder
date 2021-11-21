#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
#define MAX 200000
int  main(){
    char str[MAX];
    int next[MAX];
    int n;
    cin >> n;
    cin >> str;
    int start = 0;
    int final = n-1;
    rep(i,n){
        next[i] = i+1;
    }
    bool flag = true;
    int now = start;
    int *pre = &start;
    int sum = 0;
    while(flag){
        while(1){
            int ap = *pre;
            int a = str[ap];
            int bp = next[ap];
            int b = str[bp];
            int cp = next[bp];
            int c = str[cp];
            int bef = next[cp];
            if(ap == final)break;
            if(bp == final)break;
            if(a == 'f' && b == 'o' && c == 'x'){
                if(final == bef)final = bef;
                *pre = bef;
                sum+=3;
            }
            pre = &next[*pre];
        }
    }
    cout << n - sum << endl;
    return 0;
    

}

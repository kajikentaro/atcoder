#include<bits/stdc++.h>
using namespace std;
int main(){
    string input;
    cin >> input;
    if(input[input.size()-1]=='s'){
        input += "es";
    }else{
        input += 's';
    }
    cout << input << endl;
}
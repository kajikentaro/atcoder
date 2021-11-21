#include<iostream>
using namespace std;
struct my_string : std::string{
    using std::string::string;
    void print(){
        cout << *this << endl;
    }
};
//ここより下に記述
#define string my_string//stringをmy_stringに変換させる
int main(){
    string s = "hello";
    s.print();
    //output
    //hello
}
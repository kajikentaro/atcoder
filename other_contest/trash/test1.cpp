#include<iostream>
using namespace std;
struct my_string : std::string{//stringを継承する
    using std::string::string;//stringのコンストラクタを継承
    void print(){
        cout << *this << endl;
    }
};
int main(){
    my_string s = "hello";
    s.print();
    //output
    //hello
}
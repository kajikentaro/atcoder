#include<iostream>
namespace mystd{
    using namespace std;
    struct string : std::string{
        using std::string::string;
        void print(){
            std::cout << *this << std::endl;
        }
    };
}
int main(){
    namespace std = mystd;//stdをmystdのエイリアス(別名)に設定する
    std::string s;//mystd::string sと同値
    s = "hello";
    s.print();
    //output
    //hello
}
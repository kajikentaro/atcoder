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
    mystd::string s;
    std::string t;//こっちはprint関数を持たない
    s = "hello";
    s.print();
    //output
    //hello
}
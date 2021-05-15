#include<iostream>
using namespace std;
template<typename T,typename U>
class my_pair :public std::pair<T,U>{//publicをつけないとメンバを読み取れなくなる
    using std::pair<T,U>::pair;
    public://public以下にメソッドを作成
    my_pair<T,U> operator+(const my_pair<T,U> p){
        return my_pair<T,U>(this->first + p.first, this->second + p.second);
    }
    void print(){
        cout << this->first << " " << this->second << endl;
    }
};
int main(){
    my_pair<int,int> a(1,2);
    my_pair<int,int> b(1,2);
    (a+b).print();
    //output
    //2 4
}
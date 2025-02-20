#include <bits/stdc++.h>
using namespace std;
struct sophuc{
    int a,b;
    //kieu tra ve operator (+,-,....) (danh sach tham so) {//}
    // sophuc operator + (const sophuc other) {
    //     sophuc tong;
    //     tong.a = a + other.a;
    //     tong.b = b + other.b;
    //     return tong;
    // }
    
    //insertion >>
    friend istream& operator >> (istream& in, sophuc &x){
        in >> x.a >> x.b;
        return in;
    }

    //extraction <<
    friend ostream& operator << (ostream& out, sophuc x) {
        out << x.a << x.b;
        return out;
    }
};
int main() {
    sophuc a,b;
    cin >> a >> b;
    cout << a << b;
}
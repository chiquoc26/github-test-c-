#include <bits/stdc++.h>
using namespace std;

struct td{
    double x,y;

    friend istream& operator >> (istream& in, td &a){
        in >> a.x >> a.y;
        return in;
    }

};

void tung(td a){
    cout << (a.x)*-1 << " " << a.y << endl;
}

void hoanh(td a){
    cout << a.x << " " << (a.y)*-1 << endl;
}

void tdam(td a){
    cout << (a.x)*-1 << " " << (a.y)*-1 << endl;

} 

void kc(td a,td b){
    cout << fixed << setprecision(6) << sqrt((a.x - b.x)*(a.x - b.x) +(a.y -b.y)*(a.y - b.y));
}
int main(){
    td a,b,c;
    cin >> a >> b >> c;
    tung(a);
    hoanh(a);
    tdam(a);
    kc(b,c);
    return 0;
}
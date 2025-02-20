#include <bits/stdc++.h>
using namespace std;
struct PS{
    long long tu;
    long long mau;
    string s;
};

void chuyendoi(PS &a){
    string t = "";
    for(long long i = 0; i < a.s.size(); i++){
        if(a.s[i] != '/') t += a.s[i];
        else {
            a.tu = stoll(t);
            t = "";
        }
    }
    a.mau = stoll(t);
}


long long ucln(long long a,long long b){
    if(b == 0) return a;
    return ucln(b, a % b);
}

long long bcnn(long long a,long long b){
    return (a/ucln(a,b))*b;
}

void Rutgon(PS &a){
    long long temp = ucln(a.tu,a.mau);
    a.tu /= temp;
    a.mau /= temp;
}

void inra(PS a){
    if(a.mau < 0){
        a.tu *= -1;
        a.mau *= -1;
    }
    cout << a.tu << '/' << a.mau;
}

void Quydong(PS &a, PS &b){
    Rutgon(a);
    Rutgon(b);
    a.tu *= b.mau;
    b.tu *= a.mau;
    a.mau *= b.mau;
    b.mau = a.mau; // sau khi a.mau d dc nhan voi b mau
}

void gon(PS &a,PS &b){
    Rutgon(a); Rutgon(b);
    long long t =  bcnn(a.mau,b.mau);
    a.tu *= (t /a.mau);
    b.tu *= (t /b.mau);
    a.mau = b.mau = t;
}

void cong(PS a,PS b){
    Quydong(a,b);
    PS c;
    c.tu = a.tu + b.tu;
    c.mau = a.mau;
    Rutgon(c);
    inra(c);
    cout << endl;
}

void tru(PS a,PS b){
    Quydong(a,b);
    PS c;
    c.tu = a.tu - b.tu;
    c.mau = a.mau;
    Rutgon(c);
    inra(c);
    cout << endl;
}

void nhan(PS a,PS b){
    PS c;
    c.tu = a.tu * b.tu;
    c.mau = a.mau * b.mau;
    Rutgon(c);
    inra(c);
    cout << endl;
}
void chia(PS a,PS b){
    PS c;
    c.tu = a.tu * b.mau;
    c.mau = a.mau * b.tu;
    Rutgon(c);
    inra(c);
    cout << endl;
}

void ingon(PS a, PS b){
    Rutgon(a); Rutgon(b);
    inra(a);
    cout << " ";
    inra(b);
    cout << endl; 
}

void inqd(PS a,PS b){
    gon(a,b);
    inra(a);
    cout << " ";
    inra(b);
    cout << endl;  
}

void ss(PS a,PS b){
    double tua = a.tu;  double maua = a.mau;
    double tub = b.tu;  double maub = b.mau;
    if((tua/maua) > (tub/maub)) cout << 1;
    else if((tua/maua) < (tub/maub)) cout << -1;
    else cout << 0;
   
}


int main(){
    PS a,b;
    cin >> a.s >> b.s;
    chuyendoi(a);
    chuyendoi(b);
    cong(a,b);
    tru(a,b);
    nhan(a,b);
    chia(a,b);
    ingon(a,b);
    inqd(a,b);
    ss(a,b);
    return 0;
}
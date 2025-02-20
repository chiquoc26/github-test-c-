#include <bits/stdc++.h>
using namespace std;
long long ucln(long long a,long long b) {
    if(b != 0) return ucln(b,a % b);
    return a;
}
struct ps{
    long long tu;
    long long mau;
};
void doidau(ps &x) {
    if(x.mau < 0) {
        x.mau *= -1;
        x.tu *= -1;
    }
}
void nhapps(ps &x) {
    cin >> x.tu >> x.mau;
    long long t = ucln(x.tu,x.mau);
    x.tu /= t; x.mau /= t;
    if(x.tu < 0) {
        x.tu *= -1;
        x.mau *= -1;
    }
}
void psmax(ps x, ps &maxx) {
    double temp = ((x.tu ) * 1.0) / ((x.mau) * 1.0);
    if(temp > maxx.tu/maxx.mau) {
        maxx.tu = x.tu;
        maxx.mau = x.mau;
    }
}
void tongps(ps x,ps &sum) {
    sum.tu = sum.tu * x.mau + x.tu * sum.mau;
    sum.mau = sum.mau * x.mau;
    long long t = ucln(sum.tu,sum.mau);
    sum.tu = sum.tu / t;
    sum.mau = sum.mau / t;
}
void nhanps(ps x,ps &all) {
    all.tu = all.tu * x.tu;
    all.mau = all.mau * x.mau;
    long long t = ucln(all.tu,all.mau);
    all.tu /= t;
    all.mau /= t;
}
int main() {
    freopen("input.txt", "r",stdin);
    ps sum,all,maxx;
    sum.tu = 0; sum.mau = 1;
    all.tu = 1; all.mau = 1;
    ps arr[1000];
    long long n; cin >> n;
    for(long long i = 0;  i < n; i++) {
        nhapps(arr[i]);
        if(i == 0) {
            maxx.tu = arr[i].tu;
            maxx.mau = arr[i].mau;
        } else psmax(arr[i],maxx);
        nhanps(arr[i],all);
        tongps(arr[i],sum);
    }
    doidau(maxx);
    doidau(sum);
    doidau(all);
    cout << maxx.tu << " " << maxx.mau << endl;
    cout << sum.tu << " " << sum.mau << endl;
    cout << all.tu << " " << all.mau << endl;
    for(long long i = 0; i < n; i++) {
        cout << arr[i].mau << " " << arr[i].tu;
        if(i != n - 1) cout << " ";
    }
    return 0;

    
    

}

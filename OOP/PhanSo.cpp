

#include <bits/stdc++.h>
using namespace std;

class PS{
    private:
    int tu,mau;
    public:
    friend istream& operator >> (istream &in, PS& a);
    friend ostream& operator << (ostream &out, PS a);
    PS();
};

istream& operator >> (istream& in,PS &a) {
    cout << "Nhap tu di:";
    in >> a.tu ;
    cout << endl << "Nhap mau di: " << endl;
    in >> a.mau;
    return in;
}
ostream& operator << (ostream& out, PS a) {
    out << "Phan so sau khi rut gon la: ";
    out << a.tu << "/" << a.mau << endl;
    return out;
}

PS::PS() {
    int temp = gcd(tu,mau);
    this->tu /= temp;
    this->mau /= temp;
}

int main() {
    int n; cin >> n;
    PS arr[100];
    for(int i = 0;  i < n; i++)  cin >> arr[i];
    for(int i = 0;  i < n; i++)  cout << arr[i];
}
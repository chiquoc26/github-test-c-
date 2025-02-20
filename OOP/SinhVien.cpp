#include <bits/stdc++.h>
using namespace std;

class SinhVien{
    private: 
        string mssv,name,lop,email;
    public:
        void nhap();
        void in();
        friend void doiten(SinhVien,vector<string>&);
        friend bool sapxep(SinhVien,SinhVien);
};
void SinhVien:: in() {
    cout << "----------------------------" << endl;
    cout << "MSSV: " << mssv << endl;
    cout << "Ho va ten: " << name << endl;
    cout << "Lop: " << lop << endl;
    cout << "Email: "<< email << endl;
    cout << "----------------------------" << endl;
}
void SinhVien::nhap() {
    cout << "----------------------------" << endl;
    cout << "MSSV: "; cin >> mssv;
    cout << "Ho va ten: ";
    cin.ignore();
    getline(cin , name);
    cout << "Lop: "; cin >> lop;
    cout << "Email: "; cin >> email;
    cout << "----------------------------" << endl;
}

void doiten(SinhVien a,vector<string> &ten) {
    string w;
    vector <string> temp;
    stringstream ss1(a.name);
    while(ss1 >> w) {
        temp.push_back(w);
    }
    for(int i = temp.size() - 1; i >= 0; i--) {
        ten.push_back(temp[i]);
    }
    
}


bool sapxep(SinhVien a, SinhVien b) {
    vector<string> ten1,ten2;
    doiten(a,ten1); doiten(b,ten2);
    int l1 = ten1.size(),l2 = ten2.size();
    for(int i = 0; i < min(l1,l2); i++) {
        if(ten1[i] != ten2[i]) return ten1[i] < ten2[i];
    } 
    return l1 < l2;
}

int main() {
    // freopen("input.txt", "r", stdin);
    SinhVien ute[1000]; 
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        ute[i].nhap();
    }
    sort(ute,ute + n,sapxep);
    for(int i = 0; i < n; i++) {
        ute[i].in();
    }
    return 0;
}
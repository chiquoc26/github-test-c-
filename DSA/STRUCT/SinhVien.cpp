#include <bits/stdc++.h>
using namespace std;

struct sv{
    string mssv,ten,lop,ns;
    double gpa;

    void in(){
        cout << "-----------------------------------------\n";
        cout << "Ma sinh vien :" << mssv << endl;
        cout << "Ten Sinh Vien :" << ten << endl;
        cout << "Lop :" << lop << endl;
        cout << "Ngay sinh :" << ns << endl;
        cout << "GPA :" << fixed << setprecision(2) << gpa << endl;
    }

    void nhap(){
        cout << "Nhap ma sinh vien :"; cin >> mssv;
        cout << "Nhap ten sinh vien :";
        cin.ignore();
        getline(cin , ten);
        cout << "Nhap lop : "; cin >> lop;
        cout << "Nhap ngay sinh :"; cin >> ns;
        cout << "Nhap GPA :"; cin >> gpa;
    }
};


void inds(sv a[],int n) {
    cout << "Thong tin sinh vien : \n";
    for(int i = 0; i < n; i++) {
        a[i].in();

    }
}


void tkma(sv a[],int n) {
    string ma;
    cout << "Nhap mssv can tim :"; cin >> ma;
    bool found = false;
    for(int i= 0; i < n; i++){                                                   
        if(ma == a[i].mssv) {      
            found = true;
            a[i].in();
            return;
        } 
    }
    cout << "Khong tim thay sinh vien";
}
void lkgpa(sv a[], int n){
    double diem = 0;
    for(int i = 0;i < n; i++){
        diem = max(diem,a[i].gpa);
    }
    for(int i = 0; i < n; i++) {
        if(a[i].gpa == diem) a[i].in();
    }
}                 
bool cmp1(sv a, sv b) {
    return a.gpa > b.gpa;
}
void lk(sv a[],int n) { 
    vector<sv> v;     
    for(int i = 0; i < n; i++) {
        if(a[i].gpa >= 2.5) v.push_back(a[i]);
    }
    sort(v.begin(),v.end(),cmp1);
    cout << "DS sinh vien co GPA >= 2.5 :\n";                                     
    for(sv x : v) x.in();
}

string chuanhoa(string name) {
    stringstream ss(name); vector<string> v;
    string token, res = "";
    while(ss >> token){
        v.push_back(token);
    }
    res += v[v.size() - 1];
    for(int i = 0;  i < v.size() - 1 ; i++) res += v[i];
    return res;
}

bool cmp2(sv a, sv b) {
    string ten1 = chuanhoa(a.ten);
    string ten2 = chuanhoa(b.ten);
    return ten1 < ten2;
}
void sxten(sv a[],int n) {
    sort(a, a + n, cmp2);
    for(int i = 0;  i < n; i++) {
        a[i].in();
    }
}
int main() {
   sv a[1000];
   int n = 0;
   while(1){
    cout << "----------MENU------------\n";
    cout <<"1. Nhap thong tin sinh vien\n";
    cout <<"2. Hien thi toan bo danh sach sinh vien\n";
    cout <<"3. Tim kiem sinh vien theo mssv\n";
    cout <<"4. Liet ke sinh vien co GPA cao nhat\n";
    cout <<"5. Liet ke cac sinh vien co diem GPA >= 2.5\n";
    cout <<"6. Sap xep sinh vien theo ten\n";
    cout <<"0. Thoat\n";
    cout <<"----------------------------\n";
    cout << "Nhap lua chon :\n";
    int lc; cin >> lc;
    if(lc == 1){
        a[n].nhap();
        n++;
    }
    else if(lc == 2) {
        inds(a,n);
    }
    else if(lc == 3) {
        tkma(a,n);
    }
    else if(lc == 4) {
        lkgpa(a,n);
    }
    else if(lc == 5) {
        lk(a,n);
    }
    else if(lc == 6) {
        sxten(a,n);
    }
    else if(lc == 0) return 0;
   }

}
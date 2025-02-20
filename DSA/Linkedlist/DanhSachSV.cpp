#include<bits/stdc++.h>
using namespace std;
struct Student{
    string name,id;
    double gpa;
};

struct SV{
    Student s;
    SV *next;
};

typedef struct SV* sv;

sv makeNode(int x){
    Student s;
    cout << "Nhap thong tin sinh vien :\n";
    cout << "Nhap ID :"; cin >> s.id;
    cout << "Nhap Ten :"; cin.ignore();
    getline(cin ,s.name);
    cout << "Nhap gpa :"; cin >> s.gpa;
    sv tmp = new SV();
    tmp->s = s;
    tmp->next = NULL;
    return tmp;
}


int main() {

}
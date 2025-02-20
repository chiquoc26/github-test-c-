 #include <bits/stdc++.h>
 using namespace std;
 
struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

//cap phat dong mot node moi voi du lieu la so nguyen x
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;

}

//kiem tra rong 
bool empty(node a) {
    return a == NULL;
}

int Size(node a) {
    int cnt = 0;
    while(a != NULL) {
        a = a->next;//gan dia chi cua node tiep theo cho node hien tai
        cnt++;
    }
    return cnt;
}


// them 1 phan tu vao dau danh sach lien ket
void insertFirst(node &a,int x) {
    node tmp = makeNode(x);
    if(a == NULL) {
        a = tmp;
    }else {
        tmp->next = a;
        a = tmp;
    }

}

// them 1 phan tu vao cuoi danh sach lien ket
void insertLast(node &a,int x) {
    node tmp = makeNode(x);
    if(a == NULL) {
        a = tmp;
    } else {
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

//them 1 phan tu vao giua
void insertMiddle(node &a, int x, int pos){
    int n = Size(a);
    if(pos <= 0 || pos > pos + 1){
        cout << "Vi tri chen khong hop le !";
    }
    if(pos == 1) {
        insertFirst(a,x);
        return;
    }
    if(pos == pos + 1) {
        insertLast(a,x);
        return;
    }
    node p = a;
    for(int i = 1;  i < pos  - 1; i++) {
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;

}

//xoa phan tu o dau
void deleteFirst(node &a){
    if(a == NULL) return;
    a = a->next;
}

//xoa phan tu o cuoi
void deleteLast(node &a){
    if(a == NULL) return;
    node truoc = NULL; node sau = a;
    while(sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) {
        a = NULL;
    }
    else{
        truoc ->next = NULL;
    }
}

//xoa o giua
void deleteMiddle(node &a,int pos){
    if(pos <= 0 || pos > Size(a)) return;
    node truoc = NULL, sau = a;
    for(int i = 1; i < pos; i++){
        truoc = sau;
        sau = sau->next;
    }
    if(truoc == NULL) {
        a = a->next;
    }
    else truoc->next = sau->next;
}


void in(node a){
    cout << "-------------------------------\n";
    while(a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "-------------------------------\n";
}
//Sap xep cac gia tri trong danh sach lien ket
void sapxep(node &a) {
    for(node p = a; p->next != NULL; p = p->next){
        node min = p;
        for(node q = p->next; q != NULL; q = q->next){
            if(q->data < min->data){
                min = q;
            }
        }
        // int temp = min->data;
        // min->data = p->data;
        // p->data = temp;
        swap(p->data,min->data);
    }
}

int main() {
    node head = NULL;
    while(1){
        cout << "-----------------MENU------------------\n";
        cout << "1. Chen phan tu vao dau danh sach\n";
        cout << "2. Chen phan tu vao cuoi danh sach\n";
        cout << "3. Chen phan tu vao giua danh sach\n";
        cout << "4. Xoa phan tu o dau\n";
        cout << "5. Xoa phan tu o cuoi\n";
        cout << "6. Xoa phan tu o giua\n";
        cout << "7. Duyet danh sach lien ket\n";
        cout << "8. Sap xep cac phan tu trong danh sach lien ket\n";
        cout << "0. Thoat\n";
        cout << "---------------------------------------\n";
        cout << "Nhap lua chon :";
        int lc; cin >> lc;
        if(lc == 1){
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            insertFirst(head,x);
        }
        else if(lc == 2){
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            insertLast(head,x);
        }
        else if(lc == 3){
            int x; cout << "Nhap gia tri can chen :"; cin >> x;
            int y; cout << "Nhap vi tri muon chen :"; cin >> y;
            insertMiddle(head,x,y);
        }
        else if(lc == 4){
            cout << "Chung toi se xoa phan tu o dau!";
            deleteFirst(head);
        }
        else if(lc == 5){
            cout << "Chung toi se xoa phan tu o cuoi!";
            deleteLast(head);
        }
        else if(lc == 6){
            cout << "nhap vi tri muon xoa :"; 
            int x; cin >> x;
            cout << "Chung toi se xoa phan tu o vi tri" << x << " :";
            deleteMiddle(head,x);
        }
        else if(lc == 7){
            in(head);
        }
        else if(lc == 8){
            cout << "Da sap xep";
            sapxep(head);
        }
        else if(lc == 0) return 0;
    }

}

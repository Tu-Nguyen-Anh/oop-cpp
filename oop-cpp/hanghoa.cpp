#include <bits/stdc++.h>
using namespace std;

struct hanghoa {
    char mahang[30];
    char tenhang[30];
    int soluong;
    float dongia;
};

struct List {
    int count;
    hanghoa e[30];
};

void nhaphh(hanghoa &hh) {
    cout << "Nhap ma hang hoa:    ";
    fflush(stdin);
    gets(hh.mahang);
    cout << "Nhap ten hang:       ";
    fflush(stdin);
    gets(hh.tenhang);
    cout << "Nhap so luong:       ";
    cin >> hh.soluong;
    cout << "Nhap don gia:        ";
    cin >> hh.dongia;
}

void inhh(hanghoa hh) {
    cout << setw(10) << hh.mahang << setw(15) << hh.tenhang << setw(15) << hh.soluong << setw(15) << hh.dongia << endl;
}

void nhapds(int &n, List &L) {
    hanghoa x;
    L.count = n - 1;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap hang thu " << i + 1 << endl;
        nhaphh(L.e[i]);
    }
}

void sapxep(int n, List &L) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (L.e[j].dongia > L.e[i].dongia)
                swap(L.e[j], L.e[i]);
        }
    }
}

void insert(List &L, int &n) {
    int k = 1;
    hanghoa elem;
    cout << "Nhap hang hoa can chen:" << endl;
    nhaphh(elem);
    if (k <= L.count + 1 && k > 0) {
        for (int i = L.count; i >= k - 1; i--)
            L.e[i + 1] = L.e[i];
        L.e[k - 1] = elem;
        L.count++;
        n++;
    }
}

void xoa3(int &n, List &L) {
    int k = 3;
    if (k <= L.count + 1 && k > 0) {
        for (int i = k; i <= L.count; i++) {
            L.e[i - 1] = L.e[i];
        }
        L.count = L.count - 1;
        n--;
    }
}

int main() {
    int n;
    cout << "nhap so hang hoa:    ";
    cin >> n;
    List L;
    nhapds(n, L);
    // insert(L, n);
    xoa3(n, L);
    sapxep(n, L);
    cout << setw(45) << "\n-----IN-----" << endl;
    cout << setw(10) << "Ma HH" << setw(15) << "Ten HH" << setw(15) << "so luong" << setw(15) << "Don Gia" << endl;
    for (int i = 0; i < n; i++) {
        inhh(L.e[i]);
    }
}

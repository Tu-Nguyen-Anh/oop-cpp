#include <bits/stdc++.h>
using namespace std;

class BenhNhan;
void cau2(int n, BenhNhan *a);
void cau4(int n, BenhNhan *a);

class Person {
protected:
    char hoTen[30];
    int tuoi;

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        fflush(stdin);
        gets(hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class Hospital {
private:
    char tenBV[30];
    char diaChi[30];
    Person giamDoc;

    friend class BenhNhan;
    friend void cau2(int n, BenhNhan *a);
};

class BenhNhan : public Person {
private:
    char tieuSu[30];
    char chuanDoan[30];
    Hospital benhVien;

public:
    void nhap() {
        cout << "Nhap ten benh vien: ";
        fflush(stdin);
        gets(benhVien.tenBV);
        cout << "Nhap dia chi: ";
        fflush(stdin);
        gets(benhVien.diaChi);
        benhVien.giamDoc.nhap();
        cout << "Nhap ho ten benh nhan: ";
        fflush(stdin);
        gets(hoTen);
        cout << "Nhap tuoi benh nhan: ";
        cin >> tuoi;
        cout << "Nhap tieu su benh nhan: ";
        fflush(stdin);
        gets(tieuSu);
        cout << "Nhap chuan doan benh nhan: ";
        fflush(stdin);
        gets(chuanDoan);
    }

    void xuat() {
        cout << "\nBenh vien: " << benhVien.tenBV << endl;
        cout << "Dia chi:" << benhVien.diaChi << endl;
        benhVien.giamDoc.xuat();
        cout << setw(10) << hoTen << setw(20) << tuoi << setw(20)
             << tieuSu << setw(20) << chuanDoan << endl;
    }

    friend void cau2(int n, BenhNhan *a);
    friend void cau4(int n, BenhNhan *a);
};

void nhapDS(int n, BenhNhan *a) {
    for (int i = 0; i < n; i++) {
        a[i].nhap();
    }
}

void xuatDS(int n, BenhNhan *a) {
    for (int i = 0; i < n; i++) {
        a[i].xuat();
    }
}

void cau2(int n, BenhNhan *a) {
    cout << "-----Cau 2-----" << endl;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].benhVien.tenBV, "Bach Mai"))
            a[i].xuat();
    }
}

void cau4(int n, BenhNhan *a) {
    cout << "\n-----Cau 4-----" << endl;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].tieuSu, "Benh tim")) {
            for (int j = i; j < n - 2; j++) {
                a[j] = a[j + 1];
            }
            n--;
        }
    }
    cout << "N: " << n;
    xuatDS(n, a);
}

int main() {
    BenhNhan *a;
    int n;
    cout << "Nhap so benh nhan: ";
    cin >> n;
    a = new BenhNhan[n];
    nhapDS(n, a);
    xuatDS(n, a);
    // cau2(n,a);
    cau4(n, a);
    return 0;
}

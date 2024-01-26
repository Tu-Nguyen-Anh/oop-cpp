#include <bits/stdc++.h>
using namespace std;

class lophoc;

class nguoi {
protected:
    char hoten[30];
    char ngaysinh[30];
    char quequan[30];

    friend void timkiem(lophoc k);
    friend void doiten(lophoc &k);
};

class sinhvien : public nguoi {
    char masv[30];
    char nganh[30];
    int khoahoc;

public:
    void nhap();
    void xuat();

    friend class lophoc;
    friend void khoa11(lophoc k);
};

void sinhvien::nhap() {
    cout << "nhap ho ten:     ";
    fflush(stdin);
    gets(hoten);
    cout << "nhap ngay sinh:  ";
    fflush(stdin);
    gets(ngaysinh);
    cout << "nhap que quan:   ";
    fflush(stdin);
    gets(quequan);
    cout << "nhap ma sv:      ";
    fflush(stdin);
    gets(masv);
    cout << "nhap nganh:      ";
    fflush(stdin);
    gets(nganh);
    cout << "khoa hoc:        ";
    cin >> khoahoc;
}

void sinhvien::xuat() {
    cout << "HO TEN:          " << hoten << endl;
    cout << "NGAY SINH:       " << ngaysinh << endl;
    cout << "QUE QUAN:        " << quequan << endl;
    cout << "MA SINH VIEN:    " << masv << endl;
    cout << "NGANH:           " << nganh << endl;
    cout << "KHOA HOC:        " << khoahoc << endl;
}

class lophoc {
    char malop[30];
    char tenlop[30];
    char ngaymo[30];
    sinhvien *x;
    int n;
    char giaovien[30];

public:
    void nhap();
    void xuat();

    friend void khoa11(lophoc k);
    friend void timkiem(lophoc k);
    friend void doiten(lophoc &k);
};

void lophoc::nhap() {
    cout << "nhap ma lop:     ";
    fflush(stdin);
    gets(malop);
    cout << "ten lop:         ";
    fflush(stdin);
    gets(tenlop);
    cout << "ngay mo lop:     ";
    fflush(stdin);
    gets(ngaymo);
    cout << "nhap so sinh vien: ";
    cin >> n;
    x = new sinhvien[n];
    for (int i = 0; i < n; i++) {
        cout << "nhap sinh vien thu " << i + 1 << "" << endl;
        x[i].nhap();
    }
    cout << "nhap giao vien:  ";
    fflush(stdin);
    gets(giaovien);
}

void lophoc::xuat() {
    cout << "ma lop:          " << malop << endl;
    cout << "ten lop:         " << tenlop << endl;
    cout << "ngay mo:         " << ngaymo << endl;
    cout << "giao vien:       " << giaovien << endl;

    for (int i = 0; i < n; i++) {
        cout << "sinh vien thu " << i + 1 << "" << endl;
        x[i].xuat();
    }
}

void khoa11(lophoc k) {
    int count = 0;
    for (int i = 0; i < k.n; i++) {
        if (k.x[i].khoahoc == 11)
            count = count + 1;
    }
    cout << "co " << count << " sinh vien khoa 11";
}

void timkiem(lophoc k) {
    int dem = 0;
    for (int i = 0; i < k.n; i++) {
        if (strcmp(k.x[i].hoten, "Nguyen Anh Tu") == 0)
            dem = dem + 1;
    }
    cout << endl
         << "co " << dem << " sinh vien la Nguyen Anh Tu";
}

void doiten(lophoc &k) {
    for (int i = 0; i < k.n; i++) {
        strcpy(k.x[i].quequan, "Hai Duong");
    }
}

int main() {
    lophoc k;
    k.nhap();
    doiten(k);
    k.xuat();
    khoa11(k);
    timkiem(k);
    return 0;
}

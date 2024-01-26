#include <iostream>
#include <iomanip>
using namespace std;

class NCC
{
    char mancc[30];
    char tenncc[30];
    char diachi[30];
    char sdt[15];

public:
    void nhap();
    void xuat();
};

class SP
{
    char masp[30];
    char tensp[30];
    int sl;
    float dongia;

public:
    void nhap();
    void xuat();
    friend class PHIEU;
    friend void spnho(PHIEU a);
    friend void sapxep(PHIEU a);
};

class PHIEU
{
    char maphieu[30];
    char ngaylap[12];
    NCC x;
    int n;
    SP *y;

public:
    void nhap();
    void xuat();
    friend void spnho(PHIEU a);
    friend void sapxep(PHIEU a);
};

void NCC::nhap()
{
    cout << "ma nha cung cap: ";
    fflush(stdin);
    gets(mancc);
    cout << "ten nha cung cap: ";
    fflush(stdin);
    gets(tenncc);
    cout << "dia chi: ";
    fflush(stdin);
    gets(diachi);
    cout << "so dien thoai: ";
    fflush(stdin);
    gets(sdt);
}

void NCC::xuat()
{
    cout << "     ma nha cung cap: " << mancc;
    cout << "     ten nha cung cap: " << tenncc << endl;
    cout << "     dia chi: " << diachi;
    cout << "     SDT: " << sdt << endl;
}

void SP::nhap()
{
    cout << "ma sp: ";
    fflush(stdin);
    gets(masp);
    cout << "ten sp: ";
    fflush(stdin);
    gets(tensp);
    cout << "so luong: ";
    cin >> sl;
    cout << "don gia: ";
    cin >> dongia;
}

void SP::xuat()
{
    cout << setw(20) << masp << setw(20) << tensp << setw(10) << sl << setw(10) << dongia << setw(20) << sl * dongia << endl;
}

void PHIEU::nhap()
{
    cout << "ma phieu:    ";
    fflush(stdin);
    gets(maphieu);
    cout << "ngay lap:    ";
    fflush(stdin);
    gets(ngaylap);
    x.nhap();
    cout << "nhap so sp: ";
    cin >> n;
    y = new SP[n];
    for (int i = 0; i < n; i++)
        y[i].nhap();
}

void PHIEU::xuat()
{
    cout << " dai hoc victory" << endl;
    cout << setw(20) << "           phieu nhap van phong pham" << endl;
    cout << "     ma phieu:    " << maphieu;
    cout << "     ngay lap: " << ngaylap << endl;
    x.xuat();
    cout << setw(20) << "ma sp" << setw(20) << "ten san pham" << setw(10) << "so luong" << setw(10) << "don gia" << setw(20) << "thanh tien" << endl;
    for (int i = 0; i < n; i++)
        y[i].xuat();
    double TONGTIEN = 0;
    for (int i = 0; i < n; i++)
        TONGTIEN += y[i].dongia * y[i].sl;
    cout << setw(60) << "TONG:              " << TONGTIEN << endl;
    cout << endl;
    cout << setw(20) << "hieu truong" << setw(20) << "phong tai chinh" << setw(20) << "nguoi lap" << endl;
}

void spnho(PHIEU a)
{
    int dem = 0;
    for (int i = 0; i < a.n; i++)
    {
        if (a.y[i].sl < 80)
            dem++;
    }
    cout << "so sp co sl nho hon 80 la: " << dem << endl;
}

void sapxep(PHIEU a)
{
    for (int i = 0; i < a.n; i++)
        for (int j = i + 1; j < a.n; j++)
            if (a.y[i].dongia > a.y[i].dongia)
            {
                SP tg = a.y[i];
                a.y[i] = a.y[j];
                a.y[j] = tg;
            }
}

int main()
{
    PHIEU a;
    a.nhap();
    a.xuat();
    spnho(a);
    sapxep(a);
    a.xuat();
    return 0;
}

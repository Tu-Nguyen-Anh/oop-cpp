#include <bits/stdc++.h>
using namespace std;

class VECTOR {
private:
    float *a;
    int n;

public:
    VECTOR();
    VECTOR(int m);
    bool operator==(const VECTOR &y) const;
    float operator++();
    friend istream &operator>>(istream &x, VECTOR &y);
    friend ostream &operator<<(ostream &x, const VECTOR &y);
};

VECTOR::VECTOR() {
    n = 0;
    a = NULL;
}

VECTOR::VECTOR(int m) {
    n = m;
}

istream &operator>>(istream &x, VECTOR &y) {
    y.a = new float[y.n];
    for (int i = 0; i < y.n; i++) {
        cout << "Nhap phan tu vector thu " << i + 1 << ": ";
        if (!(x >> y.a[i])) {
            cerr << "Invalid input. Exiting...\n";
            exit(EXIT_FAILURE);
        }
    }
    return x;
}

ostream &operator<<(ostream &x, const VECTOR &y) {
    x << "< ";
    for (int i = 0; i < y.n; i++) {
        x << y.a[i] << " ";
    }
    x << ">" << endl;
    return x;
}

bool VECTOR::operator==(const VECTOR &y) const {
    if (n == y.n) {
        for (int i = 0; i < n; i++) {
            if (a[i] != y.a[i])
                return false;
        }
        return true;
    } else
        return false;
}

float VECTOR::operator++() {
    float max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i])
            max = a[i];
    }
    return max;
}

int main() {
    VECTOR a(3), b(3);
    cin >> a;
    cout << a;
    cin >> b;
    cout << b;
    if (a == b)
        cout << "T" << endl;
    else
        cout << "F" << endl;
    cout << "Phan tu max trong vecto 1: " << ++a << endl;
    cout << "Phan tu max trong vecto 2: " << ++b << endl;
    return 0;
}

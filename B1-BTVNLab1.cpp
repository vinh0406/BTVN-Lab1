#include <iostream>
#include <vector>
using namespace std;

// Cau truc de luu tru phan so
struct Fraction {
    int tu;   // Tu so
    int mau;  // Mau so
};

// Ham tinh gia tri thuc cua phan so
// Dau vao: mot phan so (Fraction)
// Dau ra: gia tri thuc cua phan so (tu so chia cho mau so)
double fractionValue(Fraction f) {
    return (double)f.tu / f.mau;
}

// Ham nhap phan so
// Dau vao: tham chieu den mot phan so (Fraction)
// Dau ra: khong co gia tri tra ve, nhung cap nhat gia tri cua tu so va mau so tu nguoi dung
void nhapPhanSo(Fraction &f) {
    cout << "Nhap tu so: ";
    cin >> f.tu;
    do {
        cout << "Nhap mau so (khac 0): ";
        cin >> f.mau;
        // Kiem tra mau so, neu bang 0 thi yeu cau nhap lai
        if (f.mau == 0) {
            cout << "Mau so khong hop le! Vui long nhap lai.\n";
        }
    } while (f.mau == 0); // Lap lai den khi mau so khac 0
}

// Ham tim phan so nho nhat va lon nhat trong mang phan so
// Dau vao: mang cac phan so (vector<Fraction>), tham chieu den phan so nho nhat va lon nhat (Fraction)
// Dau ra: khong co gia tri tra ve, nhung cap nhat phan so nho nhat va lon nhat qua tham chieu
void timMinMaxPhanSo(const vector<Fraction>& fractions, Fraction &minFrac, Fraction &maxFrac) {
    minFrac = fractions[0]; // Gia tri nho nhat ban dau la phan so dau tien
    maxFrac = fractions[0]; // Gia tri lon nhat ban dau la phan so dau tien
    for (int i = 1; i < fractions.size(); i++) {
        // So sanh gia tri thuc cua cac phan so de tim phan so nho nhat
        if (fractionValue(fractions[i]) < fractionValue(minFrac)) {
            minFrac = fractions[i];
        }
        // So sanh gia tri thuc cua cac phan so de tim phan so lon nhat
        if (fractionValue(fractions[i]) > fractionValue(maxFrac)) {
            maxFrac = fractions[i];
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<Fraction> fractions(n);
    // Nhap cac phan so
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        nhapPhanSo(fractions[i]); // Goi ham nhap phan so
    }

    Fraction minFrac, maxFrac;
    // Tim phan so nho nhat va lon nhat
    timMinMaxPhanSo(fractions, minFrac, maxFrac);

    // Xuat ket qua
    cout << "Phan so nho nhat: " << minFrac.tu << "/" << minFrac.mau << endl;
    cout << "Phan so lon nhat: " << maxFrac.tu << "/" << maxFrac.mau << endl;

    return 0;
}

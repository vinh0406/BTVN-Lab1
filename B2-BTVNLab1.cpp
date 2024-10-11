#include <iostream>
#include <vector>
#include <algorithm>
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
    cin >> f.tu;
    do {
        cin >> f.mau;
        if (f.mau == 0) {
            cout << "Mau so khong hop le! Vui long nhap lai.\n";
        }
    } while (f.mau == 0); // Lap lai den khi mau so khac 0
}

// Ham so sanh hai phan so de sap xep
// Dau vao: hai phan so f1 va f2
// Dau ra: tra ve true neu f1 < f2
bool soSanhBeHon(const Fraction &f1, const Fraction &f2) {
    return fractionValue(f1) < fractionValue(f2);
}

// Ham tim phan so lon thu k va be thu k
// Dau vao: mang phan so (vector<Fraction>), so nguyen k
// Dau ra: in ra phan so be thu k va lon thu k (neu co)
void timPhanSoThuK(const vector<Fraction>& fractions, int k) {
    int n = fractions.size();
    if (k > n) {
        cout << "Khong co phan so lon thu " << k << " hoac be thu " << k << endl;
        return;
    }

    // Tao ban sao cua mang phan so de sap xep
    vector<Fraction> sortedFractions = fractions;

    // Sap xep mang phan so theo gia tri thuc tang dan
    sort(sortedFractions.begin(), sortedFractions.end(), soSanhBeHon);

    // Tim phan so be thu k
    Fraction beThuK = sortedFractions[k - 1]; // be thu k la phan tu thu k trong mang da sap xep
    Fraction lonThuK = sortedFractions[n - k]; // lon thu k la phan tu thu n-k+1

    // In ra ket qua
    cout << "Phan so be thu " << k << ": " << beThuK.tu << "/" << beThuK.mau << endl;
    cout << "Phan so lon thu " << k << ": " << lonThuK.tu << "/" << lonThuK.mau << endl;
}

int main() {
    int n, k;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    cout << "Nhap gia tri k: ";
    cin >> k;

    vector<Fraction> fractions(n);
    // Nhap cac phan so
    cout << "Nhap phan so (tu so va mau so, tren cung mot dong hoac nhieu dong):" << endl;
    for (int i = 0; i < n; i++) {
        nhapPhanSo(fractions[i]); // Goi ham nhap phan so
    }

    // Tim va in ra phan so be thu k va lon thu k
    timPhanSoThuK(fractions, k);

    return 0;
}

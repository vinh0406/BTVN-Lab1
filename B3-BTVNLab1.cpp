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

// Ham nhap phan so tu ban phim
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

// Ham so sanh hai phan so
// Dau vao: hai phan so f1 va f2
// Dau ra: tra ve true neu f1 < f2
bool soSanhBeHon(const Fraction &f1, const Fraction &f2) {
    return fractionValue(f1) < fractionValue(f2);
}

// Ham tinh tich cua cac phan so trong mot tap hop
// Dau vao: mot vector cac phan so (tapHop)
// Dau ra: tra ve phan so la tich cua cac phan so trong tap hop
Fraction tinhTich(const vector<Fraction> &tapHop) {
    Fraction tich = {1, 1}; // Khoi tao tich la 1/1
    for (const Fraction &f : tapHop) {
        tich.tu *= f.tu;    // Nhan tu so
        tich.mau *= f.mau;  // Nhan mau so
    }
    return tich;
}

// Ham kiem tra hai phan so co bang nhau hay khong
// Dau vao: hai phan so f1 va f2
// Dau ra: tra ve true neu hai phan so bang nhau
bool bangNhau(Fraction f1, Fraction f2) {
    return (f1.tu * f2.mau == f2.tu * f1.mau);
}

// Ham tim tap hop con co tich bang phan so dich
// Dau vao: mot vector phan so (fractions) va phan so dich (target)
// Dau ra: in ra tap hop con co tich bang phan so dich, hoac thong bao khong tim thay
void timTapHopCon(const vector<Fraction> &fractions, Fraction target) {
    int n = fractions.size();
    vector<Fraction> bestSet; // Tap hop con tot nhat (it phan tu nhat)
    bool timThay = false;

    // Duyet qua tat ca cac tap hop con cua mang fractions
    for (int i = 1; i < (1 << n); i++) { // 1 << n tuong duong voi 2^n, so tap hop con
        vector<Fraction> tapHop;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // Neu bit thu j cua i la 1 thi lay phan so thu j
                tapHop.push_back(fractions[j]);
            }
        }

        // Tinh tich cua tap hop con
        Fraction tich = tinhTich(tapHop);

        // Neu tich cua tap hop con bang voi phan so dich
        if (bangNhau(tich, target)) {
            // Neu tap hop con nay co it phan tu hon, cap nhat tap hop con tot nhat
            if (!timThay || tapHop.size() < bestSet.size()) {
                bestSet = tapHop;
                timThay = true;
            }
        }
    }

    // Neu tim thay tap hop con thoa man
    if (timThay) {
        // Sap xep tap hop con theo thu tu tang dan
        sort(bestSet.begin(), bestSet.end(), soSanhBeHon);
        cout << "Tap hop con nho nhat co tich bang phan so dich la: " << endl;
        for (const Fraction &f : bestSet) {
            cout << f.tu << "/" << f.mau << " ";
        }
        cout << endl;
    }
    // Neu khong tim thay
    else {
        cout << "Khong co tap hop con nao thoa man." << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<Fraction> fractions(n);
    // Nhap cac phan so
    cout << "Nhap cac phan so (tu so va mau so, tren cung mot dong hoac nhieu dong):" << endl;
    for (int i = 0; i < n; i++) {
        nhapPhanSo(fractions[i]);
    }

    // Nhap phan so dich
    Fraction target;
    cout << "Nhap phan so dich (tu so va mau so): ";
    nhapPhanSo(target);

    // Tim tap hop con co tich bang phan so dich
    timTapHopCon(fractions, target);

    return 0;
}

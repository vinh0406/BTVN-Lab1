#include <iostream>
#include <vector>
using namespace std;

// Ham in danh sach cac hinh chu nhat
// Dau vao: rectangles - danh sach cac hinh chu nhat duoi dang vector cac vector [x, y, w, h] 
// Dau ra: in ra danh sach cac hinh chu nhat theo dinh dang [x, y, w, h]
void printRectangles(const vector<vector<int>> &rectangles) {
    for (const auto &rect : rectangles) {
        cout << "[" << rect[1] << ", " << rect[0] << ", " << rect[3] << ", " << rect[2] << "]" << endl;
    }
}

// Ham danh dau cac o cua hinh chu nhat da duoc tim thay
// Dau vao: visited - ma tran danh dau cac o da duoc kiem tra
//          x, y - toa do goc tren ben trai cua hinh chu nhat
//          h, w - chieu cao va chieu rong cua hinh chu nhat
// Dau ra: khong co, chi cap nhat ma tran visited
void markRectangle(vector<vector<bool>> &visited, int x, int y, int h, int w) {
    for (int i = x; i < x + h; i++) {
        for (int j = y; j < y + w; j++) {
            visited[i][j] = true;
        }
    }
}

// Ham kiem tra cac o xung quanh hinh chu nhat co bi dinh cac o 1 khong
// Dau vao: matrix - ma tran goc
//          x, y - toa do goc tren ben trai cua hinh chu nhat
//          h, w - chieu cao va chieu rong cua hinh chu nhat
//          m, n - kich thuoc ma tran
// Dau ra: tra ve true neu co o 1 nao xung quanh, tra ve false neu khong
bool hasSurroundingOnes(const vector<vector<int>> &matrix, int x, int y, int h, int w, int m, int n) {
    // Kiem tra ben tren
    if (x - 1 >= 0) {
        for (int j = y; j < y + w; j++) {
            if (matrix[x - 1][j] == 1) {
                return true;
            }
        }
    }

    // Kiem tra ben duoi
    if (x + h < m) {
        for (int j = y; j < y + w; j++) {
            if (matrix[x + h][j] == 1) {
                return true;
            }
        }
    }

    // Kiem tra ben trai
    if (y - 1 >= 0) {
        for (int i = x; i < x + h; i++) {
            if (matrix[i][y - 1] == 1) {
                return true;
            }
        }
    }

    // Kiem tra ben phai
    if (y + w < n) {
        for (int i = x; i < x + h; i++) {
            if (matrix[i][y + w] == 1) {
                return true;
            }
        }
    }

    return false;
}

// Ham tim tat ca cac hinh chu nhat co kich thuoc toi thieu 2x2
// Dau vao: matrix - ma tran goc
//          m, n - kich thuoc ma tran (so hang va so cot)
// Dau ra: tra ve danh sach cac hinh chu nhat [x, y, h, w]
vector<vector<int>> findRectangles(const vector<vector<int>> &matrix, int m, int n) {
    vector<vector<int>> rectangles; // Luu danh sach cac hinh chu nhat
    vector<vector<bool>> visited(m, vector<bool>(n, false)); // Ma tran danh dau cac o da kiem tra

    // Duyet qua tung vi tri trong ma tran
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Neu phan tu la 1 va chua duoc kiem tra
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int width = 0, height = 0;

                // Xac dinh chieu rong toi da cua hinh chu nhat
                while (j + width < n && matrix[i][j + width] == 1 && !visited[i][j + width]) {
                    width++;
                }

                // Kiem tra moi hang duoi do co giu duoc chieu rong nhu hang dau khong
                bool validRectangle = true;
                while (i + height < m && validRectangle) {
                    // Kiem tra tat ca cac phan tu tren hang hien tai
                    for (int w = 0; w < width; w++) {
                        if (matrix[i + height][j + w] == 0 || visited[i + height][j + w]) {
                            validRectangle = false;
                            break;
                        }
                    }
                    if (validRectangle) {
                        height++;
                    }
                }

                // Kiem tra neu kich thuoc hinh chu nhat >= 2x2
                if (width >= 2 && height >= 2) {
                    // Kiem tra cac o xung quanh co bi dinh khong
                    if (!hasSurroundingOnes(matrix, i, j, height, width, m, n)) {
                        rectangles.push_back({i, j, height, width}); // Luu hinh chu nhat
                    }
                    markRectangle(visited, i, j, height, width); // Danh dau hinh chu nhat da duoc xet
                }
            }
        }
    }

    return rectangles; // Tra ve danh sach cac hinh chu nhat
}

int main() {
    int m, n;
    cout << "Nhap kich thuoc ma tran (m x n): ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Nhap ma tran kich thuoc " << m << "x" << n << " (cac phan tu la 0 hoac 1):" << endl;

    // Nhap ma tran binary
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Tim cac hinh chu nhat
    vector<vector<int>> rectangles = findRectangles(matrix, m, n);

    // Xuat danh sach hinh chu nhat
    cout << "Danh sach cac hinh chu nhat (kich thuoc >= 2x2):" << endl;
    printRectangles(rectangles);

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Ham in ma tran
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Ham kiem tra hai ma tran co bang nhau khong
// Dau vao: hai ma tran vuong matrix1 va matrix2
// Dau ra: tra ve true neu hai ma tran bang nhau
bool isEqual(const vector<vector<int>> &matrix1, const vector<vector<int>> &matrix2) {
    int n = matrix1.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Ham bien doi Arnold's Cat Map
// Dau vao: ma tran goc matrix, kich thuoc ma tran m
// Dau ra: tra ve ma tran moi sau khi bien doi
vector<vector<int>> arnoldsCatMapTransform(const vector<vector<int>> &matrix, int m) {
    vector<vector<int>> newMatrix(m, vector<int>(m));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            // Cong thuc (x, y) = ((2i + j) % m, (i + j) % m)
            int newX = (2 * i + j) % m;
            int newY = (i + j) % m;
            newMatrix[newX][newY] = matrix[i][j];
        }
    }
    
    return newMatrix;
}

// Ham tinh chu ky cua Arnold's Cat Map
// Dau vao: ma tran goc ban dau matrix, kich thuoc ma tran m
// Dau ra: tra ve so lan bien doi de ma tran tro ve trang thai ban dau
int calculateArnoldsCatMapPeriod(vector<vector<int>> matrix, int m) {
    vector<vector<int>> originalMatrix = matrix;  // Luu trang thai ban dau
    int cycleCount = 0;

    do {
        matrix = arnoldsCatMapTransform(matrix, m);  // Ap dung bien doi
        cycleCount++;
    } while (!isEqual(matrix, originalMatrix));  // Lap lai den khi ma tran tro ve trang thai ban dau

    return cycleCount;  // Tra ve so chu ky
}

int main() {
    int m;
    cout << "Nhap kich thuoc ma tran m: ";
    cin >> m;

    vector<vector<int>> matrix(m, vector<int>(m));
    cout << "Nhap ma tran kich thuoc " << m << "x" << m << ":" << endl;

    // Nhap gia tri cho ma tran
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Tinh chu ky cua Arnold's Cat Map
    int period = calculateArnoldsCatMapPeriod(matrix, m);

    // Xuat ra chu ky k
    cout << "He so chu ky k cua Arnold's Cat Map la: " << period << endl;

    return 0;
}

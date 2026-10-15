#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX 20

int A[MAX][MAX];   // ma tran trong so
int n;             // so dinh

// Doc ma tran trong so tu file
// Dinh dang file: dong 1 la n, tiep theo la n dong, moi dong n so
bool Nhap(const char *tenFile) {
    ifstream f(tenFile);
    if (!f.is_open()) {
        cout << "Khong mo duoc file " << tenFile << endl;
        return false;
    }
    f >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f >> A[i][j];
    f.close();
    return true;
}

// In ma tran trong so ra man hinh
void HienThi() {
    cout << "Ma tran trong so cua do thi (" << n << " dinh):\n\n";
    cout << "    ";
    for (int j = 0; j < n; j++)
        cout << setw(4) << char('A' + j);
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << setw(4) << char('A' + i);
        for (int j = 0; j < n; j++)
            cout << setw(4) << A[i][j];
        cout << "\n";
    }
}

int main() {
    if (!Nhap("Grap.txt")) return 1;
    HienThi();
    return 0;
}

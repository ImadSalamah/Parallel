#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

const int N = 64000;
const int M = 64000;

vector<vector<int>> A(N, vector<int>(M));
vector<vector<int>> B(M, vector<int>(N));

// تعبئة المصفوفة A بقيم عشوائية
void fill_matrix() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            A[i][j] = rand() % 100;
}

// الترانسبوز بطريقة تسلسلية
void transpose_sequential() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            B[j][i] = A[i][j];
}

// التحقق من صحة الترانسبوز
bool validate_result() {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (B[i][j] != A[j][i])
                return false;
    return true;
}

int main() {
    fill_matrix();

    auto start = high_resolution_clock::now();
    transpose_sequential();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Sequential Transpose Time: " << duration.count() << " ms" << endl;

    bool isValid = validate_result();
    cout << "Validation: " << (isValid ? "PASSED ✅" : "FAILED ❌") << endl;

    // حفظ النتيجة في ملف
    ofstream out("../results/validation_checksums_sequential.txt");
    if (out.is_open()) {
        out << "Validation: " << (isValid ? "PASSED" : "FAILED") << endl;
        out.close();
    } else {
        cerr << "⚠️ Could not write to ../results/validation_checksums_sequential.txt" << endl;
    }

    return 0;
}
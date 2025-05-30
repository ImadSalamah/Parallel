#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int N = 2000;
const int M = 2000;

vector<vector<int>> A(N, vector<int>(M));
vector<vector<int>> B(M, vector<int>(N));

void fill_matrix() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            A[i][j] = rand() % 100;
}

void transpose_sequential() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            B[j][i] = A[i][j];
}

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
    cout << "Validation: " << (validate_result() ? "PASSED ✅" : "FAILED ❌") << endl;

    return 0;
}

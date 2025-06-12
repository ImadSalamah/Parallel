#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <omp.h>

using namespace std;
using namespace std::chrono;

const int N = 2000;
const int M = 2000;
const int NUM_THREADS = 4;

vector<vector<int>> A(N, vector<int>(M));
vector<vector<int>> B(M, vector<int>(N));

void fill_matrix() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            A[i][j] = rand() % 100;
}

void transpose_parallel_omp() {
    #pragma omp parallel for num_threads(NUM_THREADS) collapse(2)
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
    transpose_parallel_omp();
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "OpenMP Transpose Time (" << NUM_THREADS << " threads): " << duration.count() << " ms" << endl;

    bool isValid = validate_result();
    cout << "Validation: " << (isValid ? "PASSED ✅" : "FAILED ❌") << endl;

    ofstream out("../results/validation_checksums_omp.txt");
    if (out.is_open()) {
        out << "Validation: " << (isValid ? "PASSED" : "FAILED") << endl;
        out.close();
    }

    return 0;
}

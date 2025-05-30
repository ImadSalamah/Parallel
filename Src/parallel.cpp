#include <iostream>
#include <vector>
#include <pthread.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int N = 2000;
const int M = 2000;
const int NUM_THREADS = 4;

vector<vector<int>> A(N, vector<int>(M));
vector<vector<int>> B(M, vector<int>(N));

struct ThreadData {
    int startRow;
    int endRow;
};

void fill_matrix() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            A[i][j] = rand() % 100;
}

void* transpose_worker(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    for (int i = data->startRow; i < data->endRow; i++)
        for (int j = 0; j < M; j++)
            B[j][i] = A[i][j];
    pthread_exit(nullptr);
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

    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    int rowsPerThread = N / NUM_THREADS;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].startRow = i * rowsPerThread;
        threadData[i].endRow = (i == NUM_THREADS - 1) ? N : (i + 1) * rowsPerThread;
        pthread_create(&threads[i], nullptr, transpose_worker, &threadData[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], nullptr);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Parallel Transpose Time (" << NUM_THREADS << " threads): " << duration.count() << " ms" << endl;
    cout << "Validation: " << (validate_result() ? "PASSED ✅" : "FAILED ❌") << endl;

    return 0;
}


# 🧮 Matrix Transposition Projects – Sequential, Pthreads, and OpenMP

This repository contains two projects for transposing a matrix:

- **Project 1**: Sequential and Pthreads-based implementation.
- **Project 2**: OpenMP-based parallel implementation.

---

## 🧩 Project 1 – Sequential and Pthreads

### ✅ Description

This project implements matrix transposition using:
- A **sequential** version (single-threaded)
- A **parallel version** using POSIX Threads (Pthreads)

---

### 📁 Files

- `Src/sequential.cpp`: Sequential implementation
- `Src/parallel.cpp`: Pthreads implementation
- `results/`: Contains validation and timing output

---

### 📐 Matrix Sizes Tested

- 1000×1000  
- 2000×2000  
- 4000×4000  
- ... up to 32000×32000

---

### 🧵 Threads Used

- 1, 2, 4, 8, 16 threads (configurable)

---

## 🔁 Project 2 – Matrix Transposition using OpenMP

### ✅ Description

This part of the project implements matrix transposition using **OpenMP**, a shared-memory parallel programming model.  
It parallelizes the nested loops using:

```cpp
#pragma omp parallel for num_threads(NUM_THREADS)
```

Each thread processes separate rows, enabling concurrent execution and reduced overall time.

---

### ⚙️ Compilation Instructions (on macOS with GCC from Homebrew)

```bash
brew install gcc                     # One-time setup
cd project2/p2-Src
g++-15 -fopenmp parallel_omp.cpp -o parallel_omp
```

> Replace `g++-15` with your actual installed version.

---

### ▶️ Run Instructions

```bash
./parallel_omp
```

---

### 📐 Matrix Sizes Tested

- 1000×1000  
- 2000×2000  
- 4000×4000  
- 8000×8000  
- 16000×16000  
- 32000×32000

---

### 🧵 Threads Used

- 1, 2, 4, 8, 16 threads

---

### 🧪 Performance Results Summary

| Matrix Size  | Threads | Sequential (ms) | OpenMP (ms) | Speedup |
|--------------|---------|------------------|-------------|---------|
| 1000×1000    | 1       | 19               | 21          | 0.90×   |
| 1000×1000    | 4       | 19               | 5           | 3.80×   |
| 4000×4000    | 8       | 311              | 94          | 3.30×   |
| 8000×8000    | 16      | 1312             | 221         | 5.94×   |
| 32000×32000  | 16      | 39569            | 10464       | 3.78×   |

📊 Complete dataset available: [`p2-results/results-timingdata-omp.xlsx`](p2-results/results-timingdata-omp.xlsx)

---

### 💻 System Specs

- **CPU**: Intel(R) Core i7-8559U @ 2.70GHz  
- **Cores**: 4 Physical / 8 Logical  
- **RAM**: 16 GB  
- **OS**: macOS  

---

### ⚠️ Challenges Faced

- **OpenMP not supported by Clang (default on macOS)**  
  ✅ Solved using `g++-15` from Homebrew.

- **Low speedup for small matrices** due to thread overhead.  
  ✅ Better results with matrices ≥ 4000×4000.

- **Diminishing returns** observed beyond 8 threads.  
  ✅ Caused by memory access bottlenecks.

---

### ✅ Result Validation

All outputs were validated using `validate_result()` function.  
The console prints: `Validation: PASSED ✅` if successful.

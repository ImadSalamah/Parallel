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

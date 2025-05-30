# Matrix Transposition (Sequential & Parallel)

This project demonstrates how to perform matrix transposition using both **sequential** and **parallel** (multi-threaded) approaches in C++.

---

## 📁 Files Included

- `sequential.cpp`: Transposes a matrix using a standard for-loop (single-threaded).
- `parallel_no_struct.cpp`: Transposes a matrix using `pthread` without using `struct`, distributing rows among threads.

---

## 🧪 Matrix Size

Both programs operate on a matrix of size **2000 x 2000** by default. You can increase the size by modifying the constants `N` and `M` at the top of each file.

---

## 🧵 Threads

The parallel version uses `4` threads by default. You can change this by modifying the `NUM_THREADS` constant.

---

## 🛠️ Compilation

Make sure you have `g++` and `pthread` installed.

### Compile Sequential Version
```bash
g++ sequential.cpp -o sequential
```

### Compile Parallel Version
```bash
g++ parallel_no_struct.cpp -pthread -o parallel
```

---

## ▶️ Execution

### Run Sequential
```bash
./sequential
```

### Run Parallel
```bash
./parallel
```

---

## ✅ Validation

Both programs print:
- Execution time in milliseconds
- A validation check (`PASSED ✅` or `FAILED ❌`) to ensure the result is correct

---

## 📌 Notes

- No classes or structs are used in this implementation
- Uses `chrono` for timing
- Matrix elements are filled with random numbers

---

## 📚 References

- [Pthreads documentation](https://man7.org/linux/man-pages/man7/pthreads.7.html)
- [GeeksforGeeks - Matrix Transpose](https://www.geeksforgeeks.org/transpose-matrix/)

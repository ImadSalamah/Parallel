
# Matrix Transposition – Sequential and Parallel (Pthreads) :

This project implements matrix transposition using:
- A sequential version (single-threaded)
- A parallel version using POSIX threads (pthreads)



---

## 📁 Files 

- `sequential.cpp`: Sequential transpose 
- `parallel.cpp`: Parallel transpose with threads
- `results/`: Contains validation outputs and timing results 

---

## 📐 Matrix Sizes 

Tested sizes: 1000x1000, 2000x2000, ..., 32000x32000  

---

## 🧵 Threads Used 

Tested with 1, 2, 4, 8, 16 threads  


---

## 🛠️ Compilation 

```bash
g++ Src/sequential.cpp -o sequential
g++ Src/parallel.cpp -pthread -o parallel
```

---

## ▶️ Execution

```bash
./sequential
./parallel
```

---

## ✅ Validation 

Each version prints:  
- Execution time
- Result validation (PASSED or FAILED)
- `results/validation_checksums.txt`

---

## ⚙️ Tools 

- C++, pthread, chrono, macOS Terminal

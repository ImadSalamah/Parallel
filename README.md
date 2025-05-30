
# Matrix Transposition – Sequential and Parallel (Pthreads) | تبديل المصفوفة – تسلسلي ومتوازي (Pthreads)

This project implements matrix transposition using:
- A sequential version (single-threaded)
- A parallel version using POSIX threads (pthreads)

يطبق المشروع خوارزمية تبديل المصفوفة باستخدام:
- نسخة تسلسلية (خيط واحد)
- نسخة متوازية باستخدام pthread

---

## 📁 Files | الملفات

- `sequential.cpp`: Sequential transpose | التبديل التسلسلي
- `parallel.cpp`: Parallel transpose with threads | التبديل المتوازي
- `results/`: Contains validation outputs and timing results | نتائج التحقق والوقت

---

## 📐 Matrix Sizes | أحجام المصفوفات

Tested sizes: 1000x1000, 2000x2000, ..., 32000x32000  
تم الاختبار على: 1000x1000 حتى 32000x32000

---

## 🧵 Threads Used | عدد الخيوط

Tested with 1, 2, 4, 8, 16 threads  
تم استخدام: 1، 2، 4، 8، 16 خيطًا

---

## 🛠️ Compilation | الترجمة

```bash
g++ Src/sequential.cpp -o sequential
g++ Src/parallel.cpp -pthread -o parallel
```

---

## ▶️ Execution | التشغيل

```bash
./sequential
./parallel
```

---

## ✅ Validation | التحقق

Each version prints:  
كل نسخة تطبع:

- Execution time | زمن التنفيذ  
- Result validation (PASSED or FAILED) | صحة النتيجة (PASSED أو FAILED)  

Also saved in:  
وتُحفظ في:

- `results/validation_checksums_sequential.txt`  
- `results/validation_checksums.txt`

---

## ⚙️ Tools | الأدوات

- C++, pthread, chrono, macOS Terminal
- C++، pthread، chrono، نظام macOS

Here’s the Codeforces-style version of your problem, including constraints, edge cases, and a test generator using **testlib**.  

---

### **C. Doubled Numbers**  

**Time Limit:** 2 seconds  
**Memory Limit:** 1024 MB  

---

### **Problem Statement**  

You are given an integer $n$. Count how many integers $x$ between $1$ and $n$ (inclusive) satisfy the following condition:  

- The decimal representation of $x$ (without leading zeros) has an even number of digits.  
- The first half of the digits is the same as the second half.  

---

### **Input**  

The input consists of a single integer $n$ ($1 \leq n < 10^{12}$).  

---

### **Output**  

Print a single integer — the number of values satisfying the given conditions.  

---

### **Examples**  

#### **Input 1:**  
```
33
```
#### **Output 1:**  
```
3
```
**Explanation:** The valid numbers are **11, 22, 33**.  

---

#### **Input 2:**  
```
1333
```
#### **Output 2:**  
```
13
```
**Explanation:** Some valid numbers include **11, 22, 33, 44, 55, ..., 1313**.  

---

#### **Input 3:**  
```
10000000
```
#### **Output 3:**  
```
999
```
**Explanation:** The largest valid number is **9999**, contributing to a total count of **999**.  

---

### **Edge Cases to Consider**
1. **Smallest input:** $n = 1$  
2. **Largest possible n:** $n = 10^{12} - 1$  
3. **Cases where no valid number exists:** $n = 9$, $n = 10$, etc.  
4. **Boundaries of power of tens:** $n = 10^k - 1$ for $k = 2, 4, 6, 8, 10$  

---

### **Test Generator (Using testlib.h)**  

Here’s a **test generator** written in C++ using `testlib.h` for **Codeforces-style** testing.  

```cpp
#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    long long n = rnd.next(1LL, 999999999999LL); // Generates a number in the range [1, 10^12 - 1]
    cout << n << endl;

    return 0;
}
```

---

This version ensures the problem follows the Codeforces **format and style**, with edge cases and a test generator. Let me know if you need modifications! 🚀
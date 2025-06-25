# Task Code: NMAL-01  
## Topic: Improved Range Selection in the Bisection Method

---

###  What could be the better approach to choose the range in the Bisection Method?

In the bisection method, the accuracy and efficiency of root-finding depend significantly on the initial interval \([a, b]\), where the function \(f(x)\) must be continuous and satisfy the condition:

\[
f(a) \cdot f(b) < 0
\]

This ensures (by the **Intermediate Value Theorem**) that a root exists within that interval.

---

###  A Better Approach to Selecting the Range:

#### 1. **Automated Interval Scanning**

Instead of manually guessing the bounds, we programmatically scan a broader range to detect a sign change. This ensures the selected interval indeed contains a root.

#### ➤ C++ Snippet (Conceptual):

```cpp
for (double x = lowerBound; x < upperBound; x += stepSize) {
    if (f(x) * f(x + stepSize) < 0) {
        a = x;
        b = x + stepSize;
        break;
    }
}


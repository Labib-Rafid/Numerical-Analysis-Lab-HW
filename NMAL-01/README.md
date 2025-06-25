# Task Code: NMAL-01  
## Topic: Improved Range Selection in the Bisection Method

---

###  What could be the better approach to choose the range in the Bisection Method?

In the bisection method, the accuracy and efficiency of root-finding depend significantly on the initial interval \([a, b]\), where the function \(f(x)\) must be continuous and satisfy the condition:

f(a) * f(b) < 0
the function \( f(x) = 4x^2 + 3x - 3 \)


This ensures (by the **Intermediate Value Theorem**) that a root exists within that interval.

---

###  A Better Approach to Selecting the Range:

#### **Automated Interval Scanning**

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


````
This snippet scans through a specified domain in small increments and checks for a sign change in the function values between two consecutive points. If a sign change is detected, it indicates the presence of a root within that interval \([a, b]\).

This automated range detection method is far more reliable than manual guessing. It ensures that the Bisection Method starts with a valid interval, satisfying the condition f(a) * f(b) < 0 , which is crucial for convergence.

By narrowing down the range before applying the bisection algorithm, we reduce the number of iterations needed to reach the root within the desired tolerance. This leads to:
    (i) Faster convergence
    (ii) Increased efficiency
    (iii) Reduced computational cost
This technique is especially useful when the location of the root is not known in advance, making it a robust strategy in real-world applications involving complex or non-linear functions.

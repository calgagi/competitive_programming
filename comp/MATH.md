# Mathematical formulas

Triangle Inequality Theorem
---
Test to see if three side lengths can make a valid triangle.
~~~c++
bool valid_triangle(int a, int b, int c) {
    if (a + b <= c) return false;
    if (a + c <= b) return false;
    if (b + c <= a) return false;
    return true;
}
~~~

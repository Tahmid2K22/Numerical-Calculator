# Numerical Calculator

This project is developed in C++ to provide solutions to common numerical problems using standard numerical methods. It includes implementations of fundamental algorithms such as root finding, equation solving, and numerical approximation techniques. The project follows proper iterative procedures to ensure accuracy, stability, and convergence of results. File handling is incorporated to manage inputs and outputs in an organized and structured manner. Overall, this repository serves as a practical and educational introduction to numerical methods, demonstrating their real-world implementation using C++ programming.

## Contents

- [Algorithms](#algorithms)
  - [Bisection](#bisection)
  - [False Position](#false-position)
  - [Newton Raphson](#newton-raphson)
  - [Secant](#secant)
  - [Gauss Elimination](#gauss-elimination)
  - [Gauss Jordan](#gauss-jordan)
  - [LU Decomposition](#lu-decomposition)
  - [Naive Matrix Inversion](#naive-matrix-inversion)
  - [Interpolation](#interpolation)
  - [Regression](#regression)
  - [Forward Differentiation](#forward-differentiation)
  - [Backward Differentiation](#backward-differentiation)
  - [Runge Kutta (RK)](#runge-kutta-rk)
  - [Simpson 1/3](#simpson-13)
  - [Simpson 3/8](#simpson-38)

Each algorithm folder also includes `input.txt`, `output.txt`, and `theory.txt`.

Some algorithms support optional method selection in the input (e.g. interpolation and regression). If you omit the method token, the program uses a sensible default.


## Algorithms

Quick links to folders + sample files:

| Algorithm | Category | Folder | Sample input | Sample output |
|---|---|---|---|---|
| Bisection | Non-Linear System | [`src/algorithm/bisection/`](src/algorithm/bisection/) | [`input.txt`](src/algorithm/bisection/input.txt) | [`output.txt`](src/algorithm/bisection/output.txt) |
| False Position | Non-Linear System | [`src/algorithm/falsi/`](src/algorithm/falsi/) | [`input.txt`](src/algorithm/falsi/input.txt) | [`output.txt`](src/algorithm/falsi/output.txt) |
| Newton–Raphson | Non-Linear System | [`src/algorithm/newton_raphson/`](src/algorithm/newton_raphson/) | [`input.txt`](src/algorithm/newton_raphson/input.txt) | [`output.txt`](src/algorithm/newton_raphson/output.txt) |
| Secant | Non-Linear System | [`src/algorithm/secant/`](src/algorithm/secant/) | [`input.txt`](src/algorithm/secant/input.txt) | [`output.txt`](src/algorithm/secant/output.txt) |
| Gauss Elimination | Linear systems | [`src/algorithm/gauss_elimination/`](src/algorithm/gauss_elimination/) | [`input.txt`](src/algorithm/gauss_elimination/input.txt) | [`output.txt`](src/algorithm/gauss_elimination/output.txt) |
| Gauss–Jordan | Linear systems | [`src/algorithm/gauss_jordan/`](src/algorithm/gauss_jordan/) | [`input.txt`](src/algorithm/gauss_jordan/input.txt) | [`output.txt`](src/algorithm/gauss_jordan/output.txt) |
| LU Decomposition | Linear systems | [`src/algorithm/lu_decomposition/`](src/algorithm/lu_decomposition/) | [`input.txt`](src/algorithm/lu_decomposition/input.txt) | [`output.txt`](src/algorithm/lu_decomposition/output.txt) |
| inverse | Linear algebra | [`src/algorithm/naive_inverse/`](src/algorithm/naive_inverse/) | [`input.txt`](src/algorithm/naive_inverse/input.txt) | [`output.txt`](src/algorithm/naive_inverse/output.txt) |
| Interpolation | Interpolation | [`src/algorithm/interpolation/`](src/algorithm/interpolation/) | [`input.txt`](src/algorithm/interpolation/input.txt) | [`output.txt`](src/algorithm/interpolation/output.txt) |
| Regression | Curve fitting | [`src/algorithm/regression/`](src/algorithm/regression/) | [`input.txt`](src/algorithm/regression/input.txt) | [`output.txt`](src/algorithm/regression/output.txt) |
| Forward difference | Differentiation | [`src/algorithm/differentiation_forward/`](src/algorithm/differentiation_forward/) | [`input.txt`](src/algorithm/differentiation_forward/input.txt) | [`output.txt`](src/algorithm/differentiation_forward/output.txt) |
| Backward difference | Differentiation | [`src/algorithm/differentiation_backward/`](src/algorithm/differentiation_backward/) | [`input.txt`](src/algorithm/differentiation_backward/input.txt) | [`output.txt`](src/algorithm/differentiation_backward/output.txt) |
| Runge–Kutta | ODE solving | [`src/algorithm/RK_Method/`](src/algorithm/RK_Method/) | [`input.txt`](src/algorithm/RK_Method/input.txt) | [`output.txt`](src/algorithm/RK_Method/output.txt) |
| Simpson 1/3 | Integration | [`src/algorithm/simpson_one_third/`](src/algorithm/simpson_one_third/) | [`input.txt`](src/algorithm/simpson_one_third/input.txt) | [`output.txt`](src/algorithm/simpson_one_third/output.txt) |
| Simpson 3/8 | Integration | [`src/algorithm/simpson_three_eight/`](src/algorithm/simpson_three_eight/) | [`input.txt`](src/algorithm/simpson_three_eight/input.txt) | [`output.txt`](src/algorithm/simpson_three_eight/output.txt) |

---

### Bisection

Finds a root by repeatedly halving an interval.

- Needs f(a) and f(b) with opposite signs.
- Stops when the interval is small enough.

Sample Input:

```text
2
1 0 -4
1 0 1 0.000001 100
```

Sample Output:

```text
2.00000000 2.00000000
2.00000000
```

Links: [folder](src/algorithm/bisection/) • [theory](src/algorithm/bisection/theory.txt) • [sample input](src/algorithm/bisection/input.txt) • [sample output](src/algorithm/bisection/output.txt) • [back to top](#numerical-calculator)

### False Position

Like bisection, but picks the next point using a secant (straight line) estimate.

- Keeps the root bracketed.
- Often faster than bisection at the start.

Sample Input:

```text
2
1 0 -4
1 0 1 0.000001 100
```

Sample Output:

```text
2.00000000 2.00000000
2.000000
```

Links: [folder](src/algorithm/falsi/) • [theory](src/algorithm/falsi/theory.txt) • [sample input](src/algorithm/falsi/input.txt) • [sample output](src/algorithm/falsi/output.txt) • [back to top](#numerical-calculator)

### Newton Raphson

Uses derivatives to jump quickly to a root.

- Very fast when the first guess is good.
- Can fail if the derivative is near zero.

Sample Input:

```text
2
1 0 -4
3 0.000001 100
```

Sample Output:

```text
2.000000
```

Links: [folder](src/algorithm/newton_raphson/) • [theory](src/algorithm/newton_raphson/theory.txt) • [sample input](src/algorithm/newton_raphson/input.txt) • [sample output](src/algorithm/newton_raphson/output.txt) • [back to top](#numerical-calculator)

### Secant

Like Newton Raphson, but it does not need derivatives.

- Uses two previous points.
- Can fail if the values become unstable.

Sample Input:

```text
2
1 0 -4
1 3 0.000001 100
```

Sample Output:

```text
2.00000000 2.00000000
2.000000
```

Links: [folder](src/algorithm/secant/) • [theory](src/algorithm/secant/theory.txt) • [sample input](src/algorithm/secant/input.txt) • [sample output](src/algorithm/secant/output.txt) • [back to top](#numerical-calculator)

### Gauss Elimination

Solves Ax=b using row operations.

- Converts the matrix to upper triangular form.
- Then uses back substitution.

Sample Input:

```text
2
1 1 3
1 -1 1
```

Sample Output:

```text
2.00000000 1.00000000
```

Links: [folder](src/algorithm/gauss_elimination/) • [theory](src/algorithm/gauss_elimination/theory.txt) • [sample input](src/algorithm/gauss_elimination/input.txt) • [sample output](src/algorithm/gauss_elimination/output.txt) • [back to top](#numerical-calculator)

### Gauss Jordan

Solves Ax=b by turning [A|b] into [I|x].

- Uses row operations on the whole column.
- Gives the answer directly.

Sample Input:

```text
2
1 1 3
1 -1 1
```

Sample Output:

```text
2.00000000 1.00000000
```

Links: [folder](src/algorithm/gauss_jordan/) • [theory](src/algorithm/gauss_jordan/theory.txt) • [sample input](src/algorithm/gauss_jordan/input.txt) • [sample output](src/algorithm/gauss_jordan/output.txt) • [back to top](#numerical-calculator)

### LU Decomposition

Splits A into L and U, then solves with substitution.

- Useful if you solve the same matrix many times.

Sample Input:

```text
2
1 1
1 -1
3 1
```

Sample Output:

```text
2.00000000 1.00000000
```

Links: [folder](src/algorithm/lu_decomposition/) • [theory](src/algorithm/lu_decomposition/theory.txt) • [sample input](src/algorithm/lu_decomposition/input.txt) • [sample output](src/algorithm/lu_decomposition/output.txt) • [back to top](#numerical-calculator)

### Naive Matrix Inversion

Finds A⁻¹ (if it exists) and then computes x = A⁻¹b.

Sample Input:

```text
2
4 7
2 6
```

Sample Output:

```text
0.60000000 -0.70000000
-0.20000000 0.40000000
```

Links: [folder](src/algorithm/naive_inverse/) • [theory](src/algorithm/naive_inverse/theory.txt) • [sample input](src/algorithm/naive_inverse/input.txt) • [sample output](src/algorithm/naive_inverse/output.txt) • [back to top](#numerical-calculator)

### Interpolation

Estimates values between known data points.

Sample Input:

```text
3
0 0
1 1
2 4
1.5
```

Sample Output:

```text
Data Points:
Result: 2.25000000
```

Links: [folder](src/algorithm/interpolation/) • [theory](src/algorithm/interpolation/theory.txt) • [sample input](src/algorithm/interpolation/input.txt) • [sample output](src/algorithm/interpolation/output.txt) • [back to top](#numerical-calculator)

### Regression

Fits a curve to data (best fit).

Sample Input:

```text
4
1 2 3 4
2 4 6 8
2.5
```

Sample Output:

```text
Linear Regression: 5.00000000
```

Links: [folder](src/algorithm/regression/) • [theory](src/algorithm/regression/theory.txt) • [sample input](src/algorithm/regression/input.txt) • [sample output](src/algorithm/regression/output.txt) • [back to top](#numerical-calculator)

### Forward Differentiation

Approximates the derivative using a forward step.

Sample Input:

```text
4
0 1 2 3
0 1 4 9
0
```

Sample Output:

```text
0
```

Links: [folder](src/algorithm/differentiation_forward/) • [theory](src/algorithm/differentiation_forward/theory.txt) • [sample input](src/algorithm/differentiation_forward/input.txt) • [sample output](src/algorithm/differentiation_forward/output.txt) • [back to top](#numerical-calculator)

### Backward Differentiation

Approximates the derivative using a backward step.

Sample Input:

```text
4
0 1 2 3
0 1 4 9
3
```

Sample Output:

```text
6
```

Links: [folder](src/algorithm/differentiation_backward/) • [theory](src/algorithm/differentiation_backward/theory.txt) • [sample input](src/algorithm/differentiation_backward/input.txt) • [sample output](src/algorithm/differentiation_backward/output.txt) • [back to top](#numerical-calculator)

### Runge Kutta (RK)

Solves ODE problems like y' = f(x,y) step by step.

Sample Input:

```text
0 1 0.1 1
```

Sample Output:

```text
1.11034167
```

Links: [folder](src/algorithm/RK_Method/) • [theory](src/algorithm/RK_Method/theory.txt) • [sample input](src/algorithm/RK_Method/input.txt) • [sample output](src/algorithm/RK_Method/output.txt) • [back to top](#numerical-calculator)

### Simpson 1/3

Approximates an integral using parabolas.

Sample Input:

```text
0 3 6
2
1 0 0
```

Sample Output:

```text
9
```

Links: [folder](src/algorithm/simpson_one_third/) • [theory](src/algorithm/simpson_one_third/theory.txt) • [sample input](src/algorithm/simpson_one_third/input.txt) • [sample output](src/algorithm/simpson_one_third/output.txt) • [back to top](#numerical-calculator)

### Simpson 3/8

Approximates an integral using cubic fits.

Sample Input:

```text
0 3 6
2
1 0 0
```

Sample Output:

```text
9
```

Links: [folder](src/algorithm/simpson_three_eight/) • [theory](src/algorithm/simpson_three_eight/theory.txt) • [sample input](src/algorithm/simpson_three_eight/input.txt) • [sample output](src/algorithm/simpson_three_eight/output.txt) • [back to top](#numerical-calculator)



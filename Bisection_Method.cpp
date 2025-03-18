#include <bits/stdc++.h>
using namespace std;

// Define the function for which we want to find the root
double f(double x) 
{
    // Example function: f(x) = x^3 - 2x - 5
    return x * x * x - 2 * x - 5;  
}

// Bisection method implementation
double bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Error: The function must have opposite signs at a and b." << endl;
        return NAN;  // Return NaN if the interval is invalid
    }

    double c;
    while ((b - a) / 2 > tol) {  // Stopping condition
        c = (a + b) / 2;  // Compute midpoint

        if (f(c) == 0) {
            break;  // Check if c is the root
        } 
        else if (f(a) * f(c) < 0) {  // Root lies in [a, c]
            b = c;
        } 
        else {  // Root lies in [c, b]
            a = c;
        }
    }

    return (a + b) / 2;  // Return the approximate root
}

int main() {
    double a = 2.0;  // Left endpoint of the interval
    double b = 3.0;  // Right endpoint of the interval
    double tol = 1e-6;  // Tolerance for convergence

    double root = bisection(a, b, tol);

    if (!isnan(root)) {
        cout << "Root: " << fixed << setprecision(5) << root << endl;
    }

    return 0;
}

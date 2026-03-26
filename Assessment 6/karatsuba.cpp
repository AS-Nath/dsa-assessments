#include <bits/stdc++.h>
using namespace std;

long long int multiply(int n1, int n2) {
    if (n1 < 10 || n2 < 10) {
        return n1 * n2; 
    }
    int n; 
    if (n1 > 0 && n2 > 0) {
        n = static_cast<int>(log10(n1)) + 1 > static_cast<int>(log10(n2)) + 1 ? static_cast<int>(log10(n1)) + 1 : static_cast<int>(log10(n2)) + 1;
    }
    n = n1 > n2 ? static_cast<int>(log10(n1)) + 1 : static_cast<int>(log10(n2)) + 1;
    // Karatsuba fractions
    int b = n1 % static_cast<int>(pow(10, n / 2));
    int a = (n1 - b) / static_cast<int>(pow(10, n / 2)); 
    int d = n2 % static_cast<int>(pow(10, n / 2));
    int c = (n2 - d) / static_cast<int>(pow(10, n / 2));
    long long int p1 = multiply(a, c);
    long long int p2 = multiply(a + b, c + d);
    long long int p3 = multiply(b, d); 
    return p1 * pow(10, 2 * (n / 2)) + (p2 - p1 - p3) * pow(10, (n / 2)) + p3; 
}

int main(void) {
    int n1; 
    int n2;
    cin >> n1 >> n2; 
    cout << multiply(n1, n2) << endl; 
    return 0;
}
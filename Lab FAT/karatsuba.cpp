#include <bits/stdc++.h>
using namespace std;

int len(long long int n) {
    return static_cast<int>(log10(n)) + 1; 
}

long long int power10(int n) {
    long long int r = 1;
    for (int i = 0; i < n; i++) r *= 10; 
    return r; 
}

long long int multiply(long long int n1, long long int n2) {
    if (n1 < 10 || n2 < 10) {
        return n1 * n2; 
    }
    int n = (n1 > n2) ? len(n1) : len(n2); 
    long long int b = n1 % power10(n / 2); 
    long long int a = (n1 - b) / power10(n / 2); 
    long long int d = n2 % power10(n / 2); 
    long long int c = (n2 - d) / power10(n / 2);
    long long int p1 = multiply(a, c); 
    long long int p2 = multiply(b, d); 
    long long int p3 = multiply(a + b, c + d); 
    return p1 * power10((n / 2) * 2) + (p3 - p2 - p1) * power10(n / 2) + p2; 
}

int main(void) {
    long long int a;
    long long int b;
    cin >> a >> b;
    cout << multiply(a, b) << endl; 
    return 0; 
}
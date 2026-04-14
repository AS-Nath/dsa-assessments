#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n, 0); 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Found at index " << i << "!" << endl;
            return 0; 
        }
    }
    cout << "Not Found!" << endl;
    return 0; 
}
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int lend, int r, int rend) {
    vector<int> copyout(rend - l + 1, 0); 
    int lindex = l;
    int rindex = r; 
    int i = 0; 
    while (lindex <= lend && rindex <= rend) {
        if (arr[lindex] < arr[rindex]) {
            copyout[i] = arr[lindex]; 
            lindex += 1; 
        }
        else {
            copyout[i] = arr[rindex]; 
            rindex += 1;
        }
        i += 1;
    }
    while (lindex <= lend) {
        copyout[i] = arr[lindex]; 
        i += 1;
        lindex += 1;
    }
    while (rindex <= rend) {
        copyout[i] = arr[rindex];
        i += 1;
        rindex += 1; 
    }
    int c = l; 
    for (int i = 0; i < copyout.size(); i++) {
        arr[c] = copyout[i];
        c += 1; 
    }
}

void mergesort(vector<int>& arr, int l, int r) {
    if (l == r) {
        return; 
    }
    mergesort(arr, 0, (l + r) / 2); 
    mergesort(arr, ((l + r) / 2) + 1, r); 
    merge(arr, l, (l + r) / 2, ((l + r) / 2) + 1, r); 
}

int main(void) {
    int n; 
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i]; 
    mergesort(arr, 0, n - 1); 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;
    return 0; 
}
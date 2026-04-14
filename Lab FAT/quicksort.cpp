#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int l, int r) { 
    int p_index = l;
    int p_value = arr[r]; 
    for (int i = l; i < r; i++) {
        if (arr[i] < p_value) {
            int t = arr[i];
            arr[i] = arr[p_index]; 
            arr[p_index] = t; 
            p_index += 1; 
        }
    } 
    arr[r] = arr[p_index]; 
    arr[p_index] = p_value; 
    return p_index; 
}

void quicksort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return; 
    }
    int part_index = partition(arr, l, r); 
    quicksort(arr, l, part_index - 1); 
    quicksort(arr, part_index + 1, r);  
}

int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i]; 
    quicksort(arr, 0, n - 1); 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
    return 0; 
}
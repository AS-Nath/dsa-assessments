#include <bits/stdc++.h>
using namespace std;

void printvector(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
}

void insertionsort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int value = arr[i];
        int j = i; 
        while (j > 0 && value < arr[j - 1]) {
            arr[j] = arr[j - 1]; 
            j -= 1; 
        }
        arr[j] = value; 
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n, 0); 
    for (int i = 0; i < n; i++) cin >> arr[i]; 
    insertionsort(arr); 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0; 
}
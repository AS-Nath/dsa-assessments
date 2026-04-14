#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int& target, int left, int right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
        return mid; 
    }
    else if (left == right) {
        return -1; 
    }
    else if (arr[mid] < target) {
        return search(arr, target, mid + 1, right); 
    }
    else {
        return search(arr, target, left, mid - 1); 
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;
    int x = -1;
    int left = 0;
    int right = n - 1; 
    if ((x = search(arr, target, left, right)) > -1) {
        cout << "Found at index " << x << "!" << endl; 
    }
    else {
        cout << "Not Found!" << endl; 
    }
    return 0; 
}
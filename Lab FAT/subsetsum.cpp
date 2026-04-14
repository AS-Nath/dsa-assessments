#include <bits/stdc++.h>
using namespace std;

void evaluate(vector<int>& arr, int& target, vector<int>& current, int& curr_sum, int i) {
    if (i == arr.size()) {
        if (curr_sum == target) {
            for (int i = 0; i < current.size(); i++) {
                cout << current[i] << " ";
            }
            cout << endl; 
        }
        return; 
    }
    // Don't take, then take. 
    evaluate(arr, target, current, curr_sum, i + 1); 
    current.push_back(arr[i]); 
    curr_sum += arr[i];
    evaluate(arr, target, current, curr_sum, i + 1); 
    current.pop_back();
    curr_sum -= arr[i];
}

int main(void) {
    int n;
    cin >> n;
    vector<int> arr(n ,0);
    for (int i = 0; i < n; i++) cin >> arr[i]; 
    int target;
    cin >> target; 
    vector<int> current;
    int curr_sum = 0; 
    vector<int> ans;
    int ans_sum = INT_MAX; 
    int i = 0; 
    evaluate(arr, target, current, curr_sum, i); 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& items, int current_index, int& max_weight, int current_weight, int& max_value, int current_value, vector<int>& sequence, vector<int>& answer) {
    if (current_weight > max_weight) {
        return; 
    }
    if (current_index == items.size()) {
        if (current_value > max_value) {
            max_value = current_value; 
            answer = sequence;
        }
        return; 
    }
    // Don't take. 
    solve(items, current_index + 1, max_weight, current_weight, max_value, current_value, sequence, answer); 
    // Take. 
    sequence.push_back(items[current_index][0]); 
    current_weight += items[current_index][1]; 
    current_value += items[current_index][2]; 
    solve(items, current_index + 1, max_weight, current_weight, max_value, current_value, sequence, answer);
    sequence.pop_back();
}

int main(void) {
    int w;
    cin >> w;
    int n;
    cin >> n; 
    vector<vector<int>> items(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        cin >> items[i][0] >> items[i][1] >> items[i][2]; // ID, weight, value
    } 
    int max_value = 0;
    vector<int> answer;
    vector<int> sequence;
    solve(items, 0, w, 0, max_value, 0, sequence, answer); 
    cout << "Items to take : "; 
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\nValue : " << max_value << "\n"; 
    return 0; 
}
/*
10
4
1 4 40
2 7 42
3 5 25
4 3 12
*/
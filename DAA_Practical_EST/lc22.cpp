#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<string> ans = s.generateParenthesis(n);

    for (auto &p : ans) {
        cout << p << endl;
    }
}

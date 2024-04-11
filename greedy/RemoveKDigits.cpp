class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
        for (char c : num) {
            while (!stack.empty() && k > 0 && stack.top() > c) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        while (!stack.empty() && k > 0) {
            stack.pop();
            k--;
        }
        string res = "";
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] == '0') res.erase(i, 1);
            else break;
        }
        reverse(res.begin(), res.end());
        return (res == "") ? "0" : res;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        std::pair<int, int> best = {0, 0};

        // 擴展 lambda 函數：Zero-Allocation 暫存器操作
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            // 迴圈結束時 left 和 right 都多往外走了一步
            // 實際迴文邊界是 [left + 1, right - 1]
            return std::make_pair(left + 1, right - 1);
        };

        for (int i = 0; i < s.size(); ++i) {
            // 1. 奇數長度迴文 (以 s[i] 為中心)
            auto p1 = expand(i, i);
            if (p1.second - p1.first > best.second - best.first) {
                best = p1;
            }

            // 2. 偶數長度迴文 (以 s[i] 和 s[i+1] 中間為中心)
            auto p2 = expand(i, i + 1);
            if (p2.second - p2.first > best.second - best.first) {
                best = p2;
            }
        }

        // 最後才切字串
        return s.substr(best.first, best.second - best.first + 1);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) return 0;
    multiset<char> se;

    int start = 0;
    int end = 0;

    char duplicated_char = 'x';
    int is_duplicated = 0;
    int ans = 0;
    while (1) {
      if (!is_duplicated) {
        if (se.count(s[end]) >= 1) {
          is_duplicated = 1;
          duplicated_char = s[end];
        }
        se.emplace(s[end]);
        end++;
      } else {
        if (s[start] == duplicated_char) {
          is_duplicated = 0;
        }
        se.erase(se.find(s[start]));
        start++;
      }

      int ans_tmp = end - start;
      if (!is_duplicated && ans < ans_tmp) ans = ans_tmp;
      if (end == s.size()) break;
    }
    return ans;
  }
};

int main() {
  Solution s;
  int ans = s.lengthOfLongestSubstring("pwwkew");
  cout << ans << endl;
  ;
}
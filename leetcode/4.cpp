#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged = nums1;
    for (auto n : nums2) {
      merged.push_back(n);
    }
    sort(merged.begin(), merged.end());

    int n = merged.size();
    if (n % 2) return merged[n / 2];

    return (merged[n / 2] + merged[n / 2 - 1]) / (double)2;
  }
};

int main() { Solution s; }
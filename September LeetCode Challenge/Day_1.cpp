class Solution {
public:
  string largestTimeFromDigits(vector<int>& A) {
    sort(begin(A), end(A), greater<int>());
    string hour, min;
    do {
      hour = to_string(A[0]) + to_string(A[1]);
      min  = to_string(A[2]) + to_string(A[3]);
      if (hour < "24" && min < "60") return hour + ":" + min;
    } while (prev_permutation(begin(A), end(A)));
    return "";
  }
};
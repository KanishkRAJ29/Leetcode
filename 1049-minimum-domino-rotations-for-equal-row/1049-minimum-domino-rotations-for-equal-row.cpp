class Solution {
public:
int solveFor(int x, vector<int>& T, vector<int>& B) {
  int flipT = 0, flipB = 0;
  for (int i = 0; i < T.size(); i++) {
    if (T[i] != x && B[i] != x) return -1;
    if (T[i] != x) ++flipT;  
    if (B[i] != x) ++flipB;   
  }
  return min(flipT, flipB);
}
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int a = solveFor(tops[0], tops, bottoms);
  int b = solveFor(bottoms[0], tops, bottoms);
  if (a == -1 && b == -1) return -1;
  if (a == -1) return b;
  if (b == -1) return a;
  return min(a, b);
    }
};
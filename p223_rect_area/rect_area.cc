/**
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * 
 * Rectangle Area
 * 
 * Example:
 * 
 * Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
 * Output: 45
 * Note:
 * 
 * Assume that the total area is never beyond the maximum possible value of int.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const int w1 = C - A;
        const int h1 = D - B;
        const int area1 = w1 * h1;
        const int w2 = H - F;
        const int h2 = G - E;
        const int area2 = w2 * h2;
        // horizontal overalap
        int wo = 0;
        if (C >=G && G > A) {
            wo = min(G - A, G - E);
        } else if (G >= C && C > E) {
            wo = min(C - E, C - A);
        }
        // vertical overalap
        int ho = 0;
        if (D >= H && H > B) {
            ho = min(H - B, H - F);
        } else if (H >= D && D > F) {
            ho = min(D - F, D - B);
        }
        const int areao = wo * ho;
        return area1 - areao + area2;
    }
};

int main() {
    Solution obj;
    auto run = [&](int a, int b, int c, int d, int e, int f, int g, int h) {
        cout << obj.computeArea(a, b, c, d, e, f, g, h) << endl;
    };
    run(-3, 0, 3, 4, 0, -1, 9, 2);
    run(0,0,50000,40000,0,0,50000,40000);
    run(-2,-2,2,2,-1,4,1,6);
    return 0;
}

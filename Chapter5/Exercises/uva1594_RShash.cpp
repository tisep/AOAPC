// https://github.com/morris821028/UVa/blob/master/volume015/1594%20-%20Ducci%20Sequence.cpp
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <assert.h>
#include <map>
#include <algorithm>
using namespace std;

int nextSeq(int A[], int n) {
    // int B[32];
    A[n] = A[0];
    for (int i = 0; i < n; i++)
        A[i] = abs(A[i] - A[i+1]);
    // for (int i = 0; i < n; i++)
    //     A[i] = B[i];
    A[n] = A[0];
    return 1;
}
int main() {
    int testcase, n, A[32];
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        A[n] = A[0];

        map<int, int> R;
        do {
            int ok = 1, hash = 0;
            int a = 63689, b = 378551;
            for (int i = 0; i < n; i++) {
                hash = hash * a + A[i], a = a * b;
                ok &= A[i] == 0;
            }
            if (ok) {
                puts("ZERO");
                break;
            }
            int &f = R[hash];
            if (f) {
                puts("LOOP");
                break;
            }
            f = 1;
        } while (nextSeq(A, n));
    }
    return 0;
}

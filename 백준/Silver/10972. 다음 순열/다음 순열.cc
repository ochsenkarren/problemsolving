#include <cstdio>
#include <vector>

using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int main(void) {
    int N;
    scanf("%d", &N);
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    int i = 1, idx = -1;
    while (i < N) {
        if (v[i - 1] < v[i])
            idx = i;
        ++i;
    }
    if (idx == -1) {
        printf("-1\n");
        return 0;
    }
    int l = idx - 1, r = idx;
    for (int j = idx + 1; j < N; j++) {
        if (v[l] < v[j])
            r = j;
    }
    swap(v[l], v[r]);
    for (int j = 0; idx + j < N - 1 - j; ++j)
        swap(v[idx + j], v[N - 1 - j]);
    printf("%d", v[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", v[i]);
}
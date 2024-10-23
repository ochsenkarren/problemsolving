#include <cstdio>
int main(void) {
    int T, a, b;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d", &b);
        scanf("%d", &a);
        printf("Case #%d: %d\n", i, a + b);
    }
    return 0;
}
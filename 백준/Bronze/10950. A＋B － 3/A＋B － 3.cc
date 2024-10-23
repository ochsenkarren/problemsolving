#include <cstdio>
int main(void) {
    int T, a, b;
    scanf("%d\n", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d\n", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}
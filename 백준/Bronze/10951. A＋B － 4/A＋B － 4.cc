#include <cstdio>
int main(void) {
    int a, b;
    int flag = scanf("%d %d", &a, &b);
    while (flag == 2) {
        printf("%d\n", a + b);
        flag = scanf("%d %d", &a, &b);
    }
    return 0;
}
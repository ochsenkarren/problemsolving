#include <cstdio>
#include <vector>
using namespace std;
const int LEN = 20000001;
const int BIAS = LEN / 2;

int main(void) {
	vector<bool> nums(LEN, false);
	int N, M;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int idx;
    	scanf("%d", &idx);
		nums[idx + BIAS] = true;
	}
	scanf("%d", &M);
    int i = 0;
    do {
        int num;
        scanf("%d", &num);
        printf("%d", nums[num + BIAS] ? 1 : 0);
    } while (++i < M && printf(" "));

}
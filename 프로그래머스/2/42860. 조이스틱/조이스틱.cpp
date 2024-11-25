#include <string>
#include <vector>

using namespace std;
int len;
int min_ = ~(1 << 31);
void go(vector<bool> &v, int pos, int toFix, int count) {
    if (toFix == 0) {
        min_ = count < min_ ? count : min_;
        return ;
    }
    // 왼쪽 접근
    int l = pos, add = 0;
    while (true) {
        if (--l < 0)
            l += len;
        ++add;
        if (!v[l])
            break;
    }
    v[l] = true;
    go(v, l, toFix - 1, count + add);
    v[l] = false;
    add = 0;
    int r = pos;
    while (true) {
        if (++r == len)
            r = 0;
        ++add;
        if (!v[r])
            break;
    }
    v[r] = true;
    go(v, r, toFix - 1, count + add);
    v[r] = false;
}

int solution(string name) {
    int toFix = 0, fixCount = 0;
    len = name.size();
    vector<bool> v(len, true);
    for (int i = 0; i < len; ++i) {
		if (int diff = name[i] - 'A') {
			if ('Z' - name[i] + 1 < diff)
				diff = 'Z' - name[i] + 1;
			v[i] = false;
			++toFix;

			fixCount += diff;
		}
	}

    min_ = ~(1 << 31);
    if (!v[0]) {
        v[0] = true;
        --toFix;
    }
    go (v, 0, toFix, 0);

    return min_ + fixCount;
}
/*************************************************************************
	> File Name: E_43.cpp
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年04月29日 星期一 09时47分17秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

int list[7] = {2, 3, 5, 7, 11, 13, 17};

long answer(int *a) {
    long num = a[0], ret = a[0];
    int j = 0;
    for (int i = 1; i < 10; i++) {
        ret = ret * 10 + a[i];
        num = num * 10 + a[i];
        if (i < 3) continue;
        num -= 1000 * a[i - 3];
        if (num % list[j++]) return 0;
    }
    return ret;
}


long check(int *a) {
	int j = 0;
	for (int i = 1; i < 8; ++i, ++j) {
		int tmp_ans = (a[i] * 100 + a[i + 1] * 10 + a[i+ 2]);
		if ( tmp_ans % list[j] != 0) return 0;
	}
	long sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum *= 10;
		sum += a[i];
	}
	return sum;
	
}

int main() {
	int a[10] = {0};
	long sum = 0;
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}

	do {
		sum += check(a);
	} while (next_permutation(a, a + 10));
	printf("%ld\n", sum);


	return 0;
}

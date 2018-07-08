/*************************************************************************
	> File Name: E_38.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年04月29日 星期一 09时21分17秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>



int is_pan(int n, int *num) {
	int t = n;
	while (t) {
		if (t % 10 == 0) return 0;
		if (num[t % 10]) return 0;
		num[t % 10] = 1;
		t /= 10;
	}
	return 1;
}

int test(int x) {
	int num[10] = {0};
	int tmp_ans = 0;
	int value;
	for (int i = 1; ; ++i) {
		int t = x * i;
		if (!is_pan(t, num)) return 0;
		value = pow(10, floor(log10(t)) + 1);
		tmp_ans = tmp_ans * value + t;
		int digits = floor(log10(tmp_ans)) + 1;
		if (digits > 9) return 0;
		else if (digits == 9) return tmp_ans;

	}
}

int main() {
	int ans = 0;
	for (int i = 1; i < 10000; ++i) {
		int x = test(i);
		ans = ans > x ? ans : x;

	}
	printf("%d\n", ans);

	return 0;
}
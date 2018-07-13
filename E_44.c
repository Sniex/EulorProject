/*************************************************************************
	> File Name: E_44.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年04月29日 星期一 09时47分17秒
 ************************************************************************/

#include <stdio.h>
#include <limits.h>

long pent(long n) {
	return n * (n * 3 - 1) / 2;
}

long is_pent(long *num, long l, long r, long k) {
	long mid = (l + r) / 2;
	if (num[mid] == k) return mid;
	if (l >= r) return 0;
	if (num[mid] < k) return is_pent(num, mid + 1, r, k);
	else if (num[mid] > k) return is_pent(num, l, mid - 1, k);
}

int is_pentagonal(long n) {
    long head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        long value = mid * (3 * mid - 1) / 2;
        if (value == n) return 1;
        if (value > n) tail = mid - 1;
        else head = mid + 1;
    }
    return 0;
}

long loop() {
	long p[1000000] = {0};
	long d = INT_MAX;
	for (long k = 1; k < 1000000; k++) {
		p[++p[0]] = pent(k);
		long tmp = INT_MAX - 1;
		if (d <= p[k] - p[k - 1]) break;
		for (long j = k - 1; j > 0; j--) {
			if (is_pentagonal(p[k] - p[j]) && is_pentagonal(p[k] + p[j])) {
				tmp = p[k] - p[j];
				return tmp;
			}
			
		}
	}
	return d;
}


int main() {
	long x = loop();
	printf("%ld\n", x);

	return 0;
}

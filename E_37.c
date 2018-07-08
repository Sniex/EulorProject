/*************************************************************************
	> File Name: E_37.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年04月25日 星期一 19时16分17秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX 1000000

int prime[MAX + 5] = {0};
int is_prime[MAX + 5] = {0};

int is_prime1(int n) {
	if(n == 1) return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int is_f(int n) {
	int source = n;
	int digi = (int)floor(log10(n));
	// int tmp1 = digi;
	for (int i = 0; i < digi+1; i++) {
		int tmp = n / 10;
		if (!is_prime1(tmp)) {
			return 0;
		}
		n = tmp;
	}
	n = source;
	for (int i = 0; i < digi + 1; i++) {
		int tmp = n % (int)pow(10, digi-i);
		if (!is_prime1(tmp)) {
			return 0;
		}
		n = tmp;
	}	
	return 1;
}

int main() {
	for (int i = 2; i <= MAX; i++) {
		if(!prime[i]) is_prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0]; ++j) {
			if (i * is_prime[j] > MAX) break;
			prime[i * is_prime[j]] = 1;
			if (i % is_prime[j] == 0) break;
		}
	}
	int sum = 0;
	for (int i = 1; i < prime[0]; i++) {
		if (is_prime[i] < 20) continue;
		if (is_f(is_prime[i])) {
			sum += is_prime[i];
		}
	}
	printf("%d\n", sum);

	return 0;
}
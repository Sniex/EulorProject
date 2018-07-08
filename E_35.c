/*************************************************************************
	> File Name: E_35.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年04月25日 星期一 18时27分17秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX 1000000

int prime[MAX + 5] = {0};
int is_prime[MAX + 5] = {0};

int is_f(int n) {
	int len = n;
	
	for (int i = 0; i < floor(log10(len) + 1); i++) {
		int tmp_s = n % (int)pow(10, floor(log10(n)));
		int tmp_l = n / (int)pow(10, floor(log10(n)));
		int tmp = tmp_s * 10 + tmp_l;
		
		if (prime[tmp]) {
			return 0;
		}
		if (!prime[tmp]){
			if (floor(log10(len) + 1) != floor(log10(tmp) + 1)) return 0;
			n = tmp;
			continue;
		}

		
	} 
	return 1;
}

int main() {

	for (int i = 2; i <= MAX; i++) {
		// if(!prime[i]) prime[++prime[0]] = i;
		if(!prime[i]) is_prime[++prime[0]] = i;
		// printf("6666\n");
		for (int j = 1; j <= prime[0]; ++j) {
			if (i * is_prime[j] > MAX) break;
			prime[i * is_prime[j]] = 1;
			if (i % is_prime[j] == 0) break;
		}
	}
	
	int count = 0;
	for (int i = 1; i < prime[0]; i++) {
		// printf("%d\n", is_prime[i]);
		if (is_f(is_prime[i])) {
			count++;
		}
	}

	printf("%d\n", count);
	return 0;
}
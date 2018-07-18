/*************************************************************************
	> File Name: 46EP.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年05月06日 星期日 11时31分20秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX 100000
int prime[MAX + 5] = {0};

void init() {
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 2; j <= prime[0]; j++) {
            if (prime[j] * i > MAX) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_ok(int n) {
    int a = 0;
    int i = 1;
    while (prime[i] < n) {
        for (int j = 1; a < n; ++j) {
            a = prime[i] + 2 * j * j;
        }
        if (a == n) return 1;
        a = 0;
        i++;
    }
    return 0;
}

int is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    init();
    for (long i = 9; ; i += 2) {
        if (!is_prime(i)) {
            if (is_ok(i) == 1) continue;
            else { 
                printf("--->%ld\n", i);
                break;
            }
        }
    }
    return 0;
}

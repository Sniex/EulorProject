/*************************************************************************
	> File Name: 23EP.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年05月06日 星期日 19时46分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 28123

int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};
int mnum[MAX_N + 5] = {0};
int arr[MAX_N + 5] = {0};

int main() {
    
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            mnum[i] = i * i - 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                dnum[prime[j] * i] = dnum[i] * (mnum[i] * prime[j] + prime[j] - 1) / mnum[i];
                mnum[prime[j] * i] = mnum[i] * prime[j] + prime[j] - 1;
                break;
            } else { 
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
                mnum[prime[j] * i] = mnum[prime[j]];
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        dnum[i] -= i;
        if (dnum[i] > i) {
            arr[++arr[0]] = i;
        }
    }
    memset(prime, 0, sizeof(prime));
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = 1; i <= arr[0]; j++) {
            if (arr[i] + arr[j] > MAX_N) break;
            prime[arr[i] + arr[j]] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= MAX_N; i++) {
        if (!prime[i]) ans += i;
    }
    printf("%d\n", ans);
/*
    for (int i = 2; i < 10; ++i) {
        printf("prime[%d] = %d ", i, prime[i]);
        printf("dnum[%d] = %d ", i, dnum[i]);
        printf("mnum[%d] = %d\n", i, mnum[i]);
    }
*/
    return 0;
}


/*************************************************************************
	> File Name: 24EP.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年05月02日 星期三 19时37分00秒
 ************************************************************************/

#include<stdio.h>

int get_num(int k, int n, int *num, int delta) {
    int rank = k / delta + 1, now = 0;
    for (int i = 0; i < n; i++) {
        now += !(num[i]);
        if (now == rank) return i;
    }
    return -1;
}

int power(int n) {
    int sum = 1;
    for (int i = 1; i < n; i++) {
        sum *= i;
    }
    return sum;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    k = k - 1;
    int num[10] = {0}, delta = power(n);
    for (int i = 0; i < n; i++) {
        int digit = get_num(k, n, num, delta);
        printf("%d", digit);
        num[digit] = 1;
        k %= delta;
        if (i == n - 1) break;
        delta /= (n - 1 - i); 
    }
    printf("\n");
    return 0;
}

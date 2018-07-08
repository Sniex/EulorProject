/*************************************************************************
	> File Name: E_18_2.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年04月29日 星期日 20时12分34秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 100

int map[MAX_N][MAX_N] = {0};
int f[MAX_N][MAX_N] = {0};
int keep[MAX_N][MAX_N] = {0};

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", map[i] + j);
        }
    }
    f[0][0] = map[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = 0;
            if (j <= i - 1 && f[i - 1][j] > f[i][j]) {
                f[i][j] = f[i - 1][j];
                keep[i][j] = j;
            }
            if (j > 0 && f[i - 1][j - 1] > f[i][j]) {
                f[i][j] = f[i - 1][j - 1];
                keep[i][j] = j - 1;
            }
            f[i][j] += map[i][j];
        }
    }
    int ans = 0, ansj;
    for (int i = 0; i < n; i++) {
        if (f[n - 1][i] > ans) ans = f[n - 1][i], ansj = i;
    }
    printf("%d\n", ans);

    for (int i = n - 1; i >= 0; i--) {
        printf("(%d,%d)\n", i, ansj);
        ansj = keep[i][ansj];
    }

    /*
    for (int i = 0; i < n; i++) {
        f[n - 1][i] = map[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            f[i][j] = map[i][j];
            if (f[i + 1][j] > f[i + 1][j + 1]) {
                f[i][j] += f[i + 1][j];
            } else {
                f[i][j] += f[i + 1][j + 1];
            }
        }
    }
    printf("%d\n", f[0][0]);
    */
    
    return 0;
}

/*************************************************************************
	> File Name: 29EP.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年05月06日 星期日 09时58分37秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

struct Tuple {
    int p, a;
};

struct Tuple M[10000][4] = {0};
int M_num = 0;

int prime[105] = {0};

void get_M(int a, int b, struct Tuple *M) {
    int m_len = 0;
    while (a != 1) {
        int p_num = 0, pre = prime[a];
        while (a % pre == 0) {
            a /= pre;
            p_num++;
        }
        M[m_len].p = pre;
        M[m_len].a = p_num * b;
        m_len++;
    }
    return ;
}

int main() {
    for (int i = 2; i <= 100; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= 100; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
    for (int a= 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            struct Tuple tmp_M[4] = {0};
            get_M(a, b, tmp_M);
            int flag = 1;
            for (int i = 0; i < M_num && flag; i++) {
                flag = memcmp(M[i], tmp_M, sizeof(tmp_M));
            }
            if (flag) {
                memcpy(M[M_num++], tmp_M, sizeof(tmp_M));
            } 
        }
    }
    printf("%d\n", M_num);
    
    return 0;
}

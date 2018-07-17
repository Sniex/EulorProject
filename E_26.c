/*************************************************************************
	> File Name: 26EP.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年05月06日 星期日 09时19分22秒
 ************************************************************************/

#include<stdio.h>

int get_circle_length2(int d) {
    int first_index[1000] = {0};
    int y = 1, index = 1;
    do {
        first_index[y] = (index++);
        y = y * 10 % d;
    }while (y && first_index[y] == 0);
    if (y == 0) return 0;
    return index - first_index[y]; 
}

static inline int get_next(int n, int d) {
    return (n * 10) % d;
}

int get_circle_length(int d) {
    int ar = 1, br = 1;
    do {
        ar = get_next(ar, d);
        br = get_next(br, d);
        br = get_next(br, d);
    } while (br != 0 && ar != br);
    if (br == 0) return 0;
    int len = 0;
    do {
        br = get_next(br, d);
        len++;
    } while (ar != br);
    return len;
}

int main() {
    int max_length = 0, ans_num;
    for (int i = 2; i < 999; i++) {
        int tmp = get_circle_length(i);
        if ( tmp > max_length ) {
            ans_num = i;
            max_length = tmp;
        }
    }
    printf("%d  %d\n", ans_num, max_length);    
    return 0;
}


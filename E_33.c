/*************************************************************************
	> File Name: E_33.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年04月25日 星期一 13时51分17秒
 ************************************************************************/

#include<stdio.h>

struct Node {
	int x;
	int y;
	float res;
};

float divide(int x, int y) {
	return (x * 1.0) / y;
}

int is_result(int x, int y) {
	int list_x[2] = {x % 10, x / 10};
	int list_y[2] = {y % 10, y / 10};
	// printf("%d / %d = %d / %d\n", x, y, list_x[0], list_y[0]);
	if (list_x[0] == list_y[0] && list_x[0] != 0 && divide(x, y) == divide(list_x[1], list_y[1]) ) {
		printf("%d / %d = %d / %d\n", x, y, list_x[1], list_y[1]);
		return 1;
	}
	else if (list_x[0] == list_y[1] && list_x[0] != 0 && divide(x, y) == divide(list_x[1], list_y[0])) {
		printf("%d / %d = %d / %d\n", x, y, list_x[1], list_y[0]);
		return 1;
	}
	else if (list_x[1] == list_y[0] && list_x[0] != 0 && divide(x, y) == divide(list_x[0], list_y[1])){
		printf("%d / %d = %d / %d\n", x, y, list_x[0], list_y[1]);
		return 1;
	}
	else if (list_x[1] == list_y[1] && list_x[0] != 0 && divide(x, y) == divide(list_x[0], list_y[0])){

		printf("%d / %d = %d / %d\n", x, y, list_x[0], list_y[0]);
		return 1;
	}
	else return 0;
}

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    else return gcd(y, x % y);
}

int main(int argc, char const *argv[])
{
	struct Node result[5];
	int k = 0;
	for (int i = 11; i < 99; i++) {
		for (int j = i + 1; j < 99; j++) {
			if (is_result(i, j) && (i * 1.0) / j < 1 ) {
				result[k].x = i;
				result[k].y = j;
				result[k++].res = (i * 1.0) / j;
			}
		}
	}
	int res_x = 1;
	int res_y = 1;
	for (int i = 0; i < k; i++) {
		res_x *= result[i].x;
		res_y *= result[i].y;
	}
	if (gcd(res_y, res_x)  != 1) {
		printf("%d\n", res_y / gcd(res_y, res_x));	
	} else {
		printf("%d\n", res_y);
	}
	return 0;
}

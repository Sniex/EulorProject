/*************************************************************************
	> File Name: 22EP.c
	> Author: Yu_dong
	> Mail: 1124250973@qq.com
	> Created Time: 2018年05月05日 星期六 21时37分09秒
 ************************************************************************/

#include<stdio.h>


int main() {
    char name[6000][50] = {0};
    FILE *fp = fopen("./name.txt", "r");
    int i = 0;
    int length = 0;
    while (!feof(fp)) {
        fgets(name[i], 50, fp);
        // printf("%d    %s", i, name[i]);
        i++;
        length++;
    }
    i = 0;
    long sum, res = 0;
    while ( i < length ) {
        sum = 0;
        for (int j = 0; name[i][j] != '\0'; j++) {
            sum += name[i][j] - 'A' + 1;
        }
        i++;
        res = res + sum * i;
        printf("%ld\n", res);
    }
    printf("%ld\n", res);
    
    
    
    return 0;
}

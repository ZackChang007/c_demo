# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int main() {
    // // 数组
    // // int arr[5] = {1, 2, 3, 4, 5};
    // int a[5] = {0};
    // a[0] = 1;  //0x1000
    // a[1] = 2;  //0x1004, array的元素在内存中的地址是连续的，即下一个元素地址是上一个+1，右移4位bytes
    // a[2] = 3;  //0x1008
    // a[3] = 4;  //0x100c
    // a[4] = 5;  //0x1010

    // for (int i = 0; i < 5; i++) {
    //     printf("a[%d] = %d\n", i, a[i]);
    // }

    // 二维数组
    int b[3][3] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
        };
    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < 3; j++) {
            printf("\t%d", b[i][j]);  // \t是制表符，表示4个空格
            }
        }
        printf("\n");

    return 0;
}
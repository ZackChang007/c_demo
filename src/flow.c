# include <stdio.h>
# include <stdlib.h>

int main() {
    int x = 2;
    if (x > 0) {
      printf("x is positive\n");
    }
    else if (x == 0) {
      printf("x is zero\n");
    } 
    else {
      printf("x is not positive\n");
    }

    // 三元运算符 condition ? expression1 : expression2; 相当于简化版if else
    int y = 2;
    y % 2 == 1 ? printf("y是奇数\n"): printf("y是偶数\n"); 

    // switch语句, 用于多个分支的条件判断
    int z = 4;
    switch (z) {
        case 1:
            printf("z is 1\n");
            break;
        case 2:
            printf("z is 2\n");
            break;
        case 3:
            printf("z is 3\n");
            break;
        default:
            printf("z is not 1, 2 or 3\n");
            break;
    }
    return 0;
}
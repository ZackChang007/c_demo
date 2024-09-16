# include <stdio.h>
# include <stdlib.h>

int main() {
    char c = 'A';
    printf("c is %c \n", c);
    printf("c is %d \n", c);
    int i = 65;
    printf("i is %c \n", i);
    long int l = 65;
    long long int ll = 65;
    printf("l is %ld \n", l);
    printf("ll is %lld \n", ll);
    float f = 3.1415926535;
    double d = 3.1415926535;
    printf("f is %.10f \n", f);  // 对于很长小数位数的单精度float数据，会发生精度丢失
    printf("d is %.10f \n", d);  //双精度浮点数精度更高
    return 0;
}

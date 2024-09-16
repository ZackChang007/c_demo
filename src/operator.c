# include <stdio.h>
# include <stdlib.h>

int main() {
    // float a = 10;
    // int b = 20;
    // printf("a + b = %f\n", a + b);
    // printf("a - b = %f\n", a - b);
    // printf("a * b = %f\n", a * b);
    // printf("a / b = %f\n", a / b);

    int x = 10;
    printf("x++ = %d\n", x++);
    printf("++x = %d\n", ++x);
    printf("x-- = %d\n", x--);
    printf("--x = %d\n", --x);

    int a = 5;
    int b = 6;
    printf("a & b = %d\n", a & b);
    printf("a | b = %d\n", a | b);
    printf("a ^ b = %d\n", a ^ b);
    
    int c = 5;
    printf("c << 1 = %d\n", c << 1);  //int 5的二进制是101，左移一位后是1010，十进制是10，即2*5
    printf("c >> 1 = %d\n", c >> 1);  //int 5的二进制是101，右移一位后是10，十进制是2，即5/2

    return 0;
}
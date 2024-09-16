# include <stdio.h>
# include <stdlib.h>

int main() {
    // int i = 0;
    // while (i < 10) {
    //     printf("i = %d\n", i);
    //     i++;
    // }   

    // int a = 10;
    // do {                         // do while循环，不论while(condition)是否成立，do{}都会至少执行一次
    //     printf("a = %d\n", a);
    //     a++;
    //     } while (a < 10);
    
    int i = 0;
    for (; i < 10; i++) {
        if (i == 5) {
            continue;
        }
        printf("i = %d\n", i);
    }

    return 0;
}
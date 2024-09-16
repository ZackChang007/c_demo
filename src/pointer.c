# include <stdio.h>
# include <stdlib.h>

int main() {
    // 指针
    int *p;  // 变量名前面有*表示该变量是一个指针
    int a = 10;  // 变量a的地址, 指针变量p的类型int需要和指针指向的变量a的类型一致
    p = &a;  // 指针p指向变量a的地址, 地址的表示方法为在变量名前面加上&符号
    printf("Address of a: %p\n", &a);
    printf("Value of a: %d\n", a);
    printf("Address stored in p: %p\n", p);
    printf("\n");

    //指针变量p前面加*表示取指针指向的地址的值，这里的*是解引用运算符，和初始化指针变量时`int *p = &a;`的*不同
    printf("Value stored in p: %d\n", *p);  
    *p = 20;
    printf("New value of a: %d\n", a);
    printf("New value stored in p: %d\n", *p);
    printf("\n");

    // 二级指针
    int **pp;  // 指针变量pp指向指针变量, 变量初始化时的**表示变量是二级指针
    int b = 30;  // 变量b的地址
    pp = &p;  // 指针pp指向指针变量p的地址
    printf("Address of b: %p\n", &b);
    printf("Address stored in pp: %p\n", pp);
    printf("Address stored in p: %p\n", *pp);  // 解引用指针pp指向的指针变量p
    
    // 对二级指针pp进行两次解引用，得到指针变量p指向的变量a的值
    printf("Value stored in p: %d\n", **pp);  // 解引用指针pp指向的指针变量p指向的变量a的值
    printf("\n");

    // 指针数组
    int arr[3] = {1, 2, 3};  // 数组arr的地址
    int *ptr = arr;  // 指针ptr指向数组arr的地址
    printf("Address of arr: %p\n", arr);
    printf("Address stored in ptr: %p\n", ptr);
    printf("Value of arr[0]: %d\n", arr[0]);
    printf("Value of *(ptr+1): %d\n", *(ptr+1));  // 指针ptr指向数组arr的地址，加1表示下一个元素的地址，再解引用指针ptr指向的地址的值
    printf("\n");

    // 指针函数
    int add(int a, int b); {
        return a + b;
    }
    int (*pfun)(int, int);  // 指针变量pfun指向函数add的地址
    pfun = add;  // 指针变量pfun指向函数add的地址
    printf("Address of add: %p\n", add);
    printf("Address stored in pfun: %p\n", pfun);
    printf("Result of add(10, 20): %d\n", pfun(10, 20));  // 调用函数add
    
    return 0;
}
# Makefile
* [20分钟Makefile光速入门教程](https://www.bilibili.com/video/BV1tyWWeeEpp/?spm_id_from=333.999.0.0)
## C语言基础
* 在 C 语言中，包含头文件有两种方式：
  + 使用尖括号 `#include <file.h>`，这告诉编译器在标准库路径中查找文件。
  + 使用双引号 `#include "file.h"`，这告诉编译器首先在当前目录中查找文件，如果找不到，再在标准库路径中查找。
    - 如果你的 message.h 文件在当前目录中，确保使用双引号：`#include "message.h"`
* 封装本地打印函数message：
  + 创建本地.h文件：[message.h](./message.h)
    - **函数声明**：message() 是一个函数的声明，它告诉编译器这个函数的存在，但不提供函数的具体实现。函数的具体实现通常在另一个源文件[message.c](./message.c)中定义。
      - 在C语言中，函数声明告诉编译器函数的名称、返回类型和参数类型（如果有）。这允许编译器在编译时检查函数调用的正确性，即使函数的实现在另一个文件中。
    - **返回类型**：void 表示这个函数不返回任何值。
    - **函数名**：message 是这个函数的名称。  
## linux bash
* `ls -ltr`
  + -l：长格式（long format）列出文件和目录的详细信息，包括文件权限、所有者、大小、最后修改时间等。
  + -t：根据文件的修改时间排序，最新的文件或目录会显示在最前面。
  + -r：逆序（reverse）排序，与 -t 选项结合使用时，会将文件按照从旧到新的顺序显示。 
* `rm -rf file`
  - rm 是 "remove" 的缩写，用于删除文件或目录。
  - -r 是递归(recursive)删除的标志，用于删除目录及其包含的所有子目录和文件。
  - -f 是强制删除的标志，用于不提示确认直接删除文件或目录。 
## gcc make
* `gcc main.c -o hello`
  * `-o`, output, 直接编译生成目标文件
* `gcc main.c -c main.o`
  * `-c`, connection, 编译生成`.o文件`, 后面再链接为目标文件
* gcc执行`make`命令时，如果目标文件`hello`已经存在，则gcc会检查目标文件和依赖文件`main.c`,`message.c`的时间戳，如果依赖文件的时间戳比目标文件的时间戳新，说明依赖文件有更新，gcc会重新编译为目标文件，否则不会重新编译
* 规范的做法是把编译和链接分开来写，即：
  * 先把`main.c`和`message.c`分别编译成`main.o`和`message.o`
  * 然后把`main.o`和`message.o`链接成目标文件`hello`
  * 参见：[makefile](./makefile)
### makefile文件
* 格式参见：[makefile](./makefile)
  - 文件名首字母大小写皆可
  - 文件不能有拓展名
  - **缩进必须用Tab**
* 内容构成：
```makefile
target: dependencies
    action  
``` 
* 执行编译：`make`
* 除了可以生成可执行的目标文件`hello`，也可以单独编译中间文件`*.o`, 只要它是makefile中定义过的target，例如：`make message.o`
#### 伪目标
* 不生成目标文件，只是一个标签target，用于执行一些操作
* `make clean`
  * 在makefile的编译指令后面加入以下两行：
  * 并执行`make clean`，**则gcc会在编译后删除生成的过程文件`.o`文件和目标文件`hello`**
  * **如果同一目录下有名为`clean`的文件，则gcc的`make clean`命令会失效，因为make会把clean当作本地文件名来处理**
    * 解决办法是在makefile加一行`.PHONY: clean`, 显式告诉make `clean`是一个伪目标，如此则`make clean`仍能正常工作
```makefile
clean:
    rm -f *.o hello
```
* `make all`
  * 用于make生成的目标文件不止一个的情况
  * **把伪目标`all`放在makefile的第一行，默认生成全部目标文件, 编译时只需要`make`, 而不必`make all`**
  * **makefile添加伪目标`all`后，如果只想生成单独文件而不是全部生成，可以执行`make hello`只生成目标文件`hello`**
  * 执行`make all`
```makefile
# 把all显式指定为伪目标
.PHONY: clean all

# target为all，dependencies为两个生成文件hello和world
# action为打印"all done"
all: hello world
    echo "all done"

# world生成文件相比hello，只是生成的名字不同
world: main.o message.o
    gcc main.o message.o -o world
```
* 如果目标文件`hello`,`world`的内容完全一样，只是生成的目标文件名不同，可以简写为以下：
  * 第二行的`$@`是一个自动变量，代表目标文件的名称。在这个上下文中，它将是 hello 或 world，取决于当前正在构建的目标。
```makefile
hello world: main.o message.o
    gcc main.o message.o -o $@
```
#### 定义变量
* 参见: [makefile](./makefile)中定义的相关变量及使用：
  * `$(targets)`, `$(objects)`, `$(CFLAGS)`
  * 其中，`CFLAGS = -Wall -g -O2`：
    * `-Wall`：告诉编译器显示所有警告信息。
    * `-g`：生成调试信息，这对于调试程序非常有用。
    * `-O2`：优化代码，提高程序的运行效率。
#### 字符含义
* `$@`, 表示目标文件
* `$<`, 表示第一个依赖文件(dependecies)
* `$^`, 表示所有依赖文件
* 示例：
```makefile
# main.o: main.c
#   gcc $(CFLAGS) -c main.c

main.o: main.c
    gcc $(CFLAGS) -c $< -o $@

# message.o: message.c
#   gcc $(CFLAGS) -c message.c

message.o: message.c
    gcc $(CFLAGS) -c $< -o $@
```
#### 通配符
* 示例：做完以下修改后，先后运行：`make clean`, `make`
```makefile
# 以下两个编译命令都是.c文件生成.o文件，只是文件名不同
# 用%把编译指令进行泛化
main.o: main.c
    gcc $(CFLAGS) -c $< -o $@

message.o: message.c
    gcc $(CFLAGS) -c $< -o $@

# 注释掉上面的指令后，新增修改为
%.o: %.c
    gcc $(CFLAGS) -c $< -o $@
```
## CMake
* 创建: [CMakeLists.txt](./CMakeLists.txt)
```bash
mkdir build
cd ./build
# `cmake ..`会在build文件夹生成Makefile
cmake ..
# 编译
make
# 测试目标可执行文件是否正常
./hello
# 删除目标文件hello
make clean
```

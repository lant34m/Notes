# 复习C

# C程序结构

一个C程序

![image-20220219175723172](C:/Users/LanT34m/AppData/Roaming/Typora/typora-user-images/image-20220219175723172.png)

```c
#include <stdio.h>

int main()
{
   /* 我的第一个 C 程序 */
   printf("Hello, World! \n");

   return 0;
}
```

1. 头文件

2. 函数(main函数)

   - 花括号
   - 函数体
   - 返回值

3. 注释

   ```c
   /* 单行注释 */
   /* 
    多行注释
    多行注释
    多行注释
    */
   ```

4. 声明(定义)

   - type variable_list;

     ```c
     int    i, j, k;
     char   c, ch;
     float  f, salary;
     double d;
     ```

   - 字母、数字和下划线

   - 初始化 int a = 0;

     ```c
     int d = 3, f = 5;    // d 和 f 的声明与初始化
     int d = 3, f = 5;           // 定义并初始化 d 和 f
     byte z = 22;                // 定义并初始化 z
     char x = 'x';               // 变量 x 的值为 'x'
     ```

     

# 数据类型

### 整型

|      类型      |  存储大小   |                        值范围                        |
| :------------: | :---------: | :--------------------------------------------------: |
|      char      |   1 字节    |               -128 到 127 或 0 到 255                |
| unsigned char  |   1 字节    |                       0 到 255                       |
|  signed char   |   1 字节    |                     -128 到 127                      |
|      int       | 2 或 4 字节 | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647 |
|  unsigned int  | 2 或 4 字节 |          0 到 65,535 或 0 到 4,294,967,295           |
|     short      |   2 字节    |                  -32,768 到 32,767                   |
| unsigned short |   2 字节    |                     0 到 65,535                      |
|      long      |   4 字节    |           -2,147,483,648 到 2,147,483,647            |
| unsigned long  |   4 字节    |                  0 到 4,294,967,295                  |

### 浮点

|    类型     | 存储大小 |         值范围         |   精度    |
| :---------: | :------: | :--------------------: | :-------: |
|    float    |  4 字节  |   1.2E-38 到 3.4E+38   | 6 位小数  |
|   double    |  8 字节  |  2.3E-308 到 1.7E+308  | 15 位小数 |
| long double | 16 字节  | 3.4E-4932 到 1.1E+4932 | 19 位小数 |



 ## 常用

- int 整型，整数
- char 字符型
- float 单精度浮点
- double 双精度浮点
- unsigned 无符号

|  类型  |                             描述                             |
| :----: | :----------------------------------------------------------: |
|  char  |          通常是一个字节（八位）。这是一个整数类型。          |
|  int   |               对机器而言，整数的最自然的大小。               |
| float  | 单精度浮点值。单精度是这样的格式，1位符号，8位指数，23位小数。![图片说明](https://uploadfiles.nowcoder.com/images/20190921/334190970_1569032449395_DFFAFA273002E825B428C0E6453C6B6E) |
| double | 双精度浮点值。双精度是1位符号，11位指数，52位小数。![图片说明](https://uploadfiles.nowcoder.com/images/20190921/334190970_1569032462308_6466136D1077A4900F42C47E312D4188) |
|  void  |                       表示类型的缺失。                       |

## 转换

### 自动转换

```c
float a = 100.5; 
int b = a;//自动转换成int,存在精读损失
1 + 1.1 //数据位长度小的类型自动转换成长度大的类型
```

![image-20220219183107305](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219183107305.png)

### 强制转换

```c
//(类型名) 表达式
(float) a;
(int) (c+d);
(float) 5;
```

## 常量

```c
#define identifier value
#define X 10

const type variable = value;
const int  LENGTH = 10;
```

常量通常定义为大写形式

# 运算符

- 算术运算符
  假设变量 **A** 的值为 10，变量 **B** 的值为 20
  取余必须是左右整型

  ```c
  x++//先用x做运算再++
  ++x//先++再运算
  ```

  ![image-20220219183813918](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219183813918.png)

- 关系运算符
  ![image-20220219190658585](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219190658585.png)

- 逻辑运算符
  ![image-20220219190710602](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219190710602.png)

- 位运算符

- 赋值运算符
  ![image-20220219190750618](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219190750618.png)

- 杂项运算符
  ![image-20220219191325527](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219191325527.png)

  ```c
  Exp1 ? Exp2 : Exp3;
  
  #include<stdio.h>
  
  int main()
  {
      int num;
  
      printf("输入一个数字 : ");
      scanf("%d",&num);
  
      (num%2==0)?printf("偶数"):printf("奇数");
  }
  ```

# 输入输出

## 输入

![image-20220219192528136](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219192528136.png)

```c
#include <stdio.h>
int scanf( const char *format, ... );
```

![image-20220219192620425](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219192620425.png)

```c
//格式化输出整数
#include <stdio.h>
int main()
{
    int testInteger = 5;
    printf("Number = %d", testInteger);
    return 0;
}
```

```c
//格式化输出浮点型数据
#include <stdio.h>
int main()
{
    float f;
    printf("Enter a number: ");
    // %f 匹配浮点型数据
    scanf("%f",&f);
    printf("Value = %f", f);
    return 0;
}
```

### 注意

```c
#include <stdio.h>

int main()
{
    int i;
    char c;
    scanf("%d", &i);
    printf("i=%d\n", i);
    scanf("%c", &c);
    printf("c=%c", c);
    
}
```

![image-20220219192952270](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219192952270.png)

> 第二个 scanf函数读取了缓冲区中的“`\n`”,即 scanf("%c",&c)实现了读取，打印输出了换行
>
> 我们向标准输入缓冲区中放入的字符为10\n’，输入"\n"（回车）后，scanf函数才开始匹配， scanf函数中的%d匹配整型数10，然后放入变量i中，接着进行打印输出，这时'\n'仍然在标准输入缓冲区（ stdin）内，如果第二个 scanf函数为 scanf（"%d"，&i），那么依然会发生阻塞，因为 scanf函数在读取整型数、浮点数、字符串（后面介绍数组时讲解字符串）时，会忽略"\n’（回车符）、空格符等字符（忽略是指 scanf函数执行时会首先删除这些字符，然后再阻塞）. scanf函数匹配一个字符时，会在缓冲区删除对应的字符。因为在执行 scanf（"%c"，&c)语句时，不会忽略任何字符，所以 scanf（"%c"，&c）读取了还在缓冲区中残留的"\n"

### 循环读取

```c
#include <stdio.h>

int main()
{
    int i;
    while(scanf("%d", &i) != EOF)
    {
        printf("i=%d\n", i);
    }

}
```

> 如果我们输错了，输入的为字符型数据，那么 scanf函数就无法匹配成功， scanf函数未匹配成功时其返回值为0，即ret的值为0，但这并不等于EOF，因为EOF的返回值为-1.当scanf函数无法匹配成功时，程序仍然会进入循环，这时会导致不断地重复打印。

更改为

```c
#include <stdio.h>

int main()
{
    int i,ret;
    while(rewind(stdin),(ret=scanf("%d", &i)) != EOF)
    {
        printf("i=%d\n", i);
    }

}
```

使用rewind(stdin)清空缓冲区

**scanf () 混合输入,读取多种类型的数据，混合输入时每次在%c之前需要加入一个空格**

### putchar和getchar

一个单一的字符

```c
#include <stdio.h>

int main( )
{
   int c;

   printf( "Enter a value :");
   c = getchar( );

   printf( "\nYou entered: ");
   putchar( c );
   printf( "\n");
   return 0;
}
```

### gets和puts

一整行直到该行结束

```c
#include <stdio.h>

int main( )
{
   char str[100];

   printf( "Enter a value :");
   gets( str );

   printf( "\nYou entered: ");
   puts( str );
   return 0;
}
```



## 输出

printf () 函数可以输出各种类型 的数据，包括整型、浮点型、字符型、字符串型等，实际原理是 printf () 函数将这些类型的数据格式化为字符串后，放入标准输出缓冲区，然后通过\n'来刷新标准输出，并将结果显示到屏幕上

- 用`%f` 精度修饰符指定想要的小数位数。例如，`%5.2f`会至少显示5位数字并带有2位小数的浮点数

# 语句

## 分支语句

> 判断结构要求程序员指定一个或多个要评估或测试的条件，以及条件为真时要执行的语句（必需的）和条件为假时要执行的语句（可选的）。
>
> C 语言把任何**非零**和**非空**的值假定为 **true**，把**零**或 **null** 假定为 **false**。

![image-20220219191740844](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219191740844.png)

## 循环

![image-20220219191936361](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219191936361.png)

### 循环控制

![image-20220219192006613](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219192006613.png)

### 无线循环

```c
#include <stdio.h>

int main ()
{
   for( ; ; )
   {
      printf("该循环会永远执行下去！\n");
   }
    
    while(1)
    {
        printf("该循环会永远执行下去！\n");
    }
   return 0;
}
```


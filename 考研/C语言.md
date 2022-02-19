# 复习C

# C程序结构

一个C程序

![image-20220219211849059](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219211849059.png)

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
   包含头文件和预处理器

   - 头文件是扩展名为 **.h** 的文件，包含了 C 函数声明和宏定义，使用#include包含

     ```c
     #include <file> //用于引用系统头文件
     #include "file" //用于引用用户头文件
     ```

   - 常用的预处理器

     ```c
     #define //定义宏
     #define MAX_ARRAY_LENGTH 20 //可以用来定义定量
     #include //包含头文件
     ```

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

![图片说明](https://raw.githubusercontent.com/lant34m/pic/main/img/334190970_1569033453348_F7A6CB412ED7F2C38470A57736E51569)

### 强制转换

```c
//(类型名) 表达式
(float) a;
(int) (c+d);
(float) 5;
```

```c
#include <stdio.h>

int main()
{
   int sum = 17, count = 5;
   double mean;

   mean = (double) sum / count;
   printf("Value of mean : %f\n", mean );

}
```

## 常量

```c
#define identifier value
#define X 10

const type variable = value;
const int  LENGTH = 10;
```

常量通常定义为大写形式

## 静态变量

![image-20220219210447636](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219210447636.png)

```c
static int a = 0;
//上图将a定义为函数f静态变量，a并不会随着函数f的结束而销毁
```

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

或

```c
while((ch=getchar())!=EOF && ch!='\n') ;
```

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

### if

```c
if(boolean_expression)
{
   /* 如果布尔表达式为真将执行的语句 */
}

#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 10;

   /* 使用 if 语句检查布尔条件 */
   if( a < 20 )
   {
       /* 如果条件为真，则输出下面的语句 */
       printf("a 小于 20\n" );
   }
   printf("a 的值是 %d\n", a);

   return 0;
}
```

### if else

``` c
if(boolean_expression)
{
   /* 如果布尔表达式为真将执行的语句 */
}
else
{
   /* 如果布尔表达式为假将执行的语句 */
}

#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 100;

   /* 检查布尔条件 */
   if( a < 20 )
   {
       /* 如果条件为真，则输出下面的语句 */
       printf("a 小于 20\n" );
   }
   else
   {
       /* 如果条件为假，则输出下面的语句 */
       printf("a 大于 20\n" );
   }
   printf("a 的值是 %d\n", a);

   return 0;
}


```

```c
if(boolean_expression 1)
{
   /* 当布尔表达式 1 为真时执行 */
}
else if( boolean_expression 2)
{
   /* 当布尔表达式 2 为真时执行 */
}
else if( boolean_expression 3)
{
   /* 当布尔表达式 3 为真时执行 */
}
else 
{
   /* 当上面条件都不为真时执行 */
}

#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 100;

   /* 检查布尔条件 */
   if( a == 10 )
   {
       /* 如果 if 条件为真，则输出下面的语句 */
       printf("a 的值是 10\n" );
   }
   else if( a == 20 )
   {
       /* 如果 else if 条件为真，则输出下面的语句 */
       printf("a 的值是 20\n" );
   }
   else if( a == 30 )
   {
       /* 如果 else if 条件为真，则输出下面的语句 */
       printf("a 的值是 30\n" );
   }
   else
   {
       /* 如果上面条件都不为真，则输出下面的语句 */
       printf("没有匹配的值\n" );
   }
   printf("a 的准确值是 %d\n", a );

   return 0;
}
```

### 嵌套if

```c
if( boolean_expression 1)
{
   /* 当布尔表达式 1 为真时执行 */
   if(boolean_expression 2)
   {
      /* 当布尔表达式 2 为真时执行 */
   }
}

#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 100;
   int b = 200;

   /* 检查布尔条件 */
   if( a == 100 )
   {
       /* 如果条件为真，则检查下面的条件 */
       if( b == 200 )
       {
          /* 如果条件为真，则输出下面的语句 */
          printf("a 的值是 100，且 b 的值是 200\n" );
       }
   }
   printf("a 的准确值是 %d\n", a );
   printf("b 的准确值是 %d\n", b );

   return 0;
}
```

### switch

```c
switch(expression){ //expression必须是整型或枚举
    case constant-expression  : 
//constant-expression 必须是expression可能存在的值，且必须具有相同数据类型
       statement(s);
       break; /* 可选的 */ //若没有break则会一直往下执行直至break
    case constant-expression  :
       statement(s);
       break; /* 可选的 */

    /* 您可以有任意数量的 case 语句 */
    default : /* 可选的 */ //为前方都不为真时执行
       statement(s);
}

#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   char grade = 'B';

   switch(grade)
   {
   case 'A' :
      printf("很棒！\n" );
      break;
   case 'B' :
   case 'C' :
      printf("做得好\n" );
      break;
   case 'D' :
      printf("您通过了\n" );
      break;
   case 'F' :
      printf("最好再试一下\n" );
      break;
   default :
      printf("无效的成绩\n" );
   }
   printf("您的成绩是 %c\n", grade );

   return 0;
}
```

### 嵌套switch

```c
switch(ch1) {
   case 'A': 
      printf("这个 A 是外部 switch 的一部分" );
      switch(ch2) {
         case 'A':
            printf("这个 A 是内部 switch 的一部分" );
            break;
         case 'B': /* 内部 B case 代码 */
      }
      break;
   case 'B': /* 外部 B case 代码 */
}
```

## 循环

![image-20220219191936361](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219191936361.png)

### while

```c
while(condition)
{
   statement(s);
}

#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 10;

   /* while 循环执行 */
   while( a < 20 )
   {
      printf("a 的值： %d\n", a);
      a++;
   }

   return 0;
}
```

> while 语句中出现死循环的原因
>
> - 1、 `while（）`后面加了分号
> - 2、 while语句体内没有让表达式趋近于假的操作

### for

```c
for ( init; condition; increment )
{
   statement(s);
}

#include <stdio.h>

int main ()
{
   /* for 循环执行 */
   for( int a = 10; a < 20; a = a + 1 )
   {
      printf("a 的值： %d\n", a);
   }

   return 0;
}
```

> for（表达式1；表达式2；表达式3）语句；
> for循环语句的执行过程如下
> （1）先求解表达式1。
> （2）求解表达式2，若其值为真（值为非0），则先执行for语句中指定的内嵌语句，后执行
> 第（3）步。若其值为假（值为0），则结束循环，转到第（5）步。
> （3）求解表达式3.4
> （4）转回第（2）步继续执行。
> （5）循环结束，执行for语句下面的语句

### do while

do while确保运行一次

```c
do
{
   statement(s);

} while( condition );

#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 10;

   /* do 循环执行 */
   do
   {
       printf("a 的值： %d\n", a);
       a = a + 1;
   }while( a < 20 );

   return 0;
}
```

### 嵌套循环



### 循环控制

![image-20220219192006613](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219192006613.png)

continue **跳出本轮循环**，即为从代码后面的语句不会执行

break是结束整个循环

### break

```c
#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 10;

   /* while 循环执行 */
   while( a < 20 )
   {
      printf("a 的值： %d\n", a);
      a++;
      if( a > 15)
      {
         /* 使用 break 语句终止循环 */
          break;
      }
   }

   return 0;
}
```

### continue

```c
#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 10;

   /* do 循环执行 */
   do
   {
      if( a == 15)
      {
         /* 跳过迭代 */
         a = a + 1;
         continue;
      }
      printf("a 的值： %d\n", a);
      a++;

   }while( a < 20 );

   return 0;
}
```

### （不常用）goto

```c
#include <stdio.h>

int main ()
{
   /* 局部变量定义 */
   int a = 10;

   /* do 循环执行 */
   LOOP:do
   {
      if( a == 15)
      {
         /* 跳过迭代 */
         a = a + 1;
         goto LOOP;
      }
      printf("a 的值： %d\n", a);
      a++;

   }while( a < 20 );

   return 0;
}
```

### 无限循环

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

# 函数

函数是一组一起执行一个任务的语句

```c
return_type function_name( parameter list )
{
   body of the function
}
```

```c
#include <stdio.h>

/* 函数声明 */
int max(int num1, int num2);

int main ()
{
   /* 局部变量定义 */
   int a = 100;
   int b = 200;
   int ret;

   /* 调用函数来获取最大值 */
   ret = max(a, b);

   printf( "Max value is : %d\n", ret );

   return 0;
}

/* 函数返回两个数中较大的那个数 */
int max(int num1, int num2) 
{
   /* 局部变量声明 */
   int result;

   if (num1 > num2)
      result = num1;
   else
      result = num2;

   return result; 
}
```

## 传值

传值 void swap(int x, int y) 不改变真正转入的值

```c
#include <stdio.h>

/* 函数声明 */
void swap(int x, int y)
{
   int temp;

   temp = x; /* 保存 x 的值 */
   x = y;    /* 把 y 赋值给 x */
   y = temp; /* 把 temp 赋值给 y */

   return;
}

int main ()
{
   /* 局部变量定义 */
   int a = 100;
   int b = 200;

   printf("交换前，a 的值： %d\n", a );
   printf("交换前，b 的值： %d\n", b );

   /* 调用函数来交换值 */
   swap(a, b);

   printf("交换后，a 的值： %d\n", a );
   printf("交换后，b 的值： %d\n", b );

   return 0;
}
```

## 引用

可以使用void swap(int &x, int &y)

```c
#include <stdio.h>

/* 函数声明 */
void swap(int *x, int *y);

int main ()
{
   /* 局部变量定义 */
   int a = 100;
   int b = 200;

   printf("交换前，a 的值： %d\n", a );
   printf("交换前，b 的值： %d\n", b );

   /* 调用函数来交换值
    * &a 表示指向 a 的指针，即变量 a 的地址 
    * &b 表示指向 b 的指针，即变量 b 的地址 
   */
   swap(&a, &b);

   printf("交换后，a 的值： %d\n", a );
   printf("交换后，b 的值： %d\n", b );

   return 0;
}
```

# 作用域

1. 在函数或块内部的**局部**变量
2. 在所有函数外部的**全局**变量
3. 在**形式**参数的函数参数定义中

## 局部

 ![image-20220219205110525](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219205110525.png)

![image-20220219205121577](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219205121577.png)

![image-20220219205140901](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219205140901.png)

```c
#include <stdio.h>

int main ()
{
  /* 局部变量声明 */
  int a, b;
  int c;

  /* 实际初始化 */
  a = 10;
  b = 20;
  c = a + b;

  printf ("value of a = %d, b = %d and c = %d\n", a, b, c);

  return 0;
}
```

## 全局

![image-20220219205156485](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219205156485.png)

![image-20220219205214741](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220219205214741.png)

```c
#include <stdio.h>

/* 全局变量声明 */
int g;

int main ()
{
  /* 局部变量声明 */
  int a, b;

  /* 实际初始化 */
  a = 10;
  b = 20;
  g = a + b;

  printf ("value of a = %d, b = %d and g = %d\n", a, b, g);

  return 0;
}
```

```c
#include <stdio.h>

/* 全局变量声明 */
int g = 20;

int main ()
{
  /* 局部变量声明 */
  int g = 10;

  printf ("value of g = %d\n",  g);

  return 0;
}
```

## 形式参数

```c
#include <stdio.h>

/* 全局变量声明 */
int a = 20;

int main ()
{
  /* 在主函数中的局部变量声明 */
  int a = 10;
  int b = 20;
  int c = 0;
  int sum(int, int);

  printf ("value of a in main() = %d\n",  a);
  c = sum( a, b);
  printf ("value of c in main() = %d\n",  c);

  return 0;
}

/* 添加两个整数的函数 */
int sum(int a, int b)
{
    printf ("value of a in sum() = %d\n",  a);
    printf ("value of b in sum() = %d\n",  b);

    return a + b;
}
```



# 数组

```c
类型说明符 数组名 [常量表达式3] ;   
type arrayName [ arraySize ];
int a[10]; 
它可以存储一个固定大小的相同类型元素的顺序集合
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0}; //大小是初始化元素个数
//0元素是起始位置
```

## 访问数组

```c
double salary = balance[9];

#include <stdio.h>

int main ()
{
   int n[ 10 ]; /* n 是一个包含 10 个整数的数组 */
   int i,j;

   /* 初始化数组元素 */         
   for ( i = 0; i < 10; i++ )
   {
      n[ i ] = i + 100; /* 设置元素 i 为 i + 100 */
   }

   /* 输出数组中每个元素的值 */
   for (j = 0; j < 10; j++ )
   {
      printf("Element[%d] = %d\n", j, n[j] );
   }

   return 0;
}
```


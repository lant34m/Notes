- 🔲进程控制块简答题

```plain
什么是PCB?
pCB是Process Control Block的缩写。全称是进程控制块，用于记录进程的所有信息。包括进程信息，
进程管理与调度信息，资源信息，处理机信息，PCB在进程被创建时，就自动生成。当进程因故消失，
则PCB也随之消失
```

- 🔲IPC机制

![img](https://cdn.nlark.com/yuque/0/2021/jpeg/12376342/1638646336982-a2c52338-b21e-47c1-a8cd-177623132426.jpeg)

- 🔲内存分配算法Buddy
- 🔲链接文件

# 

# 第一章 操作系统概述

## Linux操作系统的组成

![img](https://cdn.nlark.com/yuque/0/2021/jpeg/12376342/1638624994617-4f5cb12f-717b-4c71-8a9a-3eb4626bc475.jpeg)

# 第二章 Linux操作基础

## 基本操作

### 修改口令

修改口令使用passwd命令

### 关闭与重启

```plain
shutdown  now 关机
shutdown  -r now 重启
halt 关机
reboot  重启
```

## linux命令

### 简单命令

```plain
who   显示已登录的用户
	-H 显示各列的标题
echo   将命令行中的内容回显到标准输出上
	-n 输出字符串后光标不换行
	使用单引号扩出输出原格式内容
date   显示、设置日期和时间
	转义字符“%”前加“+”
cal     显示月份和日历 
```

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638625884239-1776e0fd-5839-4d22-bf72-d906ae981d1d.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638625896614-ae9cdb92-05a0-4d58-8653-b228cb2037b1.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638625907363-c3eec50f-b51e-4693-84ac-1d183cd9740f.png)

### 联机帮助 

```plain
--help选项：大部分命令都提供--help选项，用于显示该命令的帮助信息。 
man命令：查看命令的联机手册页。
info命令：查看命令的超文本说明书。
```

## Linux文件操作

### Linux文件

#### 命名规则

1. 最大长度255字符
2. 以“.”开头文件是隐含文件

1. 文件名不能包含“\”“\0”

#### 通配符

1. “?”匹配任意的单个字符
2. “*”匹配0或多个任意字符

1. “[]”匹配方括号中列出的字符集合中的任何单个字符

•列举：逐个列出各个字符，如[abc]；

•范围：用-描述字符范围，如[a-z]；

•排除：用！排除字符，如[!A-Z]。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638626588148-381212d3-5b38-4146-a7f3-f977d36f90b0.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638626607689-998082be-d7e9-4b5e-b2f1-9aebec9d0e00.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638626885354-71ce3967-fb4e-441a-a891-43e787ec54b2.png)

#### 文件类型

- 普通文件（-）
- 目录文件（d）

设备文件（c、d）：字符设备（c）和块设备（b） 

符号链接文件（l）：存放的数据是某个文件的路径

- 管道文件（p）

#### 文件归属关系

文件属主（user）：文件的所有者（通常是建立文件的人），用其用户名标识。

文件属组（group）：文件属主所在的用户组，用组名标识。

其他人（others）：除文件属主和属组用户外的其它系统用户。

所有人（all）：系统的所有用户。

#### 文件权限

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638627363479-1cbad622-a4ad-4520-a26d-02c65c7fe289.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638627396466-4f9ff201-46f1-41e8-a5bf-e1bb23d3d04c.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638627424002-ea717e4f-41b4-46b4-b005-6f9339853d4b.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638627535426-b49b1782-e4df-4f82-ac03-e0723eca0151.png)

数字表示法：用数字1或0来表示u、g、o权限的9位字符：有相应权限的位为1，无权限的位为0，形成一个9位长的二进制数，用3位八进制数字来表示。

新建文件的默认权限：

- 可执行文件：由777-掩码
- 不可执行文件：（777-掩码）&666

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638629984288-79b6eec9-f194-4b31-9486-d64ccc23e65f.png)



#### 目录

 ![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638629860336-7e720c02-ad8a-493f-9302-26d848516fd4.png)

#### 目录操作命令

```plain
查看、改变工作目录：
pwd 命令
cd 命令

显示目录内容：
ls 命令
	-a 显示所有文件及目录
  -R 递归显示目录下文件
  -u 显示文件最后访问时间
  -c 显示文件最后变更时间
  -t 按文件修改时间排序
  -l 显示文件详细信息

创建与删除目录：
mkdir 命令
	-m 按指定的权限建立目录
  -p 递归建立目录
  
rmdir 命令
	-p 递归删除目录
```

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638630071641-84887044-3f25-491f-b980-e6cbd5850547.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638630087459-1164a2f4-0c4c-47c7-8c71-339d7749d1de.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638630423944-564554cd-5206-49a5-8276-0fa132f4c0d0.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638630669100-2c264869-feca-45df-99df-fdd8b7feaeb3.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638630690888-ce2fbe01-4922-4829-a57a-91c73863566c.png)

#### 文件操作命令

```plain
r递归
v显示操作
i交互
f强制执行

文件显示：cat、more、less
	cat 命令
  	-A：显示所有字符
		-n ：由1开始对所有输出的行数编号。
		-b ：和-n相似，但对于空白行不编号。
		-s ：将连续的空白行压缩为一个空白行

文件复制、删除和移动：cp、rm、mv 
	cp 命令
  	-f：目标文件存在时，直接覆盖
		-i：目标文件存在时，提示是否覆盖
		-r：递归复制
		-b：生成覆盖文件的备份
		-p：保持文件原有属性
    -v：显示操作结果

	rm 命令
  	-f：忽略不存在的文件，不提示。
		-i：提示确认删除。
		-r：递归删除目录 。

	mv 命令
  	-i：提示是否覆盖。
		-b：建立覆盖文件的备份。
		-f：不提示，直接覆盖。
		-v：显示移动信息。
```

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638631082502-6cc86c2a-278c-4294-88cb-4647c7f3b5eb.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638631303481-eaddb721-10c2-4365-9e39-3e4a559626b2.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638631549791-6ac1e699-962f-4989-adb5-f9951c46d869.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638631647984-3d5d4c83-d704-40a9-b849-df675f150626.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638631741449-414d6943-c710-452b-a548-aa42aed014ae.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638632454050-4a7ff9b0-eb7a-479d-bb7e-af6e04a73280.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638632468606-31e2f117-e720-4666-b450-318598022043.png)

```plain
a访问
m更改
c变更

文件内容统计与排序：wc、sort
	wc 命令
  	-c：统计字节数。
		-l：统计行数。
		-w：统计字数。

	sort 命令
  	-b：忽略开始的空白。 
		-f：忽略大小写。
		-kn：按从第n个字段开始的内容排序。  
		-r：逆序排列。 

改变文件存取权限：chmod
	chmod 命令
  	权限范围：u，g，o，a
		操作：+ 增加权限，- 取消权限，= 赋权限
		权限字符：r，w，x


改变文件时间标签：touch
	touch 命令
  -a：仅改变文件的存取时间。
	-m：仅改变文件的修改时间。
	-c：不创建文件。
	-t  STAMP：使用STAMP指定的时间标签，而不是系统现在时间。
```

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638632804957-236994fa-2151-4557-84a5-cac96eea6c02.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638632820642-9f73d79a-555a-44a2-bf62-a8798bb02f49.png)
![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638633036845-817a087b-78f9-4209-a33f-55c883da6061.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638633063453-512323a3-c8a0-4c49-b214-61cfdc66a0e8.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638633379747-8ebbf394-2340-47c0-ada2-7def5617679b.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638633777937-293d7797-ef6c-4b3d-842c-94b90ad8cca8.png)

```plain
文件查找：find、grep

“+n”表示大于n的文件；“-n”表示小于n的文件。

	find 命令
  ——在文件系统的目录树中查找匹配的文件，并可对匹配的文件执行各种命令
  	-name 文件名：查找指定名称的文件
		-user  用户名：查找指定用户拥有的文件
		-group 组名：查找指定组拥有的文件
		-mtime n：查找在n天前修改的文件。
    -atime  n：类似于mtime，但检查的是文件被访问的时间。
		-type x：查找类型为x的文件。x是表示文件类型的字符（f 普通文件、d目录）。
		-size n：查找文件大小为n的文件。
		-print：显示找到的文件名。 
		-exec 命令 {} \; ：对匹配文件执行指定的命令。
		-ok 命令 {} \; ：执行命令的时候请求用户确认。其它与-exec相同。
```

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638634197017-8ba3f8c1-caf1-4fe5-b0f0-7cb684259494.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638634294561-630275f9-649f-429e-a17b-ec6efc4f153f.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638634307006-0d5a2222-4055-4458-89c7-b9320cafd8fd.png)

```plain
文件查找：find、grep
	grep 命令
  	-v：列出不包含匹配字符串的行。 
		-c：只列出匹配的行数。  
		-r：递归地查询所有子目录。 
		-n：在每个匹配行前加行号显示。 
		-i：不区分大小写。
```

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638635675599-006404e8-590f-48ce-8999-19a9984531c1.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638635686806-352d9f54-e867-481e-a661-0396c6c8e52d.png)![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636060746-f146f1d7-4716-4c6c-9f56-44a084767f4a.png)

## 输入输出重定向

### 输入重定向

命令< 文件

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636338006-14941bcc-e076-44b7-83c8-602fddfb61e2.png)

### 输出重定向

- 标准输出重定向：命令 >文件
- 标准错误输出重定向：命令 2>文件

- 合并输出重定向：命令 &>文件
- 附加输出重定向：命令 >>文件

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636366297-dcf44490-e49c-4b00-a975-b0559c5f35dc.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636379218-414e5037-50f5-4dc4-ba7a-c64822f2be57.png)

  ![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636399835-db703bfd-b7bc-4031-9abb-df40afe7c952.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636531136-09cfbb85-afa6-4bb5-8648-060fb57978c7.png)

### 管道

管道的形式为:	     命令1 | 命令2

命令1 | tee 文件| 命令2

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636870308-674bdbec-793a-469d-8d54-6ed0bcfa4107.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636882271-cfe307f6-2c48-42dd-a1e2-43ceb100a1a5.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638636897617-8ab290cc-1569-422e-bdd3-5e7839e7d1f0.png)

## 习题

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638637103522-ef0ed643-0021-4081-9558-ffb75afebd1b.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638638422863-da3f336a-9aa6-49f0-9fe5-003370e17c94.png)

1. -n 不换行输出
2. %T

1. 切换至主目录
   切换至上层目录
   切换至上层目录的上层目录
   切换至根目录
2. /bin
   /usr/share/zoneinfo
   /usr/lib
   /usr/lib/games

1. ip, ipip, rawip, rip
   idp, udp
   arp, egp, ggp, idp
2. 显示/home目录下文件；在屏幕上打印出/home
   显示当前目录文件；不显示
   显示当前目录文件；显示当前目录文件

1. 显示当前目录文件详细信息；显示当前目录的详细信息
   显示当前目录文件；显示当前目录文件
2. 目录文件，g、o列出目录下文件，打开目录
   普通文件，g、o打开目录
   字符文件，u、g列出目录下文件，修改目录下文件

1. 不可以，目录文件规定权限高于目录下文件权限
2. 文本文件：（777-037）&666=640（110 100 000）
   目录文件：777-037=740

1. find  . '[A-Z]*' -type f -ls
2. 成功
   成功
   报错

1. cp -i /.profile /backup
2. chmod a+x myfile

1. find -name '*mem*'
2. find ~ -name '*.gif' - atime +30 -exec rm -ri {} \;

1. grep -i saturday\|sunday
2. wc -l > memo.lines

1. 找到所有以.c结尾的文件，显示文件内容
   找到所有以.c结尾的文件，以标准输出赋给cat（即路径）
   找到所有以.c结尾的文件，将内容输出至文件cat
2. find -name '*.c' -o -name '*.h' | wc -l

1. sort data > data.sort
   sort data | tee data.sort | wc -l
   sort data | tee data.sort | wc -l > data.lines

# 第三章 vi文本编辑器

 vi工作模式

1. 命令模式
2. 插入模式

1. 末行模式

# 第四章 Linux C编程基础

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638639426021-51cecb0f-89f1-4c49-b825-5fa5e7f55ef9.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638639459761-95bdd610-7acd-47ab-957a-21a226ee01bb.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638639480563-94ff0a10-69bd-4f37-8016-29e0da30a200.png)

# 第五章 进程管理

## 进程

### 程序顺序执行

- 顺序性
- 封闭性

- 可再现性

### 程序并发执行

- 间断性
- 没有封闭性

- 不可再现性

### 进程的状态和切换

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638639843950-27931516-c2a4-4122-8ba3-4ad40a1686c0.png)

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638640456931-aa9f9409-3a11-4757-b9ec-83117bdf6f58.png)

### 进程控制块

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638640192914-c3aa73b8-87ea-49eb-8622-4b0c67ce8f8f.png)

### 查看进程信息

```plain
ps命令
  -e   显示所有进程。
  -f    以全格式显示。
  -r   只显示正在运行的进程。
  a    显示终端上的所有进程。
  u    以面向用户的格式显示。
  x    显示所有不控制终端的进程。
```

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638640760859-87266e9e-dcd8-46d3-9415-db91fe68deb9.png)

## 内核

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638640931564-69fd363c-8d43-47bb-9237-ae58dba529e8.png)

### 内核的组成

- 系统调用：提供进程与内核的接口。
- 进程控制子系统：负责控制进程的运行，包括进程调度、进程间通信、内存管理。

- 文件子系统：为进程提供I/O环境，控制对文件和设备的访问。包括文件系统、网络接口、设备驱动。
- 硬件控制：处理中断及与硬件通信。 

## 进程的组织

通常采用的结构有数组、散列表和链表。

## 进程操作

### 创建子进程

0：向子进程返回的ID值；                                                                    

\> 0：向父进程返回的子进程的ID值。                                                                    

-1：创建失败。

若fork()调用成功，它向父进程返回子进程的PID，并向新建立的子进程返回0。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638643681238-5c5ae8de-56e9-4a10-991c-5d34015cbe06.png)

### 改变进程映像

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1638643874662-70a09d7b-0c92-4b95-ad57-1d6f596196e0.png)

## 进程调度算法

- 先进先出法：按照进程在可执行队列中的先后次序来调度
- 短进程优先法：优先调度短进程，提高系统吞吐率  

- 时间片轮转法：进程按照规定的时间片轮流使用CPU
- 优先级调度法：为进程设置优先级，优先级高的先执行
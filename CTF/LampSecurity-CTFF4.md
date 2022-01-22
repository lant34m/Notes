# 关于配置方面

我的Kali机和FreakLeaks靶机均是NAT网络

# 撸起袖子加油干

![image-20220123005334469](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123005334469.png)

老样子

```
netdiscover
```

靶机对应ip是172.16.12.102

使用

```
nmap -sV 172.16.12.102
```

![image-20220123005446774](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123005446774.png)

> 开放了22 ssh，25 smtp，80 http和631 cups打印机服务

![image-20220123010545731](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123010545731.png)

80端口

直接扫目录

```
dirb http://172.16.12.102
```

![image-20220123011116455](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123011116455.png)

![image-20220123011133150](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123011133150.png)

![image-20220123011227538](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123011227538.png)

![image-20220123012048100](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123012048100.png)

![image-20220123012123733](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123012123733.png)

有个敏感文件robots.txt

![image-20220123012234804](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123012234804.png)

访问sql目录

![image-20220123012302666](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123012302666.png)

Apache版本2.2.0

![image-20220123012415223](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123012415223.png)

```sql
use ehks;
create table user (user_id int not null auto_increment primary key, user_name varchar(20) not null, user_pass varchar(32) not null);
create table blog (blog_id int primary key not null auto_increment, blog_title varchar(255), blog_body text, blog_date datetime not null);
create table comment (comment_id int not null auto_increment primary key, comment_title varchar (50), comment_body text, comment_author varchar(50), comment_url varchar(50), comment_date datetime not null);
```

在数据库ehks中有三个表user，blog和comment

在

```
http://172.16.12.102/admin/
```

目录是登陆界面

```
http://172.16.12.102/restricted
```

![image-20220123013138396](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123013138396.png)

> This server could not verify that you are authorized to access the document requested. Either you supplied the wrong credentials (e.g., bad password), or your browser doesn't understand how to supply the credentials required.
> Apache/2.2.0 (Fedora) Server at 172.16.12.102 Port 80

需要验证

```
http://172.16.12.102/mail/src/login.php
```

![image-20220123013317667](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123013317667.png)

邮件服务同样是登陆界面

## 登陆界面看看有什么操作

使用admin' or 1=1#登陆试试

![image-20220123013636957](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123013636957.png)

可以看到页面把单引号空格等号和井号过滤

使用url和base64加密的方式不可行

进行多次测试并未发生登陆次数限制，尝试爆破密码

## 博客页面看看有什么操作

![image-20220123021320403](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123021320403.png)

```
http://172.16.12.102/index.html?page=blog&title=Blog&id=2
```

id可能是个注入点

![image-20220123021501831](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123021501831.png)

使用单引号注入后报错，mysql_fetch_row()即从数据库中选出一行作为输出，同时靶机的目录被爆出

```
/var/www/html/pages/
```

使用语句测出

```
http://172.16.12.102/index.html?page=blog&title=Blog&id=2 order by 1
```

![image-20220123021946893](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123021946893.png)

直接sqlmap跑一下就出来了

```
python sqlmap.py -u "http://172.16.12.102/index.html?page=blog&title=Blog&id=2"
```

![image-20220123022512477](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123022512477.png)

Apache版本 2.2.0，PHP版本5.1.2，Mysql版本5.0.12

## 邮件页面看看有什么操作

![image-20220123023229096](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123023229096.png)

SquirrelMail版本是1.4.17，上网搜一搜

> PHP邮件Squirrelmail远程代码执行漏洞CVE-2017-7692 1.4.22以下版本均受影响

可以对其测试

相关poc

## calendar页面看看有什么操作

![image-20220123023902902](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123023902902.png)

选年月的位置是否可以注入，查看源代码发现是链接页面，可能存在注入

搜索界面有没有xss

登陆界面sql注入或其他

选月份后

```
http://172.16.12.102/calendar/index.php?action=display&year=2022&month=2
```

![image-20220123024050589](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123024050589.png)

可以看到有报错，遇到了不完善的数值，判断存在数值类型转换

在登陆页面

利用admin'登陆测试，发现报错

![image-20220123025032920](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123025032920.png)

```sql
SELECT uid FROM phpc_users
WHERE username = 'admin'' AND password = 'c4ca4238a0b923820dcc509a6f75849b' AND calendar = '0'
```

在phpc_users表中选出uid

sql语句被报错显示出，单引号没被过滤可以测试

> 账号：admin' or '1=1
>
> 密码：任意

登陆成功

![image-20220123025243499](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123025243499.png)

![image-20220123025304560](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123025304560.png)

创建两个新用户尝试，12和12'#查看能否修改密码，其中'#使用url编码

事实发现，随便用个账号登陆就是admin账户= =

在账户设置处，有日历标题选项，可以测试存储性xss

![image-20220123025924957](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123025924957.png)

![image-20220123025956596](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123025956596.png)

将Anonymous Permission权限改为可以修改和添加日程

测试日程处的存储型xss

![image-20220123030336225](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123030336225.png)

弹出失败
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


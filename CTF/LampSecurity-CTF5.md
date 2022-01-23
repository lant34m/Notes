# 关于配置方面

我的Kali机和FreakLeaks靶机均是NAT网络

# 撸起袖子加油干

先用netdiscover扫一下靶机ip

![image-20220123181628304](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123181628304.png)

在用

```
nmap -sV 172.16.12.103
```

![image-20220123182149767](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123182149767.png)

```
dirb http://172.16.12.103
```

![image-20220123183155979](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123183155979.png)

![image-20220123183211087](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123183211087.png)

![image-20220123183230357](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123183230357.png)

挖掘一下关键信息：

- 有一个info.php的页面

  ```
  172.16.12.103/info.php
  ```

  ![image-20220123183540270](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123183540270.png)

- phpmyadmin页面开放

  ```
  172.16.12.103/phpmyadmin
  ```

  ![image-20220123183507115](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123183507115.png)

  phpmyadmin的ChangeLog页面开放

  ```
  172.16.12.103/phpmyadmin/ChangeLog
  ```

  ![image-20220123184500436](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123184500436.png)

- squirrelmail邮件页面开放

  ```
  172.16.12.103/squirrelmail
  ```

  ![image-20220123183619896](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123183619896.png)

- events页面开放

  ```
  172.16.12.103/events
  ```

  ![image-20220123183724045](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123183724045.png)

  内含一个登陆页面

  ```
  172.16.12.103/events/user
  ```

  ![image-20220123184109201](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123184109201.png)

- events内robots.txt页面开放

  ```
  172.16.12.103/events/robots.txt
  ```

  ![image-20220123183950112](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123183950112.png)

- list注册界面

  ```
  172.16.12.103/list
  ```

  ![image-20220123184230047](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123184230047.png)

- 
# Network

## Ch1 FTP - authentication

用Wireshark打开pcap文件

![image-20220116112001036](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116112001036.png)

在过滤器处输入ftp-过滤显示ftp内容

![image-20220116112230051](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116112230051.png)

可以看到

```
Request : USER cdts3500
Request : PASS cdts3500
Response : 230 CDTS3500 logged on.
```

故密码为cdts3500

## Ch2 TELNET - authentication

用Wireshark打开pcap文件

![image-20220116112828623](C:/Users/LanT34m/AppData/Roaming/Typora/typora-user-images/image-20220116112828623.png)

最笨的方法，在过滤器处输入telnet过滤telnet内容

对每个Telnet Data筛选查找关键字login/username/pass

如图

![image-20220116113137386](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116113137386.png)

右键数据流进行TCP数据流追踪

![image-20220116113232422](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116113232422.png)

查找到password

## Ch3 ETHERNET - frame

作为基础知识，ETHERNET帧结构是16进制

故使用16进制转字符工具即可

![image-20220116115649241](D:/Notes/CTF/Network/image-20220116115649241.png)

填入后并不正确，需要用Base64解密

![image-20220116115916859](D:/Notes/CTF/Network/image-20220116115916859.png)

## Ch4 Twitter - authentication

打开文件只有一条数据流

追踪TCP后

![image-20220116120151281](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116120151281.png)

依旧是Base64编码，解码可得

![image-20220116120231776](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116120231776.png)

## Ch4 Bluetooth - unknownfile

> Your friend working at NSA recovered an unreadable file from a hacker’s computer. The only thing he knows is that it comes from a communication between a computer and a phone.
>
> The answer is the sha-1 hash of the concatenation of the MAC address (uppercase) and the name of the phone.
>
> Example:
> AB:CD:EF:12:34:56myPhone -> 023cc433c380c2618ed961000a681f1d4c44f8f1

由题知：由电脑和手机的交互，答案是SHA-1哈希加密。

可以继续用最笨的方法找

![image-20220116121012589](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116121012589.png)

找到了手机和地址

进行拼接，==一定按照示例中的规则，即大写拼接手机名==

![image-20220116121844677](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116121844677.png)

## Ch5 IP - Time To Live

> Find the TTL used to reach the targeted host in this ICMP exchange.

很简单，打开文件后，应用过滤器ICMP

![image-20220116132054805](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116132054805.png)

找到TTL下方有Response的，将ttl值填入即可

# WEB  - CLIENT

## Ch1 HTML - disabled buttons

![image-20220116150718659](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116150718659.png)

利用F12开发者工具，将Form表单中的disable删除即可。

## Ch2 Javascript -authentication1

![image-20220116152117462](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116152117462.png)

同样利用F12的开发者工具，可以看到HTML代码中login按钮提交到Login()函数中。==小tips==：可以去网络模块查看包括但不限于关键JS代码、响应服务器版本等。

## Ch3 Javascript - Source

![image-20220116152845246](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116152845246.png)

任意提交一个密码尝试一下，和上题类似响应中提示了密码。

## Ch4 Javascript-authentication2

提交用户名密码登陆尝试后，继续查看响应的JS代码

![image-20220116153741138](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116153741138.png)

需要一点语言基础，只需要看明白函数对TheLists字符串以冒号分割。冒号前是用户名冒号后是密码。

## Ch5 Javascript - Obfuscation1

![image-20220116155034793](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116155034793.png)

同样是一个登陆框，使用之前的思路进行尝试。

发现并不返回JS代码了

登陆之后会返回一个没有登陆框的界面

![image-20220116155203854](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116155203854.png)

右键查看页面源代码即可

![image-20220116155216781](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116155216781.png)

页面使用unescape解密pass，直接扔到解密工具即可

## Ch6 Javascript -Obfuscation2

![image-20220116155532648](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116155532648.png)

直接右键查看源代码

对%URL加密需要了解或者使用工具解密，%28%22解密为("等等

语句解密如下

```javascript
var pass = unescape("unescape("String.fromCharCode(104,68,117,102,106,100,107,105,49,53,54)")");
```

可以去RUNOOB或W3C等在线编译网站进行编译输出。

## Ch7 Javascript -Native code


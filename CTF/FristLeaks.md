# 关于配置方面

我的Kali机和FreakLeaks靶机均是NAT网络

同时需要手动配置靶机的MAC地址为：08：00：27：A5：A6：76

# 撸起袖子加油干

在FreakLeaks打开后，会显示当前主机的IP地址

可以使用netdiscover命令

![image-20220122220850857](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122220850857.png)

亦或者

```
nmap -O 172.16.12.0/24
```

![image-20220122221001449](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122221001449.png)

扫除目标靶机的IP地址后

可以使用

```
nmap -sV 172.16.12.101
```

![image-20220122221127556](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122221127556.png)

靶机开了80端口

```
dirb http://172.16.12.101
```

![image-20220122221230630](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122221230630.png)

提示如果想全目录扫描，可以加参数-w

```
dirb http://172.16.12.101 -w
```

我们找到了一个敏感目录文件robots.txt

访问一下试试

![image-20220122221616176](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122221616176.png)

每一个目录都是

![image-20220122222021249](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122222021249.png)

返回主页查看以下主页源代码

![image-20220122222112985](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122222112985.png)

img引入了一个images目录下的文件

碰运气访问下images看看有没有开放目录浏览

![image-20220122222311696](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122222311696.png)

返回父目录直接返回主页，推断做了重定向

随意打开一个图片可直接跳转

![image-20220122223528592](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122223528592.png)

如果上传php一句话，应该是可以利用的

没什么信息挖掘出来

只好手动测试

![image-20220122224415093](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122224415093.png)

将每一个都试一下

主页图片上的fristi拼接成功，想尝试leaks但没有成功

![image-20220122224526342](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122224526342.png)

![image-20220122224619155](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122224619155.png)

老样子查看网页源码，发现一个Base64加密

```
iVBORw0KGgoAAAANSUhEUgAAAW0AAABLCAIAAAA04UHqAAAAAXNSR0IArs4c6QAAAARnQU1BAACx
jwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAARSSURBVHhe7dlRdtsgEIVhr8sL8nqymmwmi0kl
S0iAQGY0Nb01//dWSQyTgdxz2t5+AcCHHAHgRY4A8CJHAHiRIwC8yBEAXuQIAC9yBIAXOQLAixw
B4EWOAPAiRwB4kSMAvMgRAF7kCAAvcgSAFzkCwIscAeBFjgDwIkcAeJEjALzIEQBe5AgAL5kc+f
m63yaP7/XP/5RUM2jx7iMz1ZdqpguZHPl+zJO53b9+1gd/0TL2Wull5+RMpJq5tMTkE1paHlVXJJ
Zv7/d5i6qse0t9rWa6UMsR1+WrORl72DbdWKqZS0tMPqGl8LRhzyWjWkTFDPXFmulC7e81bxnNOvb
DpYzOMN1WqplLS0w+oaXwomXXtfhL8e6W+lrNdDFujoQNJ9XbKtHMpSUmn9BSeGf51bUcr6W+VjNd
jJQjcelwepPCjlLNXFpi8gktXfnVtYSd6UpINdPFCDlyKB3dyPLpSTVzZYnJR7R0WHEiFGv5NrDU
12qmC/1/Zz2ZWXi1abli0aLqjZdq5sqSxUgtWY7syq+u6UpINdOFeI5ENygbTfj+qDbc+QpG9c5
uvFQzV5aM15LlyMrfnrPU12qmC+Ucqd+g6E1JNsX16/i/6BtvvEQzF5YM2JLhyMLz4sNNtp/pSkg1
04VajmwziEdZvmSz9E0YbzbI/FSycgVSzZiXDNmS4cjCni+kLRnqizXThUqOhEkso2k5pGy00aLq
i1n+skSqGfOSIVsKC5Zv4+XH36vQzbl0V0t9rWb6EMyRaLLp+Bbhy31k8SBbjqpUNSHVjHXJmC2Fg
tOH0drysrz404sdLPW1mulDLUdSpdEsk5vf5Gtqg1xnfX88tu/PZy7VjHXJmC21H9lWvBBfdZb6Ws
30oZ0jk3y+pQ9fnEG4lNOco9UnY5dqxrhk0JZKezwdNwqfnv6AOUN9sWb6UMyR5zT2B+lwDh++Fl
3K/U+z2uFJNWNcMmhLzUe2v6n/dAWG+mLN9KGWI9EcKsMJl6o6+ecH8dv0Uu4PnkqDl2rGuiS8HK
ul9iMrFG9gqa/VTB8qORLuSTqF7fYU7tgsn/4+zfhV6aiiIsczlGrGvGTIlsLLhiPbnh6KnLDU12q
mD+0cKQ8nunpVcZ21Rj7erEz0WqoZ+5IRW1oXNB3Z/vBMWulSfYlm+hDLkcIAtuHEUzu/l9l867X34
rPtA6lmLi0ZrqX6gu37aIukRkVaylRfqpk+9HNkH85hNocTKC4P31Vebhd8fy/VzOTCkqeBWlrrFhe
EPdMjO3SSys7XVF+qmT5UcmT9+Ss//fyyOLU3kWoGLd59ZKb6Us10IZMjAP5b5AgAL3IEgBc5AsCLH
AHgRY4A8CJHAHiRIwC8yBEAXuQIAC9yBIAXOQLAixwB4EWOAPAiRwB4kSMAvMgRAF7kCAAvcgSAFzk
CwIscAeBFjgDwIkcAeJEjALzIEQBe5AgAL3IEgBc5AsCLHAHgRY4A8Pn9/QNa7zik1qtycQAAAABJR
U5ErkJggg==
```

![image-20220122224746766](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122224746766.png)

转码有标识符PNG，故使用Base64转图片

![image-20220122224932201](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122224932201.png)

使用任意账号密码测试下，网络包中返回了对应的Apache和PHP版本信息(PHP5.3有目录遍历漏洞和PDO SQL注入)

![image-20220122225659147](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122225659147.png)

网站源码中有![image-20220122231431823](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122231431823.png)

使用刚刚解出的密码和注释中的by eezeepz

![image-20220122231603755](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122231603755.png)

登陆成功，有一个上传文件的连接，跳转至upload.php

![image-20220122231720139](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122231720139.png)

上传普通图片可以访问

![image-20220122232304275](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220122232304275.png)

上传一句话木马试试

![image-20220123000457556](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123000457556.png)

成功访问，抓包改成php试试

![image-20220123000741930](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220123000741930.png)

被拒绝

把上传文件改为1.php.jpg即可
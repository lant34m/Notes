# 关于配置方面

我的Kali机和FreakLeaks靶机均是NAT网络

# 撸起袖子加油干

```
netdiscover
```

![image-20220124220225608](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220124220225608.png)

靶机地址为172.16.12.104

```
nmap -sV 172.16.12.104
```

![image-20220124220256743](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220124220256743.png)

基本上只能从web服务和ssh服务提权

```
dirb http://172.16.12.104
```

![image-20220124220456235](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220124220456235.png)

```
http://172.16.12.104/in
```

目录下包含phpinfo

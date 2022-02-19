# Xray简单使用

## 创建证书

![image-20220218011635588](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220218011635588.png)

导入证书即可，一般使用Chrome浏览器较为方便。

## 简单使用

设置代理

使用语句

```
./xray_linux_amd64 webscan --listen 127.0.0.1:7777 --html-output xray.html
```

启动webscan功能对127.0.0.1:7777进行监听，对功能结果输出为html文件

![image-20220218125847651](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220218125847651.png)

打开Sqli-Labs的一个关卡可以很轻松的访问并扫描出漏洞

![image-20220218131131607](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220218131131607.png)

但查看服务日志

在很短的时间内对服务造成大量请求

![image-20220218130620161](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220218130620161.png)

可以通过config.yaml中的

```
max_qps
```

更改，根据官方文档描述

> ## 限制发包速度 `max_qps`
>
> 默认值 500， 因为最大允许每秒发送 500 个请求。一般来说这个值够快了，通常是为了避免被ban，会把该值改的小一些，极限情况支持设置为 1， 表示每秒只能发送一个请求。


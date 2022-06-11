# Docker基础

### ubuntu安装

```
apt-get install docker.io
```

### 搜索镜像

可以通过网页版DockerHub搜索

![image-20220606115336406](http://pic.oft5mile.cn/storage/app/uploads/2022/06/06/629d7a4b07ff6.png)

可以通过

```
docker search 
```

直接搜索

![image-20220606115534966](http://pic.oft5mile.cn/storage/app/uploads/2022/06/06/629d7aba4074c.png)

### 下载镜像

```
docker pull name:tag
```

### 通过Dockerfile构建镜像

```
docker build -t name:tag .
```

name:tag后一定携带空格点才能正确执行

### 通过docker-compose构建镜像

```
先下载docker-compose
apt-get install docker-compose
```

```
docker-compose up -d
```

### 列出本地镜像

```
docker images
```

![image-20220606115707852](http://pic.oft5mile.cn/storage/app/uploads/2022/06/06/629d7b1747702.png)

### 运行镜像创建容器

```
docker run -it -d -p xxxx:xxxx REPOSITORY:TAG
或 docker run -it -d -p xxxx:xxxx IMAGEID
如果不知道镜像内部端口可以使用docker run -it -d -P REPOSITORY:TAG让docker自动选择本地空闲端口
```

```bash
使用 -i、-t选项可以在运行的Bash shell中进行输入与输出
```

![image-20220606120240897](http://pic.oft5mile.cn/storage/app/uploads/2022/06/06/629d7c643f89f.png)

**注意**：不可使用重复本地端口

借用盘古实验室PPT

![image-20220607153925528](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f00ae23acd.png)

### 查看本地容器

```
docker ps 仅查看当前运行容器
docker ps -a 查看本地所有容器
```

### 关闭和启动容器

```
docker stop CONTAINERID 	
docker start CONTAINERID
docker restart CONTAINERID
```

### 进入容器

```
docker exec -it CONTAINERID /bin/bash
docker exec -it CONTAINERID /bin/sh
命令区别在容器内是否有bash
docker attach CONTAINERID
```

![image-20220606121701755](http://pic.oft5mile.cn/storage/app/uploads/2022/06/06/629d7fc10a761.png)

### 复制文件

```
docker cp 主机路径 容器ID:容器路径
docker cp 容器ID:容器路径 主机路径
```

### 删除容器或镜像

```
docker kill CONTAINERID
docker rm CONTAINERID
以上命令搭配执行删除容器

docker image rm IMAGEID
在所有运行镜像的容器都已经被删除的状态下，才能删除镜像
```

### 查看容器的日志

```
docker logs CONTAINERID
```

在工作的时候经常会有容器因为联网问题服务启动失败的状态，需要查看docker容器的日志排查错误原因

### docker更换镜像源

```
vim /etc/docker/daemon.json
```

可以使用阿里云的docker镜像源或者其他的

更新后

```bash
sudo systemctl daemon-reload
sudo systemctl restart docker
```

### 提交镜像更改

```
docker commit CONTAINERID name:tag
```

### 保存镜像为.tar文件

```
docker save -o name.tar name:tag
```

### 将tar包导入docker

```
docker load -i name.tar
```





# Dockerfile

借用盘古实验室PPT

![image-20220607153842960](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f0083a0f8b.png)

### FROM 指定基础镜像

```
FROM <image> [AS <name>]
FROM <image>:<tag> [AS <name>]
FROM <image>@<digest> [AS <name>]
```

`FROM`指令为后续指令设置基础镜像。有效的`Dockerfile`必须以`FROM`指令开头。

### RUN

```
SHELL执行
RUN <command>

EXEC执行
RUN ["executable", "param1", "param2"]
```

RUN用于在构建镜像时执行命令

### ADD

```
ADD <src>... <dest>
ADD ["<src>",... "<dest>"] 用于支持包含空格的路径
```

### COPY

用法功能类似ADD，但不能自动解压文件或访问使用互联网资源

### CMD

```
CMD ["executable","param1","param2"] (执行可执行文件，优先)

CMD ["param1","param2"] (设置了ENTRYPOINT，则直接调用ENTRYPOINT添加参数)

CMD command param1 param2 (执行shell内部命令)
```

在构建镜像后，启动容器时调用

### ENTRYPOINT

```
ENTRYPOINT ["executable", "param1", "param2"] (可执行文件, 优先)
ENTRYPOINT command param1 param2 (shell内部命令)
```

配置容器，使其可执行化。ENTRYPOINT 与CMD一起使用，ENTRYPOINT 写默认命令，当需要参数时候 使用CMD传参。

### ENV

```
ENV <key> <value>  #<key>之后的所有内容均会被视为其<value>的组成部分，因此，一次只能设置一个变量

ENV <key>=<value> ...  #可以设置多个变量，每个变量为一个"<key>=<value>"的键值对，如果<key>中包含空格，可以使用\来进行转义，也可以通过""来进行标示；另外，反斜线也可以用于续行
```

设置环境变量

### EXPOSE

```
EXPOSE <port> [<port>...]
```

指定与容器外交互的端口。

EXPOSE并不会让容器的端口访问到主机。要使其可访问，需要在docker run运行容器时通过-p来发布这些端口，或通过-P参数来发布EXPOSE导出的所有端口

如果没有EXPOSE端口，后期也可以通过-p 8080:80方式映射端口，但是不能通过-P形式映射

### WORKDIR

```
WORKDIR /path/to/workdir
```

指定工作目录，类似于cd命令

### 制作镜像

- 如果有多个RUN,自上而下依次运行，每次运行都会形成新的层，建议&& 放入一行运行
- 如果有多个CMD,只有最后一个运行
  如果有多个Entrypoint，只有最后一个运行
- 如果CMD和entrypoint共存，只有entrypoint运行，且最后的CMD会当做entrypoint的参数





# 解析Dockerfile

### 构建CMS

![image-20220607124504653](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629ed7d10a77b.png)

![image-20220607123103072](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629ed48f54302.png)

![image-20220607123114985](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629ed493699da.png)

先说Dockerfile文件，基础镜像是`lamp_alpine:php56_mariadb10.2`，基础镜像内自带apache、mysql和php环境，定义了时区是`Asia/Shanghai`。

将目录中的`database.sql`复制到根目录，`source.zip`文件复制到根目录。

执行一系列命令，删除网站根目录所有内容，解压`source.zip`的内容至网站根目录；

将网站根目录的所有者更改为apache组的apache用户；

启动mysql服务，从`database.sql`文件中读取数据库内容；

删除`database.sql`和`source.zip`文件。

切换工作目录至网站根目录（即进入容器后的当前目录）。

向外映射80端口。

打开容器执行`docker-entrypotint.sh`文件。



`docker-entrypotint.sh`文件内容是

打开apache和mysql服务。

关于sleep找到的解释是。

> docker 容器将一直存在，直到它运行的命令完成。此命令通常设置在`Dockerfile`用于构建映像的命令中（在一个`CMD`节中），并且可以在命令行上覆盖（如`docker container run -d --name mycontainer myimage:mytag sleep infinity`所示）。
>
> 许多基本映像（如 debian、ubuntu、centos 的基本操作系统......）将运行 shell 作为默认命令（`bash`或`sh`一般情况下）。如果你尝试使用其默认命令从该映像生成一个容器，它将一直存在，直到 shell 退出。
>
> 当以交互方式（即使用`docker container run -it .....`）运行此类图像时，它将一直运行到你结束 shell 会话为止。但是如果你想在后台启动它（即使用`docker container run -d ...`），它会立即退出，留下一个停止的容器。
>
> 在这种情况下，你可以通过使用长时间运行的命令覆盖默认命令来“伪造”长时间运行的服务，该命令基本上什么都不做，只是等待容器停止。两个广泛使用的命令是`sleep infinity`（或任何适合你需要的时期）和`tail -f /dev/null`
>
> 启动这样的容器后，你可以使用它来测试你需要的任何内容。最常见的方法是针对它运行交互式 shell：
>
> ```
> # command will depend on shells available in your image
> docker exec -it mycontainer [bash|sh|zsh|ash|...]
> ```
>
> 完成实验/测试后，你可以停止并回收容器
>
> ```
> docker container stop mycontainer
> docker container rm mycontainer
> ```
>
> [其他-Docker sleep 命令有什么作用？ - 糯米PHP (nuomiphp.com)](https://www.nuomiphp.com/a/stackoverflow/zh/61587ff3c1b4ef490e244366.html)



### 构建Middleware

![image-20220607160424135](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f06889b264.png)

![image-20220607160438060](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f06967ff3a.png)

![image-20220607160451696](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f06a43085c.png)

从基础镜像`openjdk:8u111-alpine`构建，设置时区为`Aisa/Shanghai`，将脚本文件复制进docker容器；

新建目录，给予`docker-entrypotint.sh`脚本文件执行权限；

将log4j的漏洞jar包复制到新建的目录内，向外部映射80端口；

运行容器即执行`docker-entrypotint.sh`脚本



`docker-entrypotint.sh`文件内容是

用java命令执行jar包

# docker-compose

> Compose的使用基本遵循以下三步：
> 1）用Dockfile文件定义应用的运行环境，以便应用在任何地方都可以复制；基于这个Dockfile，可以构建出一个Docker镜像
> 2）用docker-compose.yml文件定义应用的各个服务，以便这些服务可以作为此应用的组件一起运行
> 3）最后，执行docker-compose up命令，这样Compose就会创建和运行整个应用了

一般Dockerfile就够了，如果后续有用到，再编写。

借用盘古实验室PPT

![image-20220607182719542](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f280849d9f.png)

![image-20220607182741788](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f281ea4c6f.png)

编写docker-compose.yml的目的大部分是为了可以指定镜像名和端口，利用`docker-compose up -d`命令直接一键运行。

![image-20220607182335293](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f272805b2f.png)

![image-20220607182407960](http://pic.oft5mile.cn/storage/app/uploads/2022/06/07/629f274877590.png)
# 前情提要

**本文使用的软件仅限于个人学习，严禁用于非法用途！**

其次，分享一个在用的Burpsuite版本——v2021.9.1。我的运行环境是Windows 11、Java17。

链接如下：http://pan.oft5mile.cn:10000/index.php/s/8BXo9Gsb3FcHQBj 密码：oftsmile



解压压缩包后如下：

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637945056474-1a18f00f-881e-454f-bde6-bb403567de41.png)

如若运行不了，建议从官网下载Burp Suite Professional v2021.9.1版本，并将burpsuite.bat、burpsuiteen.bat、burpSuite_cn.jar、BurpSuiteLoader.jar文件保留至新安装文件夹内。

其中将burpsuite.bat和burpsuiten.bat文件

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637945401505-b61ddca1-c257-43bb-9f4d-ac87973f2d78.png)

**需要做修改：盘符改为burpsuite安装的盘符，cd后路径改为burpsuite安装路径。**



在安装破解过程中，遇到了如下问题：

- 由于之前的误操作，javaw.exe文件被损坏。在这个文件损坏的状况下，在你尝试运行***.jar\***文件是无法正常操作的。

——解决办法：重装Java（建议安装Java9以上版本，否则无法打开较新的burpsuite，同时不建议使用Java新版本）

- Java安装过程中，需注意：

- - - - - - - - 高版本Java已经将jdk和jre集成，无需独立安装。
              - 同时高版本Java中已经不需要在环境配置中加入rt.jar、tools.jar和dt.jar

- - - - - - - - JRE包调出命令：

```plain
bin\jlink.exe --module-path jmods --add-modules java.desktop --output jre
```

- 对于高版本Java，前人分享的Burpsuiteloader并不能正确运行，主要是因为其中有句-Xbootclasspath/p，在高版本是执行不了的。
  	其实，改为-Xbootclasspath或-Xbootclasspath/a均可运行
  	将整体语句改为

```plain
java -noverify -javaagent:BurpSuiteLoader.jar -jar burpsuite_pro.jar
```







以上问题不存在后且能正常运行burpsuite后，进入学习吧！

# 启动BurpSuite

## 命令行启动

配置Java之后，在cmd中执行以下命令

```plain
java -jar BurpSuitePath/burpsuite.jar
```

其中BurpSuitePath是burpsuite安装路径，burpsuite.jar是你的jar文件

通过学习，可以了解到将burpsuite的jar文件放在classpath目录下，直接执行

```plain
java burpsuite.jar
```

也可启动。

## 图形界面启动

如果使用的我提供的工具，双击burpsuite.bat即可运行（burpsuite.bat是中文界面，burpsuiteen.bat是英文界面）。**请确保.bat文件已经正确配置！**

其他，一般需先打开BurpSuiteLoader.jar或同类型文件的文件

请确保BurpSuiteLoader.jar文件在破解时，一直处于打开状态。

因为每次打开的License均不同。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637948131267-6926b59e-5d22-46ab-816b-02773439da65.png)

点击Run打开burpsuite本体。只能从Run处打开本体！

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637948372251-d1f00c3e-8223-4205-8331-36a97106ff87.png)

输入License，点击next。以下图源自网络，因笔者已经完成破解。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637948587922-062a6055-d3a2-49c5-b3f4-974819753fce.png)

选择Manual activation

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637948613204-c481fedf-173c-41df-9e34-1cd157d62b62.png)

将Request粘贴至Loader对应处

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637948657441-08c1c472-8fef-4daa-831d-2e5e902fe6bc.png)

再将Response粘贴至本体对应处

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637948698124-a1992cf1-3fba-407b-854c-eeddd7b1790f.png)

至此完成破解。

# BurpSuite简单使用

## Proxy简单使用

 Burp Suite代理工具是以拦截代理的方式，拦截所有通过代理的网络流量，如客户端的请求数 据、服务器端的返回信息等。Burp Suite主要拦截http和https协议的流量，通过拦截，Burp Suite以中间人的方式，可以对客户端请求数据、服务端返回做各种处理，以达到安全评估测 试的目的。 在日常工作中，我们最常用的web客户端就是的web浏览器，我们可以通过代理的设置，做到 对web浏览器的流量拦截，并对经过Burp Suite代理的流量数据进行处理。  

### Proxy设置

#### BurpSuite的Proxy设置

如图，在Proxy Listeners处设置拦截端口，是默认分配的。

同时注意，Intercept Cilent Requests如图默认设置。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637949247440-0bd8c016-2b17-4262-8ccd-125df401e417.png)

***在Intercept Cilent Requests处，如果把所有选项勾上，将捕获不到任何数据包***

#### FireFox

FireFox是测试常用的浏览器之一，因其强大的插件和简单的操作。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637947844031-6da1b29d-05b9-42c7-846d-2ad73779a8f9.png)

在设置中如图打开，新版有所不同

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637948987754-a7a78d8e-f46f-4bf3-a484-2eccfd83d38a.png)

对连接设置

***注意：在不使用代理处，删去127.0.0.1、localhost和本机ip***![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637949727991-2b50d9f6-8745-4355-ad62-3fe218eb49b7.png)

#### Google Chrome

Google Chrome的代理设置是打开Windows系统中的代理设置。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637950248508-4e6f9356-3e53-4ce7-a77c-0c5e6a0d3d84.png)

#### Microsoft Edge

与Google Chrome相同，会打开Windows系统设置中的代理。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637950397940-b7e4066c-0f98-4a3c-b113-e7ba14713c55.png)

### 认识Proxy界面

#### Intercept

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637957481468-31467720-02b7-4c59-a929-f63f012d3e05.png)

1. Forward 发送
   点击 "Forward "按钮，将请求发送到服务器。在大多数情况下，为了显示页面，浏览器会发出不止一个请求（图像等）。这个按钮方便操作每个后续的请求，然后把它转发到服务器上。当没有更多的请求需要转发时，浏览器应该已经完成了所有请求的URL的加载。
   	**每点击一次，发送一个信息。**
2. Drop 丢失
   点击"Drop"按钮，将当前拦截的信息丢失，不在发送到浏览器。

1. Intercept is on/off 拦截开启/关闭
   拦截功能是否打开，拦截所有通过Brupsuite Proxy的所有请求数据。
   	（通过Proxy设置中操作实现）
2. Action 对请求的操作
    除了将当前请求的消息传递到Spider、Scanner、 Repeater、Intruder、Sequencer、Decoder、Comparer组件外，还可以做一些请求消息的修 改，如改变GET或者POST请求方式、改变请求body的编码，同时也可以改变请求消息的拦 截设置，如不再拦截此主机的消息、不再拦截此IP地址的消息、不再拦截此种文件类型的消 息、不再拦截此目录的消息，也可以指定针对此消息拦截它的服务器端返回消息。  

1. Open browser 打开内置浏览器

#### HTTP history

所有流经Burp Proxy的消息，都会在http history记录下来，可以通过历史选项卡，查看传输的数据内容，对交互的数据进行测试和验证。同时，对于Intercept和HTTP history功能，都可以通过右击弹出菜单，发送到Burp的其他组件，如Spider、Scanner、 Repeater、Intruder、Sequencer、Decoder、Comparer、Extender，进行进一步的测试。  

#### WebSockets history
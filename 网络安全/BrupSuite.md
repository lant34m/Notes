# 前情提要

**本文使用的软件仅限于个人学习，严禁用于非法用途！**

其次，分享一个在用的Burpsuite版本——v2021.9.1。我的运行环境是Windows 11、Java17。

链接如下：http://pan.oft5mile.cn:10000/index.php/s/8BXo9Gsb3FcHQBj 密码：oftsmile



解压压缩包后如下：

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637945056474-1a18f00f-881e-454f-bde6-bb403567de41.png)

如若运行不了，建议从官网下载Burp Suite Professional v2021.9.1版本，并将burpsuite.bat、burpsuiteen.bat、burpSuite_cn.jar、BurpSuiteLoader.jar文件保留至新安装文件夹内。

其中将burpsuite.bat和burpsuiten.bat文件

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637945401505-b61ddca1-c257-43bb-9f4d-ac87973f2d78.png)

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

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637948131267-6926b59e-5d22-46ab-816b-02773439da65.png)

点击Run打开burpsuite本体。只能从Run处打开本体！

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637948372251-d1f00c3e-8223-4205-8331-36a97106ff87.png)

输入License，点击next。以下图源自网络，因笔者已经完成破解。

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637948587922-062a6055-d3a2-49c5-b3f4-974819753fce.png)

选择Manual activation

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637948613204-c481fedf-173c-41df-9e34-1cd157d62b62.png)

将Request粘贴至Loader对应处

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637948657441-08c1c472-8fef-4daa-831d-2e5e902fe6bc.png)

再将Response粘贴至本体对应处

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637948698124-a1992cf1-3fba-407b-854c-eeddd7b1790f.png)

至此完成破解。

## Proxy设置

 Burp Suite代理工具是以拦截代理的方式，拦截所有通过代理的网络流量，如客户端的请求数 据、服务器端的返回信息等。Burp Suite主要拦截http和https协议的流量，通过拦截，Burp Suite以中间人的方式，可以对客户端请求数据、服务端返回做各种处理，以达到安全评估测 试的目的。 在日常工作中，我们最常用的web客户端就是的web浏览器，我们可以通过代理的设置，做到 对web浏览器的流量拦截，并对经过Burp Suite代理的流量数据进行处理。  

### Proxy设置

#### BurpSuite的Proxy设置

如图，在Proxy Listeners处设置拦截端口，是默认分配的。

同时注意，Intercept Cilent Requests如图默认设置。

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637949247440-0bd8c016-2b17-4262-8ccd-125df401e417.png)

***在Intercept Cilent Requests处，如果把所有选项勾上，将捕获不到任何数据包***

#### FireFox

FireFox是测试常用的浏览器之一，因其强大的插件和简单的操作。

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637947844031-6da1b29d-05b9-42c7-846d-2ad73779a8f9.png)

在设置中如图打开，新版有所不同

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637948987754-a7a78d8e-f46f-4bf3-a484-2eccfd83d38a.png)

对连接设置

***注意：在不使用代理处，删去127.0.0.1、localhost和本机ip***![img](https://raw.githubusercontent.com/lant34m/pic/main/1637949727991-2b50d9f6-8745-4355-ad62-3fe218eb49b7.png)

#### Google Chrome

Google Chrome的代理设置是打开Windows系统中的代理设置。

![img](https://raw.githubusercontent.com/lant34m/pic/main/1637950248508-4e6f9356-3e53-4ce7-a77c-0c5e6a0d3d84.png)

#### Microsoft Edge

与Google Chrome相同，会打开Windows系统设置中的代理。

![img](https://cdn.nlark.com/yuque/0/2021/png/12376342/1637950397940-b7e4066c-0f98-4a3c-b113-e7ba14713c55.png)

## 基本使用

1. 在Burp中，进入 "代理">"拦截 "选项卡，并确保 "拦截 "按钮处于开启状态（如果 "拦截 "按钮处于关闭状态，则点击它来切换拦截状态）。

![image-20220316221416138](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221416138.png)

2. 在你的浏览器中，访问任何URL。浏览器将发送一个请求，但随后将被卡住，等待响应。
   在Burp中，Proxy>Inspector。你应该看到请求被显示出来供查看和编辑。使用Inspector工具来查看分析消息的不同方式。
   ![image-20220316221504329](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221504329.png)

3. 点击 “Forward "按钮，将请求发送到服务器上。在大多数情况下，为了显示页面，你的浏览器会发出不止一个请求（对于图像等）。看一下每个后续的请求，然后把它转发到服务器上。当没有更多的请求需要转发时，你的浏览器应该已经完成了加载你请求的URL。
   ![image-20220316221516681](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221516681.png)

4. 在Burp中，Proxy > Intercept上编辑请求。改变请求的第一行中的URL，请求一个不存在的URL。将该请求（以及任何后续的请求）转发给服务器，然后回到浏览器查看。尽管你的浏览器请求的URL和以前一样，你应该看到一个与正常请求不同的页面。这是因为在Burp中临时改变了发出的请求。
   ![image-20220316221550876](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221550876.png)
   ![image-20220316221557244](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221557244.png)

5. 在Burp中，进入Proxy > HTTP history标签。这包含一个所有通过代理的HTTP消息的表格。选择表中的一个项目，在消息编辑器中查看HTTP消息。如果你选择了你所修改的项目，你可以从下拉菜单中选择显示原始或编辑的请求。
   ![image-20220316221610698](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221610698.png)

6. 点击HTTP history中的一列标题，这将根据该列对表格的内容进行排序。再次点击同一标题，对该列进行反向排序，再点一次取消排序，按默认顺序显示项目。
   ![image-20220316221622420](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221622420.png)

7. 在HTTP history表格中，点击最左边一列的单元格，从下拉菜单中选择一种颜色。这将以选定的颜色突出显示该行。

   在评论栏内双击并输入Comment。你可以使用highlights和comment来标记HTTP history，识别感兴趣的项目。
   ![image-20220316221703199](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221703199.png)

8. 在历史表的上方有一个过滤栏。点击过滤栏，显示可用的选项，以各种方式改变过滤器的设置。当HTTP history项目较多时，你可以用过滤器来隐藏某些类型的项目，以帮助找到你正在寻找的项目。
   ![image-20220316221717684](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221717684.png)

9. 进入Proxy > Options标签，看看所有可用的选项。这些可以改变代理监听的行为，筛选过滤以确定代理拦截哪些请求和响应信息，对信息进行自动修改，或以其他方式控制代理的行为。
   ![image-20220316221727379](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221727379.png)

10. 在历史记录中选择一个项目，并显示上下文菜单（通常，通过右键点击鼠标）。上下文菜单中的选项与其他模块进行交互。
    ![image-20220316221736813](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221736813.png)

# 认识Proxy界面

## Intercept

### HTTP数据包编辑器

#### HTTP数据包编辑器面板

数据包编辑器在整个Burp中被用来查看和编辑HTTP请求和响应，以及WebSocket数据包。除了显示数据包本身之外，编辑器还包括大量的功能，以帮助你快速地进一步分析数据包，配合Burp的核心工作，并执行其他有用的任务。
![image-20220316221846031](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221846031.png)

##### 数据包编辑器 

HTTP请求和响应中的语法被自动着色，以突出关键的代码，如请求中的参数和响应中的HTML元素。JavaScript、JSON和CSS内容也是完全变色的。你可以在User options的HTTP Message Display中配置这种行为，并调整字体。

当语法着色被启用时，编辑器也会在适当的时候显示鼠标悬停的弹出窗口，显示语法项目的解码值。对于HTTP请求，弹出窗口执行URL解码，而对于响应，则执行HTML解码。![image-20220316221906374](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221906374.png)
![image-20220316221956078](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316221956078.png)

##### Inspector

可以点击Inspector右上方的问号查看详细文档。

- 快速查看和编辑HTTP和WebSocket数据包的特征。

- 查看你在编辑器中选择的参数、cookies或一个子字符串的完全解码值。

- 点击就可添加、删除和重新排序，而不是用Raw的HTTP语法工作。

- 以其解码的形式编辑数据。

- 切换用于发送单个请求的协议。
- 使用HTTP头和伪造头，而不被数据包编辑器的HTTP/1风格语法所束缚，这有利于测试特殊的HTTP/2。

![image-20220316222050493](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316222050493.png)

##### 数据包视图

Raw视图——在这个视图中，文本编辑器以其Raw形式显示完整的信息。文本编辑器包括各种有用的功能，包括语法分析、热键和文本搜索。你可以使用 "n "按钮来切换是否显示非打印字符。

Pretty视图——在这个视图中，你可以访问所有与Raw视图相同的功能。关键的区别是，文本编辑器的Pretty显示功能被启用。这大大改善了HTTP数据包中的数据、标记和代码的可读性，以标准化的缩进和换行来显示它们。

十六进制视图——该视图在十六进制编辑器中以原始形式显示信息。它将信息排列成16个字节的行，并显示每个字节的十六进制值。你可以在十六进制视图中编辑信息，你插入的任何数值都可以作为字符或以两位数的十六进制形式给出，从00到FF。例如：查看或编辑单个字符的码位、查看或插入非打印字符、插入或删除单个字节或字符串。

![image-20220316222217737](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316222217737.png)

#### 数据包控制

- Forward - 当你检查并编辑了信息后，点击Forward，将数据包发送到服务器或浏览器上。
- Drop - 使用此功能丢弃数据包，使其不被转发。
- Intercept is On/Off- 这个按钮用来切换所有拦截的开启和关闭。如果该按钮显示Intercept is on，那么数据包将被拦截或根据配置的HTTP和WebSocket数据包的拦截选项自动转发。如果按钮显示Intercept is off，那么所有的信息将被自动转发，不做拦截。
- Action - 这显示了一个可用的下拉菜单，可以对当前显示的数据包执行操作。
  除了将当前请求的消息传递到Spider、Scanner、 Repeater、Intruder、Sequencer、Decoder、Comparer组件外，还可以做一些请求消息的修 改，如改变GET或者POST请求方式、改变请求body的编码，同时也可以改变请求消息的拦 截设置，如不再拦截此主机的消息、不再拦截此IP地址的消息、不再拦截此种文件类型的消 息、不再拦截此目录的消息，也可以指定针对此消息拦截它的服务器端返回消息。  
- Open Browser – 可以打开BurpSuite内部自带浏览器，其中相关代理设置已被配置好。
- Comment - 这可以让你为特定的数据包表示，以便日后轻松识别。在Intercept中添加的评论将出现在HTTP history中的相关数据包中。

![image-20220316222353912](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316222353912.png)

### Action菜单

#### Action具体操作

你可以通过点击 “Action ”按钮来访问请求或响应的一系列上下文特定操作，亦或者，你可以右键数据包，从上下文菜单中选择一个操作。可用的操作取决于数据包的类型。

- 注意

该菜单还可能包括特定工具出现的额外选项(例如，在Repeater中，上下文菜单有粘贴URL作为请求和添加当前数据包到SiteMap的选项)。

#### Scan / Send to

你可以发送任何数据包，或数据包的选定部分，给其他Burp模块，以执行进一步的攻击或分析。在工具之间发送请求的能力构成了Burp操作的核心。

![image-20220316222824338](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316222824338.png)

#### Request in Browser

你可以用它来在你的浏览器中渲染所选的响应，以避免Burp内置的HTML渲染器的限制。当你选择这个选项时，Burp会给一个特定的URL，你可以把它粘贴到你的浏览器中，以呈现响应。由此产生的浏览器请求由Burp提供你所选择的确切的响应（该请求不会被转发到原始的Web服务器），然而该响应是由浏览器在最初请求的URL的背景下处理的。因此，响应中的相对链接将由您的浏览器正确处理。

![image-20220316222913835](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316222913835.png)

#### Engagement tools

你可以用它在你的浏览器中重新发出选定的请求（配置为使用当前的Burp作为其代理）。

- Find references- 你可以从所有Burp的工具中搜索相关资料。
- Dicover content- 这个功能可以帮助捕获爬取一些从可视区域或可以访问连接之外的内容。
- Schedule task- 这个功能可以用来创建在一定时间和间隔内执行的自动化任务。
- Genarate CSRF PoC – 这个功能可以创建在浏览器中能正常访问的HTML页面。通过生成的页面或链接可以实现CSRF攻击。

![image-20220316222957039](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316222957039.png)

#### Change ..

- Change request method
  对于任意请求，你可以在GET和POST之间自动切换请求方法，所有相关的参数在数据包中会重新排列。这个选项可以用来快速测试应用程序对参数位置的敏感度(即位置限制)。例如，绕过输入过滤或改变跨站脚本攻击语法格式。
- Change body encoding
  对于请求，你可以使用标准URL编码或将数据包以类型分为多部分。

![image-20220316223038244](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220316223038244.png)

#### Copy / Paste

- Copy URL
  复制当前的完整URL到剪贴板。

- Copy as curl command
  将一个可用于生成当前请求的curl命令复制到剪贴板上。

- Copy to / Paste from file
  选择一个文件并将当前信息的内容复制到该文件。可以与二进制数据包协作，当通过剪贴板复制可能会引起问题。拷贝的对象是选定的数据包内容，如果没有特指，则是整个信息。粘贴会取代选定的文本，如果没有选定，则会插入光标位置。
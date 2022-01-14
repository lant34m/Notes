# Zeus

malware——恶意软件、恶意代码

phishing——钓鱼

Zeus是一种特洛伊木马病毒，针对Windows操作系统。通常被用来对输入表单劫持或窃取浏览器中保存的银行相关信息，也和勒索病毒一同使用。

最主要的传播方式是驱动下载和网络钓鱼事件。

> Zeus除了窃取账户，还会将恶意代码注入到大多数当前运行的进程中，做了大量的进程钩子，给系统运行的安全性和稳定性带来隐患。

从用户角度，执行可疑可执行文件后，指针发生错误，多个工具发生错误，内存地址发生错误。

![image-20211231122809639](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231122809639.png)

![image-20211231122826839](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231122826839.png)

![image-20211231122841633](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231122841633.png)

![image-20211231122852447](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231122852447.png)

![image-20211231122903244](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231122903244.png)

![image-20211231122916335](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231122916335.png)

WerFault是Windwos操作系统自带的用于错误报告的程序。

使用Zbot查杀工具查杀后

![image-20211231121509909](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231121509909.png)

可见影响因素：

1. Files

2. Treads

   ![image-20211231123924980](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231123924980.png)

   ![image-20211231123556891](https://raw.githubusercontent.com/lant34m/pic/main/image-20211231123556891.png)

   （不知道存在什么问题，他人经验时是文件大小和占用空间显示0字节、文件创建时间、修改时间、访问时间通通是空）

   Zeus病毒程序通常在启动项上可以找到

   ![image-20211231123744435](C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20211231123744435.png)

   如上图userinit中的ntos.exe，路径是HKCU\SOFTWARE\Microsoft\Windows\Current\Run



对进程信息进行查看，winlogon.exe进程中的进程模块存在

![image-20211231124854771](C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20211231124854771.png)

ntdll.dll，其为Zeus病毒的附属进程、

svchost.exe的进程中同样存在。

通过专杀工具反推，其在进程explorer.exe中同样存在。

### ？？但理应存在的IAT勾子没有 ###






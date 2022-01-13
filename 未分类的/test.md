实操过程中出现的几个问题：

1. 打开虚拟机蓝屏无限重启
   解决办法：更新VMware Workstation至16 Pro
   
2. iso丢失问题
   把虚拟机设置中CD那一栏移除即可
   
3. 无法访问pte2003中资源
   首先用运行（Win+r)输入mmc打开控制台，点击文件—添加/删除管理单元—添加Internet 信息服务管理器，右键默认网站
   ![image-20211222021035240](C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20211222021035240.png)
   属性，将IP地址改为本机地址。
   
4. 对“当前标识(NT AUTHORITY\NETWORK SERVICE)没有对“C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\Temporary ASP.NET Files”的写访问权限。”解决方法
   在pet2003虚拟机中，用命令行执行“C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727\aspnet_regiss -i -enable”命令
   
5. 关于Centos ping不通的解决方法
   ![image-20211222105455232](C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20211222105455232.png)

   打开虚拟机-编辑-虚拟网络编辑器，
   将VMnet8如下图更改
   ![image-20211222105613325](C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20211222105613325.png)

   <img src="C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20211222105625006.png" alt="image-20211222105625006" style="zoom: 150%;" />

   
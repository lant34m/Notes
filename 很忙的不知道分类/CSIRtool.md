# CSIR

[2021考研——复习规划（408篇） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/122469340)

# 重点

[tide-emergency/yingji: 应急相关内容积累 (github.com)](https://github.com/tide-emergency/yingji)

[应急响应实战笔记_v0.1.pdf](file:///C:/Users/LanT34m/Downloads/应急响应实战笔记_v0.1.pdf)

[VirusTotal/vt-py：VirusTotal 的官方 Python 3 客户端库 (github.com)](https://github.com/VirusTotal/vt-py)

[VirusTotal - Api key - oftsmile](https://www.virustotal.com/gui/user/oftsmile/apikey)

[文件 (virustotal.com)](https://developers.virustotal.com/reference/files)

[快速入门 — vt-py 文档 (virustotal.github.io)](https://virustotal.github.io/vt-py/quickstart.html#get-information-about-a-file)

[The-Hacker-Playbook-3-Translation/[译\] 渗透测试实战第三版(红队版)3月19日更新.pdf at master · Snowming04/The-Hacker-Playbook-3-Translation (github.com)](https://github.com/Snowming04/The-Hacker-Playbook-3-Translation/blob/master/PDF/[译] 渗透测试实战第三版(红队版)3月19日更新.pdf)

## windwos

#### windwos启动项

步骤：

1. 启动目录
   - 打开启动目录：C:\\Users\\%s\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup
   - 将指定天数范围的文件打印出便于查找
2. 启动配置

```cmd
curl -X POST \https://www.virustotal.com/vtapi/v2/file/scan \-F apikey=0afa97ae1daec0de95c8aa60541322db7794fb9356ee4ecce650c4a5341e222c\-F file=D:\Universitystudies\CSIR\spider\test\test.py
```

## linux

rsa.com/en-us/blog/2017-04/why-malware-installers-use-tmp-files-and-the-temp-folder

# 2021-1-29 项目进度报告

> 下一个任务是各组汇报项目进度。要求：
> \1. 由组长指定一名成员，录制汇报视频
> 2.视频内容：（1）介绍组员和分工（2）介绍各组员工作的进展
> 3.录制电脑屏幕即可，不需要人出境，10分钟以内
> 4.录制视频的同学负责将视频上传到学习通，截止1月29日，每组传一份即可。如果视频太大需要压缩一下。

我是**IRidescent**组员，组长是董思源，负责项目的需求分析和编写代码；组员张忠广负责对软件功能进行测试；组员王金全负责对市场调研和项目进度监督。

现汇报项目进展，我们的项目是安全事件响应工具，期望达到对安全事件（包括但不限于病毒和Webshell）的发生，及时的通过数据分析确定攻击时间、查找攻击线索、梳理攻击过程、在一定程度上溯源的目的。

目前对Zeus病毒的危害、中度病状和查杀进行了全面剖析，下一步拟对勒索病毒进行剖析查杀。同时，积极复现最新安全漏洞包括但不限于Log4j和Polkit。

其中对应急事件案例采取以服务器为环境，手工入侵、上传病毒等方式模拟应急事件发生。

已成功编写查看服务器可疑账号可疑进程的Python脚本，专用于提供给有基础的运维人员。

对工具最终界面采取图形化易于使用，同时提供终端界面贡命令行服务器使用。

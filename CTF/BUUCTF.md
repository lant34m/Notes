# wireshark
黑客通过wireshark抓到管理员登陆网站的一段流量包（管理员的密码即是答案) 注意：得到的 flag 请包上 flag{} 提交

登陆网站的一段流量包，肯定是HTTP的请求，在过滤器输入POST过滤。

![image-20220118011958691](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118011958691.png)

可以看到一个email=flag的GET请求，尝试追踪TCP数据流可得

![image-20220118012112420](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118012112420.png)

ffb7567a1d4f4abdffdb54e022f8facd，解决

# 被嗅探的流量

某黑客潜入到某公司内网通过嗅探抓取了一段文件传输的数据，该数据也被该公司截获，你能帮该公司分析他抓取的到底是什么文件的数据吗？ 注意：得到的 flag 请包上 flag{} 提交

根据题目可知，文件传输数据被截获。继续使HTTP.REQUEST.METHOD="POST"过滤

![image-20220118013144372](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118013144372.png)

追踪TCP，划到最低端即可

![image-20220118013216813](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118013216813.png)

# 数据包中的线索

公安机关近期截获到某网络犯罪团伙在线交流的数据包，但无法分析出具体的交流内容，聪明的你能帮公安机关找到线索吗？ 注意：得到的 flag 请包上 flag{} 提交

继续使用HTTP.REQUEST过滤

![image-20220118013654592](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118013654592.png)

有个fenxi.php比较可疑，追踪TCP数据流试试。

很长的一段编码，因为是=结尾所有猜测是base64

![image-20220118014013678](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118014013678.png)

解出来是一串乱码，开头有JFIF字样，猜测应该是图片格式

使用Base64转图片网站得出flag

![image-20220118014200067](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118014200067.png)

# 被偷走的文件

一黑客入侵了某公司盗取了重要的机密文件，还好管理员记录了文件被盗走时的流量，请分析该流量，分析出该黑客盗走了什么文件。 注意：得到的 flag 请包上 flag{} 提交

浏览了下文件，有FTP传输了flag.rar

![image-20220118023140509](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118023140509.png)

右键追踪TCP数据流

![image-20220118023218507](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220118023218507.png)

使用源格式Raw保存为flag.rar

但是打开flag.rar需要密码，回去找

此时，使用

```
ip.dst==172.16.66.10
```

看看攻击者还偷了些什么

但是并没有发现什么信息，

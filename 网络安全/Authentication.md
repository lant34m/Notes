# Authentication vulnerabilities 认证漏洞

![image-20220115183814400](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115183814400.png)

认证是验证一个特定用户或客户身份的过程。

认证因素可以归结为：

1. 用户知道的内容：密码或安全问题的答案
2. 用户拥有的内容：手机或安全令牌之类的实物
3. 用户的行为方式：生物行为模式

认证机制依靠一系列技术验证因素中的一个或多个。

### 认证和授权的区别

认证是验证一个用户是不是所声明身份的过程，授权验证是验证一个用户是不是具有执行某项行为的权利。

### 认证漏洞的产生原因

1. 认证机制并不完善，不能完全阻止暴力破解的发生。
2. 失效的身份验证，认证实现中逻辑缺陷或错误编码验证会导致攻击者使用技巧绕过登陆。

### 认证漏洞的影响

攻击者绕过认证或暴力破解后，可以访问被攻击账户的所有数据和功能。如果用户权限很高，就可以获取对网站的控制权，同时可以访问内部设施。低权限的用户可能造成信息泄露或提供了利用其他漏洞的可能。

## 详解

### 密码登陆中的漏洞

#### 暴力破解

暴力破解指的是攻击者通过不断登陆，利用系统提供的错误显示信息，猜解用户的正确信息。

暴力破解可以分为完全猜解和不完全猜解。当攻击者对猜解信息毫无头绪时，通常使用巨大的密码字典进行暴力破解。通常情况下，攻击者可以利用一些基本的密码逻辑和收集到的用户信息，做出有一定依据的猜解。

##### 暴力破解用户名

用户名容易被猜解是因为可视化较高，甚至可以猜测到。

可以检查是否能在不登录情况下访问用户档案，或HTTP响应中是否有被泄露。

##### 暴力破解密码

密码破解的难度随密码的复杂程度有所不同，通常的网站会采取一定形式规范用户密码的设置（比如，规定最少密码位数、大小写和特殊字符）。

我们可以根据猜解用户行为方式使得暴力破解过程更便捷，比如通常不会使用随机字符组合方式创建密码。

### 用户名枚举

攻击者通过观察网站响应内容猜解用户名，通常发生在登录页面上。

在暴力破解时，应该注意以下的网站响应差异：

1. ==状态码==
   在暴力破解的猜解过程中，返回的HTTP状态码中，如果猜解返回的状态码是不同的，表明用户名可能是正确的。
   ==最佳解决方案是：网站始终返回相同的状态代码==
   ![image-20220115195522534](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115195522534.png)
2. 错误信息
   取决于用户名和密码的正确与否，返回的错误信息可能不同。
3. 响应时间
   当大多数请求都有相似的响应时间，有些请求响应与之不同，可能在后端发生了一些问题，是猜解正确的一种迹象。
   - ==注意事项==：当利用响应时间作为判断依据时
     ![image-20220115213935297](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220115213935297.png)
     在Burp中需要打开Response received和Response completed作为值比较。同时，username或password猜解的另一方需为较大的==字符值==（至少大于100)，才能分辨出存在的用户名。

### 有缺陷的防护措施

暴力破解必定涉及很多错误的猜解，防止暴力破解最常见的两种常见方法是：

1. 如果失败次数过多，锁定远程访问用户的权限
2. 如果IP地址进行过多的远程登陆尝试，阻止IP地址的访问
   待解决问题：
   ![image-20220116003327432](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116003327432.png)
   在Burpsuite的Intruder模块爆破时，理论上通过一个正确混搭一个猜解的方式可以绕过同IP多次暴力破解导致被封时间。但通过测试，在随机一定范围内会正常进行，之后就会被判断为同IP多次登陆失败。
   ==已解决==：
   通过利用Resource Pool并发数配置，在两个请求间人为的设置一个间隔时间，使得服务器响应彻底返回即可。

### 账户锁定相关

当满足某些可疑条件（如一定数量的登录失败）时锁定账户。服务器指示账户已锁定时，用户名可以被枚举猜解出来。

#### 绕过账户锁定保护的技巧

1. 构建一个足够小的密码字典，以达成不超过限制登陆次数
2. 使用凭证登陆。由一个网站数据泄露的凭证，攻击者使用一个凭证可能登陆很多使用同样凭证方式的网站。

### 用户限流

在短时间内尝试登陆请求次数过多，网站可能将IP地址限制登陆。

通常可以通过以下方式解封：

1. 管理员手动操作
2. 用户完成验证后解封

用户限流通常比锁定账户更有效，通常情况下避免了用户名猜解和DDOS攻击。

#### 例子

请求如下

![image-20220116021813790](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116021813790.png)

在Repeater构造如下请求即可

![image-20220116021724828](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116021724828.png)

返回302登录成功

![image-20220116021901587](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116021901587.png)

右键点击Show response in Browser

![image-20220116021944246](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116021944246.png)

成功利用漏洞

### HTTP基本认证

在HTTP认证中，客户端从服务器收到一个token。token由用户名和密码连接而成，并用Base64编码进行加密。这个token由浏览器存储和管理，浏览器会自动加入后续请求的认证内。如

```
Authorization: Basic base64(username:password)
```

但这并不安全，每次请求中不断重复发送用户的token，除非网站实现了HSTS，否则可以被中间人攻击截获。

其次，用户的token是完全静态的，很容易被暴力破解。

同时，被CSRF跨站请求伪造攻击。

### 多重身份验证中的漏洞

许多网站完全依赖于使用密码作为单因素验证身份，但验证生物特征不切实际，所以大多网站根据Something you know和Something you have进行双因素身份验证（2FA）。这通常需要用户输入密码和外设中的临时验证码（银行多有在使用）。

攻击者可能获得密码，但另一个验证因素被破解的情况少得多。但安全性高低只取决于实施的策略是否合理，实施不合理时可能被爆破或绕过。

电子邮件2FA并不属于多重身份验证，依旧只使用密码作为唯一因素验证。

#### 双因素认证令牌

验证码通常由用户从某种物理设备上读取。许多保密程度高、重视数据安全的网站为用户提供如RSA令牌等设备。

在一些网站使用短信验证码的方式验证，但容易被截获，若用户手机卡被攻击者获得则可以欺诈网站进行登录，同时也有可能被滥用于短信轰炸。

##### 如何绕过

用户提示输入密码后，跳转到另一个页面输入第二重身份验证。用户在密码输入之后，可能已经存在登陆的状态。

##### 例子

> This lab's two-factor authentication can be bypassed. You  have already obtained a valid username and password, but do not have  access to the user's 2FA verification code. To solve the lab, access  Carlos's account page.        
>
> - Your credentials: `wiener:peter` 		
> - Victim's credentials `carlos:montoya` 		

![image-20220116212512515](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116212512515.png)

通过正常手段登陆自己的账号后

![image-20220116212708531](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116212708531.png)

为正常登陆路径

登陆其他用户账号后不进行验证直接输入路径访问链接即可

#### 有逻辑缺陷的双因素验证

用户在完成初步登陆后，并没有充分验证是否完成第二重验证。

```
POST /login-steps/first HTTP/1.1
Host: vulnerable-website.com
...
username=carlos&password=qwerty
```

然后再第二重验证之前分配一个cookie

```
HTTP/1.1 200 OK
Set-Cookie: account=carlos

GET /login-steps/second HTTP/1.1
Cookie: account=carlos
```

在第二重验证时，以确定访问的账户

```
POST /login-steps/second HTTP/1.1
Host: vulnerable-website.com
Cookie: account=carlos
...
verification-code=123456
```

在这种情况下，cookie可以被攻击者改变，以达到访问其他人账户的目的。

```
POST /login-steps/second HTTP/1.1
Host: vulnerable-website.com
Cookie: account=victim-user
...
verification-code=123456
```

如果攻击者通过暴力破解或其他方式获得用户的账户密码时，可以根据这个逻辑漏洞登陆到任意账户。
## 链接

[www.cn-hee.cn/index.php?app=store&id=2%27](http://www.cn-hee.cn/index.php?app=store&id=2')

![image-20220116043601777](https://raw.githubusercontent.com/lant34m/pic/main/img/image-20220116043601777.png)

由此可得

- '被转义为\

- 数据库为Mysql

- 此处的语句为

  ```sql
  SELECT COUNT(DISTINCT goods_id) as c FROM ecm_cart WHERE session_id='0df314d6a60df49c531cf60c022ac394' AND store_id=2\'
  ```

- 系统是Windows，文件目录是

  ```
  E:\PHPnow-1.5.6.1428396605\htdocs\eccore\model\mysql.php
  ```

  


# 来学Python

> 以《Python Cookbook第三版》为参考书，以《Python语言程序设计基础第2版》作为课程教材使用学习。教材推荐使用Python3.x版本，我的版本是3.10.1。
> Python编程练习网站：[PythonTip-挑战Python](http://www.pythontip.com/coding/code_oj)

通常来说，我崇尚练一次顶看十次的习惯。笔记通篇将以练代学。

### 示例：温度转换

计算机通常需要六个步骤解决问题：

1. 分析问题
2. 划分边界
   - 明确输入输出数据
   - 数据处理的要求
3. 设计算法
4. 编写程序
5. 调试程序
6. 升级维护

```python
#coding:utf-8
TempStr = input("请输入带有符号的温度值: ")
if TempStr[-1] in ['F', 'f']:
    C = (eval(TempStr[0:-1]) - 32) / 1.8
    print("转换后的温度是{:.2f}C".format(C))
elif TempStr[-1] in ['C', 'c']:
    F = 1.8 * eval(TempStr[0:-1]) + 32
    print("转换后的温度是{:.2f}F".format(F))
else:
    print("输入格式错误")
    
结果是：
请输入带有符号的温度值: 82F
转换后的温度是27.78C

请输入带有符号的温度值: 27c
转换后的温度是80.60F
```

# 数据结构与算法

## 1.1将序列分解为单独的变量

```python
p = (4, 5)
x, y = p
print x
print y

print '\n'

data = ['ACME', 50, 91.1, (2012, 12, 21)]

name, share, price, date = data
print(name)
print(share)
print(price)
print(date)
print name, share, price, date

name, shares, price, (year, mon, day) = data
print year
print mon
print day
print (year, mon, day)
```

任何序列或可迭代对象都可以通过一个简单的赋值操作来分解为单独的变量。

```python
p = (4,5)
x,y,z = p

ValueErrorTraceback (most recent call last)
<ipython-input-3-0ee77b9f8b35> in <module>()
      1 p = (4,5)
----> 2 x,y,z = p
      3 

ValueError: need more than 2 values to unpack
```

## 1.2 从任意长度的可迭代对象中分解元素




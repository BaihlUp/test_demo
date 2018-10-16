# 运算符：
# in/not in
# ==、> 、< 、>= 、<= 、!= 、<>(不等于)、
#字符串操作方法

name="baihl"
print (name)
if "a" in name:    #not in操作
    print("OK")
else:
    print("Error")
var = "b" not in name
print(type(var))
print(var)

num = 1>=1
print(num)

a = 123
print(a.bit_length())  #转换成二进制的时候的最小宽度

print(name.capitalize()) #首字母大写

a = "123"
print(type(a), a)
print(type(int(a)), int(a))  #类型转换

num = "011"
print(int(num, base=16))  #表示num为base进制，输出转换成十进制

age = 3
print(age.bit_length())   #表示当前数字表示成二进制有几位

#字符串处理操作
strname = "BAIHLBAIHL"
print(strname.casefold())   #小写转换
print(strname.lower())      #小写转换
print(strname.center(20, "*"))   #字符居中，宽度20,第二个参数可选
print(strname.ljust(20,"*"))    #左对齐
print(strname.rjust(20,"*"))    #右对齐
print(strname.zfill(20))        #右对齐，使用0填充
print(strname.count("I"))   #子字符串的个数
print(strname.count("I",5)) #从第5个下标位置开始查找
print(strname.count("I",5,6))#设置查找的起始位置和结束位置
print(strname.endswith("I"))  #表示字符串以什么结尾，输出bool值
print(strname.startswith("B")) #表示字符串以什么开始

str1 = "    hello world "
print(str1.find("o"))        #在字符串中查找指定的字串，返回其下标，未找到返回-1
print(str1.index("o"))     #在字符串中查找指定的字串，返回其下标，未找到返回错误

test1 = "i am {name}, age {a}"
#print(test1.format(name="baihl", a=10))  #格式化输出
test2 = "i am {0}, age {1}"
#print(test2.format("baihl", 10))  #格式化输出
print(test1.format_map({'name':"baihl", 'a':10}))   #使用字典方式格式化

test3 = "baihl1992"
print(test3.isalnum())  #判断字符串中只包含数字或字符

test4 = "hello\tworld\tbaihl"
print(test4)
print(test4.expandtabs(6)) #表示以tab分割，每个tab加字符串的宽度为6
test4 = "username\tmail\tpasswd\nbaihl\tbaihl@qq.com\t123456\nhaoliang\thaoliang@qq.com\t123456\n"
print(test4.expandtabs(20))     #制作表格，每列为20宽度

test5 = "baihl白2"
print(test5.isalpha())  #判断字符串是否全是字符，中文也算字符

test6 = "123"
print(test6.isdecimal(), test6.isdigit())  #判断是否是数字
print(test6.isnumeric())            #判断是否是数字，可以判断中文的数字

test7 = "_\n"
print(test7.isidentifier()) #判断是否是字母、数字或下划线
print(test7.isprintable()) #是否包含不可见字符

test8 = "   "
print(test8.isspace()) #判断字符串是否全是空格

test9 = "Baihl Up li"
print(test9.istitle())  #判断是否是标题,标题表示字符串中的所有单词首字母大写
print(test9.title())    #转换成标题

test10 = "心梦无痕"
str1 = "_"
print(str1.join(test10))  #表示以字符串_分割字符
print(" ".join(test10))   #以空格分割

test11 = "Baihl"
print(test11.islower())    #判断是否全是小写
print(test11.lower())      #全部转换成小写
print(test11.isupper())     #判断是否全是大写
print(test11.upper())      #全部转换成大写
print(test11.swapcase())  #大小写转换，把字符串中的大写转成小写，小写转成大写

test12 = " \nalex "
print(test12.lstrip())    #删除左边的空格或左边的换行
print(test12.rstrip())    #删除右边的空格。。。
print(test12.strip())     #删除所有的空格。。。
print("baihl".lstrip("bax")) #从左开始匹配，把匹配到的最长字符删除,一次类推，输出"ihl"

test13 = str.maketrans("aeiou", "12345") #设置对应关系
test14 = "ajljljailjlou dlkjfdfillj"
new_test = test14.translate(test13)      #按照对应关系进行test14字符串的转换
print(new_test)

test15 = "absdfsnlkjsljlkj"
print(test15.partition("s"))   #指定以s字符从左开始分割字符串，只分割一次
print(test15.rpartition("s"))  #指定以s字符从右开始分割字符串，只分割一次
print(test15.split("s", 2))  #指定以s字符从左开始分割字符串，分割2次，如果没有第二个参数，默认全部分割，分割后s不包含在分割后的字符中
print(test15.rsplit("s", 2))

test16 = "ajf\nadfjadfjadf\nfajdfjj"
print(test16.splitlines())   #默认使用\n进行字符串分割，分割后的字符串中不包含\n
print(test16.splitlines(True))  #默认使用\n进行字符串分割，分割后的字符串中包含\n
print(test16.splitlines(False)) #同不带参数

test17 = "梦之痕"
print(len(test17))  #获取字符串的长度，输出3，（Python2中一个汉字是3，会输出9）

test18 = "alexalexalex"
print(test18.replace("ex", "bbb"))  #把字符串中指定的字串替换，默认把全部的替换
print(test18.replace("ex", "bbb", 2))  #把字符串中指定的字串替换，第三个参数指定替换其中的前几个
#注意：字符串一旦创建，不可修改，如果修改字符串，内存中会重新创建一个新的字符串

numb = range(100)
print(numb)
for num in numb:
    print(num, 1)
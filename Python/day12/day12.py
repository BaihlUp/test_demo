li = [11,22,33,["baihl",92], "liang"]
print(li)
for var in li:
    print(var)
print(li[1:3])
del li[1:3]
print(li)
li[1:3] = [1,3]
print(li)

#字符串转换成列表,数字不能转换成列表
test = "baihl"
print(list(test))

li = ["11","22","liang", "22"]
test1 = "".join(li)
print(test1)

#拷贝
v = li.copy();
print(v)
print(v.count("22")) #计算出现的次数
v.append([11,22])   #和extend的差异['11', '22', 'liang', '22', [11, 22]]
print(v)
#v.extend("baihl")   #['11', '22', 'liang', '22', 'b', 'a', 'i', 'h', 'l']
print(v)

#元组的一级元素不能被修改/删除/增加
tu = (111, "baihl", [(11,22)], "liang");
print(tu);
tu[2][0] = "hello"
print(tu);        #(111, 'baihl', ['hello'], 'liang')

a = "alex"
b = a.capitalize()
print(a)
print(b)
print(bin(123))  #转换成二进制

var = 5
print(var.bit_length())

test1 = "11"
print(int(test1, 2))
var =3
if var== 1:
    pass
elif var==2:
    print("baihl")
else:
    print("liang")
# a=range(100)
# print(a)
# for i in range(100):
#     print(i)
# i=1
# while i<100:
#     if i%2==0:
#         print(i)
#     i+=1

# var=sum(range(100))
# print(var)
j=1
sum=0
while j<100:
    if j%2==1:
        sum+=j
    else:
        sum-=j
    j
print(sum)

a="alex"
b=a.capitalize()
print(a)
print(b)
n1=5
print(n1.bit_length())

name =" aleX"
print(name.strip())
print(name.startswith("al"))
print(name.endswith("X"))
print(name.replace("l","p"))
print(name.split("l"))
print(name.partition("l"))
print(name.upper())
print(name.lower())
print(name[1])
print(name[:3])
print(name[-2:])
print(name.find("e"))
print(len(name))
print(name[:-1])
# for i in name:
#     print(i)

# li="alexericrain"
# print("_".join(li))
# li=["alex", "eric", "rain"]
# print("_".join(li))

# # li="敬爱可亲的{name}, 我喜欢在{position}地方干{what}"
# # name=input("名字：")
# # position=input("地点：")
# # what=input("干什么：")
# # print(li.format_map({'name':name, 'position':position, 'what':what}))
#
# name="苍老师"
# what="东京热"
# var=input("请输入：")
# if name in var:
#     var = var.replace(name,"***")
# if what in var:
#     var = var.replace(what,"***")
# print(var)
#
# name=""
# while name!="q" or name!="Q":
#     user=input("用户名：")
#     passwd=input("密码：")
#     mail=input("邮箱：")

# content=input("请输入内容：")
# v1,v2 = content.split("+")
# print(int(v1),int(v2))
# content=input(">>>")
# num=0
# ch=0
# for i in content:
#     if i.isdigit() :
#         num+=1
#     if i.isalpha():
#         ch+=1
# print(num,ch)

# var=""
# while True:
#     user=input(">>>")
#     if user == "q" or user == "Q":
#         break
#     passwd=input(">>>")
#     mail=input(">>>")
#     template="{0}\t{1}\t{2}\n"
#     test=template.format(user,passwd,mail)
#     var+=test
# print(var.expandtabs(20))
#
# a = "123"
# print(int(a))       #转换成数字
# b = 5
# print(b.bit_length())   #返回表示数字时占用的最少位数



# replace/find/join/strip/startswith/split/upper/lower/format
# tempalte = "i am {name}, age : {age}"
# # v = tempalte.format(name='alex',age=19)
# v = tempalte.format(**{"name": 'alex','age': 19})
# print(v)

# test1=[11,22,33]
# test1.append(["baihl","liang"])
# print(test1)
# test2=[11,22,33]
# test2.extend(["baihl","liang"])
# print(test2)
#
# test2="liang"
# var=["1111","liang"]
# print(tuple(var))
# print(list(test2))
#
# dic={
#     "k1":"v1",
#     "k2":"v2"
# }
# print(dic.get("k1"))
#     print(dic.get("k3"))


info = {
    "k1": 18,
    2: True,
    "k3": [
        11,
        [],
        (),
        22,
        33,
        {
            'kk1': 'vv1',
            'kk2': 'vv2',
            'kk3': (11,22),
        }
    ],
    "k4": (11,22,33,44)
}
for item in info:
    print(item)          #输出所有的key

for item in info.keys():
    print(item)             #输出所有的key

for item in info.values():
    print(item)              #输出所有的key

for item in info.keys():
    print(item,info[item])    #输出所有的key和value

for k,v in info.items():
    print(k,v)                  #输出所有的key和value

# #True 1  False 0
# info ={
#     "k1": 'asdf',
#     True: "123",
#     # [11,22]: 123
#     (11,22): 123,
#     # {'k1':' v1'}: 123
#
# }
# print(info)

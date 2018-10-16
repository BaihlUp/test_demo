name = "baihl"
print(id(name))  # id指向内存地址

s = "baihl"
print(set(s))
s = set(s)
# add
# remove
# pop
# discard()

p_s = {"alex", "baihl", "liang"}
l_s = {"alex", "bhl"}
l_s.add("hello")  # 向集合中添加元素
print(l_s)

# #l_s.clear()
# print(l_s)       #清空集合
#
# l_s1=l_s.copy()
# print(l_s1)
# p_s={"alex","baihl","liang"}
# l_s={"alex","bhl"}
# #l_s.pop()
# print(l_s)
# l_s.remove("alex")   #如果删除不存在的元素，会报错
# print(l_s)
# l_s.discard("hello")    #删除不存在的元素，不会操作
# print(l_s)
p_s = {"alex", "baihl", "liang"}
l_s = {"alex", "bhl"}
# print(p_s & l_s)
# print(p_s.intersection(l_s))
# print(p_s | l_s)
# print(p_s.union(l_s))
# print(p_s - l_s)
# print(p_s.difference(l_s))
print(p_s ^ l_s)
print(p_s.symmetric_difference(l_s))
print(l_s.symmetric_difference(p_s))

s1 = {1,2,3}
s2 = {1,2,3,4,5}
print(s1.issubset(s2))      #s1是s2的子集，返回True
print(s2.issuperset(s1))    #s2是s1的父集，返回True

print(s1)
s1.update({"baihl":"liang"})
print(s1)
# s1.add(("hello","world"))   #不支持list、字典等可变类型
# print(s1)

s=frozenset('hello')
print(s)

p_s = {"alex", "baihl", "liang"}
l_s = {"alex", "bhl"}
# print(p_s & l_s)
# print(p_s.intersection(l_s))
# l_s.intersection_update(p_s)
# # print(l_s)
# print(p_s | l_s)
# print(p_s.union(l_s))
# print(p_s - l_s)
# print(p_s.difference(l_s))
# p_s.difference_update(l_s)
# print(p_s)
# print(p_s ^ l_s)
# print(p_s.symmetric_difference(l_s))
# print(l_s.symmetric_difference(p_s))
p_s.symmetric_difference_update(l_s)
print(p_s)

for i in p_s:
    print(i)

s = frozenset("hello")
print(s)

def test(x,y,z):#x=1,y=2,z=3
    print(x)
    print(y)
    print(z)

#位置参数，必须一一对应，缺一不行多一也不行
test(1,2,3)

#关键字参数，无须一一对应，缺一不行多一也不行
test(y=1,x=3,z=4)

#位置参数必须在关键字参数左边
# test(1,y=2,3)#报错
# test(1,3,y=2)#报错
# test(1,3,z=2)
test(1,3,z=2)#报错
# test(z=2,1,3)#报错

# def handle(x,type='mysql'):
#     print(x)
#     print(type)
# handle('hello')
# handle('hello',type='sqlite')
# handle('hello','sqlite')

#参数组：**字典 *列表
def test(x,*args):
    print(x)
    print(args)
test(1)
test(1,2,3,4,5)
test(1,{'name':'alex'})
test(1,['x','y','z'])
test(1,*['x','y','z'])
test(1,*('x','y','z'))

def test(x,**kwargs):
    print(x)
    print(kwargs)
test(1,y=2,z=3)
#test(1,1,2,2,2,2,2,y=2,z=3)
#test(1,y=2,z=3,z=3)#会报错 ：一个参数不能传两个值

def test(x,*args,**kwargs):
    print(x)
    print(args,args[-1])
    print(kwargs,kwargs.get('y'))
#test(1,1,2,1,1,11,1,x=1,y=2,z=3) #报错
test(1,1,2,1,1,11,1,y=2,z=3)
test(1,*[1,2,3],**{'y':1})

name='lhf'
def change_name():
    global name
    name='baihl'
    print('change_name',name)
# 如果函数的内容无global关键字，
#   - 有声明局部变量
#         NAME = ["产品经理","廖波湿"]
#         def qupengfei():
#             NAME = "自己"
#             print('我要搞', NAME)
#         qupengfei()
  # - 无声明局部变量
# NAME = ["baihl","hello"]
# def qupengfei():
#     NAME.append('xxxxx')
#     print('input', NAME)
# qupengfei()
# print(NAME)

name='baihl'
def hello():
    name="hello"
    def world():
        nonlocal name
        name="world"
    world()
    print(name)
print(name)
hello()
print(name)



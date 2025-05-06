#定义一个栈
def CreateStack(n):
    ls=[0]*n
    P=0
    return ls,P

def Pop(ls):
    global P
    if P==0:
        print("堆栈已空！")
        return -1
    else:
        a=ls[P]
        ls[P]=0
        P-=1
        return a
def Push(ls,a):
    global P
    if P>len(ls)-1:
        print("堆栈已满！")
        return -1
    else:
        P+=1
        ls[P]=a
def Priority(i):
    if i in ["+","-"]:
        return 1
    elif i in ["*",'/']:
        return 2
    else:
        return 3
ls1,P=CreateStack(10)
#Input
print("请输入一个中缀表达式：")
ls1=list(input())

#Logic
ls2,P=CreateStack(len(ls1))
for i in range(0,len(ls1)):
    if ls2[i] in ["0",'1','2','3','4','5','6','7','8','9']:
        print(i,end="")
    elif ls2[i] =="(":
        Push(ls2,i)
    elif ls2[i]==")":
        while(ls2[P]!="("):
            a=Pop(ls2)
            print(a,end="")
    elif ls2[i] in ["+",'-','*','/']:
        if Priority(ls2[i])>Priority(ls2[P]):
            Push(ls2,i)
        else:
            while(Priority(ls2[i])<=Priority(ls2[P])) or P!=0:
                a=Pop(ls2)
                print(a,end="")
            Push(ls2,i)
while(P!=0):
    a=Pop(ls2)
    print(a,end="")





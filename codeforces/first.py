t=input()
for j in range(t):
    a,b,x,y=map(int,input().split())
    ans=0
    if(a>=b):
        print(0)
    elif(x==1 and y==1):
        print(-1)
    else:
        if(y>=x):
            while(b>a):
                b=b//y
                ans=ans+1
        else:
            while(b>a):
                a=a*x
                ans=ans+1 
    print(ans)                   




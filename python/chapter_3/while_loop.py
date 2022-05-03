#sum of n natural numbers
n=int(input("enter the number\n"))
sum=0
i=1
while i<=n:
    sum=sum+i
    i=i+1
print(sum)

#sum of digits

sum=0
while n:
    sum=sum+n%10
    n=n//10
print(sum)    

# count of each character in string

name=input("Enter your name\n")
l=len(name)
i=0
while i<l:
    j=0
    k=0
    while j<i:
        if name[j]==name[i]:
            k=k+1
        j=j+1    
    if k==0:
        print(f"count of {name[i]} = {name.count(name[i])}")
    i=i+1            
def bubble(a,n):
    for j in range(0,n):
        for i in range(0,n-1):
          if(a[i]>a[i+1]):
                a[i],a[i+1]=a[i+1],a[i]
    return a
                  
l=[]
n = int(input("Enter Count : ").strip())
for i in range(n):
    a = int(input("Enter number: "))
    l.append(a)
    
print(bubble(l,n))

"""
Input
Enter Count : 5
Enter number: 3
Enter number: 89
Enter number: 5
Enter number: 1
Enter number: 0

Output
[0, 1, 3, 5, 89]
"""

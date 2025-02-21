a = input("")
a = a.split()
n = int(a[0])
y= int(a[1])

lista=[]
resta=1
for a in range(y):
    aux=int(input(""))
    if aux not in lista:
        lista.append(aux)
    else:
        resta+=1
i=0
sum=0
flag=False
for a in range(n):
    if a not in lista:
        print(a)
    else:
        sum+=1

print("Mario got ",sum," of the dangerous obstacles.")
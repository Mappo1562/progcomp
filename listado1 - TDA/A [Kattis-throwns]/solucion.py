# lectura n,k
entrada=input("")
n, k = entrada.split()
n=int(n) # numero estudiantes
k=int(k) # numero instrucciones
estudiantes=list(range(n))

# pasar instrucciones a una lista
entrada=input("")
entrada=entrada.split()


i=0 # n de instruccion
j=0 # pos en la lista de instrucciones
pos=0
undo=0
pila=[]

while i<k:
    instruccion=entrada[j]

    if undo:
        c=int(instruccion)
        undo=0
        while c>0:
            instruccion=pila.pop()
            pos=(-instruccion+pos)%n
            c-=1

    elif instruccion == "undo":
        i-=1
        undo=1
        
    else:
        pila.append(int(instruccion))
        pos=(int(instruccion)+pos)%n

    i+=1
    j+=1

print(pos)
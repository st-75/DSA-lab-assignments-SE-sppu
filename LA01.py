'''
Consider telephone book database on N clients. Make use of hash table implmentation to 
quickly look up clients telephone no. and compare them using no. of comparisons required to 
find a set of telephone numbers.
'''
size=10
hashtable=[]
hashtable1=[]

for i in range(size):
    hashtable.append(0)
    hashtable1.append(0)

def hash_v(num):    #linear probing
    index=num%size
    if(hashtable[index]==0):
        hashtable[index] = num
    else:   
        while(hashtable[index]!=0): 
            index+=1
    hashtable[index] = num
    

def quadratic_v(num):
    index1=num%size
    if(hashtable1[index1]==0):
        hashtable1[index1]=num
    else:
        for k in range(size):
            t=(hashtable1[index1]+k*k)%size
            if(hashtable1[t]==0):

                hashtable1[t]=num
                break

def find(num,hash_table):
    index2=num%size
    if(hash_table[index2]==num):
        print("Found",num)
    elif(hash_table[index2]!=num):
        while(hash_table[index2]!=0):
            index2+=1
            if(hash_table[index2]==num):
                print("Found",num)
                break
            else:
                print("Not found",num)
                break
    else:
        print("Invalid syntax")
        
        
def main():
    while True:
        print("1.Linear probing.")
        print("2.Quadratic probing.")
        print("3.Find element.")
        print("4.Exit.")

        cd=int(input("Enter choice: "))

        if cd==1:
            n=int(input("Enter total elements "))
            for j in range(n):
                h=int(input("Enter numbers "))
                hash_v(h)
                print("Hashtable using linear probing is : ",hashtable)

        elif cd==2:
            m=int(input("Enter total elements "))
            for j in range(m):
                q=int(input("Enter phone numbers "))
                quadratic_v(q)
                print("Hashtable using quadratic probing is : ",hashtable1)

        elif cd==3:
            n=int(input("Enter number to be found "))
            find(n,hashtable)

        elif cd==4:
            print("End of Program")
            break
        else:
            print("Enter a valid choice")
main()
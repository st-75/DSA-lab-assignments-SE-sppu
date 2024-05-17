'''
Implement all functions of a dictionary (ADT) using hashing and handle
collisions using chaining with /without replacement.
Data : Set of (key, value) pairs , keys are mapped to values, Keys must be
comparable, Keys must be unique. Standard Operations : Inset(key, value), Find
(key), Delete (key)
'''
#Hashing using Dictionary

size = 10
hash_table = {}

def addList(dict, size):
    for i in range(size):
        dict[i] = []
    return dict

def insert_lst(n, key, val, dict):
    lst = []
    idx = val % n
    lst += [key, val]
    dict[idx].append(lst)
    return dict

def delete_key(key, dict):
    for i in dict:
        for j in dict[i]:
            if key == j[0]:
                dict[i].remove(j)
    return dict

def find_key(key, dict):
    for i in dict:
        for j in dict[i]:
            if j[0] == key:
                return j

dict = addList(hash_table, size)

def main():
  while True :
    print("Dictionary Implementation ")
    print("1. Insert an element ")
    print("2. Delete an element ")
    print("3. Finding a key ")
    print("4. Exit")
    choice = int(input("Enter the choice : "))

    if choice == 1:
        key = input("Enter the key : ")
        val = int(input("Enter the data in array : "))
        arr = insert_lst(size, key, val, dict)
        print(arr)

    elif choice == 2:
        key = input("Enter the key to delete : ")
        print(delete_key(key, dict))

    elif choice == 3:
        key = input("Enter the key to Find : ")
        print(find_key(key, dict))

    elif choice > 4:
        print("Invalid input !!!")

    else:
        break

main()



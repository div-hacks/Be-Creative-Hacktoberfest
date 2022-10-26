import random

x = int(input("Enter Number Of Players : "))

br = []

for i in range(0, x):
    z = input("Enter Name : ")
    br.append(z)

print("\nThe Entered List Is : \n")
print(br)

y = random.randint(0,x)

print("\nBanker's Roulette Chooses "+br[y]+" To Pay The Bill!!")
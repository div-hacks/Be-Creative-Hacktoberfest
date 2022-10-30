#Password Generator Project
import random
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("Welcome to the PyPassword Generator!")
nr_letters= int(input("How many letters would you like in your password?\n")) 
nr_symbols = int(input(f"How many symbols would you like?\n"))
nr_numbers = int(input(f"How many numbers would you like?\n"))

password=""

for x in range(0,nr_letters):
                                             # we can also do this alternatively by using choice func.
    ltr=random.randint(0,len(letters)-1)     # ltr=random.choice(letters)
    password+=letters[ltr]                   # password+=ltr or password+=random.choice(letters)

for x in range(0,nr_numbers):
    num=random.randint(0,len(numbers)-1)
    password+=numbers[num]

for x in range(0,nr_symbols):
    sym=random.randint(0,len(symbols)-1)
    password+=symbols[sym]

password=list(password)
random.shuffle(password)
pass_shuffle=password

password=""
for item in pass_shuffle:
    password+=item

print(password)

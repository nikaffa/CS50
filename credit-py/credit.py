# credit 
from cs50 import get_int, sys

while True:
    card_number = get_int("Credit card: ")
    if card_number > 0:
        break
    
# 1. calculate checksum
card = card_number
sum_odd = 0
sum_even = 0
checksum = 0

while (card > 0):
    # calculate sum of odd numbers. ALL DIVISIONS MUST BE CONVERTED TO INT!!! (otherviwe results're floats)
    odd = card % 10
    sum_odd = sum_odd + odd
    card = int(card / 10)
        
    # calculate sum of even numbers
    even = card % 10
    even = even * 2
    even_dig1 = even % 10
    even_dig2 = int(even / 10)
    sum_even = sum_even + even_dig1 + even_dig2
    card = int(card / 10)

checksum = int(sum_odd + sum_even)

if (checksum % 10 != 0):
    print("INVALID")
    sys.exit(1)

# 2.check the length of the card
card_length = card_number
i = 0
while (card_length > 0):
    card_length = int(card_length / 10)
    i += 1

if (i != 15 and i != 13 and i != 16):
    print("INVALID")
    sys.exit(2)

# 3.check the card's starting digits
card_first = card_number
while (card_first > 100):
    card_first = int(card_first / 10)
        
if (card_first == 34 or card_first == 37):
    print("AMEX")
elif (card_first >= 51 and card_first <= 55):
    print("MASTERCARD")
elif (int(card_first / 10) == 4):
    print("VISA")
else:
    print("INVALID")
    sys.exit(3)
    

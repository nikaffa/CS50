from cs50 import get_float

while True:
    change = get_float("Change in dollars: ")
    if change >= 0:
        break

cents = round(change * 100)

coins = 0
while cents > 0:
    if (cents >= 25):
        cents = cents - 25
    elif (cents >= 10):
        cents = cents - 10
    elif (cents >= 5):
        cents = cents - 5
    elif (cents >= 1):
        cents = cents - 1
    coins += 1
        
print(f"Number of coins: {coins}")


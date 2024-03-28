from art import logo
MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 5000,
    "milk": 2000,
    "coffee": 500,
}
profit = 0


def check_money():
    """Counts how much money user has inserted"""
    print("Please insert coins.")
    balance = 0
    balance += int(input("How many quarters?: ")) * 0.25
    balance += int(input("How many dimes?: ")) * 0.10
    balance += int(input("How many nickles?: ")) * 0.05
    balance += int(input("How many pennies?: ")) * 0.01
    return balance


def is_transaction_successful(money_inserted, drink_cost):
    """Checks if user inserted enough money into machine and sums up profits"""
    if money_inserted >= drink_cost:
        change = round(money_inserted - drink_cost, 2)
        global profit
        profit += drink_cost
        print(f"Your change ${change}")
        return True
    else:
        print("Sorry, not enough money. Here is your refund.")
        return False


def is_ingredients_sufficient(drink_ingredients):
    """Checks if there is enough resources for a certain drink"""
    for item in drink_ingredients:
        if resources[item] >= drink_ingredients[item]:
            return True
        else:
            print("Not enough ingredients in machine. We are sorry. Hope you come back later:)")
            return False


def make_coffe(drink_ingredients):
    """Subtracts values of resources and makes a delicious coffee"""
    for item in drink_ingredients:
        resources[item] -= drink_ingredients[item]
    print(f"Here is your {choice}☕️. Enjoy!!!")

print(logo)

while 1:
    choice = input("What would you like? (espresso/latte/cappuccino): ").lower()
    if choice == "report":
        print(f"Water: {resources['water']}ml")
        print(f"Milk: {resources['milk']}ml")
        print(f"Coffee: {resources['coffee']}g")
        print(f"Money: ${profit}")
    elif choice == "off":
        exit()
    elif choice == list(MENU.keys())[0] or choice == list(MENU.keys())[1] or choice == list(MENU.keys())[2]:
        drink = MENU[choice]
        drink_ingredients = drink['ingredients']
        if is_ingredients_sufficient(drink_ingredients):
            money_inserted = check_money()
            drink_cost = drink['cost']
            if is_transaction_successful(money_inserted, drink_cost):
                make_coffe(drink_ingredients)
    else:
        print("Sorry, we do not have what you are looking for. Try again.")



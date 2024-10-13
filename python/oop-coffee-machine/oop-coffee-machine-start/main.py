from menu import Menu, MenuItem
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine

menu = Menu()
money_machine = MoneyMachine()
coffe_maker = CoffeeMaker()

is_on = True
while is_on:
    order_name = input(f"What would you like? ({menu.get_items()}): ")
    if order_name == "off":
        is_on = False
    elif order_name == "report":
        coffe_maker.report()
        money_machine.report()
    else:
        order = menu.find_drink(order_name)
        if coffe_maker.is_resource_sufficient(order):
            if money_machine.make_payment(order.cost):
                coffe_maker.make_coffee(order)



import turtle
from turtle import Turtle, Screen
import random

is_race_on = False
screen = Screen()
screen.setup(width=500, height=400)
user_bet = screen.textinput(title="Make your bet", prompt="Which turtle will win the race? Enter a color: ")
color = ["red", "yellow", "orange", "purple", "blue", "green"]
y_pos = -100.0
all_turtles = []

for turtle_id in range(0, 5):
    new_turtle = Turtle(shape="turtle")
    new_turtle.color(color[turtle_id])
    new_turtle.penup()
    new_turtle.setposition(-230.0, y_pos)
    y_pos += 50
    all_turtles.append(new_turtle)

if user_bet:
    is_race_on = True

while is_race_on:

    for turtle in all_turtles:
        turtle.forward(random.randint(0, 12))
        if turtle.xcor() > 225:
            winning_color = turtle.pencolor()
            if winning_color == user_bet:
                print(f"You,ve won! The {winning_color} turtle is the winner!")
            else:
                print(f"You've lost! The {winning_color} turtle won.")
            is_race_on = False


screen.exitonclick()

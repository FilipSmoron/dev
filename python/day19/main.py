from turtle import Turtle, Screen

pablo = Turtle()
screen = Screen()


def move_forwards():
    pablo.forward(10)


def move_backwards():
    pablo.backward(10)


def turn_left():
    pablo.setheading(pablo.heading() + 10)


def turn_right():
    pablo.setheading(pablo.heading() - 10)


def clear_screen():
    pablo.penup()
    pablo.home()
    pablo.clear()
    pablo.pendown()


screen.listen()
screen.onkey(move_forwards, "w")
screen.onkey(move_backwards, "s")
screen.onkey(turn_left, "a")
screen.onkey(turn_right, "d")
screen.onkey(clear_screen, "c")
screen.exitonclick()
from turtle import Turtle, Screen
import random
pablo = Turtle()
pablo.shape("turtle")
pablo.color("DarkOliveGreen")

# for _ in range(15):
#     pablo.forward(10)
#     pablo.penup()
#     pablo.forward(10)
#     pablo.pendown()


def random_color():
    R = random.random()
    B = random.random()
    G = random.random()
    pablo.color(R, G, B)


def draw_shape(num_sides):
    angle = 360 / num_sides
    for _ in range(num_sides):
        pablo.forward(100)
        pablo.right(angle)
    random_color()


# for shape_side_n in range(3,11):
#     draw_shape(shape_side_n)


pablo.speed("fastest")
pablo.pensize(1)
directions = [0, 90, 180, 270]

# for _ in range(200):
#     pablo.forward(25)
#     pablo.setheading(random.choice(directions))
#     random_color()


def draw_spirograph(size_of_gap):
    for _ in range(360 // size_of_gap):
        pablo.circle(100)
        pablo.setheading(pablo.heading() + size_of_gap)
        random_color()


# draw_spirograph(5)


screen = Screen()
screen.exitonclick()

# import colorgram
#
# rgb_colors = []
# colors = colorgram.extract('image.jpg', 30)
# for color in colors:
#     r = color.rgb.r
#     g = color.rgb.g
#     b = color.rgb.b
#     rgb_colors.append((r, g, b))
#
# print(rgb_colors)

import turtle as t
import random

color_list = [(220, 153, 106), (132, 171, 196), (224, 71, 88), (216, 130, 149), (24, 119, 152), (241, 208, 97), (120, 177, 149), (38, 119, 84), (19, 166, 204), (219, 84, 76), (140, 86, 61), (130, 83, 102), (175, 185, 216), (21, 169, 124), (160, 210, 166), (174, 155, 73), (239, 159, 173), (3, 96, 115), (240, 164, 150), (54, 59, 93), (148, 209, 222), (97, 127, 178), (236, 215, 11), (38, 56, 77), (33, 87, 52), (74, 79, 41)]


hirst = t.Turtle()
t.colormode(255)

hirst.penup()
hirst.hideturtle()

x_pos = -400.00
y_pos = -300.00
for _ in range(14):
    hirst.setposition(x_pos, y_pos)
    for _ in range(16):
        random_color = random.choice(color_list)
        hirst.dot(20, random_color)
        hirst.forward(50)
    y_pos += 50


screen = t.Screen()
screen.bgcolor(246, 247, 247)
screen.exitonclick()
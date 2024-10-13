rows_1 = 9
rows_2 = 1
for i in range(9):
    print(rows_1 * " " + rows_2 * "*")
    rows_1 -= 1
    rows_2 += 2
    
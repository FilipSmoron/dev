with open("Input/Letters/starting_letter.txt", mode="r") as f:
    letter = f.read()
#    print(letter)

with open("Input/Names/invited_names.txt", mode="r") as f:
    names = f.readlines()
#    print(names)

for name in names:
    stripped_name = name.strip("\n")
    with open(f"Output/ReadyToSend/letter_for_{stripped_name}.txt", mode="w") as f:
        f.write(letter.replace("[name]", stripped_name))

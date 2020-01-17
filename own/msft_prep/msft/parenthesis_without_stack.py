string = "(afafafafafadf)((aefafafafafeaf()()afafa()(afaefa)))()()"

counter = 0

for i, char in enumerate(string):
    if char == '(':
        counter += 1
    elif char == ')':
        counter -= 1
    if counter < 0:
        break

if counter == 0:
    print("Good string!")
else:
    print("Bad string!")

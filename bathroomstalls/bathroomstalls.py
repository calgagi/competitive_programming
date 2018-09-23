file = open("C-small-practice-1.in", "r");

line = file.read();

tcs = line.split('\n');

for x in tcs:
    # Get numbers
    sp = x.split(" ");
    stalls = int(sp[0]);
    print(stalls);

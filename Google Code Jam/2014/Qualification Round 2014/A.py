T = int(input())
for _ in range(T):
    a1 = int(input()) - 1
    n1 = [input() for i in range(4)]
    a2 = int(input()) - 1
    n2 = [input() for i in range(4)]

    n1 = [int(x) for x in n1[a1].strip().split()]
    n2 = [int(x) for x in n2[a2].strip().split()]

    counter, answer = 0, 0
    for x in n1:
        if x in n2:
            counter += 1
            answer = x
    output = "Case #%d: " % (_ + 1)
    if counter == 0:
        output += "Volunteer cheated!"
    elif counter == 1:
        output += str(answer)
    else:
        output += "Bad magician!"
    print(output)
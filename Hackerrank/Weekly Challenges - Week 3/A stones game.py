import math
import sys
A = [-1] * 34
def getAnswer(i, j):
    if i - j <= 1:
        return 2 ** (i - 2)
    return 2 ** (i - 1) - (2 ** j - 1)
for SG in range(2, 34):    
        flag = True
        for i in range(2, SG):
            for j in range(1, i + 1):
                if 1 ^ (i - j) ^ i ^ SG == 0:
                    A[SG] = getAnswer(i, i - j)
                    flag = False
                    break
            if not flag:
                break
                
T = int(input())
for line in sys.stdin:
    N = int(line)
    if N % 2 == 1:
        print(1)
    else:
        SG = int(math.log2(N)) + 1        
        if A[SG] == -1:
            print(2 ** (SG - 1) - 1)
        else:
            print(A[SG])
import string

str1 = input()
ansDict = []
i = 0

for alpha in string.ascii_lowercase:
    count = str1.lower().count(alpha)
    ansDict.append(count)

dict2 = list(reversed(sorted(ansDict)))

if dict2[0] == dict2[1]:
    print("?")
else:
    print(string.ascii_lowercase[ansDict.index(max(ansDict))].upper())

N = int(input())
dictionary = {}
for i in range(N):
    name = input()
    if name in dictionary :
        dictionary[name] += 1
    else:
        dictionary[name] = 1

max_dict = max(dictionary.values())

best_seller = []

for key, value in dictionary.items():
    if value == max_dict:
        best_seller.append(key)

print(sorted(best_seller)[0])

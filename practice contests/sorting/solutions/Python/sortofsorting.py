def sort_of_sort(names):
    n = len(names)
    for i in range(n):
        for j in range(0, n-i-1):
            if names[j][:2] > names[j+1][:2]:
                names[j], names[j+1] = names[j+1], names[j]
    return names

while True:
    n = int(input())
    if n == 0:
        break
    names = [input() for k in range(n)]
    sorted_names = sort_of_sort(names)
    print('\n'.join(sorted_names))
    print()
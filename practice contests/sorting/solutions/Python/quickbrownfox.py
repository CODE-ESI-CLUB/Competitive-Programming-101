def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        mini = i
        for j in range(i + 1, n):
            if arr[j] < arr[mini]:
                mini = j
        arr[i], arr[mini] = arr[mini], arr[i]
    return arr
n = int(input())
for i in range(n):
    phrase = input()
    alphabet = set("abcdefghijklmnopqrstuvwxyz")
    letters = set(char.lower() for char in phrase if char.isalpha())
    missing = list(alphabet - letters)
    if not missing:
        print("pangram")
    else:
        missing_sorted = selection_sort(missing)
        print(f"missing {''.join(missing_sorted)}")
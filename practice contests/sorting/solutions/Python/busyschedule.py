def converter(s):
    h, min_apm = s.split(':')
    min, t = min_apm.split()
    h = int(h)
    min = int(min)
    if t == 'a.m.':
        if h == 12:
            h = 0
    else:
        if h != 12:
            h += 12
    return h * 100 + min

def sort_time(times):
    n = len(times)
    for i in range(n-1):
        for j in range(n-i-1):
            if converter(times[j]) > converter(times[j+1]):
                times[j], times[j+1] = times[j+1], times[j]
    return times

results = []
while True:
    n = int(input())
    if n == 0:
        break
    app = []
    for _ in range(n):
        app.append(input())
    sorted_app = sort_time(app)
    results.append('\n'.join(sorted_app))
print('\n\n'.join(results))
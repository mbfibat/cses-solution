import requests
import sys
r = requests.get('https://cses.fi/problemset/').text

pos = 0;
f = open('Readme.md', 'w')
sys.stdout = f

print('| Name'.ljust(75) + '| Solution'.ljust(46) + '|')
print('| ' + '-'*72 + ' | ' + '-'*43 + ' |')
while True:
    st = r.find('<a href="/problemset/task/', pos);
    if st == -1:
        break
    ed = r.find('</a>', st);
    id = r[st + len('<a href="/problemset/task/') : st + len('<a href="/problemset/task/') + 4]
    name = r[st + len('<a href="/problemset/task/') + 6 : ed]
    space = '%20'
    print(('| [%s](https://cses.fi/problemset/task/%s)' % (name, id)).ljust(75) + '| [%s.cpp](./Solutions/CSES%s%s/main.cpp)'.ljust(42) %(id, space, id) + '|')

    pos = ed;
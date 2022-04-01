s = input().strip()
x = int(input().strip())
if (s=="ABC" and x<2000) or (s=="ARC" and x<2800) or (s=="AGC" and x>=1200):
    print('yes')
else:
    print('no')
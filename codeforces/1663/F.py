s = input().strip()
words = ["","","","the","","buffy","slayer","vampire"]
target = words[len(s)]

if target=="":
    print("none")
else:
    ans = ""
    for i in range(len(s)):
        a = ord(s[i])-ord('a')
        b = ord(target[i])-ord('a')
        ans += chr((a+b)%26 + ord('a'))
    print(ans)
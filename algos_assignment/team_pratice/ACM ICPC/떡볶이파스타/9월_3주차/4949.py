while True:
    a = input()
    if a==".":
        break
    stack = []
    hi = 1
    for i in a:
        if i=='(' or i=='[':
            stack.append(i)

        elif i==')':
            if stack and stack[-1]=='(':
                stack.pop()
            else:
                hi = 0
                break

        elif i==']':
            if stack and stack[-1]=='[':
                stack.pop()
            else:
                hi = 0
                break

    print("yes" if hi and not(stack) else "no")
            

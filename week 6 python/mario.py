number = int(input('Height:'))

for x in range(1,number+1):
    for y in range(number - x):
        print(' ', end = '')
        
    for s in range(x):
        print('*', end = '')

    print(' ', end = '')
    for s1 in range(x):
        print('*', end = '')

    print('\r')

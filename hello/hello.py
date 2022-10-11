#!/usr/bin/python

if __name__ == '__main__':
    print('hello world')
    a = 120
    print(bytes(a))
    print(str(a))

    print(bin(a))
    print('%c' % a)
    print(chr(a))

    b = 'x'

    print(ord(b))

    lists = [1,2,5,8,7,3,4,9]
    print(lists.sort())
    print(lists)
    lists = lists[1:-1]
    print(lists)
    print(sum(lists), len(lists))
    print(sum(lists) / len(lists))

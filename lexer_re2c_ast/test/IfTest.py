# ******************************************
# * File: IfTest.py
# * A test program for if statement
# ******************************************

x = input("Enter a number: ")
y = input("Enter another number : ")

if x == y:
    print 'X is equal to Y'
    x = y + 1
    print x
elif x < y:
    print 'X is less than Y'
    y = x + 10
    print y
else:
    print 'X is not equal to Y'
    print "Ni modo bishop"
    y = x + y
    print y
#!/usr/bin/python
# -*- coding: UTF-8 -*-

'''
multiline comment
'''

f = open("p.txt","r+")
print(f.tell())
#position of file
f.seek(2,0)
print(f.tell())

#read file
f.seek(0,0)
str = f.readline()
print(str)

str = f.readlines()
print(str)

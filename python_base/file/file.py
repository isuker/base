#!/usr/bin/python
# -*- coding: UTF-8 -*-

'''
multiline comment
'''

f = open("p.txt","r+")

#position of file
f.seek(2.0)
print(f.tell())
f.seek(1.1)
print(f.tell())
f.seek(4.2)
print(f.tell())
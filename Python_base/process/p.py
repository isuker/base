import multiprocessing
import time
import os

def  work1(x):
	global x
	while 1:
		print("I am the first")
		pass
	return 
def work2(x):
	while 1:
		print("I am the second")
		pass
	return


if __name__ == '__main__':
	p1 = multiprocessing.Process(target=work1,args=())
	p2 = multiprocessing.Process(target=work2,args=())
	p1.start()
	p2.start()
	print("p1.pid " , p1.pid)
	print ("p1.name", p1.name)                                                     
	print ("p1.is_alive:",  p1.is_alive())
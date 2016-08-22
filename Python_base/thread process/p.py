import multiprocessing
import os

def  work1():
	print("I am the first")
	return 
def work2():
	print("I am the second")
	return
if __name__ == '__main__':
	p1 = multiprocessing.Process(target=work1,args=())
	p2 = multiprocessing.Process(target=work2,args=())
	p1.start()
	p2.start()
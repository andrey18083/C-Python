class Stack():
	def __init__(self):
		self.s=list()

	def push(self, element):
		self.s.append(element)
		print('ok')

	def pop(self):
		if len(self.s)==0:
			print('error')
		else:
			print(self.s.pop())

	def back(self):
		if len(self.s)==0:
			print('error')
		else:
			print(self.s[-1])

	def size(self):
		print(len(self.s))

	def clear(self):
		self.s=[]
		print('ok')


	def exit(self):
		print('bye')

a=Stack()

while True:
	c=input().split()
	if c[0]=="push":
		a.push(int(c[1]))
	elif c[0]=="pop":
		a.pop()
	elif c[0]=="back":
		a.back()
	elif c[0]=="size":
		a.size()
	elif c[0]=="clear":
		a.clear()
	elif c[0]=="exit":
		print("bye")
		break
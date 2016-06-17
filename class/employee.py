#!/usr/bin/python

class Employee:
	'''Common base class for all employee'''
	empCount = 0

	def __init__(self, name, salary):
		self.name = name
		self.salary = salary
		Employee.empCount += 1
	def displayCount(self):
		print 'Total count is %d'%Employee.empCount
	def displayEmployee(self):
		print 'name:', self.name, 'salary:', self.salary


"First empolyee"
emp1 = Employee("Zara", 2000)
"Second employee"
emp2 = Employee("Siri", 5000)

emp1.displayEmployee()
emp2.displayEmployee()
emp2.displayCount()
print "Count:%d"%Employee.empCount

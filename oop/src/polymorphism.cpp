#include <iostream>

using namespace std;

class Calculator {
public:
	int add(int a, int b) {
		return a + b;
	}

	double add(double a, double b) {
		return a + b;
	}

	int add(int a, int b, int c) {
		return a + b + c;
	}
};

int main() {
	Calculator c;
	cout << c.add(1, 2) << endl;
	cout << c.add(3.3, 4.2) << endl;
	cout << c.add(1, 2, 3) << endl;
	return 0;
}
class Employee {
private:
	string name;
	int salary;

public:
	Employee(string name, int salary) {
		this->name = name;
		this->salary = salary;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	int getSalary() {
		return salary;
	}

	void setSalary(int salary) {
		this->salary = salary;
	}

	void display() {
		cout << "Name: " << getName() << endl;
		cout << "Salary: " << getSalary() << endl;
	}
};

class Manager : Employee {
private:
	int bonus;
public:
	Manager(string name, int salary, int bonus) : Employee(name, salary) {
		this->bonus = bonus;
	}

	int getBonus() {
		return bonus;
	}

	void setBonus(int bonus) {
		this->bonus = bonus;
	}

	int getSalary() {
		return Employee::getSalary() + bonus;
	}
};

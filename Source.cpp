#include <iostream>
#include <string>

#define random(a,b) a+rand()%(b+1-a)
using namespace std;
int gen_rand(int a, int b) {
	return rand() % (b + 1 - a) + a;
}


class User {
private:
	string name;
	string phone_number;
public:
	User(string name, string phone_number) {
		this->name = name;
		this->phone_number = phone_number;
	}
	void showInfo() {
		cout << "name " << name << " : " << "phone_number " << phone_number << endl;
	}
};

class Phonebook {
private:
	//int number;
	User** users = nullptr;

	int countUsers = 0;
public:
	Phonebook() {
		this->countUsers = countUsers;
		this->users = users;
	}

	int getCountUsers() {
		return countUsers;
	}
	void addUser(User* user) {
		User** buf = new User * [countUsers + 1];
		for (int i = 0; i < countUsers; i++) {
			buf[i] = users[i];

		}
		buf[countUsers++] = user;
		delete[]users;
		users = buf;
	}

	void removeStudent(int index) {
		User** buf = new User * [countUsers + 1];
		for (int i = 0; i < countUsers; i++) {
			buf[i] = users[i];

		}
		for (int i = index + 1; i < countUsers; i++) {
			buf[i - 1] = users[i];
		}

		delete[]users;
		users = buf;
		countUsers--;

	}
	void showInfo() {
		for (int i = 0; i < countUsers; i++) {
			users[i]->showInfo();
		}
	}
};

int main() {
	srand(time(NULL));
	Phonebook Phonebook;
	int countUsers = 7;
	const int count = 4;
	string names[count] = { "Vlad", "Alex", "Peater", "Sam" };
	string number[count] = { "79655024455", "79810315590", "79653634806", "78633203776" };
	for (int i = 0; i < countUsers; i++) {
		Phonebook.addUser(new User(names[gen_rand(0, 3)], number[0,3]));;
	}
	Phonebook.showInfo();
	Phonebook.removeUser(3);
	Phonebook.showInfo();
	
	//Phonebook.addUser(new User(names[4], number[4]));
	
}

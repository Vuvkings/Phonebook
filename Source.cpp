#include <iostream>
using namespace std;

class User {
private:
	string name;
	int phone_number;
public:
	User(string name, int phone_number) {
		this->name = name;
		this->phone_number = phone_number;
	}
	void showInfo() {
		cout << "name" << name << " : " << "phone_number" << phone_number << endl;
	}
};

class Phonebook {
private:
	//int number;
	User** users = nullptr;
	int countUsers = 0;
public:
	Phonebook() {
		//this->number = number;
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
		countUsers--;

	}
	void showInfo() {
		for (int i = 0; i < countUsers; i++) {
			cout << users[i] << endl;
		}
	}
};

int main() {
	string* usname = new string[4]{"Vlad", "Alex", "Peater", "Sam"};
	string* number = new string[4]{ "79655024", "79810315590", "79653634806", "78633203776" };
	
	Phonebook Numb;
}
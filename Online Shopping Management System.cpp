#include<string>
#include<iostream>
#include<fstream>
#include <iomanip>
#include <sstream>
#include<limits>
#include <ctime>

using namespace std;

string rightPad(string const& str, int n, char paddedChar = ' ')
{
	ostringstream ss;
	ss << left << setfill(paddedChar) << setw(n) << str;
	return ss.str();
}

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(const string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == string::npos) ? "" : s.substr(0, end + 1);
}

int isSubstring(string s1, string s2)
{
	int M = s1.length();
	int N = s2.length();

	/* A loop to slide pat[] one
	   by one */
	for (int i = 0; i <= N - M; i++)
	{
		int j;

		/* For current index i, check for
		   pattern match */
		for (j = 0; j < M; j++)
			if (s2[i + j] != s1[j])
				break;

		if (j == M)
			return i;
	}
	return -1;
}

string trim(const string& s) {
	return rtrim(ltrim(s));
}

bool is_digits(const string& str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}

class AdminManager {
public:
	string fileName = "Manager.txt"; 
	string role = "manager"; 
	string username, password, name, address, id, email, contact;
	int age;
	void addAccount() {
		fstream file1;
		fstream file2;
		int option = 1;
		do {
			
			file1.open(fileName, ios::app);
			cout << "===================================================================" << endl;
			cout << rightPad(" ", 20) << "Creating account for " << role << endl << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "Please enter the " << role << "'s username: ";
			while (getline(cin >> ws, username)) {
				if (username.length() > 20) {
					cout << endl;
					cout << "Your username shouldn't be longer than 20 characters!" << endl;
					cout << "Please enter the " << role << "'s username: ";
					continue;
				}
				else {
					username = rightPad(username, 20);
					cout << endl;
					break;
				}
			}
			cout << "Please enter the " << role << "'s password: ";
			while (getline(cin >> ws, password)) {
				if (password.length() > 20) {
					cout << endl;
					cout << "Your password shouldn't be longer than 20 characters!" << endl;
					cout << "Please enter the " << role << "'s password: ";
					continue;
				}
				else {
					password = rightPad(password, 20);
					cout << endl;
					break;
				}
			}
			cout << "Please enter the " << role << "'s name: ";
			while (getline(cin >> ws, name)) {
				if (name.length() > 40) {
					cout << endl;
					cout << "Your name shouldn't be longer than 40 characters!" << endl;
					cout << "Please enter the " << role << "'s name: ";
					continue;
				}
				else {
					name = rightPad(name, 40);
					cout << endl;
					break;
				}
			}
			cout << "Please enter the " << role << "'s age: "; 
			while (!(cin >> age)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.  Please enter a valid input: ";
			}
			string ageString = to_string(age);
			ageString = rightPad(ageString, 20); 
			cout << endl;
			cout << "Please enter the " << role << "'s address: ";
			while (getline(cin >> ws, address)) {
				if (address.length() > 50) {
					cout << endl;
					cout << "Your address shouldn't be longer than 50 characters!" << endl;
					cout << "Please enter the " << role << "'s address: ";
					continue;
				}
				else {
					address = rightPad(address, 50);
					cout << endl;
					break;
				}
			}
			string infoLine;
			
			cout << "Please enter the " << role << "'s ID: ";
			while (getline(cin >> ws, id)) {
				file2.open(fileName, ios::in);
				int unique = 1;
				if (id.length() > 20) {
					cout << endl;
					cout << "Your ID shouldn't be longer than 20 characters!" << endl;
					cout << "Please enter the " << role << "'s ID: ";
					file2.close();
					continue;
				}
				else {
					while (getline(file2, infoLine)) {
						string givenId = trim(infoLine.substr(150, 20));
						
						if (id == givenId) {
							cout << "The ID that you enter must be unique for each " << role << endl;
							cout << "Please enter the " << role << "'s ID: ";
							unique = 0;
							continue;
						}
					}
					file2.close();
					if (unique == 1) {
						id = rightPad(id, 20);
						cout << endl;
						break;
					}
				}
			}
			cout << "Please enter the " << role << "'s email: ";
			while (getline(cin >> ws, email)) {
				if (email.length() > 30) {
					cout << endl;
					cout << "Your email shouldn't be longer than 30 characters!" << endl;
					cout << "Please enter the " << role << "'s email: ";
					continue;
				}
				else {
					email = rightPad(email, 30);
					cout << endl;
					break;
				}
			}
			cout << "Please enter the " << role << "'s contact number: ";
			while (getline(cin >> ws, contact)) {
				if (contact.length() > 20) {
					cout << endl;
					cout << "Your contact number shouldn't be longer than 20 characters!" << endl;
					cout << "Please enter the " << role << "'s contact number : ";
					continue;
				}
				else {
					contact = rightPad(contact, 20);
					cout << endl;
					break;
				}
			}
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			file1 << username << password << name << ageString << address << id << email <<contact << endl;
			file1.close();
			cout << "Would you like to continue creating " << role << " accounts?[Press 1 to continue]: ";
			while (!(cin >> option)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.  Please enter an integer: ";
			}
		} while (option == 1);
	}

	void deleteAccount() {
		fstream file1;
		fstream temp;
		cout << "===================================================================" << endl;
		file1.open(fileName, ios::in);
		temp.open("temp.txt", ios::out);
		if (!file1) {
			cout << rightPad(" ", 20) << "Deleting account for " << role << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No " <<role << " exist yet. Please create one" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string usernameDelete;
			if (file1.is_open()) {
				file1.close();
				temp.close();
				int flag1 = 1;
				do {
					file1.open(fileName, ios::in);
					temp.open("temp.txt", ios::app); 
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Deleting account for " << role << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					cout << "Enter the " << role << " username that you want to delete: ";
					getline(cin >> ws, usernameDelete);
					usernameDelete = trim(usernameDelete);
					cout << endl;

					while (getline(file1, infoLine)) {
						string givenUsername = trim(infoLine.substr(0, 20));
						if (givenUsername == usernameDelete) {
							isPresent = true;
							cout << usernameDelete << " has been deleted from database" << endl << endl;
						}
						else {
							temp << infoLine << endl;
							
						}

					}

					file1.close();
					temp.close();
					if (fileName == "Manager.txt") {
						remove("Manager.txt");
						rename("temp.txt", "Manager.txt");
					}
					else {
						remove("Customer.txt");
						rename("temp.txt", "Customer.txt");
					}
					if (!isPresent) {
						cout << "There isn't a match between the " << role << " username in the database with the username that you've inputted" << endl;
					}
					
					cout << "Would you like to continue deleting accounts? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	void editAccount() {
		fstream file1;
		fstream file2;
		fstream temp;
		file1.open(fileName, ios::in);
		temp.open("temp.txt", ios::out);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Editing account for " << role << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No " << role << " exist yet. Please create one" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string usernameEdit;
			if (file1.is_open()) {
				file1.close();
				temp.close();
				int flag1 = 1;
				do {
					cout << rightPad(" ", 20) << "Editing account for " << role << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					file1.open(fileName, ios::in);
					temp.open("temp.txt", ios::out);
					bool isPresent = false;
					cout << "Enter the " << role << " username that you want to edit: ";
					getline(cin >> ws, usernameEdit);
					cout << endl;

					string editLine;
					while (getline(file1, infoLine)) {
						string givenUsername = trim(infoLine.substr(0, 20));
						string idOfUser = trim(infoLine.substr(150, 20));
						if (givenUsername == usernameEdit) {
							isPresent = true;
							cout << "Editing " << role << " details" << endl << endl;

							cout << "Please enter the " << role << "'s username: ";
							while (getline(cin >> ws, username)) {
								file2.open(fileName, ios::in);
								int unique = 1;
								if (username.length() > 20) {
									cout << endl;
									cout << "Your username shouldn't be longer than 20 characters!" << endl;
									cout << "Please enter the " << role << "'s username: ";
									file2.close();
									continue;
								}
								else {
									while (getline(file2, editLine)) {
										string roleUsername = trim(editLine.substr(0, 20));
										if (username == roleUsername) {
											continue;
										}
										else if (username == givenUsername) {
											cout << "The username that you enter must be unique for each " << role << endl;
											cout << "Please enter the " << role << "'s username: ";
											unique = 0;
											continue;
										}
									}
									file2.close();
									if (unique == 1) {
										username = rightPad(username, 20);
										cout << endl;
										break;
									}
								}
							}
							cout << "Please enter the " << role << "'s password: ";
							while (getline(cin >> ws, password)) {
								if (password.length() > 20) {
									cout << endl;
									cout << "Your password shouldn't be longer than 20 characters!" << endl;
									cout << "Please enter the " << role << "'s password: ";
									continue;
								}
								else {
									password = rightPad(password, 20);
									cout << endl;
									break;
								}
							}
							cout << "Please enter the " << role << "'s name: ";
							while (getline(cin >> ws, name)) {
								if (name.length() > 40) {
									cout << endl;
									cout << "Your name shouldn't be longer than 40 characters!" << endl;
									cout << "Please enter the " << role << "'s name: ";
									continue;
								}
								else {
									name = rightPad(name, 40);
									cout << endl;
									break;
								}
							}
							cout << "Please enter the " << role << "'s age: "; 
							while (!(cin >> age)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter a valid input: ";
							}
							string ageString = to_string(age);
							ageString = rightPad(ageString, 20);
							cout << endl;
							cout << "Please enter the " << role << "'s address: ";
							while (getline(cin >> ws, address)) {
								if (address.length() > 50) {
									cout << endl;
									cout << "Your address shouldn't be longer than 50 characters!" << endl;
									cout << "Please enter the " << role << "'s address: ";
									continue;
								}
								else {
									address = rightPad(address, 50);
									cout << endl;
									break;
								}
							}
							
							cout << "Please enter the " << role << "'s ID: ";
							while (getline(cin >> ws, id)) {
								file2.open(fileName, ios::in);
								int unique = 1;
								if (id.length() > 20) {
									cout << endl;
									cout << "Your ID shouldn't be longer than 20 characters!" << endl;
									cout << "Please enter the " << role << "'s ID: ";
									file2.close();
									continue;
								}
								else {
									while (getline(file2, editLine)) {
										string givenId = trim(editLine.substr(150, 20));
										if (givenId == idOfUser) {
											continue;
										}
										else if (id == givenId) {
											cout << "The ID that you enter must be unique for each " << role << endl;
											cout << "Please enter the " << role << "'s ID: ";
											unique = 0;
											continue;
										}
									}
									file2.close();
									if (unique == 1) {
										id = rightPad(id, 20);
										cout << endl;
										break;
									}
								}
							}

							cout << "Please enter the " << role << "'s email: ";
							while (getline(cin >> ws, email)) {
								if (email.length() > 30) {
									cout << endl;
									cout << "Your email shouldn't be longer than 30 characters!" << endl;
									cout << "Please enter the " << role << "'s email: ";
									continue;
								}
								else {
									email = rightPad(email, 30);
									cout << endl;
									break;
								}
							}
							cout << "Please enter the " << role << "'s contact number: ";
							while (getline(cin >> ws, contact)) {
								if (contact.length() > 20) {
									cout << endl;
									cout << "Your contact number shouldn't be longer than 20 characters!" << endl;
									cout << "Please enter the " << role << "'s contact number : ";
									continue;
								}
								else {
									contact = rightPad(contact, 20);
									cout << endl;
									break;
								}
							}
							temp << username << password << name << ageString << address << id << email << contact << endl;
						}
						else {
							temp << infoLine << endl;
						}

					}


					file1.close();
					temp.close();
					if (fileName == "Manager.txt") {
						remove("Manager.txt");
						rename("temp.txt", "Manager.txt");
					}
					else {
						remove("Customer.txt");
						rename("temp.txt", "Customer.txt");
					}
					if (!isPresent) {
						cout << "There isn't a match between the " << role << " username in the database with the username that you've inputted" << endl;
					}
					cout << "Would you like to continue editing accounts? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	void searchAccount() {
		fstream file1;
		file1.open(fileName, ios::in);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Searching account for " << role << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No " << role << " exist yet. Please create one" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string usernameSearch;
			string username, password, name, age, address, id, email, contact;
			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					file1.open(fileName, ios::in);
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Searching account for " << role << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					cout << "Enter the " << role << " username or ID that you want to search: ";
					getline(cin >> ws, usernameSearch);
					cout << endl;
					for (int i = 0; i < 207; i++) {
						cout << "-";
					}
					cout << endl;

					cout << rightPad("Username", 20) <<"|" << rightPad("Name", 40) << "|" << rightPad("Age", 20) << "|" << rightPad("Address", 50) << "|" << rightPad("ID", 20) << "|" << rightPad("E-mail", 30) << "|" << rightPad("Contact Number", 20) << "|" << endl;
					for (int i = 0; i < 207; i++) {
						cout << "-";
					}
					cout << endl;
	

					while (getline(file1, infoLine)) {
						string givenUsername = trim(infoLine.substr(0, 20));
						string givenId = trim(infoLine.substr(150, 20));
						if (isSubstring(usernameSearch, givenUsername) != -1 || isSubstring(usernameSearch,givenId )!= -1) {
							isPresent = true;
							username = infoLine.substr(0, 20);
							password = infoLine.substr(20, 20);
							name = infoLine.substr(40, 40);
							age = infoLine.substr(80, 20);
							address = infoLine.substr(100, 50);
							id = infoLine.substr(150, 20);
							email = infoLine.substr(170, 30);
							contact = infoLine.substr(200, 20);
							cout<< username << "|" << name << "|" << age << "|" << address << "|" << id << "|" << email << "|" << contact << "|" << endl;
						}

					}
					if (!isPresent) {
						cout << rightPad("N/A", 20) << "|" << rightPad("N/A", 40) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 50) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 30) << "|" << rightPad("N/A", 20) << "|" << endl;
					}
					for (int i = 0; i < 207; i++) {
						cout << "-";
					}
					cout << endl;
					file1.close();
					if (!isPresent) {
						cout << endl << "There isn't a match between the " << role << " username/ID in the database with the username/ID that you've inputted" << endl << endl;
					}
					cout << "Would you like to continue viewing the details of accounts? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}
	void displayAllAccounts() {
		fstream file1;
		file1.open(fileName, ios::in);
		cout << "===================================================================" << endl;
		cout << rightPad(" ", 12) << "Displaying all accounts for " << role << endl;
		for (int i = 0; i < 50; i++) {
			cout << "-";
		}
		cout << endl;
		if (!file1) {
			cout << "No " << role << " exist yet. Please create one" << endl;
		}
		else {
			string infoLine;
			string usernameSearch;
			string username, password, name, age, address, id, email, contact;
			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					file1.open(fileName, ios::in);
					int counter = 1;
					for (int i = 0; i < 213; i++) {
						cout << "-";
					}
					cout << endl;
					cout << rightPad("No", 5) << "|" << rightPad("Username", 20) <<"|" << rightPad("Name", 40) << "|" << rightPad("Age", 20) << "|" << rightPad("Address", 50) << "|" << rightPad("ID", 20) << "|" << rightPad("E-mail", 30) << "|" << rightPad("Contact Number", 20) << "|" << endl;
					for (int i = 0; i < 213; i++) {
						cout << "-";
					}
					cout << endl;
					while (getline(file1, infoLine)) {

						username = infoLine.substr(0, 20);
						password = infoLine.substr(20, 20);
						name = infoLine.substr(40, 40);
						age = infoLine.substr(80, 20);
						address = infoLine.substr(100, 50);
						id = infoLine.substr(150, 20);
						email = infoLine.substr(170, 30);
						contact = infoLine.substr(200, 20);
						string counterString = to_string(counter);
						cout << rightPad(counterString, 5) << "|" << username << "|" << name <<"|"  << age << "|" << address <<"|" << id <<"|" << email << "|" << contact << "|" << endl;
						counter += 1;
					}
					for (int i = 0; i < 213; i++) {
						cout << "-";
					}
					cout << endl;
					file1.close();
					cout << "Would you like to continue viewing the details of all the accounts? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	int adminLogin() {
		string password, username;
		fstream my_file;
		my_file.open("adminInfo.txt", ios::in);
		if (!my_file) {
			my_file.open("adminInfo.txt", ios::out);
			my_file << rightPad("Admin", 20) << rightPad("1", 50) << endl;
			my_file << "What is 1 + 1?" << endl;
			my_file << "2" << endl;
			my_file.close();
			return 0;
		}
		else {
			string adminInfoLine;
			if (my_file.is_open()) {
				getline(my_file, adminInfoLine); 
				string givenUsername = trim(adminInfoLine.substr(0, 20));
				string givenPassword = trim(adminInfoLine.substr(20, 50));
				int flag1 = 1;
				while (flag1 == 1) {
					cout << "===================================================================" << endl;
					cout << rightPad(" ", 20) << "Admin Login" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					cout << "Enter your username: ";
					getline(cin >> ws, username);
					cout << endl;
					cout << "Enter your password: ";
					getline(cin >> ws, password);
					cout << endl;

					if (givenUsername == username && givenPassword == password) {
						flag1 = 0;
						cout << "Login success!" << endl;
						return 1;
					}
					else {
						cout << "The username or password that you've entered is incorrect" << endl;
						cout << "Would you like to continue or return to the homepage? [Press 1 to continue]: ";
						while (!(cin >> flag1)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid input.  Please enter a valid input: ";
						}
						cout << endl;
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				}
				
			}
		}
		my_file.close();
		return 0;
	}


	void changeAdminLogin() {
		fstream file1;
		file1.open("adminInfo.txt", ios::in);
		string adminInfoLine, adminUsername, adminPassword, adminSecurityQ, adminSecurityA, answer, adminNewQ, adminNewA;
		if (file1.is_open()) {
			getline(file1, adminInfoLine);
			getline(file1, adminSecurityQ);
			getline(file1, adminSecurityA);
			cout << "===================================================================" << endl;
			cout << rightPad(" ", 20) << "Changing Admin Info" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "Please answer your security question" << endl;
			cout << endl;
			cout << adminSecurityQ << endl << endl;
			cout << "Enter your answer here: ";
			getline(cin >> ws, answer);
			cout << endl;
			file1.close();
			if (answer == adminSecurityA) {
				remove("adminInfo.txt");
				file1.open("adminInfo.txt", ios::app);
				cout << "Enter admin new username: ";
				getline(cin >> ws, adminUsername);
				cout << endl;
				cout << "Enter admin new password: ";
				getline(cin >> ws, adminPassword);
				cout << endl;
				cout << "Enter Security Question: ";
				getline(cin >> ws, adminNewQ);
				cout << endl;
				cout << "Enter the Answer to the Security Question: ";
				getline(cin >> ws, adminNewA);
				cout << endl;
				file1 << rightPad(adminUsername, 20) << rightPad(adminPassword, 50) << endl;
				file1 << adminNewQ << endl;
				file1 << adminNewA << endl;
				file1.close();
			}
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
	}
};

class AdminCustomer : public AdminManager{
	//AdminCustomer inherits from AdminManager
};

class ManagerProduct {
public:
	string fileName = "Product.txt"; 
	string thing= "product";
	string product, id, description, dateModified, category, location;
	int quantity;
	double price;
	void addItem() {
		fstream file1;
		fstream file2;
		int option = 1;
		while(option == 1) {

			file1.open(fileName, ios::app);
			cout << "===================================================================" << endl;
			cout << rightPad(" ", 20) << "Creating new " << thing << endl << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "Please enter the name of the " << thing << ": ";
			string nameLine;
			while (getline(cin >> ws, product)) {
				file2.open(fileName, ios::in);
				bool check = true;
				if (product.length() > 40) {
					cout << endl;
					cout << "Your "<< thing << " name shouldn't be longer than 40 characters!" << endl;
					cout << "Please enter the name of the " << thing << ": ";
					continue;
				}
				else {
					while (getline(file2, nameLine)) {
						string givenName = trim(nameLine.substr(0, 40));
						if (product == givenName) {
							cout << "The Name that you enter must be unique for each " << thing << endl << endl;
							cout << "Please enter the name of the " << thing << ": ";
							check = false;
							continue;
						}
					}
					file2.close();
					if (check == true) {
						product = rightPad(product, 40);
						cout << endl;
						break;
					}
				}
			}

			string infoLine;
			
			cout << "Please enter the ID of the " << thing << ": ";
			while (getline(cin >> ws, id)) {
				file2.open(fileName, ios::in);
				int unique = 1;
				if (id.length() > 20) {
					cout << endl;
					cout << "Your " << thing << " id shouldn't be longer than 20 characters!" << endl << endl;
					cout << "Please enter the ID of the " << thing << ": ";
					file2.close();
					continue;
				}
				else {
					while (getline(file2, infoLine)) {
						string givenId = trim(infoLine.substr(40, 20));
						if (id == givenId) {
							cout << "The ID that you enter must be unique for each " << thing << endl;
							cout << "Please enter the ID of the " << thing << ": ";
							unique = 0;
							continue;
						}
					}
					file2.close();
					if (unique == 1) {
						id = rightPad(id, 20);
						cout << endl;
						break;
					}
				}
			}
		

			cout << "Please enter a description of the " << thing << ": ";
			while (getline(cin >> ws, description)) {
				if (description.length() > 50) {
					cout << endl;
					cout << "Your " << thing << " description shouldn't be longer than 50 characters!" << endl;
					cout << "Please enter the description of the " << thing << ": ";
					continue;
				}
				else {
					description = rightPad(description, 50);
					cout << endl;
					break;
				}
			}
			cout << "Please enter the category of the " << thing << ": ";
			while (getline(cin >> ws, category)) {
				if (category.length() > 20) {
					cout << endl;
					cout << "Your " << thing << " category shouldn't be longer than 20 characters!" << endl;
					cout << "Please enter the category of the " << thing << ": ";
					continue;
				}
				else {
					category = rightPad(category, 20);
					cout << endl;
					break;
				}
			}

			cout << "Please enter the location of the " << thing << ": ";
			while (getline(cin >> ws, location)) {
				if (location.length() > 20) {
					cout << endl;
					cout << "Your " << thing << " location shouldn't be longer than 20 characters!" << endl;
					cout << "Please enter the location of the " << thing << ": ";
					continue;
				}
				else {
					location = rightPad(location, 20);
					cout << endl;
					break;
				}
			}

			cout << "Please enter the quantity of the " << thing << ": ";
			while (!(cin >> quantity)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.  Please enter a valid input: ";
			}
			string quantityString = to_string(quantity);
			quantityString = rightPad(quantityString, 20); 
			cout << endl;
			cout << "Please enter the price of the " << thing << ": ";
			while (!(cin >> price)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.  Please enter a valid input: ";
			}
			string priceString = to_string(price);
			priceString = rightPad(priceString, 20); 
			cout << endl;

			time_t now = time(0);
			char nowBuff[50];
			ctime_s(nowBuff,sizeof(nowBuff), &now);
			nowBuff[strlen(nowBuff) - 1] = '\0';
			string nowString = rightPad(nowBuff, 50);


			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			
			file1 << product << id << description << quantityString << priceString << nowString << category << location << endl;
			file1.close();
			cout << "Would you like to continue creating more " << thing<< "?[Press 1 to continue]: ";
			while (!(cin >> option)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.  Please enter an integer: ";
			}
		}
	}

	void deleteItem() {
		fstream file1, file2;
		fstream temp, temp2;
		cout << "===================================================================" << endl;
		file1.open(fileName, ios::in);
		temp.open("temp.txt", ios::out);
		if (!file1) {
			cout << rightPad(" ", 20) << "Deleting " << thing << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No " << thing << " exist yet. Please create one" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string nameDelete;
			if (file1.is_open()) {
				file1.close();
				temp.close();
				int flag1 = 1;
				do {
					file1.open(fileName, ios::in);
					temp.open("temp.txt", ios::app); 
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Deleting " << thing << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					cout << "Enter the name of the " << thing << " that you want to delete: ";
					getline(cin >> ws, nameDelete);
					nameDelete = trim(nameDelete);
					cout << endl;
					while (getline(file1, infoLine)) {
						string givenName = trim(infoLine.substr(0, 40));
						if (givenName == nameDelete) {
							isPresent = true;
							cout << nameDelete << " has been deleted from database" << endl << endl;
						}
						else {
							temp << infoLine << endl;

						}

					}
					file2.open("CustomerToPay.txt", ios::in);
					temp2.open("temp2.txt", ios::app);
					string customerLine;
					while (getline(file2, customerLine)) {
						string name = customerLine.substr(0, 40);

						if (trim(name) == nameDelete) {
							continue;
						}
						else {
							temp2 << customerLine << endl;
						}

					}

					file1.close();
					temp.close();
					file2.close();
					temp2.close();
					remove("CustomerToPay.txt");
					rename("temp2.txt", "CustomerToPay.txt");
					if (fileName == "Product.txt") {
						remove("Product.txt");
						rename("temp.txt", "Product.txt");
					}
					else {
						remove("Order.txt");
						rename("temp.txt", "Order.txt");
					}
					if (!isPresent) {
						cout << "There isn't a match between the " << thing << " name in the database with the " << thing << " name that you've inputted" << endl;
					}

					cout << "Would you like to continue deleting " << thing <<"s?" << "[Press 1 to continue] : ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}

					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	void edit() {
		fstream file1;
		fstream file2;
		fstream temp;
		file1.open(fileName, ios::in);
		temp.open("temp.txt", ios::app);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Editing " << thing << " information" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No " << thing << " exist yet. Please create one" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string nameEdit;
			if (file1.is_open()) {
				file1.close();
				temp.close();
				int flag1 = 1;
				do {
					cout << rightPad(" ", 20) << "Editing " << thing << " information" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					file1.open(fileName, ios::in);
					temp.open("temp.txt", ios::app);
					bool isPresent = false;
					cout << "Enter the " << thing << " name that you want to edit: ";
					getline(cin >> ws, nameEdit);
					cout << endl;


					while (getline(file1, infoLine)) {
						string givenUsername = trim(infoLine.substr(0, 40));
						string idOfProduct = trim(infoLine.substr(40, 20));
						if (givenUsername == nameEdit) {
							isPresent = true;
							cout << "Editing " << thing << " details" << endl;
							cout << "Please enter the name of the " << thing << ": ";
							string nameLine;
							while (getline(cin >> ws, product)) {
								file2.open(fileName, ios::in);
								bool check = true;
								if (product.length() > 40) {
									cout << endl;
									cout << "Your " << thing << " name shouldn't be longer than 40 characters!" << endl;
									cout << "Please enter the name of the " << thing << ": ";
									continue;
								}
								else {
									while (getline(file2, nameLine)) {
										string givenName = trim(nameLine.substr(0, 40));
										if (givenName == givenUsername) {
											continue;
										}
										else if (product == givenName) {
											cout << "The Name that you enter must be unique for each " << thing << endl << endl;
											cout << "Please enter the name of the " << thing << ": ";
											check = false;
											continue;
										}
									}
									file2.close();
									if (check == true) {
										product = rightPad(product, 40);
										cout << endl;
										break;
									}
								}
							}
							string infoLine;
							cout << "Please enter the ID of the " << thing << ": ";
							while (getline(cin >> ws, id)) {
								file2.open(fileName, ios::in);
								int unique = 1;
								if (id.length() > 20) {
									cout << endl;
									cout << "Your " << thing << " id shouldn't be longer than 20 characters!" << endl;
									cout << "Please enter the ID of the " << thing << ": ";
									file2.close();
									continue;
								}
								else {
									while (getline(file2, infoLine)) {
										string givenId = trim(infoLine.substr(40, 20));
										if (givenId == idOfProduct) {
											continue;
										}
										if (id == givenId) {
											cout << "The ID that you enter must be unique for each " << thing << endl;
											cout << "Please enter the ID of the " << thing << ": ";
											unique = 0;
											continue;
										}
									}
									file2.close();
									if (unique == 1) {
										id = rightPad(id, 20);
										cout << endl;
										break;
									}
								}
							}
							cout << "Please enter a description of the " << thing << ": ";
							while (getline(cin >> ws, description)) {
								if (description.length() > 50) {
									cout << endl;
									cout << "Your " << thing << " description shouldn't be longer than 50 characters!" << endl;
									cout << "Please enter the description of the " << thing << ": ";
									continue;
								}
								else {
									description = rightPad(description, 50);
									cout << endl;
									break;
								}
							}
							cout << "Please enter the category of the " << thing << ": ";
							while (getline(cin >> ws, category)) {
								if (category.length() > 20) {
									cout << endl;
									cout << "Your " << thing << " category shouldn't be longer than 20 characters!" << endl;
									cout << "Please enter the category of the " << thing << ": ";
									continue;
								}
								else {
									category = rightPad(category, 20);
									cout << endl;
									break;
								}
							}

							cout << "Please enter the location of the " << thing << ": ";
							while (getline(cin >> ws, location)) {
								if (location.length() > 20) {
									cout << endl;
									cout << "Your " << thing << " location shouldn't be longer than 20 characters!" << endl;
									cout << "Please enter the location of the " << thing << ": ";
									continue;
								}
								else {
									location = rightPad(location, 20);
									cout << endl;
									break;
								}
							}
							cout << "Please enter the quantity of the " << thing << ": ";
							while (!(cin >> quantity)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter a valid input: ";
							}
							string quantityString = to_string(quantity);
							quantityString = rightPad(quantityString, 20); 
							cout << endl;
							cout << "Please enter the price of the " << thing << ": ";
							while (!(cin >> price)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter a valid input: ";
							}
							string priceString = to_string(price);
							priceString = rightPad(priceString, 20);
							cout << endl;

							time_t now = time(0);
							char nowBuff[50];
							ctime_s(nowBuff, sizeof(nowBuff), &now);
							nowBuff[strlen(nowBuff) - 1] = '\0';
							string nowString = rightPad(nowBuff, 50);
							temp << product << id << description << quantityString << priceString << nowString << category << location << endl;
						}
						else {
							temp << infoLine << endl;
						}

					}


					file1.close();
					temp.close();
					if (fileName == "Product.txt") {
						remove("Product.txt");
						rename("temp.txt", "Product.txt");
					}
					else {
						remove("Order.txt");
						rename("temp.txt", "Order.txt");
					}
					if (!isPresent) {
						cout << "There isn't a match between the " << thing << " name in the database with the "<< thing <<" name that you've inputted" << endl;
					}
					cout << "Would you like to continue editing the " << thing <<"? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}

					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	void search() {
		fstream file1;
		file1.open(fileName, ios::in);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Searching for " << thing << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No " << thing << " exist yet. Please create one" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string nameSearch;
			string name, id, description, quantity, price, dateModified, category, location;
			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					file1.open(fileName, ios::in);
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Searching for " << thing << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;


					cout << endl;
					cout << "Enter the " << thing << " name that you want to search: ";
					getline(cin >> ws, nameSearch);
					cout << endl;
					for (int i = 0; i < 203; i++) {
						cout << "-";
					}
					cout << endl;
					cout << rightPad("Name", 40) << "|" << rightPad("ID", 20) << "|" << rightPad("Description", 50) << "|" << rightPad("Quantity", 10) <<  "|" << rightPad("Price (RM)", 10) << "|" << rightPad("Last Modified", 25) << "|" << rightPad("Category", 20) << "|" << rightPad("Location", 20) << "|" << endl;
					    
					for (int i = 0; i < 203; i++) {
						cout << "-";
					}
					cout << endl;

					while (getline(file1, infoLine)) {
						string givenName = trim(infoLine.substr(0, 40));
						string givenId = trim(infoLine.substr(40, 20));
						string givenCategory = trim(infoLine.substr(200, 20));
						string givenLocation = trim(infoLine.substr(220, 20));
						if (isSubstring(nameSearch, givenName) != -1 || isSubstring(nameSearch, givenId) != -1 || isSubstring(nameSearch, givenCategory) != -1 || isSubstring(nameSearch, givenLocation) != -1) {

							isPresent = true;


							name = infoLine.substr(0, 40);
							id = infoLine.substr(40, 20);
							description= infoLine.substr(60, 50);
							quantity = infoLine.substr(110, 20);
							price = infoLine.substr(130, 20);
							dateModified = infoLine.substr(150, 50);
							category = infoLine.substr(200, 20);
							location = infoLine.substr(220, 20);


							double priceDouble = stod(trim(price));
							stringstream stream;
							stream << fixed << setprecision(2) << priceDouble;
							price = rightPad(stream.str(),20);

							cout << name << "|" << id << "|" << description << "|" << rightPad(trim(quantity), 10) << "|" << rightPad(trim(price), 10) << "|" << rightPad(trim(dateModified), 25) << "|" << category << "|" << location << "|" << endl;

							
						}


					}
					if (!isPresent) {
						cout << rightPad("N/A", 40) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 50) << "|" << rightPad("N/A", 10) << "|" << rightPad("N/A", 10) << "|" << rightPad("N/A", 25) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 20) << "|" << endl;
					}
					for (int i = 0; i < 203; i++) {
						cout << "-";
					}
					cout << endl;

					file1.close();
					if (!isPresent) {
						cout << "There isn't a match between the " << thing << " name in the database with the "<< thing << " name that you've inputted" << endl;
					}

					cout << "Would you like to continue viewing the details of the items? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	void displayAllProducts() {
		fstream file1;
		file1.open(fileName, ios::in);
		cout << "===================================================================" << endl;

		cout << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Displaying all " << thing << "s" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No " << thing << " exist yet. Please create one" << endl;
		}
		else {
			string infoLine;
			string usernameSearch;
			string name, id, description, quantity, price, dateModified, category, location;
			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					cout << rightPad(" ", 20) << "Displaying all " << thing << "s" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					file1.open(fileName, ios::in);
					int counter = 1;
					for (int i = 0; i < 209; i++) {
						cout << "-";
					}
					cout << endl;
					cout << rightPad("No", 5) << "|" << rightPad("Name", 40) << "|" << rightPad("ID", 20) << "|" << rightPad("Description", 50) << "|" << rightPad("Quantity", 10) << "|" << rightPad("Price (RM)", 10) << "|" << rightPad("Last Modified", 25) << "|" << rightPad("Category", 20) << "|" << rightPad("Location", 20) << "|" << endl;
					for (int i = 0; i < 209; i++) {
						cout << "-";
					}
					cout << endl;
					while (getline(file1, infoLine)) {

						name = infoLine.substr(0, 40);
						id = infoLine.substr(40, 20);
						description = infoLine.substr(60, 50);
						quantity = infoLine.substr(110, 20);
						price = infoLine.substr(130, 20);
						dateModified = infoLine.substr(150, 50);
						category = infoLine.substr(200, 20);
						location = infoLine.substr(220, 20);

						string counterString = to_string(counter);
						stringstream stream;
						
						double priceDouble = stod(trim(price));
						stream << fixed << setprecision(2) << priceDouble;
						price = rightPad(stream.str(),20);
						
						cout << rightPad(counterString, 5) << "|" << name << "|" << id << "|" << description << "|" << rightPad(trim(quantity), 10) << "|" << rightPad(trim(price), 10) << "|" << rightPad(trim(dateModified), 25) << "|" << category << "|" << location << "|" << endl;
						counter += 1;
					}
					for (int i = 0; i < 209; i++) {
						cout << "-";
					}
					cout << endl;
					file1.close();
					cout << "Would you like to continue viewing the details of all the items? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	int managerLogin() {
		string password, username, infoLine;
		fstream my_file;
		my_file.open("Manager.txt", ios::in);
		if (!my_file) {
			cout << "No manager account exist yet. Wait for the admin to create one" << endl;
			my_file.close();
			return 0;
		}
		else {

			if (my_file.is_open()) {

				my_file.close();
				int flag1 = 1;
				while (flag1 == 1) {
					my_file.open("Manager.txt", ios::in);
					cout << "===================================================================" << endl;
					cout << rightPad(" ", 20) << "Manager Login" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					
					cout << endl;
					cout << "Enter your username: ";
					getline(cin >> ws, username);
					cout << endl;
					cout << "Enter your password: ";
					getline(cin >> ws, password);
					cout << endl;
					while (getline(my_file, infoLine)) {
						string givenName = trim(infoLine.substr(0, 20));
						string givenPassword = trim(infoLine.substr(20,20));
						if (givenName == username && givenPassword == password) {
							flag1 = 0;
							cout << "Login success!" << endl;
							for (int i = 0; i < 50; i++) {
								cout << "-";
							}
							cout << endl;
							my_file.close();
							return 1;
						}

					}
					cout << "The username or password that you've entered is incorrect" << endl;
					cout << "Would you like to continue or return to the homepage? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter a valid input: ";
					}
					cout << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					my_file.close();
				}

			}
		}
		
		return 0;
	}

};

class ManagerOrder {
public:
	string fileName = "Order.txt";
	string thing = "order";
	string productName, productId,orderId, description, dateModifiedOrder, totalPriceString, finalQuantityString;
	int quantity, quantityOrder;
	double price;
	string managerId, managerUsername;
	void addItem(string manager_ID, string manager_Username) {
		ManagerProduct MP;
		MP.displayAllProducts();
		fstream file1;
		file1.open("Product.txt", ios::in);
		fstream file2;
		fstream temp;
		fstream sheet;
		int counter;
		cout << "===================================================================" << endl;

		file2.open("Order.txt", ios::in);
		if (!file2) {
			counter = 1;
		}
		else {
			string lastLine;

			while (getline(file2, lastLine)) {
				counter = stoi(trim(lastLine.substr(210, 20))) + 1;
			}
			
		}
		file2.close();
		if (!file1) {
			cout << rightPad(" ", 20) << "Creating a new " << thing << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No product exist yet. Please create one first!" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			file1.close();
			string infoLine;
			string orderName;
			string tempInfoLine;
			int flag1 = 1;
			bool isPresent = false;
			do {
				cout << rightPad(" ", 20) << "Creating a new " << thing << endl;
				for (int i = 0; i < 50; i++) {
					cout << "-";
				}

				cout << endl;
				file1.open("Product.txt", ios::in);
				cout << "Enter the name of the product that you want to order: ";
				getline(cin >> ws, orderName);
				cout << endl;


				while (getline(file1, infoLine)) {
					productName = infoLine.substr(0, 40);
					productId = infoLine.substr(40, 20);
					string givenName = trim(productName);
					string givenId = trim(productId);
					if (orderName == givenName || orderName == givenId) {
						isPresent = true;
						description = infoLine.substr(60, 50);
						quantity = stoi(infoLine.substr(110, 20));
						price = stoi(infoLine.substr(130, 20));

						cout << "Please enter the number of " << orderName << " that you would like to order: ";
						while (!(cin >> quantityOrder)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid input.  Please enter a valid input: ";
						}
						cout << endl;
						finalQuantityString = to_string(quantityOrder + quantity);
						finalQuantityString = rightPad(finalQuantityString, 20);
						string initialQuantityString = to_string(quantity);
						initialQuantityString = rightPad(initialQuantityString, 20);
						double totalPrice = quantityOrder * price;
						totalPriceString = to_string(totalPrice);
						totalPriceString = rightPad(totalPriceString, 20);
						temp.open("temp.txt", ios::app);
						sheet.open("sheet.txt", ios::in);
						if (!sheet) {
							sheet.close();
							sheet.open("sheet.txt", ios::app);
							sheet << productName << initialQuantityString << finalQuantityString << totalPriceString << endl;
							sheet.close();
						}
						else {
							bool isAdded = false;
							string sheetLine;
							while (getline(sheet, sheetLine)) {
								string sheetName = trim(sheetLine.substr(0, 40));
								string sheetInitial = trim(sheetLine.substr(40, 20));
								string sheetFinal = trim(sheetLine.substr(60, 20));
								if (givenName == sheetName) {
									int total = stoi(sheetFinal) + stoi(sheetInitial);
									string totalString = rightPad(to_string(total), 20);
									temp << rightPad(sheetName, 40) << rightPad(sheetInitial, 20) << totalString << totalPriceString << endl;
									isAdded = true;
								}
								else {
									temp << sheetLine << endl;

								}

							}

							sheet.close();
							temp.close();
							remove("sheet.txt");
							rename("temp.txt", "sheet.txt");

							sheet.open("sheet.txt", ios::app);
							sheet << productName << initialQuantityString << finalQuantityString << totalPriceString << endl;
							sheet.close();
						}
						temp.close();

						time_t now = time(0);
						char nowBuff[50];
						ctime_s(nowBuff, sizeof(nowBuff), &now);
						nowBuff[strlen(nowBuff) - 1] = '\0';
						string nowString = rightPad(nowBuff, 50);
						file2.open("Order.txt", ios::app);
						file2 << productName << productId << finalQuantityString << rightPad(manager_Username, 20) << rightPad(manager_ID, 20) << rightPad(to_string(price), 20) << totalPriceString << nowString << rightPad(to_string(counter), 20) << rightPad(trim(initialQuantityString),10) << rightPad(to_string(quantityOrder),10) << endl;
						//40 + 20 + 20 + 20 + 20 + 20 + 20 + 50 + 20 + 10 + 10= 250
						file2.close();
					}
					
				}
				file1.close();
				file1.open("Product.txt", ios::in);
				sheet.open("sheet.txt", ios::in);
				temp.open("temp.txt", ios::app);
				time_t now = time(0);
				char nowBuff[50];
				ctime_s(nowBuff, sizeof(nowBuff), &now);
				nowBuff[strlen(nowBuff) - 1] = '\0';
				string nowString = rightPad(nowBuff, 50);
				dateModifiedOrder = nowString;
				string sheetLine;
				string productLine;
				while (getline(sheet, sheetLine)) {
					string sheetName = sheetLine.substr(0, 40);
					string sheetInitial = sheetLine.substr(40, 20);
					string sheetFinal = sheetLine.substr(60, 20);
					string sheetPrice = sheetLine.substr(80, 20);

					double sheetPriceDouble = stod(trim(sheetPrice));
					stringstream stream;
					stream << fixed << setprecision(2) << sheetPriceDouble;
					sheetPrice = rightPad(stream.str(), 20);

					cout << trim(sheetName) << " stock has increased from: " << endl << endl;
					cout << trim(sheetInitial) << " => " << trim(sheetFinal) << endl << endl;
					cout << "Price is: RM" << trim(sheetPrice) << endl << endl;
					while (getline(file1, productLine)) {
						string givenName = productLine.substr(0, 40);
						string id = productLine.substr(40, 20);
						string description = productLine.substr(60, 50);
						string quantity = productLine.substr(110, 20);
						string price = productLine.substr(130, 20);
						string dateModified = productLine.substr(150, 50);
						string category = productLine.substr(200, 20);
						string location = productLine.substr(220, 20);
						if (trim(givenName) == trim(sheetName)) {
							temp << sheetName << id << description << sheetFinal << price << nowString <<category <<location << endl;
						}
						else {
							temp << productLine << endl;

						}

					}
				}

				file1.close();
				sheet.close();
				temp.close();
				//temp.close();
				remove("sheet.txt");
				remove("Product.txt");
				/*remove("Product.txt");*/
				rename("temp.txt", "Product.txt");
				if (!isPresent) {
					cout << "There isn't a match between the product name in the database with the product name that you've inputted" << endl;
				}
				cout << "Would you like to continue creating new orders? [Press 1 to continue]: ";
				while (!(cin >> flag1)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Please enter an integer: ";
				}

				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
			} while (flag1 == 1);
		}
	}
	void deleteItem() {
		fstream file1;
		fstream temp;
		cout << "===================================================================" << endl;
		file1.open("Order.txt", ios::in);
		temp.open("temp.txt", ios::app);
		if (!file1) {
			cout << rightPad(" ", 20) << "Deleting Order " << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No order exist yet. Please create one" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string orderIdDelete;
			if (file1.is_open()) {
				file1.close();
				temp.close();
				int flag1 = 1;
				do {
					file1.open("Order.txt", ios::in);
					temp.open("temp.txt", ios::app); 
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Deleting order " << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					cout << "Enter the Order ID of the Order that you want to delete: ";
					getline(cin >> ws, orderIdDelete);
					cout << endl;
					while (getline(file1, infoLine)) {
						string givenId = trim(infoLine.substr(40, 20));
						string givenOrderId = trim(infoLine.substr(210, 20));
						int number_of_zeroes = 4 - givenOrderId.length();
						givenOrderId.insert(0, number_of_zeroes, '0');
						string givenOrderIdString = "ORD-" + givenOrderId;

						if (givenOrderIdString == orderIdDelete) {
							isPresent = true;
							cout << "ORD-" << givenOrderId << " has been deleted from database" << endl << endl;
						}
						else {
							temp << infoLine << endl;

						}

					}

					file1.close();
					temp.close();
					remove("Order.txt");
					rename("temp.txt", "Order.txt");
					if (!isPresent) {
						cout << "There isn't a match between the Order ID in the database with the Order ID that you've inputted" << endl;
					}

					cout << "Would you like to continue deleting Orders?" << "[Press 1 to continue] : ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}

					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	void edit() {
		fstream file1;
		fstream file2;
		fstream temp;
		fstream temp2;
		int qty;
		double price;
		file1.open("Order.txt", ios::in);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Editing order information" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No " << thing << " exist yet. Please create one" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string orderId;
			string productId;
			
			file1.close();
			temp.close();
			int flag1 = 1;
			do {
				cout << rightPad(" ", 20) << "Editing order information" << endl;
				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
				file1.open("Order.txt", ios::in);
				temp.open("temp.txt", ios::app);
				bool isPresent = false;
				cout << "Enter the order ID of the order that you want to edit: ";
				getline(cin >> ws, orderId);
				cout << endl;
				cout << "Enter the product ID of the order that you want to edit: ";
				getline(cin >> ws, productId);
				cout << endl;

				while (getline(file1, infoLine)) {
					
					string givenProductName = trim(infoLine.substr(0, 40));
					string givenProductId = trim(infoLine.substr(40, 20));
					string givenProductQty = trim(infoLine.substr(60, 20));
					string givenManagerName = trim(infoLine.substr(80, 20));
					string givenManagerId = trim(infoLine.substr(100, 20));
					string givenProductPrice = trim(infoLine.substr(120, 20));
					string givenProductTotalPrice = trim(infoLine.substr(140, 20));
					string givenDateModified = trim(infoLine.substr(160, 50));
					string givenOrderId = trim(infoLine.substr(210, 20));
					string givenInitialQty = infoLine.substr(230, 10);
					string givenQuantityOrdered = infoLine.substr(240, 10);

					string givenOrderIdUpdated = givenOrderId;

					int number_of_zeroes = 4 - givenOrderId.length();
					givenOrderIdUpdated.insert(0, number_of_zeroes, '0');
					string givenOrderIdString = "ORD-" + givenOrderIdUpdated;
					
					if (givenOrderIdString == orderId && givenProductId == productId) {
						isPresent = true;
						cout << "Editing order details for Order ID: " << givenOrderIdString << " and Product ID: " << givenProductId << endl << endl;
						cout << "Please enter the quantity for Order ID: " << givenOrderIdString << " and Product ID: " << givenProductId << ": ";
						while (!(cin >> qty)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid input.  Please enter a valid input: ";
						}
						string quantityString = to_string(qty);
						quantityString = rightPad(quantityString, 20); 
						cout << endl;
						cout << "Please enter the price for Order ID: " << givenOrderIdString << " and Product ID: " << givenProductId << ": ";
						while (!(cin >> price)) {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid input.  Please enter a valid input: ";
						}
						string priceString = to_string(price);
						priceString = rightPad(priceString, 20);
						cout << endl;

						string totalPriceString = rightPad(to_string(price * qty), 20);

						time_t now = time(0);
						char nowBuff[50];
						ctime_s(nowBuff, sizeof(nowBuff), &now);
						nowBuff[strlen(nowBuff) - 1] = '\0';
						string nowString = rightPad(nowBuff, 50);

						int difference = qty - stoi(trim(givenProductQty));
						string differenceString = rightPad(to_string(difference), 10);
						temp << rightPad(givenProductName, 40) << rightPad(givenProductId, 20) << quantityString << rightPad(givenManagerName, 20) << rightPad(givenManagerId, 20) << priceString << totalPriceString << nowString << rightPad(givenOrderId, 20) << rightPad(givenProductQty,10) << differenceString << endl;
					
						string productInfoLine;
						file2.open("Product.txt", ios::in);
						temp2.open("temp2.txt", ios::app);
						while (getline(file2, productInfoLine)) {
							string name = productInfoLine.substr(0, 40);
							string id = trim(productInfoLine.substr(40, 20));
							string description = productInfoLine.substr(60, 50);
							string quantity = productInfoLine.substr(110, 20);
							string priceString = productInfoLine.substr(130, 20);
							string dateModified = productInfoLine.substr(150, 50);
							string category = productInfoLine.substr(200, 20);
							string location = productInfoLine.substr(220, 20);

							time_t now = time(0);
							char nowBuff[50];
							ctime_s(nowBuff, sizeof(nowBuff), &now);
							nowBuff[strlen(nowBuff) - 1] = '\0';
							string nowString = rightPad(nowBuff, 50);
							if (id == productId) {
								temp2 << name << rightPad(id,20) << description << rightPad(to_string(qty), 20) << rightPad(to_string(price), 20) << nowString << category << location << endl;
							}
							else {
								temp2 << productInfoLine << endl;
							}
						}
						file2.close();
						temp2.close();
					}
					else {
						temp << infoLine << endl;
					}
				}
		

				file1.close();
				temp.close();
				remove("Order.txt");
				rename("temp.txt", "Order.txt");
			
				
				if (!isPresent) {
					cout << "There isn't a match between the Order ID and Product Name in the database with the Order ID and Product Name that you've inputted" << endl;
				}
				else {
					remove("Product.txt");
					rename("temp2.txt", "Product.txt");
				}
				cout << "Would you like to continue editing orders? [Press 1 to continue]: ";
				while (!(cin >> flag1)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Please enter an integer: ";
				}

				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
			} while (flag1 == 1);

		}
	}
	

	void search() {
		fstream file1;
		file1.open("Order.txt", ios::in);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Searching for Order"  << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No Order exist yet. Please create one" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string idSearch;
		
			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					file1.open("Order.txt", ios::in);
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Searching for Orders" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					

					cout << endl;
					cout << "Enter the Order ID of the Order that you want to search: ";
					getline(cin >> ws, idSearch);
					cout << endl;

					for (int i = 0; i < 216; i++) {
						cout << "-";
					}
					cout << endl;

					cout << rightPad("Product Name", 40) << "|" << rightPad("Product ID", 20) << "|" << rightPad("Initial", 10) << "|" << rightPad("Changes", 10) << "|" << rightPad("Quantity", 10) << "|" << rightPad("Username of Orderer", 20) << "|" << rightPad("ID of Orderer", 20) << "|" << rightPad("Price per Unit (RM)", 20) << "|" << rightPad("Total Price (RM)", 20) << "|" << rightPad("Last Modified", 25) << "|" << rightPad("Order ID", 10) << "|" << endl;

					for (int i = 0; i < 216; i++) {
						cout << "-";
					}
					cout << endl;

					while (getline(file1, infoLine)) {
						string givenOrderId = trim(infoLine.substr(210, 20));
						int number_of_zeroes = 4 - givenOrderId.length();
						givenOrderId.insert(0, number_of_zeroes, '0');
						string givenOrderIdString = "ORD-" + givenOrderId;
						if (isSubstring(idSearch, givenOrderIdString) != -1) {

							isPresent = true;


							string productName = infoLine.substr(0, 40);
							string productId = infoLine.substr(40, 20);
							string quantity= trim(infoLine.substr(60, 20));
							string username = infoLine.substr(80, 20);
							string id = infoLine.substr(100, 20);
							string price = infoLine.substr(120, 20);
							string totalPrice = infoLine.substr(140, 20);
							string dateModified = trim(infoLine.substr(160, 50));
							string orderId = trim(infoLine.substr(210, 20));
							string givenInitialQty = infoLine.substr(230, 10);
							string givenQuantityOrdered = infoLine.substr(240, 10);

							int number_of_zeroes = 4 - orderId.length();
							orderId.insert(0, number_of_zeroes, '0');
							string givenOrderIdString = "ORD-" + orderId;

							double priceDouble = stod(trim(price));
							stringstream stream;
							stream << fixed << setprecision(2) << priceDouble;
							price = rightPad(stream.str(),20);

							double totalPriceDouble = stod(trim(totalPrice));
							stringstream stream2;
							stream2 << fixed << setprecision(2) << totalPriceDouble;
							totalPrice = rightPad(stream2.str(), 20);

							cout << productName << "|" << productId << "|" << givenInitialQty << "|" << givenQuantityOrdered << "|" << rightPad(quantity,10) << "|" << username << "|" << id << "|" << price << "|" << totalPrice << "|" << rightPad(dateModified,25) << "|" << rightPad(givenOrderIdString,10) << "|" << endl;
							//40 + 20 + 10 + 10 + 10 + 20 + 20 + 20 + 20 + 25 + 10

						}


					}
					if (!isPresent) {
						cout << rightPad("N/A", 40) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 10) << "|" << rightPad("N/A", 10) << "|" << rightPad("N/A", 10) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 20) << "|" << rightPad("N/A", 25) << "|" << rightPad("N/A", 10) << "|" << endl;
					}

					for (int i = 0; i < 216; i++) {
						cout << "-";
					}
					cout << endl;

					file1.close();
					if (!isPresent) {
						cout << "There isn't a match between the Order ID in the database with the Order ID that you've inputted" << endl;
					}

					cout << "Would you like to continue viewing the details of the orders? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}
	void displayAllProducts() {
		fstream file1;
		file1.open("Order.txt", ios::in);
		cout << "===================================================================" << endl;
		cout << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Displaying all Orders" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << "No Orders exist yet. Please create one" << endl; 
		}
		else {
			string infoLine;
			string usernameSearch;
			string name, id, description, quantity, price, dateModified;
			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					cout << rightPad(" ", 20) << "Displaying all Orders" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					file1.open("Order.txt", ios::in);
					int counter = 1;
					for (int i = 0; i < 222; i++) {
						cout << "-";
					}
					cout << endl;
					cout << rightPad("No", 5) << "|" << rightPad("Product Name", 40) << "|" << rightPad("Product ID", 20) << "|" << rightPad("Initial", 10) << "|" << rightPad("Changes", 10) << "|" << rightPad("Quantity", 10) << "|" << rightPad("Username of Orderer", 20) << "|" << rightPad("ID of Orderer", 20) << "|" << rightPad("Price per Unit (RM)", 20) << "|" << rightPad("Total Price (RM)", 20) << "|" << rightPad("Last Modified", 25) << "|" << rightPad("Order ID", 10) << "|" << endl;
					for (int i = 0; i < 222; i++) {
						cout << "-";
					}
					cout << endl;
					while (getline(file1, infoLine)) {

						string productName = infoLine.substr(0, 40);
						string productId = infoLine.substr(40, 20);
						string quantity = trim(infoLine.substr(60, 20));
						string username = infoLine.substr(80, 20);
						string id = infoLine.substr(100, 20);
						string price = infoLine.substr(120, 20);
						string totalPrice = infoLine.substr(140, 20);
						string dateModified = infoLine.substr(160, 50);
						string orderId = trim(infoLine.substr(210, 20));
						string givenInitialQty = infoLine.substr(230, 10);
						string givenQuantityOrdered = infoLine.substr(240, 10);

						int number_of_zeroes = 4 - orderId.length();
						orderId.insert(0, number_of_zeroes, '0');
						string givenOrderIdString = "ORD-" + orderId;

						string counterString = to_string(counter);
						
						double priceDouble = stod(trim(price));
						stringstream stream;
						stream << fixed << setprecision(2) << priceDouble;
						price = rightPad(stream.str(), 20);

						double totalPriceDouble = stod(trim(totalPrice));
						stringstream stream2;
						stream2 << fixed << setprecision(2) << totalPriceDouble;
						totalPrice = rightPad(stream2.str(), 20);

						cout << rightPad(counterString, 5) << "|" << productName << "|" << productId << "|" << givenInitialQty << "|" << givenQuantityOrdered << "|" << rightPad(quantity, 10) << "|" << username << "|" << id << "|" << price << "|" << totalPrice << "|" << rightPad(trim(dateModified), 25) << "|" << rightPad(givenOrderIdString, 10) << "|" << endl;
						counter += 1;
					}
					for (int i = 0; i < 222; i++) {
						cout << "-";
					}
					cout << endl;
					file1.close();
					cout << "Would you like to continue viewing the details of all the Orders? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	void summary() {
		string orderId, totalPriceString, infoLine, limit, orderIdString;
		double totalPrice = 0;
		int totalItem = 0, maxOrderId= 0;
		fstream file1;
		file1.open("Order.txt", ios::in);

		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Summary of all Orders" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << "No orders exist yet. Please create one" << endl;
		}
		else {
			cout << rightPad(" ", 20) << "Summary of all Orders" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			for (int i = 0; i < 63; i++) {
				cout << "-";
			}
			cout << endl;
			cout << rightPad("Order ID", 20) << "|" << rightPad("Total Items", 20) << "|" << rightPad("Total Price", 20) << "|" << endl;
			int counter = 1;
			while (getline(file1, limit)) {
				maxOrderId = stoi(trim(limit.substr(210, 20)));
			}
			file1.close();
			
			while (counter <= maxOrderId) {

				bool isPresent = false;
				file1.open("Order.txt", ios::in);
				while (getline(file1, infoLine)) {
				
					string productName = infoLine.substr(0, 40);
					string productId = infoLine.substr(40, 20);
					string quantity = trim(infoLine.substr(60, 20));
					string username = infoLine.substr(80, 20);
					string id = infoLine.substr(100, 20);
					string price = infoLine.substr(120, 20);
					string totalPriceOrder = infoLine.substr(140, 20);
					string dateModified = infoLine.substr(160, 50);
					orderId = trim(infoLine.substr(210, 20));
					string givenInitialQty = infoLine.substr(230, 10);
					string givenQuantityOrdered = infoLine.substr(240, 10);


					if (stoi(orderId) == counter) {
						totalItem += 1;
						totalPrice += stod(trim(totalPriceOrder));

						isPresent = true;

						int number_of_zeroes = 4 - orderId.length();
						orderId.insert(0, number_of_zeroes, '0');
						orderIdString = "ORD-" + orderId;
					}
					

				}
				file1.close();
				counter += 1;
				if (isPresent == true) {

					for (int i = 0; i < 63; i++) {
						cout << "-";
					}
					cout << endl;
					stringstream stream;
					stream << fixed << setprecision(2) << totalPrice;
					totalPriceString = rightPad(stream.str(), 20);
					cout << rightPad(orderIdString, 20) << "|" << rightPad(to_string(totalItem), 20) << "|" << totalPriceString << "|" << endl;
					totalItem = 0;
					totalPrice = 0;


					for (int i = 0; i < 63; i++) {
						cout << "-";
					}
					cout << endl;
				}
			}
		}

	}

	int managerLogin() {
		string password, username, infoLine;
		fstream my_file;
		my_file.open("Manager.txt", ios::in);
		if (!my_file) {
			cout << "No manager account exist yet. Wait for the admin to create one" << endl;
			return 0;
		}
		else {
			if (my_file.is_open()) {
				my_file.close();
				int flag1 = 1;
				while (flag1 == 1) {
					my_file.open("Manager.txt", ios::in);
					cout << "===================================================================" << endl;
					cout << rightPad(" ", 20) << "Manager Login" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					cout << "Enter your username: ";
					getline(cin >> ws, username);
					cout << endl;
					cout << "Enter your password: ";
					getline(cin >> ws, password);
					cout << endl;
					while (getline(my_file, infoLine)) {
						string givenName = trim(infoLine.substr(0, 20));
						string givenPassword = trim(infoLine.substr(20, 20));
						string id = infoLine.substr(150, 20);
						if (givenName == username && givenPassword == password) {
							flag1 = 0;
							cout << "Login success!" << endl;
							managerId = id;
							managerUsername = givenName;
							for (int i = 0; i < 50; i++) {
								cout << "-";
							}
							cout << endl;
							my_file.close();
							return 1;
						}

					}
					cout << "The username or password that you've entered is incorrect" << endl;
					cout << "Would you like to continue or return to the homepage? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter a valid input: ";
					}
					cout << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					my_file.close();
				}

			}
		}

		return 0;
	}

};


class Customer {
public:
	string customerID, customerUsername;
	void shop(string customer_ID) {
		int quantity;
		fstream file1;
		fstream temp;
		fstream checkToPay;
		fstream temp2;
		fstream toPay;
		file1.open("Product.txt", ios::in);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Online Shop" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "All the products are unavailabe at this point in time. Please wait until the manager restocks. " << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string nameBuy;
			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					cout << rightPad(" ", 20) << "Online Shop" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					file1.open("Product.txt", ios::in);
					
					bool isPresent = false;
					cout << "Enter the product name that you want to buy: ";
					getline(cin >> ws, nameBuy);
					cout << endl;
					int totalOfItem = 0;

					while (getline(file1, infoLine)) {
						bool appended = false;
						string givenName = trim(infoLine.substr(0, 40));
						if (givenName == nameBuy) {
							isPresent = true;
							cout << "Please enter the amount of " << nameBuy << " that you would like to buy : ";
							while (!(cin >> quantity)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter a valid input: ";
							}
							string quantityString = to_string(quantity);
							quantityString = rightPad(quantityString, 20); 
							cout << endl;

							string name = infoLine.substr(0, 40);
							string id = infoLine.substr(40, 20);
							string description = infoLine.substr(60, 50);
							string quantityProduct = infoLine.substr(110, 20);
							string priceString = infoLine.substr(130, 20);
							string dateModified = infoLine.substr(150, 50);

							time_t now = time(0);
							char nowBuff[50];
							ctime_s(nowBuff, sizeof(nowBuff), &now);
							nowBuff[strlen(nowBuff) - 1] = '\0';
							string nowString = rightPad(nowBuff, 50);

							

							if (quantity > stoi(trim(quantityProduct))) {
								cout << "The quantity of the product that you are trying to purchase exceeds the stock of the product" << endl << endl;
								cout << "Please wait for the manager to restock or buy fewer quantity of the product" << endl;
							}
							else {
								double priceDouble = stod(trim(priceString));

								checkToPay.open("CustomerToPay.txt", ios::in);
								temp2.open("temp2.txt", ios::app);
								string tempLine;
								while (getline(checkToPay, tempLine)) {
									string tempName = trim(tempLine.substr(0, 40));
									string tempQuantity = trim(tempLine.substr(60, 20));
									string tempId = tempLine.substr(40, 20);
									string tempPriceString = tempLine.substr(80, 20);
									string tempTotalPriceString = tempLine.substr(100, 20);
									string dateModifiedString = tempLine.substr(120, 50);
									string tempCustomerID = tempLine.substr(170, 20);

									if (tempName == nameBuy) {
										int newQty = stoi(tempQuantity) + quantity;
										if (newQty > stoi(trim(quantityProduct))) {
											cout << "The quantity of the product that you are trying to purchase exceeds the stock of the product" << endl << endl;
											cout << "Please wait for the manager to restock or buy fewer quantity of the product" << endl;
											temp2 << tempLine;
											appended = true;
										}
										else {
											appended = true;
											double tempPriceDouble = stod(trim(tempPriceString));
											temp2 << rightPad(tempName, 40) << tempId << rightPad(to_string(newQty),20) << tempPriceString << rightPad(to_string(tempPriceDouble * newQty), 20) << nowString << rightPad(customer_ID, 20) << endl;
										}
									}
									else {
										temp2 << tempLine << endl;;
									}
								}
								temp2.close();
								checkToPay.close();
								remove("CustomerToPay.txt");
								rename("temp2.txt", "CustomerToPay.txt");
								if (!appended) {
									checkToPay.open("CustomerTopay.txt", ios::app);
									checkToPay << name << id << quantityString << priceString << rightPad(to_string(priceDouble * quantity), 20) << nowString << rightPad(customer_ID, 20) << endl;
									checkToPay.close();
								}
								//40 + 20 + 20 + 20 + 20 + 50 + 20 = 190
							}
						}

					}


					file1.close();
					
					if (!isPresent) {
						cout << "There isn't a match between the product name in the database with the product name that you've inputted" << endl;
					}
					cout << "Would you like to continue shopping? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}

					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);
			}
		}
	}


	void ViewCart(string customer_ID) {
		fstream file1;
		file1.open("CustomerToPay.txt", ios::in);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Viewing Customer Cart" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "Nothing has been added to the cart yet. Please add item to the cart first" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			file1.close();
		}
		else {
			string infoLine;
			string nameSearch;
			string name, id, description, quantityString, priceString, totalPriceString, dateModified;
			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Viewing Customer Cart" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					for (int i = 0; i < 176; i++) {
						cout << "-";
					}
					cout << endl;

					cout << rightPad("Name", 40) << "|" << rightPad("ID", 20) << "|" << rightPad("Quantity", 20) << "|" << rightPad("Price Per Unit (RM)", 20) << "|" << rightPad("Total Price (RM)", 20) << "|" << rightPad("Last Modified", 50) << "|" << endl;

					for (int i = 0; i < 176; i++) {
						cout << "-";
					}
					cout << endl;
					file1.open("CustomerToPay.txt", ios::in);
					while (getline(file1, infoLine)) {
						string customerID = trim(infoLine.substr(170, 20));
						if (customerID == customer_ID) {
							isPresent = true;

							name = infoLine.substr(0, 40);
							id = infoLine.substr(40, 20);
							quantityString = infoLine.substr(60, 20);
							priceString = infoLine.substr(80, 20);
							totalPriceString = infoLine.substr(100, 20);
							dateModified = infoLine.substr(120, 50);
							

							double priceDouble = stod(trim(priceString));
							stringstream stream;
							stream << fixed << setprecision(2) << priceDouble;
							priceString = rightPad(stream.str(), 20);

							double totalDouble = stod(trim(totalPriceString));
							stringstream stream2;
							stream2 << fixed << setprecision(2) << totalDouble;
							totalPriceString = rightPad(stream2.str(), 20);

							cout << name << "|" << id << "|" << quantityString << "|" << priceString << "|" << totalPriceString << "|" << dateModified << "|" << endl;

						}
					}
					for (int i = 0; i < 176; i++) {
						cout << "-";
					}
					cout << endl;
					file1.close();
					if (!isPresent) {
						cout << "There isn't anything in the cart yet"  << endl;
					}

					cout << "Would you like to continue viewing the details of the cart? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}


	void edit(string customer_ID) {
		fstream file1;
		fstream file2;
		fstream temp;
		file1.open("CustomerToPay.txt", ios::in);
		temp.open("temp.txt", ios::app);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Editing Item in Cart" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No Items are added to the cart yet. Please add some items to the cart first!" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			file1.close();
			temp.close();
		}
		else {
			string infoLine;
			string nameEdit;
			if (file1.is_open()) {
				file1.close();
				temp.close();
				int flag1 = 1;
				do {
					cout << rightPad(" ", 20) << "Editing Items in Cart" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					file1.open("CustomerToPay.txt", ios::in);
					temp.open("temp.txt", ios::app);
					bool isPresent = false;
					int quantity = 1;
					cout << "Enter the name of the item in the cart that you want to edit: ";
					getline(cin >> ws, nameEdit);
					cout << endl;
					while (getline(file1, infoLine)) {
						string givenProductName = trim(infoLine.substr(0, 40));
						string id = infoLine.substr(40, 20);
						string quantityString = infoLine.substr(60, 20);
						string priceString = infoLine.substr(80, 20);
						string totalPriceString = infoLine.substr(100, 20);
						string dateModified = infoLine.substr(120, 50);
						string customerID = infoLine.substr(170, 20);
						if (givenProductName == nameEdit && trim(customerID) == customer_ID) {
							isPresent = true;
							cout << "Editing item details" << endl;
							for (int i = 0; i < 50; i++) {
								cout << "-";
							}
							cout << endl;
							cout << "Please enter the quantity of the item: ";
							do {
								if (quantity < 0) {
									cout << "Please enter a positive number!" << endl;
									cout << "Please enter the quantity of the item: ";
								}
								while (!(cin >> quantity)) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Please enter a valid input: ";
								}
							} while (quantity < 0);
							string quantityStr = to_string(quantity);
							quantityStr = rightPad(quantityStr, 20); 
							cout << endl;

							string totalPriceString = rightPad(to_string(quantity * stoi(trim(priceString))), 20);
							

							time_t now = time(0);
							char nowBuff[50];
							ctime_s(nowBuff, sizeof(nowBuff), &now);
							nowBuff[strlen(nowBuff) - 1] = '\0';
							string nowString = rightPad(nowBuff, 50);
							if (quantity > 0) {
								temp << rightPad(givenProductName,40) << id << quantityStr << priceString << totalPriceString << nowString << customerID << endl;
							}
						}
						else {
							temp << infoLine << endl;
						}
					}
					file1.close();
					temp.close();

					remove("CustomerToPay.txt");
					rename("temp.txt", "CustomerToPay.txt");

					if (!isPresent) {
						cout << "There isn't a match between the item name in your cart with the item name that you've inputted" << endl;
					}
					cout << "Would you like to continue editing the items in cart? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}

					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}


	void deleteItem(string customer_ID) {
		fstream file1;
		fstream temp;
		cout << "===================================================================" << endl;
		file1.open("CustomerToPay.txt", ios::in);
		temp.open("temp.txt", ios::app);
		if (!file1) {
			cout << rightPad(" ", 20) << "Deleting Item in Cart " << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No Item exist in cart yet. Please create one first" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string itemDelete;
			string name, id, quantityString, totalPriceString, dateModified, priceString;
			if (file1.is_open()) {
				file1.close();
				temp.close();
				int flag1 = 1;
				do {
					file1.open("CustomerToPay.txt", ios::in);
					temp.open("temp.txt", ios::app); 
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Deleting Item in cart" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					cout << "Enter the Name of the Product in the cart that you want to delete: ";
					getline(cin >> ws, itemDelete);
					cout << endl;
					while (getline(file1, infoLine)) {
						string customerID = trim(infoLine.substr(170, 20));
						if (customerID == customer_ID) {
							name = infoLine.substr(0, 40);
							id = infoLine.substr(40, 20);
							quantityString = infoLine.substr(60, 20);
							priceString = infoLine.substr(80, 20);
							totalPriceString = infoLine.substr(100, 20);
							dateModified = infoLine.substr(120, 50);

							if (trim(name) == itemDelete) {
								isPresent = true;
								cout << trim(name) << " has been removed from the cart" << endl << endl;
							}
							else {
								temp << infoLine << endl;

							}
						}
					}

					file1.close();
					temp.close();
					remove("CustomerToPay.txt");
					rename("temp.txt", "CustomerToPay.txt");
					if (!isPresent) {
						cout << "There isn't a match between the Item name in the cart with the Item Name that you've inputted" << endl;
					}

					cout << "Would you like to continue deleting Items in the cart? [Press 1 to continue] : ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}

					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}

	void pay(string customer_Username, string customer_ID) {
		string name, id, quantityString, priceString, totalPriceString, totalPriceStringUpdated, dateModified, infoLine, creditCardNum, customerID, initialQuantity, addedString;
		int proceed, proceed2, counter, added;
		double totalPrice = 0;
		int totalItem = 0, maxOrderId = 0;
		fstream file1, file2, file3, temp, temp2;
		file1.open("CustomerToPay.txt", ios::in);

		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Buying the items in the cart" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "No item exist in cart yet. Please create one" << endl;
		}
		else {
			file1.close();
			cout << rightPad(" ", 20) << "Buying the items in the cart" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			for (int i = 0; i < 63; i++) {
				cout << "-";
			}
			cout << endl;

			file1.open("CustomerToPay.txt", ios::in);
			while (getline(file1, infoLine)) {

				name = infoLine.substr(0, 40);
				id = infoLine.substr(40, 20);
				quantityString = infoLine.substr(60, 20);
				priceString = infoLine.substr(80, 20);
				totalPriceString = infoLine.substr(100, 20);
				dateModified = infoLine.substr(120, 50);
				string idOfCustomer = infoLine.substr(170, 20);
				if (customer_ID == trim(idOfCustomer)) {
					double totalPriceDouble = stod(trim(totalPriceString));
					totalPrice += totalPriceDouble;
				}
			}
			file1.close();

			stringstream stream;
			stream << fixed << setprecision(2) << totalPrice;
			totalPriceStringUpdated = rightPad(stream.str(), 20);

			cout << "Total Price: " << totalPriceStringUpdated << endl << endl;
			if (totalPrice > 0) {
				cout << "Do you wish to pay now? [Press 1 to pay]: ";
				while (!(cin >> proceed)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Please enter an integer: ";
				}
				cout << endl;
				if (proceed == 1) {
					proceed2 = 0;
					do {
						cout << "Please enter your credit card detail: ";
						getline(cin >> ws, creditCardNum);
						cout << endl;
						int sumOfEven = 0;
						int sumOfOdds = 0;
						int sumOfLargerSum = 0;
						//374245455400126
						//3 4 4 4 5 0 1 6 = 27
						//7 2 5 5 4 0 2 = 14 4 10 10 8 0 4 = 5 4 1 1 8 0 4 = 23
						//23+257 = 50
						if (is_digits(creditCardNum) && creditCardNum.length() > 14 && creditCardNum.length() <= 16) {
							for (int i = 1; i < creditCardNum.length(); i += 2) {
								int numDoubled = ((int(creditCardNum[i]) - 48) * 2);
								if (numDoubled >= 10) {
									string largerSum = to_string(numDoubled);
									for (int j = 0; j < largerSum.length(); j++) {
										sumOfEven += (int(largerSum[j]) - 48);

									}
								}
								else {
									sumOfEven += numDoubled;
								}

							}
							for (int j = 0; j < creditCardNum.length(); j += 2) {
								sumOfOdds += (int(creditCardNum[j]) - 48);
							}
							sumOfLargerSum = sumOfOdds + sumOfEven;

							if (sumOfLargerSum % 10 == 0) {
								string infoLine;
								string tempInfoLine;
								int flag1 = 1;
								bool isPresent = false;
								int expiryMonth;
								int expiryYear;
								string securityCode;


								cout << "Please enter the expiry month [MM]: ";
								while (!(cin >> expiryMonth)) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Represent the month with a number, E.g. October is 10" << endl;
									cout << "Invalid input.  Please enter an integer: ";
								}
								cout << endl;

								cout << "Please enter the expiry year [YY]: ";
								while (!(cin >> expiryYear)) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Please enter an integer: ";
								}
								cout << endl;

								if (expiryMonth >= 1 && expiryMonth <= 12 && expiryYear >= 0 && expiryYear <= 100) {
									time_t t = time(NULL);
									tm timePtr;
									localtime_s(&timePtr, &t);
									int currentMonth = timePtr.tm_mon + 1;
									cout << "THE TIME IS: " << currentMonth << endl;
									int currentYear = (timePtr.tm_year) - 100;

									if (expiryYear > currentYear || (expiryYear == currentYear && expiryMonth >= currentMonth)) {

										file2.open("Order.txt", ios::in);
										if (!file2) {
											counter = 1;
										}
										else {
											string lastLine;
											while (getline(file2, lastLine)) {
												counter = stoi(trim(lastLine.substr(210, 20))) + 1;
											}

										}
										file2.close();

										do {
											cout << "Please enter your security number: ";
											getline(cin >> ws, securityCode);
											cout << endl;
										} while (!is_digits(securityCode) || securityCode.length() != 3);

										file1.open("CustomerToPay.txt", ios::in);
										temp2.open("temp2.txt", ios::app);
										while (getline(file1, infoLine)) {
											name = infoLine.substr(0, 40);
											id = infoLine.substr(40, 20);
											quantityString = infoLine.substr(60, 20);
											priceString = infoLine.substr(80, 20);
											totalPriceString = infoLine.substr(100, 20);
											dateModified = infoLine.substr(120, 50);
											customerID = infoLine.substr(170, 20);

											if (trim(customerID) == customer_ID) {
												isPresent = true;


												file2.open("Order.txt", ios::app);
												time_t now = time(0);
												char nowBuff[50];
												ctime_s(nowBuff, sizeof(nowBuff), &now);
												nowBuff[strlen(nowBuff) - 1] = '\0';
												string nowString = rightPad(nowBuff, 50);

												file3.open("Product.txt", ios::in);
												temp.open("temp.txt", ios::app);
												string productLine;
												while (getline(file3, productLine)) {
													string productName = productLine.substr(0, 40);
													string id = productLine.substr(40, 20);
													string description = productLine.substr(60, 50);
													string quantity = productLine.substr(110, 20);
													string price = productLine.substr(130, 20);
													string dateModified = productLine.substr(150, 50);
													string category = productLine.substr(200, 20);
													string location = productLine.substr(220, 20);
													if (trim(name) == trim(productName)) {
														initialQuantity = rightPad(trim(productLine.substr(110, 20)), 10);
														int newQuantity = stoi(trim(initialQuantity)) - stoi(trim(quantityString));
														string newQuantityString = rightPad(to_string(newQuantity), 20);
														temp << productName << id << description << newQuantityString << price << nowString << category << location << endl;
													}
													else {
														temp << productLine << endl;
													}
												}
												file3.close();
												temp.close();
												remove("Product.txt");
												rename("temp.txt", "Product.txt");

												int finalQuantity = stoi(trim(initialQuantity)) - stoi(trim(quantityString));
												added = stoi(trim(quantityString));
												added *= -1;
												addedString = rightPad(to_string(added), 10);
												string finalQuantityString = rightPad(to_string(finalQuantity), 20);

												file2 << name << id << finalQuantityString << rightPad(customer_Username, 20) << rightPad(customer_ID, 20) << priceString << totalPriceString << nowString << rightPad(to_string(counter), 20) << initialQuantity << addedString << endl;
												//40 + 20 + 20 + 20 + 20 + 20 + 20 + 50 + 20 + 10 + 10= 250
												file2.close();
											}
											else {
												temp2 << infoLine << endl;
											}

										}
										file1.close();
										temp.close();
										temp2.close();
										remove("CustomerToPay.txt");
										rename("temp2.txt", "CustomerToPay.txt");
										cout << "Thank you for shopping with us! Enjoy your newly bought products!" << endl;
										proceed2 = 0;
									}
									else {
										cout << "It appears that your credit card has already expired, Would you like to try again?" << endl;
										cout << "Press 1 to try again: ";
										while (!(cin >> proceed2)) {
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "Invalid input.  Please enter an integer: ";
										}
									}
								}
								else {
									cout << "It appears that the expiry month or date that you've entered is out of range, Would you like to try again?" << endl;
									cout << "Press 1 to try again: ";
									while (!(cin >> proceed2)) {
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Invalid input.  Please enter an integer: ";
									}
								}
							}
							else {
								cout << "It appears that you've entered an invalid credit card number, Would you like to try again?" << endl;
								cout << "Press 1 to try again: ";
								while (!(cin >> proceed2)) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "Invalid input.  Please enter an integer: ";
								}
							}
						}
						else {
							cout << "It appears that you've entered an invalid credit card number, Would you like to try again?" << endl;
							cout << "Press 1 to try again: ";
							while (!(cin >> proceed2)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter an integer: ";
							}
						}
					} while (proceed2 == 1);
				}
			}
			else {
				cout << "Please add something to your cart first!" << endl;
			}
		}

	}

	void customerHistory(string customer_ID) {
		fstream file1;
		file1.open("Order.txt", ios::in);
		cout << "===================================================================" << endl;
		if (!file1) {
			cout << rightPad(" ", 20) << "Customer Order History" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "You haven't ordered anything yet. Please order something first!" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
		}
		else {
			string infoLine;
			string idSearch;

			if (file1.is_open()) {
				file1.close();
				int flag1 = 1;
				do {
					file1.open("Order.txt", ios::in);
					bool isPresent = false;
					cout << rightPad(" ", 20) << "Customer Order History" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;


					cout << endl;

					for (int i = 0; i < 216; i++) {
						cout << "-";
					}
					cout << endl;

					cout << rightPad("Product Name", 40) << "|" << rightPad("Product ID", 20) << "|" << rightPad("Initial", 10) << "|" << rightPad("Changes", 10) << "|" << rightPad("Quantity", 10) << "|" << rightPad("Username of Orderer", 20) << "|" << rightPad("ID of Orderer", 20) << "|" << rightPad("Price per Unit (RM)", 20) << "|" << rightPad("Total Price (RM)", 20) << "|" << rightPad("Last Modified", 25) << "|" << rightPad("Order ID", 10) << "|" << endl;

					for (int i = 0; i < 216; i++) {
						cout << "-";
					}
					cout << endl;

					while (getline(file1, infoLine)) {
						string givenCustomerID= trim(infoLine.substr(100, 20));

						if (givenCustomerID == customer_ID) {

							isPresent = true;


							string productName = infoLine.substr(0, 40);
							string productId = infoLine.substr(40, 20);
							string quantity = trim(infoLine.substr(60, 20));
							string username = infoLine.substr(80, 20);
							string id = infoLine.substr(100, 20);
							string price = infoLine.substr(120, 20);
							string totalPrice = infoLine.substr(140, 20);
							string dateModified = trim(infoLine.substr(160, 50));
							string orderId = trim(infoLine.substr(210, 20));
							string givenInitialQty = infoLine.substr(230, 10);
							string givenQuantityOrdered = infoLine.substr(240, 10);

							int number_of_zeroes = 4 - orderId.length();
							orderId.insert(0, number_of_zeroes, '0');
							string givenOrderIdString = "ORD-" + orderId;

							double priceDouble = stod(trim(price));
							stringstream stream;
							stream << fixed << setprecision(2) << priceDouble;
							price = rightPad(stream.str(), 20);

							double totalPriceDouble = stod(trim(totalPrice));
							stringstream stream2;
							stream2 << fixed << setprecision(2) << totalPriceDouble;
							totalPrice = rightPad(stream2.str(), 20);

							cout << productName << "|" << productId << "|" << givenInitialQty << "|" << givenQuantityOrdered << "|" << rightPad(quantity, 10) << "|" << username << "|" << id << "|" << price << "|" << totalPrice << "|" << rightPad(dateModified, 25) << "|" << rightPad(givenOrderIdString, 10) << "|" << endl;
							//40 + 20 + 10 + 10 + 10 + 20 + 20 + 20 + 20 + 25 + 10

						}


					}
					for (int i = 0; i < 216; i++) {
						cout << "-";
					}
					cout << endl;

					file1.close();
					if (!isPresent) {
						cout << "You haven't ordered anything yet, please order some products first!" << endl;
					}

					cout << "Would you like to continue viewing the details of the orders? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter an integer: ";
					}
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
				} while (flag1 == 1);

			}
		}
	}
	int customerLogin() {
		string password, username, infoLine;
		fstream my_file;
		my_file.open("Customer.txt", ios::in);
		if (!my_file) {
			cout << "No Customer account exist yet. Wait for the admin to create one" << endl;
			return 0;
		}
		else {
			if (my_file.is_open()) {
				my_file.close();
				int flag1 = 1;
				while (flag1 == 1) {
					my_file.open("Customer.txt", ios::in);
					cout << "===================================================================" << endl;
					cout << rightPad(" ", 20) << "Customer Login" << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}

					cout << endl;
					cout << "Enter your username: ";
					getline(cin >> ws, username);
					cout << endl;
					cout << "Enter your password: ";
					getline(cin >> ws, password);
					cout << endl;
					while (getline(my_file, infoLine)) {
						string givenName = trim(infoLine.substr(0, 20));
						string givenPassword = trim(infoLine.substr(20, 20));
						string id = trim(infoLine.substr(150, 20));
						if (givenName == username && givenPassword == password) {
							flag1 = 0;
							cout << "Login success!" << endl;
							customerID = id;
							customerUsername = givenName;
							for (int i = 0; i < 50; i++) {
								cout << "-";
							}
							cout << endl;
							my_file.close();
							return 1;
						}

					}
					cout << "The username or password that you've entered is incorrect" << endl;
					cout << "Would you like to continue or return to the homepage? [Press 1 to continue]: ";
					while (!(cin >> flag1)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter a valid input: ";
					}
					cout << endl;
					for (int i = 0; i < 50; i++) {
						cout << "-";
					}
					cout << endl;
					my_file.close();
				}

			}
		}

		return 0;
	}

};


int main() {
	int choice = -1;
	bool isLoggedIn = false;
	fstream currentManager;
	currentManager.open("currentManager.txt", ios::in);
	if (currentManager) {
		currentManager.close();
		remove("currentManager.txt");
	}
	fstream currentCustomer;
	currentCustomer.open("currentCustomer.txt", ios::in);
	if (currentCustomer) {
		currentCustomer.close();
		remove("currentCustomer.txt");
	}
	do {
		if (choice == -1) {
			cout << "===================================================================" << endl;
			cout << rightPad(" ", 15) << "Online Shopping Management System" << endl;
			cout << rightPad(" ", 27) << "Main Menu" << endl << endl;
			cout << "You can log in with your role or exit the system" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "You may pick from the options listed below: " << rightPad(" ", 5) << "|" << endl;
			cout << rightPad(" ", 49) << "|" << endl;
			cout << "1. Admin Login" << rightPad(" ", 35) << "|" << endl;
			cout << "2. Manager Login" << rightPad(" ", 33) << "|" << endl;
			cout << "3. Customer Login" << rightPad(" ", 32) << "|" << endl;
			cout << "4. Exit" << rightPad(" ", 42) << "|" << endl;
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			cout << "Please enter your choice: ";
			while (!(cin >> choice)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.  Please enter a valid input: ";
			}
			cout << endl;
		}

		if (choice == 1) {
			int loginSuccess;
			int adminChoice  = 0;
			AdminManager AM;
			if (!isLoggedIn) {
				loginSuccess = AM.adminLogin();
			}
			else {
				loginSuccess = 1;
			}
			if (loginSuccess == 1) {
				for (int i = 0; i < 50; i++) {
					cout << "=";
				}
				cout << endl;
				cout << rightPad(" ", 16) << "Welcome Back Admin!" << endl;
				cout << rightPad(" ", 16) << "Administritive Page" << endl;
				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
				cout << "What would you like to do?" << rightPad(" ", 23) << "|" << endl;
				cout << rightPad(" ", 49) << "|" << endl;
				cout << "1. Manage Manager's Account" << rightPad(" ", 22) << "|" << endl;
				cout << "2. Manage Customer's Account" << rightPad(" ", 21) << "|" << endl;
				cout << "3. Change Admin Details" << rightPad(" ", 26) << "|" << endl;
				cout << "4. Logout" << rightPad(" ", 40) << "|" << endl;
				cout << "5. Return to Main Menu" << rightPad(" ", 27) << "|" << endl;
				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
				cout << "Please enter your choice: ";
				while (!(adminChoice >= 1 && adminChoice <= 5)) {
					while (!(cin >> adminChoice)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter a valid input: ";
					}
				}
				cout << endl;
				switch (adminChoice) {
				case 1:
				{
					int adminManageManager = 0;
					do {
						cout << "===================================================================" << endl;
						cout << rightPad(" ", 20) << "Managing Managers account" << endl;
						cout << rightPad(" ", 20) << "What would you like to do?" << endl;
						for (int i = 0; i < 50; i++) {
							cout << "-";
						}
						cout << endl;
						cout << "1. Create Manager Account" << rightPad(" ", 24) << "|" << endl;
						cout << "2. Delete Manager Account" << rightPad(" ", 24) << "|" << endl;
						cout << "3. Edit Manager Account Details" << rightPad(" ", 18) << "|" << endl;
						cout << "4. View All Manager Account" << rightPad(" ", 22) << "|" << endl;
						cout << "5. Search for Manager Account" << rightPad(" ", 20) << "|" << endl;
						cout << "6. Return to Administrative page" << rightPad(" ", 17) << "|" << endl; 
						cout << "7. Exit" << rightPad(" ", 42) << "|" << endl;
						for (int i = 0; i < 50; i++) {
							cout << "-";
						}
						cout << endl;
						cout << "Please enter your choice: ";  
						while (!(adminManageManager >= 1 && adminManageManager <= 7)) {
							while (!(cin >> adminManageManager)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter a valid input: ";  
							}
						}
						if (adminManageManager == 1) {
							AdminManager AM;
							AM.addAccount(); 
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 2) {
							//delete
							AdminManager AM;
							AM.displayAllAccounts();
							AM.deleteAccount();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 3) {
							//edit
							AdminManager AM;
							AM.displayAllAccounts();
							AM.editAccount();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 4) {
							//view all
							AdminManager AM;
							AM.displayAllAccounts();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 5) {
							//Search
							AdminManager AM;
							AM.searchAccount();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 6) {
							isLoggedIn = true;
							break;

						}
						else if (adminManageManager == 7) {
							isLoggedIn = false; 
							choice = 4;
						}
						else {
							//invalid
							cout << "Invalid input. Please enter a valid input based on the list below. " << endl;
							adminManageManager = 0;
						}
					} while (adminManageManager != 7);
					break;// for case 1
				}
				case 2: {
					int adminManageManager = 0;
					do {
						cout << "===================================================================" << endl;
						cout << rightPad(" ", 20) << "Managing Customers account" << endl;
						cout << rightPad(" ", 20) << "What would you like to do?" << endl;
						for (int i = 0; i < 50; i++) {
							cout << "-";
						}
						cout << endl;
						cout << "1. Create Customer Account" << rightPad(" ", 23) << "|" << endl;
						cout << "2. Delete Customer Account" << rightPad(" ", 23) << "|" << endl;
						cout << "3. Edit Customer Account Details" << rightPad(" ", 17) << "|" << endl;
						cout << "4. View All Customer Account" << rightPad(" ", 21) << "|" << endl;
						cout << "5. Search for Customer Account" << rightPad(" ", 19) << "|" << endl;
						cout << "6. Return to Administrative page" << rightPad(" ", 17) << "|" << endl; 
						cout << "7. Exit" << rightPad(" ", 42) << "|" << endl;
						for (int i = 0; i < 50; i++) {
							cout << "-";
						}
						cout << endl;
						cout << "Please enter your choice: ";  
						while (!(adminManageManager >= 1 && adminManageManager <= 7)) {
							while (!(cin >> adminManageManager)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter a valid input: "; 
							}
						}
						if (adminManageManager == 1) {
							AdminCustomer AC;
							AC.fileName = "Customer.txt";
							AC.role = "Customer";
							AC.addAccount();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 2) {
							//delete
							AdminCustomer AC;
							AC.fileName = "Customer.txt";
							AC.role = "Customer";  
							AC.displayAllAccounts();
							AC.deleteAccount();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 3) {
							//edit
							AdminCustomer AC;
							AC.fileName = "Customer.txt";
							AC.role = "Customer";
							AC.displayAllAccounts();
							AC.editAccount();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 4) {
							//view all
							AdminCustomer AC;
							AC.fileName = "Customer.txt";
							AC.role = "Customer";
							AC.displayAllAccounts();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 5) {
							//Search
							AdminCustomer AC;
							AC.fileName = "Customer.txt";
							AC.role = "Customer";
							AC.searchAccount();
							adminManageManager = 0;
							isLoggedIn = false;
						}
						else if (adminManageManager == 6) {
							isLoggedIn = true;
							break;

						}
						else if (adminManageManager == 7) {
							isLoggedIn = false;
							choice = 4;
						}
						else {
							//invalid
							cout << "Invalid input. Please enter a valid input based on the list below. " << endl;
							adminManageManager = 0;
						}
					} while (adminManageManager != 7);
					break;
				}
				case 3: {
					AdminManager AM;
					AM.changeAdminLogin();
					break;
				}
				case 4: {
					;
					break;
				}
				case 5: {
					choice = -1;
					isLoggedIn = false;
					break;
				}
				default: {
					;
					break;
				}
				}
			}
			else {
				choice = -1;
			}
		}
		else if (choice == 2) {
			int loginSuccess;
			string managerUsername;
			string managerID;
			int managerChoice = 0;
			ManagerOrder MO;

			if (!isLoggedIn) {
				loginSuccess = MO.managerLogin();
				managerUsername = MO.managerUsername;
				managerID = MO.managerId;
				currentManager.open("currentManager.txt", ios::app);
				currentManager << managerUsername << endl;
				currentManager << managerID << endl;
				currentManager.close();
			}
			else {
				loginSuccess = 1;
			}
			if (loginSuccess == 1) {
				for (int i = 0; i < 50; i++) {
					cout << "=";
				}
				cout << endl;
				cout << rightPad(" ", 16) << "Welcome Back Manager!" << endl;
				cout << rightPad(" ", 17) << "Manager Home Page" << endl; 
				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
				cout << "What would you like to do?" << rightPad(" ", 23) << "|" << endl;
				cout << rightPad(" ", 49) << "|" << endl;
				cout << "1. Manage Product" << rightPad(" ", 32) << "|" << endl;
				cout << "2. Manage Order" << rightPad(" ", 34) << "|" << endl;
				cout << "3. Logout" << rightPad(" ", 40) << "|" << endl;
				cout << "4. Return to Main Menu" << rightPad(" ", 27) << "|" << endl;
				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
				cout << "Please enter your choice: ";
				while (!(managerChoice >= 1 && managerChoice<= 4)) {
					while (!(cin >> managerChoice)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter a valid input: "; 
					}
				}
				cout << endl;
				switch (managerChoice) {
				case 1:
				{
					int managerProduct = 0;
					do {
						cout << "===================================================================" << endl;
						cout << rightPad(" ", 17) << "Managing Product" << endl;
						cout << rightPad(" ", 12) << "What would you like to do?" << endl;
						for (int i = 0; i < 50; i++) {
							cout << "-";
						}
						cout << endl;
						cout << "1. Create New Product" << rightPad(" ", 28) << "|" << endl;
						cout << "2. Delete Existing Product" << rightPad(" ", 23) << "|" << endl;
						cout << "3. Edit Existing Product Details" << rightPad(" ", 17) << "|" << endl;
						cout << "4. View All Products" << rightPad(" ", 29) << "|" << endl;
						cout << "5. Search for Product" << rightPad(" ", 28) << "|" << endl;
						cout << "6. Return to Home page" << rightPad(" ", 27) << "|" << endl; 
						cout << "7. Exit" << rightPad(" ", 42) << "|" << endl;
						for (int i = 0; i < 50; i++) {
							cout << "-";
						}
						cout << endl;
						cout << "Please enter your choice: ";  
						while (!(managerProduct >= 1 && managerProduct <= 7)) {
							while (!(cin >> managerProduct)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter a valid input: "; 
							}
						}
						if (managerProduct == 1) {
							ManagerProduct MP;
							MP.addItem();
							managerProduct = 0;
							isLoggedIn = false;
						}
						else if (managerProduct == 2) {
							//delete
							ManagerProduct MP;
							MP.displayAllProducts();
							MP.deleteItem(); 
							managerProduct = 0;
							isLoggedIn = false;
						}
						else if (managerProduct == 3) {
							//edit
							ManagerProduct MP;
							MP.displayAllProducts();
							MP.edit();
							managerProduct = 0;
							isLoggedIn = false;
						}
						else if (managerProduct == 4) {
							//view all
							ManagerProduct MP;
							MP.displayAllProducts();
							managerProduct = 0;
							isLoggedIn = false;
						}
						else if (managerProduct == 5) {
							//Search
							ManagerProduct MP;
							MP.search();
							managerProduct = 0;
							isLoggedIn = false;
						}
						else if (managerProduct == 6) {
							isLoggedIn = true;
							break;

						}
						else if (managerProduct == 7) {
							isLoggedIn = false;
							choice = 4;
						}
						else {
							//invalid
							cout << "Invalid input. Please enter a valid input based on the list below. " << endl;
							managerProduct = 0;
						}
					} while (managerProduct != 7);
					break;
				}
				case 2: {
					int managerOrder = 0;
					do {
						cout << "===================================================================" << endl;
						cout << rightPad(" ", 17) << "Managing Orders" << endl;
						cout << rightPad(" ", 12) << "What would you like to do?" << endl;
						for (int i = 0; i < 50; i++) {
							cout << "-";
						}
						cout << endl;
						cout << "1. Create New Orders" << rightPad(" ", 29) << "|" << endl;
						cout << "2. Delete Existing Orders" << rightPad(" ", 24) << "|" << endl;
						cout << "3. Edit Existing Order Details" << rightPad(" ", 19) << "|" << endl;
						cout << "4. View All Existing Order Details" << rightPad(" ", 15) << "|" << endl;
						cout << "5. Search for Existing Orders" << rightPad(" ", 20) << "|" << endl;
						cout << "6. Return to Home page" << rightPad(" ", 27) << "|" << endl; 
						cout << "7. Exit" << rightPad(" ", 42) << "|" << endl;
						for (int i = 0; i < 50; i++) {
							cout << "-";
						}
						cout << endl;
						cout << "Please enter your choice: ";  
						while (!(managerOrder >= 1 && managerOrder <= 7)) {
							while (!(cin >> managerOrder)) {
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Invalid input.  Please enter a valid input: "; 
							}
						}
						if (managerOrder == 1) {
							ManagerOrder MP;
							fstream currentManager;
							string idOfManager;
							string usernameOfManager;
							currentManager.open("currentManager.txt", ios::in);
							getline(currentManager, usernameOfManager);
							getline(currentManager, idOfManager);
							currentManager.close();
							MP.addItem(idOfManager, usernameOfManager);
							managerOrder = 0;
							isLoggedIn = false;
						}
						else if (managerOrder == 2) {
							//delete
							ManagerOrder MP;
							MP.displayAllProducts();
							MP.deleteItem();
							managerOrder = 0;
							isLoggedIn = false;
						}
						else if (managerOrder == 3) {
							//edit
							ManagerOrder MP;
							MP.displayAllProducts();
							MP.edit();
							
							managerOrder = 0;
							isLoggedIn = false;
						}
						else if (managerOrder == 4) {
							//view all
							ManagerOrder MP;
							MP.displayAllProducts();
							MP.summary();
							managerOrder = 0;
							isLoggedIn = false;
						}
						else if (managerOrder == 5) {
							//Search
							ManagerOrder MP;
							MP.search();
							managerOrder = 0;
							isLoggedIn = false;
						}
						else if (managerOrder == 6) {
							isLoggedIn = true;
							break;

						}
						else if (managerOrder == 7) {
							isLoggedIn = false; 
							choice = 4;
						}
						else {
							//invalid
							cout << "Invalid input. Please enter a valid input based on the list below. " << endl;
							managerOrder = 0;
						}
					} while (managerOrder != 7);
					break;
				}
				case 3: {
					;
					break;
				}
				case 4: {
					choice = -1;
					isLoggedIn = false;
					break;
				}
				default: {
					;
					break;
				}
				}
			}
			else {
				choice = -1;
			}
		}
		else if (choice == 3) {
		int loginSuccess;
		string customerUsername;
		string customerID;
		int customerChoice = 0;
		Customer C;
		if (!isLoggedIn) {

			loginSuccess = C.customerLogin();
			customerUsername = C.customerUsername;
			customerID = C.customerID;
			currentCustomer.open("currentCustomer.txt", ios::app);
			currentCustomer << customerUsername << endl;
			currentCustomer << customerID << endl;
			currentCustomer.close();
		}
		else {
			loginSuccess = 1;
		}
		if (loginSuccess == 1) {
			for (int i = 0; i < 50; i++) {
				cout << "=";
			}
			cout << endl;
			cout << rightPad(" ", 16) << "Welcome Back Customer!" << endl;
			cout << rightPad(" ", 13) << "Customer Home Page" << endl; 
			for (int i = 0; i < 50; i++) {
				cout << "-";
			}
			cout << endl;
			int customerChoice = 0;
			do {
				cout << "===================================================================" << endl;
				cout << rightPad(" ", 20) << "What would you like to do?" << endl;
				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
				cout << "1. View All Products" << rightPad(" ", 29) << "|" << endl;
				cout << "2. Search for a Product" << rightPad(" ", 26) << "|" << endl;
				cout << "3. Shop" << rightPad(" ", 42) << "|" << endl;
				cout << "4. View Cart" << rightPad(" ", 37) << "|" << endl;
				cout << "5. Edit Cart" << rightPad(" ", 37) << "|" << endl;
				cout << "6. Delete Items in Cart" << rightPad(" ", 26) << "|" << endl;
				cout << "7. Pay for Items in Cart" << rightPad(" ", 25) << "|" << endl;
				cout << "8. View Order History" << rightPad(" ", 28) << "|" << endl;
				cout << "9. Logout" << rightPad(" ", 40) << "|" << endl;
				cout << "10. Exit" << rightPad(" ", 41) << "|" << endl;
				cout << "11. Return to Main Menu" << rightPad(" ", 26) << "|" << endl;
				for (int i = 0; i < 50; i++) {
					cout << "-";
				}
				cout << endl;
				cout << "Please enter your choice: ";  
				while (!(customerChoice >= 1 && customerChoice <= 11)) {
					while (!(cin >> customerChoice)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid input.  Please enter a valid input: ";   
					}
				}
				if (customerChoice == 1) {
					ManagerProduct MP;
					MP.displayAllProducts();
					customerChoice = 0;
					isLoggedIn = false;
				}
				else if (customerChoice == 2) {
					//delete
					ManagerProduct MP;
					MP.search();
					customerChoice = 0;
					isLoggedIn = false;
				}
				else if (customerChoice == 3) {
					//edit
					ManagerProduct MP;
					Customer C;
					fstream currentCustomer;
					string idOfCustomer;
					string usernameOfCustomer;
					MP.displayAllProducts();
					currentCustomer.open("currentCustomer.txt", ios::in);
					getline(currentCustomer, usernameOfCustomer);
					usernameOfCustomer = trim(usernameOfCustomer);
					getline(currentCustomer, idOfCustomer);
					idOfCustomer = trim(idOfCustomer);
					currentCustomer.close();
					C.shop(idOfCustomer);
					customerChoice = 0;
					isLoggedIn = false;

				}
				else if (customerChoice == 4) {
					//view all
					Customer C;
					fstream currentCustomer;
					string idOfCustomer;
					string usernameOfCustomer;
					currentCustomer.open("currentCustomer.txt", ios::in);
					getline(currentCustomer, usernameOfCustomer);
					usernameOfCustomer = trim(usernameOfCustomer);
					getline(currentCustomer, idOfCustomer);
					idOfCustomer = trim(idOfCustomer);
					currentCustomer.close();
					C.ViewCart(idOfCustomer);
					customerChoice = 0;
					isLoggedIn = false;
				}
				else if (customerChoice == 5) {
					//view all
					Customer C;
					fstream currentCustomer;
					string idOfCustomer;
					string usernameOfCustomer;
					currentCustomer.open("currentCustomer.txt", ios::in);
					getline(currentCustomer, usernameOfCustomer);
					usernameOfCustomer = trim(usernameOfCustomer);
					getline(currentCustomer, idOfCustomer);
					idOfCustomer = trim(idOfCustomer);
					currentCustomer.close();
					C.ViewCart(idOfCustomer);
					C.edit(idOfCustomer);
					customerChoice = 0;
					isLoggedIn = false;
				}
				else if (customerChoice == 6) {
					//view all
					Customer C;
					fstream currentCustomer;
					string idOfCustomer;
					string usernameOfCustomer;
					currentCustomer.open("currentCustomer.txt", ios::in);
					getline(currentCustomer, usernameOfCustomer);
					getline(currentCustomer, idOfCustomer);
					currentCustomer.close();
					C.ViewCart(idOfCustomer);
					C.deleteItem(idOfCustomer);
					customerChoice = 0;
					isLoggedIn = false;
				}
				else if (customerChoice == 7) {
					//view all
					Customer C;
					fstream currentCustomer;
					string idOfCustomer;
					string usernameOfCustomer;
					currentCustomer.open("currentCustomer.txt", ios::in);
					getline(currentCustomer, usernameOfCustomer);
					getline(currentCustomer, idOfCustomer);
					currentCustomer.close();
					C.ViewCart(idOfCustomer);
					C.pay(usernameOfCustomer, idOfCustomer);
					customerChoice = 0;
					isLoggedIn = false;
				}
				else if (customerChoice == 8) {
					//view all
					Customer C;
					fstream currentCustomer;
					string idOfCustomer;
					string usernameOfCustomer;
					currentCustomer.open("currentCustomer.txt", ios::in);
					getline(currentCustomer, usernameOfCustomer);
					usernameOfCustomer = trim(usernameOfCustomer);
					getline(currentCustomer, idOfCustomer);
					idOfCustomer = trim(idOfCustomer);
					currentCustomer.close();
					C.customerHistory(idOfCustomer);
					customerChoice = 0;
					isLoggedIn = false;
				}
				else if (customerChoice == 9) {
					isLoggedIn = false;
				}
				else if (customerChoice == 10) {
					isLoggedIn = false; 
					choice = 4;
				}
				else if (customerChoice == 11) {
					choice = -1;
				}
				else {
					//invalid
					cout << "Invalid input. Please enter a valid input based on the list below. " << endl;
					customerChoice = 0;
				}
			} while (customerChoice != 10 && customerChoice != 9 && customerChoice != 11);
			}
			else {
			choice = -1;
			}
		}
			

		else if (choice == 4) {
		//Exit
		}
		else {
			cout << "Invalid input!" << endl << endl;
			cout << "Please enter an integer between the number 1 to 4 only" << endl << endl;
			cout << "Please enter a valid input: ";
			while (!(cin >> choice)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.  Please enter a valid input: ";
			}
			cout << endl;
		}
	} while (choice != 4);
}
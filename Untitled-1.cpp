#include <iostream>
using namespace std;

int const password = 1234;
int x, c_num, c_price, c_year, ch_id;
int& px = x;
string name, c_brand;
bool gender;
long budget;
bool c_s;
 
//***************************************************************************************************************************
class Car
{
private:
	int price, year;
	string color, brand, model;

public:

	void showinfocar()
	{
		cout << endl;
		cout << "Brand : " << this->brand << endl;
		cout << "Model : " << this->model << endl;
		cout << "Color : " << this->color << endl;
		cout << "Year : " << this->year << endl;
		cout << "Price : " << this->price << "$" << endl;
		cout << endl;

	}

	Car(int p, int y, string c, string b, string m) :model(m), price(p), year(y), color(c), brand(b) {}
	Car() :price(0), year(0), color("NULL"), brand("NULL") {}
	~Car() {}
};
//***************************************************************************************************************************
Car c1(350000, 2020, "Black", "BMW", "BMW i7");
Car c2(10000000, 2022, "Green", "Mercedes", "BENZ 300-SLR");
Car c3(400000, 2024, "Lime Green", "McLaren", "570S");
Car c4(300000, 2023, "Red", "Audi", "A4");
Car c5(200000, 2023, "Brown", "Porsche ", "Taycan GTS");
Car c6(500000, 2020, "Black", "Dodge Charger", "SRT Hellcat");
Car cars[6] = { c1,c2,c3,c4,c5,c6 };
//***************************************************************************************************************************
class Human {
protected:
	string name;
	bool gender;

public:

	Human() : name(""), gender(0) {}

	Human(string n, bool g) : name(n), gender(g) {}

	void display() {
		cout << "Name: " << this->name << "\nGender: ";
		if (gender) {
			cout << "Male";
		}
		else if (!gender) {
			cout << "Female";
		}
	}
};
//***************************************************************************************************************************
class Stuff : public Human {

public:
	int id;
	Stuff() : Human() {
		id = 0;
	}

	Stuff(string n, bool g, int i) : Human(n, g) {

		id = i;
	}


	void Display() {
		Human::display();
		cout << "\nID: " << this->id << endl;
	}

};
//***************************************************************************************************************************
class Worker : public Stuff {
private:
	int salary;
	string GGender;
	static int ID;
	int _id;
public:
	int SSalary = 0;
	Worker() : Stuff() {
		salary = 0;
	}

	//Constructor for old 4 objects createn in global scope
	Worker(string n, bool g, int i, int s) : Stuff(n, g, i) {
		salary = s;

	}

	//A constructor for the new workers created by the manager
	Worker(string N, string G, int SS)
	{
		name = N;
		GGender = G;
		SSalary = SS;
		ID++;
		_id = ID;

	}

	void infoworkers() {

		Stuff::display();
		cout << "\nSalary: " << this->salary << endl;
		cout << "ID: " << this->id << endl;

	}

	void AFTERADD()
	{
		cout << "Name: " << this->name << endl;
		cout << "Gender: " << this->GGender << endl;
		cout << "Salary: " << this->SSalary << endl;
		cout << "ID: " << this->_id << endl;
	}
};
//***************************************************************************************************************************
Worker w1("Tamer", 1, 22310503, 5000);
Worker w2("Habib", 1, 22310504, 6000);
Worker w3("Raed", 1, 22310505, 7000);
Worker w4("Shehata", 1, 22310506, 8000);
Worker W[] = { w1,w2,w3,w4 };
int Worker::ID = 22310506;
//***************************************************************************************************************************
class Customer : public Human
{

private:
	long budget;

public:

	Customer() : Human() {
		budget = 0;
	}
	Customer(string n, bool g, long bdgt) : Human(n, g) {
		budget = bdgt;
	};

};
//***************************************************************************************************************************

//All Functions
//***************************************************************************************************************************

//Shows all cars' informations
void allcars()
{

	for (int i = 0; i < 6; i++)
	{
		cout << "   Car (" << i + 1 << ")";
		cars[i].showinfocar();
	}
}

//Welcome Message
void welcome() {
	cout << endl << "   \t\t\t\t\t\t\t    ----------------------------\n";
	cout << "\t\t\t\t\t\t\tWelcome to El-Ged3an Car's Dealership\n";
	cout << "   \t\t\t\t\t\t\t    ----------------------------\n\n";
	cout << "Classify which one of these are you: \n\n";
	cout << "1- Customer\n\n" << "2- Staff Member\n\n";
	cout << "Type (1) or (2) : ";
}

//Let user choose whether he is a customer or a staff member || 1 -> 0 ( Customer )  || 2 -> 1 ( Staff Member )
void startup() {

	cin >> ::x;
	if (::x == 1) {
		system("cls");
		cout << "\n\t\t\t\tWelcome please choose your gender for better experience\n";
		::c_s = 0;
	}
	else if (::x == 2) {
		system("cls");
		cout << "\n\t\t\t\t\t\t\tChoose whether you a Manager or a Worker\n";
		cout << "\n\n(1) Manager\n\n(2) Worker\n\n(1) Or (2): ";
		::c_s = 1;
	}
	else {
		system("cls");
		cout << "\n\n\t\t\tPlease Type (1) If You Are A Customer Or (2) If You Are A Staff Member, You Can't Type Anything Else!: ";
		startup();
	}

}

//Customer's Gender Screen (0) Female , (1) Male
void cstmr_g() {
	cout << "\n" << "Female\t(F)\tMale\t(M)\n";
	cout << "Type    (F)      OR     (M) : ";
	char gn;
	cin >> gn;

	switch (gn)
	{
	case 'F':
		::gender = 0;
		break;
	case 'M':
		::gender = 1;
		break;
	default:
		system("cls");
		cout << "Please type (F) if you are a Female or (M) if you are a Male!\n";
		cstmr_g();
		break;
	}
}

//Customer's Name Screen 
void cstmr_n() {
	string name;
	cout << "\nPlease Tell Us Your Name: ";
	cin >> name;
	::name = name;

}

//Customer's Budget
void cstmr_b() {
	if (!::gender) {
		cout << "\nMs." << name << ", Please Enter Your Budget: ";
	}
	else {
		cout << "\nMr." << name << ", Please Enter Your Budget: ";
	}
	cin >> budget;
	::budget = budget;
	Customer c1(::name, ::gender, ::budget);

}

//Choose Car For Buying Car
void ch_car() {
	int x;
	cin >> x;
	if (x < 0 || x>6) {
		system("cls");
		cout << "Please Enter A Number From (1) To (5) only: ";
		ch_car();
	}
	::c_num = x;
	system("cls");
	cout << "\nAre You Sure You Want This Car?\n";
	cars[c_num - 1].showinfocar();
	cout << "Yes Or No : ";
	string ans;
	cin >> ans;
	if (ans == "Yes") {
		cout << "\n\nThank You, Enjoy Your New Car :)";
	}
	else if (ans == "No") {
		system("cls");
		cout << "Choose Your Car Again\n\n";
		allcars();
		ch_car();
	}
	else {
		system("cls");
		cout << "\nType (Yes) If You're Sure or (NO) If You're not: ";
		ch_car();
	}

}

//The Car's Year Of Creation
void c_yearr() {

	cin >> ::c_year;
	if (::c_year >= 1950 && ::c_year < 2000) {
		::c_price += 30000;
	}
	else if (::c_year >= 2000 && ::c_year < 2010) {
		::c_price += 70000;
	}
	else if (::c_year >= 2010 && ::c_year < 2025) {
		::c_price += 110000;
	}
	else if ((::c_year < 1950 || ::c_year > 2024)) {
		cout << "\nEnter The Car's Year From 1950 To 2024 Only ";
		c_yearr();
	}
}

//A Function To Show Workers' Information (Used By Manager)
Worker *NWs = new Worker[100] ;

//Three Functions To Add Workers (Used By Manager)
void Addworkr()
{
	static int B = 0;
	static int E = B + 1;;
	string N;
	string G;
	int S;
	int W = 0;
	int WW = 1;
	int stop;
	for (int i = 0; i < 100; i++) {
		if (W == WW)
		{
			cout << "Do You Want To Add More Worker? \n";
			cout << "(1) No, I Don't \n(2) Yes, I Do\n\n";
			cout << "Type (1) Or (2): ";
			cin >> stop;
			system("cls");
			if (stop == 1)
			{
				break;
			}
			else
			{
				WW++;
			}
		}
		W++;
		cout << "Enter Worker's Gender: \n";
		cin >> G;
		cout << "Enter Worker's Name: \n";
		cin >> N;
		cout << "Enter Worker's Salary: \n";
		cin >> S;
		cout << "\n\n";

		for (int J = B; J < E; i++)
		{
			NWs[J] = { N , G , S };
			break;

		}
		B++;
		E++;
	}


}
void Sworkrinfo()
{

	for (int i = 0; i < 4; i++)
	{
		W[i].infoworkers();
		cout << "\n\n";
	}
}
void AFTERADDworker()
{
	Sworkrinfo();
	for (int i = 0; i < 100; i++)
	{
		if (NWs[i].SSalary == 0)
			break;
		NWs[i].AFTERADD();
		cout << "\n\n";
	}
}

//Sell Car 
void s_car() {
	int x;
	string con;
	cout << "Enter The Number Of The Car You Want To Sell: ";
	cin >> x;
	switch (x) {
	case 1:  // Dodge 500K
		::c_price += 500000;
		::c_brand = "Dodge";
		break;
	case 2: // Procshe 200K 
		::c_price += 200000;
		::c_brand = "Porsche";
		break;
	case 3: // McLaren 400K 
		::c_price += 400000;
		::c_brand = "Mclaren";
		break;
	case 4: // BMW 350K 
		::c_price += 350000;
		::c_brand = "BMW";
		break;
	case 5: // Mersedes 1 M 
		::c_price += 1000000;
		::c_brand = "Mersedes";
		break;
	case 6: // Audi 300K 
		::c_price += 300000;
		::c_brand = "Audi";
		break;

	default:
		cout << "\nPlease Select From (1)-(6) Only\n";
		s_car();
	}
	cout << "\n\nEnter The Car's Year Of Creation: ";
	c_yearr();
	system("cls");

	cout << "You Are Going To Sell A " << ::c_brand << " Model (" << ::c_year << ") For: " << ::c_price << "$\n\n";
	cout << "Please Confirm This Operation By Typing Confirm (If You Typed Anything Else The App Will Close) :";
	cin >> con;
	if (con == "Confirm") {
		cout << "\n\nThank You For Selling To Us, Enjoy Your Money :)";
	}
	else {

	}
}

//Buy or Sell Function
void s_b() {
	int SB;
	string y_n;
	cout << "\nWhat Do You Want To Do ";
	if (!::gender) {
		cout << "Ms." << name;
	}
	else {
		cout << "Mr." << name;
	}
	cout << "\n\n(1)I Want To Buy A Car\n(2)I Want To Sell A Car\nChoose (1) Or (2) : ";
	cin >> SB;
	system("cls");
	if (SB == 1) {
		cstmr_b();
		if (::budget < 200000) {
			cout << "\n\nSadly You Don't Have Enough Money To Buy From Our Cars Dealership, Sadly You Have To Leave :( \n\n";

			cout << "We Are Joking With You, You Can Still See All The Cars We Have If You Want\n\n Do You Want To See Them (Yes or No)? :";
			cin >> y_n;
			if (y_n == "Yes") {
				system("cls");
				cout << "Wait Please Showing Cars...\n\n";
				system("cls");
				allcars();
			}
			else if (y_n == "No") {
				cout << "The Programm Will Close...";


			}
		}
		else if (::budget > 200000) {
			cout << "\n\nThese Are The Available Cars In Our Car Dealership At The Moment, Choose One Of Them\n\n";
			allcars();
			cout << "Enter The Car's Number: ";
			ch_car();
		}
	}
	else if (SB == 2)
	{
		cout << "\nWe Only Buy These Cars, So Choose Which Car Do You Want To Sell: \n\n";
		cout << "(1) Dodge\n" << "(2) Porsche\n" << "(3) McLaren\n" << "(4) BMW\n" << "(5) Mercedes\n" << "(6) Audi\n\n";
		s_car();

	}
	else
	{
		system("cls");
		cout << "\n\nType (1) Or (2) Only: ";
		cout << "\n\n";
		s_b();
	}
}

//Select Operation (For Manager)
void op() {
	int op;
	cin >> op;
	int n;

	if (op == 1) {
		system("cls");
		cout << "\n";
		Sworkrinfo();
	}
	else if (op == 2) {
		system("cls");
		cout << "\n";
		allcars();
	}
	else if (op == 3)
	{
		system("cls");
		cout << "\n";
		Addworkr();
		cout << " Do you want to show your workers?\n";
		cout << "(1) Yes I Do\n(2) No I Don't (The App Will Close)\n";
		cout << "Type (1) Or (2): ";
		cin >> n;
		system("cls");
		if (n == 1)
			AFTERADDworker();

	}
}

//Manager's Password Function
void manager() {
	int password;
	int z = 0;
	int m = 4;

	cout << "\nEnter password: ";
	cin >> password;
	if (password == ::password)
	{
		system("cls");
		cout << "\n\nHello, Manager\n\n";
		cout << "Choose what you want to do:\n\n";
		cout << "(1) Show Workers' Information\n\n";
		cout << "(2) Show All Cars in the \n\n";
		cout << "(3) Add A Worker \n\n";
		cout << "Type (1) Or (2) Or (3): ";
		op();
	}
	else
	{
		while (password != ::password) {
			m--;
			cout << "\n\nThe Password Is Wrong You Have  " << m - 1 << "  Attempts Left\n" << endl;
			z++;
			cout << "\nEnter password: ";
			cin >> password;
			if (password == ::password)
			{
				system("cls");
				cout << "\n\nHello, Manager\n\n";
				cout << "Choose what you want to do:\n\n";
				cout << "(1) Show Workers' Information\n\n";
				cout << "(2) Show All Cars in the \n\n";
				cout << "(3) Add A Worker \n\n";
				cout << "Type (1) Or (2) Or (3): ";
				op();
			}
			if (z == 2)
			{
				cout << "You Have Exceeded The Maximum Number Of Attempts. Exiting...\n\n";
				break;
			}
		}

	}


}

//Worker Function (It takes the ID from the worker then search for the worker in the array using the ID and shows the Info about the worker with same ID
void worker() {
	system("cls");
	int n;
	cout << "Hi, Please Enter Your ID\n";
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		if (W[i].id == n)
		{
			W[i].infoworkers();
			break;
		}
	}


}

//***************************************************************************************************************************
int main()
{

	welcome();
	startup();
	if (!c_s) {
		cstmr_g();
		cstmr_n();
		s_b();

	}
	else if (c_s) {
		int x;
		cin >> x;
		if (x == 1) {
			manager();
			delete[]NWs;
		}
		else if (x == 2) {
			worker();
		}
	}

	return 0;
}
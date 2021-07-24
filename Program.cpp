#include <iostream>
#include <cstring>
#include <ctype>
#include <cstdlib>
using namespace std;

//struct
const int size = 1;
struct inv_company{
char item[40];//name things
double cost;// this is cost things
double retail;//розничная цена
int on_hand;//amount pieces
int lead_time;// amount days 
}inventory[size];

//function
void init_inv(), enter(), input(int t), update(), display(), cleanAll(), select();
int menu();

int main(){
char choose;	
init_inv();
for(;;){
choose = menu();
switch (choose){
case 'e':enter();
break;
case 'd':display();
break;
case 'u':update();
break;
case 'c':cleanAll();
break;
case 's':select();
break;
case 'q':return 0;
}
}
return 0;
}

//Choose
int menu(){
	char choose;
	do{
	cout << "(E). Enter\n";
	cout << "(D). Display\n";
	cout << "(U). Update\n";
	cout << "(C). Clean\n";
	cout << "(S). Select and delete\n";
	cout << "(Q). Quit\n";
	cout << "Your choose: ";
	cin >> choose;	
	}while(!strchr("eduqcs", tolower(choose)));
return tolower(choose);
}


//preparation array
void init_inv(){
	for(int t=0;t<size;t++) *inventory[t].item='\0';
}

//enter information
void enter(){
int t;
for(t=0;t<size;t++){
if(!*inventory[t].item) break;
if(t==size){
	cout << "List full!" << endl;
	return;
}
input(t);
}
}

void input(int t){
	cout << "Thing №" << t+1 << endl;
	cout << "Product name: ";
	cin >> inventory[t].item;
	cout << "Product value: ";
	cin >> inventory[t].cost;
	cout << "Value retail: ";
	cin >> inventory[t].retail;
	cout << "In stock: ";
	cin >> inventory[t].on_hand;
	cout << "Time before replenishment: ";
	cin >> inventory[t].lead_time;	
}
void update(){
	int t;
	char name[100];
	cout << "Enter product name :";
	cin >> name;
for(t=0;t<size;t++)
	if(!strcmp(name,inventory[t].item))break;
if(t==size){
cout << "Not found!" << endl;
return;	
}	
cout << "Enter new information about this is product" << endl;
input(t);	
}
void display(){
	for(int i=0;i<size;i++){
		if(*inventory[i].item){
			cout << "Thing №" << i+1 << endl;
			cout << "Product name = " << inventory[i].item << endl;
			cout << "Product value = " << inventory[i].cost << endl;
			cout << "Value retail = " << inventory[i].retail << endl;
			cout << "In stock = " << inventory[i].on_hand << endl;
			cout << "Time before replenishment = " << inventory[i].lead_time << endl;
		}
	}
}

void cleanAll(){
	for(int t=0;t<size;t++){
	strcpy(inventory[t].item,"1");
	inventory[t].cost=0;
	inventory[t].retail=0;
	inventory[t].on_hand=0;
	inventory[t].lead_time=0;
	}
	cout << "All cleaned!" << endl;
}

void select(){
char name[100];
int t;
cout << "Enter product name: ";
cin >> name;
for(t=0;t<size;t++){
	if(!strcmp(name,inventory[t].item))break;
		if(t==size){
			cout << "Not found!" << endl;
			return;	
		}
}
strcpy(inventory[t].item,"");
inventory[t].cost=0;
inventory[t].retail=0;
inventory[t].on_hand=0;
inventory[t].lead_time=0;
cout << "Information about product is " << name << " cleaned!" << endl;
}
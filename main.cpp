
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

class ffile{
 	private:
	  string n[10];
		string tu[100];
 		int a;				//tao bao nhieu so
 public:
 	ffile();
  void doc(char* name,int c);//c=1 doc ten file   2: Doc tu vung
void ghi();
void giaodien();
void on1(char* name);		
void onf(char* name);
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	ffile f1;
	f1.giaodien();
return 0;
}

void ffile::doc(char *name,int c){
	ifstream f;
	f.open(name, ios::in);
	int l=0;
	string line;
	while (!f.eof())          // (1)
	{
		getline(f, line); // (2)
		if(c==1)
		tu[l]=line;
		else
		n[l]=line;
		l++;
	}
	a=l;
	f.close();
};
ffile::ffile(){

};
void ffile::giaodien(){
	bool f1 = true;
	int lc;
	while(f1){
		system("cls");
		cout<<"1 On tung phan: "<<endl;
		cout<<"2 On toan bo: "<<endl;
		cout<<"3 Thoat"<<endl;
		cout<<"Nhap lua chon cua ban: ";cin>>lc;
		switch(lc){
			case 1:
				on1("buoi1.txt");
				break;
			case 2:
				onf("buoi1.txt");
				break;
			default:
				f1 = false;
				break;
		}
	}
};
void ffile::on1(char* name){
	system("cls");
	cout<<"tung vung on 1 "<<endl;
	doc(name,1);
	//hien thi
	for(int i=0;i<a;i++){
		cout<<tu[i]<<endl;
	}
	//
	getch();
};
void ffile::onf(char* name){
	system("cls");
	cout<<"Hay tra loi tung vung on full ";getch();
	
};

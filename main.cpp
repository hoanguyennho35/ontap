
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
 		int stt[50];		//luu bien ngau nhien
	  string n[10];			//luu ten file
		string tu[100];		//luu tru tu
 		int a;				//bao nhieu tu vung trong file
 public:
 	ffile();
  void doc(string name,int c);//c=1 doc ten file   2: Doc tu vung
void ghi();							//k su dung
void on1(string name);				//on lai chi 1 file
void onf(string name);				//on lai nhieu file
int rdum(int st, int mau[]);		//ho tro rdum2
		void rdum2();				//tao so ngau nhien truoc khi goi gan bien a

		int get_a() {
			return a;
		}
		string get_n(int a1) {
			return n[a1];
		}
		int get_stt(int a1) {
			return stt[a1];
		}
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	bool f1 = true;
	int lc;
	string ten;
	while(f1){
		system("cls");
		cout<<"1 On tung phan: "<<endl;
		cout<<"2 On toan bo: "<<endl;
		cout<<"3 Thoat"<<endl;
		cout << "Nhap lua chon cua ban: "; cin >> lc; cin.ignore();
		switch(lc){
			case 1:
			{	system("cls");
			cout << "nhap ten file ban muon luyen: "; cin >> ten;
			ten = "D:\\ontap\\visual_ot\\Debug\\" + ten + ".txt";
					ffile b;
					b.on1(ten);
				}
				break;
			case 2:
			{		string file;
					int b1;
					ffile a;
					a.doc("D:\\ontap\\visual_ot\\Debug\\fdoc.txt",2);			//load file fdoc luu ten bai hoc
					a.rdum2();
					for (int i = 0; i < a.get_a(); i++) {
						b1 = a.get_stt(i);
						file = a.get_n(b1);
						file = "D:\\ontap\\visual_ot\\Debug\\" + file + ".txt";
						system("cls");
						cout << "Begin lesson - press continue!!"; cin.ignore();
						ffile b;
						b.on1(file);
						system("cls");
						cout << "Congratulate end lesson "<< a.get_n(b1)<<"- press continue!!"; cin.ignore();
					}
			}
				break;
			default:
				f1 = false;
				break;
		}
	}
	return 0;
}

void ffile::doc(string name,int c){
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
	srand(time(NULL));
	tu[0]="anh";
	tu[1]="yeu";
	tu[2]="em";
};
void ffile::on1(string name){
	system("cls");
	doc(name,1);
	//hien thi truoc khi goi gan bien a
	rdum2();
	//xoa bien luu tu vung
	string sum;
	for(int i=0;i<a;i++){
		string buf;
		int a;
		buf = tu[stt[i]];
		sum = sum + buf +"\n";
		a = buf.find('-');
		system("cls");
		cout<<buf.substr(0,a)<<endl; 
		cout<<"press continue"<<endl;
		cin.ignore();
	}

	//tong ket tu vung
	system("cls");
	/*for (int i = 0; i < a; i++) {
		cout << tu[stt[i]] << endl;
	}*/
	cout <<"tong ket: "<<endl<<sum;
	cout << endl << "press continue";
	cin.ignore();
};
void ffile::onf(string name){
	system("cls");
	cout<<"Hay tra loi tung vung on full ";
	cin.ignore();
	
};
//ham rdum ho tro cho rdum2
int ffile::rdum(int st,int mau[]){
	bool b = true;
	int bien;
	while(b){
		bien = rand()%a;
		for(int i=0;i<st;i++){
			if(bien == mau[i]){
				break;
			}
			if(i==st-1) {mau[st-1]=bien;b=false;}
		}
	}
	return bien;	
}
//truoc khi goi gan so tu cho bien a
void ffile::rdum2(){
	int mau[50];		//luu gia tri da hien thi
	mau[0]=1000;
	for(int i=0;i<a;i++){
		rdum(i+1,mau);
		stt[i]=mau[i];
	}
}


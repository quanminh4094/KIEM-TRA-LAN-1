#include<iostream>
#include<iomanip>
using namespace std;
class ANPHAM{
	private:
		char mahang[30];
		char tenNSX[30];
		char NXB[30];
		int dongia;
	public:
	ANPHAM(char *mahang="",char *tenNSX="",char *NXB="",int dongia=0)
	{
		
		strcpy(this->mahang, mahang);
		strcpy(this->tenNSX, tenNSX);
		strcpy(this->NXB, NXB);
		       this->dongia = dongia;
	}
	~ANPHAM(){}
	void nhap()
	{
		cout<<"Nhap ma hang: ";
		cin.getline(mahang, 30);
		cout<<"Nhap ten nha san xuat: ";
		cin.getline(tenNSX, 30);
		cout<<"Nhap nha xuat ban: ";
		cin.getline(NXB, 30);
		cout<<"Nhap don gia: ";
		cin>>dongia;
		fflush(stdin);
	}
	void xuat()
	{
	cout<<mahang<<"\t|"<<tenNSX<<"\t\t\t|"<<NXB<<"\t\t|"<<dongia<<"|"<<endl;	
	}
		int getdongia()
		{
			return dongia;
		}
};
class SACH: public ANPHAM
{
	private:
		char tensach[30];
		char tenTG[15];
		int SL;
	public:
		SACH(char *tensach="",char *tenTG="",int SL=0)
		{
		strcpy(this->tensach, tensach);
		strcpy(this->tenTG, tenTG);
			   this->SL=SL;
		}
		~SACH(){}
		void nhap()
		{
			ANPHAM::nhap();
		}
		friend istream & operator>>(istream &is, SACH &a)
		{
			cout<<"Nhap ten sach: ";
			is.getline(a.tensach, 30);
			cout<<"Nhap ten tac gia: ";
			is.getline(a.tenTG, 15);
			cout<<"Nhap so luong: ";
			is>>a.SL;
			fflush(stdin);
		}
		int TT()
		{
			float s=0;
			s=SL*getdongia();
		return s;
		}
		void xuat()
		{
			ANPHAM::xuat();
			cout<<tensach<<"\t|"<<tenTG<<"\t\t\t|"<<SL<<endl;
		} 
};
int main()
{
	int n;
	cout<<"Nhap so an pham: "; cin>>n;
	fflush(stdin);
	ANPHAM a[n];
	for(int i=0;i<n;i++)
	{
		cout<<"An phan thu "<<i+1<<endl;
		a[i].nhap();
	}
cout<<"Ma hang\t|Ten nha san xuat\t|Nha xuat ban\t|Don gia|"<<endl;
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
	int m;
	cout<<"Nhap so sach:"; cin>>m;
	fflush(stdin);
	SACH b[m];
		for(int i=0;i<m;i++)
	{
		cout<<"Sach thu "<<i+1<<endl;
		b[i].nhap();
	}
cout<<"Ma hang\t|Ten nha san xuat\t|Nha xuat ban\t|Don gia\t|Ten sach\t|Ten tac gia\t|Thanh tien|"<<endl;
	for(int i=0;i<m;i++)
	{
		a[i].xuat();
	}	
}
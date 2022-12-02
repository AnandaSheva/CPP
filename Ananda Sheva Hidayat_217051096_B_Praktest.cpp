#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float kimia[10],matematika[10],fisika[10],biologi[10];
	char nama[10][10];
	int banyak_data;
	float jumlah[10],rata_siswa[10],temp_kimia=0,temp_matematika=0,temp_fisika=0,temp_biologi=0;
	
	cout<<"Masukan Banyaknya Data : ";
	cin>>banyak_data;
	
	for(int i = 0; i<banyak_data; i++){
		cout<<"----------------------------------"<<endl;
		cout<<"Data Ke - "<<i+1<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"Nama Panggilan\t\t: "; cin>>nama[i];
		cout<<"Nilai kimia\t\t: " ; cin>>kimia[i];
		cout<<"Nilai matematika\t: ";cin>>matematika[i];
		cout<<"Nilai fisika\t\t: "; cin>>fisika[i];
		cout<<"Nilai biologi\t\t: "; cin>>biologi[i];
		
		jumlah[i]= fisika[i]+matematika[i]+kimia[i]+biologi[i];
		rata_siswa[i]= jumlah[i]/4;
		temp_kimia=temp_kimia+kimia[i];
		temp_matematika=temp_matematika+matematika[i];
		temp_fisika=temp_fisika+fisika[i];
		temp_biologi=temp_biologi=biologi[i];
	}
	
	cout<<"\n=====================================================================================\n";
	cout<<setw(4)<<"no"<<setw(15)<<"Nama"
		<<setw(15)<<"KIMIA"<<setw(20)<<"MATEMATIKA"
		<<setw(15)<<"FISIKA"<<setw(15)<<"BIOLOGI";
	cout<<"\n===================================================================================== \n";
	
	for(int n=0;n<banyak_data;n++){
		int no = n+1;
		cout<<setw(4)<<no<<setw(15)<<nama[n]
		<<setw(13)<<kimia[n]<<setw(20)<<matematika[n]
		<<setw(18)<<fisika[n]<<setw(15)<<biologi[n]<<endl;
	}cout<<endl;
	
	cout<<"Rata-Rata Tiap Mahasiswa :"<<endl;
		for(int n=0;n<banyak_data;n++){
			cout<<nama[n]<<"\t : "<<rata_siswa[n]<<endl;
	}
		cout<<"\nRata-Rata Nilai Mata Kuliah :"<<endl;
	cout<<"KIMIA\t\t:"<<temp_kimia/banyak_data<<endl;
	cout<<"MATEMATIKA\t:"<<temp_matematika/banyak_data<<endl;
	cout<<"FISIKA\t\t:"<<temp_fisika/banyak_data<<endl;
	cout<<"BIOLOGI\t\t:"<<temp_biologi/banyak_data<<endl;
}

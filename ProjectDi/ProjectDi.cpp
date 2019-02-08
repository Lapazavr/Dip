#include "stdafx.h"
#include "process.h"
#include <string>
#include <conio.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include <map>
#include "windows.h"
#include <iomanip>              //��� �������� �������
#include <stdlib.h>             //��� �������� � ���� ������ ���

using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


 string print(std::string::size_type n, std::string const &s, int k)          //����� ������� ������ �������
{
	    if (n != std::string::npos) {    
        string S = s.substr(n+k);           //����� ��������� � ��������� "\author"+8
    delP:
					int k0 = S.find(" ");                //�������� �������, ��� �������
					if(k0 < string::npos){
						S.erase(k0,1);
						if (S.find(" ")<string::npos) goto delP;
					}
	delS1:				
					int k1 = S.find("{");                //�������� {, ��� �������
					if(k1 < string::npos){
						S.erase(k1,1);
						if (S.find("{")<string::npos) goto delS1;
					}
	delS2:
					int k2 = S.find("}");                //�������� }, ��� �������
					if(k2 < string::npos){
						S.erase(k2,1);
						if (S.find("}")<string::npos) goto delS2;
					}
					
					int k3 = S.find("~\\surname");                //�������� ~\\surname, ��� �������
					if(k3 < string::npos){
						S.erase(k3,9);
					}
					int k4 = S.find("~");                //�������� ~\\surname, ��� �������
					if(k4 < string::npos){
						S.erase(k4,1);
					}
	return S;
	}
		
}
 
string printEmail(std::string::size_type n, std::string const &s, int k)          //����� ������� ������ �������
{
    if (n != std::string::npos) {    
        string S = s.substr(n+k);           //����� ��������� � ��������� "\email"+6
    delP:
					int k0 = S.find(" ");                //�������� �������, ��� �������
					if(k0 < string::npos){
						S.erase(k0,1);
						if (S.find(" ")<string::npos) goto delP;
					}
	delS1:				
					int k1 = S.find("{");                //�������� {, ��� �������
					if(k1 < string::npos){
						S.erase(k1,1);
						if (S.find("{")<string::npos) goto delS1;
					}
	delS2:
					int k2 = S.find("}");                //�������� }, ��� �������
					if(k2 < string::npos){
						S.erase(k2,1);
						if (S.find("}")<string::npos) goto delS2;
					}				
	return S;
	}
		    
}


string printToc(std::string::size_type n, std::string::size_type k, string S)          //����� ������� ������ ������ �� ����� .toc
{
    if (n != std::string::npos) {    
        string Symbol=S;
		
			Symbol=Symbol.erase(k);
		Symbol=Symbol.erase(0,n+5);
		
		if(Symbol=="A") Symbol="�";
		if(Symbol=="a") Symbol="�";
		if(Symbol=="B") Symbol="�";
		if(Symbol=="b") Symbol="�";
		if(Symbol=="V") Symbol="�";
		if(Symbol=="v") Symbol="�";
		if(Symbol=="G") Symbol="�";
		if(Symbol=="g") Symbol="�";
		if(Symbol=="D") Symbol="�";
		if(Symbol=="d") Symbol="�";
		if(Symbol=="E") Symbol="�";
		if(Symbol=="e") Symbol="�";
		if(Symbol=="YO") Symbol="�";
		if(Symbol=="yo") Symbol="�";
		if(Symbol=="ZH") Symbol="�";
		if(Symbol=="zh") Symbol="�";
		if(Symbol=="Z") Symbol="�";
		if(Symbol=="z") Symbol="�";
		if(Symbol=="I") Symbol="�";
		if(Symbol=="i") Symbol="�";
		if(Symbol=="I_shrt") Symbol="�";
		if(Symbol=="i_shrt") Symbol="�";
		if(Symbol=="K") Symbol="�";
		if(Symbol=="k") Symbol="�";
		if(Symbol=="L") Symbol="�";
		if(Symbol=="l") Symbol="�";
		if(Symbol=="M") Symbol="�";
		if(Symbol=="m") Symbol="�";
		if(Symbol=="N") Symbol="�";
		if(Symbol=="n") Symbol="�";
		if(Symbol=="O") Symbol="�";
		if(Symbol=="o") Symbol="�";
		if(Symbol=="P") Symbol="�";
		if(Symbol=="p") Symbol="�";
		if(Symbol=="R") Symbol="�";
		if(Symbol=="r") Symbol="�";
		if(Symbol=="S") Symbol="�";
		if(Symbol=="s") Symbol="�";
		if(Symbol=="T") Symbol="�";
		if(Symbol=="t") Symbol="�";
		if(Symbol=="U") Symbol="�";
		if(Symbol=="u") Symbol="�";
		if(Symbol=="F") Symbol="�";
		if(Symbol=="f") Symbol="�";
		if(Symbol=="H") Symbol="�";
		if(Symbol=="h") Symbol="�";
		if(Symbol=="C") Symbol="�";
		if(Symbol=="c") Symbol="�";
		if(Symbol=="CH") Symbol="�";
		if(Symbol=="ch") Symbol="�";
		if(Symbol=="SH") Symbol="�";
		if(Symbol=="sh") Symbol="�";
		if(Symbol=="SHCH") Symbol="�";
		if(Symbol=="shch") Symbol="�";
		if(Symbol=="HRDSN") Symbol="�";
		if(Symbol=="hrdsn") Symbol="�";
		if(Symbol=="ERY") Symbol="�";
		if(Symbol=="ery") Symbol="�";
		if(Symbol=="SFTSN") Symbol="�";
		if(Symbol=="sftsn") Symbol="�";
		if(Symbol=="EREV") Symbol="�";
		if(Symbol=="erev") Symbol="�";
		if(Symbol=="YU") Symbol="�";
		if(Symbol=="yu") Symbol="�";
		if(Symbol=="YA") Symbol="�";
		if(Symbol=="ya") Symbol="�";
		
		
		
		return Symbol;           //����� ��������� � ��������� 
    }
	    
}

string printPage(std::string::size_type n, std::string const &s)          //����� ������� ������ �������� ������ ������ �� ����� .toc
{
    if (n != std::string::npos) {    
        string S = s.substr(n+1);           //����� ��������� � ��������� "\email"+6
		            int k1 = S.find("{");                //�������� {, ��� �������
					if(k1 < string::npos){
						S.erase(k1,1);
					}
					
					int k2 = S.find("}");                //�������� }, ��� �������
					if(k2 < string::npos){
						S.erase(k2,1);
					}
					return S;
    }
	
	    
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int _tmain(int argc, _TCHAR* argv[])
{   
    
    setlocale(LC_ALL, "Russian_Russia.1251");
    setlocale(LC_ALL, "RUS");
	
	string::size_type n;
    string S; //� S ����� ����������� ������

	char adressPuti[256];
	char adressPutiTex[256];
	char adressPutiToc[256];
	char tagAuthor[100];
	char tagEmail[100];
	int dlinaTagAuthor = 0;
	int dlinaTagEmail = 0;
	bool metkaAuthor = 0;         //����� ��� ���������� ������� ������ � ������
	bool metkaEmail = 0;          //����� ��� ���������� ������� ���� � ������
	int kolAuthor = 0;            //���������� ������� (� ��� �� ������ � �������)
	char Tablica[256];
	cout<<"������� ������ ����� �������:"<<endl;
	cout<<"!!!������ \\ ��������� \\\\!!!"<<endl;
	cout<<"���� �� ������ ��������� �������� �������� ��������!"<<endl;
	cout<<"!!!���� �� ������ ��������� �������!!!"<<endl;
	cout<<"��������:"<<endl;
	cout<<"C:\\\\Users\\\\Max\\\\Desktop\\\\ZZtop\\\\v-izd-v0-t16\\\\"<<endl;
	//C:\\Users\\Max\\Desktop\\ZZtop\\v-izd-v0-t16\\                       ����� ����� ������, ���� ������� � ������� ���� ����������� ������ (�� ��������� � ������)
	cin>>adressPuti;
	//cin.getline(adressPuti,256);
	
	
	cout<<endl;
	char adressPDFtk[256];
	cout<<"������� ������ ���� � ����� pdftk.exe:"<<endl;
	cout<<"!!!������ \\ ��������� \\\\!!!"<<endl;
	cout<<"���� �� ������ ��������� �������� �������� ��������!"<<endl;
	cout<<"!!!���� �� ������ ��������� �������!!!"<<endl;
	cout<<"��������: "<<endl;
	cout<<"C:\\\\Users\\\\Max\\\\Desktop\\\\bin\\\\pdftk.exe"<<endl;
	//cin.getline(adressPDFtk,256);
	cin>>adressPDFtk;
	
	cout<<endl;
	cout<<"������� ��� ��� ������ � ������ .��� �������:"<<endl;
	cout<<"!!!������ \\ ��������� \\\\!!!"<<endl;
	cout<<"��������: \\\\author"<<endl;
	cin>>tagAuthor;
	
	dlinaTagAuthor = strlen( tagAuthor);

	cout<<endl;
	cout<<"������� ��� ��� ������� ����� � ������ .��� �������:"<<endl;
	cout<<"!!!������ \\ ��������� \\\\!!!"<<endl;
	cout<<"��������: \\\\email"<<endl;
	cin>>tagEmail;
	
	dlinaTagEmail = strlen( tagEmail);

	
	cout<<endl;
	char adressSbornik[256];
	cout<<"������� ������ ���� � PDF ����� �������� ��������:"<<endl;
	cout<<"!!!������ \\ ��������� \\\\!!!"<<endl;
	cout<<"���� �� ������ ��������� �������� �������� ��������!"<<endl;
	cout<<"!!!���� �� ������ ��������� �������!!!"<<endl;
	cout<<"��������: "<<endl;
	cout<<"C:\\\\Users\\\\Max\\\\Desktop\\\\ZZtop\\\\v-izd-v0-t16\\\\izv2016-2-t16.pdf"<<endl;
	cin>>adressSbornik;

	cout<<endl;
	char adressDirect[256];
	cout<<"������� ���� � �����, � ������� ����� ��������� �������� �����:"<<endl;
	cout<<"!!!������ \\ ��������� \\\\!!!"<<endl;
	cout<<"���� �� ������ ��������� �������� �������� ��������!"<<endl;
	cout<<"!!!���� �� ������ ��������� �������!!!"<<endl;
	cout<<"��������: "<<endl;
	cout<<"C:\\\\Users\\\\Max\\\\Desktop\\\\ZZtop\\\\v-izd-v0-t16\\\\"<<endl;
	cin>>adressDirect;

	cout<<"===================================================================="<<endl;

	strcpy_s(adressPutiTex,adressPuti);//    "���������" ������ ���� � ���������� ��� �����
	strcat_s(adressPutiTex,"*tex");

	strcpy_s(Tablica,adressDirect);//    "���������" ������ ���� � ���������� ��� �����
	strcat_s(Tablica,"Tablica.txt");
	ofstream fout(Tablica);   // ������� ��������� ����, � ������� ����� �������� ����������

	 map<string, string> map;      //�������� ����� ��� �����==����
	  string name;
	  string email;
	

    struct _finddata_t findData;    //�������� ��������� ��� ������ ���� ������ ��������� ���������� �������� ����������
    intptr_t hFile;
 
     

    if((hFile = _findfirst(adressPutiTex, &findData ))  //�������� ���� ���������� � ����������
		
		==-1L)
 
        cout<<endl;
 
    else
    {
        cout<<endl;
        cout<<"��� ����� .tex:\n";
		cout << endl;
      
        do
        {
        
        cout<<findData.name;    //����� ����� ������������� �����
        cout << endl;
		
		char str[100];
		strcpy_s(str, adressPuti);        //��������� � string ���� ���������� � ��� ���������� ����� �� _finndfirst _findnext
		strcat_s(str, findData.name);


		fstream in1(str); //������� ���� ��� ������

		  while (!in1.eof()) //����� ������ ���������� ���� �� ������ �� ����� �����
	   {
	      getline(in1, S);		  
		  
		    

				n = S.find("\\author"); // ����� � ������ ������         
				if (n < string::npos && metkaAuthor == 0){
					name=print(n, S, dlinaTagAuthor);                //����� ��������� � ��������� "\author"
					metkaAuthor = 1;
				}
				
				n = S.find("\\email"); // ����� � ������ ������ ������
				if (n < string::npos && metkaEmail == 0) {  
					email=printEmail(n, S, dlinaTagEmail);           //����� ��������� � ��������� "\email"
					metkaEmail = 1;
					kolAuthor = kolAuthor + 1;
				}				
 		 
				

		    
		  
	   }
       in1.close();  //������� �������� ����
	   
	   metkaAuthor = 0;
	   metkaEmail = 0;
	   map.emplace(name, email);    //������� ���� ���==����
	   cout<<name<<endl;
	   cout<<email<<endl;
	   name="";
	   email="";
	   cout << endl;

        } while ( _findnext ( hFile, &findData ) == 0);

		

        _findclose (hFile);
    }




	for (auto& p : map){
		   cout << "Name: " << p.first<< " Email: " << p.second<< "\n";     //����� ������� ���� �����==����
	}
	 
////////////////////////////////////////////////////����� �� �������� ������������ ���� � ����������� .TOC///////////////////////////////////////////////////
	  std::string::size_type n1;
	  std::string::size_type English;
	  std::string::size_type Russian;
	  std::string::size_type sO;
	  std::string::size_type sC;
      string S1; //� S ����� ����������� ������
	  string kleistr="";
	  int Eng = 0; 
	  bool metkaStranici;
	  
	  int *pageDip = new int[kolAuthor];
	  string *AuthorName = new string[kolAuthor];
	  string nameToc;//���� � �������� ��� ����� �����.TOC==��������
	  string page;
	  
	  strcpy_s(adressPutiToc,adressPuti);
	  strcat_s(adressPutiToc,"*toc");

	   



	if((hFile = _findfirst(adressPutiToc, &findData ))  //�������� ���� ���������� � ����������
		
		==-1L)
 
        cout<<endl;
 
    else
    {
        cout<<endl;
        cout<<"��� ����� .toc:\n";
        		
		do
        {
        
        cout<<findData.name;    //����� ����� ������������� �����
        cout << endl;
		cout << endl;
		
		std::cout		<< std::setw( 25 ) << std::left << "��� ������" 
                        << std::setw( 30 ) << "�������� �����"
                        << std::setw( 10 ) << "��������� ��������"
						<< std::endl;
		std::cout		<< std::setw( 30 ) << std::left << "==============================" 
                        << std::setw( 30 ) << "=============================="
                        << std::setw( 10 ) << "==================="
                        << std::endl;



		fout		<< std::setw( 25 ) << std::left << "��� ������" 
                        << std::setw( 30 ) << "�������� �����"
                        << std::setw( 10 ) << "��������� ��������"
						<< std::endl;
		fout		<< std::setw( 30 ) << std::left << "==============================" 
                        << std::setw( 30 ) << "=============================="
                        << std::setw( 10 ) << "==================="
                        << std::endl;
						

		char str1[100];
		strcpy_s(str1,adressPuti);        //��������� � string ���� ���������� � ��� ���������� ����� �� _finndfirst _findnext
		strcat_s(str1,findData.name);		

		fstream in2(str1); //������� ���� ��� ������


		  int iForPageDip = 0; 
		  int iForAuthorName = 0;
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
		
		while (!in2.eof()) //����� ������ ���������� ���� �� ������ �� ����� �����
	   {
	      getline(in2, S1);		  

				
		//////////////////////////////////////////////////////////////////////////////////////////////////////			
				English = S1.find("{abcdf}{\\selectlanguage {english}"); // ����� ������ ������ �� ���������� �����                   
				Russian = S1.find("{abcdf}{\\selectlanguage {russian}"); // ����� ������ ������ �� ������� �����
					
	///////////////////////////////////////////////////////////////////////////////////////////////////// 
				
				
					

	

				string klei;
				
		        metkaStranici = 0;

				n1 = S1.find("\\contentsline"); // ����� � ������ ������         
				if (n1 < string::npos){
				
				if (Russian < string::npos && English == string::npos){ //��������� ������ ������������� ������			
					
					
					klei=S1.erase(0,S1.find("{\\CYR"));
					klei=klei.erase(klei.find(".}"));
					if(klei.find("},")<string::npos)klei=klei.erase(klei.find("},"+1));
					
			delIEC:
					int IEC = klei.find("\\IeC");                //�������� \IEC, ��� �������
					if(IEC < string::npos){
						klei.erase(IEC,4);
						if (klei.find("\\IeC")<string::npos) goto delIEC;
					}				
					
					
					
					
			delPToc:
					int pToc = klei.find(" ");                //�������� �������, ��� �������
					if(pToc < string::npos){
						klei.erase(pToc,1);
						if (klei.find(" ")<string::npos) goto delPToc;
					}		
					
		symbolOP:
					
					sO = klei.find("{\\CYR");
					sC = klei.find("}");
					nameToc=printToc(sO,sC,klei);       //����� ��������� � ��������� "\author"
					
					kleistr=kleistr+nameToc+".";
					klei=klei.erase(0,sC+1);
					
					if(klei.find("{\\CYR")<string::npos) goto symbolOP;
					if(klei.find("{\\CYR")==string::npos) kleistr=kleistr.erase(kleistr.rfind("."));
		
		symbolOP1:			
					sO = klei.find("{\\cyr");
					sC = klei.find("}");
					nameToc=printToc(sO,sC,klei);       //����� ��������� � ��������� "\author"
					
					kleistr=kleistr+nameToc;
					klei=klei.erase(0,sC+1);
					
					if(klei.find("{\\cyr")<string::npos) goto symbolOP1;
					
					
					
					std::cout		<< std::setw( 25 ) << std::left <<kleistr
									<< std::setw( 30 ) << map.find(kleistr)->second;
									
					
					
					fout			<< std::setw( 25 ) << std::left <<kleistr
									<< std::setw( 30 ) << map.find(kleistr)->second;
					
					
					metkaStranici = 1;
					AuthorName[iForAuthorName]=kleistr;
					iForAuthorName = iForAuthorName + 1;
					kleistr="";
					
					
				}			
				     
		else if(English < string::npos && Russian == string::npos){  //��������� ������ ������������ ������
					metkaStranici = 1;
					string kleiEng = S1;
					Eng = kleiEng.find("\\bfseries");                //�������� �������, ��� �������
					if(Eng < string::npos){
						kleiEng.erase(0,Eng+9);
						
					}

					Eng = kleiEng.find(".}");
					if(Eng < string::npos){
						kleiEng.erase(Eng);
					}
					
					Eng = kleiEng.find(",");
					 
					if(Eng < string::npos){
						kleiEng.erase(Eng);
						
					}
					
					
					
			delPEng:
					Eng = kleiEng.find(" ");                //�������� �������, ��� �������
					if(Eng < string::npos){
						kleiEng.erase(Eng,1);
						if (kleiEng.find(" ")<string::npos) goto delPEng;
					}
					
					std::cout		<< std::setw( 25 ) << std::left <<kleiEng
									<< std::setw( 30 ) << map.find(kleiEng)->second;
									 
									
					
					
					fout			<< std::setw( 25 ) << std::left <<kleiEng
									<< std::setw( 30 ) << map.find(kleiEng)->second;
					AuthorName[iForAuthorName]=kleiEng;
					iForAuthorName = iForAuthorName + 1;
				}

				
				}
				//cout<<nameToc<<endl;
				

				


				n1 = S1.rfind("{"); 
				if (n1 < string::npos && metkaStranici == 1) {    
				page=printPage(n1, S1);           
				
				cout<<std::setw( 30 ) <<page<<endl;
				fout<<std::setw( 30 ) <<page<<endl;
				metkaStranici = 0;
				pageDip[iForPageDip] = atoi( page.c_str() ); //���������� ������� � �������� ������� (��� ������� PDF)
				
				iForPageDip = iForPageDip + 1;
				}
				
		  
	   }
       in2.close();  //������� �������� ����
	   goto exitToc;
	   
	  
        } while ( _findnext ( hFile, &findData ) == 0);

		

        _findclose (hFile);
    }

	exitToc:
	cout<<endl;
	//��� ������ ����������� �� ��������� ������ !!! pdftk A=C:\Users\Max\Desktop\ZZtop\v-izd-v0-t16\izv2016-2-t16.pdf cat A5-8 output C:\Users\Max\Desktop\ZZtop\v-izd-v0-t16\cat.pdf
	
	cout<<"���������� ������ � ��������: "<<kolAuthor<<endl;
	
	
	
	char car[100];	
	
	
	for (int i=1; i<kolAuthor;i++){
		//char op[256] ="\"C:\\Program Files (x86)\\PDFtk\\bin\\pdftk.exe\" A=C:\\Users\\Max\\Desktop\\ZZtop\\v-izd-v0-t16\\izv2016-2-t16.pdf cat A1-2 A";
		//char pop[256] =" output C:\\Users\\Max\\Desktop\\ZZtop\\v-izd-v0-t16\\cat";
		
		char op[256]="\"";
		strcat_s(op,adressPDFtk);
		strcat_s(op,"\" A=");
		strcat_s(op, adressSbornik);
		strcat_s(op," cat A1-2 A");
		
		char pop[256] = " output ";
		strcat_s(pop, adressDirect);
		strcat_s(pop,AuthorName[i-1].c_str());
		
		char dipa[200]="";
		char nar[100]="";
	 _itoa_s(pageDip[i]-1, nar, 10);
	 _itoa_s(pageDip[i-1], car, 10);
	 
	strcat_s(dipa,car);
	strcat_s(dipa,"-");
	strcat_s(dipa,nar);
	strcat_s(op,dipa);
	strcat_s(op,pop);
	strcat_s(op,dipa);
	strcat_s(op,".pdf");
	
		cout<<op<<endl;
	system(op);

	}

	char op[256]="\"";
		strcat_s(op,adressPDFtk);
		strcat_s(op,"\" A=");
		strcat_s(op, adressSbornik);
		strcat_s(op," cat A1-2 A");
		
		char pop[256] = " output ";
		strcat_s(pop, adressDirect);
		strcat_s(pop,AuthorName[kolAuthor-1].c_str());
	char dipa[100]="";
	cout<<pageDip[kolAuthor-1]<<endl;	
	_itoa_s(pageDip[kolAuthor-1],car,10);
	strcat_s(dipa,car);
	strcat_s(dipa,"-end");
	
	strcat_s(op,dipa);
	strcat_s(op,pop);
	strcat_s(op,dipa);
	strcat_s(op,".pdf");
	
		cout<<op<<endl;
	system(op);
	
	
	//C:\\Users\\Max\\Desktop\\ZZtop\\v-izd-v0-t16\\                       ����� ����� ������, ���� ������� � ������� ���� ����������� ������ (�� ��������� � ������)
	
	fout.close();
    _getch();   
	delete pageDip;
	
	system("pause"); 
}
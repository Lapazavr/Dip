#include "stdafx.h"
#include "process.h"
#include <string>
#include <conio.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include <map>
#include "windows.h"
#include <iomanip>              //для создания таблицы
#include <stdlib.h>             //для перевода в атои стринг инт

using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


 string print(std::string::size_type n, std::string const &s, int k)          //здесь функция вывода авторов
{
	    if (n != std::string::npos) {    
        string S = s.substr(n+k);           //вывод подстроки с вхождения "\author"+8
    delP:
					int k0 = S.find(" ");                //удаление пробела, при наличии
					if(k0 < string::npos){
						S.erase(k0,1);
						if (S.find(" ")<string::npos) goto delP;
					}
	delS1:				
					int k1 = S.find("{");                //удаление {, при наличии
					if(k1 < string::npos){
						S.erase(k1,1);
						if (S.find("{")<string::npos) goto delS1;
					}
	delS2:
					int k2 = S.find("}");                //удаление }, при наличии
					if(k2 < string::npos){
						S.erase(k2,1);
						if (S.find("}")<string::npos) goto delS2;
					}
					
					int k3 = S.find("~\\surname");                //удаление ~\\surname, при наличии
					if(k3 < string::npos){
						S.erase(k3,9);
					}
					int k4 = S.find("~");                //удаление ~\\surname, при наличии
					if(k4 < string::npos){
						S.erase(k4,1);
					}
	return S;
	}
		
}
 
string printEmail(std::string::size_type n, std::string const &s, int k)          //здесь функция вывода ымейлов
{
    if (n != std::string::npos) {    
        string S = s.substr(n+k);           //вывод подстроки с вхождения "\email"+6
    delP:
					int k0 = S.find(" ");                //удаление пробела, при наличии
					if(k0 < string::npos){
						S.erase(k0,1);
						if (S.find(" ")<string::npos) goto delP;
					}
	delS1:				
					int k1 = S.find("{");                //удаление {, при наличии
					if(k1 < string::npos){
						S.erase(k1,1);
						if (S.find("{")<string::npos) goto delS1;
					}
	delS2:
					int k2 = S.find("}");                //удаление }, при наличии
					if(k2 < string::npos){
						S.erase(k2,1);
						if (S.find("}")<string::npos) goto delS2;
					}				
	return S;
	}
		    
}


string printToc(std::string::size_type n, std::string::size_type k, string S)          //здесь функция вывода автора из файла .toc
{
    if (n != std::string::npos) {    
        string Symbol=S;
		
			Symbol=Symbol.erase(k);
		Symbol=Symbol.erase(0,n+5);
		
		if(Symbol=="A") Symbol="А";
		if(Symbol=="a") Symbol="а";
		if(Symbol=="B") Symbol="Б";
		if(Symbol=="b") Symbol="б";
		if(Symbol=="V") Symbol="В";
		if(Symbol=="v") Symbol="в";
		if(Symbol=="G") Symbol="Г";
		if(Symbol=="g") Symbol="г";
		if(Symbol=="D") Symbol="Д";
		if(Symbol=="d") Symbol="д";
		if(Symbol=="E") Symbol="Е";
		if(Symbol=="e") Symbol="е";
		if(Symbol=="YO") Symbol="Ё";
		if(Symbol=="yo") Symbol="ё";
		if(Symbol=="ZH") Symbol="Ж";
		if(Symbol=="zh") Symbol="ж";
		if(Symbol=="Z") Symbol="З";
		if(Symbol=="z") Symbol="з";
		if(Symbol=="I") Symbol="И";
		if(Symbol=="i") Symbol="и";
		if(Symbol=="I_shrt") Symbol="Й";
		if(Symbol=="i_shrt") Symbol="й";
		if(Symbol=="K") Symbol="К";
		if(Symbol=="k") Symbol="к";
		if(Symbol=="L") Symbol="Л";
		if(Symbol=="l") Symbol="л";
		if(Symbol=="M") Symbol="М";
		if(Symbol=="m") Symbol="м";
		if(Symbol=="N") Symbol="Н";
		if(Symbol=="n") Symbol="н";
		if(Symbol=="O") Symbol="О";
		if(Symbol=="o") Symbol="о";
		if(Symbol=="P") Symbol="П";
		if(Symbol=="p") Symbol="п";
		if(Symbol=="R") Symbol="Р";
		if(Symbol=="r") Symbol="р";
		if(Symbol=="S") Symbol="С";
		if(Symbol=="s") Symbol="с";
		if(Symbol=="T") Symbol="Т";
		if(Symbol=="t") Symbol="т";
		if(Symbol=="U") Symbol="У";
		if(Symbol=="u") Symbol="у";
		if(Symbol=="F") Symbol="Ф";
		if(Symbol=="f") Symbol="ф";
		if(Symbol=="H") Symbol="Х";
		if(Symbol=="h") Symbol="х";
		if(Symbol=="C") Symbol="Ц";
		if(Symbol=="c") Symbol="ц";
		if(Symbol=="CH") Symbol="Ч";
		if(Symbol=="ch") Symbol="ч";
		if(Symbol=="SH") Symbol="Ш";
		if(Symbol=="sh") Symbol="ш";
		if(Symbol=="SHCH") Symbol="Щ";
		if(Symbol=="shch") Symbol="щ";
		if(Symbol=="HRDSN") Symbol="Ъ";
		if(Symbol=="hrdsn") Symbol="ъ";
		if(Symbol=="ERY") Symbol="Ы";
		if(Symbol=="ery") Symbol="ы";
		if(Symbol=="SFTSN") Symbol="Ь";
		if(Symbol=="sftsn") Symbol="ь";
		if(Symbol=="EREV") Symbol="Э";
		if(Symbol=="erev") Symbol="э";
		if(Symbol=="YU") Symbol="Ю";
		if(Symbol=="yu") Symbol="ю";
		if(Symbol=="YA") Symbol="Я";
		if(Symbol=="ya") Symbol="я";
		
		
		
		return Symbol;           //вывод подстроки с вхождения 
    }
	    
}

string printPage(std::string::size_type n, std::string const &s)          //здесь функция вывода страницы начала статьи из файло .toc
{
    if (n != std::string::npos) {    
        string S = s.substr(n+1);           //вывод подстроки с вхождения "\email"+6
		            int k1 = S.find("{");                //удаление {, при наличии
					if(k1 < string::npos){
						S.erase(k1,1);
					}
					
					int k2 = S.find("}");                //удаление }, при наличии
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
    string S; //В S будут считываться строки

	char adressPuti[256];
	char adressPutiTex[256];
	char adressPutiToc[256];
	char tagAuthor[100];
	char tagEmail[100];
	int dlinaTagAuthor = 0;
	int dlinaTagEmail = 0;
	bool metkaAuthor = 0;         //метка для нахождения первого автора в статье
	bool metkaEmail = 0;          //метка для нахождения первого мыла в статье
	int kolAuthor = 0;            //количество авторов (а так же мейлов и страниц)
	char Tablica[256];
	cout<<"Укажите адресс папки проекта:"<<endl;
	cout<<"!!!ВМЕСТО \\ УКАЗЫВАТЬ \\\\!!!"<<endl;
	cout<<"Путь не должен содержать символов русского алфавита!"<<endl;
	cout<<"!!!ПУТЬ НЕ ДОЛЖЕН СОДЕРЖАТЬ ПРОБЕЛЫ!!!"<<endl;
	cout<<"Например:"<<endl;
	cout<<"C:\\\\Users\\\\Max\\\\Desktop\\\\ZZtop\\\\v-izd-v0-t16\\\\"<<endl;
	//C:\\Users\\Max\\Desktop\\ZZtop\\v-izd-v0-t16\\                       здесь лежит строка, чтоб удобней и быстрее было копипастить адресс (не перебивая в ручную)
	cin>>adressPuti;
	//cin.getline(adressPuti,256);
	
	
	cout<<endl;
	char adressPDFtk[256];
	cout<<"Укажите полный путь к файлу pdftk.exe:"<<endl;
	cout<<"!!!ВМЕСТО \\ УКАЗЫВАТЬ \\\\!!!"<<endl;
	cout<<"Путь не должен содержать символов русского алфавита!"<<endl;
	cout<<"!!!ПУТЬ НЕ ДОЛЖЕН СОДЕРЖАТЬ ПРОБЕЛЫ!!!"<<endl;
	cout<<"Например: "<<endl;
	cout<<"C:\\\\Users\\\\Max\\\\Desktop\\\\bin\\\\pdftk.exe"<<endl;
	//cin.getline(adressPDFtk,256);
	cin>>adressPDFtk;
	
	cout<<endl;
	cout<<"Укажите тэг для автора в файлах .тех проекта:"<<endl;
	cout<<"!!!ВМЕСТО \\ УКАЗЫВАТЬ \\\\!!!"<<endl;
	cout<<"Например: \\\\author"<<endl;
	cin>>tagAuthor;
	
	dlinaTagAuthor = strlen( tagAuthor);

	cout<<endl;
	cout<<"Укажите тэг для адресса почты в файлах .тех проекта:"<<endl;
	cout<<"!!!ВМЕСТО \\ УКАЗЫВАТЬ \\\\!!!"<<endl;
	cout<<"Например: \\\\email"<<endl;
	cin>>tagEmail;
	
	dlinaTagEmail = strlen( tagEmail);

	
	cout<<endl;
	char adressSbornik[256];
	cout<<"Укажите полный путь к PDF файлу готового сборника:"<<endl;
	cout<<"!!!ВМЕСТО \\ УКАЗЫВАТЬ \\\\!!!"<<endl;
	cout<<"Путь не должен содержать символов русского алфавита!"<<endl;
	cout<<"!!!ПУТЬ НЕ ДОЛЖЕН СОДЕРЖАТЬ ПРОБЕЛЫ!!!"<<endl;
	cout<<"Например: "<<endl;
	cout<<"C:\\\\Users\\\\Max\\\\Desktop\\\\ZZtop\\\\v-izd-v0-t16\\\\izv2016-2-t16.pdf"<<endl;
	cin>>adressSbornik;

	cout<<endl;
	char adressDirect[256];
	cout<<"Укажите путь к папке, в которую нужно поместить конечные файлы:"<<endl;
	cout<<"!!!ВМЕСТО \\ УКАЗЫВАТЬ \\\\!!!"<<endl;
	cout<<"Путь не должен содержать символов русского алфавита!"<<endl;
	cout<<"!!!ПУТЬ НЕ ДОЛЖЕН СОДЕРЖАТЬ ПРОБЕЛЫ!!!"<<endl;
	cout<<"Например: "<<endl;
	cout<<"C:\\\\Users\\\\Max\\\\Desktop\\\\ZZtop\\\\v-izd-v0-t16\\\\"<<endl;
	cin>>adressDirect;

	cout<<"===================================================================="<<endl;

	strcpy_s(adressPutiTex,adressPuti);//    "склеиваем" адресс пути и расширение ТЕХ файла
	strcat_s(adressPutiTex,"*tex");

	strcpy_s(Tablica,adressDirect);//    "склеиваем" адресс пути и расширение ТЕХ файла
	strcat_s(Tablica,"Tablica.txt");
	ofstream fout(Tablica);   // создаем текстовый файл, в который будем заносить результаты

	 map<string, string> map;      //создание карты для АВТОР==МЫЛО
	  string name;
	  string email;
	

    struct _finddata_t findData;    //создание структуры для обхода всех файлов заданного расширения заданной директории
    intptr_t hFile;
 
     

    if((hFile = _findfirst(adressPutiTex, &findData ))  //указание пути директории и расширения
		
		==-1L)
 
        cout<<endl;
 
    else
    {
        cout<<endl;
        cout<<"Имя файла .tex:\n";
		cout << endl;
      
        do
        {
        
        cout<<findData.name;    //вывод имени обработанного файла
        cout << endl;
		
		char str[100];
		strcpy_s(str, adressPuti);        //склеиваем в string путь дериктории и имя найденного файла по _finndfirst _findnext
		strcat_s(str, findData.name);


		fstream in1(str); //Открыли файл для чтения

		  while (!in1.eof()) //Будем читать информацию пока не дойдем до конца файла
	   {
	      getline(in1, S);		  
		  
		    

				n = S.find("\\author"); // поиск с начала строки         
				if (n < string::npos && metkaAuthor == 0){
					name=print(n, S, dlinaTagAuthor);                //вывод подстроки с вхождения "\author"
					metkaAuthor = 1;
				}
				
				n = S.find("\\email"); // поиск с начала строки ымейла
				if (n < string::npos && metkaEmail == 0) {  
					email=printEmail(n, S, dlinaTagEmail);           //вывод подстроки с вхождения "\email"
					metkaEmail = 1;
					kolAuthor = kolAuthor + 1;
				}				
 		 
				

		    
		  
	   }
       in1.close();  //Закрыли открытый файл
	   
	   metkaAuthor = 0;
	   metkaEmail = 0;
	   map.emplace(name, email);    //создали пару ИМЯ==МЫЛО
	   cout<<name<<endl;
	   cout<<email<<endl;
	   name="";
	   email="";
	   cout << endl;

        } while ( _findnext ( hFile, &findData ) == 0);

		

        _findclose (hFile);
    }




	for (auto& p : map){
		   cout << "Name: " << p.first<< " Email: " << p.second<< "\n";     //вывод таблицы карт АВТОР==МЫЛО
	}
	 
////////////////////////////////////////////////////ЗДЕСЬ МЫ НАЧИНАЕМ ОБРАБАТЫВАТЬ ФАЙЛ С РАСШИРЕНИЕМ .TOC///////////////////////////////////////////////////
	  std::string::size_type n1;
	  std::string::size_type English;
	  std::string::size_type Russian;
	  std::string::size_type sO;
	  std::string::size_type sC;
      string S1; //В S будут считываться строки
	  string kleistr="";
	  int Eng = 0; 
	  bool metkaStranici;
	  
	  int *pageDip = new int[kolAuthor];
	  string *AuthorName = new string[kolAuthor];
	  string nameToc;//ключ и значение для карты АВТОР.TOC==СТРАНИЦА
	  string page;
	  
	  strcpy_s(adressPutiToc,adressPuti);
	  strcat_s(adressPutiToc,"*toc");

	   



	if((hFile = _findfirst(adressPutiToc, &findData ))  //указание пути директории и расширения
		
		==-1L)
 
        cout<<endl;
 
    else
    {
        cout<<endl;
        cout<<"Имя файла .toc:\n";
        		
		do
        {
        
        cout<<findData.name;    //вывод имени обработанного файла
        cout << endl;
		cout << endl;
		
		std::cout		<< std::setw( 25 ) << std::left << "ИМЯ АВТОРА" 
                        << std::setw( 30 ) << "ПОЧТОВЫЙ АДРЕС"
                        << std::setw( 10 ) << "НАЧАЛЬНАЯ СТРАНИЦА"
						<< std::endl;
		std::cout		<< std::setw( 30 ) << std::left << "==============================" 
                        << std::setw( 30 ) << "=============================="
                        << std::setw( 10 ) << "==================="
                        << std::endl;



		fout		<< std::setw( 25 ) << std::left << "ИМЯ АВТОРА" 
                        << std::setw( 30 ) << "ПОЧТОВЫЙ АДРЕС"
                        << std::setw( 10 ) << "НАЧАЛЬНАЯ СТРАНИЦА"
						<< std::endl;
		fout		<< std::setw( 30 ) << std::left << "==============================" 
                        << std::setw( 30 ) << "=============================="
                        << std::setw( 10 ) << "==================="
                        << std::endl;
						

		char str1[100];
		strcpy_s(str1,adressPuti);        //склеиваем в string путь дериктории и имя найденного файла по _finndfirst _findnext
		strcat_s(str1,findData.name);		

		fstream in2(str1); //Открыли файл для чтения


		  int iForPageDip = 0; 
		  int iForAuthorName = 0;
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
		
		while (!in2.eof()) //Будем читать информацию пока не дойдем до конца файла
	   {
	      getline(in2, S1);		  

				
		//////////////////////////////////////////////////////////////////////////////////////////////////////			
				English = S1.find("{abcdf}{\\selectlanguage {english}"); // поиск автора статьи на английском языке                   
				Russian = S1.find("{abcdf}{\\selectlanguage {russian}"); // поиск автора статьи на русском языке
					
	///////////////////////////////////////////////////////////////////////////////////////////////////// 
				
				
					

	

				string klei;
				
		        metkaStranici = 0;

				n1 = S1.find("\\contentsline"); // поиск с начала строки         
				if (n1 < string::npos){
				
				if (Russian < string::npos && English == string::npos){ //обработка автора русскоязычной статьи			
					
					
					klei=S1.erase(0,S1.find("{\\CYR"));
					klei=klei.erase(klei.find(".}"));
					if(klei.find("},")<string::npos)klei=klei.erase(klei.find("},"+1));
					
			delIEC:
					int IEC = klei.find("\\IeC");                //удаление \IEC, при наличии
					if(IEC < string::npos){
						klei.erase(IEC,4);
						if (klei.find("\\IeC")<string::npos) goto delIEC;
					}				
					
					
					
					
			delPToc:
					int pToc = klei.find(" ");                //удаление пробела, при наличии
					if(pToc < string::npos){
						klei.erase(pToc,1);
						if (klei.find(" ")<string::npos) goto delPToc;
					}		
					
		symbolOP:
					
					sO = klei.find("{\\CYR");
					sC = klei.find("}");
					nameToc=printToc(sO,sC,klei);       //вывод подстроки с вхождения "\author"
					
					kleistr=kleistr+nameToc+".";
					klei=klei.erase(0,sC+1);
					
					if(klei.find("{\\CYR")<string::npos) goto symbolOP;
					if(klei.find("{\\CYR")==string::npos) kleistr=kleistr.erase(kleistr.rfind("."));
		
		symbolOP1:			
					sO = klei.find("{\\cyr");
					sC = klei.find("}");
					nameToc=printToc(sO,sC,klei);       //вывод подстроки с вхождения "\author"
					
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
				     
		else if(English < string::npos && Russian == string::npos){  //обработка автора англоязычной статьи
					metkaStranici = 1;
					string kleiEng = S1;
					Eng = kleiEng.find("\\bfseries");                //удаление пробела, при наличии
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
					Eng = kleiEng.find(" ");                //удаление пробела, при наличии
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
				pageDip[iForPageDip] = atoi( page.c_str() ); //заполнение массива с началами страниц (для нарезки PDF)
				
				iForPageDip = iForPageDip + 1;
				}
				
		  
	   }
       in2.close();  //Закрыли открытый файл
	   goto exitToc;
	   
	  
        } while ( _findnext ( hFile, &findData ) == 0);

		

        _findclose (hFile);
    }

	exitToc:
	cout<<endl;
	//Эта строка запускается из командной строки !!! pdftk A=C:\Users\Max\Desktop\ZZtop\v-izd-v0-t16\izv2016-2-t16.pdf cat A5-8 output C:\Users\Max\Desktop\ZZtop\v-izd-v0-t16\cat.pdf
	
	cout<<"Количество статей в сборнике: "<<kolAuthor<<endl;
	
	
	
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
	
	
	//C:\\Users\\Max\\Desktop\\ZZtop\\v-izd-v0-t16\\                       здесь лежит строка, чтоб удобней и быстрее было копипастить адресс (не перебивая в ручную)
	
	fout.close();
    _getch();   
	delete pageDip;
	
	system("pause"); 
}
 #include <iostream>  
 #include <string>  

 using std::cout;  
 using std::cin;  
 using std::endl; 
 using std::string; 

int main()
{
	string str;
	
	for (int i = 0; i < 100 && !cin.eof(); i++)
	{
		getline(cin, str);
		cout << str << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace  std;

class matrix{


// vector<vector<char>> arr1={
// {'Q','W','E'},
// {'R','T','Y'},
// {'U','I','O'}
// };
// vector<vector<char>> arr2={
// {'P','A','S'},
// {'D','F','G'},
// {'H','J','K'}
// };
// vector<vector<char>> arr3={
// {'L','Z','X'},
// {'C','V','B'},
// {'N','M','.'}
// };
vector<vector<vector<char>>> v;
vector<vector<int>> code;
vector<int> mixedcode;
int count;
public:
	
	//vector<int>
	matrix(){//constructor wo
		count=0;
		v={
	{
		{'Q','W','E'},
		{'R','T','Y'},
		{'U','I','O'},
	},
	{
		{'P','A','S'},
		{'D','F','G'},
		{'H','J','K'},
	},
	{
		{'L','Z','X'},
		{'C','V','B'},
		{'N','M','.'},
	}
	//ending of key
    		};
	}
	vector<int> getcodeforchar(char s)
{
		bool flag=false;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					if(s==v[i][j][k]){
						vector<int> temp;
						temp.push_back(i+1);
						temp.push_back(j+1);
						temp.push_back(k+1);
						return temp;
						flag=true;
						break;
					}
					else{
						continue;
					}
				}
				if(flag==true){
					break;
				}
			}
			if(flag==true){
				break;
			}
		}
		if(flag==false){
			vector<int> temp={-1,-1,-1};
			return(temp);
		}
}
void stringcode(string s);
//void mixingarr();
void syboler();
vector<int> mixingarr(){
	vector<int> temp;
	for(int i=0;i<3;i++){
		for(int j=0;j!=count;j++){
			temp.push_back(code[j][i]);
		}

	}
	return(temp);
}
///ending of class defenition
};
void matrix::stringcode(string s){
	cout<<s<<"\n";
	for(auto i=s.begin();i!=s.end();i++){
		vector<int> temp=getcodeforchar(*i);
		code.push_back(temp);
		count++;
	}
	syboler();
}
void matrix::syboler(){

	mixedcode=mixingarr();
	for(auto i=mixedcode.begin();i!=mixedcode.end();i++){
		if(*i==1){
			cout<<".";
		}
		else if(*i==2){
			cout<<"_";
		}
		else{
			cout<<"/";
		}
	}
}
int main()
{
	string pwd;
	matrix m;
	cout<<"enter your pwd in caps\n";
	cin>>pwd;
	m.stringcode(pwd);
	return 0;
}
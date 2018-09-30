/* 
Description
 һ����׺���ʽ���ܰ�����������СдӢ����ĸ�ͣ����������ͣ������㡣���ʽ���ܰ����ո�
���磬12.02  x + 2  3 * +.
�����һ�������׺���ʽֵ�ĺ�����

Input
��һ����һ������������ʾ�����������������������ɲ���������
ÿ�����������ĵ�һ����һ����׺���ʽ���ڶ�����������ĸ���ֵĸ�����Ȼ����ÿ����ĸ�������ֵ��

Output
 ��ÿ������������������ʽ��ֵ������3λС����ÿ�����ռһ�С�������ʽ���г���Ϊ0��������������Error'.

Sample Input
2
ab + 2.3 +
2
a:1
b:2.1
a b/
2
a:1
b:0

Sample Output
5.400
Error
*/ 
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
double eval(string e, map<char,double> f);

int main()
{
	int t;
	cin >> t;
	cin.clear();
	cin.ignore();    // Eat the '\n'.
	while(t--){
		string s;
		getline(cin, s);
		int n;
		cin >> n;
		cin.clear(); // Don't forget this! 
		cin.ignore();
		map<char, double> mymap;
		while(n--){
			char tmp_c;
			double tmp_d;
			cin >> tmp_c;
			cin.clear();
			cin.ignore();    // Eat the ':'.
			cin >> tmp_d;
			cin.clear();
			cin.ignore();    // Eat the '\n'.
			mymap[tmp_c] = tmp_d;
		}
		
		try{
			cout << fixed << setprecision(3) << eval(s, mymap) << endl;
		}
		catch(const char*){
			cout << "Error" << endl;
		}
	}
	return 0;
}

double eval(string e, map<char,double> f){
	stack<double> stk;
	for(int i = 0; i < e.length(); i++){
		char c = e[i];
		
		if(c>='0' && c<='9'){
			ostringstream os;
			while((e[i]>='0' && e[i]<='9') || e[i]=='.'){	// Read the whole number into os.
				os << e[i];
				i++;
			}
			stk.push(stod(os.str())); 
		}
		else if(c>='a' && c<='z'){
			stk.push(f[c]);
		}
		else{
			if(c=='+'){
				double z = stk.top();
				stk.pop();
				double y = stk.top();
				stk.pop();
				stk.push(y+z);
			}
			if(c=='-'){
				double z = stk.top();
				stk.pop();
				double y = stk.top();
				stk.pop();
				stk.push(y-z);
			}
			if(c=='*'){
				double z = stk.top();
				stk.pop();
				double y = stk.top();
				stk.pop();
				stk.push(y*z);
			}
			if(c=='/'){
				double z = stk.top();
				stk.pop();
				double y = stk.top();
				stk.pop();
				if(z==0){
					throw "Division by zero.";
				}
				stk.push(y/z);
			}
		}
	}
	return stk.top();
}

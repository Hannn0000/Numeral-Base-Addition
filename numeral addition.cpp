#include <iostream>
using namespace std;

int get_num (char , int );
void addition (int ,int ,int );

int main()
{
	string num;
	int base,num_a,num_b;
	cout<<"Please enter the base number (2,8,10,16) : ";
	cin >> base;
	num_a = get_num('a',base);
	num_b = get_num('b',base);
	addition (num_a, num_b, base);
}

int get_num (char num_type, int base)
{
	string num;
	int number = 0;
	cout<<"Please enter the number you want to add : ";
	cin >>num;
	char bas;
	bas = (char) (base + 87); 
	
	for ( int i = 0; i<=num.length() ; i++)
	{
        if (num[i] >= '0' && num[i] <= '9')
        {
        	if((num[i]-48) >= base)
        	{
        		cerr<<"Invalid input!!!"<<endl;
        		exit(0);
			}
		}
		
		else if (num[i] >= 'a' && num[i] <= 'e')
		{
			if(num[i] >= bas)
			{
				cerr<<"Invalid input!!!"<<endl;
        		exit(0);
			}
		}
		
		else if (num[i] >= 'f')
		{
			cerr<<"Invalid input!!!"<<endl;
			exit(0);
		}
        
	}
	int val = 1;
	for (int i = 0; i < num.length(); i++)
    {
        for (int j = i; j < num.length() - 1; j++)
        {
            val *= base;
        } 
        if (num[i] >= '0' && num[i] <= '9')
        {
            number += (num[i] - 48) * val;
        }
        else if (num[i] >= 'a' && num[i] <= 'f')
        {
            number += (num[i] - 87) * val;
        }
        val = 1;
    }
	return number;
}

void addition (int num_a,int num_b,int base)
{
	int digit,ans[50];
	int sum = num_a + num_b;

   while (sum != 0)
 	{
 		ans[digit] = sum % base;
 		sum /= base;
 		digit ++;
	}
	cout<<"The sum of these two numbers is ";
	for (int a = digit -1; a >= 0; a--)
    {
        if (ans[a] >= 10)
        {
            cout << (char)(ans[a] + 87);
        }
        else
        {
            cout << ans[a];
        }
    }
}



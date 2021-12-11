#include <iostream>
#include <queue>
#include<deque>
using namespace std;
int main()
{
    char input[25];
    cout<<"Please input the postfix expression to calculate in 25 characters or less."<<endl;
    cin>>input;
    deque<int> queue;
    int a, b;
    for (int i=0;i<25;i++)
    {
        if((input[i]=='0')||(input[i]=='1')||(input[i]=='2')||(input[i]=='3')||(input[i]=='4')||(input[i]=='5')||(input[i]=='6')||(input[i]=='7')||(input[i]=='8')||(input[i]=='9'))
        {switch(input[i]){
            case '0':
                queue.push_front(0);
                break;
            case '1':
                queue.push_front(1);
                break;
            case '2':
                queue.push_front(2);
                break;
            case '3':
                queue.push_front(3);
                break;
            case '4':
                queue.push_front(4);
                break;
            case '5':
                queue.push_front(5);
                break;
            case '6':
                queue.push_front(6);
                break;
            case '7':
                queue.push_front(7);
                break;
            case '8':
                queue.push_front(8);
                break;
            case '9':
                queue.push_front(9);
                break;
            }
        }
        else
        {
            if((input[i]=='+')||(input[i]=='*')||(input[i]=='/')||(input[i]=='-')||(input[i]=='%'))
            {
                a=queue.front();
                queue.pop_front();
                b=queue.front();
                queue.pop_front();
                 switch(input[i]){
                    case '*':
                        queue.push_front(b*a);
                        break;
                    case '+':
                        queue.push_front(b+a);
                        break;
                    case '/':
                        queue.push_front(b/a);
                        break;
                    case '-':
                        queue.push_front(b-a);
                        break;
                    case '%':
                        queue.push_front(b%a);
                        break;
                    }
                }
            else
            {cout << "End calculation." << endl;
            break;}
        }
    }
cout<<"The result is " << queue.back()<<endl;       
}
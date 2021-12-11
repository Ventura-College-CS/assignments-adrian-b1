#include <iostream>
#include <queue>

using namespace std;
int main()
{
    char input[25];
    cout<<"Please input the postfix expression to calculate in 25 characters or less."<<endl;
    cin>>input;
    queue<int> queue;
    int a, b;
    for (int i=0;i<25;i++)
    {
        if(input[i]==('0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'))
        {switch(input){
            case '0':
                queue.enqueue(0);
                break;
            case '1':
                queue.enqueue(1);
                break;
            case '2':
                queue.enqueue(2);
                break;
            case '3':
                queue.enqueue(3);
                break;
            case '4':
                queue.enqueue(4);
                break;
            case '5':
                queue.enqueue(5);
                break;
            case '6':
                queue.enqueue(6);
                break;
            case '7':
                queue.enqueue(7);
                break;
            case '8':
                queue.enqueue(8);
                break;
            case '9':
                queue.enqueue(9);
                break;
        }
        else
        {
            if(input[i]==('+'||'*'||'/'||'-'||'%'))
            {
                a=queue.front();
                queue.pop();
                b=queue.front();
                queue.pop();
                 switch(input){
                    case '*':
                        queue.enqueue(a*b);
                        break;
                    case '+':
                        queue.enqueue(a+b);
                        break;
                    case '/':
                        queue.enqueue(a/b);
                        break;
                    case '-':
                        queue.enqueue(a-b);
                        break;
                    case '%':
                        queue.enqueue(a%b);
                        break;
                    }
                }
            else
            {cout << "Input not recognized." << endl;}
            }
        
        
}
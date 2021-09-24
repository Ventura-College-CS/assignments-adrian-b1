#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char mainstr[10]="chocolate";
    char substr[10]="col";
    int pos, i, j;
    int flag=0;
    for (i=0; i<strlen(mainstr)-strlen(substr);i++)
        {
            for(j=0;j<strlen(substr);j++)
            {
                if(substr[j]!=mainstr[i+j])
                break;
            }
            if(j==strlen(substr))
            {
                cout << " matched at the position " << i << endl;
                flag = 1;
            }
        }
    if(!flag)
        cout << " We did not find the substring \n";
}
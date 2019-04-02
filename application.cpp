#include "application.h"
#include <iostream>
#include <number.h>
#include <math.h>
#include "polinom.h"
using namespace std;
TApplication::TApplication(int argc, char **argv) :
    QCoreApplication(argc, argv)
{

}
int TApplication::run()
{
    int ch;
    number a = 1, b = -2, c = 1;
    while (true)
    {
        cout <<"1 - Input data" << endl;
        cout <<"2 - Roots" << endl;
        cout <<"3 - Value" << endl;
        cout <<"4 - Output" << endl;
        cout <<"0 - Exit" << endl;
        cout <<">";
        cin >> ch;
        switch(ch)
        {
        case 1:
             {
            cout <<"Enter a,b,c: " << endl;
            cout << ">";
            cin >> a >> b >> c;
             }
            break;
        case 2:
              {
                TPolinom p(a,b,c);
                number *x = new number[2];
                int num_roots = p.roots(x);
                if (num_roots == 2)
                  {
                    cout <<"Roots:" << x[0] <<"," << x[1] <<endl;
                     }
                if (num_roots == 1)
                    {
                    cout << "Root:" << x[0]<< endl;
                    }
                if (num_roots == 0)
                {
                    cout << "No roots!" << endl;
                }
              } break;
        case 3:
                {
                TPolinom p(a,b,c);
                number x;
                cout <<"Enter x:" << endl;
                cout << ">";
                cin >>x;
                cout << "P("<<x<<")="<<p.value(x)<<endl;
                 }
            break;
          case 4:
                {
                TPolinom p(a,b,c);
                cout << p << endl;
                }
            break;
        default:break;
        }
        if (ch == 0)
            break;
    }
    return 0;
}




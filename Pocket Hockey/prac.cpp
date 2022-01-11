#include<iostream>

using namespace std;

int main()
{
    class sample
    {
        int x;
        int y;
        public:
        sample()
        {
            cout<<"Normal "<<endl;
        }
        ~sample()
        {
            cout<<"destr"<<endl;
        }
    };
    sample *s[2],s2;
    return 0;
}


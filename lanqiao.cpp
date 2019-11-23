#include <iostream>
#include <iomanip>

using namespace std;

class CRumenPractice
{
public:
    void begin_1();
};
void CRumenPractice::begin_1()
{
    string str;
    cout<<"cin的测试："<<endl;
    cin>>str;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout<<str<<endl;
    cin>>str;
    cout<<str<<endl;
}
int main(){
    CRumenPractice r;
    r.begin_1();
    return 0;
}
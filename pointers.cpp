#include <bits/stdc++.h>
using namespace std;

class Cookie{
    private: string color;
    public:
        Cookie(string color){
        this->color = color;

    }
    string getColor(){
        return color;
    }
    void setColor(string color){
        this->color = color;
    }

};

int main()
{
  /*  int* num1= new int(11);
    int* num2 = num1;//num1 and num 2 are having same
    cout<<*num1<<" "<<*num2<<endl;*/

    Cookie* cookieOne = new Cookie("green");
    Cookie* cookieTwo = new Cookie("blue");
    cout<<cookieOne->getColor()<<endl;
    cout<<cookieTwo->getColor()<<endl;
    return 0;
}

#include<bits/stdc++.h>
#include "interpreter.h"

int main()
{
    Canvas canvas(800,800);
    canvas.setOrigin(50,0);
    Interpreter pattern1("^[X]",&canvas);
    pattern1.addProduction('X',"[-X][+X][+X][-X]+FX");
    pattern1.addProduction('F',"FF");
    pattern1.addMeaning('X',0);
    Color color1(255,0,0);
    pattern1.addMeaning('F',1,5,&color1);
    pattern1.addMeaning('[',2);
    pattern1.addMeaning(']',3);
    pattern1.addMeaning('^',4,90);
    pattern1.addMeaning('-',4,25);
    pattern1.addMeaning('+',4,-25);
    for(int i = 0;i<7;i++)
    {
        pattern1.createNewGeneration();
        char buf[1000000];
        pattern1.getCurrent(buf);
        cout<<buf<<endl;
    }
    pattern1.interpret();

    canvas.setOrigin(250,0);
    Interpreter pattern2("^[X]",&canvas);
    pattern2.addProduction('X',"[-X][+X][+X][-X]+FX");
    pattern2.addProduction('F',"FF");
    pattern2.addMeaning('X',0);
    Color color2(0,255,56);
    pattern2.addMeaning('F',1,5,&color2);
    pattern2.addMeaning('[',2);
    pattern2.addMeaning(']',3);
    pattern2.addMeaning('^',4,90);
    pattern2.addMeaning('-',4,25);
    pattern2.addMeaning('+',4,-25);
    for(int i = 0;i<7;i++)
    {
        pattern2.createNewGeneration();
        char buf[1000000];
        pattern2.getCurrent(buf);
        cout<<buf<<endl;
    }
    pattern2.interpret();

    canvas.display();
    return 0;
}
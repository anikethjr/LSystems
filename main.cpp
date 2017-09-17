#include<bits/stdc++.h>
#include "interpreter.h"

int main()
{
    Interpreter interpreter("X",800,800);
    interpreter.setOrigin(100,700);
    interpreter.addProduction('X',"F[−X][X]F[−X]+FX");
    interpreter.addProduction('F',"FF");
    interpreter.addMeaning('X',0);
    Color color(255,0,0);
    interpreter.addMeaning('F',1,5,&color);
    interpreter.addMeaning('[',2);
    interpreter.addMeaning(']',3);
    interpreter.addMeaning('-',4,25);
    interpreter.addMeaning('+',4,-25);
    for(int i = 0;i<6;i++)
    {
        interpreter.createNewGeneration();
        char buf[1000000];
        interpreter.getCurrent(buf);
        cerr<<buf<<endl;
    }
    interpreter.interpret();
    interpreter.display();
    return 0;
}
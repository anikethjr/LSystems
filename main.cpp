#include<bits/stdc++.h>
#include "interpreter.h"
#include <string>

int main()
{

    Canvas canvas(1400, 1400);
    //canvas.setBackgroundColor(Color(255, 255, 255));
//    canvas.setOrigin(100, 100);
//    Interpreter pattern1("^[X]",&canvas);
//    pattern1.addProduction('X', "[-X/][+X/][+X][-X/]+FX/");
////    pattern1.addProduction('X', "[-/FX][+X][+X][-X]+/FX");
//    pattern1.addProduction('F',"FF");
//    pattern1.addMeaning('X',0);
    Color color1(25, 23, 111);
    Color color2(20, 123, 20);
//    pattern1.addMeaning('F',1,5,&color1);
//    pattern1.addMeaning('[',2);
//    pattern1.addMeaning(']',3);
//    pattern1.addMeaning('^',4,90);
//    pattern1.addMeaning('-',4,25);
//    pattern1.addMeaning('+',4,-25);
//    pattern1.addMeaning('/', 5, 2, &color2);
//    for (int i = 0; i < 7; i++) {
//        pattern1.createNewGeneration();
//        char buf[1000000];
//        pattern1.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern1.interpret();
//
//    canvas.setOrigin(500, 0);
//    Interpreter pattern2("^[X]", &canvas);
//    pattern2.addProduction('X', "F+[X/]-F-[X/]+X/");
//    pattern2.addProduction('F', "FF");
//    pattern2.addMeaning('X', 0);
//    Color color3(139, 69, 19);
//    pattern2.addMeaning('F', 1, 5, &color3);
//    pattern2.addMeaning('[', 2);
//    pattern2.addMeaning(']', 3);
//    pattern2.addMeaning('^', 4, 90);
//    pattern2.addMeaning('-', 4, 25);
//    pattern2.addMeaning('+', 4, -25);
//    pattern2.addMeaning('/', 5, 2, &color2);
//    for (int i = 0; i < 6; i++) {
//        pattern2.createNewGeneration();
//        char buf[1000000];
//        pattern2.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern2.interpret();

//    canvas.setOrigin(500, 100);
//    Interpreter pattern3("^[X]", &canvas);
//    pattern3.addProduction('X', "F[+X]-X");
//    pattern3.addProduction('F', "FF");
////    pattern3.addProduction('Y',"Y/");
//    pattern3.addMeaning('X', 5, 5, &color1);
//    Color color4(134, 234, 24);
//    pattern3.addMeaning('F', 1, 5, &color4);
//    pattern3.addMeaning('[', 2);
//    pattern3.addMeaning(']', 3);
//    pattern3.addMeaning('^', 4, 90);
//    pattern3.addMeaning('-', 4, 45);
//    pattern3.addMeaning('+', 4, -45);
//    pattern3.addMeaning('/', 5, 5, &color1);
//    for(int i = 0;i<7;i++)
//    {
//        pattern3.createNewGeneration();
//        char buf[1000000];
//        pattern3.getCurrent(buf);
//        cout<<buf<<endl;
//    }
//    pattern3.interpret();

    // Tree with flowers
    canvas.setOrigin(500, 100);
    Interpreter pattern3("^[X]", &canvas);
    pattern3.addProduction('X', "F[+XL]-XL");  // L is the production for flower
    pattern3.addProduction('F', "FF");
    pattern3.addProduction('L', "/B");
    pattern3.addProduction('B', "[G/][(G/)][((G/))][)G/(][))G/((]"); // G forward with black color
//    pattern3.addProduction('B',"[GT][(GT)][((GT))][)GT(][))GT((]");
    pattern3.addMeaning('X', 0);
    pattern3.addMeaning('B', 0);
    Color color4(165, 42, 42);
    Color col_flower(216, 41, 222);
    Color color3(0, 0, 0);
    pattern3.addMeaning('F', 1, 5, &color4);
    pattern3.addMeaning('G', 1, 6, &color3);
    pattern3.addMeaning('[', 2);
    pattern3.addMeaning(']', 3);
    pattern3.addMeaning('^', 4, 90);
    pattern3.addMeaning('-', 4, 60);
    pattern3.addMeaning('+', 4, -60);
//    pattern3.addMeaning('T', 5, 4, &color2);
    pattern3.addMeaning('/', 5, 3, &col_flower);
    pattern3.addMeaning('(', 4, 72);
    pattern3.addMeaning(')', 4, -72);
    for (int i = 0; i < 8; i++) {
        pattern3.createNewGeneration();
        char buf[1000000];
        pattern3.getCurrent(buf);
        cout << buf << endl;
    }
    pattern3.interpret();

    canvas.setOrigin(800, 100);
    Interpreter pattern4("^[X]", &canvas);
    pattern4.addProduction('X', "FXL");  // L is the production for flower
    pattern4.addProduction('F', "FF");
    pattern4.addProduction('L', "/B");
    pattern4.addProduction('B', "[G/][(G/)][((G/))][)G/(][))G/((]"); // G forward with black color
//    pattern3.addProduction('B',"[GT][(GT)][((GT))][)GT(][))GT((]");
    pattern4.addMeaning('X', 0);
    pattern4.addMeaning('B', 0);
//    Color color4(134, 234, 24);
//    Color color3(0, 0, 0);
    pattern4.addMeaning('F', 1, 5, &color4);
    pattern4.addMeaning('G', 1, 12, &color3);
    pattern4.addMeaning('[', 2);
    pattern4.addMeaning(']', 3);
    pattern4.addMeaning('^', 4, 90);
    pattern4.addMeaning('-', 4, 60);
    pattern4.addMeaning('+', 4, -60);
//    pattern3.addMeaning('T', 5, 4, &color2);
    pattern4.addMeaning('/', 5, 6, &color1);
    pattern4.addMeaning('(', 4, 72);
    pattern4.addMeaning(')', 4, -72);
    for (int i = 0; i < 6; i++) {
        pattern4.createNewGeneration();
        char buf[1000000];
        pattern4.getCurrent(buf);
        cout << buf << endl;
    }
    pattern4.interpret();


    canvas.display();
    return 0;
}
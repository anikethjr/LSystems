#include<bits/stdc++.h>
#include "interpreter.h"
#include <string>

int main()
{

    Canvas canvas(1400, 1400);
    Color color1(255, 255, 0), color2(20, 123, 20), color3(0, 0, 0), color4(165, 42, 42);
    Color col_flower(216, 41, 222), col_flower2(233, 130, 52), col_flower3(34, 100, 230);


    // Tree with flowers
    canvas.setOrigin(200, 200);
    Interpreter pattern3("^[X]", &canvas);
    pattern3.addProduction('X', "F[+X/B]-X/B");
    pattern3.addProduction('F', "FF");
//    pattern3.addProduction('L', "/B");
    pattern3.addProduction('B', "[G/][(G/)][((G/))][)G/(][))G/((]"); // G forward with black color
    pattern3.addMeaning('X', 0);
    pattern3.addMeaning('B', 0);
    pattern3.addMeaning('F', 1, 15, &color4);
    pattern3.addMeaning('G', 1, 8, &color3);
    pattern3.addMeaning('[', 2);
    pattern3.addMeaning(']', 3);
    pattern3.addMeaning('^', 4, 90);
    pattern3.addMeaning('-', 4, 60);
    pattern3.addMeaning('+', 4, -60);
    pattern3.addMeaning('/', 5, 3, &col_flower);
    pattern3.addMeaning('(', 4, 72);
    pattern3.addMeaning(')', 4, -72);
    for (int i = 0; i < 6; i++) {
        pattern3.createNewGeneration();
        char buf[1000000];
        pattern3.getCurrent(buf);
        cout << buf << endl;
    }
    pattern3.interpret();

    // Test flower
    canvas.setOrigin(100, 400);
    Interpreter pattern5("X", &canvas);
    pattern5.addProduction('X', "FXL");  // L is for leaf
    pattern5.addProduction('F', "FF");
//    [(G++G++G][(--G--G--G]
//    [--G++G++G][++G--G--G]
    pattern5.addProduction('L', "[(G++G++G][(--G--G--G][--G++G++G][++G--G--G]"); // G is forward for leaf
    pattern5.addMeaning('X', 0);
    pattern5.addMeaning('F', 1, 15, &color4);
    pattern5.addMeaning('G', 1, 15, &color1);
    pattern5.addMeaning('[', 2);
    pattern5.addMeaning(']', 3);
    pattern5.addMeaning('^', 4, 90);
    pattern5.addMeaning('-', 4, 60);
    pattern5.addMeaning('+', 4, -60);
    pattern5.addMeaning('(', 4, 30);
    pattern5.addMeaning(')', 4, -30);
    for (int i = 0; i < 2; i++) {
        pattern5.createNewGeneration();
        char buf[1000000];
        pattern5.getCurrent(buf);
        cout << buf << endl;
    }
    pattern5.interpret();

    // A tree with rhombus flowers
    canvas.setOrigin(500, 0);
    Interpreter pattern6("^[X]", &canvas);
    pattern6.addProduction('X', "F[+XL]-XL");  // L is for leaf
    pattern6.addProduction('F', "FF");
//    pattern6.addProduction('L', "[(G))G))G))G]"); // G is forward for leaf
    pattern6.addProduction('L', "[(G(G(((G(G][)G)G)))G)G][((G(G(((G(G][))G)G)))G)G]");
    pattern6.addMeaning('X', 0);
    pattern6.addMeaning('F', 1, 15, &color4);
    pattern6.addMeaning('G', 1, 10, &col_flower3);
    pattern6.addMeaning('[', 2);
    pattern6.addMeaning(']', 3);
    pattern6.addMeaning('^', 4, 90);
    pattern6.addMeaning('-', 4, 60);
    pattern6.addMeaning('+', 4, -60);
    pattern6.addMeaning('(', 4, 45);
    pattern6.addMeaning(')', 4, -45);
    for (int i = 0; i < 6; i++) {
        pattern6.createNewGeneration();
        char buf[1000000];
        pattern6.getCurrent(buf);
        cout << buf << endl;
    }
    pattern6.interpret();

    // A tree with triangular flowers
    canvas.setOrigin(200, -800);
    Interpreter pattern7("^[X]", &canvas);
    pattern7.addProduction('X', "F[+XL]-XL");  // L is for leaf
    pattern7.addProduction('F', "FF");
//    pattern6.addProduction('L', "[(G))G))G))G]"); // G is forward for leaf
    pattern7.addProduction('L', "[(G++G++G][(--G--G--G][--G++G++G][++G--G--G]");
    pattern7.addMeaning('X', 0);
    pattern7.addMeaning('F', 1, 15, &color4);
    pattern7.addMeaning('G', 1, 10, &color1);
    pattern7.addMeaning('[', 2);
    pattern7.addMeaning(']', 3);
    pattern7.addMeaning('^', 4, 90);
    pattern7.addMeaning('-', 4, 60);
    pattern7.addMeaning('+', 4, -60);
    pattern7.addMeaning('(', 4, 30);
    pattern7.addMeaning(')', 4, -30);
    for (int i = 0; i < 6; i++) {
        pattern7.createNewGeneration();
        char buf[1000000];
        pattern7.getCurrent(buf);
        cout << buf << endl;
    }
    pattern7.interpret();



    canvas.display();
    return 0;
}



//canvas.setBackgroundColor(Color(255, 255, 255));
//    canvas.setOrigin(100, 100);
//    Interpreter pattern1("^[X]",&canvas);
//    pattern1.addProduction('X', "[-X/][+X/][+X][-X/]+FX/");
//    pattern1.addProduction('X', "[-/FX][+X][+X][-X]+/FX");
//    pattern1.addProduction('F',"FF");
//    pattern1.addMeaning('X',0);
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
//
//    canvas.setOrigin(500, 100);
//    Interpreter pattern3("^[X]", &canvas);
//    pattern3.addProduction('X', "F[+X]-X");
//    pattern3.addProduction('F', "FF");
//    pattern3.addProduction('Y',"Y/");
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

//    A flower
//    canvas.setOrigin(800, 100);
//    Interpreter pattern4("^[X]", &canvas);
//    pattern4.addProduction('X', "FXL");  // L is the production for flower
//    pattern4.addProduction('F', "FF");
//    pattern4.addProduction('L', "/B");
//    pattern4.addProduction('B', "[G/][(G/)][((G/))][)G/][))G/((]"); // G forward with black color
//    pattern4.addMeaning('X', 0);
//    pattern4.addMeaning('B', 0);
//    pattern4.addMeaning('F', 1, 5, &color4);
//    pattern4.addMeaning('G', 1, 12, &color3);
//    pattern4.addMeaning('[', 2);
//    pattern4.addMeaning(']', 3);
//    pattern4.addMeaning('^', 4, 90);
//    pattern4.addMeaning('-', 4, 60);
//    pattern4.addMeaning('+', 4, -60);
//    pattern3.addMeaning('T', 5, 6, &col_flower2);
//    pattern4.addMeaning('/', 5, 6, &color1);
//    pattern4.addMeaning('(', 4, 72);
//    pattern4.addMeaning(')', 4, -72);
//    for (int i = 0; i < 6; i++) {
//        pattern4.createNewGeneration();
//        char buf[1000000];
//        pattern4.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern4.interpret();
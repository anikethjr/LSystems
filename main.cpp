#include <string>
#include<bits/stdc++.h>
#include "interpreter.h"

class LongTree {
public:
    LongTree(Color &colorBranch, Color &colorFlower, int x, int y, Canvas &canvas, int alignment, int generations = 6) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^[X]", &canvas);
        pattern.addProduction('F', "FF");
        pattern.addMeaning('X', 0);
        pattern.addMeaning('F', 1, 5, &colorBranch);
        pattern.addMeaning('[', 2);
        pattern.addMeaning(']', 3);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 25);
        pattern.addMeaning('+', 4, -25);
        pattern.addMeaning('P', 5, 2, &colorFlower);
        pattern.addMeaning('G', 1, 5, &colorFlower);
        pattern.addProduction('L', "[(G(G(((G(G][)G)G)))G)G][((G(G(((G(G][))G)G)))G)G]");
        pattern.addMeaning('(', 4, 45);
        pattern.addMeaning(')', 4, -45);
        if (alignment == 1) // left alignment
            pattern.addProduction('X', "F-[XL]+F+[XL]-XL");
        else
            pattern.addProduction('X', "F+[XP]-F-[XP]+XP");

        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }
};

class Shrub {
public:
    Shrub(Color &colorBranch, int x, int y, Canvas &canvas, int alignment, int generations = 6) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^[X]", &canvas);
        pattern.addProduction('F', "FF");
        pattern.addMeaning('X', 0);
        pattern.addMeaning('F', 1, 4, &colorBranch);
        pattern.addMeaning('[', 2);
        pattern.addMeaning(']', 3);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 25);
        pattern.addMeaning('+', 4, -25);
        if (alignment == 0) // left alignment
            pattern.addProduction('X', "[-X][+X][+X][-X]+FX");
        else if (alignment == 1)  // right alignment
            pattern.addProduction('X', "[+X][-X][-X][+X]-FX");
        else // symmetrical
            pattern.addProduction('X', "[-FX][+X][+X][-X]+FX");

        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }

};

class OctagonStar {
public:
    OctagonStar(Color &starColor, int x, int y, Canvas &canvas, int generations = 2) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^[F+F+F+F+F+F+F+F+F]", &canvas);
        pattern.addProduction('F', "FF+F+F+F+F+F+F+FF");
        pattern.addMeaning('F', 1, 5, &starColor);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 135);
        pattern.addMeaning('+', 4, -135);
        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }

};

class SnowFlake {
public:
    SnowFlake(Color &snowFlakeColor, int x, int y, Canvas &canvas, int generations = 1) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^[F+F+F]", &canvas);
        pattern.addProduction('F', "F-F+F-F");
        pattern.addMeaning('F', 1, 2.5, &snowFlakeColor);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 60);
        pattern.addMeaning('+', 4, -120);
        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }
};

class TreeA {
public:
    TreeA(Color &colorBranch, int x, int y, Canvas &canvas, int generations = 5) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^[F]", &canvas);
        pattern.addProduction('F', "[+F]F[-F]F");
        pattern.addMeaning('F', 1, 6, &colorBranch);
        pattern.addMeaning('[', 2);
        pattern.addMeaning(']', 3);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 25.7);
        pattern.addMeaning('+', 4, -25.7);

        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }

};

class TreeB {
public:
    TreeB(Color &colorBranch, int x, int y, Canvas &canvas, int generations = 5) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^[F]", &canvas);
        pattern.addProduction('F', "F[+F]F[-F]F");
        pattern.addMeaning('F', 1, 6, &colorBranch);
        pattern.addMeaning('[', 2);
        pattern.addMeaning(']', 3);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 20);
        pattern.addMeaning('+', 4, -20);

        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }

};

class TreeC {
public:
    TreeC(Color &colorBranch, int x, int y, Canvas &canvas, int generations = 4) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^[F]", &canvas);
        pattern.addProduction('F', "FF-[-F+F+F]+[+F-F-F]");
        pattern.addMeaning('F', 1, 5, &colorBranch);
        pattern.addMeaning('[', 2);
        pattern.addMeaning(']', 3);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 22.5);
        pattern.addMeaning('+', 4, -22.5);

        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }

};

class TreeD {
public:
    TreeD(Color &colorBranch, Color &colorFlower, int x, int y, Canvas &canvas, int generations = 5) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^X", &canvas);
        pattern.addProduction('X', "F[+XL][-XL]FX");
        pattern.addProduction('F', "FF");
        pattern.addMeaning('X', 0);
        pattern.addMeaning('F', 1, 3, &colorBranch);
        pattern.addMeaning('P', 5, 2, &colorFlower);
        pattern.addMeaning('[', 2);
        pattern.addMeaning(']', 3);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 25.7);
        pattern.addMeaning('+', 4, -25.7);
        pattern.addMeaning('G', 1, 3, &colorFlower);
        pattern.addProduction('L', "[(G(G(((G(G][)G)G)))G)G][((G(G(((G(G][))G)G)))G)G]");
        pattern.addMeaning('(', 4, 45);
        pattern.addMeaning(')', 4, -45);

        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }

};

class TreeE {
public:
    TreeE(Color &colorBranch, Color &colorFlower, int x, int y, Canvas &canvas, int generations = 5) {
        canvas.setOrigin(x, y);
        Interpreter pattern("^[X]", &canvas);
        pattern.addProduction('X', "F-[[X]+X]+F[+FX]-X");
        pattern.addProduction('F', "FF");
        pattern.addMeaning('P', 5, 2, &colorFlower);
        pattern.addMeaning('F', 1, 3, &colorBranch);
        pattern.addMeaning('[', 2);
        pattern.addMeaning(']', 3);
        pattern.addMeaning('^', 4, 90);
        pattern.addMeaning('-', 4, 25.7);
        pattern.addMeaning('+', 4, -25.7);

        for (int i = 0; i < generations; i++) {
            pattern.createNewGeneration();
            char buf[1000000];
            pattern.getCurrent(buf);
        }
        pattern.interpret();
        canvas.setOrigin(-x, -y);
    }

};


using namespace std;

int main() {
    //Winter by KAT Systems :P
    Canvas canvas(1368, 700);
    Color brown(165, 42, 42);
    Color pink(255, 192, 170);
    Color green(98, 204, 28);
    Color yellow(255, 170, 34);
    Color darkbrown(107, 47, 47);
    Color darkgreen(23, 73, 17);
    Color gore(255, 255, 255);
    Color wintersnow(240, 247, 239);
    Color kaala(0, 0, 0);
    Color grey(130, 130, 130);

    srand(15);

    for (int i = 300; i >= 0; i--)
    {
        canvas.drawLine(0, i, 1368, i, wintersnow);
    }

    for (int i = 0; i < 13; i++) {
        int y = rand() % 300 + 400;
        int x = rand() % 1368;
        SnowFlake sn(gore, x, y, canvas);
    }

    int x = 500;
    int y = 0;
    for (int i = 0; i < 13; i++, x += 40, y += 20) {
//        TreeD t1(brown, gore, x, y, canvas);
        TreeD t2(darkbrown, darkgreen, x, y, canvas);
    }

    int x1 = 500, y1 = 0;
    int x2 = 1020, y2 = 300;
    for (int i = 0; i < 520; i++, x1++, x2++) {
        canvas.drawLine(x1, y1, x2, y2, grey);
//
    }

    x = 1020;
    y = 0;
    for (int i = 0; i < 13; i++, x += 50, y += 20) {
//        TreeD t1(brown, gore, x, y, canvas);
        TreeD t2(darkbrown, darkgreen, x, y, canvas);
    }






//    // star test
//    canvas.setOrigin(500, 100);
//    Interpreter pattern4("[^F]", &canvas);
////    pattern4.addProduction('X', "FXL");  // L is the production for flower
//    pattern4.addProduction('F', "F[-F][+F]");
//    pattern4.addProduction('L', "/B");
//    pattern4.addProduction('B', "[G/][(G/)][((G/))][)G/][))G/((]"); // G forward with black color
//    pattern4.addMeaning('X', 0);
//    pattern4.addMeaning('B', 0);
//    pattern4.addMeaning('F', 1, 15, &gore);
////    pattern4.addMeaning('G', 1, 12, &color3);
//    pattern4.addMeaning('[', 2);
//    pattern4.addMeaning(']', 3);
//    pattern4.addMeaning('^', 4, 90);
//    pattern4.addMeaning('-', 4, 10);
//    pattern4.addMeaning('+', 4, -10);
////    pattern4.addMeaning('T', 5, 6, &col_flower2);
////    pattern4.addMeaning('/', 5, 6, &color1);
//    pattern4.addMeaning('(', 4, 72);
//    pattern4.addMeaning(')', 4, -72);
//    for (int i = 0; i < 10; i++) {
//        pattern4.createNewGeneration();
//        char buf[1000000];
//        pattern4.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern4.interpret();















//    OctagonStar octstar(gore, 100,100,canvas,3);
//    SnowFlake(gore, 100, 100, canvas);
//    TreeA t1(brown, 100, 300, canvas);
//    TreeB t2(brown, 400, 300, canvas);
//    TreeC t3(brown, 700, 300, canvas);
    TreeD t4(brown, pink, 100, 0, canvas, 5);
//    TreeE t5(brown, pink, 400, 0, canvas);





// star test
//    canvas.setOrigin(500, 100);
//    Interpreter pattern4("^[F+F+F]", &canvas);
////    pattern4.addProduction('X', "FXL");  // L is the production for flower
//    pattern4.addProduction('F', "F-F+F-F");
//    pattern4.addProduction('L', "/B");
//    pattern4.addProduction('B', "[G/][(G/)][((G/))][)G/][))G/((]"); // G forward with black color
//    pattern4.addMeaning('X', 0);
//    pattern4.addMeaning('B', 0);
//    pattern4.addMeaning('F', 1, 4, &gore);
////    pattern4.addMeaning('G', 1, 12, &color3);
//    pattern4.addMeaning('[', 2);
//    pattern4.addMeaning(']', 3);
//    pattern4.addMeaning('^', 4, 90);
//    pattern4.addMeaning('-', 4, 60);
//    pattern4.addMeaning('+', 4, -120);
////    pattern4.addMeaning('T', 5, 6, &col_flower2);
////    pattern4.addMeaning('/', 5, 6, &color1);
//    pattern4.addMeaning('(', 4, 72);
//    pattern4.addMeaning(')', 4, -72);
//    for (int i = 0; i < 4; i++) {
//        pattern4.createNewGeneration();
//        char buf[1000000];
//        pattern4.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern4.interpret();



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
//
//    // Tree with flowers
//    canvas.setOrigin(200, 200);
//    Interpreter pattern3("^[X]", &canvas);
//    pattern3.addProduction('X', "F[+X/B]-X/B");
//    pattern3.addProduction('F', "FF");
////    pattern3.addProduction('L', "/B");
//    pattern3.addProduction('B', "[G/][(G/)][((G/))][)G/(][))G/((]"); // G forward with black color
//    pattern3.addMeaning('X', 0);
//    pattern3.addMeaning('B', 0);
//    pattern3.addMeaning('F', 1, 15, &color4);
//    pattern3.addMeaning('G', 1, 8, &color3);
//    pattern3.addMeaning('[', 2);
//    pattern3.addMeaning(']', 3);
//    pattern3.addMeaning('^', 4, 90);
//    pattern3.addMeaning('-', 4, 60);
//    pattern3.addMeaning('+', 4, -60);
//    pattern3.addMeaning('/', 5, 3, &col_flower);
//    pattern3.addMeaning('(', 4, 72);
//    pattern3.addMeaning(')', 4, -72);
//    for (int i = 0; i < 6; i++) {
//        pattern3.createNewGeneration();
//        char buf[1000000];
//        pattern3.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern3.interpret();
//
//    // Test flower
//    canvas.setOrigin(100, 400);
//    Interpreter pattern5("X", &canvas);
//    pattern5.addProduction('X', "FXL");  // L is for leaf
//    pattern5.addProduction('F', "FF");
////    [(G++G++G][(--G--G--G]
////    [--G++G++G][++G--G--G]
//    pattern5.addProduction('L', "[(G++G++G][(--G--G--G][--G++G++G][++G--G--G]"); // G is forward for leaf
//    pattern5.addMeaning('X', 0);
//    pattern5.addMeaning('F', 1, 15, &color4);
//    pattern5.addMeaning('G', 1, 15, &color1);
//    pattern5.addMeaning('[', 2);
//    pattern5.addMeaning(']', 3);
//    pattern5.addMeaning('^', 4, 90);
//    pattern5.addMeaning('-', 4, 60);
//    pattern5.addMeaning('+', 4, -60);
//    pattern5.addMeaning('(', 4, 30);
//    pattern5.addMeaning(')', 4, -30);
//    for (int i = 0; i < 2; i++) {
//        pattern5.createNewGeneration();
//        char buf[1000000];
//        pattern5.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern5.interpret();
//
//    // A tree with rhombus flowers
//    canvas.setOrigin(500, 0);
//    Interpreter pattern6("^[X]", &canvas);
//    pattern6.addProduction('X', "F[+XL]-XL");  // L is for leaf
//    pattern6.addProduction('F', "FF");
////    pattern6.addProduction('L', "[(G))G))G))G]"); // G is forward for leaf
//    pattern6.addProduction('L', "[(G(G(((G(G][)G)G)))G)G][((G(G(((G(G][))G)G)))G)G]");
//    pattern6.addMeaning('X', 0);
//    pattern6.addMeaning('F', 1, 15, &color4);
//    pattern6.addMeaning('G', 1, 10, &col_flower3);
//    pattern6.addMeaning('[', 2);
//    pattern6.addMeaning(']', 3);
//    pattern6.addMeaning('^', 4, 90);
//    pattern6.addMeaning('-', 4, 60);
//    pattern6.addMeaning('+', 4, -60);
//    pattern6.addMeaning('(', 4, 45);
//    pattern6.addMeaning(')', 4, -45);
//    for (int i = 0; i < 6; i++) {
//        pattern6.createNewGeneration();
//        char buf[1000000];
//        pattern6.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern6.interpret();
//
//    // A tree with triangular flowers
//    canvas.setOrigin(200, -800);
//    Interpreter pattern7("^[X]", &canvas);
//    pattern7.addProduction('X', "F[+XL]-XL");  // L is for leaf
//    pattern7.addProduction('F', "FF");
////    pattern6.addProduction('L', "[(G))G))G))G]"); // G is forward for leaf
//    pattern7.addProduction('L', "[(G++G++G][(--G--G--G][--G++G++G][++G--G--G]");
//    pattern7.addMeaning('X', 0);
//    pattern7.addMeaning('F', 1, 15, &color4);
//    pattern7.addMeaning('G', 1, 10, &color1);
//    pattern7.addMeaning('[', 2);
//    pattern7.addMeaning(']', 3);
//    pattern7.addMeaning('^', 4, 90);
//    pattern7.addMeaning('-', 4, 60);
//    pattern7.addMeaning('+', 4, -60);
//    pattern7.addMeaning('(', 4, 30);
//    pattern7.addMeaning(')', 4, -30);
//    for (int i = 0; i < 6; i++) {
//        pattern7.createNewGeneration();
//        char buf[1000000];
//        pattern7.getCurrent(buf);
//        cout << buf << endl;
//    }
//    pattern7.interpret();



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
#include<bits/stdc++.h>
#include "canvas.h"
#include "cfg.h"
using namespace std;
#ifndef INTERPRETER_H
#define INTERPRETER_H

class Interpreter
{
    private:
        CFG grammar;
        Canvas canvas;
        double leftangle;
        double rightangle;
        int length;
        map<char,int> constants;
    public:
        /*
         * Constructor which initializes the grammar and the canvas used to draw the image
         * @param axiom The string representing the first generation of the series
         * @param zerorulerhs The string representing the RHS of the rule of the form 0 -> rhs
         * @param onerulerhs The string representing the RHS of the rule of the form 1 -> rhs
         * @param width The width of the canvas in pixels
         * @param height The height of the canvas in pixels
         * @param leftangle The angle through which we must turn while branching left
         * @param rightangle The angle through which we must turn while branching right
         * @param length The length of the line segment to be drawn in the forward direction when the command to draw a line is given
         */
        Interpreter(string axiom, string zerorulerhs, string onerulerhs, int width, int height, double leftangle, double rightangle, int length) : grammar(axiom,zerorulerhs,onerulerhs), canvas(width,height)
        {
            this->leftangle = leftangle;
            this->rightangle = rightangle;
            this->length = length;
        }
        /**
         * Used to declare a character used in the grammar and define its meaning i.e. define the operation to be performed when the constant is encountered
         * @param character The character whose meaning is being defined
         * @param operation The operation to be performed when the character is encountered. Can take any value from 1 to 5. 1 stands for draw forward, 2 stands for pushing current coordinates and inclination to stack, 3 stands for popping a set of coordinates and inclinations, 4 stands for turning left and 5 stands for turning right.
         */
        void addMeaning(char character, int operation)
        {
            constants[character] = operation;
        }
        /**
         * Interprets the current string of the series and produces an interpretation i.e. image of it.
         */
        void interpret()
        {
            string current = grammar.getCurrent();
            long length = current.length();
            int current_x = canvas.origin.first;
            int current_y = canvas.origin.second;
            for (int i = 0; i < length; ++i)
            {
                if(constants[current[i]]==1) //draw a forward line
                {
                    drawLine();
                }
            }
        }
        /**
         * Displays the generated image. Wrapper for the function provided by the Canvas class.
         */
        void display()
        {
            canvas.display();
        }
};
#endif //INTERPRETER_H

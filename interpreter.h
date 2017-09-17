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
        int radius;
        map<char,pair<int,Color> > operations_map;
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
        Interpreter(string axiom, string zerorulerhs, string onerulerhs, int width, int height, double leftangle, double rightangle, int length, int radius) : grammar(axiom,zerorulerhs,onerulerhs), canvas(width,height)
        {
            this->leftangle = leftangle;
            this->rightangle = rightangle;
            this->length = length;
            this->radius = radius;
        }
        /**
         * Used to declare a character used in the grammar and define its meaning i.e. define the operation to be performed when the constant is encountered
         * @param character The character whose meaning is being defined
         * @param operation The operation to be performed when the character is encountered. Can take any value from 1 to 5. 1 stands for draw forward, 2 stands for pushing current coordinates and inclination to stack, 3 stands for popping a set of coordinates and inclinations, 4 stands for turning left, 5 stands for turning right and 6 stands for drawing a circle.
         */
        void addMeaning(char character, int operation, Color* color = NULL)
        {
            operations_map[character].first = operation;
            if(color!=NULL)
                operations_map[character].second = *color;
        }
        /**
         * Function to draw a line of fixed length starting at the given coordinates and inclined at the given inclination.
         * @param x Denotes the x coordinate of the starting point
         * @param y Denotes the y coordinate of the starting point
         * @param inclination Denotes the inclination of the line
         * @param color Denotes the color of the line
         */
        void drawLine(int x, int y, double inclination, Color color)
        {

        }
        /**
         * Interprets the current string of the series and produces an interpretation i.e. image of it.
         */
        void interpret()
        {
            string current = grammar.getCurrent();
            long length = current.length();
            pair<int,int> current_coordinates = canvas.getOrigin();
            int current_x = current_coordinates.first;
            int current_y = current_coordinates.second;
            double inclination = 0;
            stack<pair<int,int> > stack_coordinates;
            stack<double> stack_inclinations;
            for (int i = 0; i < length; ++i)
            {
                /*
                 * Draw a forward line at the current coordinates
                 */
                if(operations_map[current[i]].first==1)
                    drawLine(current_x,current_y,inclination,operations_map[current[i]].second);
                /*
                 * Push current coordinates and inclination to stack
                 */
                else if(operations_map[current[i]].first==2)
                {
                    stack_coordinates.push(pair<int,int> (current_x,current_y));
                    stack_inclinations.push(inclination);
                }
                /*
                 * Restore coordinates and inclination by popping from stack
                 */
                else if(operations_map[current[i]].first==3)
                {
                    current_x = stack_coordinates.top().first;
                    current_y = stack_coordinates.top().second;
                    inclination = stack_inclinations.top();
                    stack_coordinates.pop();
                    stack_inclinations.pop();
                }
                /*
                 * Rotate left by specified number of degrees (leftangle)
                 */
                else if(operations_map[current[i]].first==4)
                    inclination = inclination + leftangle;
                /*
                 * Rotate right by specified number of degrees (rightangle)
                 */
                else if(operations_map[current[i]].first==5)
                    inclination = inclination - rightangle;
                /*
                 * Draw a circle at the current coordinates
                 */
                else if(operations_map[current[i]].first==6)
                    canvas.drawCircle(current_x,current_y,radius,operations_map[current[i]].second);
                else
                    cout<<"Error 97: Unspecified constant found";
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

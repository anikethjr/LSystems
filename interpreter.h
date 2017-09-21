#include<bits/stdc++.h>
#include <cmath>
#include "canvas.h"
#include "cfg.h"

using namespace std;
#ifndef INTERPRETER_H
#define INTERPRETER_H
#define PI 3.14159265

class Interpreter {
private:
    CFG grammar;
    Canvas *canvas;
    map<char, vector<pair<int, pair<double, Color> > > > operations_map;
public:
    /**
     *
     * @param axiom Denotes the first generation
     * @param canvas Denotes a pointer of class Canvas
     */
    Interpreter(char axiom[], Canvas *canvas) : grammar(axiom) {
        this->canvas = canvas;
    }

    /**
     * Used to declare a character used in the grammar and define its meaning i.e. define the operation to be performed when the constant is encountered
     * @param character The character whose meaning is being defined
     * @param operation The operation to be performed when the character is encountered. Can take any value from 0 to 5. 0 stands for do nothing, 1 stands for draw forward, 2 stands for pushing current coordinates and inclination to stack, 3 stands for popping a set of coordinates and inclinations, 4 stands for turning left, 5 stands for turning right and 6 stands for drawing a circle.
     * @param attribute The value corresponding to a particular operation. Eg. Forward length of the pen, angle of rotation, etc.
     */
    void addMeaning(char character, int operation, double attribute = 0, Color *color = NULL) {
        pair<int, pair<double, Color> > temp;
        temp.first = operation;
        temp.second.first = attribute;
        if (color != NULL)
            temp.second.second = *color;
        operations_map[character].push_back(temp);
    }

    /**
     * Function to draw a line of fixed length starting at the given coordinates and inclined at the given inclination. Updates the current coordinates with the end points computed.
     * @param x Denotes the x coordinate of the starting point
     * @param y Denotes the y coordinate of the starting point
     * @param inclination Denotes the inclination of the line
     * @param length Denotes the length of the line segment to be drawn on the canvas
     * @param color Denotes the color of the line
     */
    void drawLine(int &x, int &y, double inclination, int length, Color color) {
        /*
         * Computing the ending coordinates of the line segment
         */
        double rad = inclination * PI / 180.0;
        int end_x = x + round((double) length * cos(rad));
        int end_y = y + round((double) length * sin(rad));
        (*canvas).drawLine(x, y, end_x, end_y, color);
        /*
         * Updating the current coordinates with the end points computed
         */
        x = end_x;
        y = end_y;
    }

    /**
     * Interprets the current string of the series and produces an interpretation i.e. image of it.
     */
    void interpret() {
        char current[1000000];
        grammar.getCurrent(current);
        long length = strlen(current);
        int current_x = 0;
        int current_y = 0;
        double inclination = 0;
        stack<pair<int, int> > stack_coordinates;
        stack<double> stack_inclinations;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < operations_map[current[i]].size(); ++j) {
                /*
                 * Do nothing
                 */
                if (operations_map[current[i]][j].first == 0)
                    continue;
                    /*
                     * Draw a forward line at the current coordinates
                     */
                else if (operations_map[current[i]][j].first == 1)
                    drawLine(current_x, current_y, inclination, round(operations_map[current[i]][j].second.first),
                             operations_map[current[i]][j].second.second);
                    /*
                     * Push current coordinates and inclination to stack
                     */
                else if (operations_map[current[i]][j].first == 2) {
                    stack_coordinates.push(pair<int, int>(current_x, current_y));
                    stack_inclinations.push(inclination);
                }
                    /*
                     * Restore coordinates and inclination by popping from stack
                     */
                else if (operations_map[current[i]][j].first == 3) {
                    current_x = stack_coordinates.top().first;
                    current_y = stack_coordinates.top().second;
                    inclination = stack_inclinations.top();
                    stack_coordinates.pop();
                    stack_inclinations.pop();
                }
                    /*
                     * Rotate left (or right) by specified number of degrees
                     */
                else if (operations_map[current[i]][j].first == 4)
                    inclination = inclination + operations_map[current[i]][j].second.first;
                    /*
                     * Draw a circle at the current coordinates
                     */
                else if (operations_map[current[i]][j].first == 5)
                    (*canvas).drawCircle(current_x, current_y, round(operations_map[current[i]][j].second.first),
                                         operations_map[current[i]][j].second.second);
                    /**
                     *  Pen Up and take the cursor to a specified coordinate
                     */
//                else if (operations_map[current[i]][j].first == 6)

                else
                    cout << "Error 97: Unspecified constant found " << current[i] << " "
                         << operations_map[current[i]][j].first << endl;
            }
        }
    }

    /*
     * Function to add a production to the grammar. Wrapper for the function provided by the CFG class
     * @param symbol Represents the LHS symbol of the production
     * @param rhs Represents the RHS of the production
     */
    void addProduction(char symbol, char rhs[]) {
        grammar.addProduction(symbol, rhs);
    }

    /*
     * Creates next generation string. Wrapper for the function provided by the CFG class.
     */
    void createNewGeneration() {
        grammar.createNewGeneration();
    }
    /**
     * Function to return the string of the most recent(current) generation
     * @param buf Denotes the buffer to be populated with the current generation string
     */
    void getCurrent(char buf[]) {
        grammar.getCurrent(buf);
    }
};

#endif //INTERPRETER_H
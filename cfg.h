#include<bits/stdc++.h>
using namespace std;
#ifndef CFG_H
#define CFG_H

/**
 * Class representing the Context Free Grammar being used to generate the image.
 */
class CFG
{
    private:
        map<char,char[1000000]> productions;
        char current[1000000];
    public:
        /**
         * Constructor which initializes the string with the axiom
         * @param axiom The string representing the first generation of the series
         */
        CFG(char axiom[])
        {
            strcpy(current,axiom);
        }
        /*
         * Function to add a production to the grammar
         * @param symbol Represents the LHS symbol of the production
         * @param rhs Represents the RHS of the production
         */
        void addProduction(char symbol,char rhs[])
        {
            strcpy(productions[symbol],rhs);
        }
        /**
         * Generates the offspring of the current string by simultaneously replacing all the symbols by the RHS's of their respective rules.
         */
        void createNewGeneration()
        {
            char new_string[1000000];
            int pos = 0;
            for (long i = 0;current[i]!='\0'; ++i)
            {
                if(productions.find(current[i])!=productions.end())
                {
                    for(long j=0;j<strlen(productions[current[i]]);++j)
                    {
                        new_string[pos++] = productions[current[i]][j];
                    }
                }
                else
                    new_string[pos++] = current[i];
            }
            new_string[pos] = '\0';
            strcpy(current,new_string);
        }
        /**
         * Returns the current generation string
         */
        void getCurrent(char buffer[])
        {
            strcpy(buffer,current);
        }
};
#endif //CFG_H
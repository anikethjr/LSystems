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
        string zerorule;
        string onerule;
        string current;
    public:
        /**
         * Constructor which initializes various variables with their initial values
         * @param axiom The string representing the first generation of the series
         * @param zerorulerhs The string representing the RHS of the rule of the form 0 -> rhs
         * @param onerulerhs The string representing the RHS of the rule of the form 1 -> rhs
         */
        CFG(string axiom, string zerorulerhs, string onerulerhs)
        {
            current = axiom;
            zerorule = zerorulerhs;
            onerule = onerulerhs;
        }
        /**
         * Generates the offspring of the current string by simultaneously replacing all the 0s and 1s by the RHS's of their respective rules.
         */
        void createNewGeneration()
        {
            for (long i = 0;current[i]!='\0'; ++i)
            {
                //replace a 0 with its RHS
                if(current[i]=='0')
                {
                    current.replace(i,1,zerorule);
                    i = i+zerorule.length()-1;
                }
                else if(current[i]=='1')
                {
                    current.replace(i,1,onerule);
                    i = i+onerule.length()-1;
                }
            }
        }
        /**
         * Returns the current generation string
         */
        string getCurrent()
        {
            return current;
        }
};
#endif //CFG_H
//
// Created by Leon on 8/11/2019.
//

#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"

class Comedy : public Movie
{
private:

public:
    Comedy(){updateMovieType('F');};
    Comedy(string dataToParse)
    {
        updateMovieType('F');

        string temp = "";
        int curr = 0;
        int count = 0;

        while(curr <= dataToParse.length())
        {
            if(dataToParse.substr(curr, 2) != ", " && curr != dataToParse.length()) temp += dataToParse.substr(curr, 1);
            else
            {
                if(count == 0)
                {
                    int newStock = stoi(temp);
                    updateStock(newStock);
                }
                else if(count == 1)setDirectorName(temp);
                else if(count == 2)setMovieTitle(temp);
                else if(count == 3)
                {
                    int theYear = stoi(temp);
                    setYearMade(theYear);
                    return;
                }
                count++;
                curr++;
                temp = "";
            }
            curr++;
        }
    }
    ~Comedy(){};

    string printMovieDetails()
    {
        string movieType(1, getMovieType());
        return movieType + ", " + to_string(getStock()) + ", " + getFullDirectorName() + ", " + getMovieTitle() + ", " + to_string(getYearMade()) + "\n";
    }


};


#endif

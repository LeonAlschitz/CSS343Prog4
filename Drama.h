//
// Created by Leon on 8/15/2019.
//

#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"

class Drama : public Movie{


private:

public:
    Drama(){updateMovieType('D');};
    Drama(string dataToParse)
    {
        updateMovieType('D');

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
    ~Drama(){};


    string printMovieDetails()
    {
        string movieType(1, getMovieType());
        return movieType + ", " + to_string(getStock()) + ", " + getFullDirectorName() + ", " + getMovieTitle() + ", " + to_string(getYearMade()) + "\n";
    }




};


#endif
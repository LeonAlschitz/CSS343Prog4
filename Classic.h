//
// Created by Leon on 8/15/2019.
//

#ifndef CLASSIC_H
#define CLASSIC_H

#include "Movie.h"

class Classic : public Movie{


private:
    string majorActorAndDate = "";

public:
    Classic(){updateMovieType('C');};
    Classic(string dataToParse)
    {
        updateMovieType('C');

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
                    majorActorAndDate = temp;
                    return;
                }
                count++;
                curr++;
                temp = "";
            }
            curr++;
        }
    }
    ~Classic(){};

    string getMajorActorAndDate()const{ return majorActorAndDate;}

    string printMovieDetails()
    {
        string movieType(1, getMovieType());
        return movieType + ", " + to_string(getStock()) + ", " + getFullDirectorName() + ", " + getMovieTitle() + ", " + majorActorAndDate + "\n";
    }

    virtual bool compareSize(const Classic *otherClassic) const
    {
        if(getFullDirectorName() < otherClassic->getFullDirectorName())
        {
            if(getMovieTitle() < otherClassic->getMovieTitle())
            {
                if(getMajorActorAndDate() < otherClassic->getMajorActorAndDate())return true;
            }
        }
        return false;
    }

    bool checkEquality(const Classic *otherClassic) const
    {
        if(getFullDirectorName() == otherClassic->getFullDirectorName())
        {
            if(getMovieTitle() == otherClassic->getMovieTitle())
            {
                if(getMajorActorAndDate() == otherClassic->getMajorActorAndDate())return true;
            }
        }
        return false;
    }

    virtual bool operator<(const Movie &aNode) const
    {
        const Classic *derived = dynamic_cast<const Classic*>(&aNode);
        return compareSize(derived);
    }

    virtual bool operator==(const Movie &aNode) const
    {
        const Classic *derived = dynamic_cast<const Classic*>(&aNode);
        return checkEquality(derived);
    }
};


#endif
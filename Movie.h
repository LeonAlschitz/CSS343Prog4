//
// Created by Leon on 8/11/2019.
//

#ifndef MOVIE_H
#define MOVIE_H


#include <string>
using namespace std;

class Movie {

public:
    Movie();
    Movie(string dataToParse, char theType);
    virtual ~Movie();

    friend ostream & operator<<(ostream &output, const Movie &theComedy);


    virtual char getMovieType()const{return movieType;};
    virtual int getStock()const{return stock;}
    virtual string getFullDirectorName()const{return  director;}
    virtual string getMovieTitle()const{return movieTitle;}
    virtual int getYearMade()const{return yearMade;}
    virtual string printMovieDetails();


    virtual void updateMovieType(char newMovieType){ movieType = newMovieType;}
    virtual void updateStock(int newStock){ stock = newStock;}
    virtual void setDirectorName(string name){ director = name;}
    virtual void setMovieTitle(string newMovieTitle){ movieTitle = newMovieTitle;}
    virtual void setYearMade(int aYear){yearMade = aYear;}


private:

    char movieType = 'F';

    int stock = 0;
    int yearMade = 0;

    string director = "";
    string movieTitle = "";



};


#endif
#ifndef NODEDATA_H
#define NODEDATA_H

#include <string>
#include <iostream>
#include <fstream>

#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

using namespace std;

class NodeData {

    friend ostream & operator<<(ostream &output, const NodeData &theNode)
	{
		output << theNode.aMovie->printMovieDetails();
		return output;
	}

    public:

	//Description: This creates a new NodeData object
	//Preconditions: This object is un-initialized
	//Postconditions: This Object is initialized
	NodeData(){}

	//Description: This creates a new NodeData object using a string
	//Preconditions: This object is un-initialized
	//Postconditions: This Object is initialized
	NodeData(string dataToParse, char typeFound)
	{
		if(typeFound == 'F')aMovie = new Comedy(dataToParse);
		else if(typeFound == 'D')aMovie = new Drama(dataToParse);
		else if(typeFound == 'C') aMovie = new Classic(dataToParse);
	}

	//Description: This destroys this NodeData object
	//Preconditions: This object is initialized
	//Postconditions: This Object is destroyed
	~NodeData()
	{
        delete(left);
        left = NULL;
        delete(right);
        right = NULL;
        delete(aMovie);
        aMovie = NULL;
	}

	//Description: This creates a new Movie Object using the string, and sets it to the movieData
	//Preconditions: This Object is initialized
	//Postconditions: movieData will contain a pointer to a MovieObject
	bool setData(string );

	NodeData* getLeft(){return left;}
	NodeData* getRight(){return right;}

	void setLeft(NodeData *newNode){left = newNode;}
	void setRight(NodeData *newNode){right = newNode;}

	Movie* getMovie(){return aMovie;}

	int getStock(){return aMovie->getStock();}

	bool operator==(const NodeData &otherNode) const
	{
		if(*aMovie == *(otherNode.aMovie))return true;
		return false;
	}
	bool operator<(const NodeData &otherNode) const
	{
		if(*aMovie < *(otherNode.aMovie))return true;
		return false;
	}

private:
    Movie *aMovie = NULL;
	NodeData *left = NULL;
	NodeData *right = NULL;
	//vector<char> validGenres = {'F', 'C', 'D'};
};

#endif
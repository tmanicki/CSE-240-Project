#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Container.cpp"
//#include "ReadGame.cpp"
//#include "ReadScore.cpp"

using namespace std;

void ReadGameInfo();
void ReadGame();
void ReadScore();

Container *HEAD = new Container();
int numOfGames = 0;

int main(){

	HEAD->game.setName("Head of container linked list");
    //Game g1;
    // calls to Team Members 2 and 3 functions
    ReadGame();
    ReadScore();

    return 0;
}


void ReadGame(){
	char choice;
	do{
		cout << "Select parsing method" << endl;
		//cout << "(1) For using getline with delimeters" << endl;
		cout << "(2) For using line parser" << endl;
		cout << "(0) To quit" << endl;

		choice = getc(stdin);
		cout << "\n";
		if (choice == '2')
			ReadGameInfo();
		else
		{
			cout << "Incorrect input\n" << endl;
			cin.ignore();
		}

	} while (choice != '0');
}
/*
	By: Timothy Manicki
	Description:
	This method gets an entire row from the file, then parses it for the desired information. If the file fails to read,
	an ouput will state so. Otherwise, enters function. The while loop skips the first input in order to skip the titles
	of each input.
*/
void ReadGameInfo()
{
	Container *temp;
	temp = new Container();

	ifstream game("game.csv"); // Declare object to read file.
	string input, name, genre, console, tester1 = "Name", tester2 = "name"; // following strings are declared to store the parsed data.
	string delimeter = ","; // Specify the delimeter for parsing
	int checker=0; //Checks to see if reading info or skipping header

	
	if (game.is_open()) // If the file is readable
	{	
		while (getline(game, input, '\n')) // Keep reading until the end of line.
		{
			
			name = input.substr(0, input.find(delimeter)); // Read the input string until the delimeter is found.
			input.erase(0, input.find(delimeter) + delimeter.length()); // Erase the parsed input so that it is not read again

			genre = input.substr(0, input.find(delimeter));
			input.erase(0, input.find(delimeter) + delimeter.length());

			console = input.substr(0, input.find(delimeter));
			input.erase(0, input.find(delimeter) + delimeter.length());

			temp->game.setName(name);
			temp->game.setGenre(genre);
			temp->game.setConsole(console);

			if (HEAD->game.getName() == "Head of container linked list"){
				HEAD = temp;
				HEAD->setNext(0);
			}

			else{
				HEAD->setNext((Container *)temp);
				temp->setNext(0);
			}


			
			if (checker == 1)//skips initial input (i.e. game, genre, and console input from cvs file)
			{
				cout << "Name: " << name << endl;
				cout << "Genre: " << genre << endl;
				cout << "Console: " << console << "\n" << endl;
			}
			else // if haven't skipped header, incrememnt checker so following info can be read
			{
				checker++;
			}
		}

		game.close();// closes file
	}
	else
		cout << "Unable to open file" << endl;	// Consumes extra newline character at end

	cin.ignore();
};

void ReadScore() {
    ifstream score ("score.csv");
    string name;
    string temp; // temporary string to read in score values
    int graphics;
    int gameplay;
    int story;
    getline (score, name, ','); // these 4 lines skip past the first line in score.csv
    getline (score, name, ',');
    getline (score, name, ',');
    getline (score, name);
    while (score.good()) { // continues to read score.csv until there are no more lines
        getline (score, name, ','); // reads in and prints out the game name
        cout << name << ", ";
        
        getline (score, temp, ','); // reads in graphics score as a string
        graphics = atoi(temp.c_str()); // converts the string to an int
        cout << graphics << ", "; // prints the graphics score
        
        getline (score, temp, ','); // reads in gameplay score, converts to int, prints
        gameplay = atoi(temp.c_str());
        cout << gameplay << ", ";
        
        getline (score, temp); // reads in storyline score, converts to int, prints
        story = atoi(temp.c_str());
        cout << story << endl;
    }
}

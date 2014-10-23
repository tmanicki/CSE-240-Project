#include "Game.cpp"
class Container{
private:
    Container *next;
public:
	Game game;
	Container(){
		next = 0;
	}
};

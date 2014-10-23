#include "Game.cpp"
class Container{
private:
    Container *next;
public:
	Game game;
	Container(){
		next = 0;
	}

	void setNext(Container *ptr);
};

void Container::setNext(Container *ptr){
	next = ptr;
}

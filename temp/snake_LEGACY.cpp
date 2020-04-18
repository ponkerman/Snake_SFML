#include "snake.h"


Snake::Snake(int x, int y){
	snake_units = new vector<unit>;
	
	if (WIDTH - x < START_LEN || x < START_LEN ||
		HEIGHT - y < START_LEN || y < START_LEN){
		throw "error: wrong coordinates!";
	}

	snake_units->push_back(unit(x, y, '@'));
	
	/*
	for(int i = 1; i < START_LEN; i++){
		try{
			add_unit();
		} catch (const char * msg) {
			throw msg;
		}
	}
	*/
}

Snake::~Snake(){
	delete[] snake_units;
}

void Snake::add_unit(bool (*check_coord)(int, int)){
int X = snake_units->back().x; 
int Y = snake_units->back().y;

snake_units->push_back(unit(-1, -1, 'o'));

/*
x-1 |	y
x   |	y-1
x   |	y+1
x+1 |	y
*/

--X;    Y;
if(check_coord(X, Y)) {snake_units->back().x = X; snake_units->back().y = Y; return;}
++X;    --Y;
if(check_coord(X, Y)) {snake_units->back().x = X; snake_units->back().y = Y; return;}
X;      Y+=2;
if(check_coord(X, Y)) {snake_units->back().x = X; snake_units->back().y = Y; return;}
++X;    --Y;
if(check_coord(X, Y)) {snake_units->back().x = X; snake_units->back().y = Y; return;}

throw "error: unable to add new part!\n";
}

int Snake::move(int dir){
	
	/*
	for_each(std::next(snake_unit->begin()), snake_unit->end(), [](unit it){
		cout << "x: " << it.x << "\ty: " << it.y;
		//it.x = std::prev(&it)->x;
		//it.y = std::prev(&it)->y;
		unit* tmp = &it;
		tmp += 1;
		cout << "\nprev: x: " << tmp->x << "\ty: " << tmp->y << '\n';
		cout << "after: x: " << it.x << "\ty: " << it.y << "\n////////////////////////\n";
	}); 
	static unit tmp = *snake_unit->begin();
	for(vector<unit>::iterator it = snake_unit->begin(); it != std::prev(snake_unit->end()); it++){
		cout << "x: " << it->x << "\ty: " << it->y;
		std::next(it)->x = tmp.x;
		std::next(it)->y = tmp.y;
		tmp = *next(it);
		//cout << "\nprev: x: " << std::prev(it)->x << "\ty: " << std::prev(it)->y << '\n';
		cout << "\nafter: x: " << it->x << "\ty: " << it->y << "\n////////////////////////\n";
	}
	*/
	snake_units->push_back(*snake_units->begin());
	std::rotate(snake_units->rbegin(), snake_units->rbegin() + 1, snake_units->rend());
	snake_units->pop_back();

	switch(dir){
		case UP:
			//head.y += 1;
			//snake_unit->at(0).y += 1;
			snake_units->at(0).x -= 1;
			break;
		case DOWN:
			//head.y -= 1;
			snake_units->at(0).x += 1;
			break;
		case LEFT:
			//head.x -= 1;
			snake_units->at(0).y -= 1;
			break;
		case RIGHT:
			//head.x += 1;
			snake_units->at(0).y += 1;
			break;
		default:
			return -1;
			break;
	}
	return 1;
}



int Snake::getLen(){
	return snake_units->capacity();
}

vector<unit> Snake::getCoords(){
	return *snake_units;
}


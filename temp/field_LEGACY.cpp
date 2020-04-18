#include "field.h"

bool callback(int xx, int yy){
        Field tmp;
        return tmp.checkCoord(xx, yy);
}

Field::Field() : Snake::Snake(HEIGHT/2, WIDTH/2), Bonus::Bonus(3,3) 
{
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            screen[i][j] = FIELD_CHAR;
    for(int i = 0; i < WIDTH; i++)
        screen[0][i] = '#';
    for(int i = 0; i < WIDTH; i++)
        screen[HEIGHT-1][i] = '#';
    for(int i = 0; i < HEIGHT; i++)
        screen[i][0] = '#';
    for(int i = 0; i < HEIGHT; i++)
        screen[i][WIDTH-1] = '#';
    /*
    try{
        Snake::Snake(HEIGHT/2, WIDTH/2);
    } catch(const char * str) {
        cerr << str << endl;
    }
    */
    

    for(int i = 0; i < START_LEN; i++){
        try{
            Snake::add_unit(&callback);
        } catch(const char * str) {
            cerr << str << endl;
        }
    }
    
    vector<unit> snake_unit = Snake::getCoords();
    for_each(snake_unit.begin(), snake_unit.end(), [&screen = screen](unit it){screen[it.x][it.y] = it.unit_char;});
}

void Field::output(){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            cout.width(3);
            std::cout << screen[i][j];
        }
        cout << endl;
    }
}

void Field::update(int direction){
    for(int i = 1; i < HEIGHT - 1; i++)
        for(int j = 1; j < WIDTH - 1; j++)
            screen[i][j] = FIELD_CHAR;//fill_char
    try{
        Snake::move(direction);
    } catch(const char * str) {
        cerr << str << endl;
    }
    vector<unit> snakeunit = Snake::getCoords();
    for_each(snakeunit.begin(), snakeunit.end(), [&screen = screen](unit it){screen[it.x][it.y] = it.unit_char;});
}

bool Field::checkCoord(int x, int y){
    if (x == 0 || y == 0 || x == WIDTH || y == HEIGHT) return false;
	bool flag = true;
    vector<unit> tmp = Snake::getCoords();
    for_each(tmp.begin(), tmp.end(), [x, y, &flag](unit it){ if(it.x == x && it.y == y) flag = false;});
    //if(Bonus::getCoord().x == x && Bonus::getCoord().y == y) flag = false;
	if(!flag) return false;
	return true;
}


Field::~Field()
{
}
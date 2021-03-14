#pragma once

class Move {
private:
	int* data;
public:
	void set_data_value(int d) { *data = d; };
	int get_data_value() { return *data; }
	Move(int d);				//Constructor
	Move(const Move& source);	//Copy Constructor
	Move(Move&& source);		//Move Constructor
	~Move();					//Destructor

};

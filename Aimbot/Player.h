#pragma once
#include <vector>
#include <Windows.h>

class Player {
	public: 
		Player();
		Player(HANDLE proc, int base);
		std::vector<float> getCoord();								//Obtain player coordinates
		int getHealth();
		void look(float y, float z);								//Set player's look position (non-vector) 
	private:
		HANDLE proc;
		int base;
		int health;
		std::vector<float> coord;
		enum Offset {PX=0x34, PY=0x38, PZ=0x3C, LY=0x40, LZ=0x44, HP=0xF8};  //Hardcoded offsets from Assault Cube Memory Map 

};
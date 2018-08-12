#include "stdafx.h"
#include "Player.h"

Player::Player() {

}

Player::Player(HANDLE proc, int base) {
	this->proc = proc;
	this->base = base;
	coord.resize(3);
}

void Player::look(float y, float z) {
	WriteProcessMemory(proc, (void *)(base+LY), &y, sizeof(float), NULL);
	WriteProcessMemory(proc, (void *)(base+LZ), &z, sizeof(float), NULL);
}

std::vector<float> Player::getCoord() {
	ReadProcessMemory(proc, (void *)(base+PX), &coord[0], sizeof(float), NULL);
	ReadProcessMemory(proc, (void *)(base+PY), &coord[1], sizeof(float), NULL);
	ReadProcessMemory(proc, (void *)(base+PZ), &coord[2], sizeof(float), NULL);
	return coord;
}

int Player::getHealth() {
	ReadProcessMemory(proc, (void *)(base + HP), &health, sizeof(int), NULL);
	return health;
}

int Player::getTeam() {
	ReadProcessMemory(proc, (void *)(base + T2), &team, sizeof(int), NULL);
	return team;
}
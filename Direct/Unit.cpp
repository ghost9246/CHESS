#include "Unit.h"

CUnit::CUnit(void)
{
	this->type = 0;
	this->hp = 0;
	this->atk = 0;
	this->owner = 0;
}

CUnit::~CUnit(void)
{}

void CUnit::SetDefault(int type, int hp, int atk, int owner)
{
	this->type = type;
	this->hp = hp;
	this->atk = atk;
	this->owner = owner;
}

int CUnit::GetType()
{
	return type;
}

int CUnit::GetHp()
{
	return hp;
}

int CUnit::GetAtk()
{
	return atk;
}

int CUnit::GetOwner()
{
	return owner;
}

void CUnit::SetType(int type)
{
	this->type = type;
}

void CUnit::SetHp(int hp)
{
	this->hp = hp;
}

void CUnit::SetAtk(int atk)
{
	this->atk = atk;
}

void CUnit::SetOwner(int owner)
{
	this->owner = owner;
}
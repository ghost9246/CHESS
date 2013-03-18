#pragma once
class CUnit
{
public:
	CUnit();
	~CUnit(void);
	void SetDefault(int type, int hp, int atk, int owner);
	int GetType();
	int GetHp();
	int GetAtk();
	int GetOwner();
	void SetType(int type);
	void SetHp(int hp);
	void SetAtk(int atk);
	void SetOwner(int owner);

private:
	int type;		// 타입 (1:폰, 2:룩, 3:나이트, 4:비숍, 5:퀸, 6:킹)
	int hp;		// 체력 (클래식 모드는 전부 1)
	int atk;		// 공격력 (클래식 모드는 전부 1)
	int owner;	// 이 유닛의 소유주
};
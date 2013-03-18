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
	int type;		// Ÿ�� (1:��, 2:��, 3:����Ʈ, 4:���, 5:��, 6:ŷ)
	int hp;		// ü�� (Ŭ���� ���� ���� 1)
	int atk;		// ���ݷ� (Ŭ���� ���� ���� 1)
	int owner;	// �� ������ ������
};
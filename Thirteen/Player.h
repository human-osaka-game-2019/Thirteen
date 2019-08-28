#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
public:
	float x, y;
	float m_speed;
	float m_moving_distance;
	int row, col;
	int m_frame_count;
	int m_key_check;
	bool key_push_flag;
	void m_PlayerMove(Player* player, int MapChipList[][28]);
};

class Bullet
{
public:
	float x, y;
	float m_speed;
	int m_frame_count;
	int m_key_check;
	bool key_push_flag;
	void m_FireBullet(Bullet* bullet);
};

#endif

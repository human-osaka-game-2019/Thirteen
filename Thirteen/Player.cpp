#include "Player.h"

// プレイヤーの移動
void Player::m_PlayerMove(Player* player, int MapChipList[][28])
{
	player->m_frame_count++;

	if (player->m_frame_count >= 10)
	{
		switch (player->m_key_check)
		{
		case 1: // 下移動
			if (player->row + 1 <= 19 || MapChipList[row + 1][col] == 3)
			{
				player->y += player->m_speed;
				player->m_moving_distance += player->m_speed;
			}
			break;
		case 2: // 上移動
			if (player->row - 1 >= 0 || MapChipList[row - 1][col] == 3)
			{
				player->y -= player->m_speed;
				player->m_moving_distance += player->m_speed;
			}
			break;
		case 3: // 左移動
			if (player->col - 1 >= 0 || MapChipList[row][col - 1] != 3)
			{
				player->x -= player->m_speed;
				player->m_moving_distance += player->m_speed;
			}
			break;
		case 4: // 右移動
			if (player->col + 1 <= 27 || MapChipList[row][col + 1] != 3)
			{
				player->x += player->m_speed;
				player->m_moving_distance += player->m_speed;
			}
			break;
		}

		player->m_frame_count = 0;

		if (player->m_moving_distance >= 40)
		{
			// マップチップの二次元配列の更新
			switch (player->m_key_check)
			{
			case 1: // 下移動
				player->row++;
				break;
			case 2: // 上移動
				player->row--;
				break;
			case 3: // 左移動
				player->col--;
				break;
			case 4: // 右移動
				player->col++;
				break;
			}

			player->m_moving_distance = 0.0f;
			player->key_push_flag = false;
			player->m_key_check = 0;
		}
	}
}

// 弾の発射
void Bullet::m_FireBullet(Bullet* bullet)
{
	bullet->m_frame_count++;

	if (bullet->m_frame_count >= 10)
	{
		switch (bullet->m_key_check)
		{
		case 1: // 下
			bullet->y += bullet->m_speed;
			break;
		case 2: // 上
			bullet->y -= bullet->m_speed;
			break;
		case 3: // 左
			bullet->x -= bullet->m_speed;
			break;
		case 4: // 右
			bullet->x += bullet->m_speed;
			break;
		}

		bullet->m_frame_count = 0;

		if (bullet->y > 800.0f || bullet->y < 0.0f || bullet->x < 0.0f || bullet->x >1120)
		{
			bullet->m_key_check = 0;
			bullet->key_push_flag = false;
		}
	}
}

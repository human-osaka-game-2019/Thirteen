#include "Player.h"

// �v���C���[�̈ړ�
void Player::m_PlayerMove(Player* player, int MapChipList[][28])
{
	player->m_frame_count++;

	if (player->m_frame_count >= 10)
	{
		switch (player->m_key_check)
		{
		case 1: // ���ړ�
			if (player->row + 1 <= 19 || MapChipList[row + 1][col] == 3)
			{
				player->y += player->m_speed;
				player->m_moving_distance += player->m_speed;
			}
			break;
		case 2: // ��ړ�
			if (player->row - 1 >= 0 || MapChipList[row - 1][col] == 3)
			{
				player->y -= player->m_speed;
				player->m_moving_distance += player->m_speed;
			}
			break;
		case 3: // ���ړ�
			if (player->col - 1 >= 0 || MapChipList[row][col - 1] != 3)
			{
				player->x -= player->m_speed;
				player->m_moving_distance += player->m_speed;
			}
			break;
		case 4: // �E�ړ�
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
			// �}�b�v�`�b�v�̓񎟌��z��̍X�V
			switch (player->m_key_check)
			{
			case 1: // ���ړ�
				player->row++;
				break;
			case 2: // ��ړ�
				player->row--;
				break;
			case 3: // ���ړ�
				player->col--;
				break;
			case 4: // �E�ړ�
				player->col++;
				break;
			}

			player->m_moving_distance = 0.0f;
			player->key_push_flag = false;
			player->m_key_check = 0;
		}
	}
}

// �e�̔���
void Bullet::m_FireBullet(Bullet* bullet)
{
	bullet->m_frame_count++;

	if (bullet->m_frame_count >= 10)
	{
		switch (bullet->m_key_check)
		{
		case 1: // ��
			bullet->y += bullet->m_speed;
			break;
		case 2: // ��
			bullet->y -= bullet->m_speed;
			break;
		case 3: // ��
			bullet->x -= bullet->m_speed;
			break;
		case 4: // �E
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

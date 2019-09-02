#include "player.h"

// �v���C���[�̈ړ�
void Player::m_PlayerMove(Player* p_player, int mapChipList[][28])
{
	p_player->m_frame_count++;

	if (p_player->m_frame_count >= 10)
	{
		switch (p_player->m_key_check)
		{
		case 1: // ���ړ�
			if (p_player->row + 1 <= 19 || mapChipList[row + 1][col] != 3)
			{
				p_player->y += p_player->m_speed;
				p_player->m_moving_distance += p_player->m_speed;
			}
			break;
		case 2: // ��ړ�
			if (p_player->row - 1 >= 0 || mapChipList[row - 1][col] != 3)
			{
				p_player->y -= p_player->m_speed;
				p_player->m_moving_distance += p_player->m_speed;
			}
			break;
		case 3: // ���ړ�
			if (p_player->col - 1 >= 0 || mapChipList[row][col - 1] != 3)
			{
				p_player->x -= p_player->m_speed;
				p_player->m_moving_distance += p_player->m_speed;
			}
			break;
		case 4: // �E�ړ�
			if (p_player->col + 1 <= 27 || mapChipList[row][col + 1] != 3)
			{
				p_player->x += p_player->m_speed;
				p_player->m_moving_distance += p_player->m_speed;
			}
			break;
		}

		p_player->m_frame_count = 0;

		if (p_player->m_moving_distance >= 40)
		{
			// �}�b�v�`�b�v�̓񎟌��z��̍X�V
			switch (p_player->m_key_check)
			{
			case 1: // ���ړ�
				p_player->row++;
				break;
			case 2: // ��ړ�
				p_player->row--;
				break;
			case 3: // ���ړ�
				p_player->col--;
				break;
			case 4: // �E�ړ�
				p_player->col++;
				break;
			}

			p_player->m_moving_distance = 0.0f;
			p_player->key_push_flag = false;
			p_player->m_key_check = 0;
		}
	}
}

// �e�̔���
void Bullet::m_FireBullet(Bullet* bullet)
{
	bullet->m_frame_count++;

	if (bullet->y > 840.0f || bullet->y < 80.0f || bullet->x < 80.0f || bullet->x > 1160)
	{
		bullet->m_key_check = 0;
		bullet->key_push_flag = false;
	}

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

	}
}

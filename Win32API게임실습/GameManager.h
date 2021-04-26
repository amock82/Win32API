#pragma once

class GameManager
{
private:
	//�ƾ��� ī���� ����
	static int ayakoSpawnCount;
	static int ayakoDelCount;

	//���ڽ� ī���� ����
	static int stealthSpawnCount;
	static int stealthDelCount;

	//�÷��̾� ī��Ʈ
	static int playerCount;

	//�÷��̾� ü��
	static float playerHP;

	//�������� Ŭ�����//
	static bool stageClear;

	//�÷��̾� ������ UI ��ü ������ �迭
	static GameObject* playerIcon[3];

	//�÷��̾� ��ü ������
	static GameObject* playerObj;

	//�÷��̾� ü�¹� UI ��ü ������
	static GameObject* playerHPBar;

	//��ź ������ UI ��ü ������ �迭
	static GameObject* bombIcon[5];

	//��ź���� ����
	static int bombCount;

public:
	//���ӸŴ��� �ʱ�ȭ �Լ�
	static void init();

	//�ƾ��� ī���� �Լ�
	static void addAyakoCount();
	static void delAyakoCount();
	static int getAyakoCount();

	//���ڽ� ī���� �Լ�
	static void addStealthCount();
	static void delStealthCount();
	static int getStealthCount();

	//�������� Ŭ���� ����, ����//
	static void setStageClear(bool clear);
	static bool getStageClear();

	//�÷��̾� ������ �Լ�
	static void restartPlayer();

	//�÷��̾� ���� �Լ�
	static void damagePlayer(float damage);

	//�÷��̾� ü�� ���
	static void showHPBar();

	//�÷��̾� ��ź ī��Ʈ �Լ�
	static int getBombCount();
	static void addBombCount();
	static void subBombCount();

	//��ź������ ���̱��Լ�
	static void showBombIcon();

	//���� �Ͻ����� ����
	static bool isPause;
};
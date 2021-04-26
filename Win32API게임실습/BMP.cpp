#include "framework.h"

bool readBMP(const char* fileName, Image* image)
{
	FILE* stream;
	errno_t errno;

	//��Ʈ��������� ����ü : BITMAPFILEHEADER
	BITMAPFILEHEADER fileHeader;
	//��Ʈ��������� ����ü : BITMAPINFOHEADER
	BITMAPINFOHEADER infoHeader;
	//�ȼ�����Ÿ �����޸� 
	unsigned int* data = nullptr;

	errno = fopen_s(&stream, fileName, "rb");

	if (errno == 0 && stream != nullptr)
	{
		//printf("���� ���� ����\n");
		//��Ʈ���������..�б�
		fread(&fileHeader, sizeof(fileHeader), 1, stream);

		//��Ʈ���������..���
		//printf("----��Ʈ������ ���-----\n");
		//printf("bfType 0x%x\n", fileHeader.bfType);  //���ϳ��ο���..���������� �����ϴ� �ڵ�(�����ڵ�)
		//printf("bfSize %d\n", fileHeader.bfSize);  //����ũ��
		//printf("bfReserved1 %d\n", fileHeader.bfReserved1); //��������(���� ���ȵ�)
		//printf("bfReserved2 %d\n", fileHeader.bfReserved2); //��������(���� ���ȵ�)
		//printf("bfOffBits %d\n", fileHeader.bfOffBits);   //���Ͻ��ۿ��� ��Ʈ�ʵ���Ÿ������ ����(Offset)

		//��Ʈ���������..�б�
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		//��Ʈ���������..���
		//printf("----��Ʈ������ ���----\n");
		//printf("biWidth  %d\n", infoHeader.biWidth);      //�̹��� ����ũ��
		//printf("biHeight %d\n", infoHeader.biHeight);     //�̹��� ����ũ��
		//printf("biBitCount %d\n", infoHeader.biBitCount); //�ȼ��� ��Ʈ����
		//printf("biCompression %d\n", infoHeader.biCompression); //�������� (0�� ������� ����)
		//printf("biImageSize %d\n", infoHeader.biSizeImage);   //�ȼ�����Ÿ..�迭ũ��(����Ʈ ����)
		//printf("biPlanes %d\n", infoHeader.biPlanes);  //�̹��� ���� (�׻� 1)

		//printf("biXPelsPerMeter %d\n", infoHeader.biXPelsPerMeter); //x���� ���ʹ� �ȼ�����
		//printf("biYPelsPerMeter %d\n", infoHeader.biYPelsPerMeter); //y���� ���ʹ� �ȼ�����

		//printf("biClrUsed %d\n", infoHeader.biClrUsed);           //�̹������� ���� color ����
		//printf("biClrImportant %d\n", infoHeader.biClrImportant); //�̹����� �ֿ� color ����

		//�̹��� ���� Ȯ���ϱ�
		if (fileHeader.bfType == 0x4d42 && infoHeader.biBitCount == 32 && infoHeader.biClrImportant == 0)
		{
			//�ȼ�����Ÿ �ε��ϱ�
			int length = infoHeader.biSizeImage / 4;

			data = new unsigned int[length];                    //�ε���� �����Ҵ�
			fread(data, sizeof(unsigned int), length, stream);  //�ȼ�����Ÿ �ε��ϱ�

			//���ϴݱ�
			fclose(stream);

			//�̹�������ü��..�ʿ����� �����ϱ�
			image->width = infoHeader.biWidth;
			image->height = infoHeader.biHeight;
			image->data = data;

			return true;
		}
		else {

			printf("�߸��� ��Ʈ�� ���� ������\n");
			return false;
		}
	}
	else {
		printf("���� ���� ����\n");
		return false;
	}

}

bool readBMP(const char* fileName, int x, int y, int width, int height, Image* image)
{
	FILE* stream;
	errno_t errno;

	//��Ʈ��������� ����ü : BITMAPFILEHEADER
	BITMAPFILEHEADER fileHeader;
	//��Ʈ��������� ����ü : BITMAPINFOHEADER
	BITMAPINFOHEADER infoHeader;
	//�ȼ�����Ÿ �����޸� 
	unsigned int* data = nullptr;

	errno = fopen_s(&stream, fileName, "rb");

	if (errno == 0 && stream != nullptr)
	{
		//printf("���� ���� ����\n");
		//��Ʈ���������..�б�
		fread(&fileHeader, sizeof(fileHeader), 1, stream);

		//��Ʈ���������..���
		//printf("----��Ʈ������ ���-----\n");
		//printf("bfType 0x%x\n", fileHeader.bfType);  //���ϳ��ο���..���������� �����ϴ� �ڵ�(�����ڵ�)
		//printf("bfSize %d\n", fileHeader.bfSize);  //����ũ��
		//printf("bfReserved1 %d\n", fileHeader.bfReserved1); //��������(���� ���ȵ�)
		//printf("bfReserved2 %d\n", fileHeader.bfReserved2); //��������(���� ���ȵ�)
		//printf("bfOffBits %d\n", fileHeader.bfOffBits);   //���Ͻ��ۿ��� ��Ʈ�ʵ���Ÿ������ ����(Offset)

		//��Ʈ���������..�б�
		fread(&infoHeader, sizeof(infoHeader), 1, stream);

		//��Ʈ���������..���
		//printf("----��Ʈ������ ���----\n");
		//printf("biWidth  %d\n", infoHeader.biWidth);      //�̹��� ����ũ��
		//printf("biHeight %d\n", infoHeader.biHeight);     //�̹��� ����ũ��
		//printf("biBitCount %d\n", infoHeader.biBitCount); //�ȼ��� ��Ʈ����
		//printf("biCompression %d\n", infoHeader.biCompression); //�������� (0�� ������� ����)
		//printf("biImageSize %d\n", infoHeader.biSizeImage);   //�ȼ�����Ÿ..�迭ũ��(����Ʈ ����)
		//printf("biPlanes %d\n", infoHeader.biPlanes);  //�̹��� ���� (�׻� 1)

		//printf("biXPelsPerMeter %d\n", infoHeader.biXPelsPerMeter); //x���� ���ʹ� �ȼ�����
		//printf("biYPelsPerMeter %d\n", infoHeader.biYPelsPerMeter); //y���� ���ʹ� �ȼ�����

		//printf("biClrUsed %d\n", infoHeader.biClrUsed);           //�̹������� ���� color ����
		//printf("biClrImportant %d\n", infoHeader.biClrImportant); //�̹����� �ֿ� color ����

		//�̹��� ���� Ȯ���ϱ�
		if (fileHeader.bfType == 0x4d42 && infoHeader.biBitCount == 32 && infoHeader.biClrImportant == 0)
		{
			//�ȼ�����Ÿ �ε��ϱ�
			int length = width * height;    //�ε��� �̹���ũ�⸸ŭ�� �޸� 
			data = new unsigned int[length];//�ε���� �����Ҵ�
			
			//x, y ���� width, height �簢�� ������ �̹�����..�ε��ϱ�///
			//fseek ����ϱ�
			int offset = (infoHeader.biWidth * y + x) * 4;
			fseek(stream, offset, SEEK_CUR);

			//�簢�� �̹��� �ε��ϱ�
			int hGap = (infoHeader.biWidth - width) * 4;

			for (int i = 0; i < height; i++)
			{
				fread(data + i*width , sizeof(unsigned int), width, stream);
				fseek(stream, hGap, SEEK_CUR);
			}

			//���ϴݱ�
			fclose(stream);

			//�̹�������ü��..�ʿ����� �����ϱ�
			image->width  = width;
			image->height = height;
			image->data   = data;

			return true;
		}
		else {

			printf("�߸��� ��Ʈ�� ���� ������\n");
			return false;
		}
	}
	else {
		printf("���� ���� ����\n");
		return false;
	}

}

void drawBMP(float px, float py, Image* image)
{
	//�̹��� �׸���(infoHeader.biWidth, infoHeader.biHeight, data)
	for (int y = 0; y < image->height; y++)
	{
		for (int x = 0; x < image->width; x++)
		{
			//setPixel�� x, y ��ǥ�� data�迭�� �ȼ��� ���
			unsigned int pixel = image->data[y * image->width + x];

			setPixel(px + x, py + y, pixel);
		}
	}
}

void drawBMP(float px, float py, Image* image, float fillAmount)
{
	//�̹��� �׸���(infoHeader.biWidth, infoHeader.biHeight, data)
	for (int y = 0; y < image->height; y++)
	{
		for (int x = 0; x < image->width * fillAmount; x++)
		{
			//setPixel�� x, y ��ǥ�� data�迭�� �ȼ��� ���
			unsigned int pixel = image->data[y * image->width + x];

			setPixel(px + x, py + y, pixel);
		}
	}
}
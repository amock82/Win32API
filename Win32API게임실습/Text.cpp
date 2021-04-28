#include "framework.h"

// DLL ����ϱ�
#pragma comment (lib, "freetype.lib")

Text::Text(wstring text, int fontSize, unsigned char r, unsigned char g, unsigned char b, float px, float py)
	: GameObject("UI", "�ؽ�Ʈ", true, px, py)
{
    this->text = text;
    this->fontSize = fontSize;

    this->r = r;
    this->g = g;
    this->b = b;
}

Text::Text(wstring text, float px, float py)
    : GameObject("UI", "�ؽ�Ʈ", true, px, py)
{
    this->text = text;
    this->fontSize = 20;

    this->r = 255;
    this->g = 255;
    this->b = 255;
}

Text::~Text()
{
    // ��Ʈ��� ������
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

void Text::start()
{
    // ��Ʈ ���̺귯�� �ʱ�ȭ
    if (FT_Init_FreeType(&library) == 0)
    {
        cout << "��Ʈ���̺귯�� �ʱ�ȭ ����" << endl;
    }
    else
    {
        cout << "��Ʈ���̺귯�� �ʱ�ȭ ����" << endl;
    }

    // ��Ʈ ���� �о����
    if (FT_New_Face(library, "Asset/UI/DungGeunMo.ttf", 0, &face) == 0)
    //if (FT_New_Face(library, "Asset/UI/koverwatch.ttf", 0, &face) == 0)
    {
        cout << "��Ʈ���� �ε� ����" << endl;
    }
    else
    {
        cout << "��Ʈ���� �ε� ����" << endl;
    }

    // ��Ʈ �ɼ� (ũ�� �����ϱ�)
    FT_Set_Pixel_Sizes(face, fontSize, fontSize);
}

void Text::update()
{

}

void Text::setText(wstring text)
{
    this->text = text;
}

void Text::draw()
{
    // ��Ʈ ��� ��ġ
    float fontx = getPx();
    float fonty = getPy();

    for (int i = 0; i < text.size(); i++)
    {
        int index = FT_Get_Char_Index(face, text[i]);          // text ���� ��� ���� ��ġ(�ε���) ���ϱ�
        FT_Load_Glyph(face, index, 0);                      // index ��ġ���� �ش� ���� ���� �ε��ϱ�. �ε� ��ġ�� face->glyph
        FT_Render_Glyph(face->glyph, (FT_Render_Mode)0);    // face->glyph�� �ε��� ���������� �̹������� ����� face->glyph->bitmap

        int width = face->glyph->bitmap.width; // �̹��� ����ũ��
        int height = face->glyph->bitmap.rows;  // �̹��� ����ũ��
        unsigned char* buffer = face->glyph->bitmap.buffer;

        //��Ʈ ��� �簢�� �������� ��ġ ������ ����
        int left = face->glyph->bitmap_left;
        int top  = face->glyph->bitmap_top;

        // ��Ʈ ����ϱ�
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char v = buffer[y * width + x];
                
                float a = v / 255.0f;   // ���� ��
                
                // ������
                unsigned char br, bg, bb;

                getPixel(fontx + x + left, fonty + y - top, br, bg, bb);

                // ���ĺ����ϱ�
                unsigned rr = r * a + br * (1 - a);
                unsigned rg = g * a + bg * (1 - a);
                unsigned rb = b * a + bb * (1 - a);

                
                if (v != 0)
                {
                    setPixel(fontx + x + left, fonty + y - top, rr, rg, rb);
                }
                
            }
        }

        // ��Ʈ ��� ��ġ ������Ű��
        fontx += face->glyph->advance.x / 64;
        fonty -= face->glyph->advance.y / 64;
    }
}
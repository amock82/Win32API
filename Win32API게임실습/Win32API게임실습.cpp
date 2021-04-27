﻿// Win32API게임실습.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Win32API게임실습.h"

// freetype 헤더
#include <ft2build.h>
#include FT_FREETYPE_H

#pragma comment (lib, "freetype.lib")

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND hWnd;                                      // 윈도우 핸들 입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    START_DEBUG_CONSOLE();
    cout << "디버그 콘솔창 시작하기" << endl;
  
    // freetype 테스트
    FT_Library library;
    FT_Face    face;

    // 폰트 라이브러리 초기화
    if (FT_Init_FreeType(&library) == 0)
    {
        cout << "폰트라이브러리 초기화 성공" << endl;
    }
    else
    {
        cout << "폰트라이브러리 초기화 실패" << endl;
    }

    // 폰트 파일 읽어오기
    if (FT_New_Face(library, "Asset/UI/DungGeunMo.ttf", 0, &face) == 0)
    {
        cout << "폰트파일 로드 성공" << endl;
    }
    else
    {
        cout << "폰트파일 로드 실패" << endl;
    }

    // 폰트 옵션 (크기 지정하기)
    FT_Set_Pixel_Sizes(face, 32, 32);   

    // 글자 모양 정보 위치 찾기
    WCHAR text = L'a';

    int index = FT_Get_Char_Index(face, text);          // text 글자 모양 정보 위치(인덱스) 구하기
    FT_Load_Glyph(face, index, 0);                      // index 위치에서 해당 글자 정보 로드하기. 로드 위치는 face->glyph
    FT_Render_Glyph(face->glyph, (FT_Render_Mode)0);    // face->glyph에 로드한 글자정보로 이미지정보 만들기 face->glyph->bitmap

    int width  = face->glyph->bitmap.width; // 이미지 가로크기
    int height = face->glyph->bitmap.rows;  // 이미지 세로크기
    unsigned char* buffer = face->glyph->bitmap.buffer;

    // 폰트 출력하기
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            unsigned char v = buffer[y * width + x];

            printf("%4d", v);
        }
        printf("\n");
    }

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32API, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    MSG msg;

    //게임 초기화 : 타이머, 그래픽
    initGraphic(hWnd, 0, 0, WIDTH,HEIGHT);
    Timer::init();
    Input::init();
    Random::init();
    SceneManager::init();

    while (Application::isPlaying)
    {  
         if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) == TRUE)
         {
             if (msg.message == WM_QUIT)
             {
                 break;
             }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
         }

         //게임 실행하기
         clear(0, 0, 0);
         Timer::update();
         Input::update();

         SceneManager::run();

         render();
    }

    //종료하기
    STOP_DEBUG_CONSOLE();
    exitGraphic();

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32API));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = CreateSolidBrush(RGB(0, 0, 0));
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    int style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;

   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   //윈도우 크기 조정하기 
   RECT rt = {0,0, WIDTH, HEIGHT};

   AdjustWindowRect(&rt, style, FALSE);

   int width  = rt.right - rt.left;
   int height = rt.bottom - rt.top;

   hWnd = CreateWindowW(szWindowClass, 
                        szTitle, 
                        style,
                        CW_USEDEFAULT, 
                        0, 
                        width,  //윈도우 가로길이 
                        height, //윈도우 세로길이
                        nullptr, 
                        nullptr, 
                        hInstance, 
                        nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            render();

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:

    case WM_MOUSEMOVE:
    {
        int mx = LOWORD(lParam);
        int my = HIWORD(lParam);

        Input::mousePosition = { mx, my };
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
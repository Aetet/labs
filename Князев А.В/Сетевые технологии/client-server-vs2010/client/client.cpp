// client.cpp: ���������� ����� ����� ��� ����������.
//


#include "stdafx.h"
#include "client.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <tchar.h>

#pragma comment(lib, "Ws2_32.lib")

#define MAX_LOADSTRING 100

// ���������� ����������:
HINSTANCE hInst;								// ������� ���������
TCHAR szTitle[MAX_LOADSTRING];					// ����� ������ ���������
TCHAR szWindowClass[MAX_LOADSTRING];			// ��� ������ �������� ����
HWND hLst;

SOCKET srv_socket;
SOCKADDR_IN local_sin;
SOCKADDR_IN dest_sin;
TCHAR host[255]=TEXT("localhost");
TCHAR port[5]=TEXT("70");

// ��������� ���������� �������, ���������� � ���� ������ ����:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Connect(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	MSG msg;
	HACCEL hAccelTable;

	// ������������� ���������� �����
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CLIENT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ��������� ������������� ����������:
	if (!InitInstance (hInstance, nCmdShow))
		return FALSE;
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLIENT));
	// ���� ��������� ���������:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int) msg.wParam;
}




// P����������� ����� ����.
//    ��� ������� � �� ������������� ���������� ������ � ������, ���� �����, ����� ������ ���
//    ��� ��������� � ��������� Win32, �� �������� ������� RegisterClassEx'
//    ������� ���� ��������� � Windows 95. ����� ���� ������� ����� ��� ����,
//    ����� ���������� �������� "������������" ������ ������ � ���������� �����
//    � ����.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLIENT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_CLIENT);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	return RegisterClassEx(&wcex);
}


//   C�������� ��������� ���������� � ������� ������� ����.
//        � ������ ������� ���������� ���������� ����������� � ���������� ����������, � �����
//        ��������� � ��������� �� ����� ������� ���� ���������.
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
   hInst = hInstance; // ��������� ���������� ���������� � ���������� ����������
   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      300, 300, 300, 300, NULL, NULL, hInstance, NULL);
   if (!hWnd)
      return FALSE;
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   hLst=CreateWindow(TEXT("listbox"), NULL,
         WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_VSCROLL | WS_BORDER |
         LBS_WANTKEYBOARDINPUT,
         0, 0, 300, 300,
         hWnd, (HMENU) 0, hInst, NULL);
   return TRUE;
}

BOOL OnCreate()
{
	int rc;
	WSADATA WSAData;
	rc = WSAStartup(MAKEWORD(2,2),&WSAData);
	if(rc!=0)
	{
		MessageBox(0,TEXT("WSAStartup failed"),TEXT("������"),MB_OK);
		return FALSE;
	}
	return TRUE;
}

BOOL SetConnection(HWND hwnd)
{
	PHOSTENT phe;
	srv_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(srv_socket == INVALID_SOCKET)
	{
		//��������� ������;
		MessageBox(0,TEXT("�� ������� ������� �����"),TEXT("������"),MB_OK);
		return FALSE;
	}
	dest_sin.sin_family = AF_INET;
	char temp[255];
	CharToOem(host,temp);
	phe = gethostbyname(temp);
	if(phe == NULL)
	{
		//��������� ������;
		MessageBox(0,TEXT("���� �� ������"),TEXT("������"),MB_OK);
		return FALSE;
	}
	memcpy((char FAR*)&(dest_sin.sin_addr),phe->h_addr_list[0], phe->h_length);
	dest_sin.sin_port=htons(_ttoi(port));
	if(connect(srv_socket,(PSOCKADDR)&dest_sin,sizeof(dest_sin))==SOCKET_ERROR)
	{
		MessageBox(0,TEXT("�� ������� �����������"),TEXT("������"),MB_OK);
		return FALSE;
	}
	char szBuf[1000];
	szBuf[0]=0;
	strcpy(szBuf,"\n");
	send(srv_socket,szBuf,strlen(szBuf),0);
	szBuf[0]=0;
	int rc=recv(srv_socket,szBuf,sizeof(szBuf),0);
	if(rc==0) return FALSE;
	szBuf[rc]=0;
	char *p=szBuf, *t=szBuf;
	for(;*p!=0;p++)
	if(*p=='\n')
	{
		*p=0;
		TCHAR wtemp[255];
		//OemToChar(t,wtemp); ��� �������� � ����������. ���������� cp866 -> win1251 ����� ������
		MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,t,-1,wtemp,sizeof(wtemp)/sizeof(wtemp[0]));
		SendMessage(hLst,LB_ADDSTRING,0,(LPARAM)wtemp);
		t=p+1;
	}
}

// O����������� ��������� � ������� ����.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// ��������� ����� � ����:
		if(wmEvent==LBN_DBLCLK)
		{
			int sel = SendMessage(hLst,LB_GETCURSEL,0,0);
			if(sel==LB_ERR)break;
			char szBuf[255];
			szBuf[0]=0;
			itoa(sel,szBuf,10);
			send(srv_socket,szBuf,strlen(szBuf),0);
			szBuf[0]=0;
			int rc=recv(srv_socket,szBuf,sizeof(szBuf),0);
			if(rc==0) break;
			szBuf[rc]=0;
			TCHAR wtemp[255];
			MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,szBuf,-1,wtemp,sizeof(wtemp)/sizeof(wtemp[0]));
			MessageBox(hWnd,wtemp,TEXT("��������"),MB_OK);
			break;
		}
		switch (wmId)
		{
			case IDM_CONNECT:
				if(DialogBox(hInst, MAKEINTRESOURCE(IDD_CONNECT), hWnd, Connect)==IDOK)
					SetConnection(hWnd);
				break;
			case IDM_ABOUT:
				DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
				break;
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
		}
	case WM_CREATE:
		OnCreate();
		break;
	case WM_DESTROY:
		WSACleanup();
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		MoveWindow(hLst,0,0,LOWORD(lParam),HIWORD(lParam),TRUE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: �������� ����� ��� ���������...
		EndPaint(hWnd, &ps);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���������� ��������� ��� ���� "� ���������".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

// ���������� ��������� ��� ���� "���������".
INT_PTR CALLBACK Connect(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		SendDlgItemMessage(hDlg, IDC_HOST, WM_SETTEXT, 0, (LPARAM) host); 
		SendDlgItemMessage(hDlg, IDC_PORT, WM_SETTEXT, 0, (LPARAM) port); 
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			HWND hWndEdit = GetDlgItem(hDlg, IDC_HOST);
			GetWindowText(hWndEdit, host, 255);
			hWndEdit = GetDlgItem(hDlg, IDC_PORT);
            GetWindowText(hWndEdit, port, 5);
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

#include "WinStart.h"
//#include "commands.h"
//#include "resource.h"
#include "Wnd.h"

#if _WIN64
#define SETWINPTR SetWindowLongPtr(_hWnd, GWLP_USERDATA, (LONG_PTR)wnd);
#define GETWINPTR (Wnd*)GetWindowLongPtr(_hWnd, GWLP_USERDATA);
#else
#define SETWINPTR SetWindowLongPtr(_hWnd, GWL_USERDATA, (LONG_PTR)wnd);
#define GETWINPTR  (Wnd*)GetWindowLongPtr(_hWnd, GWL_USERDATA);
#endif

LRESULT CALLBACK wndProc(HWND _hWnd, UINT _msg, WPARAM _wparam, LPARAM _lparam)
{
	switch (_msg)
	{
		case WM_CREATE:
		{
			Wnd* wnd = (Wnd*)((LPCREATESTRUCT)_lparam)->lpCreateParams;
			if (wnd)
			{
				SETWINPTR;
			}
			break;
		}

		case WM_CLOSE:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->onClose();
			}
			break;
		}

		case WM_SETFOCUS:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->onFocus();
			}
			break;
		}

		case WM_KILLFOCUS:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->onBlur();
			}
			break;
		}

		case WM_KEYDOWN:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->onKeyDown(_wparam);
			}
			break;
		}

		case WM_KEYUP:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->onKeyUp(_wparam);
			}
			break;
		}

		case WM_COMMAND:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->sendMessage(wnd->CMD, _wparam, NULL, "");
			}
			break;
		}

		case WM_MOUSEMOVE:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->onMouseMove(LOWORD(_lparam), HIWORD(_lparam));
			}
			break;
		}

		case WM_LBUTTONDOWN:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->sendMessage(wnd->LBD, LOWORD(_lparam), HIWORD(_lparam), "");
			}
			break;
		}

		case WM_LBUTTONUP:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->sendMessage(wnd->LBU, LOWORD(_lparam), HIWORD(_lparam), "");
			}
			break;
		}

		case WM_RBUTTONDOWN:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->sendMessage(wnd->RBD, LOWORD(_lparam), HIWORD(_lparam), "");
			}
			break;
		}

		case WM_RBUTTONUP:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->sendMessage(wnd->RBU, LOWORD(_lparam), HIWORD(_lparam), "");
			}
			break;
		}

		case WM_MOUSELEAVE:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->sendMessage(wnd->MSO, 0, 0, "");
			}
			break;
		}

		case WM_PAINT:
		{
			Wnd* wnd = GETWINPTR;
			if (wnd)
			{
				wnd->onPaint();
			}
			break;
		}
	}
	return(DefWindowProc(_hWnd, _msg, _wparam, _lparam));
}

int WinStart(HINSTANCE _hInstance)
{
	WNDCLASSEX wcFrame;
	ZeroMemory(&wcFrame, sizeof(WNDCLASSEX));
	wcFrame.cbClsExtra = 0;
	wcFrame.cbSize = sizeof(WNDCLASSEX);
	wcFrame.cbWndExtra = 0;
	wcFrame.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcFrame.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcFrame.hIcon = LoadIcon(_hInstance, MAKEINTRESOURCE(APP_LARGE_ICON));/*IDI_APPLICATION);*/
	wcFrame.hIconSm = LoadIcon(_hInstance, MAKEINTRESOURCE(APP_SMALL_ICON));
	wcFrame.hInstance = _hInstance;
	wcFrame.lpfnWndProc = (WNDPROC)wndProc;
	wcFrame.lpszClassName = "wcFrame";
	wcFrame.lpszMenuName = NULL;
	wcFrame.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	INITCOMMONCONTROLSEX comctrl;
	comctrl.dwSize = sizeof(INITCOMMONCONTROLSEX);
	comctrl.dwICC = ICC_PROGRESS_CLASS | ICC_STANDARD_CLASSES;
	InitCommonControlsEx(&comctrl);

	if (!RegisterClassEx(&wcFrame))
	{
		return(-1);
	}
	return(0);
}

int WinStop()
{
	return(0);
}


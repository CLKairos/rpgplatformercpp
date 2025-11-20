#include "window.h"
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
}   

Window::Window() : m_hInstance(GetModuleHandle(nullptr)) {
    const wchar_t* CLASS_NAME = L"Sample Window Class";

    WNDCLASSW wndClass = { };
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = m_hInstance;
    wndClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wndClass.lpfnWndProc = nullptr; //fix later

    RegisterClassW(&wndClass);

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

    int width = 800;
    int height = 600;

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;

    AdjustWindowRect(&rect, style, FALSE);
    
    m_hWnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Sample Window",
        style,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        nullptr,
        nullptr,
        m_hInstance,
        nullptr
    );
}

Window::~Window() {
    const wchar_t* CLASS_NAME = L"Sample Window Class";
    
    UnregisterClassW(CLASS_NAME, m_hInstance);
}

bool Window::processMessages() {
    MSG msg = {};

    while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            return false;
        }
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
}

#pragma once
#include <windows.h>
#include <string>

class ImageDisplay {
public:
	// 显示位图图像
	static bool showImage(int resourceId, const std::string& title = "Image Display", int timeoutMs = 0);

	// 显示位图图像（通过资源名称）
	static bool showImage(const char* resourceName, const std::string& title = "Image Display", int timeoutMs = 0);

	// 关闭图像窗口
	static void closeImage();

	// 检查窗口是否正在显示
	static bool isShowing();

private:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static void CreateWindowInstance(int resourceId, const std::string& title, int timeoutMs);
	static void CreateWindowInstance(const char* resourceName, const std::string& title, int timeoutMs);
	static void Cleanup();

	static HWND hwnd;
	static HBITMAP hBitmap;
	static HWND staticControl;
	static UINT_PTR timerId;
};
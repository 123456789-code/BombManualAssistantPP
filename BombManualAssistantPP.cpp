#include <string>
#include <windows.h>
#include "win.h"
#include "mytool.h"
#include "Module1.h"
#include "Module2.h"
#include "Module3.h"
#include "Module4.h"
#include "Module5.h"
#include "Module6.h"
#include "Module7.h"
#include "Module8.h"
#include "Module9.h"
#include "Module10.h"
#include "Module11.h"
#include "Module12.h"

using std::string, std::wstring, std::string_view;
using namespace mytool;

constexpr inline string_view version = "2.3.2";

int main() {
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	SetConsoleTitle((L"Bomb Manual Assistant " + wstring(version.begin(), version.end())).c_str());
	if (!IsRunAsAdmin()) {
		// 启动提示
		prints('\n', '\n',
			"此程序仅用于辅助拆弹助手，带有一定作弊性质，请谨慎使用！",
			"建议第一次使用时先将各个模块的编码方式完整阅读",
			"祝你好运 ^_^",
			"Made by Wang125510"
		);
		bool ontop = false;
		print("是否需要将窗口置顶(0表示否，1表示是): ");
		input(ontop);
		if (ontop) { // 请求以管理员权限重新启动
			if (RestartAsAdmin()) {
				return 0; // 当前进程退出
			}
			else {
				// 用户拒绝了权限请求
				return 1;
			}
		}
	}
	else {
		// 设置置顶
		if (HWND hwnd = GetConsoleWindow()) {
			SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
		}
	}

	BombInfo info;
	int module = 0;
	bool restart = false;
	do {
		restart = false;
		system("cls");

		// 预输入炸弹参数
		printa("请告诉我你的炸弹的型号");
		print("序列号的末伪是奇数还是偶数(0表示偶数，1表示奇数): ");
		input(info.odd);
		print("序列号是否包含元音: ");
		input(info.aeiou);
		print("电池数量: ");
		input(info.battery);
		print("是否有Parallel端口: ");
		input(info.parallel);

		while (true) { // 选择模块
			system("cls");
			prints('\n', '\n',
				"请输入当前的模块",
				"0.重新开始",
				"1.线路模块",
				"2.按钮模块",
				"3.键盘模块",
				"4.四色方块",
				"5.汉字模块",
				"6.记忆模块",
				"7.摩斯电码",
				"8.复杂线路",
				"9.顺序线路",
				"10.迷宫模块",
				"11.密码模块",
				"12.旋钮模块"
			);
			print("请选择模块: ");
			input(module);
			switch (module) {
			case 0: { restart = true; break; }
			case 1: { Module1::main(info); break; }
			case 2: { Module2::main(info); break; }
			case 3: { Module3::main(info); break; }
			case 4: { Module4::main(info); break; }
			case 5: { Module5::main(info); break; }
			case 6: { Module6::main(info); break; }
			case 7: { Module7::main(info); break; }
			case 8: { Module8::main(info); break; }
			case 9: { Module9::main(info); break; }
			case 10: { Module10::main(info); break; }
			case 11: { Module11::main(info); break; }
			case 12: { Module12::main(info); break; }
			default: { printa("你输入了错误指令"); break; }
			}
			if (restart) { break; }
			system("pause");
		}
	} while (restart);
	return 0;
}

#pragma once
#include <array>
#include <algorithm>
#include "resource.h"
#include "mytool.h"

using std::array, std::cin, std::any_of;
using namespace mytool;

class Module3 { // 键盘模块
public:
	static void main(const BombInfo& info) {
		printa("请输入当前键盘上的字符，编码为下表对应数字，顺序请按照正常文字阅读顺序");
		show_image(IDB_BITMAP1);
		array<unsigned, 4> code;
		print("请输入左上角的字符: ");
		input(code[0]);
		print("请输入右上角的字符: ");
		input(code[1]);
		print("请输入左下角的字符: ");
		input(code[2]);
		print("请输入右下角的字符: ");
		input(code[3]);
		code = sort(code);
		if (any_of(code.begin(), code.end(), [](int x) { return x == 0; })) {
			printa("没找到相关的顺序，请检查输入");
		}
		else {
			prints('\0', '\n',
				"按下顺序为:\n",
				"╔═══╦═══╗\n",
				"║ ", code[0], " ║ ", code[1], " ║\n",
				"╠═══╬═══╣\n",
				"║ ", code[2], " ║ ", code[3], " ║\n",
				"╚═══╩═══╝"
			);
		}
		close_image();
	}

private:
	static constexpr array<array<uint8_t, 7>, 6> table{{
		{ 0,8,9,21,18,22,17 },
		{ 10,0,17,23,6,22,3 },
		{ 2,19,23,11,24,9,6 },
		{ 14,1,15,18,11,3,26 },
		{ 13,26,15,16,1,7,5 },
		{ 14,10,25,14,13,20,4 }
	}};

	static constexpr array<unsigned, 4> sort(const array<unsigned, 4>& code) {
		array<unsigned, 4> order = { 0,0,0,0 };
		int idx = 0;
		bool flag = false;
		for (; idx < 6; idx++) {
			flag = false;
			for (const unsigned& c : code) {
				flag = true;
				for (const unsigned& l : table[idx]) {
					if (c == l) {
						flag = false;
						break;
					}
				}
				if (flag) { break; }
			}
			if (!flag) { break; }
		}
		if (idx == 6) { return order; }
		int pos = 0;
		int o = 1;
		for (const unsigned& l : table[idx]) {
			for (int i = 0; i < 4; i++) {
				if (code[i] == l) {
					order[i] = o++;
					break;
				}
			}
			if (o == 5) { break; }
		}
		return order;
	}
};

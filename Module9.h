#pragma once
#include <array>
#include "mytool.h"

using std::array;
using namespace mytool;

class Module9 { // 顺序线路
public:
	static void main(const BombInfo& info) {
		array<int, 3> active = { 0, 0, 0 };
		int choice = 0;
		string code = "";
		bool flag = false;
		while (true) {
			print("请选择线路(123对应红蓝黑，0表示退出): ");
			input(choice, [](int v) { return v >= 0 && v <= 3; });
			if (choice == 0) { break; }
			printa("请按照左侧从上倒下的顺序输入当前颜色对应的字母(使用123代替ABC): ");
			input(code, [](string c) {return all_of(c.begin(), c.end(), [](char ch) { return ch >= '0' && ch <= '3'; }); });
			for (char c : code) {
				if (active[choice - 1] >= 9) {
					printa("该线路已经没有更多的线了，请你小心");
				}
				else {
					print(table[choice - 1][active[choice - 1]][c - '1'] ? "剪!" : "不剪!", " ");
				}
				active[choice - 1]++;
			}
			if (flag) { break; }
			printa("");
		}
	}

private:
	static constexpr array<array<array<bool, 3>, 9>, 3> table{{
		{{ {0,0,1}, {0,1,0}, {1,0,0}, {1,0,1}, {0,1,0}, {1,0,1}, {1,1,1}, {1,1,0}, {0,1,0} }},
		{{ {0,1,0}, {1,0,1}, {0,1,0}, {1,0,0}, {0,1,0}, {0,1,1}, {0,0,1}, {1,0,1}, {1,0,0} }},
		{{ {1,1,1}, {1,0,1}, {0,1,0}, {1,0,1}, {0,1,0}, {0,1,1}, {1,1,0}, {0,0,1}, {0,0,1} }}
	}};
};

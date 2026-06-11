#pragma once
#include <string>
#include <array>
#include <utility>
#include "mytool.h"

using std::string, std::array, std::pair;
using namespace mytool;

class Module6 { // 记忆模块
public:
	static void main(const BombInfo& info) {
		array<int, 5> now;
		int ans = 0;
		array<pair<int, int>, 4> history;
		printa("编码格式为{屏幕数字}{下方四位数字}，请放心，程序会帮你记住的^_^");

		// 第一次
		print("请输入第一次的情况: ");
		input_code(now);
		switch (now[0]) {
		case 1:
			ans = 2;
			break;
		case 2:
			[[fallthrough]];
		case 3:
			[[fallthrough]];
		case 4:
			ans = now[0];
			break;
		}
		print("按下第", ans, "个位置的按钮\n");
		history[0] = { ans, now[ans] };

		// 第二次
		print("请输入第二次的情况: ");
		input_code(now);
		switch (now[0]) {
		case 1:
			for (int i = 1; i < 5; i++) { if (now[i] == 4) { ans = i; break; } }
			break;
		case 3:
			ans = 1;
			break;
		case 2:
			[[fallthrough]];
		case 4:
			ans = history[0].first;
			break;
		}
		print("按下第", ans, "个位置的按钮\n");
		history[1] = { ans, now[ans] };

		// 第三次
		print("请输入第三次的情况: ");
		input_code(now);
		switch (now[0]) {
		case 1:
			for (int i = 1; i < 5; i++) { if (now[i] == history[1].second) { ans = i; break; } }
			break;
		case 2:
			for (int i = 1; i < 5; i++) { if (now[i] == history[0].second) { ans = i; break; } }
			break;
		case 3:
			ans = 3;
			break;
		case 4:
			for (int i = 1; i < 5; i++) { if (now[i] == 4) { ans = i; break; } }
			break;
		}
		print("按下第", ans, "个位置的按钮\n");
		history[2] = { ans, now[ans] };

		// 第四次
		print("请输入第四次的情况: ");
		input_code(now);
		switch (now[0]) {
		case 1:
			ans = history[0].first;
			break;
		case 2:
			ans = 1;
			break;
		case 3:
			[[fallthrough]];
		case 4:
			ans = history[1].first;
			break;
		}
		print("按下第", ans, "个位置的按钮\n");
		history[3] = { ans, now[ans] };

		// 第五次
		print("请输入第五次的情况: ");
		input_code(now);
		switch (now[0]) {
		case 1:
			for (int i = 1; i < 5; i++) { if (now[i] == history[0].second) { ans = i; break; } }
			break;
		case 2:
			for (int i = 1; i < 5; i++) { if (now[i] == history[1].second) { ans = i; break; } }
			break;
		case 3:
			for (int i = 1; i < 5; i++) { if (now[i] == history[3].second) { ans = i; break; } }
			break;
		case 4:
			for (int i = 1; i < 5; i++) { if (now[i] == history[2].second) { ans = i; break; } }
			break;
		}
		print("按下第", ans, "个位置的按钮\n");
	}

private:
	static void input_code(array<int, 5>& now) {
		auto is_valid = [](char c) { return c >= '1' && c <= '4'; };
		auto to_int = [](char c) { return c - '0'; };
		string code;
		while (!(input(code) &&
			code.size() == 5 &&
			all_of(code.begin(), code.end(), is_valid) &&
			(transform(code.begin(), code.end(), now.begin(), to_int), true))) {
			print("应该输入五个1-4之间的数字，请重新输入: ");
		}
	}
};

#pragma once
#include "mytool.h"

using namespace mytool;

class Module4 { // 四色方块
public:
	static void main(const BombInfo& info) {
		int times = 0, temp = 0;
		print("目前失误了几次: ");
		input(times);
		while (times > 2) {
			print("失误应当最多两次，请重新输入: ");
			input(times);
		}
		printa("接下来输入本次新增的颜色，红绿黄蓝对应1234，输入0表示退出");
		while (true) {
			print("请输入本次的颜色: ");
			input(temp);
			while (temp > 4 || temp < 0) {
				print("编码应当在1234中取，请重新输入: ");
				input(temp);
			}
			if (temp == 0) { break; }
			printa(static_cast<int>(table[!info.aeiou][times][temp - 1]));
		}
	}

private:
	static constexpr array<array<array<uint8_t, 4>, 3>, 2> table{{
		{{ {4,3,2,1}, {3,4,1,2}, {2,3,4,1} }},
		{{ {4,2,1,3}, {1,3,2,4}, {3,4,1,2} }}
	}};
};

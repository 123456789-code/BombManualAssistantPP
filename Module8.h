#pragma once
#include <string>
#include <array>
#include <bitset>
#include "mytool.h"

using std::string, std::array, std::bitset;
using namespace mytool;

class Module8 { // 复杂线路
public:
	static void main(const BombInfo& info) {
		string code = "";
		printa("编码格式为{红色}{蓝色}{符号}{LED}，存在为1，不存在为0，不规范输入表示该模块完成");
		while (true) {
			print("请输入编码: ");
			input(code);
			if (code.length() != 4) { break; }
			// 直接查表
			bitset<4> bits(code);
			switch (table[static_cast<uint8_t>(bits.to_ulong())]) {
			case 'C': // 剪断线路
				printa("剪!");
				break;
			case 'D': // 不要剪断线路
				printa("不剪!");
				break;
			case 'S': // 如果炸弹序列号末位为偶数则剪断线路
				if (!info.odd) { printa("剪!"); }
				else { printa("不剪!"); }
				break;
			case 'P': // 如果炸弹有Parallel端口则剪断线路
				if (info.parallel) { printa("剪!"); }
				else { printa("不剪!"); }
				break;
			case 'B': // 如果炸弹上有两个或更多电池则剪断线路
				if (info.battery >= 2) { printa("剪!"); }
				else { printa("不剪!"); }
				break;
			}
		}
	}

private:
	static constexpr array<char, 16> table{
		'C', 'D', 'C', 'B',
		'S', 'P', 'D', 'P',
		'S', 'B', 'C', 'B',
		'S', 'S', 'P', 'D'
	};
};

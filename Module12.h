#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include "mytool.h"

using std::string, std::bitset;
using namespace mytool;

class Module12 { // 旋钮模块
public:
	static void main(const BombInfo& info) {
		// 读取并编码
		string code = "";
		printa("请输入灯泡亮起的模式，按从左到右，先第一行后第二行，亮起为1进行编码:");
		input(code);
		while (code.length() != 12) {
			printa("应是12位二进制数字，请重新输入");
			input(code);
		}
		// 直接查表
		bitset<12> bits(code);
		switch (table[static_cast<uint16_t>(bits.to_ulong())]) {
		case 1:
			printa("上");
			break;
		case 2:
			printa("下");
			break;
		case 3:
			printa("左");
			break;
		case 4:
			printa("右");
			break;
		default:
			printa("没有这个排列");
			break;
		}
	}

private:
	static constexpr array<uint8_t, 4096> table = []() {
		array<uint8_t, 4096> table{};
		table[0x2FD] = 1;
		table[0xA9B] = 1;
		table[0x67D] = 2;
		table[0xA91] = 2;
		table[0x0A7] = 3;
		table[0x086] = 3;
		table[0xBFA] = 4;
		table[0xB3A] = 4;
		return table;
	}();
};

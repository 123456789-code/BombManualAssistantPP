#pragma once
#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>
#include "mytool.h"

using std::string, std::bitset, std::unordered_map;
using namespace mytool;

class Module12 { // 旋钮模块
public:
	static void main(const BombInfo& info) {
		// 读取并编码
		string code = "";
		printa("请输入灯泡亮起的模式，按从左到右，先第一行后第二行，亮起为1进行编码:");
		input(code, [](string c) { return c.length() == 12 && c.find_first_not_of('01') == string::npos; });
		// 直接查表
		bitset<12> bits(code);
		auto it = table.find(static_cast<uint16_t>(bits.to_ulong()));
		if (it != table.end()) {
			switch (it->second) {
				case 1: printa("上"); break;
				case 2: printa("下"); break;
				case 3: printa("左"); break;
				case 4: printa("右"); break;
			}
		}
		else {
			printa("没有这个排列");
		}
	}

private:
	static inline const unordered_map<uint16_t, uint8_t> table{{
		{0x2FD, 1}, {0xA9B, 1},
		{0x67D, 2}, {0xA91, 2},
		{0x0A7, 3}, {0x086, 3},
		{0xBFA, 4}, {0xB3A, 4}
	}};
};

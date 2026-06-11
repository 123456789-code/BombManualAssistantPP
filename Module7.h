#pragma once
#include <string>
#include <unordered_map>
#include "mytool.h"

using std::string, std::string_view, std::unordered_map, std::all_of;
using namespace mytool;

class Module7 { // 摩斯电码
public:
	static void main(const BombInfo& info) {
		string code = "", ans = "";
		printa("请输入摩斯密码，0代表短，1代表长，每次输入一个字母，全部输入完后输入任意非数字完成单词输入: ");
		while (true) {
			print("输入: ");
			input(code);
			if (!all_of(code.begin(), code.end(), ::isdigit)) {
				break;
			}
			auto temp = morse_to_char.find(string_view(code));
			if (temp == morse_to_char.end()) {
				printa("没有这个摩斯电码");
				continue;
			}
			print("本次输入的是: ", temp->second, '\n');
			ans += temp->second;
			print("当前得到的是: ", ans, '\n');
		}
		print("你的密码是: ", ans, '\n');
		auto temp = table.find(string_view(ans));
		if (temp == table.end()) { printa("库里没这个单词"); }
		else { print("对应的数字是: ", temp->second, '\n'); }
	}

private:
	static inline const unordered_map<string_view, char> morse_to_char{
		{"01", 'a'},      // .-
		{"1000", 'b'},    // -...
		{"1010", 'c'},    // -.-.
		{"100", 'd'},     // -..
		{"0", 'e'},       // .
		{"0010", 'f'},    // ..-.
		{"110", 'g'},     // --.
		{"0000", 'h'},    // ....
		{"00", 'i'},      // ..
		{"0111", 'j'},    // .---
		{"101", 'k'},     // -.-
		{"0100", 'l'},    // .-..
		{"11", 'm'},      // --
		{"10", 'n'},      // -.
		{"111", 'o'},     // ---
		{"0110", 'p'},    // .--.
		{"1101", 'q'},    // --.-
		{"010", 'r'},     // .-.
		{"000", 's'},     // ...
		{"1", 't'},       // -
		{"001", 'u'},     // ..-
		{"0001", 'v'},    // ...-
		{"011", 'w'},     // .--
		{"1001", 'x'},    // -..-
		{"1011", 'y'},    // -.--
		{"1100", 'z'},    // --..
		{"11111", '0'},   // -----
		{"01111", '1'},   // .----
		{"00111", '2'},   // ..---
		{"00011", '3'},   // ...--
		{"00001", '4'},   // ....-
		{"00000", '5'},   // .....
		{"10000", '6'},   // -....
		{"11000", '7'},   // --...
		{"11100", '8'},   // ---..
		{"11110", '9'}    // ----.
	};

	static inline const unordered_map<string_view, unsigned> table{
		{"shell", 505},
		{"halls", 515},
		{"slick", 522},
		{"trick", 532},
		{"boxes", 535},
		{"leaks", 542},
		{"strobe", 545},
		{"bistro", 552},
		{"flick", 555},
		{"bombs", 565},
		{"break", 572},
		{"brick", 575},
		{"steak", 582},
		{"sting", 592},
		{"vector", 595},
		{"beats", 600}
	};
};

#pragma once
#include <string>
#include <vector>
#include "mytool.h"

using std::string, std::vector, std::string_view;
using namespace mytool;

class Module11 { // 密码模块
public:
	static void main(const BombInfo& info) {
		string ch;
		vector<string_view> candidates(table.begin(), table.end());
		for (int i = 0; i < 5 && candidates.size() > 1; i++) {
			print("请按第", i + 1, "个位置的可能字母（6个小写字母，中间无空格）: ");
			input(ch, [](string ch) { return ch.size() == 6 && all_of(ch.begin(), ch.end(), ::islower); });
			bool valid_chars[26] = { false };
			for (char c : ch) valid_chars[c - 'a'] = true;
			candidates.erase(
				remove_if(
					candidates.begin(), candidates.end(),
					[&valid_chars, i](string_view w) { return !valid_chars[w[i] - 'a']; }
				),
				candidates.end()
			);
		}
		if (candidates.size() == 1) {
			print("正确答案是: ", candidates[0], '\n');
		}
		else if (candidates.empty()) {
			printa("没有符合条件的单词，请检查输入是否正确");
		}
		else {
			printa("找到多个符合条件的单词，请检查输入是否正确");
			print("可能的单词有: ");
			for (string_view c : candidates) {
				print(c, ' ');
			}
			printa();
		}
	}

private:
	static constexpr array<string_view, 35> table{
		"about", "after", "again", "below", "could",
		"every", "first", "found", "great", "house",
		"large", "learn", "never", "other", "place",
		"plant", "point", "right", "small", "sound",
		"spell", "still", "study", "their", "there",
		"these", "thing", "think", "three", "water",
		"where", "which", "world", "would", "write"
	};
};

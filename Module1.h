#pragma once
#include <format>
#include <string>
#include "mytool.h"

using std::format, std::string;
using namespace mytool;

class Module1 { // 线路模块
public:
	static void main(const BombInfo& info) {
		unsigned counts = 0;
		print("请输入线的数量: ");
		input(counts, [](int v) { return v >= 3 && v <= 6; });

		printa("╔════════════════════════════════════════════════════════╗");
		printa(format("║ {:^54} ║", "线路模块操作指南"));
		printa("╠══════════════════════════════╦═════════════════════════╣");
		printf("条件", "剪断");
		printa("╠══════════════════════════════╬═════════════════════════╣");
		switch (counts) {
		case 3:
			printf("红线 == 0", "2");
			printf("last == 白线", "3");
			printf("蓝线 > 1", "最后一根蓝线");
			printf("其他", "3");
			break;
		case 4:
			if (info.odd) { printf("红线 > 1", "最后一根红线"); }
			printf("红线 == 0 && last == 黄线", "1");
			printf("蓝线 == 1", "1");
			printf("黄线 > 1", "4");
			printf("其他", "2");
			break;
		case 5:
			if (info.odd) { printf("last == 黑线", "4"); }
			printf("红线 == 1 && 黄线 > 1", "1");
			printf("黑线 == 0", "2");
			printf("其他", "1");
			break;
		case 6:
			if (info.odd) { printf("黄线 == 0", "3"); }
			printf("黄线 == 1 && 白线 > 1", "4");
			printf("红线 == 0", "6");
			printf("其他", "4");
			break;
		}
		printa("╚══════════════════════════════╩═════════════════════════╝");
	}
	
private:
	static constexpr void printf(string&& msg1, string&& msg2) {
		printa(format("║ {:<{}} ║ {:<{}} ║", msg1, 28, msg2, 23));
	}
};

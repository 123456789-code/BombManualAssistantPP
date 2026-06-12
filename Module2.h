#pragma once
#include <format>
#include "mytool.h"

using std::format;
using namespace mytool;

class Module2 { // 按钮模块
public:
	static void main(const BombInfo& info) {
		printa("╔════════════════════════════════════════╗");
		printa(format("║ {:^38} ║", "按钮模块操作指南"));
		printa("╠══════════════════════════╦═════════════╣");
		printf1("情况", "操作");
		printa("╠══════════════════════════╬═════════════╣");
		if (info.battery > 1) { printf1("引爆", "按下松开"); }
		printf1("白色, CAR", "按住");
		if (info.battery > 2) { printf1("FRK", "按下松开"); }
		printf1("黄色", "按住");
		printf1("红色, 按住", "按下松开");
		printf1("否则", "按住");
		printa("╚══════════════════════════╩═════════════╝");

		printa("松开时观察条的颜色，并根据下表操作:");
		printa("╔══════════════════╦═════════════╗");
		printf2("颜色", "松开时数字");
		printa("╠══════════════════╬═════════════╣");
		printf2("蓝色", "4");
		printf2("白色", "1");
		printf2("黄色", "5");
		printf2("其他颜色", "1");
		printa("╚══════════════════╩═════════════╝");
	}

private:
	static constexpr void printf1(string&& msg1, string&& msg2) {
		printa(format("║ {:<{}} ║ {:<{}} ║", msg1, 24, msg2, 11));
	}

	static constexpr void printf2(string&& msg1, string&& msg2) {
		printa(format("║ {:<{}} ║ {:<{}} ║", msg1, 16, msg2, 11));
	}
};

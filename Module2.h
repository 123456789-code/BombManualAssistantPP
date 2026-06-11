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
		printa(format("║ {:<{}} ║ {:<{}} ║", "情况", left1, "操作", right1));
		printa("╠══════════════════════════╬═════════════╣");
		if (info.battery > 1) {
			printa(format("║ {:<{}} ║ {:<{}} ║", "引爆", left1, "按下松开", right1));
		}
		printa(format("║ {:<{}} ║ {:<{}} ║", "白色, CAR", left1, "按住", right1));
		if (info.battery > 2) {
			printa(format("║ {:<{}} ║ {:<{}} ║", "FRK", left1, "按下松开", right1));
		}
		printa(format("║ {:<{}} ║ {:<{}} ║", "黄色", left1, "按住", right1));
		printa(format("║ {:<{}} ║ {:<{}} ║", "红色, 按住", left1, "按下松开", right1));
		printa(format("║ {:<{}} ║ {:<{}} ║", "否则", left1, "按住", right1));
		printa("╚══════════════════════════╩═════════════╝");
		printa("松开时观察条的颜色，并根据下表操作:");
		printa("╔══════════════════╦═════════════╗");
		printa(format("║ {:<{}} ║ {:<{}} ║", "颜色", left2, "松开时数字", right2));
		printa("╠══════════════════╬═════════════╣");
		printa(format("║ {:<{}} ║ {:<{}} ║", "蓝色", left2, "4", right2));
		printa(format("║ {:<{}} ║ {:<{}} ║", "白色", left2, "1", right2));
		printa(format("║ {:<{}} ║ {:<{}} ║", "黄色", left2, "5", right2));
		printa(format("║ {:<{}} ║ {:<{}} ║", "其他颜色", left2, "1", right2));
		printa("╚══════════════════╩═════════════╝");
	}

private:
	static constexpr int left1 = 24;
	static constexpr int right1 = 11;
	static constexpr int left2 = 16;
	static constexpr int right2 = 11;
};

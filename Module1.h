#pragma once
#include <format>
#include "mytool.h"

using std::format;
using namespace mytool;

class Module1 { // 线路模块
public:
	static void main(const BombInfo& info) {
		unsigned counts = 0;
		print("请输入线的数量: ");
		input(counts);
		while (counts < 3 || counts > 6) {
			print("线的数量应该在3到6之间，请重新输入: ");
			input(counts);
		}

		printa("╔════════════════════════════════════════════════════════╗");
		printa(format("║ {:^54} ║", "线路模块操作指南"));
		printa("╠══════════════════════════════╦═════════════════════════╣");
		printa(format("║ {:<{}} ║ {:<{}} ║", "条件", left, "剪断", right));
		printa("╠══════════════════════════════╬═════════════════════════╣");
		switch (counts) {
		case 3:
			printa(format("║ {:<{}} ║ {:<{}} ║", "红线 == 0", left, "2", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "last == 白线", left, "3", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "蓝线 > 1", left, "最后一根蓝线", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "其他", left, "3", right));
			break;
		case 4:
			if (info.odd) {
				printa(format("║ {:<{}} ║ {:<{}} ║", "红线 > 1", left, "最后一根红线", right));
			}
			printa(format("║ {:<{}} ║ {:<{}} ║", "红线 == 0 && last == 黄线", left, "1", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "蓝线 == 1", left, "1", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "黄线 > 1", left, "4", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "其他", left, "2", right));
			break;
		case 5:
			if (info.odd) {
				printa(format("║ {:<{}} ║ {:<{}} ║", "last == 黑线", left, "4", right));
			}
			printa(format("║ {:<{}} ║ {:<{}} ║", "红线 == 1 && 黄线 > 1", left, "1", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "黑线 == 0", left, "2", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "其他", left, "1", right));
			break;
		case 6:
			if (info.odd) {
				printa(format("║ {:<{}} ║ {:<{}} ║", "黄线 == 0", left, "3", right));
			}
			printa(format("║ {:<{}} ║ {:<{}} ║", "黄线 == 1 && 白线 > 1", left, "4", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "红线 == 0", left, "6", right));
			printa(format("║ {:<{}} ║ {:<{}} ║", "其他", left, "4", right));
			break;
		}
		printa("╚══════════════════════════════╩═════════════════════════╝");
	}
	
private:
	static constexpr int left = 28;
	static constexpr int right = 23;
};

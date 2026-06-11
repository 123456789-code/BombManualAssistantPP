#pragma once
#include <vector>
#include <string>
#include "mytool.h"

using std::pair, std::array, std::string_view, std::vector, std::string;
using namespace mytool;

#ifdef _DEBUG
#include <format>
using std::format_to, std::back_inserter;
#endif

constexpr inline int maze_size = 6;

class Maze {
private:
	static constexpr int size = maze_size;
	array<array<bool, size>, size - 1> rwall;
	array<array<bool, size - 1>, size> cwall;

public:
	constexpr Maze() noexcept : rwall{}, cwall{} {}
	constexpr Maze(
		array<array<bool, size>, size - 1> r,
		array<array<bool, size - 1>, size> c
	) noexcept : rwall(r), cwall(c) {}
	constexpr ~Maze() noexcept = default;

	constexpr bool is_wall(int r, int c, int direction) const {
		// direction: 0=上, 1=右, 2=下, 3=左
		switch (direction) {
		case 0:
			return r == 0 || rwall[r - 1][c];
		case 1:
			return c == size || cwall[r][c];
		case 2:
			return r == size - 1 || rwall[r][c];
		case 3:
			return c == 0 || cwall[r][c - 1];
		}
		return true;
	}

	static constexpr array<array<bool, size>, size - 1> buildr(string_view r) {
		array<array<bool, size>, size - 1> rwall{};
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size; j++) {
				rwall[i][j] = (r[i * (size + 1) + j] == '1');
			}
		}
		return rwall;
	}

	static constexpr array<array<bool, size - 1>, size> buildc(string_view c) {
		array<array<bool, size - 1>, size> cwall{};
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
				cwall[i][j] = (c[i * (size - 1 + 1) + j] == '1');
			}
		}
		return cwall;
	}
};

class Module10 { // 迷宫模块
public:
	static void main(const BombInfo& info) {
		int temp, type = 0;
		printa("其实，任意一个圈的坐标都足以确定迷宫结构");
		printa("接下来的坐标格式均为{行}{列}，以左上角为11");
		print("请输入一个圈的坐标: ");
		input(temp);
		while (true) {
			if (temp / 10 >= 7 || temp / 10 < 1 || temp % 10 > 6 || temp % 10 == 0) {
				print("行列均应在1到6之间，请重新输入: ");
				input(temp);
				continue;
			}
			type = table[temp];
			if (type == 0) {
				print("未找到对应的迷宫，请重新输入: ");
				input(temp);
				continue;
			}
			break;
		}
		print("该迷宫的类型是: ", type, "，接下来将输出对应的迷宫\n");
		printa(draw_maze(type - 1));
		print("请输入起点坐标: ");
		input(temp);
		while (temp / 10 >= 7 || temp / 10 < 1 || temp % 10 > 6 || temp % 10 == 0) {
			print("行列均应在1到6之间，请重新输入: ");
			input(temp);
		}
		pair<int, int> start = { static_cast<int>(temp / 10) - 1, static_cast<int>(temp % 10) - 1 };
		print("请输入终点坐标: ");
		input(temp);
		while (temp / 10 >= 7 || temp / 10 < 1 || temp % 10 > 6 || temp % 10 == 0) {
			print("行列均应在1到6之间，请重新输入: ");
			input(temp);
		}
		pair<int, int> end = { static_cast<int>(temp / 10) - 1, static_cast<int>(temp % 10) - 1 };
		printa("计算得到的路径为");
		printa(draw_maze(type - 1, solve(mazes[type - 1], start, end)));
#ifdef _DEBUG
		printa(output_path(solve(mazes[type - 1], start, end)));
#endif
	}

private:
	static constexpr int size = maze_size;

	static constexpr array<unsigned, 100> table = []() {
		array<unsigned, 100> arr{};
		arr[21] = 1; arr[36] = 1;
		arr[25] = 2; arr[42] = 2;
		arr[44] = 3; arr[46] = 3;
		arr[11] = 4; arr[41] = 4;
		arr[35] = 5; arr[64] = 5;
		arr[15] = 6; arr[53] = 6;
		arr[12] = 7; arr[62] = 7;
		arr[14] = 8; arr[43] = 8;
		arr[23] = 9; arr[51] = 9;
		return arr;
	}();

	static constexpr array<Maze, 9> mazes{{
		Maze(Maze::buildr("010011 001110 010010 011110 010010"), Maze::buildc("00100 10100 10100 10010 00101 01010")),
		Maze(Maze::buildr("101001 010110 001010 010100 000010"), Maze::buildc("00100 01010 10100 01011 11101 10100")),
		Maze(Maze::buildr("010000 100110 000000 000000 011000"), Maze::buildc("00110 11101 01101 11111 10111 00010")),
		Maze(Maze::buildr("001110 000110 011010 011110 011100"), Maze::buildc("01000 11000 10101 10000 00001 00101")),
		Maze(Maze::buildr("111100 011011 001100 011010 001110"), Maze::buildc("00000 00001 01010 10011 10001 10000")),
		Maze(Maze::buildr("000100 000010 011001 100000 011010"), Maze::buildc("10100 11101 01110 01011 01110 00010")),
		Maze(Maze::buildr("011000 001110 110100 000110 011100"), Maze::buildc("00010 10101 01010 01001 11001 00000")),
		Maze(Maze::buildr("001000 011110 001100 010111 001111"), Maze::buildc("10010 00101 10001 10100 11000 00000")),
		Maze(Maze::buildr("001100 000100 011010 000110 000001"), Maze::buildc("10000 11011 00101 11010 11101 01010"))
	}};

	static vector<pair<int, int>> solve(const Maze& maze, const pair<int, int>& start, const pair<int, int>& end) {
		vector<pair<int, int>> path;

		// 方向：上、右、下、左
		static constexpr array<pair<int, int>, 4> directions = {{
			{-1, 0}, {0, 1}, {1, 0}, {0, -1}
		}};

		// 从终点开始DFS
		//vector<vector<bool>> visited(size, vector<bool>(size, false));
		uint64_t visited = 0;
		auto dfs = [&](auto& self, int r, int c) {
			if (r == start.first && c == start.second) {
				path.emplace_back(r, c);
				return true;
			}
			visited |= (1ULL << (r * size + c));
			for (int dir = 0; dir < 4; dir++) {
				int nr = r + directions[dir].first;
				int nc = c + directions[dir].second;
				if (nr >= 0 && nr < size && nc >= 0 && nc < size && !maze.is_wall(r, c, dir) && !(visited & (1ULL << (nr * size + nc)))) {
					if (self(self, nr, nc)) {
						path.emplace_back(r, c);
						return true;
					}
				}
			}
			return false;
			};
		dfs(dfs, end.first, end.second);
		return path;
	}

#ifdef _DEBUG
	static string output_path(const vector<pair<int, int>>& path) {
		string result = "路径为: ";
		for (size_t i = 0; i < path.size() - 1; i++) {
			format_to(back_inserter(result), "({}, {}) -> ", path[i].first + 1, path[i].second + 1);
		}
		format_to(back_inserter(result), "({}, {})\n", path.back().first + 1, path.back().second + 1);
		return result;
	}
#endif

	static constexpr array<array<bool, 4 * size + 1>, 4 * size + 1> form_maze(unsigned type) {
		array<array<bool, 4 * size + 1>, 4 * size + 1> wall;
		// 初始全部设为空格
		for (int i = 0; i < 4 * size + 1; i++) {
			for (int j = 0; j < 4 * size + 1; j++) {
				wall[i][j] = 0;
			}
		}
		// 初始化迷宫边界
		for (int i = 0; i < 4 * size + 1; i++) {
			wall[0][i] = true;
			wall[4 * size][i] = true;
			wall[i][0] = true;
			wall[i][4 * size] = true;
		}
		// 设置格点
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				wall[4 * i][4 * j] = true;
			}
		}
		const Maze& maze = mazes[type];
		// 设置横墙
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size; j++) {
				if (maze.is_wall(i, j, 2)) {
					for (int k = 0; k < 4; k++) {
						wall[4 * (i + 1)][4 * j + 1 + k] = true;
					}
				}
			}
		}
		// 设置竖墙
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (maze.is_wall(i, j, 1)) {
					for (int k = 0; k < 4; k++) {
						wall[4 * i + 1 + k][4 * (j + 1)] = true;
					}
				}
			}
		}
		return wall;
	}

	static constexpr string draw_maze(unsigned type) { // 打印迷宫本身
		array<array<bool, 4 * size + 1>, 4 * size + 1> wall = form_maze(type);
		string maze_str;
		for (int i = 0; i < 4 * size + 1; i++) {
			for (int j = 0; j < 4 * size + 1; j++) {
				maze_str += wall[i][j] ? "██" : "  ";
			}
			maze_str += '\n';
		}
		return maze_str;
	}
	static constexpr string draw_maze(unsigned type, const vector<pair<int, int>>& path) { // 打印带路径的迷宫
		array<array<bool, 4 * size + 1>, 4 * size + 1> wall = form_maze(type);
		array<array<bool, 4 * size + 1>, 4 * size + 1> star;
		// 初始star
		for (int i = 0; i < 4 * size + 1; i++) {
			for (int j = 0; j < 4 * size + 1; j++) {
				star[i][j] = false;
			}
		}
		// 标记路径
		for (int i = 0; i < path.size(); i++) {
			int r = path[i].first;
			int c = path[i].second;
			star[4 * r + 2][4 * c + 2] = true;
			if (i < path.size() - 1) {
				int nr = path[i + 1].first;
				int nc = path[i + 1].second;
				if (nr == r - 1 && nc == c) { // 上
					star[4 * r + 1][4 * c + 2] = true;
					star[4 * r][4 * c + 2] = true;
					star[4 * r - 1][4 * c + 2] = true;
				}
				else if (nr == r + 1 && nc == c) { // 下
					star[4 * r + 3][4 * c + 2] = true;
					star[4 * r + 4][4 * c + 2] = true;
					star[4 * r + 5][4 * c + 2] = true;
				}
				else if (nr == r && nc == c - 1) { // 左
					star[4 * r + 2][4 * c + 1] = true;
					star[4 * r + 2][4 * c] = true;
					star[4 * r + 2][4 * c - 1] = true;
				}
				else if (nr == r && nc == c + 1) { // 右
					star[4 * r + 2][4 * c + 3] = true;
					star[4 * r + 2][4 * c + 4] = true;
					star[4 * r + 2][4 * c + 5] = true;
				}
			}
		}
		string maze_str;
		for (int i = 0; i < 4 * size + 1; i++) {
			for (int j = 0; j < 4 * size + 1; j++) {
				maze_str += wall[i][j] ? "██" : (star[i][j] ? "▓▓" : "  ");
			}
			maze_str += '\n';
		}
		return maze_str;
	}
};

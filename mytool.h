#pragma once
#include <iostream>
#include "ImageDisplay.h"

namespace mytool {
	template <typename T, typename ... others>
	constexpr void print(const T& t, const others& ... o) {
		std::cout << t;
		if constexpr (sizeof...(o) != 0) { print(o...); }
	}

	template <typename S1, typename S2, typename T, typename ... others>
	constexpr void prints(const S1& sep, const S2& end, const T& t, const others& ... o) {
		if constexpr (sizeof...(o) == 0) { std::cout << t << end; }
		else {
			std::cout << t << sep;
			prints(sep, end, o...);
		}
	}

	template <typename ... others>
	constexpr void printa(const others& ... o) {
		if constexpr (sizeof...(o) == 0) { std::cout << std::endl; }
		else { prints(" ", "\n", o...); }
		std::cout.flush();
	}

	template<typename T>
	bool input(T& value) {
		while (!(std::cin >> value)) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			print("输入无效，请重新输入: ");
		}
		return true;
	}

	inline bool show_image(int resourceId, const char* title = "Image Display", int timeoutMs = 0) {
		return ImageDisplay::showImage(resourceId, title, timeoutMs);
	}

	inline bool show_image(const char* resourceName, const char* title = "Image Display", int timeoutMs = 0) {
		return ImageDisplay::showImage(resourceName, title, timeoutMs);
	}

	inline void close_image() {
		ImageDisplay::closeImage();
	}

	inline bool is_image_showing() {
		return ImageDisplay::isShowing();
	}

	struct BombInfo {
		bool odd;
		bool aeiou;
		int  battery;
		bool parallel;
	};
}
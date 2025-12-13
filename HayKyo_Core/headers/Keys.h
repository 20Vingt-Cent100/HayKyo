#pragma once
#include "GLFW/glfw3.h"

namespace HayKyo_Core {
	static const enum STATE {
		PRESSED = 0,
		RELEASED = 1,
		HOLD = 2,

		UNKNOWN = -1
	};

	static const struct KEYS {
		int A = glfwGetKeyScancode(GLFW_KEY_A);
		int B = glfwGetKeyScancode(GLFW_KEY_B);
		int C = glfwGetKeyScancode(GLFW_KEY_C);
		int D = glfwGetKeyScancode(GLFW_KEY_D);
		int E = glfwGetKeyScancode(GLFW_KEY_E);
		int F = glfwGetKeyScancode(GLFW_KEY_F);
		int G = glfwGetKeyScancode(GLFW_KEY_G);
		int H = glfwGetKeyScancode(GLFW_KEY_H);
		int I = glfwGetKeyScancode(GLFW_KEY_I);
		int J = glfwGetKeyScancode(GLFW_KEY_J);
		int K = glfwGetKeyScancode(GLFW_KEY_K);
		int L = glfwGetKeyScancode(GLFW_KEY_L);
		int M = glfwGetKeyScancode(GLFW_KEY_M);
		int N = glfwGetKeyScancode(GLFW_KEY_N);
		int O = glfwGetKeyScancode(GLFW_KEY_O);
		int P = glfwGetKeyScancode(GLFW_KEY_P);
		int Q = glfwGetKeyScancode(GLFW_KEY_Q);
		int R = glfwGetKeyScancode(GLFW_KEY_R);
		int S = glfwGetKeyScancode(GLFW_KEY_S);
		int T = glfwGetKeyScancode(GLFW_KEY_T);
	};

	static const enum MOUSE_INPUT {
		LEFT_CLICK_BUTTON = 0,
		RIGHT_CLICK_BUTTON = 1,

		BUTTON_1 = 2,
		BUTTON_2 = 3,
		BUTTON_3 = 4,
		BUTTON_4 = 5,
		BUTTON_5 = 6,
		BUTTON_6 = 7,

		UNKNOWN_BUTTON = -1
	};
}
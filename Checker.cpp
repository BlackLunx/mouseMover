#include <Windows.h>
#include<random>
#include<time.h>
#include<iostream>

int main()
{
	srand(time(0));
	int end = 0, was = 0, seconds;
	while (true) {
		if (GetAsyncKeyState(VK_HOME)) //КНОПКА HOME - начало
			was = 1;
		if (GetAsyncKeyState(VK_END))  // КНОПКА END - конец
			was = 0;
		if (was) {
			mouse_event(MOUSEEVENTF_MOVE, rand() % 200 - 100, rand() % 200 - 100, 0, 0);
			mouse_event(MOUSEEVENTF_WHEEL, rand() % 200 - 100, 0, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
// Simulate a key release
			keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
		Sleep(1000);
	}
	return 0;
}

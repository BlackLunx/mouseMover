#include <Windows.h>
#include<random>
#include<time.h>
#include<iostream>

int main()
{
	srand(time(0));
	int end = 0, was = 0, seconds;
	while (!end) {
		if (GetAsyncKeyState(VK_HOME)) //КНОПКА HOME - начало
			was++;
		if (GetAsyncKeyState(VK_END))  // КНОПКА END - конец
			end++;
		if (was) {
			mouse_event(MOUSEEVENTF_MOVE, rand() % 200 - 100, rand() % 200 - 100, 0, 0);
			keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
// Simulate a key release
			keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
		}
		Sleep(11);
	}
	return 0;
}

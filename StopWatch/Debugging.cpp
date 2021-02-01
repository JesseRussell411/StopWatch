#include "Stopwatch.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;
using namespace JesseRussell::Diagnostics;

int main() {
	Stopwatch s;
	cout << s.getElapsedMilliseconds() << endl;
	s.start();
	this_thread::sleep_for(chrono::milliseconds(200));
	s.stop();
	cout << s.getElapsedMilliseconds() << endl;

	s.reset();
	s.start();
	this_thread::sleep_for(chrono::milliseconds(100));
	cout << s.getElapsedMilliseconds() << endl;

	s.restart();
	this_thread::sleep_for(chrono::milliseconds(300));
	cout << s.getElapsedMilliseconds() << endl;
	this_thread::sleep_for(chrono::milliseconds(400));
	cout << s.getElapsedMilliseconds() << endl;
	cout << s.isRunning() << endl;
}
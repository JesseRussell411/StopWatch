#pragma once
#include<chrono>
// Stopwatch class similar to C#'s stopwatch all the way down to the namespace.
namespace JesseRussell {
	namespace Diagnostics {
		class Stopwatch
		{
		private:
			std::chrono::steady_clock::time_point startTime, stopTime;
			bool running, ready;

		public:
			Stopwatch() {
				reset();
			}

			void start() {
				if (ready) {
					startTime = std::chrono::high_resolution_clock::now();
					ready = false;
				}
				running = true;
			}

			void stop() {
				if (running) {
					stopTime = std::chrono::high_resolution_clock::now();
					running = false;
				}
			}

			void reset() {
				running = false;
				ready = true;
			}

			void restart() {
				reset();
				start();
			}

			bool isRunning() { return running; }

			std::chrono::steady_clock::duration getElapsed() {
				if (running)
					return std::chrono::high_resolution_clock::now() - startTime;
				else if (ready)
					return std::chrono::steady_clock::duration::zero();
				else
					return stopTime - startTime;
			}

			long long getElapsedMilliseconds() {
				return std::chrono::duration_cast<std::chrono::milliseconds>(getElapsed()).count();
			}
		};
	}
}
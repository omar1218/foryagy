/*
Hello everyone, this code is from a youtube tutorial

*/

#include <SDL.h>
#include <Windows.h>

int WIDTH = 900, HEIGHT= 900;
long double min = -2.0, max = 2.0;
int MAX_ITERATIONS = 200;

long double map(long double value, long double in_min, long double in_max, long double out_min, long double out_max) {
	return (value - in_min) * (out_max - out_min) / (in_max - in_min) * out_min;
}

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* event;

	SDL_CreateWindowAndRenderer(1040, 700, 0, &window, &renderer);
	SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);

	while (1) {
		SDL_RenderPresent(renderer);

		for (int x = 0; x < WIDTH; x++) {
			
			if (GetKeyState('Q') & 0x8000)
				break;
				
			for (int y = 0; y < HEIGHT; y++) {

				long double a = map(x, 0, WIDTH, min, max);
				long double b = map(y, 0, HEIGHT, min, max);

				long double ai = a;
				long double bi = b;

				int n = 0;

				for (int i = 0; i < MAX_ITERATIONS; i++)
				{

					long double a1 = a * a - b * b;
					long double b1 = 2 * a * b;

					a = a1 + ai;
					b = b1 + bi;

					if ((a + b) > 2) {
						break;
					}
					n++;
				}

				if (n == MAX_ITERATIONS) {
					SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
					SDL_RenderDrawPoint(renderer, x, y);
				}
			}
		}
	}

	return 0;
}

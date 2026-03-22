#include "system/window.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* win = SDL_CreateWindow("SDL3 Project", 640, 480, 0);
    if (win == nullptr) {
        fprintf(stderr, "SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* ren = SDL_CreateRenderer(win, NULL);
    if (ren == nullptr) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare = {270, 190, 100, 100};

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_EVENT_QUIT: 
                quit = true;
                break;
            case SDL_EVENT_KEY_DOWN:
                fprintf(stdout, "%s: Pressed=%d\n", __func__, e.key.scancode);
                switch (e.key.scancode) {
                case SDL_SCANCODE_W: greenSquare.y -= 10; break;
                case SDL_SCANCODE_A: greenSquare.x -= 10; break;
                case SDL_SCANCODE_S: greenSquare.y += 10; break;
                case SDL_SCANCODE_D: greenSquare.x += 10; break;
                }
                break;
            default:
                fprintf(stderr, "%s: no events\n", __func__);
            }

        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(ren); // Clear the renderer

        SDL_SetRenderDrawColor(ren, 79, 255, 90, 255); // Set render draw color to green
        SDL_RenderFillRect(ren, &greenSquare); // Render the rectangle
        
        SDL_RenderPresent(ren); // Render the screen
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}    

#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

class Display
{
    public:
        Display(int width,int height,const std::string& title);
        void Clear(float r, float g,float b, float a);

        void Update();
        bool IsClosed();

        virtual ~Display();


    protected:

    private:
        Display(const Display& other){}
        //Display& operator=(const Display& other){}
        void operator=(const Display& other){}
        // need a private window here
        //I dont want to store the actual window in my dislay so i use a window pointer
        SDL_Window* m_window; //now we have a window that we created with sdl

        SDL_GLContext m_glContext;
        bool m_isClosed;
};

#endif // DISPLAY_H

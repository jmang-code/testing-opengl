#include "display.h"
#include <iostream>
#include <GL/glew.h>  //Put this in as one of final steps when we are ready to do opengl stuff

Display::Display(int width,int height,const std::string& title)
{
    //i ONLY use sdl for windowing purposes so the below code is safe here/you might want to do this in main if you use sdl for other purposes too
    // I initialize sdl below

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8); //2pow*8 )256 diff shades of red,number of bits used to display  red color,generally this number ok for most colors
    //the human eye absorbs about 256 shades of each color

    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);  //transparent color
     SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1); //allocate space for a second window where we can draw but it will not be displayed
     // so we have 32 bits of color data

     SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);   //how much data opengl will allocate for each pixel ,we set it to 32

     // sdl sayas it will give you at leat that many bits you have specified above
    m_window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_window);
    GLenum status = glewInit();
    if(status !=GLEW_OK)
    {
        std::cerr<<"Glew failed to initialize!"<<std::endl;
    }
   m_isClosed=false;
}

Display::~Display()
{   SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

}
void Display::Clear(float r, float g,float b, float a)
{
    glClearColor(r,g,b.a);
        glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::IsClosed()
{
    return m_isClosed;
}
void Display::Update()
{
    SDL_GL_SwapWindow(m_window);
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type==SDL_QUIT)
           m_isClosed=true;
    }

}


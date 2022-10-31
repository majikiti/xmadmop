#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(){

  Display *disp;
  Window winIdf;
  Font   fntIdf;
  GC     gbgClc;
  XEvent evn;

  unsigned long black, white;

  disp=XOpenDisplay(NULL);

  black=BlackPixel(disp, 0);
  white=WhitePixel(disp, 0);

  winIdf=XCreateSimpleWindow(disp, RootWindow(disp, 0), 50, 100, 800, 800, 1, black, white);

  XSelectInput(disp, winIdf, ExposureMask);

  XMapWindow(disp, winIdf);
  gbgClc=XCreateGC(disp, winIdf, 0, 0);

  while(1){
    XNextEvent(disp, &evn);
    switch(evn.type){
      case Expose:
        // fntIdf=XLoadFont(disp, "variable");
        // XSetFont(disp, gbgClc, fntIdf);

        XSetForeground(disp, gbgClc, black);
        XDrawString(disp, winIdf, gbgClc, 400, 200, "Hello, X11!!", 13);

        XFlush(disp);
    }
  }
}

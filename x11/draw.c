#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main(void)
{
	Display *display;
	Window parent;
	register int x;
	register int y;
	unsigned int width;
	unsigned int height;
	unsigned int border_width;
	int screen_number;
	int depth;
	unsigned int class;
	Visual *visual;
	unsigned long valuemask;
	XSetWindowAttributes attributes;
	Window window;
	XEvent event_return;
	GC gc;

	display = XOpenDisplay(NULL);
	if (!display)
	{
		fprintf(stderr, "\"XOpenDisplay\" does not succeed.\n");
		exit(1);
	}

	parent = DefaultRootWindow(display);
	x = 0;
	y = 0;
	width = 100;
	height = 100;
	border_width = 0;
	screen_number = DefaultScreen(display);
	depth = DefaultDepth(display, screen_number);
	class = InputOutput;
	visual = DefaultVisual(display, screen_number);
	valuemask = CWBackPixel | CWBorderPixel | CWEventMask;
	attributes.background_pixel = WhitePixel(display, screen_number);
	attributes.border_pixel = BlackPixel(display, screen_number);
	attributes.event_mask = ButtonPressMask | ButtonMotionMask |
		KeyPressMask;
	gc = DefaultGC(display, screen_number);

	window = XCreateWindow(display, parent, x, y, width, height,
			border_width, depth, class, visual, valuemask,
			&attributes);
	
	XStoreName(display, window, "Drawing...");
	XMapRaised(display, window);

	fprintf(stdout, "window id: %ld\n"
			"x: %d\n"
			"y: %d\n"
			"width: %u\n"
			"height: %u\n"
			"border_width: %u\n"
			"screen_number: %d\n"
			"depth: %d\n"
			"class: %u\n"
			"valuemask: %lu\n",
		window, x, y, width, height, border_width, screen_number, depth,
		class, valuemask);

	while (1) {
		XNextEvent(display, &event_return);
		x = event_return.xbutton.x;
		y = event_return.xbutton.y;
		printf("x: %d y: %d\n", x, y);
		switch (event_return.type) {
		case ButtonPress:
		case MotionNotify:
			XDrawPoint(display, window, gc, x, y);
			break;
		case KeyPress:
			XUnmapWindow(display, window);
			XDestroyWindow(display, window);
			XFreeGC(display, gc);
			exit(0);
		}
	}
}

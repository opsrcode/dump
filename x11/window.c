#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

/*
 * Window XCreateWindow(Display *display, Window parent, int x, int y,
 * 	unsigned int width, unsigned int height, unsigned int border_width,
 * 	int depth, unsigned int class, Visual *visual, unsigned long valuemask,
 * 	XSetWindowAttributes * attributes);
 */

int main(void)
{
	Display *display;
	Window parent;
	int x;
	int y;
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

	display = XOpenDisplay(NULL); /* DISPLAY environment variable */
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
	class = InputOutput; /* InputOutput, InputOnly, CopyFromParent */
	visual = DefaultVisual(display, screen_number);
	valuemask = CWBackPixel | CWBorderPixel;
	attributes.background_pixel = WhitePixel(display, screen_number);
	attributes.border_pixel = BlackPixel(display, screen_number);

	window = XCreateWindow(display, parent, x, y, width, height,
			border_width, depth, class, visual, valuemask,
			&attributes);
	
	XRaiseWindow(display, window);
	XMapWindow(display, window);
	XFlush(display);

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

	getchar();
	
	XUnmapWindow(display, window);
	XDestroyWindow(display, window);
	exit(0);
}

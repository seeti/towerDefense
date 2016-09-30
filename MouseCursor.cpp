#include "MouseCursor.h"

#ifdef SFML_SYSTEM_WINDOWS

MouseCursor::MouseCursor(const MouseCursor::TYPE t)
{
	switch (t)
	{
	case MouseCursor::WAIT:
		Cursor = LoadCursor(NULL, IDC_WAIT);
		break;
	case MouseCursor::HAND:
		Cursor = LoadCursor(NULL, IDC_HAND);
		break;
	case MouseCursor::NORMAL:
		Cursor = LoadCursor(NULL, IDC_ARROW);
		break;
	case MouseCursor::TEXT:
		Cursor = LoadCursor(NULL, IDC_IBEAM);
		break;
		//For more cursor options on Windows go here:
		// http://msdn.microsoft.com/en-us/library/ms648391%28v=vs.85%29.aspx
	}
}

void MouseCursor::set(const sf::WindowHandle& aWindowHandle) const
{
	SetClassLongPtr(aWindowHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
}

MouseCursor::~MouseCursor()
{
	// Nothing to do for destructor :
	// no memory has been allocated (shared ressource principle)
}

#elif defined(SFML_SYSTEM_LINUX)

MouseCursor::MouseCursor(const MouseCursor::TYPE t)
{
	display = XOpenDisplay(NULL);

	switch (t)
	{
	case MouseCursor::WAIT:
		Cursor = XCreateFontCursor(display, XC_watch);
		break;
	case MouseCursor::HAND:
		Cursor = XCreateFontCursor(display, XC_hand1);
		break;
	case MouseCursor::NORMAL:
		Cursor = XCreateFontCursor(display, XC_left_ptr);
		break;
	case MouseCursor::TEXT:
		Cursor = XCreateFontCursor(display, XC_xterm);
		break;
		// For more cursor options on Linux go here:
		// http://www.tronche.com/gui/x/xlib/appendix/b/
	}
}

void MouseCursor::set(const sf::WindowHandle& aWindowHandle) const
{
	XDefineCursor(display, aWindowHandle, Cursor);
	XFlush(display);
}

MouseCursor::~MouseCursor()
{
	XFreeCursor(display, Cursor);
	delete display;
	display = NULL;
}

#else
#error This OS is not yet supported by the cursor library.
#endif

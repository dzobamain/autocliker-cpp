#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#elif __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#elif __linux__
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
#include <stdio.h>
#else
#error "Unsupported platform"
#endif

#include <Autocliker.h>

void Autocliker::StartClickingAtCursor(int number_of_clicks, const int &delay_between_clicks, const int &click_execution_time, const int &time_to_start)
{
    std::this_thread::sleep_for(std::chrono::seconds(time_to_start));
    auto startTime = std::chrono::steady_clock::now();
    int clicks_done = 0;

    while (true)
    {
        if (clicks_done >= number_of_clicks)
            break;

        this->ClickAreaAtCursor();
        clicks_done++;

        std::this_thread::sleep_for(std::chrono::milliseconds(delay_between_clicks));

        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::steady_clock::now() - startTime
        ).count();

        if (elapsed >= click_execution_time)
            break;
    }
}

// Click at cursor
#ifdef _WIN32
void Autocliker::ClickAreaAtCursor()
{
    POINT p;
    if (GetCursorPos(&p))
    {
        mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
    }
}

#elif __APPLE__
void Autocliker::ClickAreaAtCursor()
{
    CGEventRef ourEvent = CGEventCreate(NULL);
    CGPoint point = CGEventGetLocation(ourEvent);
    CFRelease(ourEvent);

    CGEventRef click_down = CGEventCreateMouseEvent(NULL, kCGEventLeftMouseDown, point, kCGMouseButtonLeft);
    CGEventRef click_up = CGEventCreateMouseEvent(NULL, kCGEventLeftMouseUp, point, kCGMouseButtonLeft);

    CGEventPost(kCGHIDEventTap, click_down);
    CGEventPost(kCGHIDEventTap, click_up);

    CFRelease(click_down);
    CFRelease(click_up);
}

#elif __linux__
void Autocliker::ClickAreaAtCursor()
{
    Display *display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "Unable to open X display\n");
        return;
    }

    XTestFakeButtonEvent(display, 1, True, CurrentTime);
    XFlush(display);

    XTestFakeButtonEvent(display, 1, False, CurrentTime);
    XFlush(display);

    XCloseDisplay(display);
}
#endif

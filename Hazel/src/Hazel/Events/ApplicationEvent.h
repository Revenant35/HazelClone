#pragma once

#include "Event.h"

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

namespace Hazel {
    
    class HAZEL_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class HAZEL_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}

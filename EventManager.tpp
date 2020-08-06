#include "EventManager.hpp"
#include "EventPayload.hpp"
#include "EventType.hpp"
#include "Vector.hpp"

#include <functional>
#include <map>

void subscribe(EventType eventType, THandler handler)
{
    //add the handler int he handler map
    if (!m_handlers.contains(eventType))
    {
        m_handlers[eventType] = {};
    }

    m_handlers[eventType].push_back(handler);
}

void fire(EventType eventType, EventPayload payload)
{
    for (auto& handler : m_handlers[eventType])
    {
        handler(payload);
    }
}
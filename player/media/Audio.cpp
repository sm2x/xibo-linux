#include "Audio.hpp"

#include "IAudioHandler.hpp"
#include "MediaVisitor.hpp"
#include "utils/Logger.hpp"

namespace ph = std::placeholders;

Audio::Audio(int id, const FilePath& path, std::unique_ptr<IAudioHandler>&& handler) :
    Media(id), m_handler(std::move(handler))
{
    assert(m_handler);

    m_handler->load(path);
    m_handler->connect(std::bind(&Audio::onAudioFinished, this));
}

void Audio::play()
{
    m_handler->play();
}

void Audio::stop()
{
    m_handler->stop();
}

void Audio::apply(MediaVisitor& visitor)
{
    visitor.visit(*this);
}

void Audio::onAudioFinished()
{
    if(m_looped)
    {
        Log::debug("Looping enabled. Restarting...");
        m_handler->play();
    }
}

void Audio::setVolume(int volume)
{
    m_handler->setVolume(volume);
}

void Audio::setLooped(bool looped)
{
    m_looped = looped;
}

bool Audio::looped() const
{
    return m_looped;
}

void Audio::handleEvent(const Event& ev)
{
    switch(ev.type())
    {
        case EventType::StartMedia:
            play();
            break;
        case EventType::DurationExpired:
        case EventType::StopMedia:
            stop();
            break;
        default:
            break;
    }
}



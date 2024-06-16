#ifndef SIGNAL_H
#define SIGNAL_H

#include <functional>
#include <vector>
#include <algorithm>
#include <utility>

template<typename... Args>
class Signal {
public:
    using CallbackType = std::function<void(Args...)>;

    // Connect a callback to the signal
    void connect(const CallbackType& callback);

    // Emit the signal, calling all connected callbacks with arguments
    void emit(Args... args) const;

    // Disconnect a specific callback from the signal
    void disconnect(const CallbackType& callback);

private:
    std::vector<CallbackType> callbacks;
};

#endif // SIGNAL_H

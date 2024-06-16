#include "Signal.h"

template<typename... Args>
void Signal<Args...>::connect(const CallbackType& callback) {
    callbacks.push_back(callback);
}

template<typename... Args>
void Signal<Args...>::emit(Args... args) const {
    for (const auto& callback : callbacks) {
        callback(std::forward<Args>(args)...);
    }
}

template<typename... Args>
void Signal<Args...>::disconnect(const CallbackType& callback) {
    callbacks.erase(std::remove(callbacks.begin(), callbacks.end(), callback), callbacks.end());
}

// // example usage
// class Button {
// public:
//     // Define a signal for the button pressed event with parameters
//     Signal<int, const std::string&> pressed;

//     // Method to simulate the button being pressed
//     void press(int id, const std::string& name) {
//         std::cout << "Button pressed!\n";
//         pressed.emit(id, name);
//     }
// };

// class Receiver {
// public:
//     void onButtonPressed(int id, const std::string& name) {
//         std::cout << "Receiver received the button press signal. ID: " << id << ", Name: " << name << "\n";
//     }
// };

// int main() {
//     Button button;
//     Receiver receiver;

//     // Connect the receiver's method to the button's pressed signal
//     button.pressed.connect(std::bind(&Receiver::onButtonPressed, &receiver, std::placeholders::_1, std::placeholders::_2));

//     // Simulate button press
//     button.press(1, "TestButton");

//     return 0;
// }

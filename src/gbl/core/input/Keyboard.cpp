//GameBaseLibrary Includes
#include <core/input/Keyboard.hpp>

namespace gbl {
    namespace core {
        std::map<Keyboard::Key, SDL_Keycode> Keyboard::m_keys = {
            {Keyboard::Key::Num0, SDLK_0},
            {Keyboard::Key::Num1, SDLK_1},
            {Keyboard::Key::Num2, SDLK_2},
            {Keyboard::Key::Num3, SDLK_3},
            {Keyboard::Key::Num4, SDLK_4},
            {Keyboard::Key::Num5, SDLK_5},
            {Keyboard::Key::Num6, SDLK_6},
            {Keyboard::Key::Num7, SDLK_7},
            {Keyboard::Key::Num8, SDLK_8},
            {Keyboard::Key::Num9, SDLK_9},
            {Keyboard::Key::Escape, SDLK_ESCAPE},
            {Keyboard::Key::LeftControl, SDLK_LCTRL},
            {Keyboard::Key::LeftShift, SDLK_LSHIFT},
            {Keyboard::Key::LeftAlt, SDLK_LALT},
            {Keyboard::Key::LeftSystem, SDLK_LGUI},
            {Keyboard::Key::RightControl, SDLK_RCTRL},
            {Keyboard::Key::RightShift, SDLK_RSHIFT},
            {Keyboard::Key::RightAlt, SDLK_RALT},
            {Keyboard::Key::RightSystem, SDLK_RGUI},
            {Keyboard::Key::Menu, SDLK_MENU},
            {Keyboard::Key::LeftBracket, SDLK_LEFTBRACKET},
            {Keyboard::Key::RightBracket, SDLK_RIGHTBRACKET},
            {Keyboard::Key::Semicolon, SDLK_SEMICOLON},
            {Keyboard::Key::Comma, SDLK_COMMA},
            {Keyboard::Key::Period, SDLK_PERIOD},
            {Keyboard::Key::Quote, SDLK_QUOTE},
            {Keyboard::Key::Slash, SDLK_SLASH},
            {Keyboard::Key::Backslash, SDLK_BACKSLASH},
            {Keyboard::Key::Tilde, SDLK_KP_VERTICALBAR},
            {Keyboard::Key::Equal, SDLK_EQUALS},
            {Keyboard::Key::Hyphen, SDLK_MINUS},
            {Keyboard::Key::Space, SDLK_SPACE},
            {Keyboard::Key::Enter, SDLK_RETURN},
            {Keyboard::Key::Backspace, SDLK_BACKSPACE},
            {Keyboard::Key::Tab, SDLK_TAB},
            {Keyboard::Key::PageUp, SDLK_PAGEUP},
            {Keyboard::Key::PageDown, SDLK_PAGEDOWN},
            {Keyboard::Key::End, SDLK_END},
            {Keyboard::Key::Home, SDLK_HOME},
            {Keyboard::Key::Insert, SDLK_INSERT},
            {Keyboard::Key::Delete, SDLK_DELETE},
            {Keyboard::Key::Add, SDLK_KP_PLUS},
            {Keyboard::Key::Substract, SDLK_KP_MINUS},
            {Keyboard::Key::Multiply, SDLK_KP_MULTIPLY},
            {Keyboard::Key::Divide, SDLK_KP_DIVIDE},
            {Keyboard::Key::Left, SDLK_LEFT},
            {Keyboard::Key::Right, SDLK_RIGHT},
            {Keyboard::Key::Up, SDLK_UP},
            {Keyboard::Key::Down, SDLK_DOWN},
            {Keyboard::Key::A, SDLK_a},
            {Keyboard::Key::B, SDLK_b},
            {Keyboard::Key::C, SDLK_c},
            {Keyboard::Key::D, SDLK_d},
            {Keyboard::Key::E, SDLK_e},
            {Keyboard::Key::F, SDLK_f},
            {Keyboard::Key::G, SDLK_g},
            {Keyboard::Key::H, SDLK_h},
            {Keyboard::Key::I, SDLK_i},
            {Keyboard::Key::J, SDLK_j},
            {Keyboard::Key::K, SDLK_k},
            {Keyboard::Key::L, SDLK_l},
            {Keyboard::Key::M, SDLK_m},
            {Keyboard::Key::N, SDLK_n},
            {Keyboard::Key::O, SDLK_o},
            {Keyboard::Key::P, SDLK_p},
            {Keyboard::Key::Q, SDLK_q},
            {Keyboard::Key::R, SDLK_r},
            {Keyboard::Key::S, SDLK_s},
            {Keyboard::Key::T, SDLK_t},
            {Keyboard::Key::U, SDLK_u},
            {Keyboard::Key::V, SDLK_v},
            {Keyboard::Key::W, SDLK_w},
            {Keyboard::Key::X, SDLK_x},
            {Keyboard::Key::Y, SDLK_y},
            {Keyboard::Key::Z, SDLK_z},
            {Keyboard::Key::Numpad0, SDLK_KP_0},
            {Keyboard::Key::Numpad1, SDLK_KP_1},
            {Keyboard::Key::Numpad2, SDLK_KP_2},
            {Keyboard::Key::Numpad3, SDLK_KP_3},
            {Keyboard::Key::Numpad4, SDLK_KP_4},
            {Keyboard::Key::Numpad5, SDLK_KP_5},
            {Keyboard::Key::Numpad6, SDLK_KP_6},
            {Keyboard::Key::Numpad7, SDLK_KP_7},
            {Keyboard::Key::Numpad8, SDLK_KP_8},
            {Keyboard::Key::Numpad9, SDLK_KP_9},
            {Keyboard::Key::F1, SDLK_F1},
            {Keyboard::Key::F2, SDLK_F2},
            {Keyboard::Key::F3, SDLK_F3},
            {Keyboard::Key::F4, SDLK_F4},
            {Keyboard::Key::F5, SDLK_F5},
            {Keyboard::Key::F6, SDLK_F6},
            {Keyboard::Key::F7, SDLK_F7},
            {Keyboard::Key::F8, SDLK_F8},
            {Keyboard::Key::F9, SDLK_F9},
            {Keyboard::Key::F10, SDLK_F10},
            {Keyboard::Key::F11, SDLK_F11},
            {Keyboard::Key::F12, SDLK_F12}
        };

        Keyboard::Key Keyboard::getKeycodeFromSDLKeycode(const SDL_Keycode& code)
        {
            for (auto it = Keyboard::m_keys.begin(); it != Keyboard::m_keys.end(); ++it)
                if (it->second == code)
                    return it->first;
            return Keyboard::Key::Unknown;
        }

        std::string Keyboard::getKeyName(Key key)
        {
            return getKeyNameFromSDLKeycode(m_keys[key]);
        }

        std::string Keyboard::getKeyNameFromSDLKeycode(const SDL_Keycode& code)
        {
            return SDL_GetKeyName(code);
        }
    }
}
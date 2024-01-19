#pragma once

#include <string>
#include <vector>
#include <stack>
#include <functional>
#include <exception>

// Stephan Baumann

namespace GenericInterpreter {
    template<typename T>
    T convertString(const std::string& s) {
        throw "Type not supported";
        return T();
    }

    // TODO: Aufgabe 2a) Deklarieren Sie hier alle spezialisierten Implementationen von convertString()

    template<>
    inline int convertString<int>(const std::string& s) {
        return std::stoi(s);
    }

    template<>
    inline long long convertString<long long>(const std::string& s) {
        return std::stoll(s);
    }

    template<>
    inline double convertString<double>(const std::string& s) {
        return std::stod(s);
    }

    template<>
    inline float convertString<float>(const std::string& s) {
        return std::stof(s);
    }

    // TODO: Aufgabe 2c) & 3b) Deklariere Sie hier alle Concepts

    template<typename T>
    concept Addable = requires(T a, T b) {
        a + b;
    };

    template<typename T>
    concept Subtractable = requires(T a, T b) {
        a - b;
    };

    template<typename T>
    concept Multiplyable = requires(T a, T b) {
        a * b;
    };

    template<typename T>
    concept Divideable = requires(T a, T b) {
        a / b;
    };

    template<typename T>
    concept Computable = (Addable<T> && Subtractable<T> && Multiplyable<T> && Divideable<T>);

    // TODO: Aufgabe 3c) Deklariere Sie hier den Funktor increment

    template <Computable T>
    class PostfixInterpreter {
        // TODO: Aufgabe 2b) Definieren Sie hier die notwendige Datenstruktur

        std::stack<std::string> stk;

        // TODO: Aufgabe 3a) Definieren Sie hier die Hilfsmethode apply()

        template<Computable T, typename Func>
        void apply(Func f) {
            const auto rhs = convertString<T>(stk.top());
            stk.pop();
            const auto lhs = convertString<T>(stk.top());
            stk.pop();
            stk.push(std::to_string(Func(lhs, rhs)));
        };

    public:
        /// <summary>
        /// Postfix interpretation of arithmetic expressions.
        /// Throws an exception if list of tokens isn't valid.
        /// </summary>
        /// <param name="tokens">list of tokens</param>
        /// <returns>result</returns>
        T evaluate(const std::vector<std::string>& tokens) {
            // TODO: Aufgabe 2b) Berechnen Sie den Wert des Ausdrucks

            int len = tokens.size();

            for (int i = 0; i < len; ++i) {

                if (tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-") {
                    stk.push(tokens[i]);
                }
                else {
                    const auto rhs = convertString<T>(stk.top());
                    stk.pop();
                    const auto lhs = convertString<T>(stk.top());
                    stk.pop();

                    if (tokens[i] == "+") {
                        stk.push(std::to_string(lhs + rhs));
                    }
                    else if (tokens[i] == "-") {
                        stk.push(std::to_string(lhs - rhs));
                    }
                    else if (tokens[i] == "*") {
                        stk.push(std::to_string(lhs * rhs));
                    }
                    else if (tokens[i] == "/") {
                        stk.push(std::to_string(lhs / rhs));
                    }
                    else {
                        throw std::exception("Wrong operator token");
                    }
                }

            }
            if (stk.size() > 1) {
                throw std::exception("Format error");
            }
            return convertString<T>(stk.top());
        }
    };
}

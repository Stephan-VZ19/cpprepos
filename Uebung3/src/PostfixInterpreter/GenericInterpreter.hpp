#pragma once

#include <string>
#include <vector>
#include <stack>
#include <functional>
#include <exception>

// Ihr Name

namespace GenericInterpreter {
    template<typename T>
    T convertString(const std::string& s) {
        throw "Type not supported";
        return T();
    }

    // TODO: Aufgabe 2a) Deklarieren Sie hier alle spezialisierten Implementationen von convertString()

    // TODO: Aufgabe 2c) & 3b) Deklariere Sie hier alle Concepts

    // TODO: Aufgabe 3c) Deklariere Sie hier den Funktor increment

    template <typename T>
    class PostfixInterpreter {
        // TODO: Aufgabe 2b) Definieren Sie hier die notwendige Datenstruktur

        // TODO: Aufgabe 3a) Definieren Sie hier die Hilfsmethode apply()

    public:
        /// <summary>
        /// Postfix interpretation of arithmetic expressions.
        /// Throws an exception if list of tokens isn't valid.
        /// </summary>
        /// <param name="tokens">list of tokens</param>
        /// <returns>result</returns>
        T evaluate(const std::vector<std::string>& tokens) {
            // TODO: Aufgabe 2b) Berechnen Sie den Wert des Ausdrucks
            return T();
        }
    };
}

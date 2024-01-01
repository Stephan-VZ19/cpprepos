#pragma once

#include <string>
#include <vector>
#include <stack>
#include <functional>
#include <exception>

// Ihr Name

namespace VariadicInterpreter {

    template <typename T>
    class PostfixInterpreter {
        // TODO: Deklarieren Sie die notwendigen Datenstrukturen und Hilfsmethoden.

    public:
        /// <summary>
        /// Postfix interpretation of arithmetic expressions.
        /// </summary>
        /// <param name="tokens">list of tokens</param>
        /// <returns>result</returns>
        template<typename... Args>
        T evaluate(const Args&... tokens) {
            // TODO: Berechnen Sie den Wert des Ausdrucks
            return T();
        }
    };
}

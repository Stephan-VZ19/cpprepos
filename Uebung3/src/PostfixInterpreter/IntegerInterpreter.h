#pragma once

#include <string>
#include <vector>
#include <stack>
#include <exception>


// Ihr Name

namespace IntegerInterpreter {
    class PostfixInterpreter {
        // TODO: Aufgabe 1) Definieren Sie hier die notwendige Datenstrukturen

    public:
        /// <summary>
        /// Postfix interpretation of arithmetic expressions.
        /// Throws an exception if list of tokens isn't valid.
        /// </summary>
        /// <param name="tokens">list of tokens</param>
        /// <returns>result</returns>
        int evaluate(const std::vector<std::string>& tokens) {
            // TODO: Aufgabe 1) Berechnen Sie den Wert des Ausdrucks
            int len = tokens.size();
        
            if (len < 3) throw std::exception("Smaller than 3 tokens");

            return 0;
        }
    };
}

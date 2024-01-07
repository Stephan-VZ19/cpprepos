#pragma once

#include <string>
#include <vector>
#include <stack>
#include <exception>


// Stephan Baumann

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
            std::stack<std::string> stk;

            for (int i = 0; i < len; ++i) {

                if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                    stk.push(tokens[i]);
                }
                else {
                    int rhs = std::stoi(stk.top());
                    stk.pop();
                    int lhs = std::stoi(stk.top());
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
            if (stk.size() > 1) throw std::exception("Format error");
            return std::stoi(stk.top());
        }
    };
}

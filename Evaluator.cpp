//
// Created by Caleb on 9/27/18.
//

//Probably going to consolidate evaluation to parser class because it's not storing any information not in Parser already -Landon

#include "Evaluator.h"
#include <stack>
#include <string>
#include <cmath>

bool Evaluator::isOperand(char opr) {
    return (opr == '+' || opr == '-' || opr == '*' || opr == '/');
}

//int Evaluator::evaluate(std::string exp) {
//    // This function evaluates simple expressions. It returns -1 if the
//    // given expression is invalid.
//    // source: https://www.geeksforgeeks.org/program-evaluate-simple-expressions/
//
//    // Base Case: Given expression is empty
//    if (exp.empty())  return -1;
//
//    // The first character must be an operand, find its value
//    auto res = static_cast<int>(exp[0]);
//
//    // Traverse the remaining characters in pairs
//    for (int i = 1; exp[i]; i += 2)
//    {
//        // The next character must be an operator, and
//        // next to next an operand
//        char opr = exp[i], opd = exp[i+1];
//
//        // If next to next character is not an operand
//        if (!isOperand(opd))  return -1;
//
//        // Update result according to the operator
//        if (opr == '+')       res += static_cast<int>(opd);
//        else if (opr == '-')  res -= static_cast<int>(opd);
//        else if (opr == '*')  res *= static_cast<int>(opd);
//        else if (opr == '/')  res /= static_cast<int>(opd);
//
//            // If not a valid operator
//        else                  return -1;
//    }
//    return res;
//}

int Evaluator::evaluate(std::stack<int>* numStack, std::stack<std::string>* opStack) {
    int result;

    if (opStack->top() == "++") {
        int oper1 = numStack->top();
        numStack->pop();
        result = oper1++;
        numStack->push(result);
        opStack->pop();
        return result;
    } else if (opStack->top() == "--") {
        int oper1 = numStack->top();
        numStack->pop();
        int result = oper1--;
        numStack->push(result);
        opStack->pop();
        return result;
    } else if (opStack->top() == "/") {
        int oper2 = numStack->top();
        numStack->pop();
        int oper1 = numStack->top();
        numStack->pop();
        if (oper2 == 0) {
            throw "You cannot divide by 0!";
        } else {
            result = oper1 / oper2;
        }
        opStack->pop();
        return result;
    }
    else {
        int oper2 = numStack->top();
        numStack->pop();
        int oper1 = numStack->top();
        numStack->pop();

        if (opStack->top() == "-") result = oper1 - oper2;
        if (opStack->top() == "*") result = oper1 * oper2;
        if (opStack->top() == "+") result = oper1 + oper2;
        if (opStack->top() == "%") result = oper1 % oper2;
        if (opStack->top() == "^") result = pow(oper1, oper2);
        if (opStack->top() == "<=") result = (oper1 <= oper2);
        if (opStack->top() == "<") result = (oper1 < oper2);
        if (opStack->top() == ">=") result = (oper1 >= oper2);
        if (opStack->top() == ">") result = (oper1 > oper2);
        if (opStack->top() == "!=") result = (oper1 != oper2);
        if (opStack->top() == "==") result = (oper1 == oper2);
        if (opStack->top() == "&&") result = (oper1 && oper2);
        if (opStack->top() == "||") result = (oper1 || oper2);

        numStack->push(result);
        opStack->pop();
        return result;
    }
}

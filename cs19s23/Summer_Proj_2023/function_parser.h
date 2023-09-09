  // **
  // Creator: Massimo Ginella (massimoginella12@gmail.com)
  // This header file is designed to provide functions for the folder pro_main.cpp
  // This file handles most of the computations associated with pro_main.cpp and 
  // is responsible for the calculation of parsing functions and calculating all three 
  // rules.
  // **


#ifndef FUNCTION_PARSER_H_
#define FUNCTION_PARSER_H_

#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cmath>

namespace par {

    bool poly_check (std::string poly) {  // i think this works ok
        for (int i = 0; i < poly.size(); i++) {
            while (poly[i] >= '0' && poly[i] <= '9') {
                i++;
            }
            if (poly[i] != 'x') {
                return false;
            }
            i++;
            if (poly[i] != '^') {
                return false;
            }
            i++;
            while (poly[i] >= '0' && poly[i] <= '9') {
                if (i == poly.size() - 1) {
                     return true;
                }
                i++;
            }
            if (poly[i] == ' ') {
                i++;
                if (poly[i] == '+' || poly[i] == '-') {
                    i++;
                }
                if (poly[i] != ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    bool limit_check (std::string a, std::string b) {
        for (int i = 0; i < a.size(); i++) {
            if (!isdigit(a[i])) {
                return false;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (!isdigit(b[i])) {
                return false;
            }
        }
        if (stoi(a) > stoi(b)) {
            return false;
        }
        return true;
    }

    double simpsons (std::string function, double delta_x, std::string a, std::string b) {
        std::vector<double> plug_ins;
        double limit_b = stod(b);
        double limit_a = stod(a);
        bool check = false;

        while (!check) {  // increase the nums to plug in by the delta_x until it has exceeded limit_b
            if (limit_a > limit_b) {
                check = true;
            } else {
                plug_ins.push_back(limit_a);
            }
            limit_a += delta_x;
        }

        std::vector<double> multipliers;
        std::vector<double> exponents;
        std::string str_multiplier;
        std::string str_exponent;
        std::string sign_pattern;
        for (int i = 0; i < function.size(); i++) {  // fishes for exp, mult, +, -
            if (function[i] == '+' || function[i] == '-') {
                sign_pattern += function[i];
            }
            if (function[i] >= '0' && function[i] <= '9') {
                while (function[i] >= '0' && function[i] <= '9') {
                    str_multiplier += function[i];
                    i++;
                }
                if (sign_pattern.back() == '-') {
                    multipliers.push_back(-stod(str_multiplier));
                    str_multiplier = "";
                } else {
                    multipliers.push_back(stod(str_multiplier));
                    str_multiplier = "";
                }
            }
            if (function[i] == '^') {
                i++;
                while (function[i] >= '0' && function[i] <= '9') {
                    str_exponent += function[i];
                    i++;
                }
                exponents.push_back(stod(str_exponent));
                str_exponent = "";
            }
        }

        std::vector<double> results;
        std::vector<double> function_sim;
        double pemdas = 0;
        for (int i = 0; i < plug_ins.size(); i++) {
            for (int k = 0; k < multipliers.size(); k++) {
                function_sim.push_back(multipliers[k] * pow(plug_ins[i], exponents[k]));
            }
            for (auto j : function_sim) {
                pemdas += j;
            }
            results.push_back(pemdas);
            function_sim.clear();
            pemdas = 0;
        }

        double final_answer = 0;
        for (int i  = 0; i < results.size(); i++) {
            if (i == 0 || i == results.size() - 1) {
                final_answer += results[i];
            } else if (i % 2 == 0) {
                final_answer += 2*results[i];
            } else {
                final_answer += 4* results[i];
            }
        }

        return final_answer * (delta_x / 3.0);
    }

    double trapezoidal (std::string function, double delta_x, std::string a, std::string b) {
        std::vector<double> plug_ins;
        double limit_b = stod(b);
        double num = stod(a);
        bool check = false;

        while (!check) {  // increase the nums to plug in by the delta_x until it has exceeded limit_b
            if (num > limit_b) {
                check = true;
            } else {
                plug_ins.push_back(num);
            }
            num += delta_x;
        }

        // maybe create a class that can handle these two vectors.
        std::vector<double> multipliers;  // throw this vector into function.
        std::vector<double> exponents;  // throw this vector into function.
        std::string str_multiplier;
        std::string str_exponent;
        std::string sign_pattern;
        for (int i = 0; i < function.size(); i++) {  // fishes for exp, mult, +, -
            if (function[i] == '+' || function[i] == '-') {
                sign_pattern += function[i];
            }
            if (function[i] >= '0' && function[i] <= '9') {
                while (function[i] >= '0' && function[i] <= '9') {
                    str_multiplier += function[i];
                    i++;
                }
                if (sign_pattern.back() == '-') {
                    multipliers.push_back(-stod(str_multiplier));
                    str_multiplier = "";
                } else {
                    multipliers.push_back(stod(str_multiplier));
                    str_multiplier = "";
                }
            }
            if (function[i] == '^') {
                i++;
                while (function[i] >= '0' && function[i] <= '9') {
                    str_exponent += function[i];
                    i++;
                }
                exponents.push_back(stod(str_exponent));
                str_exponent = "";
            }
        }

        std::vector<double> results;
        std::vector<double> function_sim;
        double pemdas = 0;
        for (int i = 0; i < plug_ins.size(); i++) {
            for (int k = 0; k < multipliers.size(); k++) {
                function_sim.push_back(multipliers[k] * pow(plug_ins[i], exponents[k]));
            }
            for (auto j : function_sim) {
                pemdas += j;
            }
            results.push_back(pemdas);
            function_sim.clear();
            pemdas = 0;
        }

        double final_answer = 0;
        for (int i  = 0; i < results.size(); i++) {
            if (i == 0 || i == results.size() - 1) {
                final_answer += results[i];
            } else {
                final_answer += 2 * results[i];
            }
        }

        return final_answer * (delta_x / 2.0);
    }

    double midpoint (std::string function, double delta_x, std::string a, std::string b) {
        std::vector<double> plug_ins;
        std::vector<double> midpoints;
        double limit_b = stod(b);
        double num = stod(a);
        bool check = false;

        while (!check) {  // increase the nums to plug in by the delta_x until it has exceeded limit_b
            if (num > limit_b) {
                check = true;
            } else {
                plug_ins.push_back(num);
            }
            num += delta_x;
        }

        for (int i = 0; i < plug_ins.size(); i++) {
            midpoints.push_back((plug_ins[i] + plug_ins[i + 1]) / 2.0);
        }

        midpoints.pop_back();

        std::vector<double> multipliers;
        std::vector<double> exponents;
        std::string str_multiplier;
        std::string str_exponent;
        std::string sign_pattern;
        for (int i = 0; i < function.size(); i++) {  // fishes for exp, mult, +, -
            if (function[i] == '+' || function[i] == '-') {
                sign_pattern += function[i];
            }
            if (function[i] >= '0' && function[i] <= '9') {
                while (function[i] >= '0' && function[i] <= '9') {
                    str_multiplier += function[i];
                    i++;
                }
                if (sign_pattern.back() == '-') {
                    multipliers.push_back(-stod(str_multiplier));
                    str_multiplier = "";
                } else {
                    multipliers.push_back(stod(str_multiplier));
                    str_multiplier = "";
                }
            }
            if (function[i] == '^') {
                i++;
                while (function[i] >= '0' && function[i] <= '9') {
                    str_exponent += function[i];
                    i++;
                }
                exponents.push_back(stod(str_exponent));
                str_exponent = "";
            }
        }

        std::vector<double> results;
        std::vector<double> function_sim;
        double pemdas = 0;
        for (int i = 0; i < midpoints.size(); i++) {
            for (int k = 0; k < multipliers.size(); k++) {
                function_sim.push_back(multipliers[k] * pow(midpoints[i], exponents[k]));
            }
            for (auto j : function_sim) {
                pemdas += j;
            }
            results.push_back(pemdas);
            function_sim.clear();
            pemdas = 0;
        }

        double final_answer = 0;
        for (auto i : results) {
            final_answer += i;
        }

        return final_answer * delta_x;
    }
}  // namespace par

#endif  // FUNCTION_PARSER_H_
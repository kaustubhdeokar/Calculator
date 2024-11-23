#include "crow_all.h"
#include <iostream>
#include "operations.h"
#include "trig_operations.h"
#include "compound_interest.h"


int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/basic_math").methods(crow::HTTPMethod::GET)([](const crow::request &req)
                                                                  {
        auto x = crow::json::load(req.body);
        if (!x) {
            return crow::response(400, "Invalid JSON");
        }

        std::string operation = x["operation"].s();
        double result;

        try {
            if (operation == "add") {
                result = add(x["a"].d(), x["b"].d());
            } else if (operation == "subtract") {
                result = subtract(x["a"].d(), x["b"].d());
            } else if (operation == "multiply") {
                result = multiply(x["a"].d(), x["b"].d());
            } else if (operation == "divide") {
                result = divide(x["a"].d(), x["b"].d());
            } else {
                return crow::response(400, "Invalid operation");
            }
        } catch (const std::exception& e) {
            return crow::response(400, e.what());
        }

        crow::json::wvalue response;
        response["result"] = result;
        return crow::response(response); });

    CROW_ROUTE(app, "/trig_functions").methods(crow::HTTPMethod::GET)([](const crow::request &req)
                                                                      {
        auto x = crow::json::load(req.body);
        if (!x) {
            return crow::response(400, "Invalid JSON");
        }

        std::string operation = x["operation"].s();
        double result;

        try {
            if (operation == "sin") {
                result = sincalc(x["angle"].d());
            } else if (operation == "cos") {
                result = coscalc(x["angle"].d());
            } else if (operation == "tan") {
                result = tancalc(x["angle"].d());
            } else {
                return crow::response(400, "Invalid operation");
            }
        } catch (const std::exception& e) {
            return crow::response(400, e.what());
        }

        crow::json::wvalue response;
        response["result"] = result;
        return crow::response(response); });

    CROW_ROUTE(app, "/compound_interest").methods(crow::HTTPMethod::GET)([](const crow::request &req)
                                                                         {
        auto x = crow::json::load(req.body);
        if (!x) {
            return crow::response(400, "Invalid JSON");
        }

        double result;

        try {
            result = calculateCompoundInterest(x["principal"].d(), x["rate"].d(), x["times"].i(), x["years"].i());
        } catch (const std::exception& e) {
            return crow::response(400, e.what());
        }

        crow::json::wvalue response;
        response["result"] = result;
        return crow::response(response); });

    app.port(18080).multithreaded().run();
}
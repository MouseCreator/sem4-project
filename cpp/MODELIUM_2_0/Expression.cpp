#include "Expression.h"
#include<iostream>
#include<cmath>
#include<algorithm>
#include <string>
#include <QMessageBox>


namespace expr
{
    Expression::Expression(const Expression& expr)
    {
        this->tree.root = expr.tree.Copy(expr.tree.root);
        this->vars = expr.get_vars();
    }

    /// @brief Parses expression into RPN (reverse polish notation),
    ///  then fill it in binary tree
    /// @param expression Expression to handle
    Expression::Expression(std::string expression)
    {
        std::vector<std::string> rpn;
        try {
            rpn = GenRpn(expression);
            std::reverse(rpn.begin(), rpn.end());

            std::vector<std::string>::iterator start = rpn.begin();
            GenSubTree(&this->tree.root, start);
        }
        catch (std::runtime_error& e) {
            //std::cout << "Runtime error occured:\n " << e.what() << std::endl;
            //throw std::runtime_error(" ");
            QMessageBox* error_box = new QMessageBox;
            error_box->setText("Invalid input (missing or extra brackets or invalid symbols\n");
            error_box->setIcon(QMessageBox::Critical);
            error_box->setWindowTitle("Input Error");
            error_box->exec();
        }
    }

    /// @brief Delete previous data and create new Expression
    /// @param expression New data
    void Expression::LoadExpression(std::string expression)
    {
        this->tree.Clear(tree.root);
        delete tree.root;

        new (this) Expression(expression);
    }

    Expression::Expression(ENode* expr) {
        this->tree.root = expr;
    }

    std::string Expression::to_string(ENode* node) const
    {
        if (tree.root == nullptr)
            return std::string("");
        if (node == nullptr)
            node = tree.root;

        if (isFunction(node->data)) {
            if (isUnaryFunction(node->data))
                return (node->data + '(' + to_string(node->right) + ')');
            else
                return ('(' + to_string(node->left) + ')' + node->data + '(' + to_string(node->right) + ')');
        }
        else
            return node->data;
    }

    std::vector<std::string> Expression::get_vars() const
    {
        return vars;
    }

    Expression& Expression::operator=(const Expression& expr)
    {
        this->tree.Clear();
        this->tree.root = expr.tree.Copy(expr.tree.root);
        this->vars = expr.get_vars();
        return *this;
    }

    void Expression::ProcessOperation(std::string function,
        std::stack<std::string>& operators, std::vector<std::string>& rpn) const
    {
        int cur_function_priority = this->kFunctionsPriorities.at(function);
        while (!operators.empty())
        {
            int stack_function_priority = this->kFunctionsPriorities.at(operators.top());
            if (stack_function_priority <= cur_function_priority) {
                rpn.push_back(operators.top());
                operators.pop();
            }
            else
                break;
        }
        operators.push(function);
    }

    std::vector<std::string> Expression::GenRpn(std::string expression) const
    {
        std::stack <std::string> operations;
        std::vector<std::string> rpn;

        for (int i = 0; i < expression.size(); i++)
        {
            if (expression.find("log", i) == i) {
                ProcessOperation(std::string("log"), operations, rpn);
                i += 2;
            }
            else if (expression.find("ln", i) == i) {
                ProcessOperation(std::string("ln"), operations, rpn);
                i++;
            }
            else if (expression.find("sin", i) == i) {
                ProcessOperation(std::string("sin"), operations, rpn);
                i += 2;
            }
            else if (expression.find("cos", i) == i) {
                ProcessOperation(std::string("cos"), operations, rpn);
                i += 2;
            }
            else if (expression.find("tg", i) == i) {
                ProcessOperation(std::string("tg"), operations, rpn);
                i++;
            }
            else if (isalnum(expression[i]))
            {
                std::string var;
                while (isalnum(expression[i]) || expression[i] == '.' || expression[i] == ',')
                {
                    var.append(1, expression[i]);
                    i++;
                }
                i--;
                rpn.push_back(var);
            }
            else switch (expression[i])
            {
            case '(':
                operations.push(std::string(1, expression[i]));
                break;
            case ')':
                while (operations.empty() || operations.top() != "(")
                {
                    if (operations.empty()){
                        throw std::runtime_error("Input error: Brackets correctness error\n");
                    }

                    rpn.push_back(operations.top());
                    operations.pop();
                }
                operations.pop();
                break;

            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                ProcessOperation(std::string(1, expression[i]), operations, rpn);
                if (i > 1)
                    if (expression[i] == '-' && expression[i - 1] == '(' && expression[i - 2] == '-')
                        rpn.push_back("0");
                break;
            default:
                throw std::runtime_error("Input error: Invalid symbol\n");
            }
        }

        while (!operations.empty())
        {
            if (operations.top() == "(" || operations.top() == ")")
                throw std::runtime_error("Input error: Brackets correctness error\n");

            rpn.push_back(operations.top());
            operations.pop();
        }
        return rpn;
    }

    bool Expression::isNumber(std::string str) const
    {
        for (auto i : str) {
            char end = *(str.end() - 1);
            if (!isdigit(i) && i != '.' && i != ',' && !(i == '-' && end != '-'))
                return false;
        }
        return true;
    }

    void Expression::CheckVar(std::string var)
    {
        if (std::find(vars.begin(), vars.end(), var) == vars.end())
            vars.push_back(var);
    }

    bool Expression::isFunction(std::string str) const
    {
        return kFunctionsPriorities.count(str) != 0;
    }

    bool Expression::isUnaryFunction(std::string str) const
    {
        if (!isFunction(str))
            return false;
        return kFunctionsPriorities.at(str) == 1;
    }

    void Expression::GenSubTree(ENode** node, std::vector<std::string>::iterator& cur)
    {
        if (isFunction(*cur))
        {
            *node = new ENode(std::string(*cur));
            std::vector<std::string>::iterator funct = cur;
            GenSubTree(&(*node)->right, ++cur);
            if (!isUnaryFunction(*funct))
                GenSubTree(&(*node)->left, ++cur);
        }
        else {
            *node = new ENode(std::string(*cur));
            if (!isNumber(*cur))
                CheckVar(*cur);
        }
    }

    bool Expression::Compare(ENode* node_1, ENode* node_2) const
    {
        if (!node_1 && !node_2)
            return true;
        else if ((!node_1 && node_2) || (node_1 && !node_2))
            return false;
        else
            if (node_1->data == node_2->data || (isNumber(node_1->data) && isNumber(node_2->data) && std::stod(node_1->data) == std::stod(node_2->data)))
            {
                if (node_1->data == "+" || node_1->data == "*")
                    return ((Compare(node_1->left, node_2->left) && Compare(node_1->right, node_2->right)) ||
                        (Compare(node_1->left, node_2->right) && Compare(node_1->right, node_2->left)));
                else
                    if (isUnaryFunction(node_1->data)) {
                        return Compare(node_1->right, node_2->right);
                    }
                    else
                        return (Compare(node_1->left, node_2->left) && Compare(node_1->right, node_2->right));
            }
            else
                return false;
    }

    void Expression::dCos(std::string var, ENode*& cos_node)
    {
        ENode* mult = new ENode(std::string("*"));

        ENode* diff = new ENode(std::string("-"));
        ENode* dCos = new ENode(std::string("sin"));
        dCos->right = tree.Copy(cos_node->right);
        diff->left = new ENode(std::string("0"));
        diff->right = dCos;
        mult->left = diff;
        mult->right = Differentiate(var, cos_node->right);
        *cos_node = *mult;
    }

    void Expression::dSin(std::string var, ENode*& sin_node)
    {
        ENode* mult = new ENode(std::string("*"));
        ENode* dSin = new ENode(std::string("cos"));
        dSin->right = tree.Copy(sin_node->right);
        mult->left = dSin;
        mult->right = Differentiate(var, sin_node->right);

        *sin_node = *mult;
    }

    void Expression::dLog(std::string var, ENode*& log_node)
    {
        ENode* mult = new ENode(std::string("*"));

        ENode* div = new ENode(std::string("/"));
        ENode* multInDenominator = new ENode(std::string("*"));
        ENode* lnA = new ENode(std::string("ln"));
        lnA->right = tree.Copy(log_node->left);
        multInDenominator->left = tree.Copy(log_node->right);
        multInDenominator->right = lnA;
        div->left = new ENode(std::string("1"));
        div->right = multInDenominator;

        mult->left = div;
        mult->right = Differentiate(var, log_node->right);

        *log_node = *mult;
    }

    void Expression::dPow(std::string var, ENode*& pow_node)
    {
        ENode* mult = new ENode(std::string("*"));

        ENode* dPow = new ENode(std::string("*"));
        dPow->left = tree.Copy(pow_node->right);

        ENode* newPower = new ENode(std::string("-"));
        newPower->left = tree.Copy(pow_node->right);
        newPower->right = new ENode(std::string("1"));
        ENode* newPow = new ENode(std::string("^"));
        newPow->left = tree.Copy(pow_node->left);
        newPow->right = newPower;
        dPow->right = newPow;

        mult->left = dPow;
        mult->right = Differentiate(var, pow_node->left);

        *pow_node = *mult;
    }

    void Expression::dLn(std::string var, ENode*& ln_node)
    {
        ENode* mult = new ENode(std::string("*"));

        ENode* divide = new ENode(std::string("/"));
        divide->left = new ENode(std::string("1"));
        divide->right = tree.Copy(ln_node->right);
        mult->left = divide;
        mult->right = Differentiate(var, ln_node->right);

        *ln_node = *mult;
    }

    void Expression::dTg(std::string var, ENode*& tg_node)
    {
        ENode* mult = new ENode(std::string("*"));

        ENode* divide = new ENode(std::string("/"));
        ENode* power = new ENode(std::string("^"));
        ENode* cos = new ENode(std::string("cos"));
        cos->right = tree.Copy(tg_node->right);
        power->left = cos;
        power->right = new ENode(std::string("2"));
        divide->left = new ENode(std::string("1"));
        divide->right = power;
        mult->left = divide;
        mult->right = Differentiate(var, tg_node->right);

        *tg_node = *mult;
    }

    Expression::ENode* Expression::Differentiate(std::string var, ENode* node)
    {
        if (node == nullptr)
            node = tree.root;

        this->Simplify(node);

        if (node->data == var) {
            node->data = std::string("1");
        }
        else if (!isFunction(node->data)) {
            node->data = std::string("0");
        }
        else {
            if (node->data == "sin")
                dSin(var, node);
            else if (node->data == "cos")
                dCos(var, node);
            else if (node->data == "tg")
                dTg(var, node);
            else if (node->data == "ln")
                dLn(var, node);
            else if (node->data == "cos")
                dCos(var, node);
            else if (node->data == "log")
                dLog(var, node);
            else if (node->data == "^")
                dPow(var, node);
            else if (node->data == "*")
                dMult(var, node);
            else if (node->data == "/")
                dDiv(var, node);
            else if (node->data == "+" || node->data == "-") {
                Differentiate(var, node->left);
                Differentiate(var, node->right);
            }
        }
        return node;
    }

    void Expression::dDiv(std::string var, ENode*& div_node)
    {
        ENode* div = new ENode(std::string("/"));

        ENode* numerator = new ENode(std::string("-")), * denominator = new ENode(std::string("^"));
        ENode* toReduce = new ENode(std::string("*")), * subtractor = new ENode(std::string("*"));
        toReduce->left = tree.Copy(div_node->left);
        subtractor->right = tree.Copy(div_node->right);
        denominator->left = tree.Copy(div_node->right);
        toReduce->right = Differentiate(var, div_node->right);
        subtractor->left = Differentiate(var, div_node->left);
        numerator->left = toReduce;
        numerator->right = subtractor;
        denominator->right = new ENode(std::string("2"));
        div->left = numerator;
        div->right = denominator;

        *div_node = *div;
    }

    void Expression::dMult(std::string var, ENode*& mult_node)
    {
        ENode* sum = new ENode(std::string("+"));

        ENode* dod_1 = new ENode(std::string("*")),
            * dod_2 = new ENode(std::string("*"));

        dod_1->left = tree.Copy(mult_node->left);
        dod_2->right = tree.Copy(mult_node->right);
        dod_1->right = Differentiate(var, mult_node->right);
        dod_2->left = Differentiate(var, mult_node->left);
        sum->left = dod_1;
        sum->right = dod_2;

        *mult_node = *sum;
    }

    double Expression::CalculateFunction(std::string function, double arg_1, double arg_2) const
    {
        if (function == "+")
            return arg_1 + arg_2;
        else if (function == "-")
            return arg_1 - arg_2;
        else if (function == "*")
            return arg_1 * arg_2;
        else if (function == "/") {
            if (arg_2 == 0)
                throw std::overflow_error("Math error: Dividing by Zero");
            return arg_1 / arg_2;
        }
        else if (function == "^")
            return pow(arg_1, arg_2);
        else if (function == "ln") {
            if (arg_1 <= 0)
                throw std::overflow_error("Math error: Wrong function argument 'ln(a)', 'a' is less than or equal to Zero\n");

            return log(arg_1);
        }
        else if (function == "log") {
            if (arg_1 <= 0 || arg_2 <= 0)
                throw std::overflow_error("Math error: Wrong function argument 'log(a, b)', 'a' or 'b' is less than or equal to Zero\n");
            if (arg_1 == 1)
                throw std::overflow_error("Math error: Wrong function argument 'log(a, b)', 'a' is equal to One\n");

            return (log(arg_2) / log(arg_1));
        }
        else if (function == "sin")
            return sin(arg_1);
        else if (function == "cos")
            return cos(arg_1);
        else if (function == "tg")
            return tan(arg_1);
        else return arg_1;
    }

    void Expression::Simplify(ENode* node, ENode* parent)
    {
        if (node == nullptr)
            node = tree.root;

        try {
            if (isFunction(node->data))
            {
                if (isUnaryFunction(node->data)) {
                    SimplifyUnaryFunction(node, parent);
                }
                else {
                    SimplifyBinaryFunction(node, parent);
                }
            }
        }
        catch (std::overflow_error& e) {
            //std::cout << "Overflow error occurred\n" << e.what();
            QMessageBox* error_box = new QMessageBox;
            error_box->setText("Overflow error occurred\n");
            error_box->setIcon(QMessageBox::Critical);
            error_box->setWindowTitle("Input Error");
            error_box->exec();
        }
    }

    void Expression::SimplifyBinaryFunction(ENode* node, ENode* parent)
    {
        if (!isNumber(node->right->data)) {
            Simplify(node->right, node);
        }
        if (!isNumber(node->left->data)) {
            Simplify(node->left, node);
        }
        if (isNumber(node->right->data) && isNumber(node->left->data))
        {
            node->data = std::to_string(CalculateFunction(node->data,
                std::stod(node->left->data), std::stod(node->right->data)));
            tree.Clear(node);
        }
        else {
            // Check all possible combinations to simplify expression

            if (isNumber(node->left->data) && std::stod(node->left->data) == 0)
            {
                if (node->data == "+") {
                    delete node->left;
                    this->tree.DeleteNode(parent, node, node->right);
                }
                else if (node->data == "*" || node->data == "/" || node->data == "^") {
                    tree.Clear(node);
                    node->data = std::string("0");
                }
            }
            else if (isNumber(node->right->data) && std::stod(node->right->data) == 0)
            {
                if (node->data == "+" || node->data == "-") {
                    delete node->right;
                    this->tree.DeleteNode(parent, node, node->left);
                }
                else if (node->data == "*") {
                    tree.Clear(node);
                    node->data = std::string("0");
                }
                else if (node->data == "^") {
                    tree.Clear(node);
                    node->data = std::string("1");
                }
            }
            else if (isNumber(node->left->data) && std::stod(node->left->data) == 1)
            {
                if (node->data == "*") {
                    delete node->left;
                    this->tree.DeleteNode(parent, node, node->right);
                }
                else if (node->data == "^") {
                    tree.Clear(node);
                    node->data = std::string("1");
                }
            }
            else if (isNumber(node->right->data) && std::stod(node->right->data) == 1)
            {
                if (node->data == "*" || node->data == "/" || node->data == "^") {
                    delete node->right;
                    this->tree.DeleteNode(parent, node, node->left);
                }
                else if (node->data == "log") {
                    tree.Clear(node);
                    node->data = std::string("0");
                }
            }
            else
                if (!isNumber(node->left->data) && !isNumber(node->right->data) && node->data == "-") {
                    if (Compare(node->left, node->right)) {
                        tree.Clear(node);
                        node->data = std::string("0");
                    }
                }
        }
    }

    void Expression::SimplifyUnaryFunction(ENode* node, ENode* parent)
    {
        if (!isNumber(node->right->data)) {
            Simplify(node->right, node);
        }
        if (isNumber(node->right->data)) {
            node->data = std::to_string(CalculateFunction(node->data, std::stod(node->right->data)));
            tree.Clear(node);
        }
    }

    void Expression::ConvertVarsToNumbers(std::map<std::string, double> values, ENode* node)
    {
        if (!node)
            return;

        if (!isNumber(node->data) && !isFunction(node->data)) // is variable
            node->data = std::to_string(values.at(node->data));

        ConvertVarsToNumbers(values, node->left);
        ConvertVarsToNumbers(values, node->right);
    }

    double Expression::CalculateExpression(std::map<std::string, double> variables_values) const
    {
        Expression* temp = new Expression(tree.Copy(this->tree.root));
        temp->ConvertVarsToNumbers(variables_values, temp->tree.root);
        temp->Simplify();
        double res = std::stod(temp->tree.root->data);
        temp->tree.Clear(temp->tree.root);
        delete temp;
        return res;
    }
}

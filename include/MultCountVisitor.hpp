//
// Created by Mario Stöckli on 04.04.20.
//

#ifndef GRANITE_MULTCOUNTVISITOR_H
#define GRANITE_MULTCOUNTVISITOR_H


#include "ast_opt/visitor/Visitor.h"
#include "ast_opt/ast/LogicalExpr.h"
#include "ast_opt/ast/UnaryExpr.h"
#include "ast_opt/ast/AbstractBinaryExpr.h"
#include "ast_opt/ast/ArithmeticExpr.h"

class MultCountVisitor : Visitor {
private:
    int multCount = 0;
public:
    int getMultCount();

    void visit(AbstractExpr &elem) override;

    void visit(ArithmeticExpr &elem) override;


};

#endif //GRANITE_MULTCOUNTVISITOR_H

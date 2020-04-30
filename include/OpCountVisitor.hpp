//
// Created by Mario Stöckli on 03.04.20.
//

#ifndef GRANITE_OPCOUNTVISITOR_HPP
#define GRANITE_OPCOUNTVISITOR_HPP

#include "ast_opt/visitor/Visitor.h"

#include "ast_opt/ast/LogicalExpr.h"
#include "ast_opt/ast/UnaryExpr.h"
#include "ast_opt/ast/AbstractBinaryExpr.h"
#include "ast_opt/ast/ArithmeticExpr.h"

class OpCountVisitor : Visitor {
private:
    int opcount;
public:
    int getOpCount();

    void visit(AbstractExpr &elem) override;

    void visit(LogicalExpr &elem) override;

    void visit(UnaryExpr &elem) override;

    void visit(ArithmeticExpr &elem) override;


};


#endif //GRANITE_OPCOUNTVISITOR_HPP

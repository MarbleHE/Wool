//
// Created by Mario Stöckli on 03.04.20.
//

#include "OpCountVisitor.hpp"

#include "ast_opt/ast/LogicalExpr.h"
#include "ast_opt/ast/UnaryExpr.h"
#include "ast_opt/ast/AbstractBinaryExpr.h"
#include "ast_opt/ast/ArithmeticExpr.h"

int OpCountVisitor::getOpCount() {
    return this->opcount;
}

void OpCountVisitor::visit(AbstractExpr &elem) {
    elem.accept(*this);
}

void OpCountVisitor::visit(LogicalExpr &elem) {
    opcount++;
    elem.getLeft()->accept(*this);
    elem.getRight()->accept(*this);
}

void OpCountVisitor::visit(UnaryExpr &elem) {
    opcount++;
    elem.getRight()->accept(*this);
}

void OpCountVisitor::visit(ArithmeticExpr &elem) {
    opcount++;
    elem.getLeft()->accept(*this);
    elem.getRight()->accept(*this);
}

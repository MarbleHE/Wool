//
// Created by Mario Stöckli on 04.04.20.
//

#include "MultCountVisitor.hpp"
#include "ast_opt/ast/AbstractExpr.h"
#include "ast_opt/ast/ArithmeticExpr.h"
#include "ast_opt/ast/OpSymbEnum.h"

int MultCountVisitor::getMultCount() {
    return this->multCount;
}

void MultCountVisitor::visit(AbstractExpr &elem) {
    elem.accept(*this);
}

void MultCountVisitor::visit(ArithmeticExpr &elem) {
    if (std::get<ArithmeticOp>(elem.getOperator()->getOperatorSymbol()) == ArithmeticOp::MULTIPLICATION){
        multCount++;
    }
    elem.getLeft()->accept(*this);
    elem.getRight()->accept(*this);
}

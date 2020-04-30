//
// Created by Mario Stöckli on 06.04.20.
//


#include <cmath>
#include "ParameterVisitor.hpp"
#include "ast_opt/ast/Dimension.h"
#include "ast_opt/ast/LiteralInt.h"
#include "ast_opt/ast/Matrix.h"
#include "ast_opt/ast/LogicalExpr.h"
#include "ast_opt/ast/UnaryExpr.h"
#include "ast_opt/ast/ArithmeticExpr.h"
#include "ast_opt/ast/AbstractExpr.h"
#include "ast_opt/ast/OpSymbEnum.h"


int ParameterVisitor::getMultCount() {
    return this->multCount;
}

void ParameterVisitor::visit(AbstractExpr &elem) {
    elem.accept(*this);
}

void ParameterVisitor::visit(ArithmeticExpr &elem) {
    opcount++;
    if (std::get<ArithmeticOp>(elem.getOperator()->getOperatorSymbol()) == ArithmeticOp::MULTIPLICATION){
        multCount++;
    }
    elem.getLeft()->accept(*this);
    elem.getRight()->accept(*this);
}


int ParameterVisitor::getOpCount() {
    return this->opcount;
}

void ParameterVisitor::visit(LogicalExpr &elem) {
    opcount++;
    elem.getLeft()->accept(*this);
    elem.getRight()->accept(*this);
}

void ParameterVisitor::visit(UnaryExpr &elem) {
    opcount++;
    elem.getRight()->accept(*this);
}

void ParameterVisitor::visit(LiteralInt &elem) {
    auto m = elem.getMatrix();
    if (auto mat = dynamic_cast<Matrix<int>*> (m)){
        if (mat->getDimensions().numColumns >= maxSlots) {
            maxSlots = mat->getDimensions().numColumns;
        } else {
            sndMax = std::max(mat->getDimensions().numColumns,sndMax);
        }
    } else if (auto mat = dynamic_cast<Matrix<AbstractExpr*>*> (m)){
        for (size_t i = 0; i < mat->getDimensions().numColumns; i++){
            mat->getElementAt(0,i)->accept(*this);
        }
    } else {
        throw std::runtime_error("LiteralInt has something in Matrix it should not.");
    }
}

int ParameterVisitor::getMaxSlots() {
    return this->maxSlots;
}

int ParameterVisitor::getSndMaxSlots(){
    return this->sndMax;
}
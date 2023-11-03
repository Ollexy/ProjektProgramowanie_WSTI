//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_FINANCEDEPARTMENT_H
#define PROJEKTPROGRAMOWANIE_WSTI_FINANCEDEPARTMENT_H

#include "Department.h"

class FinanceDepartment : Department {
public:
    FinanceDepartment(std::string localization, std::string manager);
    std::string getName() const override;

};


#endif //PROJEKTPROGRAMOWANIE_WSTI_FINANCEDEPARTMENT_H

//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_MARKETINGDEPARTMENT_H
#define PROJEKTPROGRAMOWANIE_WSTI_MARKETINGDEPARTMENT_H

#include "Department.h"

class MarketingDepartment : Department {
public:
    MarketingDepartment(std::string localization, std::string manager);
    std::string getName() const override;
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_MARKETINGDEPARTMENT_H

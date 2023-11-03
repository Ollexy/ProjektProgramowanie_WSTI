//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_ITDEPARTMENT_H
#define PROJEKTPROGRAMOWANIE_WSTI_ITDEPARTMENT_H

#include "Department.h"


class ITDepartment : public Department {
public:
    ITDepartment(std::string localization, std::string manager);
    std::string getName() const override;
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_ITDEPARTMENT_H

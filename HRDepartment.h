//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_HRDEPARTMENT_H
#define PROJEKTPROGRAMOWANIE_WSTI_HRDEPARTMENT_H

#include "Department.h"

class HRDepartment : public Department {
public:
    HRDepartment(std::string localization, std::string manager);
    std::string getName() const override;
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_HRDEPARTMENT_H
